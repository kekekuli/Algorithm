#include <iostream>
#include <algorithm>
using namespace std;
int arr[60];
int main(){
    int n;
    long long res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + n + 1);
    for (int i = 1; i <= n; i++){
        int x = arr[i] - i + 1;
        if (x <= 0){
            res = 0;
            break;
        }
        res = res * x % 1000000007;
    }
    cout << res << endl;
    return 0;
}