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
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
char ans[] = {'1', '0', '*'};
int main() {
	int r, c, sx, sy, ex, ey;
	int t, nx, ny;
	Node tn;
	while(~scanf("%d %d %d %d %d %d", &r, &c, &sx, &sy, &ex, &ey)) {
		Stack stack;
		init(&stack, r*c);
		int map[r+2][c+2];
		int visit[r+1][c+1];
		memset(map, 0, sizeof(map));
		memset(visit, 0, sizeof(visit));
		for(int q=1; q<=r; q++){
			for(int w=1; w<=c; w++){
				scanf("%d", &t);
				map[q][w] = 1-t; // in my map, road is 1, map is 0
			}
		}
		int nowx = sx, nowy = sy, nowdir = 0;
		while(1) {
			visit[nowx][nowy] = 1;
			if(nowx == ex && nowy == ey){
				push(&stack, (Node){nowx, nowy, -1});
				break;
			}
			for(; nowdir<8; nowdir++) {
				nx = nowx+dx[nowdir];
				ny = nowy+dy[nowdir];
				if(map[nx][ny] && !visit[nx][ny]) {
					push(&stack, (Node){nowx, nowy, nowdir});
					nowx = nx;
					nowy = ny;
					nowdir = 0;
					break;
				}
			}
			if(nowdir == 8) {
				if (size(&stack) == 0) {
					break;
				}
				tn = top(&stack);
				pop(&stack);
				nowx = tn.x;
				nowy = tn.y;
				nowdir = tn.dir+1;
			}
		}
		if (size(&stack)) {
			printf("Yes\n");
			while(size(&stack)) {
				tn = top(&stack);
				pop(&stack);
				map[tn.x][tn.y] = 2;
			}
			for(int q=1;q<=r;q++) {
				for(int w=1; w<=c; w++) {
					printf("%c ", ans[map[q][w]]);
				}
				printf("\n");
			}
		} else {
			printf("No\n");
		}
	}
}

