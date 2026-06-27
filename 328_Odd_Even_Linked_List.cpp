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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* l1 = new ListNode();
        ListNode* p1 = l1;
        
        ListNode* l2 = new ListNode();
        ListNode* p2 = l2;

        int index = 0;
        while(head){
            if(index % 2 == 0){
                p1->next = new ListNode(head->val);
                p1 = p1->next;
            }
            else{
                p2->next = new ListNode(head->val);
                p2 = p2->next;
            }
            head = head->next;
            index += 1;
        }

        p1->next = l2->next;
        
        return l1->next;
    }
};
