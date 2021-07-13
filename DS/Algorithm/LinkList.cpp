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

void Del_X_2(LinkList &L, ElemType x) {
    LNode *p = L->next, *r = L, *q;
    while (p != NULL) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}

// 逆序输出
void Reverse_Print(LinkList L) {
    if (L->next != NULL) {
        Reverse_Print(L->next);
    }
    if (L != NULL) printf("%d", L->data);
}

void Reverse_Print_Ignore_Head(LinkList L) {
    if (L != NULL) Reverse_Print_Ignore_Head(L->next);
}

// 题目4：删除最小
LinkList Delete_Min(LinkList &L) {
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;
    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }
    minpre->next = minp->next;
    free(minp);
    return L;
}

// 题目5：转置
LinkList Reverse_1(LinkList L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;
    while (p != NULL) {
        r = p->next;        // 暂存
        p->next = L->next;  // p节点插入头结点之后
        L->next = p;
        p = r;
    }
}

LinkList Reverse_2(LinkList L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}