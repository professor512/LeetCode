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

//  1.find middle
//  2. reverse second half
//  3. merge 2 half alternatively

class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while(second != NULL){
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // Prev is head of second now so
        second = prev;

        ListNode* first = head;

        while(second != NULL){
            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
