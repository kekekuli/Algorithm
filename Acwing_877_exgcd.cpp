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
        int a, b, x, y;
        scanf("%d%d", &a, &b);
        exgcd(a, b, x, y);
        printf("%d %d\n", x, y);
    }
    return 0;
}