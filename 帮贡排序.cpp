#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct person {
	string name;
	string pos;
	int bg;
	int level;
	int order;
	
};
person p[110];
bool cmp(person x,person y){
	if (x.pos == "BangZhu")return true;
	if (y.pos == "BangZhu")return false;
	if (x.pos == "FuBangZhu"&&y.pos == "FuBangZhu") {
		if (x.level = y.level)return x.order < y.order;
		else return x.level > y.level;
	}
	if (x.pos == "FuBangZhu")return true;
	if (y.pos == "FuBangZhu")return false;
	if (x.bg == y.bg) {
		return x.order < y.order;
	}
	else {
		return x.bg > y.bg;
	}
	return false;
}
bool cmp2(person x, person y) {
	if (x.level == y.level) return x.order < y.order;
	else return x.level > y.level;
}
int mainbgpx() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> p[i].name;
		cin >> p[i].pos;
		cin >> p[i].bg;
		cin >> p[i].level;
		p[i].order = i;
	}
	sort(p, p + n, cmp);
	
	if (n >= 3 && n <=5) {
		sort(p + 3, p + n, cmp2);
	}
	else if (n <= 9) {
		sort(p + 3, p + 5, cmp2);
		sort(p + 5, p + n, cmp2);
		cout << endl << endl;
	}
	else if (n <= 16) {
		sort(p + 3, p + 5, cmp2);
		sort(p + 5, p + 9, cmp2);
		sort(p + 9, p + n, cmp2);
	}
	else if (n <= 41) {
		sort(p + 3, p + 5, cmp2);
		sort(p + 5, p + 9, cmp2);
		sort(p + 9, p + 16, cmp2);
		sort(p + 16, p + n, cmp2);
	}
	else {
		sort(p + 3, p + 5, cmp2);
		sort(p + 5, p + 9, cmp2);
		sort(p + 9, p + 16, cmp2);
		sort(p + 16, p + 41, cmp2);
		sort(p + 41, p + n, cmp2);
	}
	for (int i = 0; i < n; i++) {
		if (i > 2 && i < 5)
			cout << p[i].name<<" " << "HuFa" << " "<< p[i].level  << endl;
		else if (i >=5  && i < 9)
			cout << p[i].name << " " << "ZhangLao" << " " << p[i].level << endl;
		else if (i >= 9 && i < 16)
			cout << p[i].name << " " << "TangZhu" << " " << p[i].level << endl;
		else if (i >=16  && i < 41)
			cout << p[i].name << " " << "JingYing" << " " << p[i].level << endl;
		else if (i >=41 )
			cout << p[i].name << " " << "BangZhong" << " " << p[i].level << endl;
		else 
			cout << p[i].name << " " << p[i].pos << " " << p[i].level << endl;
		
	}
	
	system("pause");

	return 0;

}