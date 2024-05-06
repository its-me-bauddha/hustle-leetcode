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
    ListNode* reverseNode(ListNode * head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;

        while(curr != NULL){
            nextNode  = curr->next;
            curr->next = prev;
            prev = curr;
            curr  = nextNode;
            
        }
        return prev;
    } 
    ListNode* removeNodes(ListNode* head) {
            // ListNode* reveseList = reverseNode(head);

            stack<ListNode*> st;
            ListNode*temp = head;
            while(temp != NULL){
                st.push(temp);
                temp = temp->next;
            }
            temp = st.top();
            st.pop();
            int maxNode = temp->val;
            ListNode* ans = new ListNode(maxNode);

            while(!st.empty()){
                   temp = st.top();
                    st.pop();
                    if(temp->val < maxNode){
                       continue;
                    }else{
                         
                       ListNode* newNode = new ListNode(temp->val);
                        newNode->next = ans;
                        ans = newNode;
                        maxNode = temp->val;
                    }
            }

            return ans;
    }

};