#include"stack.h"

int main(void)
{
	int order = NULL;
	elementType elementIn;
	seqQueue input = {					//ģ����ջ����������
		{1,2,3,4,5},
		0,
		4
	}, output = {						//��ʱ�洢���м�ջ
		{},
		0,
		-1
	};
	seqStack mid = {					//ģ���ջ���������
		{},
		-1
	};

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
			break;
		case 2:
			system("cls");
			cout << "������������У�" << endl;
			for (int i = 0; i < MAXLEN; i++)
			{
				cout << "������������е�" << i + 1 << "��Ԫ�أ�\t";
				cin >> elementIn;
				output.data[i] = elementIn;
				output.rear++;
			}
			if (legalOutput(&input, &output))cout << "�ǺϷ��������" << endl;
			else cout << "���ǺϷ��������" << endl;
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


//���ܣ���ȡ���кϷ��������
//���룺�������У��м�ջ�洢λ�ã�������д洢λ��
//����������ڴ�ӡ�Ϸ��������
void getAllOutput(seqQueue* input, seqStack* mid, seqQueue* output)
{
	seqQueue newInput, newOutput;		//�½��������ڿ����µݹ�ʱ����ԭʼ���ݣ��Կ�����һ�ֿ��ܵĵݹ�
	seqStack newMid;

	if (input->front > input->rear)		//��ģ������ջ�Ķ���Ϊ��ʱ����������Ԫ�ض�����ջ���ջ
	{
		if (mid->top == -1)				//������ջΪ�յ������£����м�ջҲΪ��ʱ��˵������Ԫ�ض��ѳ�ջ���������ģ���ջ�Ķ���
		{								//ѭ�����ģ���ջ����
			while (output->front <= output->rear)
			{
				cout << output->data[output->front] << "_";
				output->front++;
			}
			cout << endl;
		}
		else							//������ջΪ�յ������£����м�ջ��Ϊ��ʱ��˵����Щ����ջԪ�ػ�δ��ջ��Ҫ���г�ջ����
		{
			output->data[output->rear + 1] = mid->data[mid->top];
			mid->top--;
			output->rear++;
			getAllOutput(input, mid, output);
		}
	}
	else								//��ģ������ջ�Ķ��зǿ�ʱ����������Ԫ����δ��ջ�����������������������ִ��
	{
		if (mid->top != -1)				//������ջ�ǿյ������£���һ��������м�ջ��Ϊ��ʱ�����Խ����м�ջ��ջ����
		{
			newInput = *input;			//��Ϊ���еڶ�������������ڽ��г�ջǰ����Ҫ����ԭʼ����
			newMid = *mid;				//����һ��ԭʼ���ݣ����г�ջ����
			newOutput = *output;
			newOutput.data[newOutput.rear + 1] = newMid.data[newMid.top];
			newMid.top--;
			newOutput.rear++;
			getAllOutput(&newInput, &newMid, &newOutput);
		}
		//������ջ�ǿյ������£��ڶ�������������м�ջ�Ƿ�Ϊ�գ������Խ����м�ջ��ջ����
		//��һ������Ѿ�������һ�����ݽ��в���������������ֱ����ԭʼ���ݽ����м�ջ��ջ����
		mid->data[mid->top + 1] = input->data[input->front];
		mid->top++;
		input->front++;
		getAllOutput(input, mid, output);
	}
}


//���ܣ��жϸ�����������Ƿ��Ǹ����������еĺϷ��������
//���룺�����������У������������
//���أ��Ϸ�����true���Ƿ�����false
//ע�⣺ֻ�����ڵ���������������
bool legalOutput(seqQueue* input, seqQueue* output)
{
	seqStack mid = {					//�½��м�ջ
		{},
		-1
	};

	while (input->front <= input->rear)
	{									//���������Ԫ����ͬ����ʾ��Ԫ��һ��ջ�ͳ�ջ
		if (input->data[input->front] == output->data[output->front])
		{
			input->front++;
			output->front++;
		}								//����Ԫ��С�����Ԫ�أ���ʾ������Ԫ����ջ����δ��ջ
		else if (input->data[input->front] < output->data[output->front])
		{
			mid.top++;
			mid.data[mid.top] = input->data[input->front];
			input->front++;
		}								//����Ԫ�ش������Ԫ�أ���ʾ�ڸ�����Ԫ����ջ֮ǰ�����Ԫ�س�ջ
		else
		{								//�м�ջ��Ԫ�����ڸ����Ԫ����ȣ������ȷʵ�Ǹ�Ԫ�س�ջ
			if (mid.data[mid.top] == output->data[output->front])
			{
				mid.top--;
				output->front++;
			}							//��֮�����������в��Ϸ�
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
	//�ָ�ԭʼ���ݣ�������������
	input->front = 0;
	input->rear = 4;
	output->front = 0;
	output->rear = -1;
	return true;
}