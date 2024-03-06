#include <iostream>
#define N 110
bool map[N][N];
int m, n, k, now;
char s;
char dr[] = {'U', 'R', 'D', 'L'};
void solu(int x, int y, int r){
    if (now == k){
        printf("%d %d\n", x, y);
        return;
    }

    int dx = x, dy = y, ddr = r;

    if (map[x][y] == 1)
        ddr = (r + 1 + 4) % 4;
    else
        ddr = (r - 1 + 4) % 4;

    map[x][y] = !map[x][y];
    
    if (dr[ddr] == 'U')
            dx -= 1;
    if (dr[ddr] == 'R')
            dy += 1;
    if (dr[ddr] == 'D')
            dx += 1;
    if (dr[ddr] == 'L')
            dy -= 1;
    now ++;
    printf("\n");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++)
            std::cout << map[i][j] << " ";
        printf("\n");
    }

    solu(dx, dy, ddr);
}

int main(){
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            std::cin>>map[i][j];
    int x, y;
    char r;
    scanf("%d %d %c %d", &x, &y, &r, &k);
    if (r == 'U')
        r = 0;
    if (r == 'R')
        r = 1;
    if (r == 'D')
        r = 2;
    if (r == 'L')
        r = 3;
    solu(x, y, r);
    return 0;
}