#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
using namespace std;
int dczzzt[26] = { 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0,0 };
int mainczzzt() {
	string s;
	for (int i = 0; i < 4; i++) {
		getline(cin, s);
		for (int j = 0; j < s.length(); j++) {
			if (s[j] <= 'Z'&&s[j] >= 'A') {
				dczzzt[s[j] - 'A']++;
			}
		}
	}
	int max = 0;
	for(int i=0;i<26;i++){
		if (dczzzt[i] > max)max = dczzzt[i];
	}
	for (int j = max; j >0; j--) {
		for (int i = 0; i < 51; i++) {
			if (i % 2 == 0&&dczzzt[i/2]>=j) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	for (int i = 0; i < 51; i++) {
		if (i % 2 == 0) {
			cout << char('A' + i / 2);
		}
		else {
			cout << " ";
		}
	}
	system("pause");
	return 0;
}