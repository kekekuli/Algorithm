#include<iostream>
#define LL long long
int qmi(int a, int k, int p){
    int res = 1;
    while(k){
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL) a * a % p;  
    }
    return res;
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