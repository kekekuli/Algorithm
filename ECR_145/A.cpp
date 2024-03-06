#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#define N 200010
#define LL long long
using namespace std;
int arr[10], idx;

void solve(){
    memset(arr, 0, sizeof(arr));
    idx = 0;
    int n;
    scanf("%d", &n);
    while(n){
        arr[idx++] = n % 10;
        n /= 10;
    }
    sort(arr, arr + 4);
    if (arr[0] == arr[3]){
        cout << -1 << endl;
    }
    else if (arr[0] == arr[2] || arr[1] == arr[3]){
        cout << 6 << endl;
    }
    else
        cout << 4 << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) 
        solve();
    return 0;
}