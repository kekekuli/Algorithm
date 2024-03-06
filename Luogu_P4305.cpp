#include <iostream>
#include <string.h>
#define N 50021
int h[N], e[N], ne[N], idx;
bool flag[N];
int find(int x){
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]){
        if (e[i] == x)
            return i;
    }
    return -1;
}
void insert(int x){
    int k = (x % N + N) % N;
    int t = find(x);
    if (t == -1){
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx++;
    }
}

int main(){
    int T, n, nums[N];
    scanf("%d", &T);
    while(T--){
        memset(h, -1, sizeof(h));
        memset(flag, 0, sizeof(flag));
        idx = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &nums[i]);
            insert(nums[i]);
            int t = find(nums[i]);
            
            if(flag[t] == 0){
                printf("%d ", nums[i]);
                flag[t] = 1;
            }
        }
        printf("\n");
    }
    return 0;
}