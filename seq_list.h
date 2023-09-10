#ifndef SEQ_LIST_H
#define SEQ_LIST_H

typedef int Element;
//定义顺序表的表头结构
typedef struct {
	Element* data;		// 指向该顺序表的数据区域
	int capacity;		// 该数据区域的边界条件，最大值（容量）
	int len;			// 该数据区域的有效元素的个数（待插入位置的索引号）
}SeqList;

/* 维护表头结构(堆区)，申请表和释放表 */
SeqList* createSeqList(int n);			// 创建表头，并将表头的数据域初始化n个
void releaseSeqList(SeqList* seq);

/* 表里数据的操作行为 */
// 1. 插入行为（尾插法，推荐）
int pushBackSeq(SeqList* seq, Element val);
// 1. 插入行为（任意位置插入法，接口，慎用）
int insertSeq(SeqList* seq, int pos, Element val);

// 2. 显示、打印顺序表
void showSeq(const SeqList* seq);
// 3. 删除（删除某个特定值）
int deleteSeq(SeqList* seq, Element val);
// 4. 查找元素，返回索引值
int findSeq(SeqList* seq, Element val);

// 扩容顺序表
static int enLargerSeq(SeqList* seq);
#endif