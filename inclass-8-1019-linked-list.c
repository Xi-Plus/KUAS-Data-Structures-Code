#include <stdio.h>
#include <string.h>
#define MAX_L 10
char v[MAX_L];
int link[MAX_L];
void del(int idx) {
	if (link[idx] == -1) {
		printf("nothing to delete\n");
		return;
	}
	int newlink = link[link[idx]];
	v[link[idx]] = ' ';
	link[link[idx]] = -1;
	link[idx] = newlink;
}
void ins(char c, int next) {
	for(int q=1; q<MAX_L; q++) {
		if(v[q] == ' ') {
			if(link[next] == -1) {
				link[q] = -1;
			} else {
				link[q] = link[next];
			}
			v[q] = c;
			link[next] = q;
			return;
		}
	}
	printf("no space to insert\n");
}
int sea(char c, int idx) {
	if (v[idx] == c) {
		return idx;
	} else if (link[idx] == -1 ){
		return -1;
	} else {
		return sea(c, link[idx]);
	}
}
void visit(int idx) {
	if (link[idx] == -1){
		return;
	} else {
		printf("%c", v[link[idx]]);
		visit(link[idx]);
	}
}
int main() {
	memset(v, ' ', sizeof(v));
	memset(link, -1, sizeof(link));
	char cmd[10];
	char c;
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "del") == 0) {
			scanf(" %d", &n);
			del(n);
		} else if (strcmp(cmd, "ins") == 0) {
			scanf(" %c %d", &c, &n);
			ins(c, n);
		} else if (strcmp(cmd, "sea") == 0) {
			scanf(" %c", &c);
			n = sea(c, 0);
			if (n == -1) {
				printf("not found\n");
			} else {
				printf("found at %d\n", n);
			}
		}
		for (int q=0; q < MAX_L; q++) {
			printf("%d\t", q);
		}
		printf("\n");
		for (int q=0; q < MAX_L; q++) {
			printf("%c\t", v[q]);
		}
		printf("\n");
		for (int q=0; q < MAX_L; q++) {
			printf("%d\t", link[q]);
		}
		printf("\n");
		visit(0);
		printf("\n");
	}
}

