#include <stdio.h>

#pragma warning(disable:4996)

int main(void) {
	int number, ranking, count;

	scanf("%d %d", &number, &ranking);

	ranking--;

	for (count = 1; count <= number; count++) {
		if (number % count == 0) {
			if (ranking == 0) {
				printf("%d", count);
				
				return 0;
			}

			else {
				ranking--;
			}
		}
	}

	printf("0");

	return 0;
}