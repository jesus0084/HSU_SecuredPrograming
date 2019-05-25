/* Memory Freeing */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

// main.c �� �ִ� �������� ���
extern Node* allocHead;		// �Ҵ�� ���� ����Ʈ
extern Node* emptyHead;		// �� ���� ����Ʈ


// Memory Freeing
// buf �ȿ� �Ҵ�� �޸� ���� ��ȯ
void myFree(Node* target) {
	Node* i;
	Node* freedTarget = NULL;
	int targetCheck = FALSE;

	// �Ҵ�� ���� ����Ʈ�� target�� �ִ��� �˻�
	for(i=allocHead->next; i!=allocHead; i=i->next) {
		if(target == i) {
			targetCheck = TRUE;
			break;
		}
	}
	if(i == allocHead) {	// worstAlloc()���� �Ҵ�� ������ �ƴϸ� ���� ��� �� ����
		fprintf(stdout, "[*] myFree() : �ش� �ּ��� �Ҵ�� ������ �������� �ʽ��ϴ�.\n");
		return;
	}
	else {
		memset((void*)target->addr, '-', target->size);
		// ����ִ� ���� ����Ʈ�� target �߰�
		freedTarget = insert(emptyHead, target->addr, target->size);
		// �Ҵ�� ���� ����Ʈ���� target ����
		delete(allocHead, target);
	}

	// free�� target��, buf�� ������ ������ ��ġ�� ����
	for(i=freedTarget->next; i != freedTarget; i = i->next) {
		// ������ �� ������ freedTarget �տ� ��ġ�� ��
		if(i->addr + i->size == freedTarget->addr) {
			insert(emptyHead, i->addr, i->size + freedTarget->size);	// ��ģ ������ �� ���� ����Ʈ�� �߰�
																		// ������ �� ���� ��� ����
			delete(emptyHead, i);
			delete(emptyHead, freedTarget);
			printf("[+] ��� ������\n");
			break;
		}
		// ������ �� ������ freedTarget �ڿ� ��ġ�� ��
		else if(freedTarget->addr + freedTarget->size == i->addr) {
			insert(emptyHead, freedTarget->addr, freedTarget->size + i->size);	// ��ģ ������ �� ���� ����Ʈ�� �߰�
																				// ������ �� ���� ��� ����
			delete(emptyHead, i);
			delete(emptyHead, freedTarget);
			printf("[+] ��� ������\n");
			break;
		}
	}
}