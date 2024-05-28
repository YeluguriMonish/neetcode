#include <iostream>
#include <vector>

using namespace std;

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
  void reorderList(ListNode *head) {
    vector<ListNode *> nodes;
    while (head != nullptr) {
      nodes.push_back(head);
      head = head->next;
    }

    int left = 0;
    int right = nodes.size() - 1;
    int toggle = 1;

    cout << "node count: " << nodes.size() << endl;
    while (left != right) {
      cout << "left: " << left << " right: " << right << endl;

      if (toggle) {
        nodes[left]->next = nodes[right];
        left++;
      } else {
        nodes[right]->next = nodes[left];
        right--;
      }

      toggle = !toggle;
    }
  }
};

int main() {
  ListNode *head;
  printf("hello\n");
  head->val = 2;
  printf("hello\n");
  head->next = new;
  printf("hello\n");
  head->next->next->val = 6;
  printf("hello\n");
  head->next->next->next->val = 8;
  printf("hello\n");

  Solution *soln = new Solution();
  soln->reorderList(head);
}
