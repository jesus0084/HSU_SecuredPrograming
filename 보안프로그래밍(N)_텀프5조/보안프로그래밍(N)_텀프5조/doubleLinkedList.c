/* 이중 연결 리스트 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"


// 리스트 초기화
Node* listInit(Node* head) {
	head->size = 0;
	head->prev = head;
	head->next = head;

	return head;
}


// 리스트 출력
void printList(Node* head, char* buf) {
	Node* p;
	int idx=0;
	char ch;
	for(p = head->next; p != head; p = p->next) {
		strncpy(&ch, (void*)p->addr, 1);
		// ex) A:[00085738,0,5] 의 뜻은 다음과 같다.
		// A: 구분 문자,		00085738: 리스트 노드 주소,	0: 인덱스,	5: 할당 크기
		printf("%c:[%p,%d,%d]  ", ch, p, p->addr - (int)buf, p->size);
	}
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