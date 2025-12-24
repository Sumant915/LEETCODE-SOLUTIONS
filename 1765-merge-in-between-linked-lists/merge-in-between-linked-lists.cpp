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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*temp1=list1;
        ListNode*temp2=list1;
        int count=0;
        while(count!=a-1){
            count=count+1;
            if(temp1->next){
            temp1=temp1->next;
            }
        }
        count=0;
        while(count!=b+1){
            count++;
            if(temp2->next){
            temp2=temp2->next;
            }
        }
        ListNode*head2=list2;
        while(list2->next!=nullptr){
            list2=list2->next;
        }
        temp1->next=head2;
        list2->next=temp2;
        return list1;
    }
};