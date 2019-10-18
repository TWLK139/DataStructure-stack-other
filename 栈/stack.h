//��Žṹ���塢�����������ļ�

#ifndef STACK_H

#define STACK_H

#include<iostream>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

//ͨ������
using namespace std;

typedef int elementType;

//*******************************************************************************************************************
//����һ�㹦�ܵ���󳤶�
#define MAXLEN 100

//����һ�㹦�ܵ�ջ
typedef struct sStack
{
	elementType data[MAXLEN];
	int top;
} seqStack;

//����һ�㹦�ܵĺ���
void initialStack(seqStack& S);
elementType stackTop(seqStack& S);
bool pushStack(seqStack& S, elementType x);
bool popStack(seqStack& S, elementType& x);
bool popStack(seqStack& S);					//���س�ջ�����������Ƿ���Ҫ����ջ��Ԫ��ѡ��ʹ��

//******************************
bool expressionLagel(char ex[]);

//*******************************************************************************************************************



//*******************************************************************************************************************
//����������кϷ��Է�������󳤶�
#define MAXLEN_1 5

//����������кϷ��Է�����ջ�����
typedef struct sQueue_lagel					//ʹ���������й�ͬģ��һ��ջ����ջ��ջ�����ڽ�����
{
	elementType data[MAXLEN_1];
	int front;
	int rear;
} seqQueue_lagel;

typedef struct sStack_lagel					//ʹ��һ���м�ջ����ģ��ʱ����ջ����δ��ջ��Ԫ��
{
	elementType data[MAXLEN_1];
	int top;
} seqStack_lagel;

//����������кϷ��Է�������
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output);
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output);
//*******************************************************************************************************************

#endif // STACK_H