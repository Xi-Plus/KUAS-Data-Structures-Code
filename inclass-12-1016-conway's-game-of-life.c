#include <stdio.h>
#include <windows.h>
#define side 5
#define MAX_R 40
#define MAX_C 60
int v[MAX_R+side*2][MAX_C+side*2];
int v2[MAX_R+side*2][MAX_C+side*2];
void gotoxy(int xpos, int ypos) {
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}
int count(int q, int w) {
	return v[q-1][w-1] +
	       v[q-1][w] +
	       v[q-1][w+1] +
	       v[q][w-1] +
	       v[q][w+1] +
	       v[q+1][w-1] +
	       v[q+1][w] +
	       v[q+1][w+1];
}
int main() {
	char cmd[50];
	sprintf(cmd, "mode %d,%d", MAX_C*2, MAX_R+1);
	system(cmd);
	memset(v, 0, sizeof(v));
	int a, b;
	while(~scanf("%d %d", &a, &b)) {
		if(a == -1 || b == -1) {
			break;
		}
		if(a < 0 || a >= MAX_R || b < 0 || b > MAX_C) {
			printf("bad: %d %d\n", a, b);
			continue;
		}
		v[a+side-1][b+side-1] = 1;
	}
	system("cls");
	for(int q=side; q<MAX_R+side; q++) {
		for(int w=side; w<MAX_C+side; w++) {
			if(v[q][w]) {
				printf("¡½");
			} else {
				printf("¡@");
			}
		}
		printf("\n");
	}
	system("pause");
	int c;
	while(1) {
		memset(v2, 0, sizeof(v2));
		system("cls");
//		gotoxy(0, 0);
		for(int q=1; q<MAX_R+side*2-1; q++) {
			for(int w=1; w<MAX_C+side*2-1; w++) {
				c = count(q, w);
				if(v[q][w]) {
					if(c == 2 || c == 3) {
						v2[q][w] = 1;
					}
				} else {
					if(c == 3) {
						v2[q][w] = 1;
					}
				}
			}
		}
		memcpy(v, v2, sizeof(v));
		for(int q=side; q<MAX_R+side; q++) {
			for(int w=side; w<MAX_C+side; w++) {
				if(v2[q][w]) {
					printf("¡½");
				} else {
					printf("¡@");
				}
			}
			printf("\n");
		}
//		Sleep(50);
	}
}
