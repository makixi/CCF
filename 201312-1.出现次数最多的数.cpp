#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
using namespace std;
const int inf=0x3f3f3f3f;
int main(){
	int n,res=inf,cnt=0;
	map<int,int> m;
	scanf("%d",&n);
	while(n--){
		int tmp;
		scanf("%d",&tmp);
		m[tmp]++;
		if(m[tmp]>cnt){
			cnt=m[tmp];
			res=tmp;
		}else if(m[tmp]==cnt&&res>tmp)res=tmp;
	}
	cout<<res;
	return 0;
}
