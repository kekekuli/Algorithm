#include <iostream>
#include <cstring>
#include <queue>
#define N 100010
#define M 200010
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
void init(){
    memset(h, -1, sizeof(h));
}
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool draw(int x){
    if (color[x] != 0)
        return true;
    std::queue<int> q;
    color[x] = 1;
    q.push(x);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (!color[j]){
                color[j] = -color[t];
                q.push(j);
            }
            else if (color[j] != -color[t])
                    return false;
        }
    }
    return true;
}
int main(){
    init();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    for (int i = 1; i <= n; i++){
        if (!draw(i)){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}