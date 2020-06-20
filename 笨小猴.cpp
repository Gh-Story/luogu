#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int mainbxh() {
	int n;
	scanf("%d", &n);
	string s;
	char c;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s[0] == 'a') {
			c = 'a';
			cin >> a >> b;
			string o = to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
			cout << o << endl << o.size() << endl;
		}
		else if (s[0] == 'b') {
			c = 'b';
			cin >> a >> b;
			string o = to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
			cout << o << endl << o.size() << endl;
		}
		else if (s[0] == 'c') {
			c = 'c';
			cin >> a >> b;
			string o = to_string(a) + "*" + to_string(b) + "=" + to_string(a * b);
			cout << o << endl << o.size() << endl;
		}
		else {
			a = atoi(s.c_str());
			cin >> b;
			if (c == 'a') {
				string o = to_string(a) + "+" + to_string(b) + "=" + to_string(a + b);
				cout << o << endl << o.size() << endl;
			}
			else if (c == 'b'){
				string o = to_string(a) + "-" + to_string(b) + "=" + to_string(a - b);
				cout << o << endl << o.size() << endl;
			}
			else {
				string o = to_string(a) + "*" + to_string(b) + "=" + to_string(a * b);
				cout << o << endl << o.size() << endl;
			}
		}
	}
	
	return 0;
}