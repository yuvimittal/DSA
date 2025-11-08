/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // if(head == NULL){
        //     return false;
        // }

        // hasCycle(head->next);
        // return true;
// if (!head || !head->next) return false;
        ListNode *slow= head;
        ListNode *fast= head;

        while(fast && fast->next){
            slow= slow->next;       //jump1
            fast= fast->next->next; //jump2

            if(slow==fast){
                return true;
            }
        }
        return false;
        
    }
};