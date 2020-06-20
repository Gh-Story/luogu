#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
using namespace std;
bool com(string s, string p){
	if (s.length() != p.length())return false;
	for (int i = 0; i < s.length(); i++) {
		if ((s[i]-p[i]!=0)&&abs(s[i]-p[i])!=32)return false;
	}
	return true;
}
int maintjdcs() {
	string s, p;
	getline(cin, p);
	getline(cin, s);
	int num=0;
	int i = 0,j=0;
	int plen = p.length();
	int slen = s.length();
	bool flag=true;
	int index = 0;
	while (i < slen) {
		if (s[i] != ' ') {
			for (j =  1; j < slen-i; j++) {
				if (s[j+i] == ' ')break;
			}
			if (com(s.substr(i, j), p)) {
				num++;
				if (flag) {
					index = i;
					flag = false;
				}
			}
			i += j;
		}
		else {
			i++;
		}
	}
	if (num != 0) {
		cout << num << " " << index << endl;
	}
	else {
		cout << -1 << endl;
	}
	
	return 0;

}
	
