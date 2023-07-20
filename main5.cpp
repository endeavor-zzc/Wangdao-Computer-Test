//
// Created by endeavor on 2023/7/20.
//
/*
 * 输入一系列整数，将其中最大的数挑出(有多个最大数时，挑出一个即可)，并对剩下的数排序，如果无剩下的数，那么输出-1
 * 输入：
 * 输入第一行包括1个整数N，1<=N<=1000，代表输入数据的个数。
 * 接下来的一行有N个整数。
 * 输出：
 * 可能有多组测试数据，对于每组数据，
 * 第一行输出一个整数，代表N个整数中的最大值，并将此值从数组中去除，将剩下的数进行排序。
 * 第二行将排序的结果输出。
 * 样例输入：
 * 4
 * 1 3 4 2
 * 样例输出：
 * 4
 * 1 2 3
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100;
int array[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    sort(array, array + n);
    if (n == 1){
        cout << array[0] << endl;
        cout << -1 << endl;
    } else{
        cout << array[n-1] << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << array[i] << ' ';
        }
    }
}

