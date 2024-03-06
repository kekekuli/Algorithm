#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 200010
#define LL long long
using namespace std;

void solve(){
    LL x;
    cin >> x;
    LL l = 0, r = sqrt(x);
    while(l < r){
        LL mid = (l + r) >> 1;
        bool flag = false;
        if (mid % 2 == 0){
            LL n = mid / 2;
            flag = 4 * (n * n + n) + 1 >= x;
        }
        else{
            LL n = (mid + 1) / 2;
            flag = n * n * 4 >= x;
        }
        if (flag)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}