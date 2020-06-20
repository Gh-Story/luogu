#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string strs[26]={
	"one", "two" ,"three" ,"four" ,"five" ,"six" ,
	"seven" ,"eight" ,"nine" ,"ten" ,"eleven" ,
	"twelve" ,"thirteen" ,"fourteen" ,"fifteen" ,
	"sixteen" ,"seventeen" ,"eighteen" ,"nineteen" ,
	"twenty","a" ,"both", "another", "first" ,"second" ,"third"
};
int mod[26] = {
	1,4,9,16,25,36,49,64,81,0,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9
};
int find(string s) {
	for (int i = 0; i < 26; i++) {
		if (strs[i] == s)return i;
	}
	return -1;
}
int mainsndmm() {
	string s;
	int pos;
	int d[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 6; i++) {
		cin >> s;
		pos = find(s);
		if (pos != -1) {
			d[i] = mod[pos];
		}
	}
	sort(d,d+6);
	bool flag= false;
	for (int i = 0; i < 6; i++) {	
		if (flag) {
			printf("%.2d", d[i]);
		}
		else {
			if (d[i]==0);
			else {
				printf("%d", d[i]);
				flag = true;
			}
		}
		
	}
	if (flag == false)printf("0");
	printf("\n");
	
	return 0;
}