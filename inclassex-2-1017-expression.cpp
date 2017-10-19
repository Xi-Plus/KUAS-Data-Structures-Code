// By xiplus
// http://zerojudge.tw/ShowProblem?problemid=a017
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
vector<char> op;
vector<int> ans;
map<char, int> oporder;
int a, b;
bool ophigher(char op1, char op2) {
	return oporder[op1] < oporder[op2];
}
void action(char c) {
	b = ans.back(); ans.pop_back();
	a = ans.back(); ans.pop_back();
	switch(c) {
		case '+': a+=b; break;
		case '-': a-=b; break;
		case '*': a*=b; break;
		case '/': a/=b; break;
		case '%': a%=b; break;
	}
	ans.push_back(a);
}
int main(){
	char q,w;
	oporder['('] = 2;
	oporder[')'] = 2;
	oporder['*'] = 5;
	oporder['/'] = 5;
	oporder['%'] = 5;
	oporder['+'] = 6;
	oporder['-'] = 6;
	oporder['#'] = 100;
	string s;
	int a, b;
	char c;
	while(getline(cin, s)){
		stringstream ss(s);
		op.clear();
		op.push_back('#');
		ans.clear();
		ans.push_back(0);
		while(ss>>s){
			c=s[0];
			switch(c){
				case '(':
					op.push_back('(');
					break;
				case ')':
					while(op.back()!='(') {
						action(op.back());
						op.pop_back();
					}
					op.pop_back();
					break;
				default:
					if(oporder[c]!=0) {
						if(ophigher(c, op.back())) {
							op.push_back(c);
						} else {
							while(!ophigher(c, op.back()) && op.back() != '(') {
								action(op.back());
								op.pop_back();
							}
							op.push_back(c);
						}
					} else {
						a=atoi(s.c_str());
						ans.push_back(a);
					}
					break;
			}
		}
		while(op.back() != '#') {
			action(op.back());
			op.pop_back();
		}
		cout<<ans.back()<<endl;
	}
}

