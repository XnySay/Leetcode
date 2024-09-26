#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; // 哑节点
    struct ListNode* current = &dummy; // 当前节点指针
    int carry = 0; // 进位

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int val1 = l1 != NULL ? l1->val : 0; // l1 的当前值，如果 l1 为空，则为 0
        int val2 = l2 != NULL ? l2->val : 0; // l2 的当前值，如果 l2 为空，则为 0
        int sum = val1 + val2 + carry; // 当前位的和，包括进位
        carry = sum / 10; // 计算新的进位
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode)); // 创建新节点
        current = current->next;
        current->val = sum % 10; // 设置当前位的值
        current->next = NULL; // 设置下一个节点为 NULL

        if (l1 != NULL) l1 = l1->next; // 移动 l1 指针
        if (l2 != NULL) l2 = l2->next; // 移动 l2 指针
    }

    return dummy.next; // 返回结果链表的第一个节点
}

// 用于创建链表的辅助函数
struct ListNode* createList(int* values, int size) {
    struct ListNode* dummy = NULL;
    struct ListNode** current = &dummy;
    for (int i = 0; i < size; i++) {
        *current = (struct ListNode*)malloc(sizeof(struct ListNode));
        (*current)->val = values[i];
        (*current)->next = NULL;
        current = &(*current)->next;
    }
    return dummy->next;
}

// 用于打印链表的辅助函数
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d", node->val);
        if (node->next != NULL) printf("->");
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* l1 = createList((int[]){2, 4, 3}, 3);
    struct ListNode* l2 = createList((int[]){5, 6, 4}, 3);
    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result);
    return 0;
}