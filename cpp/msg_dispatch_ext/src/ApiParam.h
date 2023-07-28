#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>

using ApiErrCode = int;


struct openReq
{
	std::string path;
	std::string name;
};


struct openRsp
{
	int fd;
};


struct curveGetEdgesReq
{
	int tag;
};

struct curveGetEdgesRsp
{
	int numEdges;
	int* edges;
};

