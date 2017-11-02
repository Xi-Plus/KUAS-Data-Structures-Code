#include <stdlib.h>
#include <stdio.h>
typedef struct Node {
	char v;
	struct Node *l,*r;
}Node;
void dfs(Node *root) {
	if(!root) {
		return;
	}
	printf("%c", root->v);
	dfs(root->l);
	dfs(root->r);
}
void dfs2(Node *root) {
	if(!root) {
		return;
	}
	printf("%c", root->v);
	dfs2(root->r);
	dfs2(root->l);
}
Node* search(Node *root, char c) {
	if(!root) {
		return NULL;
	}
	if(root->v == c) {
		return root;
	}
	Node* tmp;
	tmp = search(root->l, c);
	if(tmp != NULL) {
		return tmp;
	}
	tmp = search(root->r, c);
	if(tmp != NULL) {
		return tmp;
	}
	return NULL;
}
void insert(Node *root, char parent, int side, char ins) {
	Node* tmp = search(root, parent);
	if(tmp == NULL) {
		printf("insert fail 1\n");
		return;
	} else {
		if(side == 1) {
			if(tmp->l != NULL) {
				printf("insert fail 2\n");
				return;
			} else {
				tmp->l = malloc(sizeof(Node));
				tmp->l->v = ins;
				tmp->l->l = NULL;
				tmp->l->r = NULL;
			}
		} else {
			if(tmp->r != NULL) {
				printf("insert fail 3\n");
				return;
			} else {
				tmp->r = malloc(sizeof(Node));
				tmp->r->v = ins;
				tmp->r->l = NULL;
				tmp->r->r = NULL;
			}
		}
	}
}
int main() {
	Node *root = malloc(sizeof(Node));
	root->v = 'A';
	root->l = NULL;
	root->r = NULL;
	insert(root, 'A', 1, 'F');
	insert(root, 'F', 1, 'I');
	insert(root, 'F', 2, 'G');
	insert(root, 'G', 2, 'H');
	insert(root, 'A', 2, 'B');
	insert(root, 'B', 1, 'E');
	insert(root, 'B', 2, 'C');
	insert(root, 'C', 1, 'D');
	
	dfs(root);
	printf("\n");
	
	dfs2(root);
	printf("\n");
}
