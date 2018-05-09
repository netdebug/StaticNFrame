// -------------------------------------------------------------------------
//    @FileName         :    NFKernelPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :    2010-03-15
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#include "NFKernelPlugin.h"
#include "NFCKernelModule.h"
#include "NFCTimerModule.h"
#include "NFCLogModule.h"
#include "NFCEventModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFKernelPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFKernelPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

const int NFKernelPlugin::GetPluginVersion()
{
    return 0;
}

const std::string NFKernelPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFKernelPlugin);
}

void NFKernelPlugin::Install()
{
	REGISTER_MODULE(pPluginManager, NFILogModule, NFCLogModule)
    REGISTER_MODULE(pPluginManager, NFITimerModule, NFCTimerModule);
    REGISTER_MODULE(pPluginManager, NFIEventModule, NFCEventModule);
    REGISTER_MODULE(pPluginManager, NFIKernelModule, NFCKernelModule);
}

void NFKernelPlugin::Uninstall()
{
    UNREGISTER_MODULE(pPluginManager, NFIKernelModule, NFCKernelModule);
    UNREGISTER_MODULE(pPluginManager, NFIEventModule, NFCEventModule);
    UNREGISTER_MODULE(pPluginManager, NFITimerModule, NFCTimerModule);
	UNREGISTER_MODULE(pPluginManager, NFILogModule, NFCLogModule)
}