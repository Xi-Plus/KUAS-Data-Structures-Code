#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// graph
#define MAX_V 20
#define MAX_E 20
int G[MAX_V][MAX_V];
int visited[MAX_V];
int count = 0;
void dfs(int p) {
	visited[p] = 1;
	printf("%d ", p);
	for (int i = 0; i < MAX_V; i++) {
		if (!visited[i] && G[p][i]) {
			dfs(i);
		}
	}
}
int main() {
	srand(time(NULL));
	printf("edge\n");
	memset(G, 0, sizeof(G));
	int a, b;
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] != 0) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
		}
		G[a][b] = 1;
		G[b][a] = 1;
		printf("%d %d\n", a, b);
	}
	for (int i = 0; i < MAX_V; i++) {
		printf("%d %d\n", i, i);
	}
	printf("\nvisit\n");
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < MAX_V; i++) {
		if (!visited[i]) {
			count++;
			dfs(i);
			printf("\n");
		}
	}
	printf("count = %d\n", count);
	return 0;
}
