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


//Find the mid of the linked list and then reverse one half of the list then //compare one list to another!
class Solution {
public:
    
    ListNode* reverse(ListNode*head){
        ListNode*prev=NULL;
        while(head!=NULL){
          ListNode*next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
                slow=slow->next;
                fast=fast->next->next;
        }
        if(fast!=NULL)slow=slow->next;
        
        ListNode*revhead=reverse(slow);
        while(revhead!=NULL){
            if(revhead->val!=head->val)return false;
            else{
                revhead=revhead->next;
                head=head->next;
            }
        }
        return true;
    }
};