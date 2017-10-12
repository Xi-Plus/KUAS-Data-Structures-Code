#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10
int queue[MAX_SIZE]={0};
int s=0, e=0;
int size() {
	return e-s;
}
void refresh() {
	if (s == 0) return;
	printf("run refresh\n");
	int sz = size();
	for(int q=0; q<sz; q++) {
		queue[q] = queue[s+q];
	}
	s = 0;
	e = sz;
}
int push(int n) {
	if (e == MAX_SIZE) {
		refresh();
	}
	if (e == MAX_SIZE) {
		printf("push fail\n");
		return 0;
	}
	queue[e++]=n;
	return 1;
}
int front() {
	if (size()) {
		return queue[s];
	} else {
		return -1;
	}
}
int pop() {
	if (size()) {
		s++;
		return 1;
	}
	return 0;
}
int back() {
	if (size()) {
		return queue[e-1];
	} else {
		return -1;
	}
}
int main() {
	char cmd[10];
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "push") == 0) {
			scanf(" %d", &n);
			push(n);
		} else if (strcmp(cmd, "front") == 0) {
			printf("%d\n", front());
		} else if (strcmp(cmd, "pop") == 0) {
			pop();
		} else if (strcmp(cmd, "back") == 0) {
			printf("%d\n", back());
		} else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", size());
		} else {
			printf("no command\n");
		}
		int sz = size();
		for (int q=s; q < s+sz; q++) {
			printf("%d ", queue[q]);
		}
		printf("\n");
	}
}

