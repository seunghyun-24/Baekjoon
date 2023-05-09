#include <iostream>

using namespace std;
//양수 A의 가장 작은 약수가 min, 가장 큰 약수 max =  A/min
//가장 작은 약수 * 가장 큰 약수 = 해당 수

void selectSort(int arr[], int n) {
	int i, j, m, t;
    
	for (i = 0; i < n; i++) {
		m = i;
        for (j = i; j < n; j++){
			if (arr[m] > arr[j]) m = j;
		}

		t = arr[i];
		arr[i] = arr[m];
		arr[m] = t;
	}
}

int main(){
    
	int N; int arr[51];

	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	selectSort(arr, N);

	cout << arr[0] * arr[N-1];
}