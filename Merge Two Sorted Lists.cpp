class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result = new ListNode(-1);
        ListNode* temp = result;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        while(list1) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        while(list2) {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }

        result = result->next;
        return result;
    }
};
