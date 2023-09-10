#include <stdio.h>
#include <stdlib.h>
#include "seq_list.h"

SeqList* createSeqList(int n)			// 创建表头，并将表头的数据域初始化n个
{
	SeqList* head = (SeqList*)malloc(sizeof(SeqList));	// 创造头结点
	if (head == NULL)	//---------------注意判断头结点是否创造成功！！！------------//
	{
		printf("malloc head failed!\n");
		return NULL;
	}
	//初始化表头里的所有数据成员
	head->data = (Element*)malloc(sizeof(Element) * n);
	if (head->data == NULL)	//-----------------注意判断数据域是否创造成功！！！-----------------//
	{
		printf("malloc data failed!\n");
		free(head);		//-------------为什么free(head)-------------//
		return NULL;
	}

	head->capacity = n;
	head->len = 0;		//0个元素，待插入位置的索引号

	return head;
}

void releaseSeqList(SeqList* seq)
{
	if (seq)
	{
		if (seq->data)
		{
			free(seq->data); //-----------------------为什么释放seq->data而不是seq----------------------//
		}
		free(seq);	//---------------注意释放顺序表其他数据！！！-------------//
	}
}

/* 扩容接口，内部接口，只为本文件里的函数服务，外部的其他源文件都不能直接使用 */
static int enLargerSeq(SeqList* seq)
{
	// 1. 先申请一块原空间大小的2倍空间
	Element* tmp = (Element*)malloc(sizeof(Element) * seq->capacity * 2);
	if (tmp == NULL)
	{
		printf("alloc enlarger failed!\n");
		return 1;
	}
	// 2. 把原空间的内容拷贝到新空间
	for (int i = 0; i < seq->capacity; i++)
	{
		tmp[i] = seq->data[i];
	}
	// 3. 释放原空间，更新指针到新空间
	seq->capacity *= 2;
	free(seq->data);
	seq->data = tmp;
	printf("enlarger!\n");
	return 0;
}

// 1. 插入行为（尾插法，推荐）
int pushBackSeq(SeqList* seq, Element val)
{
	//判断是否溢出，如果溢出，要扩容
	if ((seq->len >= seq->capacity) && enLargerSeq(seq)/*扩容失败*/)	//--------注意插入前要判断顺序表是否溢出----------//
	{
		return -1;
	}
	seq->data[seq->len] == val;
	seq->len++;
	return 0;
}

// 1. 插入行为（任意位置插入法，接口，慎用）
int insertSeq(SeqList* seq, int pos, Element val)
{
	// 1. 插入范围校验 check
	if (pos<0 || pos>seq->len)	//--------------注意插入范围的检验！！！------------//
	{
		printf("pos invailed!\n");
		return -1;
	}
	// 2. 处理扩容，发现len>=capacity
	if ((seq->len >= seq->capacity) && enLargerSeq(seq))
	{
		return -1;
	}
	// 3. 从后往前遍历元素，向后拷贝元素，为pos索引处腾出位置
	for (int i = seq->len - 1; i >= pos; i--)
	{
		seq->data[i + 1] = seq->data[i];
	}
	// 4. 放入新元素
	seq->data[pos] = val;
	seq->len++;
	return 0;
}

// 2. 显示、打印顺序表
void showSeq(const SeqList* seq)
{
	for (int i = 0; i < seq->len - 1; i++)
	{
		printf("%d\t", seq->data[i]);
	}
	printf("\n");
}

// 3. 删除（删除某个特定值）
int deleteSeq(SeqList* seq, Element val)
{
	// 1. 先把val的位置找到
	int pos = findSeq(seq, val);
	if (pos < 0)	//--------------------注意检验pos的值，即val是否在顺序表中找到！！！-----------------//
	{
		printf("failed to find!\n");
		return -1;
	}
	// 2. 再删除
	for (int i = pos; i < seq->len - 1; i++)
	{
		seq->data[i] = seq->data[i + 1];
	}
	seq->len--;		//-------------------注意删除后将seq->len--，即有效元素个数减一
	printf("delete %d sucessfully!\n", val);
	return 0;
}

// 4. 查找元素，返回索引值
int findSeq(SeqList* seq, Element val)
{
	// 遍历，从头到尾依次处理
	for (int i = 0; i < seq->len; i++)
	{
		if (seq->data[i] == val)
		{
			return i;
		}
	}
	return -1;
}

