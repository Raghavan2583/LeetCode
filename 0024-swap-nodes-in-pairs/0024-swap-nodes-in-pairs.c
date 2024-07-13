/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    struct ListNode *curr = head->next, *prev = head;
    while(curr != NULL){
        swap(&prev->val, &curr->val);
        prev = curr->next;
        if(prev == NULL){
            break;
        }
        curr = prev->next;
    }
    return head;
}