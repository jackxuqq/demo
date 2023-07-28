#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "AIGCJson.hpp"
#include "ApiParam.h"

using namespace std;
using namespace aigc;

struct _openReq
{
	std::string path;
	std::string name;

	AIGC_JSON_HELPER(path, name)

	void get(openReq* req)
	{
		req->path = this->path;
		req->name = this->name;
	}
};

struct _openRsp
{
	int fd;

	AIGC_JSON_HELPER(fd)

	void set(const openRsp&  rsp)
	{
		this->fd = rsp.fd;
	}
};

struct _curveGetEdgesReq
{
	int tag;

	AIGC_JSON_HELPER(tag)

	void get(curveGetEdgesReq* req)
	{
		req->tag = this->tag;
	}
};

struct _curveGetEdgesRsp
{
	int numEdges;
	std::vector<int> edges; /*pointer type out param mapping vector type*/

	AIGC_JSON_HELPER(numEdges, edges)

	void set(const curveGetEdgesRsp& rsp)
	{
		this->numEdges = rsp.numEdges;
		auto curr = rsp.edges;
		for(unsigned int i = 0; i < rsp.numEdges; i++)
		{
			this->edges.push_back(*curr);
			++curr;
		}
	}
};

