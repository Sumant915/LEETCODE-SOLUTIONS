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
    void nodecount(ListNode*curr,int &count){
        while(curr){
            count++;
            curr=curr->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //pehle puri node counnt karunga 
        int count=0;
        nodecount(head,count);
        ListNode*temp=new ListNode(-1);
        temp->next=head;
        head=temp;
        //total kitne bar reverse hoga count/k
        int r=count/k;
        ListNode*first=temp;
        ListNode*second=first->next;
        while(first && r--){
            ListNode*prev=first;
            ListNode*curr=second;
            int x=k;
            while(curr && x--){
                ListNode*fut=curr->next;
                curr->next=prev;
                prev=curr;
                curr=fut;
            }
            first->next=prev;
             second->next=curr;
            first=second;
            second=first->next;
        }
        return temp->next;
    }
};