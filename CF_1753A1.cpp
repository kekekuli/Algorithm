#include <iostream>
#define N 200010
using namespace std;
int arr[N];
void solve(){
    int n, s = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        s += arr[i];
        if (i % 2 == 0){
            if (arr[i] == arr[i - 1])
                cnt += 1;
            else
                cnt += 2;
        }
    }
    if (s % 2 == 0){
        printf("%d\n", cnt);
        for (int i = 1; i + 1 <= n; i += 2){
            if (arr[i] == arr[i + 1]){
                printf("%d %d\n", i, i + 1);
            }
            else
                printf("%d %d\n%d %d\n", i, i, i + 1, i + 1);
        } 
    }
    else
        printf("-1\n");
}
int main(){
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}