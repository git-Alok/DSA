/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
          ListNode*left_prev = nullptr;
          ListNode*left_curr = head;
          int left_count = 1;
          while(left_count!=left){
            left_prev = left_curr;
            left_curr = left_curr->next;
            left_count++;
          }
          ListNode*r_prev = left_curr;
          ListNode*r_curr = left_curr->next;
          ListNode*r_fut = left_curr->next->next;
          while(left_count!=right && r_curr){
            r_curr->next = r_prev;
            r_prev = r_curr ;
            r_curr = r_fut;
            if(r_fut)
            r_fut = r_fut->next;
            else break;
            left_count++;
          }

if(left_prev == nullptr)
    head = r_prev;
else
    left_prev->next = r_prev;

left_curr->next = r_curr;

return head;

    }
};