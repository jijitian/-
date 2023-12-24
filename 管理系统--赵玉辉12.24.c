#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("**************学生管理系统**************\n");
	printf("1.添加信息 2.删除信息 3.修改信息 4.查找信息 5.全部信息 6.退出系统\n");
	printf("***************************************\n");
}
void choice() 
{
	int choice;
	printf("请输入你的操作选项: ");
	scanf_s("%d", &choice);
	switch (choice) 
	{
	case 1:
		printf("---------------添加信息---------------\n");
		break;
	case 2:
		printf("---------------删除信息---------------\n");
		break;
	case 3:
		printf("---------------修改信息---------------\n");
		break;
	case 4:
		printf("---------------查找信息---------------\n");
		break;
	case 5:
		printf("---------------全部信息---------------\n");
		break;
	case 6:
		printf("退出成功\n");
		exit(0);//0正常退出，1异常退出
		break;
	default:
		printf("暂时还没有该功能，重选！\n");
		system("pause");//页面停留
		break;
	}
}
struct student
{
	char Name[20];
	int ID;
	int Age;
	char Sex[10];
	char Tel[20];
};
struct Node
{
	int data;
	struct Node* next;
}; 
struct Node* createList()//链表表头
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//动态内存申请
	headNode->next = NULL;
	return headNode;
}
struct Node* createNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}
void insertNode(struct Node* headNode, int data)
{
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}
void deleteNode(struct Node* headNode, int Data)
{
	struct Node* The_Node= headNode->next;
	struct Node* front_Node = headNode;
	if (The_Node == NULL) 
	{
		printf("空,无法删除");
		return;
	}
	while (The_Node->data != Data) 
	{
		front_Node = The_Node;
		The_Node = front_Node->next;
		if (The_Node == NULL)
		{
			printf("无法删除");
			return;
		}
	}
	front_Node->next = The_Node->next;
	free(The_Node);
}
void printList(struct Node* headNode)//打印链表,书316页。
{
	struct Node* p = headNode->next;
	while(p)
	{
		printf("%d->",p->data);
		p = p->next;
	}
	printf("\n");
}
int main() 
{
	//
	//while(1)
	//{
	//	menu();
	//	choice();
	//	system("pause");
	//	system("cls");//清屏
	//}
	//
	struct Node* list = createList();
	insertNode(list, 1);
	insertNode(list, 2);
	insertNode(list, 3);
	insertNode(list, 4);
	printList(list);
	system("pause");
	return 0;
}
