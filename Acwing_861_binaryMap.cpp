#include <iostream>
#include <cstring>
#define N 510
#define M 100010
int n1, n2, m, res, match[N];
int h[N], e[M], ne[M], idx;
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x){
    for (int i = h[x]; i != -1; i = ne[i]){
        int j = e[i];
        if (!st[j]){
            st[j] = true;
            if (match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
int main(){
    memset(h, -1, sizeof(h));
    scanf("%d%d%d", &n1, &n2, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n1; i++){
        memset(st, 0, sizeof(st));
        if (find(i))
            res++; 
    }
    printf("%d\n", res);
}