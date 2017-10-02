#include<stdlib.h>
#include<string.h>
#include<stdio.h>
long long f(long long n) {
	if(n) return f(n-1)*n;
	else return 1;
}
int main() {
	printf("%lld\n", f(10));
	char s[]="123456789";
	char s2[]="987";
	strncpy(s, s2, 3);
	s[6]=0;
	strcpy(s, s2);
	printf("%s", s);
}
