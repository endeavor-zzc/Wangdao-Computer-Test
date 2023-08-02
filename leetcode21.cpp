//
// Created by endeavor on 2023/8/2.
//
/**
* 合并两个有序链表
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
*/
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution{
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode* list3 = new ListNode(0);
        ListNode* p = list3;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                p->next = list1;
                list1 = list1->next;
            } else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        p->next = list1 ? list1 : list2;
        return list3->next;
    }
};
ListNode* CreateList(int arr[], int n){
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int i = 0; i < n; ++i) {
        auto* newNode = new ListNode(arr[i]);
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
    int arr1[] = {2,3,4};
    int arr2[] = {3,5,8};
    //通过统计字节数，来计算数组长度
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    ListNode* l1 = CreateList(arr1, n1);
    ListNode* l2 = CreateList(arr2, n2);
    ListNode* result = Solution::mergeTwoLists(l1, l2);
    PrintList(result);
    return 0;
}