/* Best Fit Memory Allocation */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c 에 있는 전역변수 사용
extern Node* allocHead;		// 할당된 공간 리스트
extern Node* emptyHead;		// 빈 공간 리스트


// Best Fit Memory Allocation
// buf 안에 size만큼 문자(ch) 할당
Node* bestAlloc(char* buf, char ch, int size) {

	Node* i;
	Node* bestNode = NULL;
	Node* newNode = NULL;
	int gap = BUF_SIZE;

	// 요청 크기에 가장 알맞은 공간 탐색
	// gap이 가장 작은 노드가 bestNode로 선택된다.
	for(i=emptyHead->next; i!=emptyHead; i=i->next) {
		// 빈 공간이 요청한 공간보다 크고, gap이 이전의 gap보다 작다면
		if((i->size >= size) && (i->size - size < gap)) {
			gap = i->size - size;	// gap 갱신
			bestNode = i;			// bestNode 갱신
		}
	}

	if(bestNode == NULL) {	// bestNode를 못 찾았으면 에러 출력 후 종료.
		fprintf(stdout, "[*] bestAlloc() : 적절한 공간을 찾지 못하였습니다.\n");
		return 1;
	}
	else {	// 찾았으면 할당
		memset((void*)bestNode->addr, ch, size);

		// 할당된 공간 리스트에 추가
		newNode = insert(allocHead, bestNode->addr, size);

		// 할당된 공간으로 인하여, 비어있는 공간 리스트를 수정하는 작업
		insert(emptyHead, bestNode->addr+size, (bestNode->size) - size);
		delete(emptyHead, bestNode);
	}

	return newNode;	// 새로 추가된 노드 주소 반환
}