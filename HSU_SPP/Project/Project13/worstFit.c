/* Worst Fit Memory Allocation & Free */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleLinkeList.h"

// main.c 에 있는 전역변수 사용
extern Node* allocHead;		// 할당된 공간 리스트
extern Node* emptyHead;		// 비어있는 공간 리스트


// Worst Fit Memory Allocation
// buf 안에 size만큼 문자(ch) 할당
Node* worstAlloc(char* buf, char ch, int size) {

	Node* i;
	Node* worstNode = NULL;
	Node* newNode = NULL;

	// 요청에 맞는 가장 큰 공간 탐색
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if(i->size > size)	// 빈 공간이 요청한 공간보다 크다면 
			worstNode = i;
	}

	if(worstNode == NULL) {	// worstNode를 못 찾았으면 에러 출력 후 종료.
		fprintf(stderr, "ERROR worstAlloc() : No suitable space\n");
		exit(1);
	}
	else {	// 찾았으면 할당
		memset((void*)worstNode->addr, ch, size);
		
		// 할당된 공간 리스트에 추가
		newNode = insert(allocHead, worstNode->addr, size);

		// 할당된 공간으로 인하여, 비어있는 공간 리스트를 수정하는 작업
		insert(emptyHead, worstNode->addr+size, (worstNode->size) - size);
		delete(emptyHead, worstNode);
	}
	
	return newNode;	// 새로 추가된 노드 주소 반환
}


// Worst Fit Memory Freeing
// buf 안에 할당된 메모리 공간 반환
void worstFree(Node* target) {
	Node* i;
	int targetCheck = FALSE;

	// 할당된 공간 리스트에 target이 있는지 검사
	for(i=allocHead->next; i!=allocHead; i=i->next) {
		if(target == i) {
			targetCheck = TRUE;
			break;
		}
	}
	if(i == allocHead) {	// worstAlloc()으로 할당된 공간이 아니면 오류 출력 후 종료
		fprintf(stderr, "ERROR worstFree() : Not the space allocated as worstAlloc()\n");
		exit(1);
	}
	else {
		memset(target->addr, '0', target->size);
		// 비어있는 공간 리스트에 target 추가
		insert(emptyHead, target->addr, target->size);
		// 할당된 공간 리스트에서 target 삭제
		delete(allocHead, target);
	}
}