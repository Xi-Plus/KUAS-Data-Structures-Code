#include <stdio.h>
#include <time.h>
#include <string.h>
#include <algorithm>
#define MAX_V 20
#define MAX_E 15
bool graph[MAX_V][MAX_V] = {};
int dfsn[MAX_V];
void dfs(int p, int d) {
	dfsn[p] = d;
	for(int q=0; q<MAX_V; q++) {
		if(graph[p][q] && dfsn[q] == -1) {
			dfs(q, d+1);
		}
	}
}
int main() {
	srand(time(NULL));
	memset(dfsn, -1, sizeof(dfsn));
	int a, b;
	for(int q=0; q<MAX_E; q++) {
		a = b = -1;
		while(a == b || graph[a][b]) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
		}
		graph[a][b] = true;
		graph[b][a] = true;
	}
	for(int q=0; q<MAX_V; q++) {
		if(dfsn[q] == -1) dfs(q, 0);
	}
	bool bipartite = true;
	for(int q=0; q<MAX_V-1; q++) {
		for(int w=q+1; w<MAX_V; w++) {
			if(graph[q][w] && dfsn[q] != -1 && dfsn[w] != -1) {
				if(!((dfsn[q] ^ dfsn[w]) & 1)) {
					bipartite = false;
				}
				printf("%d-%d %d-%d\n", q, dfsn[q], w, dfsn[w]);
			}
		}
	}
	if(bipartite) {
		printf("bipartite\n");
	} else {
		printf("not bipartite\n");
	}
}

