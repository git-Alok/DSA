/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*temp = head;
        stack<Node*>st;
        while(!st.empty() || temp){
            if(temp->child){
                Node*c = temp->child;
                temp->child = NULL;
                if(temp->next)
                st.push(temp->next);
                temp->next = c ; 
                c->prev = temp;
            }
            else if(temp->next ==NULL){
                if(!st.empty()){
                    Node*c = st.top();
                    temp->next = c;
                    c->prev = temp;
                    st.pop();
                }
            }
            temp = temp->next;
        }
        return head;
    }
};