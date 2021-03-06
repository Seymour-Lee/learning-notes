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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *end = dummy;
        ListNode *first = head;
        ListNode *second = first->next;
        while(first && second){
            ListNode *next = second->next;
            end->next = second;
            second->next = first;
            first->next = nullptr;
            end = first;
            first = next == nullptr? nullptr: next;
            second = first == nullptr? nullptr: first->next;
        }
        if(first){
            end->next = first;
            first->next = nullptr;
        }
        return dummy->next;
    }
};

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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *curr = prev->next, *post = curr->next;
        while(curr && post){
            prev->next = post;
            curr->next = post->next;
            post->next = curr;
            prev = curr;
            curr = prev->next;
            post = curr? curr->next: nullptr;
        }
        return dummy->next;
    }
};