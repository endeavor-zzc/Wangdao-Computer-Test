//
// Created by endeavor on 2023/7/20.
//
/*
 * 描述
 * 输入数组长度n输入数组a[1...n] 输入查找个数m输入查找数字b[1...m]   输出 YES or NO  查找有则YES 否则NO。
 * 输入描述：
 * 输入有多组数据。 每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1<=m,n<=100）。
 * 输出描述：
 * 如果在n个数组中输出YES否则输出NO。
 * 输入：
 * 5
 * 1 5 2 4 3
 * 3
 * 2 5 6
 * 输出：
 * YES
 * YES
 * NO
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int MAX = 100;
int arr[MAX];
int b[MAX];
/**
 * 二分查找
 * @param n 数组长度
 * @param target 目标
 * @return
 */
bool BinarySearch(int n, int target){
    int left = 0;
    int right = n - 1;
    while (left <= right){
//        int middle = (left + right) / 2;
          int middle = left + (right -  left) / 2;
        if (arr[middle] < target){
            left = middle + 1;
        } else if (target < arr[middle]){
            right = middle - 1;
        } else{
            return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        if (BinarySearch(n, b[i])){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}