#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_N 20
#define MAX_V 100
int v[MAX_N];
void quicksort(int l, int r) {
	if(l >= r) return;
	
	if(l >= r-1) {
		if(v[l] > v[r]) {
			v[l] ^= v[r] ^= v[l] ^= v[r];
		}
		return;
	}
	
	int pivot = v[l];
	int i = l+1, j = r;
	while(i < j) {
		while(v[i] < pivot && i < j) i++;
		while(v[j] > pivot && i < j) j--;
		if(i < j) {
			if(v[i] > v[j]) {
				v[i] ^= v[j] ^= v[i] ^= v[j];
			}
			i++;
			j--;
		}
	}
	int k = (i < j ? i : j);
	if(v[k] > v[l]) k--;
	
	if(l != k) {
		v[l] ^= v[k] ^= v[l] ^= v[k];
	}
	
	quicksort(l, k-1);
	quicksort(k+1, r);
}
void print() {
	for(int q=0; q<MAX_N; q++) {
		printf("%2d ", q);
	}
	printf("\n");
	for(int q=0; q<MAX_N; q++) {
		printf("%d ", v[q]);
	}
	printf("\n");
}
int main() {
	srand(time(NULL));
	for(int q=0; q<MAX_N; q++) {
		v[q] = rand()%90+10;
		printf("%d ", v[q]);
	}
	printf("\n");
	
	quicksort(0, MAX_N-1);
	
	for(int q=0; q<MAX_N; q++) {
		printf("%d ", v[q]);
	}
	printf("\n");
}
