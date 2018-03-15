#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct P{
    int x,y;
};
char Map[55][55];
int mov[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
bool able[55][55][55][55],v1[55][55],v2[55][55];
void get(P a,int &st,int &ed){
    if(Map[a.x][a.y]=='-') st=2,ed=4;
    else if(Map[a.x][a.y]=='|') st=0,ed=2;
    else if(Map[a.x][a.y]=='.') st=0,ed=1;
    else st=0,ed=4;
}
int main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i) scanf("%s",Map[i]);
    queue<P> q;
    P p,e;
    for(i=0;i<n;++i)
    for(j=0;j<m;++j){
        if(Map[i][j]=='S'){
            p.x=i,p.y=j;
            q.push(p);
        }
        else if(Map[i][j]=='T'){
            e.x=i,e.y=j;
        }
    }
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    memset(able,0,sizeof(able));
    v1[p.x][p.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        int st,ed;
        get(p,st,ed);
        for(i=st;i<ed;++i){
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'){
                able[p.x][p.y][tem.x][tem.y]=1;
                if(!v1[tem.x][tem.y]){
                    v1[tem.x][tem.y]=1;
                    q.push(tem);
                }
            }
        }
    }
    if(!v1[e.x][e.y]) {puts("I'm stuck!");return 0;}
    int ans=0;
    q.push(e);
    v2[e.x][e.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        for(i=0;i<4;++i){
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'&&able[tem.x][tem.y][p.x][p.y]&&!v2[tem.x][tem.y]){
                v2[tem.x][tem.y]=1;
                q.push(tem);
            }
        }
    }
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            if(v1[i][j]&&!v2[i][j]) ++ans;
    printf("%d\n",ans);
    return 0;
}

