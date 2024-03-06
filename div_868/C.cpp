#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#define N 200010
#define LL long long
using namespace std;

map<int, int> mm;

void solve(){
    mm.clear();
    int n, cnt0 = 0, cnt1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int x;
        scanf("%d", &x);
        for (int i = 2; i <= x / i; i++){
            if (x % i == 0){
                while(x % i == 0){
                    mm[i]++;
                    if (mm[i] == 1){
                        cnt1++;
                    }
                    else{
                        mm[i] = 0;
                        cnt0++;
                        cnt1--;
                    }
                    x /= i;
                }
            }
        }
        if (x != 1){
            mm[x]++;
            if (mm[x] == 1)
                cnt1++;
            else{
                mm[x] = 0;
                cnt0++;
                cnt1--;
            }
        }
    }
    if (cnt0 == 0 && cnt1 < 3){
        printf("0\n");
    }
    else{
        cout << cnt0 + cnt1 / 3 << endl;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
