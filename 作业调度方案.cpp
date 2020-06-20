
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int w[21] = { 0 };//第i个工件，工作到第几个工序
int num[501] = { 0 };
int last[21] = { 0 };
int timen[21][21] = { 0 };//需要的时间，第i个工件，第j个工序
int need[21][21] = { 0 };//需要的机器
int mac[21][501] = { 0 };
int mainzyddfa() {
	int m, n, ans=0, s = 0;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m * n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &need[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) { 
			scanf("%d", &timen[i][j]); 
		}
	}
		

	for (int i = 1; i <= m * n; i++) {
		w[num[i]]++;
		for (int j = last[num[i]] + 1;; j++) {
			if (mac[need[num[i]][w[num[i]]]][j] == 0)s++;
			else s = 0;
			if (s == timen[num[i]][w[num[i]]]) {
				for (int k = j - s + 1; k <= j; k++) {
					mac[need[num[i]][w[num[i]]]][k] = 1;
				}
				last[num[i]] = j;
				s = 0;
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, last[i]);
	}
	printf("%d", ans);
	system("pause");
	return 0;
}
