#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 2e5 + 10;
int db[maxn];
int od[maxn];
priority_queue<int> d;
priority_queue<int,vector<int>,greater<int> > x;
inline int Input() {
	char C = getchar();
	int N = 0, F = 1;
	while (('0' > C || C > '9') && (C != '-')) C = getchar();
	if (C == '-') F = -1, C = getchar();
	while ('0' <= C && C <= '9') N = (N << 1) + (N << 3) + (C - 48), C = getchar();
	return F * N;
}

int mainhxz() {
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) scanf("%d", &db[i]);
	for (int i = 0; i < n; i++)scanf("%d", &od[i]);
	for (int i = 0, j = 0; i < n; i++) {
		for (; j < od[i]; j++) {
			if (d.empty() || db[j] >= d.top()) {
				x.push((db[j]));
			}
			else {
				x.push(d.top());
				d.push(db[j]);
				d.pop();
			}	
		}
		printf("%d\n", x.top());
		d.push(x.top());
		x.pop();
	}
	system("pause");
	return 0;
}
/*
int main() {
	int m, n,pos;
	m = Input();
	n= Input();
	for (int i = 0; i < m; i++) db[i]= Input();
	int num = 0;
	for (int i = 0; i < n; i++) {
		pos = Input();
		nth_element(db, db + num, db + pos);
		printf("%d\n", db[num]);
		num++;
	}
	system("pause");
	return 0;
}*/