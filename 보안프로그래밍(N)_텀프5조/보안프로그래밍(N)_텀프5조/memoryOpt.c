/* Memory Optimizer */
/* �Ҵ�� �������� ������� ������ ����ش�. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"


// �޸� ���� �Լ�
void memoryOpt(char* buf, Node* allocHead, Node* emptyHead) {

	// �Ҵ�� ���� ����Ʈ�� ����ų�, �� ���� ����Ʈ�� ��尡 �ϳ��� �����Ѵٸ�
	// �޸� ����ȭ �� �ʿ䰡 ����
	if(allocHead->next == allocHead || emptyHead->next->next == emptyHead) {
		fprintf(stdout, "[+] memoryOpt() : �޸𸮰� ������ �����Դϴ�.\n");
		return;
	}

	// �Ҵ�� ������ ������ ������ �ӽ� �迭 ���� �� �ʱ�ȭ
	char temp[BUF_SIZE];
	memset(temp, 0, BUF_SIZE);
	int sizeSum=0, sizeSum2=0;
	Node* nextNode = NULL;

	// �Ҵ�� �������� ��ġ�� ����
	for(Node* i=allocHead->next; i!=allocHead; i = nextNode) {
		nextNode = i->next;
		strncat(temp, (void*)i->addr, i->size);
		sizeSum = sizeSum + i->size;
		delete(allocHead, i);	// ����������, �ش� ��带 �Ҵ�� ���� ����Ʈ���� ����
	}
	// buf �ʱ�ȭ�� �Ŀ�, ������ ���� ����
	memset(buf, '-', BUF_SIZE);
	strncpy(buf, temp, sizeSum);


	// ����ִ� �������� ��ġ�� ����
	for(Node* i=emptyHead->next; i!=emptyHead; i = nextNode) {
		nextNode = i->next;
		sizeSum2 = sizeSum2 + i->size;
		delete(emptyHead, i);
	}
	// buf �ʱ�ȭ�� �Ŀ�, ������ ���� ����
	memset(buf, '-', BUF_SIZE);
	strncpy(buf, temp, sizeSum);

	// �Ҵ�� ���� ����Ʈ, �� ���� ����Ʈ ���� �ۼ�
	insert(allocHead, (int)buf, sizeSum);
	insert(emptyHead, (int)(buf+sizeSum), sizeSum2);

	printf("[+] �޸� ���� �Ϸ�\n");
}