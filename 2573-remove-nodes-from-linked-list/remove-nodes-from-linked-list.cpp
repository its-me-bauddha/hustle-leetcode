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
    ListNode* recSolve(ListNode* head){
        if(head ==NULL || head -> next == NULL){
            return head;
        }

        ListNode * nextNode = recSolve(head->next);

        if(head -> val < nextNode ->val){
            delete head;
            return nextNode;
        } 

            head ->next = nextNode;
            return head;
      

    }
    ListNode* removeNodes(ListNode* head) {
            

            // stack<ListNode*> st;
            // ListNode*temp = head;
            // while(temp != NULL){
            //     st.push(temp);
            //     temp = temp->next;
            // }
            // temp = st.top();
            // st.pop();
            // // int maxNode = temp->val;
            // ListNode* ans = new ListNode(maxNode);

            // while(!st.empty()){
            //        temp = st.top();
            //         st.pop();
            //         if(temp->val < maxNode){
            //            continue;
            //         }else{
                         
            //            ListNode* newNode = new ListNode(temp->val);
            //             newNode->next = ans;
            //             ans = newNode;
            //             maxNode = temp->val;
            //         }
            // }

            // // return recSolve(head);


         head = reverseNode(head);

        ListNode * prev = NULL;
        ListNode* curr = head;
        int maxNode = -1;
        
         while(curr != NULL){
            maxNode = max(maxNode , curr->val);
            if(maxNode > curr->val){
                prev -> next = curr->next;
                ListNode * temp = curr;
                curr = curr->next;
                delete temp;

            }else{
                prev = curr;
                curr = curr->next;
            }
         }

         return reverseNode(head);
    }

};