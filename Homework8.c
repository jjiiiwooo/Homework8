#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define MAX_HEAP_SIZE 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_HEAP_SIZE];
	int heap_size;
}HeapType;

element stack[MAX_HEAP_SIZE];

//���� �Լ� 
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

//�ʱ�ȭ �Լ� 
void init(HeapType* h) {
	h->heap_size = 0;
}

//�ִ� ���� �����Լ� 
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

//�ִ� ���� ���� �Լ� 
void delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child * 2;
	}
	h->heap[parent] = temp;
	return item;
}


//�� ����
void heap_sort(element a[], int n)
{
	int i;
	HeapType* h;
	h = create();
	init(h);
	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--) {

		a[i] = delete_max_heap(h);
	}
	free(h);
}

//��� 




int main(void)
{
	element list[SIZE] = { 34,12,76,59,32,55,88,16,79,34,85,29,78,41,56,86 };
	element temp[SIZE];
	heap_sort(list, SIZE);
	printf("<����>\n");
	
	
	for (int i = 0; i < SIZE; i++) {
		printf("%d", list[i].key);
	}

	return 0;


}