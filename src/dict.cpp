#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
using namespace std;

int main(int argc, char** argv){
	
	map<string, bool> m;

	m["fid_2821"] = true;
	m["iswatermark"] = true;
	m["logo"] = true;
	m["loginfo"] = true;
	m["sharpen"] = true;
	m["saturation"] = true;
	m["exdefn"] = true;
	map<string, bool>::const_iterator itr;
       	itr = m.begin();
	for (;itr != m.end();++itr){
		printf("k=%s\n", itr->first.c_str());
	}
	return 0;
}
