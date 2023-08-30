#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TYPE int

//带头节点的链表
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

//头添加
void add_head_list(Node* head,TYPE data)
{
	Node* node=create_node(data);
	node->next=head->next;
	head->next=node;
}

//尾添加
void add_tail_list(Node* head,TYPE data)
{
	Node* node=create_node(data);

	//找最后一个节点
	Node* n=head;
	while(NULL!=n->next) n=n->next;
	n->next=node;
}

//按位置删除
bool del_index_list(Node* head,size_t index)
{
	//找待删除节点的上一个节点
	Node* n=head;
	for(int i=0;i<index;i++)
	{
		n=n->next;
		if(NULL==n) return false;
	}
	if(NULL==n->next) return false;

	Node* temp=n->next;
	n->next=temp->next;
	free(temp);
	return true;
}

//按值删除
bool del_value_list(Node* head,TYPE val)
{
	Node* n=head;
	while(NULL!=n->next)
	{
		if(val==n->next->data)
		{
			Node* temp=n->next;
			n->next=temp->next;
			free(temp);
			return true;
		}
		n=n->next;
	}
	return false;	
}

//插入
bool insert_list(Node* head,size_t index,TYPE data)
{
	Node* n=head;
	for(int i=0;i<index;i++)
	{
		n=n->next;
		if(NULL==n) return false;
	}
	Node* node=create_node(data);
	node->next=n->next;
	n->next=node;
	return true;
}

//修改
bool modify_list(Node* head,TYPE old,TYPE data)
{
	Node* n=head->next;
	while(NULL!=n)
	{
		if(old==n->data)
		{
			n->data=data;
			return true;
		}
		n=n->next;
	}
	return false;
}

//访问
bool access_list(Node* head,size_t index,TYPE* data)
{	
	int i=0;
	for(Node* n=head->next;n;n=n->next,i++)
	{
		if(i==index)
		{
			* data=n->data;
			return true;
		}
	}
	return false;
}

//查询
int query_list(Node* head,TYPE data)
{
	Node* n=head->next;
	for(int i=0;n;i++,n=n->next)
	{
		if(data==n->data) return i;
	}
	return -1;
}

//排序
void sort_list(Node* head)
{
	for(Node* i=head->next;i->next;i=i->next)
	{
		for(Node* j=i->next;j;j=j->next)
		{
			if(i->data<j->data)
			{
				TYPE temp=i->data;
				i->data=j->data;
				j->data=temp;
			}
		}
	}
}


//遍历
void show_list(Node* head)
{
	for(Node* n=head->next;n;n=n->next)
	{
		printf("%d ",n->data);
	}
	printf("\n");
}


int main(int argc,const char* argv[])
{
	Node* head=create_node(100);  //创建头节点,头节点不存储有效数据，里面的数据是多少无所谓	
	for(int i = 0;i < 10; i++)
	{
		add_tail_list(head,i+1);
	}
	show_list(head);
	return 0;
}
