#pragma warning(disable:4996)
#pragma once

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 50

typedef struct Node {	// 노드 타입
	int addr;		// 시작 주소
	int size;		// 크기
	struct Node* prev;
	struct Node* next;
} Node;

// doubleLinkedList
Node* listInit(Node* head);
void printList(Node* head, char* buf);
Node* insert(Node* head, int value1, int value2);
void delete(Node* head, Node* target);

// worstAlloc
Node* worstAlloc(char* buf, char ch, int size);
// bestAlloc
Node* bestAlloc(char* buf, char ch, int size);
// myFree
void myFree(Node* target);
// memoryOpt
void memoryOpt(char* buf, Node* allocHead, Node* emptyHead);
