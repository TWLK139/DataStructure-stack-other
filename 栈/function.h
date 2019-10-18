//存放通用函数定义的文件

#ifndef FUNCTION_H
#define FUNCTION_H

//*******************************************************************************************************************
//用于一般栈的函数定义
//********************
//功能：初始化栈
//输入：栈
void initialStack(seqStack& S)
{
	S.top = -1;
}

//功能：取栈顶元素
//输入：栈
//返回：栈顶元素，若空栈则返回NULL
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

//功能：入栈
//输入：栈，插入元素
//返回：栈满返回false，插入成功返回true
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

//功能：出栈
//输入：栈，存储栈顶元素的地址
//返回：栈空返回false，成功出栈返回true
//输出：栈顶元素
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

//功能：出栈
//输入：栈
//返回：栈空返回false，成功出栈返回true
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