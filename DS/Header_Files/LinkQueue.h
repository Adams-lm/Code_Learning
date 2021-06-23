#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define ElemType int
using namespace std;

typedef struct LinkNode {
    ElemType data;
    LinkNode *next;
} LinkNode;

typedef struct LinkQueue {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) return true;
    return false;
}

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (IsEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}