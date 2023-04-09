
#include "Dispatch.h"
#include "ApiFile.h"
#include "ApiGeometry.h"
#include "ApiParamWrap.h"

//command array
const char* g_cmd[LENGTH_OF_CMD] = {"openFile", "curveGetEdges"};


// for test
bool constructReq(const std::string& cmd, std::string* req)
{
	if (cmd == g_cmd[0])
	{
		*req = R"({"path" : "/tmp", "name" : "demo.txt"})";
		return true;
	}
	else if (cmd == g_cmd[1])
	{
		*req = R"({"tag" : "11"})";
		return true;
	}

	return false;
}

// to be generate
void dispatch(const std::string& cmd, const std::string& jsonReq, std::string* jsonRsp)
{
	if (cmd == g_cmd[0]) 
	{
		ApiFile file;
		_openReq reqWrap;
		_openRsp rspWrap;
		openReq req;
		openRsp rsp;
		int ret = 0;

		//convert json to object
		JsonHelper::JsonToObject(reqWrap, jsonReq);
		reqWrap.get(&req);

		ret = file.open(req, &rsp);

		if (ret != 0) 
		{
			std::cout << "open file fail:" << ret << std::endl;
			return;
		}

		//convert object to json
		rspWrap.set(rsp); 
		JsonHelper::ObjectToJson(rspWrap, *jsonRsp);
	}
	else if (cmd == g_cmd[1]) 
	{
		ApiGeometry geometry;
		_curveGetEdgesReq reqWrap;
		_curveGetEdgesRsp rspWrap;
		curveGetEdgesReq req;
		curveGetEdgesRsp rsp;
		int ret = 0;
		
		//convert json to object
		JsonHelper::JsonToObject(reqWrap, jsonReq);
		reqWrap.get(&req);

		ret = geometry.curveGetEdges(req, &rsp);

		if (ret != 0)
		{
			std::cout << "geometry.curveGetEdges fail:" << ret << std::endl;
			return;
		}

		//convert object to json
		rspWrap.set(rsp);
		JsonHelper::ObjectToJson(rspWrap, *jsonRsp);
	}
	else 
	{
		std::cout << "unknown cmd!" << std::endl;
	}
}
