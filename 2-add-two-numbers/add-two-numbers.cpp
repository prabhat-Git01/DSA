class Solution {
public:
    void sumOfNodes(int a, int b, int& sum, int& carry) {
        sum = a + b + carry;

        if (sum >= 10) {
            sum %= 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* head = NULL;
        ListNode* curr = NULL;

        int carry = 0;
        int sum = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int a = (temp1 != NULL) ? temp1->val : 0;
            int b = (temp2 != NULL) ? temp2->val : 0;

            sumOfNodes(a, b, sum, carry);

            ListNode* newNode = new ListNode(sum);

            if (head == NULL) {
                head = newNode;
                curr = head;
            } else {
                curr->next = newNode;
                curr = curr->next;
            }

            if (temp1 != NULL)
                temp1 = temp1->next;

            if (temp2 != nullptr)
                temp2 = temp2->next;
        }

        // If carry is still left after both lists are finished
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }

        return head;
    }
};