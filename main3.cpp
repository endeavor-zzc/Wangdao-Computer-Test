//
// Created by endeavor on 2023/7/19.
//
/*
 * 题目描述：对输入的n个数进行排序并输出。
 * 输入：输入的第一行包括一个整数n(1<=n<=100)。接下来的一行包括n个整数。
 * 样例输入：
 * 4
 * 1 4 3 2
 * 样例输出：
 * 1 2 3 4
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100;
int array[MAX];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin  >> array[i];
    }
    sort(array, array + n);
    for (int i = 0; i < n; ++i) {
        cout << array[i] << ' ';
    }
    return 0;
}