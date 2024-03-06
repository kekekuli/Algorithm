#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        scanf("%d", &n);
        int x = sqrt(2 * n - 1);
        if (x % 2 == 0)
            x --;
        cout << (x + 1) / 2 - 1 << endl;
    } 
}