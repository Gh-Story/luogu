#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int d[5000][1100];
void cal(int n) {
	int carry = 0;
	for (int i = 0; i < 1100; i++) {
		int sum = carry + d[n - 1][i] + d[n - 2][i];
		d[n][i] = sum % 10;
		carry = sum / 10;
	}
	
}

int sltmain() {
	int n;
	d[0][0] = 1;
	d[1][0] = 2;
	scanf("%d", &n);
	if (n <= 2) {
		printf("%d", &n);
		return 0;
	}
	else {
		for (int i = 2; i < n; i++) {
			cal(i);
		}
	}
	int index = 1099;
	for (int i = 1099; i >= 0; i--) {
		if (d[n - 1][i] != 0) {
			index = i;
			break;
		}
	}
	for (; index >= 0; index--) {
		printf("%d", d[n - 1][index]);
	}
	
	system("pause");
	return 0;

}