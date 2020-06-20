/*
��Ŀ���ӣ�https://www.luogu.com.cn/problem/P1928�Ż�״�������棬���Ż�
@GH
@2020-06-21
*/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
string ans;
// ������3AD ���ַ��� ת��ΪADADAD     ������3[3AD]���ַ���ת��Ϊ[3AD][3AD][3AD]
string trn(string str) {
	string tmp;
	int start=1;
	if (str.length() <= 1)return str;
	int circle = str[0] - '0';
	if (str[1] <= '9'&& str[1] >= '0') {
		circle = circle * 10 + (str[1] - '0');
		start = 2;
	}
	for (int i = 0; i < circle; i++) {
		tmp += str.substr(start);
	}
	return tmp;
}
//���з���
void cal( string str) {
	int i = 0, j = 0, l = -1, r = -1, flag = 0;
	for (; i < str.length(); i++) {
		if (str[i] == '[') {
			l++;
			if (flag == 0) {
				j = i;
				flag = 1;
			}
		}
		else if (str[i] == ']') {
			r++;
		}
		else if (l >= 0 || r >= 0) {
			continue;
		}
		else {
			ans += str[i];
		}
		if (l > -1 && l == r) {
			cal(trn(str.substr(j + 1, i-j-1)));
			
			l = -1;
			r = -1;
			flag = 0;
		}
	}
}

int main() {
	string str;
	ans="";
	cin >> str;
	cal(str);
	cout << ans << endl;
	system("pause");
	return 0;
}