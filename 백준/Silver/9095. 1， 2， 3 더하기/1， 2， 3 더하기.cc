#include <iostream>
using namespace std;

int n;
int arr[11];



int solve(int k){
    if(!arr[k]){
        
        if(!arr[k-1]) solve(k-1);
        if(!arr[k-2]) solve(k-2);
        if(!arr[k-3]) solve(k-3);
        
        arr[k] = arr[k-1] + arr[k-2] + arr[k-3];   
    }
    
    return arr[k];
    
}

int main(){
    int y;
    cin >> n;
    arr[1]=1;
    arr[2]=2;
    arr[3]=4;
    for(int i = 0; i < n; i++){
        cin >> y;
        int ans = solve(y);
        cout << ans << endl;
    }
    
    return 0;
}