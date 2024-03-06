#include <iostream>
int main(){
    long n;
    int ans = 0;
    scanf("%d", &n);
    if (n == 0)
        ans = 1;
    while(n){
        int t = n & 15;
        if (t == 0 || t == 4 || t == 6 || t == 9 || t == 10 || t == 13)
            ans += 1;
        else if (t == 8 || t == 11)
            ans += 2;
        n = n >> 4;
    }
    printf("%d", ans);
    return 0;
}