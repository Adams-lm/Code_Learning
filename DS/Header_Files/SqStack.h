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
    printf("初始化完毕!\n");
}

bool IsEmpty(SqStack s) { return s.top == -1; }

bool Push(SqStack &s, ElemType x) {
    if (s.top == MaxSize - 1) {
        printf("栈已满\n");
        return false;
    }
    s.data[++s.top] = x;
    return true;
}

bool Pop(SqStack &s, ElemType &x) {
    if (IsEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    x = s.data[s.top--];
    printf("出栈栈顶元素，值为%d\n", x);
}

bool GetTop(SqStack &s, ElemType &x) {
    if (IsEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    x = s.data[s.top];
    printf("栈顶元素为：%d\n", x);
    return true;
}
