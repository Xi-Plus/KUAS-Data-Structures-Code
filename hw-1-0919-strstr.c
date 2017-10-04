#include <stdio.h>
#include <string.h>

int mystrstr(char *haystack, char *needle) {
	if(*needle == 0) {
		return 0;
	}
	for(unsigned q=0; *(haystack+q) != 0; q++) {
		for(unsigned w=0; *(needle+w) != 0; w++) {
			if(*(haystack+q+w) != *(needle+w)) {
				break;
			}
			if(w == strlen(needle)-1) {
				return q;
			}
		}
	}
	return -1;
}
int main() {
	char a[100],b[100];
	while(~scanf("%s %s", a, b)) {
		printf("%d\n", mystrstr(a, b));
	}
	return 0;
}
