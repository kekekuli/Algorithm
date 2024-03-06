#include <iostream>
#include <algorithm>
#define N 100010
#define PII pair<int, int>
using namespace std;
PII arr[N];

bool com(PII a, PII b){
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);
    sort(arr + 1, arr + n + 1, com);
    int now = -2 * 1e9, ans = 0;
    for (int i = 1; i <= n; i++){
        if (arr[i].first <= now && now <= arr[i].second)
            continue;
        else{
            ans++;
            now = arr[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}