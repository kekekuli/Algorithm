#include <iostream>
#include <cstring>
#include <algorithm>
#define N 6010
using namespace std;
int arr[N], f[N][2];
int h[N], e[N], ne[N], idx;
bool has_father[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u){
    f[u][1] = arr[u];
    f[u][0] = 0;

    for (int i = h[u]; i != -1; i = ne[i]){
        int s = e[i];
        dfs(s);
        f[u][1] += f[s][0];
        f[u][0] += max(f[s][0], f[s][1]);
    }
}

int main(){
    memset(h, -1, sizeof(h));
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    for (int i = 1; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        has_father[a] = true;
        add(b, a);
    }
    int root = 1;
    while(has_father[root])
        root++;
    dfs(root);
    cout << max(f[root][0], f[root][1]) << endl;
    return 0;
}