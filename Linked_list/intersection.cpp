/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Brute force 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *tempA = headA;
        ListNode *tempB= headB;

    while(tempA != NULL){
        while(tempB != NULL){
            if(tempA == tempB){
                // tempB= tempB->next;
                return tempB;
            }
            tempB= tempB->next;
        }
        tempB = headB;
        tempA = tempA->next;
    }
        return NULL;
    }
};


//Optimised way
//O(M+N)

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *tempA= headA;
        ListNode *tempB= headB;

        while(tempA != tempB){
            if(tempA == NULL){
                tempA = headB;
            }else {
            tempA = tempA->next;
            }

            if(tempB == NULL){
                tempB = headA;
            }else {
            tempB= tempB->next;}
        }
      
		return tempA; // either they become null together or returns a value

    }


	int main() {
    // Creating first linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    ListNode *b1 = new ListNode(9);
    b1->next = a4;

    Solution s;
    ListNode *intersectNode = s.getIntersectionNode(a1, b1);

    if (intersectNode)
        cout << "Intersection at node with value: " << intersectNode->val << endl;
    else
        cout << "No intersection found." << endl;

    return 0;
}