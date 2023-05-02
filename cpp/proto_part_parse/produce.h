#include <iostream>
#include <string>
#include "demo.pb.h"

class Produce
{
public:

	static void encode(const ModelData& data, std::string* buff)
	{
		data.SerializeToString(buff);
	}

};


