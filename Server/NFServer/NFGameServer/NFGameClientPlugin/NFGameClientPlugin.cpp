// -------------------------------------------------------------------------
//    @FileName         :    NFGameClientPlugin.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/06/12
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameClientPlugin
//
// -------------------------------------------------------------------------

#include "NFGameClientPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFGameClientPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFGameClientPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGameClientPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFGameClientPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFGameClientPlugin);
}

void NFGameClientPlugin::Install()
{
}

void NFGameClientPlugin::Uninstall()
{
}
