#include <iostream>
#define N 210


int stk[N], size, t;
int len[N], length;

int main(){
    int m, d;
    scanf("%d%d", &m, &d);

    while(m--){
        char op[2];
        long x;
        scanf("%s %ld", op, &x);
        if (op[0] == 'A'){
            x = (x + t) % d;
            while(size && stk[size] <= x){
                size--;
            }
            stk[++size] = x;
            len[size] = ++length;
            //单调递减栈
        }
        else{

            int l = 1, r = size, mid = (l + r) / 2;

            while(l < r){
                mid = (l + r) / 2;
                if (len[mid] >= length - x + 1)
                    r = mid;
                else l = mid + 1;
            }
            printf("%d\n", stk[l]);
            t = stk[l];
        }
    }
    return 0;
}