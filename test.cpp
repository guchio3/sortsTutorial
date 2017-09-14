#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int increment(int a){
    return a + 1;
}

int main(){
    vector<int> res;
    if(res.size() == 0)
        cout << "AAA" << endl;
    string str = "1213";
    char str2 = '2';
    cout << str[0] - 48 << endl;

    stringstream ss;
    for(int i = 0; i < 10; ++i){
        ss << "a";
    }
    cout << ss.str() << endl;
    ss.clear();
    for(int i = 0; i < 10; ++i){
        ss << "b";
    }
    cout << ss.str() << endl;
    ss.clear();

    int a = 0;
    cout << increment(&a) << endl;

    return 0;
}
