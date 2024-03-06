#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 20
#define LL long long
using namespace std;

int feb[N], t;

int dfs(int n){
    if (feb[n] != -1)
        return feb[n];
    int a = dfs(n - 1), b = dfs(n - 2);
    feb[n] = a + b;
    return feb[n];
}

int main(){
    memset(feb, -1, sizeof(feb));
    feb[1] = 0, feb[2] = 1;
    scanf("%d", &t);
    dfs(t);
    for (int i = 1; i <= t; i++)
        printf("%d ", feb[i]);
    printf("\n");
    return 0;
}