#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
	int x, y, s;
};
bool cmp(Node a, Node b) {
	return a.s < b.s;
}
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int r, c, sx, sy, t;
int dfs(int *map, int nowx, int nowy, int depth) {
	*(map+(c+4)*nowx+nowy) = depth;
	if(depth == r * c) {
		return 1;
	}
	vector<Node> v;
	for(int q=0; q<8; q++) {
		int nx = nowx+dx[q];
		int ny = nowy+dy[q];
		if(*(map+((c+4)*nx)+ny) == 0) {
			int cnt = 0;
			for(int w=0; w<8; w++) {
				int nnx = nx+dx[w];
				int nny = ny+dy[w];
				if(*(map+((c+4)*nnx)+nny) == 0) {
					cnt++;
				}
			}
			v.push_back({nx, ny, cnt});
		}
	}
	sort(v.begin(), v.end(), cmp);
	for(int q=0; q<v.size(); q++) {
		if(dfs(map, v[q].x, v[q].y, depth+1)) return 1;
	}
	*(map+(c+4)*nowx+nowy) = 0;
	return 0;
}
int main() {
	while(~scanf("%d %d %d %d", &r, &c, &sx, &sy)) {
		if (sx < 1 || sx > r || sy < 1 || sy > c) {
			printf("input error\n");
			continue;
		}
		int map[r+4][c+4];
		memset(map, 0, (r+4) * (c+4) * sizeof(int));
		for(int q=0; q<r+4; q++){
			map[q][0] = -1;
			map[q][1] = -1;
			map[q][c+2] = -1;
			map[q][c+3] = -1;
			map[0][q] = -1;
			map[1][q] = -1;
			map[r+2][q] = -1;
			map[r+3][q] = -1;
		}
		sx++;
		sy++;
		if(dfs((int*)map, sx, sy, 1)) {
			printf("Yes\n");
			for(int q=2; q<=r+1; q++) {
				printf("%3d", map[q][2]);
				for(int w=3; w<=c+1; w++) {
					printf(" %3d", map[q][w]);
				}
				printf("\n");
			}
		} else {
			printf("No\n");
		}
	}
}

