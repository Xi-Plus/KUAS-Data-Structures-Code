#include <stdio.h>
#include <time.h>
#include <algorithm>
#define MAX_V 100
#define MAX_N 20
char d[] = {'L', 'R'};
struct Node{
	int key, nullh, nulld;
	Node *l, *r;
	Node(int v): l(NULL), r(NULL), nullh(1), nulld(0), key(v){};
	void update() {
		if(!l) {
			nullh = 1;
			nulld = 0;
		} else if(!r) {
			nullh = 1;
			nulld = 1;
		} else if(l->nullh <= r->nullh) {
			nullh = l->nullh + 1;
			nulld = 0;
		} else {
			nullh = r->nullh + 1;
			nulld = 1;
		}
	}
};
Node *insert(Node *root, int v) {
	if(!root) return new Node(v);
	if(v <= root->key) {
		root->l = insert(root->l, v);
	} else {
		root->r = insert(root->r, v);
	}
	root->update();
	return root;
}
void dfs(Node *root) {
	if(!root) return;
	if(root->l) {	
		printf("%d-%d-%c %d-%d-%c L\n", root->key, root->nullh, d[root->nulld], root->l->key, root->l->nullh, d[root->l->nulld]);
		dfs(root->l);
	}
	if(root->r) {	
		printf("%d-%d-%c %d-%d-%c R\n", root->key, root->nullh, d[root->nulld], root->r->key, root->r->nullh, d[root->r->nulld]);
		dfs(root->r);
	}
}
void dfs2(Node *root) {
	if(!root) return;
	printf("%d ", root->key);
	if(root->nulld == 0) {
		dfs2(root->l);
	} else {
		dfs2(root->r);
	}
}
int main() {
	srand(time(NULL));
	Node *root;
	root = insert(root, rand()%MAX_V+1);
	for(int q=1; q<MAX_N; q++) {
		insert(root, rand()%MAX_V+1);
	}
	dfs(root);
	dfs2(root);
	printf("\n");
}

