#include <iostream>
#include <cstring>
#include <algorithm>
#define N 200010
using namespace std;
int f[N], n;
char arr[N];

void solve(){
    scanf("%s", arr + 1); 
    n = strlen(arr + 1);
    f[1]=  1;
    for (int i = 2; i <= n; i++){
        int k = i - 1;
        while(k > 0 && arr[k] != arr[i]) 
            k--;
        if (k == 0){
            f[i] = f[i - 1] + 1;
            continue; 
        }
        f[i] = min(f[k - 1] + i - k - 1, f[i - 1] + 1);
    }
    cout << f[n] << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}