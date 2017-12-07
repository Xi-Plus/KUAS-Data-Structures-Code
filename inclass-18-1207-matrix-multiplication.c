#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_A 5
#define MAX_B 5
#define MAX_C 5
#define MAX_V 10
int M1[MAX_A][MAX_B];
int M2[MAX_B][MAX_C];
int M3[MAX_A][MAX_C];
int main() {
	srand(time(NULL));
	for(int q=0; q<MAX_A; q++) {
		for(int w=0; w<MAX_B; w++) {
			M1[q][w] = rand()%MAX_V;
		}
	}
	for(int q=0; q<MAX_B; q++) {
		for(int w=0; w<MAX_C; w++) {
			M2[q][w] = rand()%MAX_V;
		}
	}
	memset(M3, 0, sizeof(M3));
	for(int q=0; q<MAX_A; q++) {
		for(int w=0; w<MAX_C; w++) {
			for(int e=0; e<MAX_B; e++) {
				M3[q][w] += M1[q][e] * M2[e][w];
			}
		}
	}
	for(int q=0; q<MAX_B; q++) {
		for(int w=0; w<MAX_B; w++) {
			printf("    ");
		}
		printf(" |");
		for(int w=0; w<MAX_C; w++) {
			printf("%4d", M2[q][w]);
		}
		printf("\n");
	}
	for(int q=0; q<(MAX_B+MAX_C)*4+2; q++) {
		printf("_");
	}
	printf("\n");
	for(int q=0; q<MAX_A; q++) {
		for(int w=0; w<MAX_B; w++) {
			printf("%4d", M1[q][w]);
		}
		printf(" |");
		for(int w=0; w<MAX_C; w++) {
			printf("%4d", M3[q][w]);
		}
		printf("\n");
	}
}
