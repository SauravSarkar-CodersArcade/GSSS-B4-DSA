#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//    string str = "12543789";
//    sort(str.begin(), str.end(), greater<>());
//    cout << str << endl;
    string str = "GSSS";
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z' ){
            str[i] += 32;
        }
    }
    cout << str << endl;
    for (int i=0; i<str.size(); i++){
        if (str[i] >= 'a' && str[i] <= 'z' ){
            str[i] -= 32;
        }
    }
    cout << str << endl;
    for (char & i : str){
        if (i >= 'A' && i <= 'Z' ){
            i += 32;
        }
    }
    cout << str << endl;
    for (char & i : str){
        if (i >= 'a' && i <= 'z' ){
            i -= 32;
        }
    }
    cout << str << endl;
    string s = "programming";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << s << endl;
    return 0;
}
