#include<stdio.h>
#include<stdlib.h>
void menu()
{
	printf("**************ѧ������ϵͳ**************\n");
	printf("1.�����Ϣ 2.ɾ����Ϣ 3.�޸���Ϣ 4.������Ϣ 5.ȫ����Ϣ 6.�˳�ϵͳ\n");
	printf("***************************************\n");
}
void choice() 
{
	int choice;
	printf("��������Ĳ���ѡ��: ");
	scanf_s("%d", &choice);
	switch (choice) 
	{
	case 1:
		printf("---------------�����Ϣ---------------\n");
		break;
	case 2:
		printf("---------------ɾ����Ϣ---------------\n");
		break;
	case 3:
		printf("---------------�޸���Ϣ---------------\n");
		break;
	case 4:
		printf("---------------������Ϣ---------------\n");
		break;
	case 5:
		printf("---------------ȫ����Ϣ---------------\n");
		break;
	case 6:
		printf("�˳��ɹ�\n");
		exit(0);//0�����˳���1�쳣�˳�
		break;
	default:
		printf("��ʱ��û�иù��ܣ���ѡ��\n");
		system("pause");//ҳ��ͣ��
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
struct Node* createList()//�����ͷ
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));//��̬�ڴ�����
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
		printf("��,�޷�ɾ��");
		return;
	}
	while (The_Node->data != Data) 
	{
		front_Node = The_Node;
		The_Node = front_Node->next;
		if (The_Node == NULL)
		{
			printf("�޷�ɾ��");
			return;
		}
	}
	front_Node->next = The_Node->next;
	free(The_Node);
}
void printList(struct Node* headNode)//��ӡ����,��316ҳ��
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
	//	system("cls");//����
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
