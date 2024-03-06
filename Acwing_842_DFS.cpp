#include <iostream>
#define N 10

int path[N];
bool flag[N];
int u;
void dfs(int x){
    if (x == u){
        for (int i = 0; i < u; i++)
            printf("%d ", path[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= u; i++){
        if (!flag[i]){
            flag[i] = true;
            path[x] = i;
            dfs(x + 1);
            flag[i] = false;
        }
    }
}

int  main(){
    scanf("%d", &u);
    dfs(0);
    return 0;
}