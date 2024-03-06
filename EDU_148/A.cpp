#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

void solve(){
    string s;
    cin >> s;
    int i = 0, j = s.size() - 1, ii = i + 1, jj = j - 1, flag = 0;
    while(ii < jj){
        if (s[ii] != s[i])
            flag = true;
        ii++;
        jj--;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
