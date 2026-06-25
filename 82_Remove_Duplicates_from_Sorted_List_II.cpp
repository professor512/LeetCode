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
        
        ListNode* temp = head;
        ListNode* prev = nullptr;
        int el = -101;
        while(temp){
            
            if(temp->next && temp->val == temp->next->val || temp->val == el){
                el = temp->val;
                ListNode* del = temp;
                temp = temp->next;

                if(prev){
                    prev->next = temp;
                }
                else{
                    head = temp;
                }
                delete del;
            }
            else{
            prev = temp;
            temp = temp->next;
            }
            
        }


        return head;
    }
};
