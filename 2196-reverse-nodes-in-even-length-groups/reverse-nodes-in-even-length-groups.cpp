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
   ListNode* rev(ListNode*root){
    ListNode* prev = NULL;
    ListNode* curr = root;
    ListNode* fut = root->next;
    while(curr){
        curr->next = prev;
        prev = curr;
        curr = fut;
        if(fut)
        fut = fut->next;
    }
    return prev;
   }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* root= head;
        ListNode* root_p = NULL;
        int even = 2;
        int odd = 1;
        bool e = 0;
        while(root){
            if(e==0){
              int k =0;
              ListNode*temp = root;
              ListNode* temp_p = root_p;
              while(temp && k<odd){
                k++;
                temp_p = temp;
                temp = temp->next;
              }
              if(k%2==0) {
                root_p->next = rev(root);
                return head;
              }
              root_p = temp_p;
              root = temp;
              odd+=2;
              e = 1;
            }
            else{
            int k = 0;
              ListNode*temp = root;
              ListNode* temp_p = root_p;
              while(temp && k<even){
                k++;
                temp_p = temp;
                temp = temp->next;
              }
              if(k%2!=0) {
                return head;
              }

                k =1;
               temp = root;
               while(temp && k<even){
                    temp = temp->next;
                    k++;
               }
               ListNode* last = NULL;
               if(temp) {
                 last = temp->next;
                 temp->next = NULL;
               }
               root_p->next = rev(root);
               while(root_p->next) root_p = root_p->next;
               root_p->next = last;
               root =  last;
               even +=2;
               e = 0;
            }
        }
        return head;
    }
};