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
    ListNode* reverse(ListNode * head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        while( curr != NULL){
          
            nextNode = curr->next;
            curr ->next = prev;
            prev  = curr;
              
            curr = nextNode;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
       head = reverse(head);
       
       ListNode* curr = head;
    ListNode * prev = NULL;
        int carry = 0 ;
       while(curr != NULL){
                int currVal = curr->val;
                int doubleVal = carry + (currVal*2);
                int digit = doubleVal  % 10;
                carry = doubleVal /10;

                curr->val = digit ;
                prev = curr;
                curr = curr->next;
       }
        
       if(carry > 0 ){
            ListNode * newNode = new ListNode(carry);
            prev -> next = newNode;
        
       }
      return  reverse(head);
      
    }
};