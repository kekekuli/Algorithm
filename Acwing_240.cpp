#include <iostream>
#define N 50010

int p[N], d[N];
int find(int x){
    if (p[x] != x){
    //回溯所以要先find
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(){
    int n, m, res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        int px = find(x), py = find(y);
        if (x > n || y > n) res ++;
        else{
            if (t == 1){
                if (px == py && ((d[x] - d[y]) % 3)) res ++;
                else if (px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else {
                if (px == py && ((d[x] - d[y] - 1) % 3)) res++;
                else if (px != py){
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}