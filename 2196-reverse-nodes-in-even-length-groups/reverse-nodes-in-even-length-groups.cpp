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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head;
        ListNode* prev = dummy;

        int group = 1;

        while (curr) {
            int count = 0;
            ListNode* temp = curr;

            // count nodes in group
            while (temp && count < group) {
                temp = temp->next;
                count++;
            }

            if (count % 2 == 0) {
                // 🔥 reverse using while loop
                ListNode* node = curr;
                ListNode* prevNode = temp;
                int k = count;

                while (k--) {
                    ListNode* nextNode = node->next;
                    node->next = prevNode;
                    prevNode = node;
                    node = nextNode;
                }

                // connect
                ListNode* newTail = curr;
                prev->next = prevNode;

                prev = newTail;
                curr = temp;
            }
            else {
                // normal move
                int k = count;
                while (k--) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            group++;
        }

        return dummy->next;
    }
};