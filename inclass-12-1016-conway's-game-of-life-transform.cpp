#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
	cout<<"��J���"<<endl;
	int r, c;
	vector<pair<int,int> > v, vt;
	int minr = 0x7FFFFFF, maxr = 0, minc = 0x7FFFFFFF, maxc = 0;
	while(cin>>r>>c) {
		if(r == -1 || c == -1) {
			break;
		}
		v.push_back(make_pair(r, c));
		if(r > maxr) maxr = r;
		else if(r < minr) minr = r;
		if(c > maxc) maxc = c;
		else if(c < minc) minc = c;
	}
	int act;
	fstream f;
	while(true) {
		cout<<"1.���(1,1) 2.���� 3.����½�� 4.����½�� 5.����90�� :";
		cin>>act;
		vt.clear();
		switch(act) {
			case 1:
				for(auto i:v) {
					vt.push_back(make_pair(i.first-minr+1, i.second-minc+1));
				}
				minr = 1; maxr -= minr-1;
				minc = 1; maxc -= minc-1;
				break;
			case 2:
				int offsetr, offsetc;
				cout<<"����R :";
				cin>>offsetr;
				cout<<"����C :";
				cin>>offsetc;
				if(minr+offsetr < 1 || minc+offsetc < 1) {
					cout<<"out of range"<<endl;
					break;
				} 
				for(auto i:v) {
					vt.push_back(make_pair(i.first+offsetr, i.second+offsetc));
				}
				minr -= r; maxr -= r;
				minc -= c; maxc -= c;
				break;
			case 3:
				for(auto i:v) {
					vt.push_back(make_pair(i.first, maxc+minc-i.second));
				}
				break;
			case 4:
				for(auto i:v) {
					vt.push_back(make_pair(maxr+minr-i.first, i.second));
				}
				break;
			case 5:
				for(auto i:v) {
					vt.push_back(make_pair(i.second-minc+minr, maxr-i.first+minc));
				}
				int dr = maxr - minr;
				int dc = maxc - minc;
				maxr = minr + dc;
				maxc = minc + dr;
				break;
		}
		v = vt;
		cout<<"----------------"<<endl;
		f.open("out.txt", ios::out);
		for(auto i:v) {
			cout<<i.first<<" "<<i.second<<endl;
			f<<i.first<<" "<<i.second<<endl;
		}
		cout<<"-1 -1"<<endl;
		f<<"-1 -1"<<endl;
		f.close();
		cout<<"----------------"<<endl;
	}
}
