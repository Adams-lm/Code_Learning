#include <stdio.h>
#include <stdlib.h>
#define ElemType int
using namespace std;

typedef struct LNode {
    ElemType data;
    LNode *next;
} LNode, *LinkList;

LinkList initList(LinkList L) {
    L = (LNode *)malloc(sizeof(LNode));
    L->data = -1;
    L->next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r = L;
    int x;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *)malloc(sizeof(LNode));
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LNode *GetElem(LinkList L, ElemType i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) {
        return L;
    }
    if (i < 1) {
        return NULL;
    }
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, int x) {
    LNode *p = L->next;
    while (p != NULL & p->data != x) {
        p = p->next;
    }
    return p;
}

void print(LNode *L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}