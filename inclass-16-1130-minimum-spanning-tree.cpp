#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <queue>
using namespace std;
// graph
#define MAX_V 5
#define MAX_E 10
int G[MAX_V][MAX_V];
// disjoint set
int v[MAX_V];
int find(int n) {
	if(v[n] == n) return n;
	return v[n] = find(v[n]);
}
void merge(int a, int b){
	int ra = find(a);
	int rb = find(b);
	v[ra] = rb;
}
int same(int a, int b) {
	return find(a) == find(b);
}
typedef struct {
	int a, b, v;
}Edge;
bool cmp(Edge a, Edge b) {
	return a.v < b.v; 
}
// main
int main() {
	memset(G, 0, sizeof(G));
	for(int q=0; q<MAX_V; q++) {
		v[q] = q;
	}
	int a, b, c;
	printf("original edge\n");
	priority_queue<Edge, vector<Edge>, decltype(&cmp)> edge(&cmp);
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] != 0) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
		}
		c = rand()%20+1;
		G[a][b] = c;
		G[b][a] = c;
		edge.push({a, b, c});
		printf("%d %d %d\n", a, b, c);
	}
	printf("-----\n");
	
	while(!edge.empty()) {
		Edge temp = edge.top();
		edge.pop();
		if(!same(temp.a, temp.b)) {
			G[temp.a][temp.b] *= -1;
			G[temp.b][temp.a] *= -1;
			merge(temp.a, temp.b);
		}
	}
	
	printf("connected edge\n");
	for(int q=0; q<MAX_V; q++) {
		for(int w=q+1; w<MAX_V; w++) {
			if(G[q][w] > 0) {
				printf("%d %d %d\n", q, w, G[q][w]);
			} else if(G[q][w] < 0) {
				printf("%d %d [%d]\n", q, w, -G[q][w]);
			}
		}
	}
}
