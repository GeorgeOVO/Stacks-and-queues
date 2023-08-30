#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int

typedef struct ArrayStack
{
	TYPE* ptr;	//存储元素首地址
	size_t cal; //容量
	size_t top; //栈顶位置
}ArrayStack;

// 创建
ArrayStack* create_array_stack(size_t cal)
{
	ArrayStack* stack=malloc(sizeof(ArrayStack));
	stack->ptr=malloc(sizeof(TYPE)*cal);
	stack->cal=cal;
	stack->top=0;
	return stack;
}

//栈满
bool full_array_stack(ArrayStack* stack)
{
	return stack->top==stack->cal;
}

//栈空
bool empty_array_stack(ArrayStack* stack)
{
	return 0==stack->top;
}

//入栈
bool push_array_stack(ArrayStack* stack,TYPE data)
{
	if(full_array_stack(stack)) return false;
	stack->ptr[stack->top++]=data;
	return true;
}

//查看栈顶元素
TYPE top_array_stack(ArrayStack* stack)
{
   if(!empty_array_stack(stack)) return stack->ptr[stack->top-1];
}

//出栈
bool pop_array_stack(ArrayStack* stack)
{
	if(empty_array_stack(stack)) return false;
	stack->top--;
	return true;
}

//销毁
void destroy_array_stack(ArrayStack* stack)
{
	free(stack->ptr);
	free(stack);
}

//判断b是否a的出栈顺序  (a、b在main函数里)
bool is_pop_stack(const int* a,const int* b,size_t len)
{
	//创建栈
	ArrayStack* stack=create_array_stack(len);
	//按照a的顺序入栈
	for(int i=0,j=0;i<len;i++)
	{
		push_array_stack(stack,a[i]);
		//按照b的顺序尝试出栈
		while(!empty_array_stack(stack)&&b[j]==top_array_stack(stack))
		{
			pop_array_stack(stack);
			j++;
		}
	}
	bool flag=empty_array_stack(stack);
	destroy_array_stack(stack);
	return flag;
}

//数量
size_t size_array_stack(ArrayStack* stack)
{
	return stack->top;
}

int main(int argc,const char* argv[])
{
	int a[5]={1,2,3,4,5};
	int b[5]={1,2,4,5,3};
	printf("%d",is_pop_stack(a,b,5));
	return 0;
}
