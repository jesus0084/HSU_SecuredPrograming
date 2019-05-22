#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

Node* allocHead;		// 할당된 공간 리스트
Node* emptyHead;		// 비어있는 공간 리스트


// buf 내용 출력 함수
void printBuf(char* buf) {
	for(int i=0; i<BUF_SIZE;i++)
		printf("%c ", buf[i]);
	printf("\n\n");
}

int main() {

	// 리스트에 메모리 할당 및 초기화
	allocHead = (Node*)malloc(sizeof(Node));
	emptyHead = (Node*)malloc(sizeof(Node));
	allocHead = listInit(allocHead);
	emptyHead = listInit(emptyHead);

	char buf[BUF_SIZE];						// 할당에 쓰일 메모리 공간
	memset(buf, '-', BUF_SIZE);				// 빈 공간은 문자 '-'으로 세팅.
	insert(emptyHead, (int)buf, BUF_SIZE);	// 처음엔 buf 전체가 빈 공간이다.


	// worstFit 테스트 부분
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