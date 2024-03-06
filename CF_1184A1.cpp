#include <iostream>
#define LL long long

using namespace std;

void solve(){
    LL r, x, y;
    cin >> r;
    r--;
    for (LL i = 1; i <= r / i; i++){
        LL tmp;
        if (r % i == 0){
            x = i;
            tmp = r / x;
            tmp -= x + 1;
            if (tmp > 0 && tmp % 2 == 0){
                y = tmp / 2;
                cout << x << " " << y << endl;
                return;
            }
            
            x = r / i;
            tmp = r / x;
            tmp -= x + 1;
            if (tmp > 0 && tmp % 2 == 0){
                y = tmp / 2;
                cout << x << " " << y << endl;
                return;
            }
        }
    }
    cout << "NO" << endl; 
}
int main(){
    solve(); 
    return 0;
}