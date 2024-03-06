#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 210
#define LL long long
using namespace std;

int arr[N], tmp[N];

LL get(LL x){
    return 1 << x;
}

void solve(){
    int n;
    LL ans0 = 0, ans1 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        tmp[i] = arr[i];
    }
    sort(arr + 1, arr + n + 1);
    sort(tmp + 1, tmp + n + 1); 
    for (int i = n; i >= 1; i--)
        ans0 += (LL)1 << arr[i];
    LL l = 0, r;
    LL x = 1, y = n, flag = 1, i = 1;
    while(x <= y){
        if (flag){
            arr[i] = tmp[x];
            x++;
            i++;

        }
        else{
            arr[i] = tmp[y];
            y--;
            i++;
        }
        flag = !flag;
    }

    for (int i = 1; i < n; i++){
        r = l + get(arr[i]);
        //printf("%lld %lld : %lld\n", l, r, get(arr[i]));
        if (r % get(arr[i + 1]))
            l = (r / get(arr[i + 1]) + 1) * get(arr[i + 1]);
        else
            l = (r / get(arr[i + 1])) * get(arr[i + 1]);
    }
    printf("%lld %lld\n", ans0, r + get(arr[n]));
}

int main(){
    solve();
    return 0;
}
