#include <cstdlib>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;
int main(int argc, char* argv[]) {
	string s = argv[1];
	s += " < hw-2-1003-maze.in";
	while(true) {
		system("hw-2-1003-maze-testdata > hw-2-1003-maze.in");
		system("type hw-2-1003-maze.in");
		cout<<endl;
		system(s.c_str());
		system("pause");
		system("cls");
	}
}

