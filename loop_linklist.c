#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	int flag;
	struct node* next;
};
 
struct node *newNode(int key)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
	temp->flag = 0;
    temp->next = NULL;
    return temp;
}

void checkloop(struct node *node)
{
    while (node != NULL)
    {
node->flag = 1;
        printf("%d  ", node->data);
        if (node->next->flag == 1)
	{
        printf("from %d  ", node->data);
        printf("to %d  ", node->next->data);
	break;
	}
node=node->next;
    }
}
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
}

int main()
{
	
	struct node *head = newNode(50);
	head->next = newNode(20);
	head->next->next = newNode(15);
    	head->next->next->next = newNode(4);
    	head->next->next->next->next = newNode(10);
	head->next->next->next->next->next = head->next->next->next->next;
	checkloop(head);
//	printList(head);
}


