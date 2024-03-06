#include <iostream>
#include <string.h>
#define N 100010
/*领接表，树、图（有向、无向）都可以存，
效率很高，形势上类似于拉链法哈希
树是特殊的图，无向连通图
领接表可以存有向图
无向图是有向图的一种，即各自有一条指向对方的边
*/
int e[N * 2], ne[N * 2], h[N], idx, ans = N , n;
bool st[N];
int max(int a, int b){
    return a > b ? a : b;
}
int min(int a, int b){
    return a < b ? a : b;
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u){
    st[u] = true;

    int sum = 1, res = 0;

    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        //判断是否走过(dfs)
        if(!st[j]){
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    
    ans = min(ans, res);

    return sum;
}

int main(){
    memset(h, -1, sizeof(h));
    //memset(ne, -1, sizeof(ne));
    scanf("%d", &n);
    ans = n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}