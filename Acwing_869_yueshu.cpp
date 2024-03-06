#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void get_appr(int n){
    vector<int> apprs;
    for (int i = 1; i <= n / i; i++){
        if (n % i == 0){
            apprs.push_back(i);
            if (i != n / i)
                apprs.push_back(n/i);
        }
    }
    sort(apprs.begin(), apprs.end());
    for (int i = 0; i < apprs.size(); i++)    
        printf("%d ", apprs[i]);
    printf("\n");
}

int main(){
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        get_appr(a);
    }
    return 0;
}