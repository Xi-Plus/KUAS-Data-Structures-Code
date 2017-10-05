#include <stdio.h>
void f(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c -> %c\n", a, c);
	} else {
		f(n-1, a, c, b);
		printf("%c -> %c\n", a, c);
		f(n-1, b, a, c);
	}
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		f(n, 'A', 'B', 'C');
		printf("\n");
	}
}

