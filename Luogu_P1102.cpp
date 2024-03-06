#include <iostream>
#include <string.h>
#define N 200017

long long h[N], e[N], ne[N], count[N], idx;

long long find(long long x){
    long long k = (x % N + N) % N;
    for(long long i = h[k]; i != -1; i = ne[i]){
        if (e[i] == x)
            return i;
    }
    return -1;
}
void insert(long long x){
    long long t = find(x), k = (x % N + N) % N;
    if (t != -1){
        count[t] ++;
    } 
    else {
        e[idx] = x;
        ne[idx] = h[k];
        count[idx] += 1;
        h[k] = idx++;
    }
}
int main(){
    long long n, c, ans = 0, nums[N];
    memset(h, -1, sizeof(h));
    scanf("%lld%lld", &n, &c);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &nums[i]);
        insert(nums[i]);
    }
    for (int i = 1; i<= n; i++){
        long long x = nums[i] - c;
        long long t = find(x), t2 = find(nums[i]);
        count[t2]--;
        if (t != -1){
            ans += count[t];
        }
        count[t2]++;
    }
    printf("%lld\n", ans);
    return 0;
}