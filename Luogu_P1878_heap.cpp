#include <iostream>
#include <climits>
#include <string.h>
#include <algorithm>
#define N 200010
bool visited[N];
int array[N];
int heap[N], left[N], right[N], size;
char str[N];

typedef struct{
    int value;
    int l;
    int r;

} ans;
ans result[N];
bool compare(ans a, ans b){
    if (a.value < b.value){
        return true;
    }    
    else if (a.value > b.value){
        return false;
    }
    else{
        if (a.l <= b.l)
            return true;
        else   
            return false;
    }
}

bool empty(){
    return size == 0;
}
bool check(int id){
    if (empty())
        return true;
    if (str[left[id]] == str[right[id]] ||
        visited[left[id]] || visited[right[id]])
            return false;
    return true;
}
void swap_heap(int id_x, int id_y){
    int h = heap[id_x], l = left[id_x], r = right[id_x];

    heap[id_x]=heap[id_y];
    left[id_x]=left[id_y];
    right[id_x]=right[id_y];

    heap[id_y]=h;
    left[id_y]=l;
    right[id_y]=r;
}
void down(int id){
    int t = id;
    if (id * 2 <= size && heap[t] >= heap[id * 2])
        t = id * 2;
    if (id * 2 + 1 <= size && heap[t] >= heap[id * 2 + 1])
        t = id * 2 + 1;
    if (t != id){
        swap_heap(t, id);
        down(t);
    }
}
void up(int id){
    if (id / 2 >=1 && heap[id] <= heap[id / 2]){
        swap_heap(id, id / 2);
        up(id / 2);
    }

}
void pop(){
    if (empty())
        return;

    swap_heap(1, size);
    size--;
    down(1);
}


int query(){
    return empty() ? 0 : 1;
}
void insert(int l, int r){
    heap[++size] = abs(array[l] - array[r]);
    left[size] = l;
    right[size] = r;

    up(size);
}

int main(){
    int n;
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++){
        scanf("%d", &array[i]);
    }
    for (int i = 1; i < n; i++){
        insert(i, i + 1);
    }

    int count = 0;
    

    while(!empty()){
        while(!check(1)){
            pop();
        }
        if (empty())
            continue;
        // update result and heap
        int id = query();
        result[++count] = {heap[id], left[id], right[id]};
        visited[left[id]] = true;
        visited[right[id]] = true;
        // new pair
        int l = left[id] - 1;
        int r = right[id] + 1;
        while(l >= 1 && visited[l])
            l--;
        while(r <= n && visited[r])
            r++;
        if (l >= 1 && r <= n){
            insert(l, r);
        }
    }

    std::sort(&result[0], &result[count + 1], compare);
    printf("%d\n", count);
    for (int i = 1; i <= count; i++){
        printf("%d %d\n", result[i].l, result[i].r);
    }

    return 0;
}