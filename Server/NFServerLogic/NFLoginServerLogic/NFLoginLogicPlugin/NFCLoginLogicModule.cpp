

#include "NFCLoginLogicModule.h"
#include "NFComm/NFPluginModule/NFEventDefine.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFServer/NFServerCommon/NFServerCommon.h"
#include "NFComm/NFCore/NFJson.h"
#include "NFMessageDefine/NFMsgDefine.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFCommon.h"

NFCLoginLogicModule::NFCLoginLogicModule(NFIPluginManager* p)
{
	pPluginManager = p;
}

NFCLoginLogicModule::~NFCLoginLogicModule()
{

}

bool NFCLoginLogicModule::Init()
{
	m_pKernelModule = pPluginManager->FindModule<NFIKernelModule>();
	m_pLoginClient_MasterModule = pPluginManager->FindModule<NFILoginClient_MasterModule>();
	m_pHttpServerModule = pPluginManager->FindModule<NFIHttpServerModule>();
	m_pHttpServerModule->AddRequestHandler("/httplogin", NFHttpType::NF_HTTP_REQ_POST, this, &NFCLoginLogicModule::HttpHandleHttpLogin);
	return true;
}

bool NFCLoginLogicModule::AfterInit()
{
	return true;
}

bool NFCLoginLogicModule::Execute()
{
	return true;
}

bool NFCLoginLogicModule::BeforeShut()
{
	return true;
}

bool NFCLoginLogicModule::Shut()
{
	return true;
}

void NFCLoginLogicModule::OnExecute(uint16_t nEventID, uint64_t nSrcID, uint8_t bySrcType, NFEventContext* pEventContext)
{

}

bool NFCLoginLogicModule::HttpHandleHttpLogin(const NFHttpRequest& req)
{
	NFLogDebug("http login | body | {}", req.body);

	std::string errString;
	NFJson json = NFJson::parse(req.body, errString);

	if (errString.empty() == false)
	{
		NFLogError("json error | {}", errString);
		return false;
	}

	if (json.is_object())
	{
		NFJson cmd = json["do"];
		NFJson data = json["data"];
		if (cmd.is_string())
		{
			if (cmd.string_value() == "request-zone-list")
			{
				NFMsg::reqeust_zone_list httpLogin;
				bool ret = NFServerCommon::JsonStringToMessage(req.body, httpLogin);
				if (ret == false)
				{
					NFLogError("json error | {}", req.body);
					return false;
				}
				RequestZoneList(req, httpLogin);
			}
			else if (cmd.string_value() == "plat-token-login")
			{
				NFMsg::plat_token_login_request httpLogin;
				bool ret = NFServerCommon::JsonStringToMessage(req.body, httpLogin);
				if (ret == false)
				{
					NFLogError("json error | {}", req.body);
					return false;
				}
				PlatTokenLogin(req, httpLogin);
			}
			else if (cmd.string_value() == "request-select-zone")
			{
				RequestSelectZone(req, data);
			}
		}
		else
		{
			NFLogError("json error | {}", req.body);
		}
	}
	return true;
}

void NFCLoginLogicModule::RequestZoneList(const NFHttpRequest& req, const NFMsg::reqeust_zone_list& httpLogin)
{
	auto pServerData = m_pLoginClient_MasterModule->GetRandGameServer();
	if (pServerData == nullptr)
	{
		NFLogError("No Game Server!");
		return;
	}

	auto pServerConfig = NFConfigMgr::Instance()->GetServerConfig(pServerData->mServerInfo.server_id());
	if (pServerConfig == nullptr)
	{
		NFLogError("No Game Server Config!");
		return;
	}

	uint64_t nowTime = pPluginManager->GetNowTime() / 1000;

	NFMsg::reqeust_zone_list_respone respone;
	respone.set_do_(httpLogin.do_());
	respone.set_error("0");
	respone.set_st(nowTime);
	auto pData = respone.mutable_data();
	if (pData)
	{
		pData->set_bestzoneid(pServerData->mServerInfo.server_id());
		pData->set_gameid(pServerConfig->mWorldId);
		pData->set_gamename(pServerConfig->mServerName);
		pData->set_zoneid(pServerData->mServerInfo.server_id());

		auto pZone = pData->add_zonelist();
		pZone->set_gameid(pServerConfig->mWorldId);
		pZone->set_gamename(pServerConfig->mServerName);
		pZone->set_newzoneid(0);
		pZone->set_onlinenum(pServerData->mServerInfo.server_cur_count());
		pZone->set_opentime("");
		pZone->set_state(pServerData->mServerInfo.server_state());
		pZone->set_zoneid(pServerData->mServerInfo.server_id());
		pZone->set_zonename(pServerData->mServerInfo.server_name());
	}

	std::string responeJson;
	bool ret = NFServerCommon::MessageToJsonString(respone, responeJson);
	if (ret == false)
	{
		return;
	}

	m_pHttpServerModule->ResponseMsg(req, responeJson, NFWebStatus::WEB_OK, "OK");
}

void NFCLoginLogicModule::PlatTokenLogin(const NFHttpRequest& req, const NFMsg::plat_token_login_request& request)
{
	std::string account = request.data().platinfo().account();
	std::string sign = request.data().platinfo().sign();
	uint32_t gameid = request.gameid();
	uint32_t zoneid = request.zoneid();
	uint64_t nowTime = pPluginManager->GetNowTime() / 1000;
	std::string plat_key = NFMD5::md5str(sign + account + NFCommon::tostr(nowTime));
	std::string plat_login = NFMD5::md5str(sign + account + NFCommon::tostr(nowTime));

	uint32_t plat_login_timeout = 2592000;
	uint64_t uuid = m_pKernelModule->GetUUID();

	NFMsg::plat_token_login_respone respone;
	respone.set_gameid(request.gameid());
	respone.set_unigame_plat_key(plat_key);
	respone.set_unigame_plat_login(plat_login);
	respone.set_unigame_plat_timestamp(nowTime);
	respone.set_zoneid(request.zoneid());

	respone.set_do_(request.do_());
	auto pData = respone.mutable_data();
	pData->set_gameid(request.gameid());
	pData->set_sid(sign + "::" + account);
	pData->set_timezone_name("CST");
	pData->set_timezone_offset(28800);
	pData->set_uid(NFCommon::tostr(uuid));
	pData->set_unigame_plat_key(plat_key);
	pData->set_unigame_plat_login(plat_login);
	pData->set_unigame_plat_login_life(plat_login_timeout);
	auto pPlatinfo = pData->mutable_platinfo();
	pPlatinfo->set_aaa(123);
	pPlatinfo->set_account(account);
	pPlatinfo->set_email("");
	pPlatinfo->set_gameid(request.gameid());
	pPlatinfo->set_gender("");
	pPlatinfo->set_nickname("");
	pPlatinfo->set_platid(0);
	pPlatinfo->set_timestamp(NFCommon::tostr(nowTime));
	pPlatinfo->set_uid(NFCommon::tostr(uuid));

	std::string responeJson;
	bool ret = NFServerCommon::MessageToJsonString(respone, responeJson);
	if (ret == false)
	{
		return;
	}
	std::string set_url = "/httplogin?unigame_plat_sign=" + NFMD5::md5str(responeJson + NFCommon::tostr(nowTime) + plat_key);
	NFLogError("last url | {}", set_url);
	m_pHttpServerModule->ResponseMsg(req, responeJson, NFWebStatus::WEB_OK, "OK");
}

void NFCLoginLogicModule::RequestSelectZone(const NFHttpRequest& req, NFJson& json)
{

}