#include <iostream>
#include <vector>
using namespace std;
#define N 2010
int arr[N], temp[N], ans[N];
int solve(int a0[], int len1, int a1[], int x){
    int i = 0, j = 0;
    for ( i = 0; i < len1; i++){
        if (a0[i] == x)
            break;                                                                                                                   
    }
    if (i == len1 - 1){
        for (int i = 0; i < len1; i ++)
            a1[i] = a0[i];
        return 0;
    }
    for (int k = i + 1; k < len1; k++)
        a1[j++] = a0[k];
    for (int k = 0; k < i; k++)
        a1[j++] = a0[k];
    return i + 1;
}
int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for (int i = n; i > 0; i--){
            ans[i] = solve(arr, i, temp, i);
            for (int j = 0; j < i - 1; j++)
                arr[j] = temp[j];
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
