#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1010;
int e[maxn][maxn];
bool vis[maxn][maxn];
int n;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
struct node{
	int x,y;
	long long dis;
	node(int xx,int yy,long long dd):x(xx),y(yy),dis(dd){}
};
bool judge(int x,int y){
	if(x<1||y<1||x>n||y>n)return false;
	if(vis[x][y])return false;
	return true;
}
int main(){
	int m,k,d,x,y,c;
	scanf("%d%d%d%d",&n,&m,&k,&d);
	memset(e,0,sizeof(e));
	queue<node> q;
	while(m--){
		scanf("%d%d",&x,&y);
		q.push(node(x,y,0));
	}
	while(k--){
		scanf("%d%d%d",&x,&y,&c);
		e[x][y]+=c;
	}
	while(d--){
		scanf("%d%d",&x,&y);
		vis[x][y]=1;
	}
	long long res=0;
	while(!q.empty()){
		node u=q.front();q.pop();
		for(int i=0;i<4;++i){
			int nx=u.x+dx[i];
			int ny=u.y+dy[i];
			if(judge(nx,ny)){
				vis[nx][ny]=true;
				if(e[nx][ny])res+=e[nx][ny]*(u.dis+1);
				q.push(node(nx,ny,u.dis+1));
			}
		}
	}
	cout<<res;
	return 0;
}
