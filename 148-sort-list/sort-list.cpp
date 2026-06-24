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
ListNode*find_mid(ListNode*head){
    ListNode*slow = head;
    ListNode*fast = head->next;
    while(fast && fast->next){
        slow= slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode*merge(ListNode*l, ListNode*r){
    ListNode*dummy = new ListNode(-1);
    ListNode*temp = dummy;
    while(l && r){
        if(l->val<=r->val)
        {
            temp->next = new ListNode(l->val);
            l= l->next;
            temp= temp->next;
        }
        else {
            temp->next = new ListNode(r->val);
            r= r->next;
            temp = temp->next;
        }

    }
    while(l){
        temp->next = new ListNode(l->val);
        temp= temp->next;
        l = l->next;
    }
     while(r){
        temp->next = new ListNode(r->val);
        temp= temp->next;
        r = r->next;
    }

    return dummy->next;
}
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode*middle = find_mid(head);
        ListNode*left = head;
        ListNode*right = middle->next;
        middle->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
        
    }
};