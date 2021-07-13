#include <stdio.h>
#include <stdlib.h>

#include <queue>
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

void InOrder(BiTree T) {
    SqStack S;
    InitStack(S);
    BiTree p = T;
    while (p || !IsEmpty(S)) {
        if (p) {
            Push(S, p);
            p = p->lchild;
        } else {
            Pop(S, p);
            visit(p);
            p = p->lchild;
        }
    }
}

void LevelOrder(BiTree T) {
    queue<BiTree> Q;
    BiTree p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild != NULL) Q.push(p->lchild);
        if (p->rchild != NULL) Q.push(p->rchild);
    }
}