#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 200010
using namespace std;

int h[N], e[2 * N], ne[2 * N], idx;
// A tree has two ends node consisting diameter
// dis0[x] is the distance between one end and x
// dis1[x] is the other end 
int n, dis0[N], dis1[N];

void init(){
    idx = 0;
    memset(h, -1, sizeof(int) * (n + 10));    
}

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
// update the distance that having edge with x, storing in dis
void dfs(int x, int par, int now, int dis[]){
    dis[x] = now;
    for (int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        // Tree has no cycles, so it is correct with this
        if (j == par)
            continue;
        dfs(j, x, now + 1, dis);
    }
}

void solve(){
    scanf("%d", &n);
    init();
    for (int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1, -1, 0, dis0);
    int a = 0, ai = 1;
    for (int i = 1; i <= n; i++)
        if (dis0[i] > a){
            a = dis0[i];
            ai = i;
        }
    dfs(ai, -1, 0, dis1);
    int b = 0, bi = 1;
    for (int i = 1; i <= n; i++)
        if (dis1[i] > b){
            b = dis1[i];
            bi = i;
        }
    dfs(bi, -1, 0, dis0);
    for (int i = 1; i <= n; i++)
        dis0[i] = max(dis0[i], dis1[i]);
    sort(dis0 + 1, dis0 + n + 1);
    int ans = 1;
    for (int i = 1; i <=n; i++){
        while(ans <= n && dis0[ans] < i)
            ans++;
        cout << min(n, ans) << ' ';
    }
    cout << "\n";
}

int main(){
        solve();
    return 0;
}