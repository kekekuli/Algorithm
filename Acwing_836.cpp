#include <iostream>
#include <stdio.h>
#define N 100010

int p[N];
void merge(int a, int b);
int query(int a);
int queryPLUS(int a);
int queryAns(int a, int b){
    return queryPLUS(a) == queryPLUS(b);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--) {
        //一如既往的OJ网站和个人电脑的输入冲突
        //setbuf(stdin, NULL);
        char op;
        int a, b;
        std::cin >> op >> a >> b;
        if (op == 'M')
            merge(a, b);
        else {
            if (queryAns(a, b) == 1)
                printf ("Yes\n");
            else printf ("No\n");
        }
    }

    return 0;
}

void merge(int a, int b){
    a = queryPLUS(a);
    b = queryPLUS(b);

    p[a] = b;
}
int query(int a){
    while (p[a] != a) a = p[a];
    return a;
}
int queryPLUS(int a){
    if (p[a] == a)
        return a;
    p[a] = queryPLUS(p[a]);

    return p[a];
}
