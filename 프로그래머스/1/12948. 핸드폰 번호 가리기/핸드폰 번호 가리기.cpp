#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int a = phone_number.length();
    for(int i = 0; i < a-4; i++){
        phone_number.replace(i, 1, "*");
    }
    return phone_number;
}