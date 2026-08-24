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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       
        priority_queue<pair<int, ListNode*>,vector<pair<int, ListNode*>>,greater<pair<int, ListNode*>>>pq;
      int k = lists.size();
      for(int i=0;i<k;i++){
        if(lists[i]!=NULL)
        pq.push({lists[i]->val,lists[i]});
      }
      ListNode*head = new ListNode(-1);
      ListNode*ans = head;
      while(!pq.empty()){
        int data = pq.top().first;
        ListNode* temp = pq.top().second;
        pq.pop();
        ans->next = new ListNode(data);
        ans = ans->next;
        temp = temp->next;
        if(temp!=NULL) pq.push({temp->val,temp});
      }
      return head->next;
    }
};