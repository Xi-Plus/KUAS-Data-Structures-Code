#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int v[100];
long long f(long long n) {
	if(v[n] != -1) return v[n];
	else return v[n] = f(n-1)+f(n-2);
}
int main() {
	memset(v, -1, sizeof(v));
	v[0] = 0;
	v[1] = 1;
	for(int q=0; q<=46; q++) {
		printf("%d %lld\n", q, f(q));
	}
	int n;
	while(~scanf("%d", &n)) {
		printf("%lld\n", f(n));
	}
}

