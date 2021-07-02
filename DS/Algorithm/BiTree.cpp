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
    printf("初始化完�?!\n");
}

bool IsEmpty(SqStack s) { return s.top == -1; }

bool Push(SqStack &s, ElemType2 x) {
    if (s.top == MaxSize - 1) {
        printf("栈已满\n");
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType2 &x) {
    if (IsEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    x = s.data[s.top--];
    printf("出栈栈顶元素，值为%d\n", x);
}

bool GetTop(SqStack &s, ElemType2 &x) {
    if (IsEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    x = s.data[s.top];
    printf("栈顶元素为：%d\n", x);
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
    BiTree T, B, C, D, E, F;
    T = (BiTNode *)malloc(sizeof(BiTNode));
    B = (BiTNode *)malloc(sizeof(BiTNode));
    C = (BiTNode *)malloc(sizeof(BiTNode));
    D = (BiTNode *)malloc(sizeof(BiTNode));
    E = (BiTNode *)malloc(sizeof(BiTNode));
    F = (BiTNode *)malloc(sizeof(BiTNode));

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

    B->rchild = NULL;
    D->lchild = NULL;

    PreOrder(T);
}