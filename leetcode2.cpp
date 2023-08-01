//
// Created by endeavor on 2023/8/1.
//
/**
* 两数相加
 * 给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 输入：
 * l1 = [2,4,3], l2 = [5,6,4]
 * 输出：
 * [7,0,8]
 * 解释：342 + 465 = 807.
*/
#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;//l1长度
        int len2 = 1;//l2长度
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != nullptr){
            len1++;
            p = p->next;
        }
        while (q->next != nullptr){
            len2++;
            q = q->next;
        }
        /**
         * 开始补齐
         */
        if(len1 > len2){ // l1大于l2
            for (int i = 1; i <= len1 - len2; ++i) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else{
            for (int i = 1; i <= len2 - len1; ++i) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        p = l1;
        q = l2;
        bool count = false;
        auto *l3 = new ListNode(0);
        ListNode *w = l3;
        int i = 0;
        while (p != nullptr && q != nullptr){
            i = count + p->val + q->val;
            w->next = new ListNode(i % 10);
            count = i >= 10;
            w = w->next;
            p = p->next;
            q = q->next;
        }
        if (count){
            w->next = new ListNode(1);
        }
        return l3->next;
    }
};
ListNode* CreateList(const int arr[], int n){
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int i = 0; i < n; ++i) {
        auto *newNode = new ListNode(arr[i]);
        if (!head){
            head = newNode;
            tail = newNode;
        } else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void PrintList(ListNode* head){
    ListNode* p = head;
    while (p){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
int main(){
    int arr1[] = {2,4,3};
    int arr2[] = {5,6,4};
    //通过统计字节数，来计算数组长度
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* l1 = CreateList(arr1, n1);
    ListNode* l2 = CreateList(arr2, n2);
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);
    PrintList(result);
    return 0;
}

