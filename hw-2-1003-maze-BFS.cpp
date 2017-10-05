#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;
typedef struct {
	int x, y;
}Node;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char ans[] = {'1', '0', '*'};
int r, c, sx, sy, ex, ey, t;
int main() {
	int nx, ny;
	Node tn;
	while(~scanf("%d %d %d %d %d %d", &r, &c, &sx, &sy, &ex, &ey)) {
		int map[r+2][c+2];
		int from[r+1][c+1];
		memset(map, 0, (r+2)*(c+2)*sizeof(int));
		memset(from, 0, (r+1)*(c+1)*sizeof(int));
		for(int q=1; q<=r; q++){
			for(int w=1; w<=c; w++){
				scanf("%d", &t);
				map[q][w] = 1-t; // in my map, road is 1, wall is 0
			}
		}
		from[sx][sy] = 0;
		queue<Node> que;
		que.push({sx, sy});
		while(!que.empty()) {
			tn = que.front();
			que.pop();
			for(int q=0; q<8; q++) {
				nx = tn.x+dx[q];
				ny = tn.y+dy[q];
				if(map[nx][ny] && !from[nx][ny]) {
					from[nx][ny] = tn.x*(c+2)+tn.y;
					que.push({nx, ny});
				}
			}
		}
		if(from[ex][ey]) {
			printf("Yes\n");
			map[ex][ey] = 2;
			while(ex != sx || ey != sy) {
				nx = from[ex][ey]/(c+2);
				ny = from[ex][ey]%(c+2);
				map[nx][ny] = 2;
				ex = nx;
				ey = ny;
			}
			for(int q=1;q<=r;q++) {
				printf("%c", ans[map[q][1]]);
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

