#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
	int x, y;
}Node;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char ans[] = {'1', '0', '*'};
int r, c, sx, sy, ex, ey, t;
int dfs(int *map, int *visit, int nowx, int nowy, int depth, Node* answer) {
	*(visit+(c+1)*nowx+nowy) = 1;
	if(nowx == ex && nowy == ey) {
		*(answer+depth) = (Node){nowx, nowy};
		return depth;
	}
	for(int q=0; q<8; q++) {
		int nx = nowx+dx[q];
		int ny = nowy+dy[q];
		if(*(map+((c+2)*nx)+ny) && !*(visit+(c+1)*nx+ny)) {
			t = dfs(map, visit, nx, ny, depth+1, answer);
			if (t) {
				*(answer+depth) = (Node){nowx, nowy};
				return t;
			} 
		}
	}
	return 0;
}
int main() {
	while(~scanf("%d %d %d %d %d %d", &r, &c, &sx, &sy, &ex, &ey)) {
		int map[r+2][c+2];
		int visit[r+1][c+1];
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for(int q=1; q<=r; q++){
			for(int w=1; w<=c; w++){
				scanf("%d", &t);
				map[q][w] = 1-t; // in my map, road is 1, wall is 0
			}
		}
		Node *answer = malloc(r * c * sizeof(Node));
		t = dfs((int*)map, (int*)visit, sx, sy, 1, answer);
		if(t) {
			printf("Yes\n");
			for(int q=t; q>=1 ;q--) {
				map[(*(answer+q)).x][(*(answer+q)).y] = 2;
			}
			for(int q=1;q<=r;q++) {
				printf("%c", ans[map[q][0]]);
				for(int w=2; w<=c; w++) {
					printf(" %c", ans[map[q][w]]);
				}
				printf("\n");
			}
		} else {
			printf("No\n");
		}
	}
}

