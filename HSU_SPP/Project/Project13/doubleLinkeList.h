#pragma once

#define TRUE 1
#define FALSE 0

typedef struct Node {	// ��� Ÿ��
	int size;
	struct Node* prev;
	struct Node* next;
} Node;


Node* listInit(Node* head);
void printList(Node* head);
void insert(Node* head, int value);
void delete(Node* head, Node* target);