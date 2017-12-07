#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define RUN 5
// graph
#define MAX_V 10
#define MAX_E 15
int G[MAX_V][MAX_V];
int G2[MAX_V][MAX_V];
int visited[MAX_V];
int main() {
	srand(time(NULL));
	printf("original edge\n");
	memset(G, 0, sizeof(G));
	int a, b, c;
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] != 0) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
			if(a>b) a^=b^=a^=b;
		}
		G[a][b] = 1;
		printf("%d %d\n", a, b);
	}
	printf("-----\n");
	for(int q=0; q<RUN; q++) {
		memset(visited, 0, sizeof(visited));
		int t[MAX_V];
		for(int q=0; q<MAX_V; q++) {
			t[q] = q;
		}
		for(int q=MAX_V-1; q>=2; q--) {
			int tt = rand()%q;
			t[q]^=t[tt]^=t[q]^=t[tt];
		}
		memcpy(G2, G, sizeof(G));
		int count = MAX_V;
		while(count) {
			for(int w=0; w<MAX_V; w++) {
				int now = t[w];
				if(visited[now]) continue;
				int root = 1;
				for(int e=0; e<MAX_V; e++) {
					if(G2[e][now]) {
						root = 0;
						break;
					}
				}
				if(root) {
					printf("%d ", now);
					visited[now] = 1;
					count--;
					for(int e=0; e<MAX_V; e++) {
						G2[now][e] = 0;
					}
					break;
				}
			}
		}
		printf("\n");
	}
}
