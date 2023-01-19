#include <iostream>
using namespace std;
void init();

int arr[100001];
int sum[100002] = {0};

int main() {
	init();
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i<N; i++){
	    cin >> arr[i];
	    sum[i+1] = sum[i] + arr[i];
	}
	
	for(int i = 0; i<M; i++){
	    int a, b;
	    cin >> a >> b;
	    cout << sum[b] - sum[a-1] << '\n';
	}
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
