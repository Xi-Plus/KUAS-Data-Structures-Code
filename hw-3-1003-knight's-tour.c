#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
	int x, y, dir;
}Node;
typedef struct {
	Node* stack;
	int size;
}Stack;
void init(Stack *s, int maxsize) {
	s->stack = (Node*)malloc(maxsize * sizeof(Node));
	s->size = 0;
}
void push(Stack *s, Node n) {
	*(s->stack+s->size) = n;
	s->size++;
}
Node top(Stack *s) {
	return *(s->stack+s->size-1);
}
void pop(Stack *s) {
	s->size--;
}
int size(Stack *s) {
	return s->size;
}
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int r, c, sx, sy;
int main() {
	int nx, ny;
	Node tn;
	while(~scanf("%d %d %d %d", &r, &c, &sx, &sy)) {
		if (sx < 1 || sx > r || sy < 1 || sy > c) {
			printf("input error\n");
			continue;
		}
		Stack stack;
		init(&stack, r*c);
		int map[r+4][c+4];
		memset(map, 0, sizeof(map));
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
		int nowx = sx+1, nowy = sy+1, cnt = 1, nowdir = 0;
		map[nowx][nowy] = cnt;
		while(1) {
			if(cnt == r * c){
				push(&stack, (Node){nowx, nowy, -1});
				break;
			}
			for(; nowdir<8; nowdir++) {
				nx = nowx+dx[nowdir];
				ny = nowy+dy[nowdir];
				if(map[nx][ny] == 0) {
					push(&stack, (Node){nowx, nowy, nowdir});
					nowx = nx;
					nowy = ny;
					nowdir = 0;
					map[nowx][nowy] = ++cnt;
					break;
				}
			}
			if(nowdir == 8) {
				if (size(&stack) == 0) {
					break;
				}
				map[nowx][nowy] = 0;
				cnt--;
				tn = top(&stack);
				pop(&stack);
				nowx = tn.x;
				nowy = tn.y;
				nowdir = tn.dir+1;
			}
		}
		if (size(&stack)) {
			printf("Yes\n");
			for(int q=2; q<=r+1; q++) {
				printf("%2d", map[q][2]);
				for(int w=3; w<=c+1; w++) {
					printf(" %2d", map[q][w]);
				}
				printf("\n");
			}
		} else {
			printf("No\n");
		}
	}
}

