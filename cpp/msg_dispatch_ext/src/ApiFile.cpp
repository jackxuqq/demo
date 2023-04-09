#include <fcntl.h>
#include <unistd.h>
#include "ApiFile.h"


ApiErrCode ApiFile::open(const openReq& req,  openRsp* rsp)
{
	if (req.path.length() <= 0 || req.name.length() <= 0) 
	{
		return -1;
	}

	std::string full = req.path + "/" + req.name;

	auto fd = ::open(full.c_str(), O_WRONLY|O_CREAT);
	
	if (fd < 0)
	{
		return -2;
	}

	rsp->fd = fd;
	return 0;
}

