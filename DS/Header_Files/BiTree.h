#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define ElemType2 BiTree
#define MaxSize 50
using namespace std;

typedef struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct SqStack {
    ElemType2 data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &s) {
    s.top = -1;
    printf("��ʼ�����!\n");
}

bool IsEmpty(SqStack s) { return s.top == -1; }

bool Push(SqStack &s, ElemType2 x) {
    if (s.top == MaxSize - 1) {
        printf("ջ����\n");
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType2 &x) {
    if (IsEmpty(s)) {
        printf("ջΪ��\n");
        return false;
    }
    x = s.data[s.top--];
    printf("��ջջ��Ԫ�أ�ֵΪ%d\n", x);
}

bool GetTop(SqStack &s, ElemType2 &x) {
    if (IsEmpty(s)) {
        printf("ջΪ��\n");
        return false;
    }
    x = s.data[s.top];
    printf("ջ��Ԫ��Ϊ��%d\n", x);
    return true;
}

void visit(BiTNode *p) { printf("%c", p->data); }

void PreOrder(BiTree T) {
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S)) {
        if (p) {
            visit(p);
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            p = p->rchild;
        }
    }
}

int main() {
    BiTree T;
    BiTree B, C, D, E, F;
    T->data = 'A';
    B->data = 'B';
    C->data = 'C';
    D->data = 'D';
    E->data = 'E';
    F->data = 'F';

    T->lchild = B;
    B->lchild = C;
    C->lchild = D;
    T->rchild = E;
    C->rchild = F;

    PreOrder(T);
}