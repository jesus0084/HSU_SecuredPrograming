#pragma once

#define TRUE 1
#define FALSE 0

typedef struct Node {	// 노드 타입
	int addr;		// 시작 주소
	int size;		// 크기
	struct Node* prev;
	struct Node* next;
} Node;


Node* listInit(Node* head);
void printList(Node* head);
Node* insert(Node* head, int value1, int value2);
void delete(Node* head, Node* target);

Node* worstAlloc(char* buf, char ch, int size);
void worstFree(Node* target);