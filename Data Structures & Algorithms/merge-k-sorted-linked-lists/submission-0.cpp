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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        return divide(lists, 0, lists.size()-1);
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        if(l>r){
            return nullptr;
        }
        if(l==r){
            return lists[l];
        }

        int mid = l+(r-l)/2;
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid+1, r);

        return conquer(left,right);
    }

    
    ListNode* conquer(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        if (list1->val <= list2->val){
            list1->next = conquer(list1->next, list2);
            return list1;
        }
        else{
            list2->next= conquer(list2->next, list1);
            return list2;
        }
    }
};
