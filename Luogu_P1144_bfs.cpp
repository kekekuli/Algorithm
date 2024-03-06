#include <iostream>
#include <string.h>
#include <queue>

#define MOD 100003
#define N 1000010

// h, sel, e, ne, idx构成领接表
int h[N], e[N * 2], ne[N * 2], idx;
// sel[i]代表i到1有多少条最短路径，dis[i]代表i到1的最短距离
int sel[N], dis[N];
int n, m;

inline int plus(int a, int b){
    return (a % MOD + b % MOD) % MOD;
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void bfs(){
    std::queue<int> q;
    q.push(1);
    // 初始状态
    sel[1] = 1;
    dis[1] = 0;
    // 遍历队列
    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(int i = h[t]; i != -1; i = ne[i]){
            // 距离等于-1代表之前没有遍历过此节点
            // 距离等于上一节点距离加一代表这是一条最短路径，但是之前已经访问过
            if (dis[e[i]] == -1 || dis[e[i]] == dis[t] + 1){
                //更新路劲数
                sel[e[i]] = plus(sel[e[i]], sel[t]);
                //注意不要多次把相同节点入队
                //只要把第一次找到的节点入队就行
                if (dis[e[i]] == -1)
                    q.push(e[i]);
                //更新最短距离
                dis[e[i]] = dis[t] + 1;
            }
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    //初始化领接表
    memset(ne, -1, sizeof(ne));
    memset(h, -1, sizeof(h));
    memset(dis, -1, sizeof(dis));
    //输入
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    bfs();
    for (int i = 1; i <= n; i++){
        printf("%d\n", sel[i]);
    }
    return 0;
}