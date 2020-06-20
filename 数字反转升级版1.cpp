#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

string re(string s) {
	reverse(s.begin(), s.end());
	int i;
	for (i = 0; i < s.length(); i++) {
		if (s[i] != '0') { break; }
	}
	if (i == s.length())return "0";
	else return s.substr(i, s.length() - i);
}
string rec(string s) {
	reverse(s.begin(), s.end());
	int i;
	for (i = s.length()-1; i >=0; i--) {
		if (s[i] != '0') { break; }
	}
	if (i ==-1)return "0";
	else return s.substr(0, i+1);
}

int mainfzssj() {
	string s;
	cin >> s;
	int flag;
	if ((flag=s.find('.'))!=-1) {
		s.reserve();
		cout << re(s.substr(0,flag)) <<"."<<rec(s.substr(flag+1,s.length()))<< endl;
	}
	else if ((flag=s.find('%'))!=-1) {
		s.reserve();
		cout << re(s.substr(0,s.length()-1)) <<"%"<< endl;
	}
	else if ((flag=s.find('/'))!=-1) {
		s.reserve();
		cout << re(s.substr(0,flag))<<"/"<< re(s.substr(flag+1,s.length()))<<endl;
	}
	else {
		cout << re(s)<<endl;
	}
	system("pause");
	return 0;
}