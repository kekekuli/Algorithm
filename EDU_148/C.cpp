#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

bool dele(vector<int> &arr, vector<int> &tmp){
    int n, flag;
    n = arr.size(), flag = 0;
    tmp.clear();

    tmp.push_back(arr[0]);
    for (int i = 1; i < n - 1; i++){
        if (abs(tmp[tmp.size() - 1] - arr[i]) + abs(arr[i] - arr[i + 1]) == abs(arr[i + 1] - tmp[tmp.size() - 1]))
            flag = 1;
        else
            tmp.push_back(arr[i]);
    }
    tmp.push_back(arr[n - 1]);
    return flag;
}

void solve(){
    int n;
    scanf("%d", &n);
    vector<int> arr, tmp;
    for (int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    int flag0= 1, flag1 = 1, cnt = 0;;
    while(flag0){
        if (flag1)
            flag0 = dele(arr, tmp);
        else
            flag0 = dele(tmp, arr);
        flag1 = !flag1;
    }
    if (!flag1)
        arr = tmp;
    int i = 0, j = arr.size() - 1; 
    while(i < j && arr[i] == arr[i + 1])
        i++;
    while(i < j && arr[j] == arr[j - 1])
        j--;
    cout << j - i + 1 << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
