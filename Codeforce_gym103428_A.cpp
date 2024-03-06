#include <iostream>
#define N 1000010
int f[N];
int main(){
    int n, ans = 0;
    bool flag = false;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        f[a]++;
        f[b]++;
    }
    for (int i = 1; i <= n; i++){
        if (f[i] > 3 || f[i] == 0){
            flag = true;
        }
        else if (f[i] < 3){
            ans++;
        }
    }
    if (!flag){
        printf("%d\n", ans);
    }
    else{
        printf("0\n");
    }
    return 0;
}