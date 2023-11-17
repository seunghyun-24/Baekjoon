#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y){
    int temp;    
    
    while(y != 0){        
        temp = x%y;        
        x = y;        
        y = temp;    
    }    
    return x;
}


int solution(vector<int> arr) {
    
    int val = arr[0];
    for(int i = 1; i < arr.size(); i++){
        val = (arr[i] * val) / gcd(arr[i], val);
    }
    
    int answer = 0;
    return val;
}