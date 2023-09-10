#include <stdio.h>
#include "seq_list.h"

/* 项目经理，集成使用小组开发的工具
 * 测试顺序表的接口
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