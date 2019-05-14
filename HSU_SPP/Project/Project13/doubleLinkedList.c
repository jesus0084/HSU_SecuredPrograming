/* ���� ���� ����Ʈ */
#include "doubleLinkeList.h"
#include <stdio.h>
#include <stdlib.h>


// ����Ʈ �ʱ�ȭ
Node* listInit(Node* head) {
	head->size = 0;
	head->prev = head;
	head->next = head;

	return head;
}


// ����Ʈ ���
void printList(Node* head) {
	Node* p;
	for(p = head->next; p != head; p = p->next)
		printf("[%d] ", p->size);
	printf("\n");
}


// head�� ������(next)�� ����
void insert(Node* head, int value) {
	Node* newNode  = (Node*)malloc(sizeof(Node));	// �� ��� ����
	newNode->size = value;
	newNode->prev = head;
	newNode->next = head->next;
	(head->next)->prev = newNode;
	head->next = newNode;
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

int main() {

	// ����Ʈ�� ������ ���� �� �ʱ�ȭ
	Node* head = (Node*)malloc(sizeof(Node));
	head = listInit(head);

	insert(head, 3);
	insert(head, 4);
	printList(head);
	delete(head, head->next);
	printList(head);
	delete(head, head->next);
	printList(head);
}