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


    ListNode* deleteDuplicates(ListNode* head) {
        // if(!head){
        //     return head;
        // }

        ListNode* curr= head;

        while(curr && curr->next ){     //the condition is necessary because head means the address to first node, not the first node

            if(curr->val == curr->next->val){
                ListNode* temp= curr->next;
                curr->next= curr->next->next;
                delete temp;
            }else{
                curr= curr->next;
            }
        }
        return head;
    }
};