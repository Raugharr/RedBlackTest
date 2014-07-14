/*
 * File: main.c
 * Author: David Brotz
 */

#include "RBTree.h"

#include <stdlib.h>
#include <time.h>

#define SIZE (1024)

int Call(const int* _One, const int* _Two) {
	return (*_One) - (*_Two);
}

int Test(int* _Data) {
	return 0;
}

void IntDestroy(int* _Int) {
	free(_Int);
}

int Incremental() {
	struct RBTree* _Tree = CreateRBTree((int(*)(const void*, const void*))Call, (int(*)(const void*, const void*))Call);
	int i;
	int* _Array[SIZE];

	for(i = 0; i < SIZE; ++i) {
		_Array[i] = malloc(sizeof(int));
		*_Array[i] = i + 1;
	}

	for(i = 0; i < SIZE; ++i) {
		RBInsert(_Tree, _Array[i]);
		if(RBColorCheck(_Tree->Table) == 0)
			return 0;
	}
	RBIterate(_Tree, ((int(*)(void*))Test));
	RBRemoveAll(_Tree, (void(*)(void*))IntDestroy);
	DestroyRBTree(_Tree);
	return 1;
}

int Decremental() {
	struct RBTree* _Tree = CreateRBTree((int(*)(const void*, const void*))Call, (int(*)(const void*, const void*))Call);
	int i;
	int* _Array[SIZE];

	for(i = 0; i < SIZE; ++i) {
		_Array[i] = malloc(sizeof(int));
		*_Array[i] = i + 1;
	}
	for(i = SIZE - 1; i >= 0 ; --i) {
		RBInsert(_Tree, _Array[i]);
		if(RBColorCheck(_Tree->Table) == 0)
			return 0;
	}
	RBIterate(_Tree, ((int(*)(void*))Test));
	RBRemoveAll(_Tree, (void(*)(void*))IntDestroy);
	DestroyRBTree(_Tree);
	return 1;
}

int RandomTree() {
	struct RBTree* _Tree = CreateRBTree((int(*)(const void*, const void*))Call, (int(*)(const void*, const void*))Call);
	int i;
	int* _Array[SIZE];

	srand(time(NULL));
	for(i = 0; i < SIZE; ++i) {
		_Array[i] = malloc(sizeof(int));
		*_Array[i] = rand();
	}
	for(i = SIZE - 1; i >= 0 ; --i) {
		RBInsert(_Tree, _Array[i]);
		if(RBColorCheck(_Tree->Table) == 0)
			return 0;
	}
	RBIterate(_Tree, ((int(*)(void*))Test));
	RBRemoveAll(_Tree, (void(*)(void*))IntDestroy);
	DestroyRBTree(_Tree);
	return 1;
}

int main(int argc, char** argv) {
	int i;

	if(Incremental() == 0)
		return 1;
	if(Decremental() == 0)
		return 1;
	for(i = 0; i < 100; ++i)
		if(RandomTree() == 0)
			return 1;
	return 0;
}
