#include <stdio.h>
#include <stdlib.h>
#define ElemType int
#define MAX_SIZE 50
using namespace std;

typedef struct {
    ElemType data[MAX_SIZE];
    int length;
} SqList;

// 题目一：从顺序表中删除最小值的元素并返回删除的值 出错则退出运行
bool deleteMinElem(SqList &L, ElemType &value) {
    if (L.length == 0) {
        return false;
    }

    value = L.data[0];
    int index = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < value) {
            index = i;
            value = L.data[i];
        }
    }
    L.data[index] = L.data[L.length - 1];
    L.length--;
    return true;
}

// 题目二：将顺序表L的所有元素逆置
void reverseList(SqList &L) {
    ElemType temp;
    for (int i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

// 题目三：删除所有值为x的元素
// 方法1：虚拟构造一个新的数组 利用数组的随机访问 根据不等于X的元素
// 在原来数组的基础上构造新的数组

void delX_1(SqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] != x) {
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}

// 方法2：有几个等于X的元素 当前元素就向前移动几个
void delX_2(SqList &L, ElemType x) {
    int k = 0, i = 0;
    while (i < L.length) {
        if (L.data[i] == x) {
            k++;
        } else {
            L.data[i - k] = L.data[i];
        }
        i++;
        L.length = L.length - k;
    }
}