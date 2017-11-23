#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 20
int v[MAX_SIZE];
int main() {
	srand(time(NULL));
	for(int q=0; q<MAX_SIZE; q++) {
		v[q] = rand()%100;
	}
	for(int q=0; q<MAX_SIZE-1; q++) {
		for(int w=0; w<MAX_SIZE-1; w++) {
			if(v[w] > v[w+1]) {
				int temp = v[w];
				v[w] = v[w+1];
				v[w+1] = temp;
			}
		}
	}
	for(int q=0; q<MAX_SIZE; q++) {
		printf("%d ", v[q]);
	}
	printf("\n");
	int n;
	while(~scanf("%d", &n)) {
		int l = 0;
		int r = MAX_SIZE-1;
		while(l <= r) {
			int m = (l+r) / 2;
			if(v[m] == n) {
				l = m;
				break;
			} else if (v[m] < n) {
				l = m+1;
			} else {
				r = m-1;
			}
		}
		if(l > r) {
			printf("not found\n");
		} else {
			printf("found at %d\n", l);
		}
	}
}

