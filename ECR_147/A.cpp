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
    int h = 0;
    while(h < s.size() && s[h] == '0')
        h++;
    if (h){
        printf("0\n");
        return;
    }
    int ans = 1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '?'){
            if (i == 0)
                ans *= 9;
            else
                ans *= 10;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}