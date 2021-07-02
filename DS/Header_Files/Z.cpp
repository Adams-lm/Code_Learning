#include "SqStack.h"
int main() {
    SqStack s;
    InitStack(s);
    IsEmpty(s);
    Push(s, 1);
    Push(s, 2);
    Push(s, 3);
    Push(s, 4);
    IsEmpty(s);
    int e, x;
    Pop(s, e);
    GetTop(s, x);
    Pop(s, e);
    Pop(s, e);
    Pop(s, e);
    system("pause");
}