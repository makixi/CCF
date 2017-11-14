#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=510;
int vis[1010];
int val[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&val[i]);
		if(val[i]>0)vis[val[i]]++;
	}
	int res=0;
	for(int i=0;i<n;++i)
		if(val[i]<0)res+=vis[-val[i]];
	cout<<res;
	return 0;
} 
