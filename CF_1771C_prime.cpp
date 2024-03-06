#include <map>
#include <iostream>
using namespace std;
#define N 200010
int primes[N], cnt = 0;
bool st[N];
map<int, int> mm;
void get_primes(int n){
    for (int i = 2; i <= n; i++){
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++){
            st[i * primes[j]] = true;
            if (i % primes[j]== 0)
                break;
        }
    }
}
int main(){
    get_primes(N);
    int t;
    scanf("%d", &t);
    while(t--){
        mm.clear();
        int n, x;
        bool flag = false;
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &x);
            if (!flag){
                for (int j = 0; primes[j] <= x / primes[j]; j++){
                    if (x % primes[j] == 0){
                        mm[primes[j]]++;
                        while(x % primes[j] == 0) 
                            x /= primes[j];
                        if (mm[primes[j]] >= 2){
                            flag = true;
                            break;
                        }
                    }
                }
                if (x > 1){
                    mm[x]++;
                    if(mm[x] >= 2)
                        flag = true;
                }
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}