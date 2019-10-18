#include"stack.h"
#include"function.h"
#include"lagelFun.h"

int main(void)
{
	int order = NULL;
	elementType elementIn;
	seqQueue_lagel input = {						//ģ����ջ����������
		{1,2,3,4,5},
		0,
		4
	}, output = {									//��ʱ�洢���м�ջ
		{},
		0,
		-1
	};
	seqStack_lagel mid = {							//ģ���ջ���������
		{},
		-1
	};
	char ex[MAXLEN];

	while (1)
	{
		cout << "*****************************************" << endl;
		cout << "*1���鿴���кϷ�������С�\t\t*" << endl;
		cout << "*2���ж���������Ƿ�Ϸ���\t\t*" << endl;
		cout << "*\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t*" << endl;
		cout << "*****************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			getAllOutput(&input, &mid, &output);
			//�ָ�ԭʼ���ݣ�������������
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			break;
		case 2:
			system("cls");
			cout << "������������У�" << endl;
			for (int i = 0; i < MAXLEN_1; i++)
			{
				cout << "������������е�" << i + 1 << "��Ԫ�أ�\t";
				cin >> elementIn;
				output.data[i] = elementIn;
				output.rear++;
			}
			if (legalOutput(&input, &output))cout << "�ǺϷ��������" << endl;
			else cout << "���ǺϷ��������" << endl;
			//�ָ�ԭʼ���ݣ�������������
			input.front = 0;
			input.rear = 4;
			output.front = 0;
			output.rear = -1;
			break;
		case 3:
			system("cls");
			cout << "������һ����ѧ���ʽ��" << endl;
			cin >> ex;
			if (expressionLagel(ex))cout << "���ʽ�Ϸ�" << endl;
			else cout << "���ʽ�Ƿ�" << endl;
			break;
		case 0:
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}