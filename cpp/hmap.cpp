#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
	unordered_map<int,int>hmap;
	hmap[1]=1;
	hmap[2]=2;
	for(auto p = hmap.begin();p!=hmap.end();p++){
		cout << p->first << ":\t" << p->second << "\n";
	}
	cout << endl;
	return 0;
}
