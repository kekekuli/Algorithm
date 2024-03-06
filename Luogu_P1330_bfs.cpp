#include <iostream>
#include <queue>
#include <string.h>
#include <utility>
#define N 10010
using namespace std;

int h[N], e[2 * N * 10], ne[2 * N * 10], idx;
// 0代表没有访问过,1代表访问过而且有一只河蟹,-1代表访问过而且相邻有一只河蟹
// 判断有无答案:如果颜色为1的点有一条路通往颜色为1的点,或-1有到-1的点，则无答案
// 这个图并没有说明是不是连通图
int color[N];
int n, m, ans;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int bfs(int u){
    // .first是图节点编号, .second是颜色
    queue<pair<int, int>> q;
    q.push({u, 1});
    color[u] = 1;
    // cnt记录从u点开始一共能到达多少个其他点
    // 假如染成1的有cnt_color个,那么cnt_color和cnt-cnt_color之间最小的那个就是需要的最少河蟹
    int cnt = 1;
    int cnt_color = 1; 

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        for (int i = h[t.first]; i != -1; i = ne[i]){
            int j = e[i];
            // 这个点之前没有访问过或者访问过但不冲突
            if (color[j] == 0 || color[j] == - color[t.first]){
                if (color[j] == 0){
                    cnt++;
                    if (- color[t.first] == 1){
                        cnt_color++;
                    }
                    color[j] = - color[t.first];
                    q.push({j, color[j]});
                }
            }
            // 冲突了
            else{
                return -1;
            }
        }
    }
    return cnt_color < cnt - cnt_color ? cnt_color : cnt - cnt_color;
}

int main(){
    memset(ne, -1, sizeof(ne));
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != b){
            add(a, b);
            add(b, a);
        }
    } 
    for (int i = 1; i <= n; i++){
        if (color[i] == 0){ 
            int cnt = bfs(i);
            // 无论如何都有冲突
            if (cnt == -1){
                printf("Impossible\n");
                return 0;
            }
            ans += cnt;
        }
    }
    printf("%d\n", ans);
}