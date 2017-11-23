#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 20
typedef struct Node {
	int v;
	Node *l, *r, *p1, *p2;
}Node;
Node* find(Node *root, int n) {
	if (n < root->v) {
		if(root->l == NULL) {
			return root;
		} else {
			return find(root->l, n);
		}
	} else {
		if(root->r == NULL) {
			return root;
		} else {
			return find(root->r, n);
		}
	}
}
Node* finddel(Node *root, int n) {
	if(!root) return NULL;
	if(root->v == n) {
		return root;
	} else if (n < root->v) {
		return finddel(root->l, n);
	} else {
		return finddel(root->r, n);
	}
}
int search(Node *root, int n) {
	if(!root) return 0;
	if(root->v == n) {
		return 1;
	} else if (n < root->v) {
		return search(root->l, n);
	} else {
		return search(root->r, n);
	}
}
void insert(Node *root, int n) {
	Node *temp = find(root, n);
	if(n < temp->v) {
		temp->l = (Node*)malloc(sizeof(Node));
		temp->l->v = n;
		temp->l->p1 = temp;
		temp->l->p2 = NULL;
		temp->l->l = NULL;
		temp->l->r = NULL;
	} else {
		temp->r = (Node*)malloc(sizeof(Node));
		temp->r->v = n;
		temp->r->p1 = NULL;
		temp->r->p2 = temp;
		temp->r->l = NULL;
		temp->r->r = NULL;
	}
}
void remove2(Node *temp) {
	if(temp->l == NULL && temp->r == NULL) {
		if(temp->p1 != NULL) temp->p1->l = NULL;
		else if(temp->p2 != NULL) temp->p2->r = NULL;
		free(temp);
	} else if(temp->r == NULL) {
		if(temp->p1 != NULL) {
			temp->p1->l = temp->l;
			temp->l->p1 = temp->p1;
		} else if(temp->p2 != NULL) {
			temp->p2->r = temp->l;
			temp->l->p2 = temp->p2;
		}
		free(temp);
	} else if(temp->l == NULL) {
		if(temp->p1 != NULL) {
			temp->p1->l = temp->r;
			temp->r->p1 = temp->p1;
		} else if(temp->p2 != NULL) {
			temp->p2->r = temp->r;
			temp->r->p2 = temp->p2;
		}
		free(temp);
	} else {
		Node *temp2 = temp->l;
		while(temp2->r != NULL) {
			temp2 = temp2->r;
		}
		temp->v = temp2->v;
		remove2(temp2);
	}
}
void remove(Node *root, int n) {
	if(search(root, n)) {
		Node* temp = finddel(root, n);
		remove2(temp);
	} else {
		printf("not found\n");
	}
}
void print(Node *root, int d) {
	if(!root) {
		return;
	}
	print(root->l, d+1);
	printf("%d ", root->v);
	print(root->r, d+1);
}

int main() {
	srand(time(NULL));
	Node *root = (Node*)malloc(sizeof(Node));
	root->l = NULL;
	root->r = NULL;
	root->p1 = NULL;
	root->p2 = NULL;
	root->v = rand()%100;
	for(int q=0; q<MAX_SIZE-1; q++) {
		insert(root, rand()%100);
	}
	print(root, 0);
	printf("\n");
	char cmd[10];
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "find") == 0) {
			scanf(" %d", &n);
			printf("%d\n", search(root, n));
		} else if (strcmp(cmd, "del") == 0) {
			scanf(" %d", &n);
			remove(root, n);
			print(root, 0);
			printf("\n");
		} else {
			printf("no command\n");
		}
	}
}

