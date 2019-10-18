#include<iostream>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>

#define MAXLEN 5

using namespace std;

typedef int elementType;

typedef struct sQueue					//ʹ���������й�ͬģ��һ��ջ����ջ��ջ�����ڽ�����
{
	elementType data[MAXLEN];
	int front;
	int rear;
} seqQueue;

typedef struct sStack					//ʹ��һ���м�ջ����ģ��ʱ����ջ����δ��ջ��Ԫ��
{
	elementType data[MAXLEN];
	int top;
} seqStack;

void getAllOutput(seqQueue* input, seqStack* mid, seqQueue* output);
bool legalOutput(seqQueue* input, seqQueue* output);