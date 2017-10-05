#include <stdio.h>
void f(int n, char from, char buffer, char to) {
	if (n == 1) {
		printf("%c -> %c\n", from, to);
	} else {
		f(n-1, from, to, buffer);
		printf("%c -> %c\n", from, to);
		f(n-1, buffer, from, to);
	}
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		f(n, 'A', 'B', 'C');
		printf("\n");
	}
}

