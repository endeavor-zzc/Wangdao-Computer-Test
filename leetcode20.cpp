//
// Created by endeavor on 2023/8/2.
//
/**
 * 有效的括号
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 每个右括号都有一个对应的相同类型的左括号。
 * 输入：s = "()"
 * 输出：true
 */
#include<iostream>
#include<stack>
using namespace std;
class Solution{
public:
    static bool isValid(string s){
        stack<char>str;
        for (char & i : s) {
            if (i == '(' || i == '[' || i == '{'){
                str.push(i);
            } else if(i == ')'){
                if (str.empty())
                    return false;
                else if (str.top() == '('){
                    str.pop();
                } else{
                    return false;
                }
            } else if (i == ']'){
                if (str.empty())
                    return false;
                else if (str.top() == '['){
                    str.pop();
                } else{
                    return false;
                }
            } else{
                if (str.empty())
                    return false;
                else if (str.top() == '{'){
                    str.pop();
                } else{
                    return false;
                }
            }
        }
        if (str.empty()){
            return true;
        } else{
            return false;
        }
    }
};
int main(){
    string s = "{()[()]}";
    bool result = Solution::isValid(s);
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}
