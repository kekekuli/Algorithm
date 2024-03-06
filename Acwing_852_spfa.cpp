#include <iostream>
#include <queue>
#include <string.h>
#define N 10010
using namespace std;

int dis[N], cnt[N], n, m;

// h, st的索引最大值是n, 然而剩余的索引最大值是m
int h[N], e[N], ne[N], w[N], idx;
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a];
    h[a] = idx ++;
}

bool spfa(){
    // 因为不用求最短距离 所以不用初始化dis
    // 因为不只从1号点出发 所以初始化将所有点入队
    queue<int> q;
    for (int i = 1; i <= n; i++){
        st[i] = true;
        q.push(i);
    }
    
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            // 0是大于负环的负数的，所以不用设置dis为无穷大
            if (dis[j] > dis[t] + w[i]){
            
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                // 抽屉原理：走过的边数大于图的点数，那么一定有某点重复走过 
                if (cnt[j] >= n)
                    return true;
                if (!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return false;
}
int main(){
    memset(h, -1, sizeof(h));
    //领接表貌似不需要初始化ne数组
    //memset(ne, -1, sizeof(ne));
    
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);        
    }
    bool t = spfa();
    if (t)
        puts("Yes");
    else
        puts("No");
    
    return 0;
}