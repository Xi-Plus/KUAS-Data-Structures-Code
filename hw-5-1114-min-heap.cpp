#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int main() {
	priority_queue<int, vector<int>, greater<int> > pq;
	char cmd[10];
	int n;
	while(~scanf("%s", cmd)) {
		if (strcmp(cmd, "push") == 0) {
			scanf(" %d", &n);
			pq.push(n);
		} else if (strcmp(cmd, "pop") == 0) {
			if(pq.empty()) printf("nothing to pop\n");
			else pq.pop();
		} else if (strcmp(cmd, "top") == 0) {
			if(pq.empty()) printf("%d\n", -1);
			else printf("%d\n", pq.top());
		} else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", pq.size());
		} else {
			printf("no command\n");
		}
	}
}
