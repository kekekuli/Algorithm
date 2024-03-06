#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
#define PII pair<int, int>
using namespace std;
int arr0[N], arr1[N], q[N];

void solve(){
    int n, l, r, ptr = 0, mm = 0, bto, fir = -1, ed = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr0[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 1; i <= n; i++){
        if (arr0[i] != arr1[i]){
            ed = i;
            if (fir == -1)
                fir = i;
        }
    } 
    for (int i = 1; i <= n; i++){
        if (q[ptr] > arr1[i])
            while(ptr > 0)
                ptr--;
        if (ptr == 0) 
            bto = i;
        q[++ptr] = arr1[i];
        if (mm < ptr && (fir == -1 || (bto <= fir && i >= ed))){
            mm = ptr;
            l = bto;
            r = i;
        }
    } 
    printf("%d %d\n", l, r);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}