// 领接表和距离初始化别忘了 血的教训
#include <iostream>
#include <queue>
#include <string.h>
#define N 100010

using namespace std;

int h[N], e[N], ne[N], w[N], idx;
int dis[N], n, m;
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a];
    h[a] = idx++;
}

void spfa(){
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;
    
    while(q.size()){
        //拿出队头
        int i = q.front();
        q.pop();
        st[i] = false;
        //遍历i的所有出边并且更新最短距离
        for (int t = h[i]; t != -1; t = ne[t]){
            int j = e[t];
            if (dis[j] > dis[i] + w[t]){
                // 只有需要更新最短距离并且没有在队列中的需要入队。
                dis[j] = dis[i] + w[t];
                if (!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    if (dis[n] == 0x3f3f3f3f)
        printf("impossible\n");
    else
        printf("%d\n", dis[n]);
    
}
int main(){
    memset(h, -1, sizeof(h));
    memset(ne, -1, sizeof(ne));
    
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        add(a, b, w);
    }
    spfa();
    return 0;
}