//You are given the heads of two sorted linked lists list1 and list2.
//
//Merge the two lists into one sorted list.
//The list should be made by splicing together the nodes of the first two lists.
//
//Return the head of the merged linked list.
//
//Input: list1 = [1, 2, 4], list2 = [1, 3, 4]
//Output : [1, 1, 2, 3, 4, 4]
//
//Input : list1 = [], list2 = [0]
//Output : [0]
//
//Constraints :
//
//    The number of nodes in both lists is in the range[0, 50].
//    - 100 <= Node.val <= 100
//    Both list1 and list2 are sorted in non - decreasing order.

#include <iostream>
using namespace std;


 struct ListNode 
 {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {

                tail->next = list1;
                list1 = list1->next;
            }
            else
            {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if (list1 != nullptr) tail->next = list1;
        else tail->next = list2;

        return dummy->next;
    }
};

