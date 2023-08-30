#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int 

typedef struct ArrayQueue
{
	TYPE* ptr;
	size_t cal;
	size_t front; //队头
	size_t rear;  //队尾
	size_t cnt;
}ArrayQueue;

ArrayQueue* create_array_queue(size_t cal)
{
	ArrayQueue* queue=malloc(sizeof(ArrayQueue));
	queue->ptr=malloc(sizeof(TYPE)*cal);
	queue->cal=cal;
	queue->front=0;
	queue->rear=0;
	queue->cnt=0;
	return queue;
}

//判断队空
bool empty_array_queue(ArrayQueue* queue)
{
	return 0 == queue->cnt;
}

//判断队满
bool full_array_queue(ArrayQueue* queue)
{
	return queue->cal==queue->cnt;
}

//入队
bool push_array_queue(ArrayQueue* queue,TYPE data)
{
	if(full_array_queue(queue)) return false;
	queue->ptr[queue->rear]=data;
	queue->rear=(queue->rear+1)%queue->cal;
	queue->cnt++;
	return true;
}

//出队
bool pop_array_queue(ArrayQueue* queue)
{
	if(empty_array_queue(queue)) return false;
	queue->front=(queue->front+1)%queue->cal;
	queue->cnt--;
	return true;
}

//队头
TYPE front_array_queue(ArrayQueue* queue)
{
	return queue->ptr[queue->front];
}

//队尾
TYPE rear_array_queue(ArrayQueue* queue)
{
	return queue->ptr[(queue->rear-1+queue->cal)%queue->cal];
}

//数量
size_t size_array_queue(ArrayQueue* queue)
{
	return queue->cnt;
}

//销毁
void destroy_array_queue(ArrayQueue* queue)
{
	free(queue->ptr);
	free(queue);
}



int main(int argc,const char* argv[])
{
	ArrayQueue* queue=create_array_queue(10);
	for(int i=0;i<10;i++)
	{
		push_array_queue(queue,i+10);
		printf("rear:%d size:%d\n",rear_array_queue(queue),size_array_queue(queue));
		pop_array_queue(queue);
		printf("rear:%d size:%d\n",rear_array_queue(queue),size_array_queue(queue));
	}
	return 0;
}
