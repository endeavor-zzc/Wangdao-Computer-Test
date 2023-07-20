//
// Created by endeavor on 2023/7/20.
//
/*
 * 题目描述
 * 输入10个整数，彼此以空格分隔。重新排序以后输出(也按空格分隔)，要求:
 * 1.先输出其中的奇数,并按从大到小排列；
 * 2.然后输出其中的偶数,并按从小到大排列。
 *
 * 样例输入
 * 0 56 19 81 59 48 35 90 83 75
 * 17 86 71 51 30 1 9 36 14 16
 * 样例输出
 * 83 81 75 59 35 19 0 48 56 90
 * 71 51 17 9 1 14 16 30 36 86
 */
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n = 10;
    int arr[n];
    int odd[n]; //奇数
    int even[n]; //偶数
    int o = 0,e = 0;//记录奇数偶数个数
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0){
            even[e] = arr[i];
            e++;
        } else{
            odd[o] = arr[i];
            o++;
        }
    }
    sort(odd, odd+o,greater<int>());
    sort(even, even+e);
    for (int i = 0; i < o; ++i) {
        cout << odd[i] << ' ';
    }
    for (int i = 0; i < e; ++i) {
        cout << even[i] << ' ';
    }
}