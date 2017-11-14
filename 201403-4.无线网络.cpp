#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#define mAXn 210
using namespace std;
int n, m, k, r;
bool e[mAXn][mAXn];
int pos[mAXn][2];
bool inrange(int a, int b, int r) {
    return sqrt(pow(pos[a][0]-pos[b][0],2)+pow(pos[a][1]-pos[b][1],2))<=r;
}
int bfs(int s, int t) {
    vector<bool> vis(m+n);
    queue<pair<int,int> > q;
    q.push(make_pair(s,0));
    int len = 1, newLen, level = 1;
    while(len>0) {
        newLen = 0;
        for(int l=0; l<len; l++) {
            pair<int,int> f = q.front();
            if(f.first == t) return level-2;
            q.pop();
            for(int i=0; i<n; i++) 
                if(e[f.first][i] && !vis[i]) {
                    q.push(make_pair(i,f.second));
                    vis[i] = true;
                    newLen++;
                }
            for(int i=n; i<n+m; i++) 
                if(e[f.first][i] && !vis[i] && f.second<k) {
                    q.push(make_pair(i,f.second+1));
                    vis[i] = true;
                    newLen++;
                }
        }
        len = newLen;
        level++;
    }
    return -1;
}
int main() {
    scanf("%d%d%d%d", &n, &m, &k, &r);
    for(int i=0; i<n+m; i++) scanf("%d%d", &pos[i][0], &pos[i][1]);
    for(int i=0; i<n+m; i++) 
        for(int j=i+1; j<n+m; j++) 
            e[i][j] = e[j][i] = inrange(i, j, r);
    printf("%d", bfs(0, 1));
}
