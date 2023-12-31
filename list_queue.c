#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int

typedef struct Node
{
	TYPE data;
	struct Node* next;
}Node;

Node* create_node(TYPE data)
{
	Node* node=malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	return node;
}

typedef struct ListQueue
{
	Node* front;
	Node* rear;
	size_t cnt;
}ListQueue;

//创建
ListQueue* create_list_queue(void)
{
	ListQueue* queue=malloc(sizeof(ListQueue));
	queue->front=NULL;
	queue->rear=NULL;
	queue->cnt=0;
	return queue;
}

//队空
bool empty_list_queue(ListQueue* queue)
{
	return 0==queue->cnt;
}

//入队
void push_list_queue(ListQueue* queue,TYPE data)
{
	Node* node=create_node(data);
	if(0==queue->cnt)
	{
		queue->front=node;
		queue->rear=node;
	}
	else
	{
		queue->rear->next=node;
		queue->rear=node;
	}
	queue->cnt++;
}

//出队
bool pop_list_queue(ListQueue* queue)
{
	if(empty_list_queue(queue)) return false;
	Node* temp=queue->front;
	queue->front=temp->next;
	free(temp);
	if(1==queue->cnt--) queue->rear=NULL;
	return true;
}

//队头
TYPE front_list_queue(ListQueue* queue)
{
	return queue->front->data;
}

//队尾
TYPE rear_list_queue(ListQueue* queue)
{
	return queue->rear->data;
}

//数量
size_t size_list_queue(ListQueue* queue)
{
	return queue->cnt;
}

//销毁
void destroy_list_queue(ListQueue* queue)
{
	while(pop_list_queue(queue));
	free(queue);
}

int main(int argc,const char* argv[])
{
	ListQueue* queue = create_list_queue();
	for(int i=0;i<10;i++)
	{
		push_list_queue(queue,i+10);
		printf("rear:%d size:%d\n",rear_list_queue(queue),size_list_queue(queue));
	}	
	return 0;
}
