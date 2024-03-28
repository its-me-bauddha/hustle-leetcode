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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* mergeList = dummy;

        ListNode * a = list1;
        ListNode * b = list2;

        if(a == NULL ) return b;
        if(b == NULL ) return a;
        

        while(a  && b ){
            if(a -> val < b -> val){
                mergeList -> next = a ;
                a = a ->next;
            }else{
                mergeList->next = b ;
                b = b ->next;  
            }
            mergeList = mergeList -> next;
        }

       if(a){
             mergeList->next = a ;
                        
        }
       if(b){
            mergeList->next= b ;
           
        }
        
        return dummy ->next;
    }
};