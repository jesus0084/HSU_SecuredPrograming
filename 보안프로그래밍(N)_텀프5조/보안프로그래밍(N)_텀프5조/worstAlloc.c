/* Worst Fit Memory Allocation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c 에 있는 전역변수 사용
extern Node* allocHead;		// 할당된 공간 리스트
extern Node* emptyHead;		// 빈 공간 리스트


// Worst Fit Memory Allocation
// buf 안에 size만큼 문자(ch) 할당
Node* worstAlloc(char* buf, char ch, int size) {
	
	Node* i;
	Node* worstNode = NULL;
	Node* newNode = NULL;
	
	// worstNode 초기값 설정
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if(i->size >= size) {
			worstNode = i;
			break;
		}
	}
	if(worstNode == NULL) {	// worstNode를 못 찾았으면 에러 출력 후 종료.
		fprintf(stdout, "[*] worstAlloc() : 적절한 공간을 찾지 못하였습니다.\n");
		return 1;
	}

	// 요청에 맞는 가장 큰 공간 탐색
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		if((i->size >= size) && (i->size > worstNode->size)) {
			worstNode = i;
		}
	}
	
	// 찾았으면 할당
	memset((void*)worstNode->addr, ch, size);

	// 할당된 공간 리스트에 추가
	newNode = insert(allocHead, worstNode->addr, size);

	// 할당된 공간으로 인하여, 빈 공간 리스트를 수정하는 작업
	// 만약 메모리공간이 꽉 찼다면 노드 삭제만 실행.
	if((worstNode->addr + size) - (int)buf < BUF_SIZE)
		insert(emptyHead, worstNode->addr + size, (worstNode->size) - size);
	delete(emptyHead, worstNode);

	return newNode;	// 새로 추가된 노드 주소 반환
}


