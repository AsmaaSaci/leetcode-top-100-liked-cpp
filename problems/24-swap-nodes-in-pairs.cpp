class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (head && head->next) {
            ListNode* first = head;
            ListNode* second = head->next;

            // التبديل
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // تحديث المؤشرات
            prev = first;
            head = first->next;
        }

        return dummy.next;
    }
};
