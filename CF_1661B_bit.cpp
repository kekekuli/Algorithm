#include <iostream>
#include <algorithm>
#define LL long long
#define N 32768
#define MOD 32768
using namespace std;

LL last(LL x){
    return x & -x;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        LL a;
        cin >> a;
        LL ans = -1;
        //所有数字的最优解都小于16
        for (LL i = 0; i < 16; i++){
            LL t = last((a + i) % MOD), k = 0;
            while(t){
                t = (t << 1) % MOD;
                k++;
            }
            if (ans == -1 || (k + i) < ans)
                ans = k + i;
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}