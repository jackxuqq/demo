#include "produce.h"
#include "consume.h"

#include <google/protobuf/util/json_util.h>

bool proto_to_json(const google::protobuf::Message& message, std::string& json) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    return google::protobuf::util::MessageToJsonString(message, &json, options).ok();
}

bool json_to_proto(const std::string& json, google::protobuf::Message& message) {
    return google::protobuf::util::JsonStringToMessage(json, &message).ok();
}

int main()
{
	ModelData data;
	data.set_ret(100);
	for (unsigned int i = 0; i < 2; i++)
	{
		auto p = data.add_planes();
		auto p1 = p->mutable_p1();
		p1->set_x(i+1);
		p1->set_y(i+2);
		p1->set_z(i+3);
		auto p2 = p->mutable_p2();
		p2->set_x(i+1);
		p2->set_y(i+3);
		p2->set_z(i+2);
		auto p3 = p->mutable_p3();
		p3->set_x(i+2);
		p3->set_y(i+1);
		p3->set_z(i+3);
	}
	
	std::string buff;
	Produce::encode(data, &buff);
	
	std::cout << "len of buff : " << buff.length() << std::endl;

	//full parse
	{
		ModelData nData;
		Consume::decode(buff, &nData);

		std::string tmp;
		proto_to_json(nData, tmp);
		std::cout << tmp << std::endl;
	}

	//part parse
	{
		std::string buff1 = buff.substr(0, 10);
		std::string buff2 = buff.substr(10);
		ModelData nData;
		Consume::decode(buff1, &nData);

		std::string tmp;
		proto_to_json(nData, tmp);
		std::cout << tmp << std::endl;
	}
}
