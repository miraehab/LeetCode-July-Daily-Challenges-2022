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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);
        ListNode* ans = before;
        ListNode* after = new ListNode(0);
        ListNode* head_after = after;
        ListNode* tmp = head;
        
        while(tmp != nullptr){
            if(tmp->val >= x){
                after->next = new ListNode(tmp->val);
                after = after->next;
            }else{
                before->next = new ListNode(tmp->val);
                before = before->next;
            }
            
            tmp = tmp->next;
        }
        
        before->next = head_after->next;
        
        return ans->next;
    }
};