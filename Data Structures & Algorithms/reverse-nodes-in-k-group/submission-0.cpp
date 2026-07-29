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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        int group = 0;
        while (cur && group < k){
            cur = cur->next;
            group++;
        }

        if(group == k){
            cur = reverseKGroup (cur, k);
            while(group-- > 0){
                /*Reversing in recursion 
                (will not reverse the last part 
                because end node will return nullptr)*/
                ListNode* tmp = head->next; 
                head->next = cur;
                cur = head;
                head = tmp;
            }
            //Head of next part
            head = cur;
        }
        return head;
    }
};
