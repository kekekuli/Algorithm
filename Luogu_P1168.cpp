#include <iostream>
#define N 50010
int h1[N], h2[N], size1, size2;

//栈会爆空间， 接着用小根大根堆试试

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
//h1是大根堆
void down1(int x){
    int t = x;
    if (2 * x <= size1 && h1[2 * x] > h1[t]) t = 2 * x;
    if (2 * x + 1 <= size1 && h1[2 * x + 1] > h1[t]) t = 2 * x + 1;
    if (t != x){
        swap(h1[x], h1[t]);
        down1(t);
    }
}
void up1(int x){
    if (x / 2 >= 1 && h1[x / 2] < h1[x]){
        swap(h1[x], h1[x / 2]);
        up1(x / 2);
    }
}
//h2是小根堆
void down2(int x){
    int t = x;
    if (2 * x <= size2 && h2[2 * x] < h2[t]) t = 2 * x;
    if (2 * x + 1 <= size2 && h2[2 * x + 1] < h2[t]) t = 2 * x + 1;
    if (t != x){
        swap(h2[x], h2[t]);
        down2(t);
    }
}
void up2(int x){
    if (x / 2 >= 1 && h2[x / 2] > h2[x]){
        swap(h2[x], h2[x / 2]);
        up2(x / 2);
    }
}
int main(){
    int n, ans = 0, x;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        //把上一次答案入堆
        if (i % 2 && ans){
            h2[++size2] = ans;
            up2(size2);
        }
        else if (ans){
            h1[++size1] = ans;
            up1(size1);
        }

        ans = x;
        //尝试把新元素压入堆
        if(size1 && h1[1] > x){
            h1[++size1] = x;
            up1(size1);

            ans = h1[1];
            
            swap(h1[1], h1[size1]);
            size1--;
            down1(1);
        }
        else if (h2[1] && h2[1] < x){
            h2[++size2] = x;
            up2(size2);

            ans = h2[1];

            swap(h2[1], h2[size2]);
            size2--;
            down2(1);
        }
        if (i % 2)
            printf("%d\n", ans);
    }

    return 0;
}