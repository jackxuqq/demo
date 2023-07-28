#pragma once 

#include <string>

const int LENGTH_OF_CMD = 2;
extern const char* g_cmd[LENGTH_OF_CMD];

bool constructReq(const std::string& cmd, std::string* req);

// to be generate
void dispatch(const std::string& cmd, const std::string& jsonReq, std::string* jsonRsp);
