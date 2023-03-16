#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ret=0;
    cout << s << endl;
    for (int i = s.length()-1;i>=0;i--){
        if (s[i] == ' ' ){
            break;
        }
        else{
            ret++;
        }
    }
    cout << ret << endl;
    return ret;
}
