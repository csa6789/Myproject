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
		ptr = top;		//指向堆栈的顶端
		top = top->next;	//将堆栈顶端的指针指向下一个节点
		temp = ptr->data;	//取出堆栈的数据
		free(ptr);			//将节点占用的内存释放
		return temp;

	}
}

int main(void)
{
	int value;
	int i;
	cout << "请按序输入10个数据:" << endl;
	for (i = 0; i<10; i++)
	{
		cin >> value;
		push(value);
	}
	cout << "====================" << endl;
	while (!isEmpty()) //将数据陆续从顶端弹出
		cout << "堆栈弹出的顺序为:" << setw(2) << pop() << endl;
	cout << "====================" << endl;
	system("pause");
	return 0;
}
