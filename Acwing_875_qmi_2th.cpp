#include<iostream>
#define LL long long
int qmi(int a, int k, int p){
    if (k == 0)
        return 1;
    else if (k & 1) 
        return (LL)a * qmi(a, k - 1, p) % p;
    else {
        LL temp = qmi(a, k / 2, p);
        return temp * temp % p;
    } 
}
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%d\n", qmi(a, b, p)); 
    }
    return 0;
}