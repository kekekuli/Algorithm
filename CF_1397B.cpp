#include <iostream>
#include <algorithm>
#define LL long long
#define N 100010
using namespace std;
LL arr[N];

int main(){
    LL n, ans = INT64_MAX, m = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &arr[i]);
        m += abs(arr[i] - 1);
    }
    ans = min(ans, m);
    sort(arr, arr + n);
    for (LL c = 1; c <= 100000; c++){
        LL t = 1, cnt = 0;
        cnt += abs(arr[0] - t);
        for (int i = 1; i < n; i++){
            t *= c;
            cnt += abs(arr[i] - t);
            if (cnt >= ans)
                break;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}