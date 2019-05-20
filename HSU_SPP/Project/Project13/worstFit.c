/* Worst Fit Memory Allocation & Free */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkeList.h"

// main.c �� �ִ� �������� ���
extern Node* allocHead;		// �Ҵ�� ���� ����Ʈ
extern Node* emptyHead;		// ����ִ� ���� ����Ʈ


// Worst Fit Memory Allocation
// buf �ȿ� size��ŭ ����(ch) �Ҵ�
Node* worstAlloc(char* buf, char ch, int size) {

	Node* i;
	Node* worstNode = NULL;
	Node* newNode = NULL;

	// ��û�� �´� ���� ū ���� Ž��
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if(i->size > size)	// �� ������ ��û�� �������� ũ�ٸ� 
			worstNode = i;
	}

	if(worstNode == NULL) {	// worstNode�� �� ã������ ���� ��� �� ����.
		fprintf(stderr, "ERROR worstAlloc() : No suitable space\n");
		exit(1);
	}
	else {	// ã������ �Ҵ�
		memset((void*)worstNode->addr, ch, size);
		
		// �Ҵ�� ���� ����Ʈ�� �߰�
		newNode = insert(allocHead, worstNode->addr, size);

		// �Ҵ�� �������� ���Ͽ�, ����ִ� ���� ����Ʈ�� �����ϴ� �۾�
		insert(emptyHead, worstNode->addr+size, (worstNode->size) - size);
		delete(emptyHead, worstNode);
	}
	
	return newNode;	// ���� �߰��� ��� �ּ� ��ȯ
}


// Worst Fit Memory Freeing
// buf �ȿ� �Ҵ�� �޸� ���� ��ȯ
void worstFree(Node* target) {
	Node* i;
	int targetCheck = FALSE;

	// �Ҵ�� ���� ����Ʈ�� target�� �ִ��� �˻�
	for(i=allocHead->next; i!=allocHead; i=i->next) {
		if(target == i) {
			targetCheck = TRUE;
			break;
		}
	}
	if(i == allocHead) {	// worstAlloc()���� �Ҵ�� ������ �ƴϸ� ���� ��� �� ����
		fprintf(stderr, "ERROR worstFree() : Not the space allocated as worstAlloc()\n");
		exit(1);
	}
	else {
		memset(target->addr, '0', target->size);
		// ����ִ� ���� ����Ʈ�� target �߰�
		insert(emptyHead, target->addr, target->size);
		// �Ҵ�� ���� ����Ʈ���� target ����
		delete(allocHead, target);
	}
}