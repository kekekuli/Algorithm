#include <iostream>
#define N 100010
using namespace std;
int s[N];
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int min(int a, int b){
    return a < b ? a : b;
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, m, x, y;
        long long res = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            s[i] = n;
        for (int i = 0; i < m; i++){
            scanf("%d%d", &x, &y);
            if (x > y)
                swap(x, y);
            s[x] = min(s[x], y - 1);           
        }
        for (int i = n; i >= 1; i--){
            if (s[i] < s[i - 1])
                s[i - 1] = s[i]; 
            res += s[i] - i + 1; 
        }
        cout << res << endl;
    }
    return 0;
}