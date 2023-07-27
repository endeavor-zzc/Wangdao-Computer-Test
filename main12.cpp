//
// Created by endeavor on 2023/7/26.
//
/**约瑟夫问题
 * 题目描述：
 * n 个小孩围坐成一圈，并按顺时针编号为1,2,…,n，从编号为 p 的小孩顺时针依次报数，由1报到m
 * 当报到 m 时，该小孩从圈中出去，然后下一个再从1报数，当报到 m 时再出去。如此反复，直至所有的小孩都从圈中出去。
 * 请按出去的先后顺序输出小孩的编号。
 * 输入：
 * 每行是用空格分开的三个整数，第一个是n,第二个是p,第三个是m (0 < m,n < 300)。最后一行是:
 * 0 0 0
 * 输出：
 * 按出圈的顺序输出编号，编号之间以逗号间隔。
 * 样例输入：
 * 8 3 4
 * 0 0 0
 * 样例输出：
 * 6,2,7,4,3,5,1,8
 */
#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int main(){
    int n, p, m;
    while (cin >> n >> p >> m){
        if (n == 0 && p == 0 & m ==0){
            break;
        }
        queue<int> children;
        for (int i = 1; i <= n; ++i) {
            children.push(i);
        }
        for (int i = 1; i < p; ++i) { //使编号为p的在队首
            children.push(children.front());
            children.pop();
        }
        while (!children.empty()){
            for (int i = 1; i < m; ++i) {
                children.push(children.front());
                children.pop();
            }
            cout << children.front() << ' ';
            children.pop();
        }
    }
    return 0;
}
