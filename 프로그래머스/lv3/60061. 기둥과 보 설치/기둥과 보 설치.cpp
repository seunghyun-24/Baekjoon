#include <set>
#include <string>
#include <vector>

using namespace std;

#define has(a) (building.find(simul[(a)]) != building.end())

bool isValid(const set<vector<int>>& building){
    for(auto build : building){
        int x = build[0], y = build[1], k = build[2];

        if(k == 0){
            vector<int> simul[3]={ {x, y-1, 0}, {x-1, y, 1}, {x, y, 1} };
            if( y == 0 || has(0) || has(1) || has(2)) continue;
            return false;
        }
        else{
            vector<int> simul[4]={ {x, y-1, 0}, {x+1, y-1, 0},{x+1, y, 1},{x-1, y, 1} };
            if (has(0) || has(1) || (has(2) && has(3)) ) continue;
            return false;
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    set<vector<int>> building;

    for(auto build : build_frame){
        vector<int> v = { build[0], build[1], build[2] };
        if(build[3] == 0){
            building.erase(v);
            if(!isValid(building)) building.insert(v);
        }
        else{
            building.insert(v);
            if(!isValid(building)) building.erase(v);
        }
    }

    for(auto a: building)
        answer.push_back(a);

    return answer;
}