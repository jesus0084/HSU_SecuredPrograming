#pragma once

#define TRUE 1
#define FALSE 0
#define BUF_SIZE 100

typedef struct Node {	// ��� Ÿ��
	int addr;		// ���� �ּ�
	int size;		// ũ��
	struct Node* prev;
	struct Node* next;
} Node;

// doubleLinkedList
Node* listInit(Node* head);
void printList(Node* head);
Node* insert(Node* head, int value1, int value2);
void delete(Node* head, Node* target);

// worstAlloc
Node* worstAlloc(char* buf, char ch, int size);
// bestAlloc
Node* bestAlloc(char* buf, char ch, int size);
// myFree
void myFree(Node* target);