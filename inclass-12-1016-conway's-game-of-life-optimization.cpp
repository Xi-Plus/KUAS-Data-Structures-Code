#include <stdio.h>
#include <windows.h>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#define side 5
#define MAX_R 80
#define MAX_C 160
using namespace std;
int v[MAX_R+side*2][MAX_C+side*2];
vector<pair<int,int> > v1, v2, add, del;
set<pair<int,int> >s, st;
void gotoxy(int r, int c) {
	COORD p;
	p.X = c;
	p.Y = r;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, p);
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
	int q, w, sleep = 500;
	
	printf("sleep (ms):");
	scanf("%d", &sleep);
	
	v2.clear();
	s.clear();
	while(~scanf("%d %d", &q, &w)) {
		if(q == -1 || w == -1) {
			break;
		}
		if(q < 1 || q > MAX_R || w < 1 || w > MAX_C) {
			printf("out of range: %d %d\n", q, w);
			continue;
		}
		q = q + side - 1;
		w = w + side - 1;
		v2.push_back(make_pair(q, w));
		s.insert(make_pair(q-1, w-1));
		s.insert(make_pair(q-1, w));
		s.insert(make_pair(q-1, w+1));
		s.insert(make_pair(q, w-1));
		s.insert(make_pair(q, w));
		s.insert(make_pair(q, w+1));
		s.insert(make_pair(q+1, w-1));
		s.insert(make_pair(q+1, w));
		s.insert(make_pair(q+1, w+1));
	}
	
	system("cls");
	
	v1.clear();
	int c;
	vector<pair<int,int> >::iterator itv;
	while(1) {
		sort(v2.begin(), v2.end());
		
		add.resize(v2.size());
		itv = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), add.begin());
		add.resize(itv - add.begin());
		
		del.resize(v1.size());
		itv = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), del.begin());
		del.resize(itv - del.begin());
		
		for(auto i:add) {
			v[i.first][i.second] = 1;
			q = i.first-side;
			w = i.second-side;
			if (q < 0 || q >= MAX_R || w < 0 || w >= MAX_C) continue;
			gotoxy(q, w*2);
			printf("¡½");
		}
		for(auto i:del) {
			v[i.first][i.second] = 0;
			q = i.first-side;
			w = i.second-side;
			if (q < 0 || q >= MAX_R || w < 0 || w >= MAX_C) continue;
			gotoxy(q, w*2);
			printf("¡@");
		}
		Sleep(sleep);
		
		v1 = v2;
		v2.clear();
		st.clear();
		set<pair<int,int> >::iterator it;
		for(it=s.begin(); it!=s.end(); it++) {
			q = (*it).first;
			w = (*it).second;
			if (q <= 0 || q >= MAX_R+side*2-1 || w <= 0 || w >= MAX_C+side*2-1) continue;
			c = count(q, w);
			if((v[q][w] && (c == 2 || c == 3)) || (!v[q][w] && c == 3)) {
				v2.push_back(make_pair(q, w));
				st.insert(make_pair(q-1, w-1));
				st.insert(make_pair(q-1, w));
				st.insert(make_pair(q-1, w+1));
				st.insert(make_pair(q, w-1));
				st.insert(make_pair(q, w));
				st.insert(make_pair(q, w+1));
				st.insert(make_pair(q+1, w-1));
				st.insert(make_pair(q+1, w));
				st.insert(make_pair(q+1, w+1));
			}
		}
		s = st;
	}
}
