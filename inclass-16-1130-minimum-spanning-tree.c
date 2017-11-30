#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// graph
#define MAX_V 10
#define MAX_E 25
int G[MAX_V][MAX_V];
// disjoint set
int v[MAX_V];
int find(int n) {
	if(v[n] == n) return n;
	return v[n] = find(v[n]);
}
void merge(int a, int b){
	int ra = find(a);
	int rb = find(b);
	v[ra] = rb;
}
int same(int a, int b) {
	return find(a) == find(b);
}
// min heap
typedef struct {
	int a, b, v;
}Edge;
void swap(Edge *a, Edge *b) {
	Edge temp = *a;
	*a = *b;
	*b = temp;
}
typedef struct {
	Edge* heap;
	int size;
}Heap;
void init(Heap *h, int maxsize) {
	h->heap = (Edge*)malloc(maxsize * sizeof(Edge));
	for(int q=0; q<maxsize; q++) h->heap[q].v = INT_MAX;
	h->size = 0;
}
void push(Heap *h, Edge n) {
	h->size++;
	h->heap[h->size] = n;
	for(int p=h->size; p>=2; p/=2) {
		if(h->heap[p].v < h->heap[p/2].v) {
			swap(&h->heap[p], &h->heap[p/2]);
		}
	}
}
Edge top(Heap *h) {
	return h->heap[1];
}
void pop(Heap *h) {
	if(h->size > 0) {
		h->heap[1] = h->heap[h->size];
		h->heap[h->size].v = INT_MAX;
		h->size--;
		for(int p=1; ; ) {
			if(h->heap[p].v > h->heap[p*2].v && h->heap[p*2].v <= h->heap[p*2+1].v) {
				swap(&h->heap[p], &h->heap[p*2]);
				p = p*2;
			} else if(h->heap[p].v > h->heap[p*2+1].v && h->heap[p*2+1].v <= h->heap[p*2].v) {
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
// main
int main() {
	Heap heap;
	init(&heap, MAX_E*2);
	memset(G, 0, sizeof(G));
	for(int q=0; q<MAX_V; q++) {
		v[q] = q;
	}
	int a, b, c;
	printf("original edge\n");
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] != 0) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
		}
		c = rand()%20+1;
		G[a][b] = c;
		G[b][a] = c;
		Edge temp = {a, b, c};
		push(&heap, temp);
		printf("%d %d %d\n", a, b, c);
	}
	printf("-----\n");
	
	while(size(&heap)) {
		Edge temp = top(&heap);
		pop(&heap);
		if(!same(temp.a, temp.b)) {
			G[temp.a][temp.b] *= -1;
			G[temp.b][temp.a] *= -1;
			merge(temp.a, temp.b);
		}
	}
	
	printf("connected edge\n");
	for(int q=0; q<MAX_V; q++) {
		for(int w=q+1; w<MAX_V; w++) {
			if(G[q][w] > 0) {
				printf("%d %d %d\n", q, w, G[q][w]);
			} else if(G[q][w] < 0) {
				printf("%d %d [%d]\n", q, w, -G[q][w]);
			}
		}
	}
}
