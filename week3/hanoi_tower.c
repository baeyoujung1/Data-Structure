#include <stdio.h>
#pragma warning(disable:4996)

void hanoi(int n, char from, char middle, char to);
int a;

int main() {
	int n;
	printf("������ ������ �Է��Ͻÿ�:");
	scanf("%d", &n);

	hanoi(n, 'A', 'B', 'C');
	printf("�� �̵� Ƚ��: %d", a);
}
void hanoi(int n, char from, char middle, char to) {
	if (n == 1) {
		printf("1�� ������ %c���� %c�� �̵�\n", from, to);
		a++;
	}
	else {
		hanoi(n - 1, from, to, middle);
		printf("%d�� ������ %c���� %c�� �̵�\n", n, from, to);
		a++;
		hanoi(n - 1, middle, from, to);
	}
}