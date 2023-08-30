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

//链式栈结构
typedef struct ListStack
{
	Node* top; //栈顶节点
	size_t cnt; //数量
}ListStack;

//创建栈结构
ListStack* create_list_stack(void)
{
	ListStack* stack=malloc(sizeof(ListStack));
	stack->top=NULL;
	stack->cnt=0;
	return stack;
}

//入栈
void push_list_stack(ListStack* stack,TYPE data)
{
	Node* node=create_node(data);
	node->next=stack->top;
	stack->top=node;
	stack->cnt++;
}

//栈空
bool empty_list_stack(ListStack* stack)
{
	return 0==stack->cnt;
}

//栈顶
TYPE top_list_stack(ListStack* stack)
{
	if(!empty_list_stack(stack)) return stack->top->data;
}

//出栈
void pop_list_stack(ListStack* stack)
{	
	if(!empty_list_stack(stack))
	{
		Node* temp=stack->top;
		stack->top=temp->next;
		free(temp);
		stack->cnt--;
	}
}

//数量
size_t size_list_stack(ListStack* stack)
{
	return stack->cnt;
}

//销毁
void destroy_list_stack(ListStack* stack)
{	
	while(!empty_list_stack(stack)) pop_list_stack(stack);
	free(stack);
}


int main(int argc,const char* argv[])
{
	
	return 0;
}
