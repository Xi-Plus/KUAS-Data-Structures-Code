#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 20
#define MAX_V 100
int v[MAX_N];
int main() {
	srand(time(NULL));
	for(int q=0; q<MAX_N; q++) {
		v[q] = rand()%MAX_V+1;
		printf("%d ", v[q]);
	}
	printf("\n");
	
	for(int q=0; q<MAX_N-1; q++) {
		int idx = q+1;
		int val = v[idx];
		for(int w=q+2; w<MAX_N; w++) {
			if(v[w] < val) {
				val = v[w];
				idx = w;
			}
		}
		v[q] ^= v[idx] ^= v[q] ^= v[idx];
	}
	
	for(int q=0; q<MAX_N; q++) {
		printf("%d ", v[q]);
	}
	printf("\n");
}
