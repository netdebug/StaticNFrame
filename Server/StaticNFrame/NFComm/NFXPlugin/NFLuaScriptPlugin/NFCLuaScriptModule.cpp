﻿// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptModule.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-01-02
//    @Module           :    NFCLuaScriptModule
//    @Desc             :
// -------------------------------------------------------------------------

#include <assert.h>
#include "NFCLuaScriptModule.h"
#include "NFLuaScriptPlugin.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFINetServerModule.h"
#include "NFComm/NFCore/NFProfiler.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFStringUtility.h"

#define TRY_RUN_GLOBAL_SCRIPT_FUN0(strFuncName)   try {LuaIntf::LuaRef func(l, strFuncName);  func.call<LuaIntf::LuaRef>(); }   catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }
#define TRY_RUN_GLOBAL_SCRIPT_FUN1(strFuncName, arg1)  try {LuaIntf::LuaRef func(l, strFuncName);  func.call<LuaIntf::LuaRef>(arg1); }catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }
#define TRY_RUN_GLOBAL_SCRIPT_FUN2(strFuncName, arg1, arg2)  try {LuaIntf::LuaRef func(l, strFuncName);  func.call<LuaIntf::LuaRef>(arg1, arg2); }catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }
#define TRY_RUN_GLOBAL_SCRIPT_FUN3(strFuncName, arg1, arg2, arg3)  try {LuaIntf::LuaRef func(l, strFuncName);  func.call<LuaIntf::LuaRef>(arg1, arg2, arg3); }catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }

#define TRY_LOAD_SCRIPT_FLE(strFileName)  try{l.doFile(strFileName);} catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }
#define TRY_ADD_PACKAGE_PATH(strFilePath)  try{ l.addPackagePath(strFilePath); } catch (LuaIntf::LuaException& e) { cout << e.what() << endl; }

bool NFCLuaScriptModule::Init()
{
    Register();
	LoadScript();
    return true;
}

bool NFCLuaScriptModule::AfterInit()
{
    return true;
}

bool NFCLuaScriptModule::ReadyExecute()
{
	TRY_RUN_GLOBAL_SCRIPT_FUN0("ScriptModule.Init");
	TRY_RUN_GLOBAL_SCRIPT_FUN0("ScriptModule.AfterInit");
	return true;
}

bool NFCLuaScriptModule::Shut()
{
    TRY_RUN_GLOBAL_SCRIPT_FUN0("ScriptModule.Shut");

    return true;
}

bool NFCLuaScriptModule::Finalize()
{
    return true;
}

bool NFCLuaScriptModule::Execute()
{
    //10秒钟reload一次

    if (NFGetSecondTime() - mnTime > 10)
    {
        BEGIN_PROFILE(__FUNCTION__);
        mnTime = NFGetSecondTime();
        TRY_RUN_GLOBAL_SCRIPT_FUN0("ScriptModule.Execute");
        END_PROFILE();
    }

    return true;
}

bool NFCLuaScriptModule::BeforeShut()
{
    TRY_RUN_GLOBAL_SCRIPT_FUN0("ScriptModule.BeforeShut");

    return true;
}

void NFCLuaScriptModule::LoadScript()
{
	TRY_ADD_PACKAGE_PATH(pPluginManager->GetConfigPath() + "/ScriptModule");

	if (pPluginManager->IsLoadAllServer())
	{
		std::list<std::string> files;
		NFFileUtility::GetFiles(pPluginManager->GetConfigPath() + "/ScriptModule", files, true, "*.lua");
		for (auto it = files.begin(); it != files.end(); it++)
		{
			std::string str = *it;
			std::cout << "load script:" << str << std::endl;
			TRY_LOAD_SCRIPT_FLE(str.c_str());
		}
	}
	else
	{
		//先记载scriptmodule下面的lua代码
		std::list<std::string> files;
		NFFileUtility::GetFiles(pPluginManager->GetConfigPath() + "/ScriptModule", files, false, "*.lua");
		for (auto it = files.begin(); it != files.end(); it++)
		{
			std::string str = *it;
			std::cout << "load script:" << str << std::endl;
			TRY_LOAD_SCRIPT_FLE(str.c_str());
		}
		files.clear();

		//然后假装gxlua下面的公共代码
		NFFileUtility::GetFiles(pPluginManager->GetConfigPath() + "/ScriptModule/gxlua", files, true, "*.lua");
		for (auto it = files.begin(); it != files.end(); it++)
		{
			std::string str = *it;
			std::cout << "load script:" << str << std::endl;
			TRY_LOAD_SCRIPT_FLE(str.c_str());
		}
		files.clear();

		//最后加载执行程序同名的目录
		NFFileUtility::GetFiles(pPluginManager->GetConfigPath() + "/ScriptModule/" + pPluginManager->GetAppName(), files, true, "*.lua");
		for (auto it = files.begin(); it != files.end(); it++)
		{
			std::string str = *it;
			std::cout << "load script:" << str << std::endl;
			TRY_LOAD_SCRIPT_FLE(str.c_str());
		}
	}

	TRY_RUN_GLOBAL_SCRIPT_FUN1("init_script_system", pPluginManager);
}

bool NFCLuaScriptModule::Register()
{
	LuaIntf::LuaBinding(l).beginClass<NFIPluginManager>("NFIPluginManager")
		.addFunction("GetAppName", &NFIPluginManager::GetAppName)
		.addFunction("GetLogModule", &NFIPluginManager::FindModule<NFILogModule>)
		.addFunction("GetLuaModule", &NFIPluginManager::FindModule<NFILuaScriptModule>)
		.addFunction("GetServerModule", &NFIPluginManager::FindModule<NFINetServerModule>)
		.endClass();

	LuaIntf::LuaBinding(l).beginClass<NFILuaScriptModule>("NFILuaScriptModule")
		.endClass();

	LuaIntf::LuaBinding(l).beginClass<NFINetServerModule>("NFINetServerModule")
		.addFunction("AddServer", &NFINetServerModule::AddServer)
		.addFunction("GetLinkIp", &NFINetServerModule::GetLinkIp)
		.addFunction("AddReceiveLuaCallBackByMsgId", &NFINetServerModule::AddReceiveLuaCallBackByMsgId)
		.addFunction("AddReceiveLuaCallBackToOthers", &NFINetServerModule::AddReceiveLuaCallBackToOthers)
		.addFunction("AddEventLuaCallBack", &NFINetServerModule::AddEventLuaCallBack)
		.endClass();

	LuaIntf::LuaBinding(l).beginClass<NFILogModule>("NFILogModule")
		.addFunction("LuaDebug", &NFILogModule::LuaDebug)
		.addFunction("LuaInfo", &NFILogModule::LuaInfo)
		.addFunction("LuaWarn", &NFILogModule::LuaWarn)
		.addFunction("LuaError", &NFILogModule::LuaError)
		.endClass();
    return true;
}

void NFCLuaScriptModule::RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t nMsgId, const char* msg, const uint32_t nLen)
{
	TryRunGlobalScriptFunc(luaFunc, unLinkId, valueId, nMsgId, msg, nLen);
}

void NFCLuaScriptModule::RunNetEventLuaFunc(const std::string& luaFunc, const eMsgType nEvent, const uint32_t unLinkId)
{
	TryRunGlobalScriptFunc(luaFunc, nEvent, unLinkId);
}