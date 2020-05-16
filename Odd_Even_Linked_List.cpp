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
        if(head == NULL){
            return NULL;
        }
        ListNode* evenHead = head;
        ListNode* oddHead = head->next;
        ListNode *temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            head->next = head->next->next;
            if(head->next->next == NULL){
                temp->next = NULL;
            }
            else{
                temp->next = head->next->next;
            }
            head = head->next;
            temp = head->next;
        }
        
        head->next = oddHead;
        return evenHead;
    }
};
