// 分解质因数
#include <iostream>
using namespace std;
void divide(int n){
    for (int i = 2; i <= n / i; i++) {
        // 如果满足, 那么i一定是质数
        if (n % i == 0){
            int s = 0;
            while(n % i == 0){
                s++;
                n /= i;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (n != 1)
        printf("%d %d\n", n, 1);
    printf("\n");
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        divide(a);
    }
}