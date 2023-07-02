#include "Library.h"
#include <stdlib.h>

bool vectorAppend(struct vector* pVec, void* data)
{
	if (pVec == NULL || data == NULL)
		return false;

	//  是否超长
	if (pVec->size >= pVec->capacity)
	{
		//  加长到两倍
		void** newData = (void**)realloc(pVec->pDate, pVec->capacity * sizeof(void*) * 2);
		if (newData == NULL)
		{
			return false;
		}
		pVec->pDate = newData;
		pVec->capacity = 2 * pVec->capacity;
	}

	pVec->pDate[pVec->size] = data;
	pVec->size++;
	return true;
}

void* vectorGet(struct vector* pVec, int index)
{
	if (index >= pVec->size)
		return NULL;
	return pVec->pDate[index];
}

void vectorRemove(struct vector* pVec, int index)
{
	for (int i = index; i < pVec->size - 1; i++)
		pVec->pDate[i] = pVec->pDate[i + 1];
	pVec->size -= 1;
}

void vectorClear(struct vector* pVec)
{
	if (pVec->pDate != NULL)
		free(pVec->pDate);

	pVec->pDate = (void**)malloc(sizeof(void*) * VECTOR_INIT_CAPACITY);
	pVec->capacity = VECTOR_INIT_CAPACITY;
	pVec->size = 0;
}

void vectorInit(struct vector* pVec)
{
	pVec->get = vectorGet;
	pVec->append = vectorAppend;
	pVec->remove = vectorRemove;
	pVec->clear = vectorClear;

	//  初始情况下申请VECTOR_INIT_CAPACITY个element
	pVec->pDate = (void**)malloc(sizeof(void*) * VECTOR_INIT_CAPACITY);
	pVec->capacity = VECTOR_INIT_CAPACITY;
	pVec->size = 0;
}

void vectorDestroy(struct vector* pVec)
{
	if (pVec->pDate == NULL)
		return;
	free(pVec->pDate);
	pVec->pDate = NULL;
	pVec->size = 0;
	pVec->capacity = 0;
}