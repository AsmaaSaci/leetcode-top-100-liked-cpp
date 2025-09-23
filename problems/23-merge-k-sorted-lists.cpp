class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // lambda function للمقارنة (min-heap على val)
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // ندخل أول عنصر من كل لستة
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next) pq.push(curr->next);
        }

        return dummy.next;
    }
};
