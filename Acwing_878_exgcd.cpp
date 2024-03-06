#include <iostream>
int exgcd(int a, int b, int &x, int &y){
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, x, y), tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, m, x, y;
        scanf("%d%d%d", &a, &b, &m);
        int d = exgcd(a, m, x, y);
        if (b % d)
            puts("impossible");
        else
            printf("%d\n", (long long) x * (b / d) % m);
    } 
    return 0;
}