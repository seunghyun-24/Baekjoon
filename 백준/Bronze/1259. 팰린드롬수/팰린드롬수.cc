#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;


int main() {
	string N;

    while (N!="0") {
        cin >> N;
        string buf = N;
        reverse(N.begin(), N.end()); // 앞 뒤 바꿈
        
        if ( N=="0") { break;}
        else if(N == buf) { // 비교
            cout <<"yes\n";
        }
        else {
            cout <<"no\n";
        }
    }  
}