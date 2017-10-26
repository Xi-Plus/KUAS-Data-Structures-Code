#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
	int v;
	struct Node* next;
}Node;
void add(Node **q, int n) {
	Node *t = (*q)->next;
	(*q)->next = (Node*)malloc(sizeof(Node));
	(*q) = (*q)->next;
	(*q)->v = n;
	(*q)->next = t;
}
int del(Node *q) {
	if(q->next == q->next->next) {
		printf("empty\n");
		return -1;
	}
	int r = q->next->next->v;
	q->next = q->next->next;
	return r;
}
int main(){
	Node *q = (Node*)malloc(sizeof(Node));
	q->next = q;
	char cmd[10];
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "add") == 0) {
			scanf(" %d", &n);
			add(&q, n);
		} else if (strcmp(cmd, "del") == 0) {
			printf("return %d\n", del(q));
		} else {
			printf("no command\n");
		}
		printf("in queue: ");
		for (Node* t=q->next->next; t != q->next; t=t->next) {
			printf("%d ", t->v);
		}
		printf("\n");
	}
}
