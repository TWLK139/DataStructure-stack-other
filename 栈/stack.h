//存放结构定义、函数声明的文件

#ifndef STACK_H

#define STACK_H

#include<iostream>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

//通用设置
using namespace std;

typedef int elementType;

//*******************************************************************************************************************
//用于一般功能的最大长度
#define MAXLEN 100

//用于一般功能的栈
typedef struct sStack
{
	elementType data[MAXLEN];
	int top;
} seqStack;

//用于一般功能的函数
void initialStack(seqStack& S);
elementType stackTop(seqStack& S);
bool pushStack(seqStack& S, elementType x);
bool popStack(seqStack& S, elementType& x);
bool popStack(seqStack& S);					//重载出栈函数，根据是否需要返回栈顶元素选择使用

//******************************
bool expressionLagel(char ex[]);

//*******************************************************************************************************************



//*******************************************************************************************************************
//用于输出序列合法性分析的最大长度
#define MAXLEN_1 5

//用于输出序列合法性分析的栈与队列
typedef struct sQueue_lagel					//使用两个队列共同模拟一个栈的入栈出栈，便于结果输出
{
	elementType data[MAXLEN_1];
	int front;
	int rear;
} seqQueue_lagel;

typedef struct sStack_lagel					//使用一个中间栈保存模拟时，入栈后暂未出栈的元素
{
	elementType data[MAXLEN_1];
	int top;
} seqStack_lagel;

//用于输出序列合法性分析函数
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output);
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output);
//*******************************************************************************************************************

#endif // STACK_H