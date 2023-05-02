#include <iostream>
#include <string>
#include "demo.pb.h"

class Consume
{
public:
	static void decode(const std::string& buff, ModelData* data)
	{
		auto flag = data->ParseFromString(buff);
		if (flag == false) 
		{
			std::cout << "Parse Fail" << std::endl;
		}
	}

};
