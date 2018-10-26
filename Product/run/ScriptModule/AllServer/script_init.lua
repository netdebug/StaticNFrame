--package.path = '../../NFDataCfg/Script/?.lua;'

require "gxlua/unilight"


function init_script_system(pluginManager)
	--初始化LuaNFrame
	LuaNFrame:init(pluginManager)

	--加载所有的module
	LuaNFrame:InsertLoadFunc(load_script_file)
	LuaNFrame:load_script_file()
end

function register_module(tbl, name)
	local tmp = {tbl = tbl, tblName = name}
	table.insert(LuaNFrame.ScriptList, tmp)
	unilight.debug("load module:" .. name)
end