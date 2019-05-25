#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

Node* allocHead;		// 할당된 공간 리스트
Node* emptyHead;		// 빈 공간 리스트


// buf 내용 출력 함수
void printBuf(char* buf) {
	for(int i=0; i<BUF_SIZE;i++)
		printf("%c ", buf[i]);
	printf("\n");
}

// 할당, 비할당 리스트 출력
void printListAll(Node* allocHead, Node* emptyList, char* buf) {
	printf("할당된 공간 리스트 : "); printList(allocHead, buf);
	printf("빈 공간 리스트 : "); printList(emptyHead, buf);
}

// 메뉴 출력
void printMenu() {
	printf("\n---------수행할 기능 선택---------\n");
	printf("| 1. Worst-Fit 할당\t\t |\n");
	printf("| 2. Best-Fit 할당\t\t |\n");
	printf("| 3. 할당 해제\t\t\t |\n");
	printf("| 4. 메모리 정리\t\t |\n");
	printf("| 5. 종료\t\t\t |\n");
	printf("----------------------------------\n");
}


// MAIN
int main() {

	// 리스트에 메모리 할당 및 초기화
	allocHead = (Node*)malloc(sizeof(Node));
	emptyHead = (Node*)malloc(sizeof(Node));
	allocHead = listInit(allocHead);
	emptyHead = listInit(emptyHead);

	char buf[BUF_SIZE];						// 할당에 쓰일 메모리 공간
	memset(buf, '-', BUF_SIZE);				// 빈 공간은 문자 '-'으로 세팅.
	insert(emptyHead, (int)buf, BUF_SIZE);	// 처음엔 buf 전체가 빈 공간이다.

	char choice, ch;
	int n, addr;
	Node* target;
	printf("########################################\n");
	printf("### 보안프로그래밍(N) 5조 텀프로젝트 ###\n");
	printf("########################################\n");

	while(1) {
		printf("\n< 현재 메모리 상태 >\n");
		printBuf(buf);								// 메모리 공간 출력
		printListAll(allocHead, emptyHead, buf);	// 리스트 출력
		printMenu();								// 메뉴 출력
		printf(">> ");
		choice = fgetc(stdin); while(getchar() != '\n');	// 입력값 받기

		switch(choice) {
		case '1':
			printf("[문자] [개수] 입력 >> ");
			scanf("%c %d", &ch, &n); while(getchar() != '\n');
			worstAlloc(buf, ch, n);
			break;

		case '2':
			printf("[문자] [개수] 입력 >> ");
			scanf("%c %d", &ch, &n); while(getchar() != '\n');
			bestAlloc(buf, ch, n); 
			break;

		case '3':
			printf("[삭제할 주소값] 소문자로 입력 >> ");
			scanf("%x", &addr); while(getchar() != '\n');	// 소문자로 입력해야 함.
			target = (Node*)addr;
			myFree(target);
			break;

		case '4':
			memoryOpt(buf, allocHead, emptyHead);
			break;

		case '5':
			printf("프로그램을 종료합니다.\n");
			exit(0);

		default:
			printf("[*] 올바른 값을 입력하세요.\n");
		}
	}

	/* worstFit 테스트 부분
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