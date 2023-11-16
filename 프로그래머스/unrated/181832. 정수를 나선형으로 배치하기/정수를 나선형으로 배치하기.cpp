#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = 1;
    int startX = 0, endX = n - 1;
    int startY = 0, endY = n - 1;
    while (num <= n * n) {
        for(int i = startY; i <= endY; ++i){
            answer[startX][i] = num++;
        }
        startX++;
        for(int i = startX; i <= endX; ++i){
            answer[i][endY] = num++;
        }
        endY--;
        for(int i = endY; i >= startY; --i){
            answer[endX][i] = num++;
        }
        endX--;
        for(int i = endX; i >= startX; --i){
            answer[i][startY] = num++;
        }
        startY++;
    }    
    return answer;
}