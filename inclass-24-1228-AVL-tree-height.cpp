#include <stdio.h>
#include <time.h>
#include <algorithm>
#define MAX_V 20
#define MAX_N 20
struct Node{
	int key, h;
	Node *l, *r;
	Node(int v): l(NULL), r(NULL), h(1), key(v){};
	void update() {
		h = 1 + std::max(l?l->h:0, r?r->h:0);
	}
};
Node *insert(Node *root, int v) {
	if(!root) return new Node(v);
	if(v < root->key) {
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
		printf("%d-%d %d-%d L\n", root->key, root->h, root->l->key, root->l->h);
		dfs(root->l);
	}
	if(root->r) {	
		printf("%d-%d %d-%d R\n", root->key, root->h, root->r->key, root->r->h);
		dfs(root->r);
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
}

