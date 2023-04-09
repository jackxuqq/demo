#pragma once
#include "ApiParam.h"


class ApiFile
{

public:
	ApiErrCode open(const openReq& req, openRsp* rsp);
};
