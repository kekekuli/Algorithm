#include <iostream>
#define N 1000010
int primes[N], cnt;
bool st[N];
//朴素质数筛, 朴素质数筛时间复杂度大概O(nlogn)
void get_prime(int n){
    cnt = 0;
    for (int i = 2; i <= n; i++){
        if (!st[i])
            //加入结果
            primes[cnt++] = i;
        // 删去此数的所有倍数
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