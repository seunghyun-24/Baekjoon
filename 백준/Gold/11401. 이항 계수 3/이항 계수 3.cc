#include <iostream>

using namespace std;

#define DIV 1'000'000'007

long long temp;

long long power(long long a, long long m) {
	if (m == 0) return 1;

	temp = power(a, m / 2) % DIV;
	if (m % 2 == 1) return temp * temp % DIV * a % DIV;
	return temp * temp % DIV;
}

int main(void) {
	int n, k;

	cin >> n >> k;
    
	if (k == 1) { 
        cout << n; 
        return 0; 
    }
	if (k == 0 || n == k) { 
        cout << 1; 
        return 0; 
    }
	if (n - k == 1) { 
        cout << n; 
        return 0; 
    }

	long long A = 1, B = 1, ans;
	for (int i = n; i >= n - k + 1; i--) {
        A = (A * i) % DIV;
    }
	for (int i = 1; i <= k; i++) {
        B = (B * i) % DIV;
    }
    
	ans = ((A % DIV) * power(B, DIV - 2) % DIV) % DIV;
	cout << ans;

	return 0;
}