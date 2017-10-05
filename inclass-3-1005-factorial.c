#include <stdio.h>
long long f(long long n) {
	if(n) return f(n-1)*n;
	else return 1;
}
int main() {
	for(int q=0; q<=20; q++) {
		printf("%d %lld\n", q, f(q));
	}
	int n;
	while(~scanf("%d", &n)) {
		printf("%lld\n", f(n));
	}
}

