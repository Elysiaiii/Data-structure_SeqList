#include <stdio.h>
#include <stdlib.h>
#include "seq_list.h"

SeqList* createSeqList(int n)			// ������ͷ��������ͷ���������ʼ��n��
{
	SeqList* head = (SeqList*)malloc(sizeof(SeqList));	// ����ͷ���
	if (head == NULL)	//---------------ע���ж�ͷ����Ƿ���ɹ�������------------//
	{
		printf("malloc head failed!\n");
		return NULL;
	}
	//��ʼ����ͷ����������ݳ�Ա
	head->data = (Element*)malloc(sizeof(Element) * n);
	if (head->data == NULL)	//-----------------ע���ж��������Ƿ���ɹ�������-----------------//
	{
		printf("malloc data failed!\n");
		free(head);		//-------------Ϊʲôfree(head)-------------//
		return NULL;
	}

	head->capacity = n;
	head->len = 0;		//0��Ԫ�أ�������λ�õ�������

	return head;
}

void releaseSeqList(SeqList* seq)
{
	if (seq)
	{
		if (seq->data)
		{
			free(seq->data); //-----------------------Ϊʲô�ͷ�seq->data������seq----------------------//
		}
		free(seq);	//---------------ע���ͷ�˳����������ݣ�����-------------//
	}
}

/* ���ݽӿڣ��ڲ��ӿڣ�ֻΪ���ļ���ĺ��������ⲿ������Դ�ļ�������ֱ��ʹ�� */
static int enLargerSeq(SeqList* seq)
{
	// 1. ������һ��ԭ�ռ��С��2���ռ�
	Element* tmp = (Element*)malloc(sizeof(Element) * seq->capacity * 2);
	if (tmp == NULL)
	{
		printf("alloc enlarger failed!\n");
		return 1;
	}
	// 2. ��ԭ�ռ�����ݿ������¿ռ�
	for (int i = 0; i < seq->capacity; i++)
	{
		tmp[i] = seq->data[i];
	}
	// 3. �ͷ�ԭ�ռ䣬����ָ�뵽�¿ռ�
	seq->capacity *= 2;
	free(seq->data);
	seq->data = tmp;
	printf("enlarger!\n");
	return 0;
}

// 1. ������Ϊ��β�巨���Ƽ���
int pushBackSeq(SeqList* seq, Element val)
{
	//�ж��Ƿ��������������Ҫ����
	if ((seq->len >= seq->capacity) && enLargerSeq(seq)/*����ʧ��*/)	//--------ע�����ǰҪ�ж�˳����Ƿ����----------//
	{
		return -1;
	}
	seq->data[seq->len] == val;
	seq->len++;
	return 0;
}

// 1. ������Ϊ������λ�ò��뷨���ӿڣ����ã�
int insertSeq(SeqList* seq, int pos, Element val)
{
	// 1. ���뷶ΧУ�� check
	if (pos<0 || pos>seq->len)	//--------------ע����뷶Χ�ļ��飡����------------//
	{
		printf("pos invailed!\n");
		return -1;
	}
	// 2. �������ݣ�����len>=capacity
	if ((seq->len >= seq->capacity) && enLargerSeq(seq))
	{
		return -1;
	}
	// 3. �Ӻ���ǰ����Ԫ�أ���󿽱�Ԫ�أ�Ϊpos�������ڳ�λ��
	for (int i = seq->len - 1; i >= pos; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	// 4. ������Ԫ��
	seq->data[pos] = val;
	seq->len++;
	return 0;
}

// 2. ��ʾ����ӡ˳���
void showSeq(const SeqList* seq)
{
	for (int i = 0; i < seq->len - 1; i++)
	{
		printf("%d\t", seq->data[i]);
	}
	printf("\n");
}

// 3. ɾ����ɾ��ĳ���ض�ֵ��
int deleteSeq(SeqList* seq, Element val)
{
	// 1. �Ȱ�val��λ���ҵ�
	int pos = findSeq(seq, val);
	if (pos < 0)	//--------------------ע�����pos��ֵ����val�Ƿ���˳������ҵ�������-----------------//
	{
		printf("failed to find!\n");
		return -1;
	}
	// 2. ��ɾ��
	for (int i = pos; i < seq->len - 1; i++)
	{
		seq->data[i] = seq->data[i + 1];
	}
	seq->len--;		//-------------------ע��ɾ����seq->len--������ЧԪ�ظ�����һ
	printf("delete %d sucessfully!\n", val);
	return 0;
}

// 4. ����Ԫ�أ���������ֵ
int findSeq(SeqList* seq, Element val)
{
	// ��������ͷ��β���δ���
	for (int i = 0; i < seq->len; i++)
	{
		if (seq->data[i] == val)
		{
			return i;
		}
	}
	return -1;
}

