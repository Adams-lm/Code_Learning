#include <stdio.h>
#include <stdlib.h>
#define ElemType int
using namespace std;

typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

// 题目一：递归删除x

void Del_X_3(LinkList &L, ElemType x) {
    LNode *p;
    if (L == NULL) return;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else {
        Del_X_3(L->next, x);
    }
}

// 题目二：遍历删除x
void Del_X_1(LinkList &L, ElemType x) {
    LNode *p = L->next, *pre = L, *q;
    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

// 逆序输出
void Reverse_Print(LinkList L) {
    if (L->next != NULL) {
        Reverse_Print(L->next);
    }
    if (L != NULL) printf("%d", L->data);
}