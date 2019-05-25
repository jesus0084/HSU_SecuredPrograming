/* ���� ���� ����Ʈ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"


// ����Ʈ �ʱ�ȭ
Node* listInit(Node* head) {
	head->size = 0;
	head->prev = head;
	head->next = head;

	return head;
}


// ����Ʈ ���
void printList(Node* head, char* buf) {
	Node* p;
	int idx=0;
	char ch;
	for(p = head->next; p != head; p = p->next) {
		strncpy(&ch, (void*)p->addr, 1);
		// ex) A:[00085738,0,5] �� ���� ������ ����.
		// A: ���� ����,		00085738: ����Ʈ ��� �ּ�,	0: �ε���,	5: �Ҵ� ũ��
		printf("%c:[%p,%d,%d]  ", ch, p, p->addr - (int)buf, p->size);
	}
	printf("\n");
}


// head�� ������(next)�� ����
Node* insert(Node* head, int value1, int value2) {
	Node* newNode  = (Node*)malloc(sizeof(Node));	// �� ��� ����
	newNode->addr = (int)value1;
	newNode->size = value2;
	newNode->prev = head;
	newNode->next = head->next;
	(head->next)->prev = newNode;
	head->next = newNode;

	return newNode;
}


// ����Ʈ�� ��� ����
void delete(Node* head, Node* target) {
	if(target == head) {	// ��������� ���� ��� �� ����.
		fprintf(stderr, "ERROR delete() : List is already empty\n");
		exit(1);
	}

	(target->prev)->next = target->next;
	(target->next)->prev = target->prev;
	free(target);
}