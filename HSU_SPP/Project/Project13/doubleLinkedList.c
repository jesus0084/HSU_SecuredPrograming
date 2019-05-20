/* 이중 연결 리스트 */
#include "doubleLinkeList.h"
#include <stdio.h>
#include <stdlib.h>


// 리스트 초기화
Node* listInit(Node* head) {
	head->size = 0;
	head->prev = head;
	head->next = head;

	return head;
}


// 리스트 출력
void printList(Node* head) {
	Node* p;
	for(p = head->next; p != head; p = p->next)
		printf("[%p,%d] ", (void*)p->addr, p->size);
	printf("\n");
}


// head의 오른쪽(next)에 삽입
Node* insert(Node* head, int value1, int value2) {
	Node* newNode  = (Node*)malloc(sizeof(Node));	// 새 노드 생성
	newNode->addr = (int)value1;
	newNode->size = value2;
	newNode->prev = head;
	newNode->next = head->next;
	(head->next)->prev = newNode;
	head->next = newNode;

	return newNode;
}


// 리스트의 노드 삭제
void delete(Node* head, Node* target) {
	if(target == head) {	// 비어있으면 오류 출력 후 종료.
		fprintf(stderr, "ERROR delete() : List is already empty\n");
		exit(1);
	}

	(target->prev)->next = target->next;
	(target->next)->prev = target->prev;
	free(target);
}
/*
int main() {

	// 리스트의 헤더노드 생성 및 초기화
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
*/