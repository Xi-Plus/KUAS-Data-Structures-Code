#include <stdio.h>
long long f(long long n) {
	if(n) return f(n-1)*n;
	else return 1;
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		printf("%lld\n", f(n));
	}
}

