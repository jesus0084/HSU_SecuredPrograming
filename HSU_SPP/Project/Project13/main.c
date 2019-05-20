#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkeList.h"

#define BUF_SIZE 100

Node* allocHead;		// �Ҵ�� ���� ����Ʈ
Node* emptyHead;		// ����ִ� ���� ����Ʈ


// buf ���� ��� �Լ�
void printBuf(char* buf) {
	for(int i=0; i<BUF_SIZE;i++)
		printf("%c ", buf[i]);
	printf("\n\n");
}

int main() {

	// ����Ʈ�� �޸� �Ҵ� �� �ʱ�ȭ
	allocHead = (Node*)malloc(sizeof(Node));
	emptyHead = (Node*)malloc(sizeof(Node));
	allocHead = listInit(allocHead);
	emptyHead = listInit(emptyHead);

	char buf[BUF_SIZE];						// �Ҵ翡 ���� �޸� ����
	memset(buf, '0', BUF_SIZE);				// �� ������ ���� '0'���� ����.
	insert(emptyHead, (int)buf, BUF_SIZE);	// ó���� buf ��ü�� �� �����̴�.


	// worstFit �׽�Ʈ �κ�
	Node* w1 = worstAlloc(buf, 'A', 5);	// 5Bytes �Ҵ��Ѵ�.
	Node* w2 = worstAlloc(buf, 'B', 5);	// 5Bytes �Ҵ��Ѵ�.
	Node* w3 = worstAlloc(buf, 'C', 5);	// 5Bytes �Ҵ��Ѵ�.
	
	printBuf(buf);

	worstFree(w2);	// w2 �Ҵ� ����

	printBuf(buf);
}