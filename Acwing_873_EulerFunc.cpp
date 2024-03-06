#include <iostream>
using namespace std;
int main(){
    int x, n, res;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        res = x;
        for (int j = 2; j <= x / j; j++){
            if (x % j == 0){
                res = res / j * (j - 1);
                while(x % j == 0)
                    x /= j;
            }
        }
        if (x != 1)
            res = res / x * (x - 1);
        printf("%d\n", res);
    }
    return 0;
}