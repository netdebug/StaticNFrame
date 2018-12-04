GateServerModule = {}

function GateServerModule.Init()
	GateServerModule.gameserver_unlinkid = 0
end

function GateServerModule.AfterInit()
	--添加网关web服务器，以及网络事件回调，协议回调
	TcpServer.addRecvCallBack(NF_SERVER_TYPES.NF_ST_PROXY, 0, "GateServerModule.NetServerRecvHandleJson")

	--添加网关客户端，链接GameServer服务器, 以及网络事件回调，协议回调
	TcpClient.addRecvCallBack(NF_SERVER_TYPES.NF_ST_GAME, 0, "GateServerModule.NetClientRecvHandleJson")

	--账号系统初始化
	AccountMgr:Init()
end

--特殊协议
function GateServerModule.NetServerRecvHandleJson(unLinkId, valueId, nMsgId, strMsg)
    local table_msg = json2table(strMsg)
    --协议规则
    if table_msg ~= nil then
        local cmd = table_msg["cmd_name"]
        if type(cmd) == "string" then
            local i, j = string.find(cmd, "Pmd.")
            local strcmd = string.sub(cmd, j+1, -1)
            if strcmd ~= "" then
				if type(Net[strcmd]) == "function" then
					local laccount = {}
					laccount.Id = AccountMgr:GetAccountId(unLinkId)
					laccount.unLinkId = unLinkId
					laccount.SendString = TcpServer.sendJsonMsg
					Net[strcmd](table_msg, laccount)
				else
					unilight.warn(cmd.." no handler!")
                end
            end
		end
    end
    -- body
end

--转发消息给客户端
function GateServerModule.NetClientRecvHandleJson(unLinkId, valueId, nMsgId, strMsg)
    local server_unlinkid = AccountMgr:GetLinkId(valueId)

    --如果连接断开了，就不在发送了
    if server_unlinkid == 0 then return end

    local msg = {
        cmd_name = "Pmd.UserJsMessageForwardUserPmd_CS",
        msg = json2table(strMsg),
    }

    local laccount = {}
    laccount.Id = valueId
    laccount.unLinkId = server_unlinkid

    unilight.debug(tostring(valueId) .. " | send msg | " .. strMsg)
    TcpServer.sendJsonMsg(msg, laccount)
end


function GateServerModule.Execute()

end

function GateServerModule.BeforeShut()

end

function GateServerModule.Shut()

end