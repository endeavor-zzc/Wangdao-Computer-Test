//
// Created by endeavor on 2023/8/3.
//
/**
* 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
*/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
/**
 * 优化前
 */
/*class Solution{
public:
    static int climbStairs(int n){
        vector<int>dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};*/
class Solution{
public:
    static int climbStairs(int n){
        int a = 1;
        int b = 1;
        for (int i = 2; i <= n; ++i) {
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};
int main(){
    int n;
    printf("n=");
    scanf("%d", &n);
    int result = Solution::climbStairs(n);
    cout << result << endl;
    return 0;
}