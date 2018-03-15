#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;
const int maxn = 512;
int n, m;
ll path[maxn][maxn];//С·
ll road[maxn][maxn];//��·
ll dijkstra() {
	bool vispath[maxn] = { false }, visroad[maxn] = { false };
	vector<ll> pathdis(path[0], path[0] + n);//ǰ����С·��dis
	vector<ll> roaddis(road[0], road[0] + n);//ǰ���Ǵ�·��dis
	vector<ll> pre(n, inf);//ÿ���ڵ�ǰ�������С·
	for (int i = 0; i < n; ++i) 
		if (pathdis[i] < inf) {
			pre[i] = pathdis[i];
			pathdis[i] *= pathdis[i];
		}
	vispath[0] = visroad[0] = true;
	while (true) {
		ll minn = inf;
		int u = -1, flag = 0;
		for (int i = 0; i < n; ++i) {
			if (!visroad[i] && minn > roaddis[i]) {
				minn = roaddis[i];
				u = i;
				flag = 0;//��·
			}
			if (!vispath[i] && minn > pathdis[i]) {
				minn = pathdis[i];
				u = i;
				flag = 1;//С·
			}
		}
		if (u == -1)break;
		if (flag == 1)vispath[u] = true;
		else visroad[u] = true;
		for (int i = 0; i < n; ++i) {
			if (!vispath[i] && path[u][i] < inf) {
				if (flag == 1) {//ǰ����С·
					ll len = pathdis[u] - pre[u] * pre[u] + (pre[u] + path[u][i])*(pre[u] + path[u][i]);
					if (pathdis[i]>len || (pathdis[i] == len && pre[i]>pre[u] + path[u][i])) {
						pathdis[i] = len;
						pre[i] = pre[u] + path[u][i];
					}
				}
				else {
					ll len = roaddis[u] + path[u][i]* path[u][i];
					if (pathdis[i]>len || (pathdis[i] == len && pre[i]>path[u][i])) {
						pathdis[i] = len;
						pre[i] = path[u][i];
					}
				}
			}
			if (!visroad[i] && road[u][i] < inf) {
				if (flag == 1) {//uǰ����С·
					ll len = pathdis[u] + road[u][i];
					roaddis[i] = min(len, roaddis[i]);
				}
				else {//uǰ���Ǵ�·
					ll len = roaddis[u] + road[u][i];
					roaddis[i] = min(len, roaddis[i]);
				}
			}
		}
	}
	return min(pathdis[n - 1], roaddis[n - 1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	memset(road, inf, sizeof(road)); memset(path, inf, sizeof(path));
	while (m--) {
		ll t, a, b, c;
		cin >> t >> a >> b >> c;
		--a; --b;
		if (t == 1)path[a][b] = path[b][a] = min(c, path[a][b]);
		else road[a][b] = road[b][a] = min(c, road[a][b]);
	}
	cout << dijkstra();
	return 0;
}
