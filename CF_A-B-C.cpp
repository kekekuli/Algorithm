#include <iostream>
using namespace std;
#define N 200010
int arr[N];

void swap(int &a, int& b){
    int t = a;
    a = b;
    b = t;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        for (int i = n, j = n - 1; j > 0; i -= 2, j -= 2)
            if (arr[j] > arr[i])
                swap(arr[j], arr[i]);
        bool flag = true;
        for (int i = 2; i <= n; i++){
            if (arr[i] < arr[i  - 1]){
                flag = false;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
