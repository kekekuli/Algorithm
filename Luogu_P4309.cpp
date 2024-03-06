#include <iostream>
#include <string.h>
#define N 1010
double e[N];
int ne[N];
int idx;
int find(double x){
    for (int i = 0; i != -1; i = ne[i]){
        i;
        if (e[i] == x)
            return i;
    }
    return -1;
}

void insert(double x){
    int t = find(x);
    if (t == -1){
        e[idx] = x;
        ne[idx] = idx++;
        
    }
}
int main(){
    memset(ne, -1, sizeof(ne));

    int n, x0, y0, flag = 0;
    scanf("%d%d%d", &n, &x0, &y0);
    for (int i = 0; i < n; i++){
        int x, y;
        double k;
        scanf("%d%d", &x, &y);

        if (x != x0){
            k = (double)(y - y0) / (double)(x - x0);
            k *= 1000010;
            insert(k);
        }
        else flag = 1;
    }
    printf("%d ", idx + flag);
    return 0;
}