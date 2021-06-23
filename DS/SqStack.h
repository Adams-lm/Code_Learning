#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
using namespace std;

typedef struct SqStack {
    int data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &s) {
    s.top = -1;
    for (int i = 0; i < MaxSize; i++) {
        s.data[i] = 0;
    }
    printf("初始化完毕!\n");
}

bool StackEmpty(SqStack s) { return s.top == -1; }

bool Push(SqStack &s, int e) {
    if (s.top == MaxSize - 1) {
        printf("栈已满\n");
        return false;
    }
    s.data[++s.top] = e;
    return true;
}

bool Pop(SqStack &s, int &e) {
    if (StackEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    e = s.data[s.top--];
    printf("出栈栈顶元素，值为%d\n", e);
}

bool GetTop(SqStack &s, int &e) {
    if (StackEmpty(s)) {
        printf("栈为空\n");
        return false;
    }
    e = s.data[s.top];
    printf("栈顶元素为：%d\n", e);
    return true;
}