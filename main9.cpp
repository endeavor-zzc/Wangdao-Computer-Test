//
// Created by endeavor on 2023/7/20.
//
/**
* 描述
* 第一行输入一个数n，1 <= n <= 1000，下面输入n行数据，每一行有两个数，分别是x y。输出一组x y，
* 该组数据是所有数据中x最小，且在x相等的情况下y最小的。
* 输入描述：
* 输入有多组数据。 每组输入n，然后输入n个整数对。
* 输出描述：
* 输出最小的整数对。
* 输入：
* 5
* 3 3
* 2 2
* 5 5
* 2 1
* 3 6
* 输出：
* 2 1
*/
#include<iostream>
using namespace std;
const int N = 1010;
int arr[N][2];
int main(){
    int n;
    int flag = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 0; i < n; ++i) {
        if((arr[flag][0] > arr[i][0]) || (arr[flag][0] == arr[i][0]) && (arr[flag][1] > arr[i][1]))
            flag = i;
    }
    cout << arr[flag][0] << ' ' << arr[flag][1];
}