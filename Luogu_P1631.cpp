#include <iostream>
#include <climits>
#define N 100010
//MLE一个点，优化思路是维护一个大根堆保存小根堆中的最大值
int h[3000], size;
void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void down(int k){
    int t = k;
    if (k * 2 <= size && h[k * 2] < h[t]) t = k * 2;
    if (k * 2 + 1 <= size && h[k * 2 + 1] < h[t]) t = k * 2 + 1;
    if (t != k){
        swap(h[t], h[k]);
        down(t);
    }
}
void up(int k){
    if (k / 2 >= 1 && h[k / 2] > h[k]){
        swap(h[k / 2], h[k]);
        up(k / 2);
    }
}
int query(){
    if (size > 0)
        return h[1];
    return INT_MAX;
}
void insert(int x){
    h[++size] = x;
    up(size);
}
void deleTop(){
    if (size > 0){
        swap(h[1], h[size]);
        size--;
        down(1);
    }
}

int main(){
    int n, a[N], b[N], flag;
    scanf("%d", &n);
    flag = n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int j = 0; j < n; j++)
        scanf("%d", &b[j]);
    while(flag){
        for (int i = 0; i < n; i++){
            int x = a[i] + b[0];
            while(flag && query() <= x){
                printf("%d ", query());
                deleTop();
                flag--;
            }
            insert(x);
            for (int j = 1; j < n && flag; j++){
                x = a[i] + b[j];
                insert(x);
            }
            
        }
        
    }

    return 0;
}