#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct node{
	int x1,x2,y1,y2;
	int index;
};
vector<node> v;
int main(){
	int m,i;
	scanf("%d%d",&n,&m);
	v.resize(n);
	for(i=0;i<n;++i){
		scanf("%d%d%d%d",&v[i].x1,&v[i].y1,&v[i].x2,&v[i].y2);
		v[i].index=i+1;
	}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		for(i=n-1;i>=0;--i)
			if(v[i].x1<=x&&v[i].x2>=x&&v[i].y1<=y&&v[i].y2>=y){
				cout<<v[i].index<<"\n";
				break;
			}
		if(i==-1)cout<<"IGNORED\n";
		else{
			node tmp=v[i];
			v.erase(v.begin()+i);
			v.push_back(tmp);
		}
	}
	return 0;
} 
