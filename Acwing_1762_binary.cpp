#include <iostream>
#define LL long long
#define N 100010
LL arr[N];
LL fn(LL a){
    if ((a & -a) == a)
        return a;
    LL res = 1;
    while(a){
        a >>= 1;
        res <<= 1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        printf("%d\n", n);
        for (int i = 1; i <= n; i++){
            printf("%d %d\n", i, fn(arr[i]) - arr[i]);
        } 
    } 
    return 0;
}