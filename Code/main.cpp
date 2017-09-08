#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

class Node
{
    public:
	int data;
	class Node *next;
};
typedef class Node Stack_Node;
typedef Stack_Node *Linked_Stack;
Linked_Stack top = NULL;

int isEmpty()
{
	if (top == NULL) return 1;
	else return 0;
}

void push(int data)
{
	Linked_Stack new_add_node;
	new_add_node = new Stack_Node;
	new_add_node->data = data;
	new_add_node->next = top;
	top = new_add_node;
}

int pop()
{
	Linked_Stack ptr;
	int temp;
	if (isEmpty())
	{
		cout << "===empty stack===" << endl;
		return -1;
	}
	else
	{
		ptr = top;		//ָ���ջ�Ķ���
		top = top->next;	//����ջ���˵�ָ��ָ����һ���ڵ�
		temp = ptr->data;	//ȡ����ջ������
		free(ptr);			//���ڵ�ռ�õ��ڴ��ͷ�
		return temp;

	}
}

int main(void)
{
	int value;
	int i;
	cout << "�밴������10������:" << endl;
	for (i = 0; i<10; i++)
	{
		cin >> value;
		push(value);
	}
	cout << "====================" << endl;
	while (!isEmpty()) //������½���Ӷ��˵���
		cout << "��ջ������˳��Ϊ:" << setw(2) << pop() << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}
