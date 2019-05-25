/* Memory Optimizer */
/* 할당된 공간들을 공백없이 앞으로 모아준다. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"


// 메모리 정리 함수
void memoryOpt(char* buf, Node* allocHead, Node* emptyHead) {

	// 할당된 공간 리스트가 비었거나, 빈 공간 리스트의 노드가 하나만 존재한다면
	// 메모리 최적화 할 필요가 없음
	if(allocHead->next == allocHead || emptyHead->next->next == emptyHead) {
		fprintf(stdout, "[+] memoryOpt() : 메모리가 깨끗한 상태입니다.\n");
		return;
	}

	// 할당된 공간의 값들을 저장할 임시 배열 선언 및 초기화
	char temp[BUF_SIZE];
	memset(temp, 0, BUF_SIZE);
	int sizeSum=0, sizeSum2=0;
	Node* nextNode = NULL;

	// 할당된 공간들을 합치는 과정
	for(Node* i=allocHead->next; i!=allocHead; i = nextNode) {
		nextNode = i->next;
		strncat(temp, (void*)i->addr, i->size);
		sizeSum = sizeSum + i->size;
		delete(allocHead, i);	// 합쳐졌으면, 해당 노드를 할당된 공간 리스트에서 삭제
	}
	// buf 초기화한 후에, 합쳐진 공간 복사
	memset(buf, '-', BUF_SIZE);
	strncpy(buf, temp, sizeSum);


	// 비어있는 공간들을 합치는 과정
	for(Node* i=emptyHead->next; i!=emptyHead; i = nextNode) {
		nextNode = i->next;
		sizeSum2 = sizeSum2 + i->size;
		delete(emptyHead, i);
	}
	// buf 초기화한 후에, 합쳐진 공간 복사
	memset(buf, '-', BUF_SIZE);
	strncpy(buf, temp, sizeSum);

	// 할당된 공간 리스트, 빈 공간 리스트 새로 작성
	insert(allocHead, (int)buf, sizeSum);
	insert(emptyHead, (int)(buf+sizeSum), sizeSum2);

	printf("[+] 메모리 정리 완료\n");
}