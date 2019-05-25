#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

Node* allocHead;		// �Ҵ�� ���� ����Ʈ
Node* emptyHead;		// �� ���� ����Ʈ


// buf ���� ��� �Լ�
void printBuf(char* buf) {
	for(int i=0; i<BUF_SIZE;i++)
		printf("%c ", buf[i]);
	printf("\n");
}

// �Ҵ�, ���Ҵ� ����Ʈ ���
void printListAll(Node* allocHead, Node* emptyList, char* buf) {
	printf("�Ҵ�� ���� ����Ʈ : "); printList(allocHead, buf);
	printf("�� ���� ����Ʈ : "); printList(emptyHead, buf);
}

// �޴� ���
void printMenu() {
	printf("\n---------������ ��� ����---------\n");
	printf("| 1. Worst-Fit �Ҵ�\t\t |\n");
	printf("| 2. Best-Fit �Ҵ�\t\t |\n");
	printf("| 3. �Ҵ� ����\t\t\t |\n");
	printf("| 4. �޸� ����\t\t |\n");
	printf("| 5. ����\t\t\t |\n");
	printf("----------------------------------\n");
}


// MAIN
int main() {

	// ����Ʈ�� �޸� �Ҵ� �� �ʱ�ȭ
	allocHead = (Node*)malloc(sizeof(Node));
	emptyHead = (Node*)malloc(sizeof(Node));
	allocHead = listInit(allocHead);
	emptyHead = listInit(emptyHead);

	char buf[BUF_SIZE];						// �Ҵ翡 ���� �޸� ����
	memset(buf, '-', BUF_SIZE);				// �� ������ ���� '-'���� ����.
	insert(emptyHead, (int)buf, BUF_SIZE);	// ó���� buf ��ü�� �� �����̴�.

	char choice, ch;
	int n, addr;
	Node* target;
	printf("########################################\n");
	printf("### �������α׷���(N) 5�� ��������Ʈ ###\n");
	printf("########################################\n");

	while(1) {
		printf("\n< ���� �޸� ���� >\n");
		printBuf(buf);								// �޸� ���� ���
		printListAll(allocHead, emptyHead, buf);	// ����Ʈ ���
		printMenu();								// �޴� ���
		printf(">> ");
		choice = fgetc(stdin); while(getchar() != '\n');	// �Է°� �ޱ�

		switch(choice) {
		case '1':
			printf("[����] [����] �Է� >> ");
			scanf("%c %d", &ch, &n); while(getchar() != '\n');
			worstAlloc(buf, ch, n);
			break;

		case '2':
			printf("[����] [����] �Է� >> ");
			scanf("%c %d", &ch, &n); while(getchar() != '\n');
			bestAlloc(buf, ch, n); 
			break;

		case '3':
			printf("[������ �ּҰ�] �ҹ��ڷ� �Է� >> ");
			scanf("%x", &addr); while(getchar() != '\n');	// �ҹ��ڷ� �Է��ؾ� ��.
			target = (Node*)addr;
			myFree(target);
			break;

		case '4':
			memoryOpt(buf, allocHead, emptyHead);
			break;

		case '5':
			printf("���α׷��� �����մϴ�.\n");
			exit(0);

		default:
			printf("[*] �ùٸ� ���� �Է��ϼ���.\n");
		}
	}

	/* worstFit �׽�Ʈ �κ�
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
	printList(allocHead);
	printList(emptyHead);

	memoryOpt(buf, allocHead, emptyHead);

	printBuf(buf);
	printList(allocHead);
	printList(emptyHead);
	*/
}