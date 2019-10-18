#include<iostream>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

#define MAXLEN 5

using namespace std;

typedef int elementType;

typedef struct sQueue					//使用两个队列共同模拟一个栈的入栈出栈，便于结果输出
{
	elementType data[MAXLEN];
	int front;
	int rear;
} seqQueue;

typedef struct sStack					//使用一个中间栈保存模拟时，入栈后暂未出栈的元素
{
	elementType data[MAXLEN];
	int top;
} seqStack;

void getAllOutput(seqQueue* input, seqStack* mid, seqQueue* output);
bool legalOutput(seqQueue* input, seqQueue* output);