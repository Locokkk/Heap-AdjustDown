#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType *_a;
	int  _size;
	int _capacity;

}Heap;

void HeapInit(Heap *hp, HPDataType *a, int n)
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;
	//�����ɶ�
	for (int i = (n - 1 - 1) / 2;i >= 0;--i)//parent�ķ�Χ��ǰ�������
	{
		AdjustDown(hp->_a, hp->_size, i);
	}
}

void AdjustDown(HPDataType *a, size_t n, size_t parent)
{
	int child = parent * 2 + 1;//����
	
	while (child < n)
	{
		//ѡ��С���Ǹ����� child+1<n :��֤���Һ��� 
		if (child + 1 < n&&a[child] > a[child + 1])
		++child;//�����ӱ�Ϊ�Һ���

		if (a[parent] > a[child])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}





