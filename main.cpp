/*
 * 题目描述：设a,b,c均是0-9之间的数字，abc，bcc是两个三位数，且有abc+bcc=532。
 * 求满足条件的所有a,b,c的值。
 * 输入：无输入
 * 输出：请输出所有满足题目条件的a,b,c的值。
 * a,b,c之间用空格隔开。
 * 每个输出占一行。
 */
#include <iostream>
using namespace std;
int main(){
    for (int a = 0; a < 10; ++a) {
        for (int b = 0; b < 10; ++b) {
            for (int c = 0; c < 10; ++c) {
                if (a * 100 + b * 10 + c + b * 100 + c * 11 == 532)
                    cout << a << ' ' << b << ' ' << c << endl;
            }
        }
    }
    return 0;
}
