#include <stdio.h>

int main(){
    int a,b=0;
    scanf("%d %d", &a, &b);
    
    if (a==b){
        printf("==");
    }
    else if (a>b){
        printf(">");
    }
    else printf("<");
    
    return 0;
}