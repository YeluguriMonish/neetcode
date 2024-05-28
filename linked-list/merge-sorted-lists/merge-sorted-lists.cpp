
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    if (!list1 && !list2) {
      return nullptr;
    }

    ListNode *head = list1;
    if ((list1 && list2 && list1->val > list2->val) || (list2 && !list1)) {
      head = list2;
      list2 = list2->next;
    } else {
      list1 = list1->next;
    }

    ListNode *curr_pos = head;

    while (list1 || list2) {

      if (list1 && list2) {
        if (list1->val <= list2->val) {
          curr_pos->next = list1;
          list1 = list1->next;
        } else {
          curr_pos->next = list2;
          list2 = list2->next;
        }
      } else if (list1 && !list2) {
        curr_pos->next = list1;
        list1 = list1->next;
      } else {
        curr_pos->next = list2;
        list2 = list2->next;
      }

      curr_pos = curr_pos->next;
    }

    return head;
  }
};

int main() { Solution *soln = new Solution(); }
