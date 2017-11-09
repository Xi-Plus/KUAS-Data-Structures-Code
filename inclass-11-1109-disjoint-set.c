#include <stdio.h>
int v[99999999];
int find(int n) {
	if(v[n] == n) return n;
	return v[n] = find(v[n]);
}
void merge(int a, int b){
	int ra = find(a);
	int rb = find(b);
	v[ra] = rb;
}
int main() {
	int m;
	scanf("%d", &m);
	for(int q=0; q<m; q++) {
		v[q] = q;
	}
	int a, b;
	while(scanf("%d %d", &a, &b)) {
		if(a == -1 || b == -1) {
			break;
		}
		merge(a, b);
	}
	for(int q=0; q<m; q++) {
		if(find(q) == q) {
			printf("%d", q);
			for(int w=0; w<m; w++) {
				if(find(w) == q && w != q) {
					printf(" %d", w);
				}
			}
			printf("\n");
		}
	}
}
