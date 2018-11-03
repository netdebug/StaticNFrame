// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/05/25
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#include "NFLogMgr.h"

#include <sstream>

NFLogMgr::NFLogMgr()
{
	m_pSpdlogModule = nullptr;
}

NFLogMgr::~NFLogMgr()
{
}

bool NFLogMgr::Init(NFISpdlogModule* pSpdlogModule)
{
	m_pSpdlogModule = pSpdlogModule;
	return true;
}

void NFLogMgr::UnInit()
{
	
}

bool NFLogMgr::LogNormal(const NF_LOG_LEVEL nll, const uint64_t ident, const std::string& strInfo, const int64_t nDesc, const char* func, int line)
{
	if (m_pSpdlogModule)
	{
		m_pSpdlogModule->Log(nll, func, line, " {} | {} | {} |", ident, nDesc, strInfo);
	}
	return false;
}

bool NFLogMgr::LogNormal(const NF_LOG_LEVEL nll, const uint64_t ident, const std::string& strInfo, const std::string& strDesc, const char* func, int line)
{
	if (m_pSpdlogModule)
	{
		m_pSpdlogModule->Log(nll, func, line, " {} | {} | {} |", ident, strInfo, strDesc);
	}
	return false;
}

bool NFLogMgr::LogNormal(const NF_LOG_LEVEL nll, const uint64_t ident, const std::ostringstream& stream, const char* func, int line)
{
	if (m_pSpdlogModule)
	{
		m_pSpdlogModule->Log(nll, func, line, " {} | {} | {} |", ident, stream.str());
	}
	return false;
}

NFISpdlogModule* NFLogMgr::GetSpdLogModule()
{
	return m_pSpdlogModule;
}

