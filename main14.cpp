//
// Created by endeavor on 2023/7/27.
//
/**
* 描述
 * 读入一个只包含 +, -, *, / 的非负整数计算表达式，计算该表达式的值。
 * 输入描述：
 * 测试输入包含若干测试用例，每个测试用例占一行，每行不超过200个字符，整数和运算符之间用一个空格分隔。没有非法表达式。
 * 当一行中只有0时输入结束，相应的结果不要输出。
 * 输出描述：
 * 对每个测试用例输出1行，即该表达式的值，精确到小数点后2位。
 * 输入：
 * 1 + 2
 * 4 + 2 * 5 - 7 / 11
 * 0
 * 输出：
 * 3.00
 * 13.36
*/
#include<iostream>
#include<stack>
#include<string>
#include<cctype>
#include<cstdio>
using namespace std;
int Priority(char c){
    if (c == '#'){
        return 0;
    } else if (c == '$'){
        return 1;
    } else if (c == '+' || c == '-'){
        return 2;
    } else
        return 3;
}

double GetNumber(string str, int &index){
    double number = 0;
    while (isdigit(str[index])){
        number = number * 10 + str[index] - '0';
        index++;
    }
    return number;
}

double Calculate(double x, double y, char op){
    double result = 0;
    if (op == '+'){
        result = x + y;
    } else if (op == '-'){
        result = x - y;
    } else if (op == '*'){
        result = x * y;
    } else{
        result = x / y;
    }
    return result;
}

int main(){
    string str;
    while (getline(cin, str)){
        if (str == "0"){
            break;
        }
        int index = 0;
        stack<char> op;
        stack<double> data;
        str += '$';
        op.push('#');
        while (index < str.size()){
            if (str[index] == ' '){
                index++;
            } else if (isdigit(str[index])){
                data.push(GetNumber(str, index));
            } else{
                if (Priority(op.top()) < Priority(str[index])){
                    op.push(str[index]);
                    index++;
                } else{
                    double y = data.top();
                    data.pop();
                    double x = data.top();
                    data.pop();
                    data.push(Calculate(x, y, op.top()));
                    op.pop();
                }
            }
        }
        printf("%.2f\n", data.top());
    }
    return 0;
}