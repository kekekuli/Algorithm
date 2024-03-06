#include <iostream>
#define N 110
int primes[N], cnt;
bool st[N];
void get_primes(int n){
    cnt = 0;
    for(int i = 2; i <= n; i++){
        if (!st[i])  
            primes[cnt ++] = i;
        // 每次要筛去primes[j] * i, 如果primes[j] * i > n 超出了n就没必要筛去，因为我们只关心1~n
        for (int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            //如果此式子成立,那么i*primes[j+1]会后来随着i的递增(i应该会增长到(i/primes[j]) * primes[j + 1])被primes[j]筛去
            //这时不break的话i*primes[j+1]就会被primes[j+1]筛去,就导致了重复筛去同一个数
            if (i % primes[j] == 0)
                break;
        }
    } 
}
int main(){
    int n;
    std::cin >> n;
    get_primes(n);
    printf("%d\n", cnt);
    return 0;
}