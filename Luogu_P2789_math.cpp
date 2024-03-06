#include <iostream>
int arr[30];
int main(){
    for (int i = 1; i <= 25; i++)
        arr[i] = arr[i - 1] + i - 1;
    int n;
    std::cin >> n;
    std::cout << arr[n] << std::endl;
    return 0;
}