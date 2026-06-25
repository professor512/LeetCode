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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int cnt = 0;
        ListNode* temp = head;
        
        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }

        int pos = cnt - n;

        if(pos == 0){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* temp2 = head;
        ListNode* prev = nullptr;

        while(pos){
            prev = temp2;
            temp2 = temp2->next;
            pos--;
        }

        prev->next = temp2->next;
        delete temp2;

        return head;
    }
};
