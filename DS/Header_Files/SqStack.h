#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define MaxSize 50
using namespace std;

typedef struct SqStack {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &s) {
    s.top = -1;
    for (int i = 0; i < MaxSize; i++) {
        s.data[i] = 0;
    }
    printf("��ʼ�����!\n");
}

bool IsEmpty(SqStack s) { return s.top == -1; }

bool Push(SqStack &s, ElemType x) {
    if (s.top == MaxSize - 1) {
        printf("ջ����\n");
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType &x) {
    if (IsEmpty(s)) {
        printf("ջΪ��\n");
        return false;
    }
    x = s.data[s.top--];
    printf("��ջջ��Ԫ�أ�ֵΪ%d\n", x);
}

bool GetTop(SqStack &s, ElemType &x) {
    if (IsEmpty(s)) {
        printf("ջΪ��\n");
        return false;
    }
    x = s.data[s.top];
    printf("ջ��Ԫ��Ϊ��%d\n", x);
    return true;
}
