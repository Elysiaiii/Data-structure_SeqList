#include <stdio.h>
#include "seq_list.h"

/* ��Ŀ��������ʹ��С�鿪���Ĺ���
 * ����˳���Ľӿ�
 * */
int main() {
	SeqList* seq = createSeqList(5);

	for (int i = 0; i < 5; ++i) {
		insertSeq(seq, 0, i + 100);
	}
	showSeq(seq);
	pushBackSeq(seq, 300);
	showSeq(seq);

	insertSeq(seq, 2, 500);
	showSeq(seq);

	deleteSeq(seq, 102);
	showSeq(seq);

	releaseSeqList(seq);
	return 0;
}