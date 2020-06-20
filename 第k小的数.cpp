#include<iostream>
#include<cstdio>
#include <climits>
using namespace std;

int nums[5000000];

int nth_sort(int i, int j, int k) {
	int pivot = nums[i];
	int l = i;
	int r = j;
	while (l < r) {
		while (r > l&&nums[r] >= pivot)r--;
		if (r > l) {
			nums[l] = nums[r];
			
		}
		while (l < r&&nums[l] <= pivot)l++;
		if (r > l) {
			nums[r] = nums[l];
			
		}
	}
	nums[l] = pivot;
	if (l == k)return nums[l];
	else if (l < k)nth_sort(l + 1, j, k);
	else nth_sort(i, l - 1, k);

}
void select_nth(int k,int n) {
	
	if (k < (n-1)/2) {
		for (int i = 0; i <= k; i++) {
			int max = 1000000001;
			int index = -1;
			for (int j = i; j < n; j++) {
				if (nums[j] < max) {
					index = j;
					max = nums[j];
				}
			}
			swap(nums[i], nums[index]);
		}
	}
	else {
		for (int i = n-1; i >=k; i--) {
			int max = -1;
			int index = -1;
			for (int j = 0; j <= i; j++) {
				if (nums[j] > max) {
					index = j;
					max = nums[j];
				}
			}
			swap(nums[i], nums[index]);
		}
	}
}
int maindkxds() {
	int n,k;
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	select_nth(k, n);
	printf("%d", nums[k]);
	system("pause");
	return 0;
}