//���������кϷ��Է�������������ļ�

#ifndef LAGELFUN_H
#define LAGELFUN_H

//*******************************************************************************************************************
//����������кϷ��Է����ĺ�������
//********************************
//���ܣ���ȡ���кϷ��������
//���룺�������У��м�ջ�洢λ�ã�������д洢λ��
//����������ڴ�ӡ�Ϸ��������
void getAllOutput(seqQueue_lagel* input, seqStack_lagel* mid, seqQueue_lagel* output)
{
	seqQueue_lagel newInput, newOutput;		//�½��������ڿ����µݹ�ʱ����ԭʼ���ݣ��Կ�����һ�ֿ��ܵĵݹ�
	seqStack_lagel newMid;

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
bool legalOutput(seqQueue_lagel* input, seqQueue_lagel* output)
{
	sStack_lagel mid = {					//�½��м�ջ
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
	return true;
}
//*******************************************************************************************************************

#endif // !LAGELFUN_H