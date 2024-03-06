#include <iostream>
#include <cmath>
using namespace std;
//试除法判断质数
bool is_prime(int a){
    if ( a <= 1)
        return false;
    int x = sqrt(a); 
    for (int i = 2; i <= x; i++) 
        if (a % i == 0)
            return false;
    return true;
}
int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        if (is_prime(a)) 
            printf("Yes\n");
        else    
            printf("No\n");
    }
    return 0;
}