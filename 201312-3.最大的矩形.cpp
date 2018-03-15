#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int v[maxn];
int height[maxn][maxn];
int n;
int main(){
	int res=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%d",&v[i]);
	for(int i=0;i<n;++i){
		height[i][i]=v[i];
		for(int j=i+1;j<n;++j){
			height[i][j]=min(height[i][j-1],v[j]);
			res=max(res,height[i][j]*(j-i+1));
		}
	}
	cout<<res;
	return 0;
}
