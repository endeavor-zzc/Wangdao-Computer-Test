//
// Created by endeavor on 2023/8/1.
//
/**
* 两数之和
 * 给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
 * 你可以按任意顺序返回答案。
 * 输入：
 * nums = [2,7,11,15], target = 9
 * 输出：
 * [0,1]
 * 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int>has;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (has.find(target - nums[i]) != has.end()){ //如果target - nums[i]在哈希表里
                return {has[target - nums[i]], i}; //找到符合的
            } else{
                has[nums[i]] = i; //没有找到则加入哈希表中
            }
        }
        return {};
    }
};
int main(){
    Solution solution;
    vector<int> nums = {2,7,9,11};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    if (result.size()){
        cout << result[0] << "," << result[1] << endl;
    } else{
        cout << "error" << endl;
    }
    return 0;
}