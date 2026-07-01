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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n = 0;
        ListNode*temp = head,*last = NULL;
        while(temp){
            if(temp->next==NULL) last = temp;
            temp = temp ->next;
            n++;
        }

        k = k%n;
        if(k==0) return head;
        temp = head;
        int count =n-k;
        ListNode*ans;
        while(count>1){
            temp = temp->next;
            count--;
        }
        ans = temp->next;
        temp->next = NULL;
        last->next = head;
        return  ans;
    }
};