#include <iostream>


//add comment v1

//add comment v2


#include <unordered_map>
using namespace std;

int main() {
    char c;
    string s;
    cin >> s >> c;
    
    unordered_map<char, int> counter;
    for (int i=0;i<s.length();i++){
        counter[s[i]]+=1;
    }
    cout << counter.size() << endl;
    for (auto p=counter.begin();p!=counter.end();p++){
        cout << p->first << ":\t" << p->second << endl;
    }
    if (c >= '0' && c <= '9'){
        cout << counter[c] << endl;
        return 0;
    }else if (c >= 'a' && c <= 'z'){
        int ret = 0;
        ret += counter[c] + counter[c + 'A' - 'a'];
        cout << ret << endl;
    }else{
        int ret = 0;
        ret += counter[c] + counter[c - 'A' + 'a'];
        cout << ret << endl;
    }
    return 0;
}
