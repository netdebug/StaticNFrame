#pragma once

#include "NFComm/NFPluginModule/NFINetClientModule.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"

class NFCTestClientModule : public NFIModule, NFTimerObj 
{
public:
	NFCTestClientModule(NFIPluginManager* p)
	{
		pPluginManager = p;
		m_usId = 0;
		m_serverId = 0;
		m_pNetClientModule = nullptr;
	}
public:
    virtual bool Init();

    virtual bool AfterInit();

    virtual bool Execute();

    virtual bool BeforeShut();

	virtual bool Shut();

	virtual void OnTimer(uint32_t nTimerID);
protected:
	void OnProxySocketEvent(const eMsgType nEvent, const uint32_t unLinkId);
	void OnHandleOtherMessage(const uint32_t unLinkId, const uint64_t playerId, const uint32_t nMsgId, const char* msg, const uint32_t nLen);
	void OnHandleQueryPlayerData(const uint32_t unLinkId, const uint64_t playerId, const uint32_t nMsgId, const char* msg, const uint32_t nLen);
protected:
	void SendCreateChar();
private:
	NFINetClientModule* m_pNetClientModule;
	uint32_t m_usId;
	std::string m_account;
	std::string m_charName;
	uint32_t m_serverId;
};