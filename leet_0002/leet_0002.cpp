// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
// 
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
// Example:
// 
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
#include <iostream>
#include <stdint.h>

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode ret(0);
        ListNode* current = &ret;
        uint8_t carry = 0;

        while((l1 != NULL) || (l2 != NULL)){
            uint8_t x, y;

            if(l1 != NULL){
                x = l1->val;
            }
            else{
                x = 0;
            }

            if(l2 != NULL){
                y = l2->val;
            }
            else{
                y = 0;
            }
            
            uint8_t sum = x + y + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }

        if(carry > 0){
            current->next = new ListNode(carry);
        }
        return ret.next;
    }
};

int main(void){
    Solution s;
    ListNode* ret;

    ListNode l1_node0(1);
    ListNode l1_node1(4);
    ListNode l1_node2(3);
//    l1_node0.next = &l1_node1;
//    l1_node1.next = &l1_node2;

    ListNode l2_node0(9);
    ListNode l2_node1(9);
    ListNode l2_node2(4);
    l2_node0.next = &l2_node1;
//    l2_node1.next = &l2_node2;

    ret = s.addTwoNumbers(&l1_node0, &l2_node0);

    std::cout << "[ " << ret->val;
    std::cout << ", " << ret->next->val;
    std::cout << ", " << ret->next->next->val;
    std::cout << "]" << std::endl;

    return 0;
}