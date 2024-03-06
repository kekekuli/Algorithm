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
    int n;
    scanf("%d", &n);
    cin >> s;
    int x = 0, y =0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1')
            x++;
        else
            y++;
    }
    for (int i = (1 << x); i <= (1 << n) - (1 << y) + 1; i++) 
        printf("%d ", i);
    printf("\n");
}

int main(){
    solve();
    return 0;
}