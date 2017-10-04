#include <cstdlib>
#include <iostream>
#include <ctime>
#define MAX_R 20
#define MAX_C 20 
using namespace std;
int RAND(int a, int b) {
	return rand()%(b-a+1)+a;
}
int main(int argc, char* argv[]) {
	srand(time(NULL));
	int r, c, sx, sy, ex, ey;
	r = RAND(2, MAX_R);
	c = RAND(2, MAX_C);
	sx = RAND(1, r);
	sy = RAND(1, c);
	ex = RAND(1, r);
	ey = RAND(1, c);
	cout<<r<<" "<<c<<" "<<sx<<" "<<sy<<" "<<ex<<" "<<ey<<endl;
	int v[r][c];
	for(int q=0; q<r; q++) {
		for(int w=0; w<c; w++) {
			v[q][w] = rand()%2;
		}
	}
	v[sx][sy] = 0;
	v[ex][ey] = 0;
	for(int q=0; q<r; q++) {
		cout<<v[q][0];
		for(int w=1; w<c; w++) {
			cout<<" "<<v[q][w];
		}
		cout<<endl;
	}
}

