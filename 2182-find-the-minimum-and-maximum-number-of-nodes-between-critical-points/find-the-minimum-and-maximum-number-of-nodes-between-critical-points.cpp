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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        vector<int>idx;
        for(int i=1;i<n-1;i++){
               if((arr[i]>arr[i-1]&& arr[i]>arr[i+1]) || (arr[i]<arr[i-1]&& arr[i]<arr[i+1]))
               idx.push_back(i+1);
        }
        if(idx.size()<2) return {-1,-1};
        int min_dist = INT_MAX;
        int max_dist =0;
        for(int i=1;i<idx.size();i++){
            min_dist= min(min_dist,idx[i]-idx[i-1]);
        }
        max_dist = idx[idx.size()-1]-idx[0];
        return {min_dist,max_dist};
    }
};