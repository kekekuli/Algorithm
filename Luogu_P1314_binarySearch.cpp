#include <stdio.h>
#include <iostream>
#include <string.h>
#include <climits>
#define MAX 200010
#define W_BOUND 1000010
long long n, m, s;
long long w[MAX], v[MAX];
long long prev[MAX], prev_v[MAX];
int left[MAX], right[MAX];
// Check function return y summation

long long abs(long long x){
    if (x < 0)
        return -x;
    return x;
}

long long check(int ww){
    long long y = 0;
    memset(prev, 0, sizeof(prev));
    memset(prev_v, 0, sizeof(prev_v));
    // init prev arrays
    for (int i = 1; i <= n; i++){
        prev[i] = prev[i - 1];
        prev_v[i] = prev_v[i - 1];
        if (w[i] >= ww){
            prev[i] += 1;
            prev_v[i] += v[i];
        }
    }
    // caclute each yi, added to y
    for (int i = 1; i <= m; i++){
        y += (prev[right[i]] - prev[left[i] - 1]) * (prev_v[right[i]] - prev_v[left[i] - 1]);
    }
    return y;
}
long long binary_search(int l, int r){
    long long diff_min = LLONG_MAX;
    while(l < r){
        // binary search W
        int mid = (l + r) / 2;
        long long y = check(mid);
        if (s - y < 0){
            l = mid + 1;
        }
        else{
            r = mid;
        }
        // update diff_min
        if (diff_min > abs(s - y)){
            diff_min = abs(s - y);
        }
    }
    return diff_min;
}
int main(){
    scanf("%lld%lld%lld", &n, &m, &s);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld", &w[i], &v[i]);
    }
    for (int i = 1; i <= m; i++){
        scanf("%d%d", &left[i], &right[i]);
    }
    printf("%lld\n", binary_search(0, W_BOUND));
    return 0;
}