#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

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
	memset(buf, '-', BUF_SIZE);				// �� ������ ���� '-'���� ����.
	insert(emptyHead, (int)buf, BUF_SIZE);	// ó���� buf ��ü�� �� �����̴�.


	// worstFit �׽�Ʈ �κ�
	Node* w1 = worstAlloc(buf, 'A', 5);
	Node* w2 = worstAlloc(buf, 'B', 5);
	Node* w3 = worstAlloc(buf, 'C', 5);

	printBuf(buf);

	myFree(w2);

	printBuf(buf);

	Node* w4 = worstAlloc(buf, 'D', 1);
	printBuf(buf);

	Node* w5 = worstAlloc(buf, 'E', 1);
	printBuf(buf);

	myFree(w4);

	Node* w6 = worstAlloc(buf, 'F', 1);
	myFree(w6);
	printBuf(buf);
	printList(emptyHead);
	
}