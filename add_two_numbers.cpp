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
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
      {
          if (l1 == nullptr) return l2;
          else if (l2 == nullptr) return l1;

          ListNode* dummy = new ListNode(-1);
          ListNode* tail = dummy;

          int leftover = 0;

          while (l1 != nullptr || l2 != nullptr || leftover != 0)
          {
              int val = leftover;
              if (l1 != nullptr)
              {
                  val += l1->val;
                  l1 = l1->next;
              }
              if (l2 != nullptr)
              {
                  val += l2->val;
                  l2 = l2->next;
              }

              leftover = val / 10;
              ListNode* new_node = new ListNode(val % 10);
              tail->next = new_node;
              tail = tail->next;
          }

          return dummy->next;
      }
  };

void free_list(ListNode* list)
{
    while (list != nullptr)
    {
        ListNode* temp = list;
        list = list->next;
        delete temp;
    }
}

int main()
{
    Solution solution;
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(3);
    ListNode* l20 = new ListNode(4);
    l2->next = l20;

    ListNode* l3 = new ListNode(-1);

    l3 = solution.addTwoNumbers(l1, l2);

    cout << "list1 = " << l1->val << endl;
    cout << "list2 = " << l2->val << " " << l20->val << endl;
    cout << "list1 + list2 = : " << l3->val << " " << l3->next->val << endl;

    free_list(l1);
    free_list(l2);
    free_list(l3);
}


