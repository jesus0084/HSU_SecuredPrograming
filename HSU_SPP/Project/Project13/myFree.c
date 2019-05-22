/* Worst Fit Memory Freeing */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c 에 있는 전역변수 사용
extern Node* allocHead;		// 할당된 공간 리스트
extern Node* emptyHead;		// 비어있는 공간 리스트


// Worst Fit Memory Freeing
// buf 안에 할당된 메모리 공간 반환
void myFree(Node* target) {
	Node* i;
	Node* freedTarget = NULL;
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
		memset((void*)target->addr, '-', target->size);
		// 비어있는 공간 리스트에 target 추가
		freedTarget = insert(emptyHead, target->addr, target->size);
		// 할당된 공간 리스트에서 target 삭제
		delete(allocHead, target);
	}

	// free된 target과, buf상 인접한 공간을 합치는 과정
	for(i=freedTarget->next; i != freedTarget; i = i->next) {
		// 인접한 빈 공간이 freedTarget 앞에 위치할 때
		if(i->addr + i->size == freedTarget->addr) {
			insert(emptyHead, i->addr, i->size + freedTarget->size);	// 합친 공간을 빈 공간 리스트에 추가
																		// 합쳐진 두 개의 노드 삭제
			delete(emptyHead, i);
			delete(emptyHead, freedTarget);
			printf("노드합쳐짐\n");
			break;
		}
		// 인접한 빈 공간이 freedTarget 뒤에 위치할 때
		else if(freedTarget->addr + freedTarget->size == i->addr) {
			insert(emptyHead, freedTarget->addr, freedTarget->size + i->size);	// 합친 공간을 빈 공간 리스트에 추가
																				// 합쳐진 두 개의 노드 삭제
			delete(emptyHead, i);
			delete(emptyHead, freedTarget);
			printf("노드합쳐짐\n");
			break;
		}
	}
}