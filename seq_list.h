#ifndef SEQ_LIST_H
#define SEQ_LIST_H

typedef int Element;
//����˳���ı�ͷ�ṹ
typedef struct {
	Element* data;		// ָ���˳������������
	int capacity;		// ����������ı߽����������ֵ��������
	int len;			// �������������ЧԪ�صĸ�����������λ�õ������ţ�
}SeqList;

/* ά����ͷ�ṹ(����)���������ͷű� */
SeqList* createSeqList(int n);			// ������ͷ��������ͷ���������ʼ��n��
void releaseSeqList(SeqList* seq);

/* �������ݵĲ�����Ϊ */
// 1. ������Ϊ��β�巨���Ƽ���
int pushBackSeq(SeqList* seq, Element val);
// 1. ������Ϊ������λ�ò��뷨���ӿڣ����ã�
int insertSeq(SeqList* seq, int pos, Element val);

// 2. ��ʾ����ӡ˳���
void showSeq(const SeqList* seq);
// 3. ɾ����ɾ��ĳ���ض�ֵ��
int deleteSeq(SeqList* seq, Element val);
// 4. ����Ԫ�أ���������ֵ
int findSeq(SeqList* seq, Element val);

// ����˳���
static int enLargerSeq(SeqList* seq);
#endif