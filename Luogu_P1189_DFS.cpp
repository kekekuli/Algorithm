#include <iostream>
#include <string.h>
#define N 60
//存地图
char map[N][N];
//按照题目的变量定义
int r, c, n;
//方便的将string类型的方向转换成数字,下标0, 1, 2, 3对应北、东、南、西
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
//dr存变成数字后的方向数组
int dr[1010];
bool vis[1010][N][N];

void dfs(int x, int y, int op){
    //大坑点，因为dfs的op定义是即将对第op个方向操作，所以标记数组是要减去一位的，是vis[op-1]而不是vis[op]
    if (op > n || vis[op - 1][x][y])
        return;
    
    //遍历在第op个方向上可以走的长度
    for(int i = 1; ; i++){
        //使用方向的快捷变化拿到走i步长的坐标
        int nx = x + dx[dr[op]] * i;
        int ny = y + dy[dr[op]] * i;
        //判断越界以及是否撞墙
        if (ny >= 1 && nx >= 1 && ny <= c && nx <= r && map[nx][ny] != 'X'){
            //这里可以直接对map操作，而不用再开个标记map存是否最终可以到这个点
            if (op == n)
                map[nx][ny] = '*';
            //注意大坑点，必须要先dfs再标记
            dfs(nx, ny, op + 1);
            vis[op][nx][ny] = true;
        }
        //如果不满足以上任一条件了，说明没有接着增加步长的需要了，直接break
        else break;
    }
}

int main(){

    //读入和初始化操作，没什么好说的，实验证明读入优化再好也没优化dfs核心来的快
    //-------------------------我是分割线-----------------
    int x = 0, y = 0;
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++)
        scanf("%s", map[i] + 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        char s[10];
        scanf("%s", s);
        if (s[0] == 'N')
            dr[i] = 0;
        else if (s[0] == 'E')
            dr[i] = 1;
        else if (s[0] == 'S')
            dr[i] = 2;
        else if (s[0] == 'W')
            dr[i] = 3;
    }
    //找一下初始位置在哪
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (map[i][j] == '*'){
                map[i][j] = '.';
                x = i;
                y = j;
                i = r;
                j = c;
            }
    //-------------------------我是分割线-----------------

    //从初始位置和第一个方向开始搜索
    dfs(x, y, 1);

    for (int i = 1; i <= r; i++)
        printf("%s\n", map[i] + 1);
    return 0;  
}