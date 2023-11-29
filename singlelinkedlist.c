#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node * NODE;

NODE head = NULL;


// insert at end
void insertatend(int x)
{
    NODE newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if( head == NULL )
    {
        head = newnode;
        return;
    }

    NODE temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

}

// insert at front
void inseratfront(int x)
{
    NODE newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;


    newnode->next = head;
    head = newnode;

}


// delete at front
void deleteatfront()
{
    if(head == NULL)
    {
        printf("Deletion is not possible because list is empty\n");
        return;
    }

    printf("Deleted element is %d\n", head->data);
    head = head->next;

}

// delete at end
void deleteatend()
{
    if(head == NULL)
    {
        printf("Deletion is not possible because list is empty\n");
        return;
    }

    if(head->next == NULL)
    {
        printf("Deleted element is %d\n", head->data);
        head = NULL;
        return;
    }

    NODE temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    printf("Deleted element is %d\n", temp->next->data);
    temp->next = NULL;

}


// transversal
void transversal()
{
    if(head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    NODE temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp= temp->next;
    }

    printf("NULL\n");

}


void insertAtPosition(int pos, int x) 
{
	if(pos <= 0)
	{
		printf("No such position in SLL so inserton is not possible\n");
		return ;
	}
	
    NODE prevpos = head ; 
    NODE curr = head ;
	
	for(int i = 1 ; i< pos ;i++ )
	{
		if(curr == NULL)
		{
			printf("No such position in SLL so insertion is not possible\n");
			return ;
		}
		prevpos = curr;
		curr = curr->next;
	}
	
	NODE temp =  malloc(sizeof( struct node));
    temp->data = x;
    temp->next = NULL;

	if( pos ==1 )
	{
		temp->next = head;
		head = temp;
        return ;
	}

    temp->next = prevpos->next;
    prevpos->next = temp;

}







int main()
{
    insertatend(10);
    insertatend(20);
    inseratfront(30);
    insertatend(40);
    deleteatend();
    deleteatfront();
    transversal();
}