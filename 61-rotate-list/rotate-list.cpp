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
        if(k==0 ) return head;
        if(head==nullptr||head->next==nullptr)
        return head;
        int count=0;
        ListNode *temp=head;
        while(temp){
            count++;
            temp=temp->next;  
        }
        if(k%count==0) return head;
        int count1=k%count;
        int count2=count-count1;
        count2--;
        temp=head;
        while(count2--){
            temp=temp->next;
        }
        ListNode * tail=temp;
        ListNode * tailfirst=temp->next;
        ListNode *taillast=tailfirst;
        while(taillast->next!=nullptr){
            taillast=taillast->next;
        }
        taillast->next=head;
        head=tailfirst;
        tail->next=nullptr;
        return head;    
    }
};