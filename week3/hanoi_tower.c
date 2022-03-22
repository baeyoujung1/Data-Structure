#include <stdio.h>
#pragma warning(disable:4996)

void hanoi(int n, char from, char middle, char to);
int a;

int main() {
	int n;
	printf("원판의 개수를 입력하시오:");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');
	printf("총 이동 횟수: %d", a);
}
void hanoi(int n, char from, char middle, char to) {
	if (n == 1) {
		printf("1번 원판을 %c에서 %c로 이동\n", from, to);
		a++;
	}
	else {
		hanoi(n - 1, from, to, middle);
		printf("%d번 원판을 %c에서 %c로 이동\n", n, from, to);
		a++;
		hanoi(n - 1, middle, from, to);
	}
}