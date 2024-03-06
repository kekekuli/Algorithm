#include<iostream>
#include<math.h>
#define N 100
int a[N], b[N];
int max(int a, int b){
    return a > b ? a : b;
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < pow(2, n); i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    for (int i = n; i > 1; i--){
        for (int j = 0, k = 0; j < pow(2, i); j += 2, k++)
            a[k] = max(a[j], a[j + 1]);
    }
    int ans;
    if (a[0] > a[1])
        ans = a[1];
    else ans = a[0];
    for (int i = 0; i < pow(2, n); i++){
        if (ans == b[i]){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    return 0;
}