#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_V 10
#define MAX_E 20
int G[MAX_V][MAX_V];
int visit[MAX_V];
int count;
void dfs(int v) {
	visit[v] = count++;
	for(int q=0; q<MAX_V; q++) {
		if(visit[q] == -1 && G[v][q] == 1) {
			G[v][q] = 2;
			G[q][v] = 2;
			dfs(q);
		}
	}
}
int main() {
	memset(G, 0, sizeof(G));
	memset(visit, -1, sizeof(visit));
	srand(time(NULL));
	int a, b;
	printf("original edge\n");
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] == 1) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
		}
		G[a][b] = 1;
		G[b][a] = 1;
		printf("%d %d\n", a, b);
	}
	printf("-----\n");
	printf("original adjacency matrix\n");
	for(int q=0; q<MAX_V; q++) {
		for(int w=0; w<MAX_V; w++) {
			printf("%d ", G[q][w]);
		}
		printf("\n");
	}
	printf("-----\n");
	printf("-----\n");
	
	count = 0;
	for(int q=0; q<MAX_V; q++) {
		if(visit[q] == -1) {
			dfs(q);
		}
	}
	
	int cycle = 0;
	printf("connected edge\n");
	for(int q=0; q<MAX_V; q++) {
		for(int w=q+1; w<MAX_V; w++) {
			if(G[q][w] != 0) {
				printf("%d %d", q, w);
				if(G[q][w] == 2) {
					printf(" V");
				} else {
					cycle = 1;
				}
				printf("\n");
			}
		}
	}
	if (cycle) {
		printf("has cycle\n");
	} else {
		printf("no cycle\n");
	}
	printf("-----\n");
	printf("connected adjacency matrix\n");
	for(int q=0; q<MAX_V; q++) {
		for(int w=0; w<MAX_V; w++) {
			printf("%d ", G[q][w]);
		}
		printf("\n");
	}
	printf("-----\n");
	
	printf("dfn\n");
	for(int q=0; q<MAX_V; q++) {
		printf("%d %d\n", q, visit[q]);
	}
}
