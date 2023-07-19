//
// Created by endeavor on 2023/7/19.
//
/*
 * 设N是一个4位数，它的9倍恰好是气反序数(如1234的反序数是4321),求N的值。
 * 输出：输出题目要求的4位数，如果结果有多组，那么每组结果之间以回车隔开。
 */
#include <iostream>
using namespace std;
int Rev(int n){
    int rev = 0;
    while (n != 0){
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }
    return rev;
}
int main(){
    for (int N = 1000; N <= 9999; ++N) {
        if (N * 9 == Rev(N)){
            cout << N << endl;
        }
    }
    return 0;
}