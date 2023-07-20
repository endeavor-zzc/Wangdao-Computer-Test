//
// Created by endeavor on 2023/7/20.
//
/*
 * 题目描述：用一维数组存储学号和成绩，然后按成绩排序输出
 * 输入：
 * 输入的第一行中包括一个整数N（1<=N<=100),它代表学生的个数
 * 接下来的N行中，每行包括两个整数p和q，分别代表每个学生的学号和成绩。
 * 输出：
 * 按照学生的成绩从小到大进行排序，并将排许后的学生信息打印出来。
 * 如果学生的成绩相同，那么按照学号的大小从小到大排序。
 * 样例输入：
 * 3
 * 1 90
 * 2 87
 * 3 92
 * 样例输出：
 * 2 87
 * 1 90
 * 3 92
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
typedef struct Student{
    int ID;
    int score;
}Stu;
Stu array[N];
bool cmp(Stu x, Stu y){
    if (x.score == y.score){
        return x.ID < y.ID;
    } else{
        return x.score < y.score;
    }
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> array[i].ID >> array[i].score;
    }
    sort(array, array+ n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << array[i].ID << ' ' << array[i].score << endl;
    }
}


