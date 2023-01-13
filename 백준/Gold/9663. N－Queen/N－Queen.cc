#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int b[15];

int promising(int cdx) {

	for (int i = 0; i < cdx; i++) {
		if (b[cdx] == b[i] || cdx - i == abs(b[cdx] - b[i])) {
			return 0;
		}
	}

	return 1;
}

void queen(int cdx) {

	if (cdx == n) {
		count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		b[cdx] = i;
		if (promising(cdx)) { 
			queen(cdx + 1);
		}
	}

}

int main() {

	scanf("%d", &n);
	queen(0);
	printf("%d", count);

}