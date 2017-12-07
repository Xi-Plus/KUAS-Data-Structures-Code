#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_V 5
#define MAX_K 10
typedef struct Matrix {
    long long m[MAX_V][MAX_V];
}Matrix;
Matrix base, ans, ans2;
Matrix mul(Matrix a, Matrix b) {
    Matrix temp;
    for(int q=0; q<MAX_V; q++) {
        for(int w=0; w<MAX_V; w++) {
            temp.m[q][w] = 0;
            for(int e=0; e<MAX_V; e++) {
            	temp.m[q][w] += a.m[q][e]*b.m[e][w];
			}
			temp.m[q][w] = !!temp.m[q][w];
        }
    }
    return temp;
}
Matrix add(Matrix a, Matrix b) {
    Matrix temp;
    for(int q=0; q<MAX_V; q++) {
        for(int w=0; w<MAX_V; w++) {
            temp.m[q][w] = a.m[q][w] + b.m[q][w];
            temp.m[q][w] = !!temp.m[q][w];
        }
    }
    return temp;
}
void print(Matrix a) {
	for(int q=0; q<MAX_V; q++) {
		for(int w=0; w<MAX_V; w++) {
			printf("%d ", a.m[q][w]);
		}
		printf("\n");
	}
}
int main() {
	srand(time(NULL));
	for(int q=0; q<MAX_V; q++) {
		for(int w=0; w<MAX_V; w++) {
			base.m[q][w] = rand()%2;
		}
	}
	printf("A^1\n");
	print(base);
	printf("\n");
	ans = base;
	ans2 = base;
	for(int q=2; q<=MAX_K; q++) {
		ans = mul(ans, base);
		ans2 = add(ans, ans2);
		printf("A^%d\n", q);
		print(ans);
		printf("A+A^2+...+A^k\n");
		print(ans2);
		printf("\n");
	}
}
