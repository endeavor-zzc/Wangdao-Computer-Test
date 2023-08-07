//
// Created by endeavor on 2023/8/7.
//
/**
* 二叉树的最大深度
 * 给定一个二叉树 root ，返回其最大深度。
 * 二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：3
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define null INT16_MIN
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
    int maxDepth(TreeNode *root){
        if (root == nullptr)
            return 0;
        else
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
TreeNode* createTree(const vector<int>& arr){
    if (arr.empty())
        return nullptr;
    auto *root = new TreeNode(arr.front());
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()){
        TreeNode* cur = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != null){
            cur->left = new TreeNode(arr[i]);
            q.push(cur->left);
        }
        i++;
        if (i < arr.size() && arr[i] != null){
            cur->right = new TreeNode(arr[i]);
            q.push(cur->right);
        }
        i++;
    }
    return root;
}
int main(){
    vector<int> arr = {3,9,20,null,null,15,7};
    TreeNode *root = createTree(arr);
    Solution solution;
    int result = solution.maxDepth(root);
    cout << result << endl;
    return 0;
}
