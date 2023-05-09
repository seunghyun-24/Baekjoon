#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define ll long long int
using namespace std;

int N, M, x;
ll cnt[1001];
ll sum, ans;

void setting();

int main() {
	
    setting();
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= 1000; i++) {
		ans += cnt[i] * (cnt[i] - 1) / 2;
	}
	
	cout << cnt[0] + ans;
}

void setting(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
}