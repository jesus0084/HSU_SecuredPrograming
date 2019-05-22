/* Worst Fit Memory Allocation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c �� �ִ� �������� ���
extern Node* allocHead;		// �Ҵ�� ���� ����Ʈ
extern Node* emptyHead;		// ����ִ� ���� ����Ʈ


// Worst Fit Memory Allocation
// buf �ȿ� size��ŭ ����(ch) �Ҵ�
Node* worstAlloc(char* buf, char ch, int size) {

	Node* i;
	Node* worstNode = NULL;
	Node* newNode = NULL;

	// worstNode �ʱⰪ ����
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if(i->size >= size) {
			worstNode = i;
			break;
		}
	}
	if(worstNode == NULL) {	// worstNode�� �� ã������ ���� ��� �� ����.
		fprintf(stderr, "ERROR worstAlloc() : No suitable space\n");
		exit(1);
	}

	// ��û�� �´� ���� ū ���� Ž��
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if((i->size >= size) && (i->size > worstNode->size)) {
			worstNode = i;
		}
	}
	
	// ã������ �Ҵ�
	memset((void*)worstNode->addr, ch, size);
	
	// �Ҵ�� ���� ����Ʈ�� �߰�
	newNode = insert(allocHead, worstNode->addr, size);

	// �Ҵ�� �������� ���Ͽ�, ����ִ� ���� ����Ʈ�� �����ϴ� �۾�
	insert(emptyHead, worstNode->addr+size, (worstNode->size) - size);
	delete(emptyHead, worstNode);
	
	return newNode;	// ���� �߰��� ��� �ּ� ��ȯ
}


