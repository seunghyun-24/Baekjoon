#include <bits/stdc++.h>
#include <string>

#define ll long long int
#define ull unsigned long long int
#define lll __int128_t
#define ld long double
#define INF (int)1e9
#define INFLL (long long)1e18
#define pii pair<int, int>
#define pll pair<long long int, long long int>
#define all(x) (x).begin(), (x).end()
#define MOD (INF + 7)

using namespace std;
void init();

#define MAX 105

typedef struct SHARK {
    int R, C, S, D, Z;
    bool isLive = true;
}SHARK;

int R, C, M;
vector<SHARK> Shark;
int Fisher = 0;
int moveY[5] = { 0,-1,1,0,0 };
int moveX[5] = { 0,0,0,1,-1 };
int answer = 0;
int MAP[MAX][MAX];

void Shark_Moving(int IDX) {
    int Len = Shark[IDX].S;
    int Dir = Shark[IDX].D;
    int Y = Shark[IDX].R;
    int X = Shark[IDX].C;
    if ((Dir == 1) || (Dir == 2)) {
        Len %= ((R - 1) * 2);
    }
    else if ((Dir == 3) || (Dir == 4)) {
        Len %= ((C - 1) * 2);
    }
    while (Len--) {
        int nextY = Y + moveY[Dir];
        int nextX = X + moveX[Dir];
        if ((nextY < 1) || (nextY > R) || (nextX < 1) || (nextX > C)) {
            if (Dir == 1) {
                Dir = 2;
            }
            else if (Dir == 2) {
                Dir = 1;
            }
            else if (Dir == 3) {
                Dir = 4;
            }
            else if (Dir == 4) {
                Dir = 3;
            }
            nextY = Y + moveY[Dir];
            nextX = X + moveX[Dir];
        }
        Y = nextY;
        X = nextX;
    };
    Shark[IDX].D = Dir;
    Shark[IDX].R = Y;
    Shark[IDX].C = X;
    MAP[Y][X]++;
}

void Shark_Eating(int Y, int X) {
    int Big = -1;
    int Big_IDX = 0;
    for (int i = 1; i <= M; i++) {
        if ((Shark[i].isLive) && (Shark[i].R == Y) && (Shark[i].C == X)) {
            if (Big < Shark[i].Z) {
                Big = Shark[i].Z;
                Big_IDX = i;
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        if ((Shark[i].isLive) && (Shark[i].R == Y) && (Shark[i].C == X)) {
            if (Big != Shark[i].Z) {
                Shark[i].isLive = false;
            }
        }
    }
    MAP[Y][X] = 1;
}

int main() {
    init();
    cin >> R >> C >> M;
    Shark.resize(M + 1);
    for (int i = 1; i <= M; i++) {
        int R, C, S, D, Z;
        cin >> Shark[i].R >> Shark[i].C >> Shark[i].S >> Shark[i].D >> Shark[i].Z;
        MAP[Shark[i].R][Shark[i].C]++;
    }
    while(1) {
        Fisher++;
        if (Fisher > C) {
            break;
        }
        for (int i = 1; i <= R; i++) {
            if (MAP[i][Fisher] == 1) {
                int Cur_Shark;
                for (int j = 1; j <= M; j++) {
                    if ((Shark[j].isLive) && (Shark[j].R == i) && (Shark[j].C == Fisher)) {
                        Cur_Shark = j;
                        break;
                    }
                }
                Shark[Cur_Shark].isLive = false;
                answer += Shark[Cur_Shark].Z;
                break;
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                MAP[i][j] = 0;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (Shark[i].isLive) {
                int nextY = Shark[i].R + moveY[Shark[i].D];
                int nextX = Shark[i].C + moveX[Shark[i].D];
                Shark_Moving(i);
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int j = 1; j <= C; j++) {
                if (MAP[i][j] >= 2) {
                    Shark_Eating(i, j);
                }
            }
        }
    }
    cout << answer << "\n";

    return 0;
}

void init() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt+", stdin);
    freopen("output.txt", "wt+", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}