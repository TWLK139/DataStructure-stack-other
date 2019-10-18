//���ͨ�ú���������ļ�

#ifndef FUNCTION_H
#define FUNCTION_H

//*******************************************************************************************************************
//����һ��ջ�ĺ�������
//********************
//���ܣ���ʼ��ջ
//���룺ջ
void initialStack(seqStack& S)
{
	S.top = -1;
}

//���ܣ�ȡջ��Ԫ��
//���룺ջ
//���أ�ջ��Ԫ�أ�����ջ�򷵻�NULL
elementType stackTop(seqStack& S)
{
	if (S.top == -1)
	{
		return NULL;
	}
	else
	{
		return S.data[S.top];
	}
}

//���ܣ���ջ
//���룺ջ������Ԫ��
//���أ�ջ������false������ɹ�����true
bool pushStack(seqStack& S, elementType x)
{
	if (S.top == MAXLEN - 1)
	{
		return false;
	}
	else
	{
		S.top++;
		S.data[S.top] = x;
		return true;
	}
}

//���ܣ���ջ
//���룺ջ���洢ջ��Ԫ�صĵ�ַ
//���أ�ջ�շ���false���ɹ���ջ����true
//�����ջ��Ԫ��
bool popStack(seqStack& S, elementType& x)
{
	if (S.top == -1)
	{
		return false;
	}
	else
	{
		x = S.data[S.top];
		S.top--;
		return true;
	}
}

//���ܣ���ջ
//���룺ջ
//���أ�ջ�շ���false���ɹ���ջ����true
bool popStack(seqStack& S)
{
	if (S.top == -1)
	{
		return false;
	}
	else
	{
		S.top--;
		return true;
	}
}

//******************************
bool expressionLagel(char ex[])
{
	int i;
	seqStack exStack;
	initialStack(exStack);

	for (i = 0; ex[i] != '\0'; i++)
	{
		if (ex[i] == '{' || ex[i] == '[' || ex[i] == '(')
		{
			pushStack(exStack, (int)ex[i]);
		}
		else if (ex[i] == ')' || ex[i] == ']' || ex[i] == '}')
		{
			switch (ex[i])
			{
			case ')':
				if (exStack.data[exStack.top] == (int)'(')popStack(exStack);
				else return false;
				break;
			case ']':
				if (exStack.data[exStack.top] == (int)'[')popStack(exStack);
				else return false;
				break;
			case '}':
				if (exStack.data[exStack.top] == (int)'{')popStack(exStack);
				else return false;
				break;
			default:
				return false;
				break;
			}
		}
	}
	if (exStack.top != -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//*******************************************************************************************************************

#endif // !FUNCTION_H