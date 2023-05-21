#include <iostream>
#define ll long long

using namespace std;
 
struct P {
    ll x, y;
    bool operator<=(P const &p1) {
        if(x == p1.x) return y <= p1.y;
        return x <= p1.x;
    }
};
 
struct Line {
    P p1, p2;  
};
 
Line line[2];
 
int CCW(const P &p1, const P &p2, const P &p3){
    ll res = (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - 
              (p2.x*p1.y + p3.x*p2.y + p1.x*p3.y);
    
    if(res > 0) return 1;   //반시계
    else if(res < 0) return -1;     //시계
    else return 0;
}
 
bool isline_intersect(Line& l1, Line &l2){
    int std1, std2;
    
    std1 = CCW(l1.p1, l1.p2, l2.p1) * CCW(l1.p1, l1.p2, l2.p2);
    std2 = CCW(l2.p1, l2.p2, l1.p1) * CCW(l2.p1, l2.p2, l1.p2);
    
    if(std1 <= 0 && std2 <= 0){
        if(std1 == 0 && std2 == 0){     //선분이 일직선인 경우
            if(l1.p2 <= l1.p1) swap(l1.p1, l1.p2);
            if(l2.p2 <= l2.p1) swap(l2.p1, l2.p2);
            
            return l1.p1 <= l2.p2 && l2.p1 <= l1.p2;
        }
        else return true;   //일직선이 아니면 교차함
    }
    else return false;  //CCW가 같은 방향이 있으면 
}
 
int main(){
    
    ll x1, x2, y1, y2;
    P p1, p2;
    
    for(int i = 0 ; i < 2; i++){
        cin >> p1.x >> p1.y >> p2.x >> p2.y;
        line[i].p1 = p1;
        line[i].p2 = p2;
    }
    
    if (isline_intersect(line[0], line[1])) cout << 1;
    else cout << 0;
    
    return 0;
}
