#include<iostream>
#define N 1000010
using namespace std;

int quick_sort_check(int q[], int l, int r, int k){
    if(l >= r)
        return q[l];
    int i = l - 1, j = r + 1, num = q[(l + r) / 2];
    while(i < j){
        do i++; while(q[i] < num);
        do j--; while(q[j] > num);
        if(i < j){
            int t = q[i];
            q[i] = q[j];
            q[j] = t;
        }
    }
    if(k <= j - l + 1)
        return quick_sort_check(q, l, j, k);
    else return quick_sort_check(q, j + 1, r, k - (j - l + 1));
}
int main(){
    int array[N];
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", array + i);
    printf("%d", quick_sort_check(array, 0, n - 1, k));
    return 0;
}