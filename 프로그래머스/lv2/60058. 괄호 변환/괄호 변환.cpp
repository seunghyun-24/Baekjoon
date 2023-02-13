#include <string>
#include <vector>
#include <stack>

using namespace std;
bool isCorrecting(string s){
    stack<bool> k;
    for(int i =0; i<s.length(); i++){
        if(s[i] == '(') k.push(true);
        else{
            if(s[i]== ')' and !k.empty()) k.pop();
            else return false;
        }
    }
    return (k.empty());
}

string splitStr(string p) {
    if (p.empty()) return p;

    string u, v;
    int count = 0;
    for (int i = 0; i < p.length(); i++) {
        (p[i] == '(') ? count++ : count--;
        if (count == 0) {
            u = p.substr(0, i+1);
            v = p.substr(i + 1, p.length()-i-1);
            break;
        }
    }

    if (isCorrecting(u)) return (u + splitStr(v));
    else {
        string a = ('(' + splitStr(v) + ')');
        u = u.substr(1, u.length()-2);
        for(int j = 0; j<u.length(); j++){
            u[j] = (u[j] == '(')? ')' : '(';
        }
        return (a+u);
    }
}


string solution(string p) {

    if(isCorrecting(p)) return p;

    else return splitStr(p);
}