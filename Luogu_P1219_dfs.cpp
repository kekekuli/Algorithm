#include <iostream>
#define N 27
int n;
int path[N];
bool dia[N], at_dia[N], col[N];
int count = 0;
void dfs(int u){
    if (u == n){
        count++;
        if (count <= 3){
            for (int i = 0; i < n; i++){
                printf("%d ", path[i]);
            }
            printf("\n");
        }
        return;
    }
    for (int i = 1; i <= n; i++){
        if (!col[i] && !dia[u + i] && !at_dia[n - (u - i)]){
            path[u] = i;
            col[i] = dia[u + i] = at_dia[n - (u - i)] = true;
            dfs(u + 1);
            col[i] = dia[u + i] = at_dia[n - (u - i)] = false;
        }
    }
}
int main(){
    scanf("%d", &n);
    dfs(0);
    printf("%d\n", count);
}