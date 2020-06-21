/*
Á´½Ó£ºhttps://www.luogu.com.cn/problem/P1498
@GH
@2020-06-21
/ + _*2 + \   ==  /__\
 /\	   0110
/__\   1111
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
char ** cal(char **pat,int row,int col) {
	
	char ** ans = new char*[row];
	for (int i = 0; i < row; i++) {
		ans[i] = new char[col];
		for (int j = 0; j < col; j++) {
			ans[i][j] = ' ';
		}
	}
	row = row / 2;
	col = col / 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col ; j++) {
			ans[i][j + col / 2] = pat[i][j];
			ans[i + row][j] = pat[i][j];
			ans[i + row][j + col] = pat[i][j];
		}
	}
	return ans;
}

int main() {
	char ** pat=new char* [2];
	pat[0]=new char[4]{' ','/','\\',' '};
	pat[1] = new char[4]{'/','_','_','\\'};
	int num;
	scanf("%d", &num);
	if (num == 1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%c", pat[i][j]);
			}
			printf("\n");
		}
		return 0;
	}
	int row = 2;
	int col = 4;
	for (int i = 1; i < num; i++) {
		row *= 2;
		col *= 2;
		pat = cal(pat, row, col);
	}
	for (int i = 0; i <row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%c", pat[i][j]);
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}