#include <iostream>
#define N 110
using namespace std;

int a[N], b[N];
int GCD(int a, int b){
    return b == 0 ? a : GCD(b, a % b);
}
int LCM(int a, int b){
    return a / GCD(a, b) * b;
}
void solve(){
    int n, res = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &b[i]);
    for (int i = 0; i <= 1000; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            int tmp = i;
            char tp = s[j];
            if (tmp < b[j]){
                cnt += (tp == '1');
                continue;
            }
            tmp -= b[j];
            tp = (tp == '0' ? '1' : '0');
            while(tmp >= a[j]){
                tmp -= a[j];
                tp = (tp == '0' ? '1' : '0');
            }
            cnt += (tp == '1');
        }
        res = res < cnt ? cnt : res;
    }
    printf("%d\n", res);
}
int main(){
    solve();
    return 0;
}