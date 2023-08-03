//
// Created by endeavor on 2023/8/1.
//
/**
* 无重复字符的最长子串
 * 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
class Solution{
public:
    static int lengthOfLongestSubstring(string s) {
        vector<int>m(128, 0);
        int p = 0;//左指针
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            p = max(p, m[s[i]]);
            m[s[i]] = i + 1; //每次m[s[i]]存储的都是下一个字符的位置，这样遇到相同字符时左指针直接移到相同字符的下一个位置。
            result = max(result, i - p + 1);
        }
        return result;
    }
};
int main(){
    string s = "abcabcbb";
    int res = Solution::lengthOfLongestSubstring(s);
    cout << res << endl;
}