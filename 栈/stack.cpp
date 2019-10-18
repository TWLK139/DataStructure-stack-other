#include"stack.h"
#include"function.h"
#include"lagelFun.h"

int main(void)
{
	int order = NULL;
	elementType elementIn;
	seqQueue_lagel input = {						//模拟入栈的输入序列
		{1,2,3,4,5},
		0,
		4
	}, output = {									//临时存储的中间栈
		{},
		0,
		-1
	};
	seqStack_lagel mid = {							//模拟出栈的输出序列
		{},
		-1
	};
	char ex[MAXLEN];

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
			//恢复原始数据，便于连续测试
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			break;
		case 2:
			system("cls");
			cout << "请输入输出序列：" << endl;
			for (int i = 0; i < MAXLEN_1; i++)
			{
				cout << "请输入输出序列第" << i + 1 << "个元素：\t";
				cin >> elementIn;
				output.data[i] = elementIn;
				output.rear++;
			}
			if (legalOutput(&input, &output))cout << "是合法输出序列" << endl;
			else cout << "不是合法输出序列" << endl;
			//恢复原始数据，便于连续测试
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			break;
		case 3:
			system("cls");
			cout << "请输入一个数学表达式：" << endl;
			cin >> ex;
			if (expressionLagel(ex))cout << "表达式合法" << endl;
			else cout << "表达式非法" << endl;
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