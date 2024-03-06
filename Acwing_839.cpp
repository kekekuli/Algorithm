#include <stdio.h>
#include <string.h>
#define N 100010

int h[N], size, hp[N], ph[N];


void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
void heap_swap(int a, int b){
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);

    swap(h[a], h[b]);
}
//下沉下标为x的值
void down(int x){
    int t = x;
    if (x * 2 <= size && h[x * 2] < h[t]) t = 2 * x;
    if (x * 2 + 1 <= size && h[x * 2 + 1] < h[t]) t = 2 * x + 1;
    if (t != x){
        heap_swap(x, t);
        down(t);
    }
}
//上浮下标为x的值
void up(int x){
    if (x / 2 >= 1 && h[x / 2] > h[x]){
        heap_swap(x, x / 2);
        up(x / 2);
    }

}
//返回并删除堆顶元素
int pop(){
    if (size == 0)
        return 0;

    int ans = h[1];
    heap_swap(1, size);
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
    heap_swap(x, size);
    size--;
    down(x);
    up(x);
}
int main() {
    int n, m = 0;
    scanf("%d", &n);
    while(n--){
        char op[5];
        int k, x;
        scanf("%s", op);
        if(!strcmp(op, "I")){
            scanf("%d", &x);
            h[++size] = x;
            ph[++m] = size;
            hp[size] = m;
            up(size);
        }
        else if(!strcmp(op, "PM")){
            printf("%d\n", h[1]);
        }
        else if(!strcmp(op, "DM")){
            dele(1);
        }
        else if(!strcmp(op, "D")){
            scanf("%d", &k);
            dele(ph[k]);
        }
        else{
            scanf("%d%d", &k, &x);
            h[ph[k]] = x;
            down(ph[k]);
            up(ph[k]);
        }
    }
    return 0;
}
