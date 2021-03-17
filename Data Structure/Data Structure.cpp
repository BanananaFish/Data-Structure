// Data Structure.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>

#define sqListMaxSize 10
#define sqMaxSize 10
#define initSize 10

typedef struct {
	int data[sqListMaxSize];
	int length;
}SqList;

typedef struct {
	int* data;
	int maxSize;
	int length;
}SeqList;

void initList(SqList &L) {
	for (int i = 0; i < sqMaxSize; i++)
		L.data[i] = 0;
	L.length = 0;
}

void initSeqList(SeqList& L) {
	L.data = (int*)malloc(initSize * sizeof(int));
	L.length = 0;
	L.maxSize = initSize;
}

void increaseSize(SeqList& L, int len) {
	int* p = L.data;
	L.data = (int*)malloc((L.maxSize + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];
	}
	L.maxSize = L.maxSize + len;
	free(p);
}

int main()
{
	SqList L;
	initList(L);
	L.data[0] = 123;
	printf("data[%d]:%d", 0, L.data[0]);
	
	return 0;
}

