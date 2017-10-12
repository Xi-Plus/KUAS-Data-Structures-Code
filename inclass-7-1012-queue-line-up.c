#include <stdio.h>
#define MAX_SIZE 100
int queue[2][MAX_SIZE]={0};
int s[2]={0}, e[2]={0};
int size(int K) {
	return e[K]-s[K];
}
void refresh(int K) {
	if (s[K] == 0) return;
	int sz = size(K);
	for(int q=0; q<sz; q++) {
		queue[K][q] = queue[K][s[K]+q];
	}
	s[K] = 0;
	e[K] = sz;
}
int push(int K, int n) {
	if (e[K] == MAX_SIZE) {
		refresh(K);
	}
	if (e[K] == MAX_SIZE) {
		return 0;
	}
	queue[K][e[K]++]=n;
	return 1;
}
int front(int K) {
	if (size(K)) {
		return queue[K][s[K]];
	} else {
		return -1;
	}
}
int pop(int K) {
	if (size(K)) {
		s[K]++;
		return 1;
	}
	return 0;
}
int back(int K) {
	if (size(K)) {
		return queue[K][e[K]-1];
	} else {
		return -1;
	}
}
int main() {
	int n;
	while(~scanf("%d", &n)) {
		if (n > 0) {
			if (size(0) <= size(1)) {
				push(0, n);
			} else {
				push(1, n);
			}
		} else if (n == -1) {
			pop(0);
		} else if (n == -2) {
			pop(1);
		}
		for(int q=0; q<=1; q++) {
			int sz = size(q);
			printf(" > ");
			for(int w=s[q]; w<s[q]+sz; w++) {
				printf("%d ", queue[q][w]);
			}
			printf("\n");
		}
	}
}

