#include<iostream>
#define N 1001
struct node{
    int left;
    int right;
    int sum;

    node() : left(), right(), sum(){}
    node(int l, int r, int s): left(l), right(r), sum(s){}

    bool operator < (node& n2){
        return this -> sum < n2.sum;
    }
    bool operator > (node& n2){
        return !(*this < n2);
    }
};

int A[N];

 node FMCS(int q[], int l, int r){
    int left_sum = 0, max_left = -1;
    int right_sum = 0, max_right = -1;
    int mid = l + r >> 1;
    int sum = 0;
    
    for(int i = mid; i >= l; i--){
        sum += q[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(int j = mid + 1; j <= r ; j++){
        sum += q[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    sum = 0;
    node res;
    if(max_left != -1){
        sum += left_sum;
        res.left = max_left;
    }
    if(max_right != -1){
        sum += right_sum;
        res.right = max_right;
    }
    res.sum = sum;
    return res;
 }
 node FMS(int q[], int l, int r){
    if(l >= r)
       return node(l, r, q[l]);
    int mid = l + r >> 1;
    node left = FMS(q, l, mid);
    node right = FMS(q, mid + 1, r);
    node cross = FMCS(q, l ,r);
    node res(0, 0, INT_MIN);
    
    if(left > res) res = left;
    if(right > res) res = right;
    if(cross > res) res = cross;

    return res;
 }

 int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", A + i);
    node ans = FMS(A, 0, n - 1);
    for(int i = ans.left; i <= ans.right; i++)
        printf("%d ", A[i]);
    printf("\nsum = %d\n", ans.sum); 
    return 0;
 }
