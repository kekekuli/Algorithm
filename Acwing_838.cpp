#include <stdio.h>
#define N 100010

int h[N], size;


void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
//下沉下标为x的值
void down(int x){
    int t = x;
    if (x * 2 <= size && h[x * 2] < h[t]) t = 2 * x;
    if (x * 2 + 1 <= size && h[x * 2 + 1] < h[t]) t = 2 * x + 1;
    if (t != x){
        swap(h[x], h[t]);
        down(t);
    }
}
//上浮下标为x的值
void up(int x){
    if (x / 2 >= 1 && h[x / 2] > h[x]){
        swap(h[x], h[x / 2]);
        up(x / 2);
    }

}
//返回并删除堆顶元素
int pop(){
    if (size == 0)
        return 0;

    int ans = h[1];
    swap(h[1], h[size]);
    size--;
    down(1);
    return ans;
}
//返回堆顶元素
int query(){
    if (size == 0)
        return 0;
    return h[1];
}
//插入一个元素
void push(int x){
    h[++size] = x;
    up(size);
}
//改变一个数的值
void change(int x, int num){
    if (x <= size)
        h[x] = num;
    down(x);
    up(x);
}
//删除一个元素
void dele(int x){
    if (x > size)
        return;
    swap(h[x], h[size]);
    size--;
    down(x);
    up(x);
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    size = n;
    for (int i = 1; i <= n; i++)
        scanf("%d", h + i);
    for (int i = n / 2; i; i--) down(i);
    while (k--){
        printf("%d ", h[1]);
        h[1] = h[size];
        size--;
        down(1);
    }
    return 0;
}
