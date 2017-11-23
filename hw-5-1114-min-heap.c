#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct {
	int* heap;
	int size;
}Heap;
void init(Heap *h, int maxsize) {
	h->heap = (int*)malloc(maxsize * sizeof(int));
	for(int q=0; q<maxsize; q++) h->heap[q] = INT_MAX;
	h->size = 0;
}
void push(Heap *h, int n) {
	h->size++;
	h->heap[h->size] = n;
	for(int p=h->size; p>=2; p/=2) {
		if(h->heap[p] < h->heap[p/2]) {
			swap(&h->heap[p], &h->heap[p/2]);
		}
	}
}
int top(Heap *h) {
	if(h->size == 0) return -1;
	return h->heap[1];
}
void pop(Heap *h) {
	if(h->size > 0) {
		h->heap[1] = h->heap[h->size];
		h->heap[h->size] = INT_MAX;
		h->size--;
		for(int p=1; ; ) {
			if(h->heap[p] > h->heap[p*2] && h->heap[p*2] < h->heap[p*2+1]) {
				swap(&h->heap[p], &h->heap[p*2]);
				p = p*2;
			} else if(h->heap[p] > h->heap[p*2+1] && h->heap[p*2+1] < h->heap[p*2]) {
				swap(&h->heap[p], &h->heap[p*2+1]);
				p = p*2 + 1;
			} else {
				break;
			}
		}
	} else {
		printf("nothing to pop\n");
	}
}
int size(Heap *h) {
	return h->size;
}
int main() {
	Heap heap;
	init(&heap, MAX_SIZE);
	char cmd[10];
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "push") == 0) {
			scanf(" %d", &n);
			push(&heap, n);
		} else if (strcmp(cmd, "pop") == 0) {
			pop(&heap);
		} else if (strcmp(cmd, "top") == 0) {
			printf("%d\n", top(&heap));
		} else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", size(&heap));
		} else {
			printf("no command\n");
		}
		for (int q=1; q <= heap.size; q++) {
			printf("%d\t", heap.heap[q]);
		}
		printf("\n");
	}
}

