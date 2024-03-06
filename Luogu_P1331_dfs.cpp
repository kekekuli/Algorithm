#include <iostream>
#define MAX 1010
char map[MAX][MAX];
bool marked[MAX][MAX];
int r, c;
int count = 0;

bool check(int x,int y)
{
    int cnt=0;
    if(map[x][y]=='#')
        cnt++;
    if(map[x+1][y]=='#')
        cnt++;
    if(map[x][y+1]=='#')
        cnt++;
    if(map[x+1][y+1]=='#')
        cnt++;
    return cnt==3;
}

void dfs(int i, int j){
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, 1, 0, -1};

    for (int d = 0; d < 4; d++){
        int ii = i + di[d];
        int jj = j + dj[d];

        // can not out of boundary
        if (ii >= 1 && ii <= r && jj >= 1 && jj <= c){
            // here (ii, jj) is a part of a ship and not was visited
            if (map[ii][jj] == '#' && !marked[ii][jj]){
                // mark that is marked
                marked[ii][jj] = true;
                
                dfs(ii, jj);
            } 
        }
    }
}
int main(){
    scanf("%d%d", &r, &c);
    for (int i = 1; i <= r; i++){
        scanf("%s", &map[i][1]);
    }
    for (int i = 1; i < r; i++){
        for (int j = 1; j < c; j++){
            if (check(i, j)){
                printf("Bad placement.");
                return 0;
            }
        }
    }
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (map[i][j] == '#' && !marked[i][j]){
                dfs(i, j);
                count++;
            }
        }
    }
    

    printf("There are %d ships.\n", count);
    return 0;
}