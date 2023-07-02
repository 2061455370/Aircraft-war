#pragma once
struct vector {
	bool (*append)(vector* pVec, void* date);
	void* (*get)(vector* pVec, int index);
	void (*clear)(vector* pVec);
	void (*remove)(vector* pVec, int index);

	void** pDate;
	int size;
	int capacity;
};

void vectorInit(vector* pVec);
void vectorDestroy(vector* pVec);