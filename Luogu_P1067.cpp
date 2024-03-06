#include <iostream>
//模拟题
//特判很多，代码很丑
int main(){
    int n, x;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++){
        scanf("%d", &x);
        if (x == 0)
            continue;
        else if (i == 0){
            if (x == 1){
                printf("x^%d", n - i);
            }
            else if (x == -1){
                printf("-x^%d", n - i);
            }
            else{
                printf("%dx^%d", x, n - i);
            }
        }
        else if (i == n - 1){
            if (x == 1){
                printf("+x");
            }
            else if (x == -1){
                printf("-x");
            }
            else if (x > 1){
                printf("+%dx", x);
            }
            else if (x < -1){
                printf("%dx", x);
            }
        }
        else if (i == n){
            if (x == 1){
                printf("+1");
            }
            else if (x == -1){
                printf("-1");
            }
            else if (x > 1){
                printf("+%d", x);
            }
            else if (x < -1){
                printf("%d", x);
            }
        }
        else {
            if (x == 1){
                printf("+x^%d", n - i);
            }
            else if (x == -1){
                printf("-x^%d", n - i);
            }
            else if (x > 1){
                printf("+%dx^%d", x, n - i);
            }
            else if (x < -1){
                printf("%dx^%d", x, n - i);
            }
        }
    }
    return 0;
}