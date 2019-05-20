#pragma once

#define TRUE 1
#define FALSE 0

typedef struct Node {	// ��� Ÿ��
	int addr;		// ���� �ּ�
	int size;		// ũ��
	struct Node* prev;
	struct Node* next;
} Node;


Node* listInit(Node* head);
void printList(Node* head);
Node* insert(Node* head, int value1, int value2);
void delete(Node* head, Node* target);

Node* worstAlloc(char* buf, char ch, int size);
void worstFree(Node* target);