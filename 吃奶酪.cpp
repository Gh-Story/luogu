/*
#include<iostream>
#include<cstdio>
#include<climits>
#include<cmath>
using namespace std;
bool visit[16];
double ans = 0x3f3f3f3f;
double x[16];
double y[16];
double dis[16][16];

double Distance(int i, int j) {
	
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
}
void trap(double sum,int index,int n,int s) {
	if (n == index) {
		if (sum < ans)ans = sum;
		return;
	}
	if (sum >= ans)return;
	for (int i = 1; i <= n; i++) {
		if (visit[i]) {
			index = index + 1;
			visit[i] = false;
			sum += dis[s][i];
			trap(sum, index, n,i);
			visit[i] = true;
			index = index - 1;
			sum -= dis[s][i];
		}
		else {
			continue;
		}
	}
	return;
}
int main() {
	
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", x+i, y+i);
		visit[i] = true;
	}
	x[0] = 0;
	y[0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			dis[i][j] = Distance(i, j);
			dis[j][i] = dis[i][j];
		}
	}
	dis[0][0];
	double sum = 0.0;
	trap(sum, 0, n, 0);
	printf("%0.2f", ans);
	system("pause");
	return 0;
}
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;

double  xz[20];
double  y[20];
double f[20][35000];
template<class T> T min(T a, T b) { return a < b ? a : b; }
double dis(int a, int b) { return sqrt((xz[a] - xz[b])*(xz[a] - xz[b]) + (y[a] - y[b])*(y[a] - y[b])); }

int maincnn() {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf%lf", &xz[i], &y[i]);
	}
	memset(f, 127, sizeof(f)); 
	for (int s = 1; s <= (1 << n) - 1; s++) {
		for (int i = 0; i < n; i++) {
			if ((s&(1 << i)) == 0)continue;
			if (s == (1 << i)) {
				f[i][s] = 0; 
				continue;
			}
			for (int j = 0; j < n; j++) {
				if ((s&(1 << j)) == 0||i==j)continue;
				f[i][s] = min(f[i][s], f[j][s-(1<<i)] + dis(i, j));
			}
		}
	}
	double ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++) {
		double s = f[i][(1 << n) - 1] + dis(i, 19);
		if (s < ans)ans = s;
	}
	printf("%0.2f", ans);
	system("pause");
	return 0;
}
/*
#include<cstdio>
#include<cmath>
#include<cstring>
typedef double db;
db x[20],y[20],f[20][35000];
template<class T> T min(T a,T b) {return a<b?a:b;}
db dis(int a,int b) {return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	memset(f,127,sizeof(f));
	for(int s=1;s<=(1<<n)-1;s++)
	for(int i=1;i<=n;i++)
	{
		if((s&(1<<(i-1)))==0) continue;
		if(s==(1<<(i-1))) {f[i][s]=0;continue;}
		for(int j=1;j<=n;j++)
		{
			if((s&(1<<(j-1)))==0||i==j) continue;
			f[i][s]=min(f[i][s],f[j][s-(1<<(i-1))]+dis(i,j));
		}
	}
	db ans=-1;
	for(int i=1;i<=n;i++)
	{
		db s=f[i][(1<<n)-1]+dis(i,0);
		if(ans==-1||ans>s) ans=s;
	}
	printf("%.2lf\n",ans);
	return 0;
}
*/