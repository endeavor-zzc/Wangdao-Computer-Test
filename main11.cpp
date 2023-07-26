//
// Created by endeavor on 2023/7/26.
//
/**
* 完数VS盈数
 * 描述
 * 一个数如果恰好等于它的各因子(该数本身除外)子和，如：6=3+2+1。则称其为“完数”；若因子之和大于该数，则称其为“盈数”。
 * 求出2到60之间所有“完数”和“盈数”。
 * 输入描述：
 * 题目没有任何输入。
 * 输出描述：
 * 输出2到60之间所有“完数”和“盈数”，并以如下形式输出：
 * E: e1 e2 e3 ......(ei为完数)
 * G: g1 g2 g3 ......(gi为盈数)
 * 其中两个数之间要有空格，行尾不加空格。
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> numberE; // 完数
vector<int> numberG; // 盈数

int Sum(int x){
    int sum = 0;
    for (int i = 1; i < x; ++i) {
        if(x % i == 0){
            sum += i;
        }
    }
    return sum;
}
int main(){
    for (int i = 2; i <= 60; ++i) {
        if (i == Sum(i)){
            numberE.push_back(i);
        } else if (i < Sum(i)){
            numberG.push_back(i);
        }
    }
    cout << "E:";
    //输出完数
    for (int i : numberE) {
        cout << ' ' << i;
    }
    cout << endl;
    cout << "G:";
    for (int i : numberG) {
        cout << ' ' << i;
    }
    cout << endl;
    return 0;
}


