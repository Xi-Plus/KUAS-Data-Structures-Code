#include <stdio.h>
long long f(long long n) {
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return f(n-1)+f(n-2);
}
int main() {
	for(int q=0; q<=46; q++) {
		printf("%d %lld\n", q, f(q));
	}
	int n;
	while(~scanf("%d", &n)) {
		printf("%lld\n", f(n));
	}
}

