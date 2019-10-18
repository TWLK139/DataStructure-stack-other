#include"stack.h"

int main(void)
{
	int order = NULL;
	elementType elementIn;
	seqQueue input = {					//模拟入栈的输入序列
		{1,2,3,4,5},
		0,
		4
	}, output = {						//临时存储的中间栈
		{},
		0,
		-1
	};
	seqStack mid = {					//模拟出栈的输出序列
		{},
		-1
	};

	while (1)
	{
		cout << "*****************************************" << endl;
		cout << "*1，查看所有合法输出序列。\t\t*" << endl;
		cout << "*2，判断输出序列是否合法。\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			getAllOutput(&input, &mid, &output);
			break;
		case 2:
			system("cls");
			cout << "请输入输出序列：" << endl;
			for (int i = 0; i < MAXLEN; i++)
			{
				cout << "请输入输出序列第" << i + 1 << "个元素：\t";
				cin >> elementIn;
				output.data[i] = elementIn;
				output.rear++;
			}
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			break;
		case 0:
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}


//功能：获取所有合法输出序列
//输入：输入序列，中间栈存储位置，输出队列存储位置
//输出：函数内打印合法输出序列
void getAllOutput(seqQueue* input, seqStack* mid, seqQueue* output)
{
	seqQueue newInput, newOutput;		//新建变量用于开启新递归时保留原始数据，以开启另一种可能的递归
	seqStack newMid;

	if (input->front > input->rear)		//当模拟输入栈的队列为空时，表明所有元素都已入栈或出栈
	{
		if (mid->top == -1)				//（输入栈为空的条件下）当中间栈也为空时，说明所有元素都已出栈，可以输出模拟出栈的队列
		{								//循环输出模拟出栈队列
			while (output->front <= output->rear)
			{
				cout << output->data[output->front] << "_";
				output->front++;
			}
			cout << endl;
		}
		else							//（输入栈为空的条件下）当中间栈不为空时，说明有些已入栈元素还未出栈，要进行出栈操作
		{
			output->data[output->rear + 1] = mid->data[mid->top];
			mid->top--;
			output->rear++;
			getAllOutput(input, mid, output);
		}
	}
	else								//当模拟输入栈的队列非空时，表明还有元素尚未入栈，接下来将有两种情况可以执行
	{
		if (mid->top != -1)				//（输入栈非空的条件下）第一种情况：中间栈不为空时，可以进行中间栈出栈操作
		{
			newInput = *input;			//因为还有第二种情况，所以在进行出栈前还需要保留原始数据
			newMid = *mid;				//拷贝一份原始数据，进行出栈操作
			newOutput = *output;
			newOutput.data[newOutput.rear + 1] = newMid.data[newMid.top];
			newMid.top--;
			newOutput.rear++;
			getAllOutput(&newInput, &newMid, &newOutput);
		}
		//（输入栈非空的条件下）第二种情况：无论中间栈是否为空，都可以进行中间栈入栈操作
		//第一种情况已经拷贝了一份数据进行操作，因此这里可以直接用原始数据进行中间栈入栈操作
		mid->data[mid->top + 1] = input->data[input->front];
		mid->top++;
		input->front++;
		getAllOutput(input, mid, output);
	}
}


//功能：判断给定输出序列是否是给定输入序列的合法输出序列
//输入：给定输入序列，给定输出序列
//返回：合法返回true，非法返回false
//注意：只适用于单调递增输入序列
bool legalOutput(seqQueue* input, seqQueue* output)
{
	seqStack mid = {					//新建中间栈
		{},
		-1
	};

	while (input->front <= input->rear)
	{									//输入与输出元素相同，表示该元素一入栈就出栈
		if (input->data[input->front] == output->data[output->front])
		{
			input->front++;
			output->front++;
		}								//输入元素小于输出元素，表示该输入元素入栈后尚未出栈
		else if (input->data[input->front] < output->data[output->front])
		{
			mid.top++;
			mid.data[mid.top] = input->data[input->front];
			input->front++;
		}								//输入元素大于输出元素，表示在该输入元素入栈之前有输出元素出栈
		else
		{								//中间栈顶元素若于该输出元素相等，则表明确实是该元素出栈
			if (mid.data[mid.top] == output->data[output->front])
			{
				mid.top--;
				output->front++;
			}							//反之则表明输出序列不合法
			else
			{
				return false;
			}
		}
	}
	while (mid.top != -1)
	{
		if (mid.data[mid.top] == output->data[output->front])
		{
			mid.top--;
			output->front++;
		}
		else
		{
			return false;
		}
	}
	//恢复原始数据，便于连续测试
	input->front = 0;
	input->rear = 4;
	output->front = 0;
	output->rear = -1;
	return true;
}