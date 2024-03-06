#include <iostream>
#define N 100
typedef long long LL;
LL m[N], mr[N], a[N];
LL exgcd(LL a, LL b, LL &x, LL &y){
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    LL d = exgcd(b, a % b, x, y), tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
}
//求a的模m乘法逆元
LL mod_reverse(LL a, LL m){
    LL x, y;
    LL d = exgcd(a, m ,x, y);
    if (d == 1)
        //直接return x导致可能返回负数 
        return (x % m + m) % m;
    return -1;
}
int main(){
    LL n;
    LL res = 0, M = 1;
    std::cin >> n;
    for (LL i = 0; i < n; i++){
        std:: cin >> m[i] >> a[i];
        M *= m[i];
    } 
    for (LL i = 0; i < n; i++){
        m[i] = M / m[i];
        mr[i] = mod_reverse(a[i], m[i]);
    }
    for (LL i = 0; i < n; i++){
        if (mr[i] == -1){
            res = -1;
            break;
        }
        res += (LL)a[i] * m[i] * mr[i];
    }
    std::cout << res << std::endl;
    return 0;
}