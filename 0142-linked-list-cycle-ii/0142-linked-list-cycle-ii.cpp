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
    ListNode* floyCycleDetection(ListNode*head){
        if(head==NULL){
            return NULL;
        }
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL && slow!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return slow;
            }

        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode*intersection=floyCycleDetection(head);
        if(intersection==NULL) return NULL;
        ListNode*slow=head;
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
    }
};