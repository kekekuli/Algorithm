//用加权并查集即可


#include <string.h>

#define N 1000003
#define TRUE 1
#define FALSE 0
// id数组必须配合值hash后的key使用,id[hash(x)]就是代表x的id值
int id[N];
// p, s, e全部用id作为索引.
// p[id] 代表id的父节点的id, s[id]代表以id节点为根的权重, e[id]代表id节点的值
int p[N], s[N], e[N], idx;
// ans代表最大权重集合的权重
int ans = 0;

// 返回x的hash值
int hash(int x){
    int k = (x % N + N) % N;
    while(id[k] != -1 && e[id[k]] != x)
        k = (k + 1) % N;
    return k;
}
// 以x为值新建一个节点
void init(int x){
    int k = hash(x);
    if (id[k] == -1){
        id[k] = idx;
        s[idx] = 1;
        e[idx] = x;
        if (ans < s[idx])
            ans = s[idx];
        idx++;
    }
}
//判断是否有值为x的节点存在
bool exist(int x){
    int k = hash(x);
    if (id[k] == -1)
        return FALSE;
    return TRUE;
}
//找到一个集合的根节点
int find_root(int x){
    int k = hash(x);
    if (p[id[k]] != -1)
        p[id[k]] = find_root(e[p[id[k]]]);
    // 为什么下面的return正确，猜的...
    return p[id[k]] == -1 ? id[k] : p[id[k]];
}
//将值x所在集合合并到y
//感觉此函数写的不太好,通用性不够
void merge(int x, int y){
    // x must smaller than y
    if (x >= y)
        return;
    
    int root_x = find_root(x);
    int root_y = find_root(y);
    if (root_x != root_y){
        p[root_x] = root_y;
        s[root_y] += s[root_x];
        // update ans
        if (ans < s[root_y])
            ans = s[root_y];
    }
}

int longestConsecutive(int* nums, int numsSize){
    // 初始化全局变量
    memset(s, 0, sizeof(s));
    memset(e, 0, sizeof(s));
    memset(p, -1, sizeof(p));
    memset(id, -1, sizeof(id));
    ans = 0;

    for (int i = 0; i < numsSize; i++){
        //如果之前访问过此值，不必管他
        if (exist(nums[i]))
            continue;
        //未访问的值需要新建一个节点保存
        init(nums[i]);
        //查看左右两个值是否已经存在，如果存在一个则合并，如果存在两个先合并小值再合并大值
        if (exist(nums[i] - 1)){
            merge(nums[i] - 1, nums[i]);
        }
        if (exist(nums[i] + 1)){
            merge(nums[i], nums[i] + 1);
        }
    }
    return ans;
}
// //测试样例
// int nums[] = {100, 4, 200, 3, 2, 1};
// int main(){
//     longestConsecutive(nums, 6);
// }