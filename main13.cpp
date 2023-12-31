//
// Created by endeavor on 2023/7/27.
//
/**括号匹配问题
* 在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；
 * 规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。
 * 写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。
 * 不能匹配的左括号用"$“标注,不能匹配的右括号用”?"标注.
 * 输入格式
 * 输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100。
 *
 * 输出格式
 * 对每组输出数据，输出两行。
 * 第一行包含原始输入字符，第二行由"$","?"和空格组成，"$“和”?"表示与之对应的左括号和右括号不能匹配。
 *
 * 输入样例
 * )(rttyy())sss)(
 *
 * 输出样例
 * )(rttyy())sss)(
 * ?            ?$
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string str;
    cin >> str;
    stack<int> brackets;
    string answer(str.size(), ' ');
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '('){
            brackets.push(i);
        } else if (str[i] == ')'){
            if (!brackets.empty()){
                brackets.pop();
            } else{
                answer[i] = '?';
            }
        }
    }
    while (!brackets.empty()){
        answer[brackets.top()] = '$';
        brackets.pop();
    }
    cout << str << endl;
    cout << answer << endl;
    return 0;
}