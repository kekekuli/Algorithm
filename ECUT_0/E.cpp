#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#define N 200010
#define LL long long
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    int a = n - 1, b = n * (n - 2);
    while(gcd(a, b) != 1){
        int c = gcd(a, b);
        a /= c;
        b /= c; 
    }
    printf("%d %d\n", a, b);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
