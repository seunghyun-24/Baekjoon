#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(toupper(str[i]) != str[i]){
            printf("%c", toupper(str[i]));
        }
        else printf("%c", tolower(str[i]));
    }
    return 0;
}