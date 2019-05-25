/* Best Fit Memory Allocation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c �� �ִ� �������� ���
extern Node* allocHead;		// �Ҵ�� ���� ����Ʈ
extern Node* emptyHead;		// �� ���� ����Ʈ


// Best Fit Memory Allocation
// buf �ȿ� size��ŭ ����(ch) �Ҵ�
Node* bestAlloc(char* buf, char ch, int size) {

	Node* i;
	Node* bestNode = NULL;
	Node* newNode = NULL;
	int gap = BUF_SIZE;

	// ��û ũ�⿡ ���� �˸��� ���� Ž��
	// gap�� ���� ���� ��尡 bestNode�� ���õȴ�.
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		// �� ������ ��û�� �������� ũ��, gap�� ������ gap���� �۴ٸ�
		if((i->size >= size) && (i->size - size < gap)) {
			gap = i->size - size;	// gap ����
			bestNode = i;			// bestNode ����
		}
	}

	if(bestNode == NULL) {	// bestNode�� �� ã������ ���� ��� �� ����.
		fprintf(stdout, "[*] bestAlloc() : ������ ������ ã�� ���Ͽ����ϴ�.\n");
		return 1;
	}
	else {	// ã������ �Ҵ�
		memset((void*)bestNode->addr, ch, size);

		// �Ҵ�� ���� ����Ʈ�� �߰�
		newNode = insert(allocHead, bestNode->addr, size);

		// �Ҵ�� �������� ���Ͽ�, ����ִ� ���� ����Ʈ�� �����ϴ� �۾�
		insert(emptyHead, bestNode->addr+size, (bestNode->size) - size);
		delete(emptyHead, bestNode);
	}

	return newNode;	// ���� �߰��� ��� �ּ� ��ȯ
}