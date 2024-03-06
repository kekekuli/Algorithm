#include <iostream>
#define N 1000010
int primes[N], cnt;
bool st[N];
//埃氏质数筛, 时间复杂度大概O(nloglogn)约等于O(n)
void get_prime(int n){
    cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!st[i])
            //加入结果
            primes[cnt++] = i;
            //只要删去质数的倍数
            for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}
int main(){
    int n;
    std::cin >> n;
    get_prime(n);
    std::cout << cnt << std::endl;
    return 0;
}