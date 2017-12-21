#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <queue>
using namespace std;
// graph
#define MAX_V 10
#define MAX_E 15
#define MAX_W 10
int G[MAX_V][MAX_V];
bool visited[MAX_V][MAX_V];
int V[MAX_V];
int from[MAX_V];
// edge
typedef struct Edge {
	int a, b, v;
}Edge;
class cmp {
	public:
	bool operator() (Edge a, Edge b) const {
		return a.v > b.v;
	}
};
int main() {
	srand(time(NULL));
	printf("original edge\n");
	memset(G, 0, sizeof(G));
	int a, b, c;
	for(int q=0; q<MAX_E; q++) {
		a = b = 0;
		while(a == b || G[a][b] != 0) {
			a = rand()%MAX_V;
			b = rand()%MAX_V;
			c = rand()%MAX_W+1;
		}
		G[a][b] = c;
		printf("%d %d %d\n", a, b, c);
	}
	printf("-----\n");
	
	memset(visited, false, sizeof(visited));
	fill_n(V, MAX_V, INT_MAX);
	fill_n(from, MAX_V, -1);
	priority_queue<Edge, vector<Edge>, cmp> edge;
	
	a = rand()%MAX_V;
	printf("start: %d\n", a);
	V[a] = 0;
	for(int q=0; q<MAX_V; q++) {
		if(from[q] == -1 && G[a][q]) {
			edge.push({a, q, G[a][q]});
			visited[a][q] = true;
		}
	}
	
	while(!edge.empty()) {
		Edge temp = edge.top();
		edge.pop();
		if(V[temp.b] > V[temp.a] + G[temp.a][temp.b]) {
			from[temp.b] = temp.a;
			V[temp.b] = V[temp.a] + G[temp.a][temp.b];
		}
		for(int q=0; q<MAX_V; q++) {
			if(G[temp.b][q] && !visited[temp.b][q]) {
				edge.push({temp.b, q, G[temp.b][q]});
				visited[temp.b][q] = true;
			}
		}
	}
	
	for(int q=0; q<MAX_V; q++) {
		for(int w=0; w<MAX_V; w++) {
			if(G[q][w]) {
				if(from[w] == q) {
					printf("%d %d %d*\n", q, w, G[q][w]);
				} else {
					printf("%d %d %d\n", q, w, G[q][w]);
				}
			}
		}
	}
}
