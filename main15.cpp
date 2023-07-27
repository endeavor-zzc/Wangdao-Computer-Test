//
// Created by endeavor on 2023/7/27.
//
/**堆栈的使用
 * 输入描述：
 * 对于每组测试数据，第一行是一个正整数 n（0 < n <= 10000）
 * 而后的 n 行，每行的第一个字符可能是'P'或者'O'或者'A'
 * 如果是'P'，后面还会跟着一个整数，表示把这个数据压入堆栈
 * 如果是'O'，表示将栈顶的值 pop 出来
 * 如果堆栈中没有元素时，忽略本次操作；如果是'A'，表示询问当前栈顶的值
 * 如果当时栈为空，则输出'E'。堆栈开始为空
 * 输出描述：
 * 对于每组测试数据，根据其中的命令字符来处理堆栈；并对所有的'A'操作，输出当时栈顶的值，每个占据一行
 * 如果当时栈为空，则输出'E'。
 * 示例1
 * 输入：
 * 3
 * A
 * P 5
 * A
 * 4
 * P 3
 * P 6
 * O
 * A
 * 输出：
 * E
 * 5
 * 3
 *
 */
#include<iostream>
#include<stack>
using namespace std;
const int N = 10000;
int main(){
    int n;
    string data;
    string flag;
    while(cin >> n){
        stack<string> stack;
        for (int i = 0; i < n; ++i) {
            cin >> flag;
            if (flag == "P"){
                cin >> data;
                stack.push(data);
            } else if (flag == "O"){
                if (!stack.empty()){
                    stack.pop();
                }
            } else if (flag == "A"){
                if (stack.empty()){
                    cout << 'E' << endl;
                }else {
                    cout << stack.top() << endl;
                }
            } else{
                stack.push(flag);
            }
        }
    }
}