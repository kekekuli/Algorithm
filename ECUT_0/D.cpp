#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

int arr0[N], arr1[N];

void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        arr0[i] = arr1[i] = 0;
    for (int i = 1; i <= m; i++){
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1){
            if (arr1[x] == 0){
                arr1[x] = i;
                continue;
            }
            if (arr1[x] + k - 1 < i){
                arr0[x] += k;
                arr1[x] = i;
            }
            else{
                arr0[x] += i - arr1[x];
                arr1[x] = i;
            }
        }
        else if (op == 2){
            if (arr1[x] == 0)
                continue;
            
            arr0[x] += min(i - arr1[x] , k);
            arr1[x] = 0;
        }
        else{
            if (arr1[x] == 0)
                printf("%d\n", arr0[x] + i - 1);
            else
                printf("%d\n", arr0[x] + i - 1 + min(i - arr1[x] , k));
        }
    }
}

int main(){
    solve();
    return 0;
}
