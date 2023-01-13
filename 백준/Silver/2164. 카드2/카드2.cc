#include <stdio.h>
#include <queue> 

using namespace std;

int main(){

    queue<int> q;
    int n;
    scanf("%d", &n);

    for(int i = 1; i<=n; i++){
        q.push(i);
    }

    while(n!=1){
        q.pop();
        n--;
        int b = q.front();
        if (n==1) break;
        q.push(b);
        q.pop();
        
    }

    printf("%d", q.front());
}