
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

void transversal()
{
    FILE* File = fopen("Linkedlist.txt", "w");
    if(head == NULL)
    {
        fprintf(File, "%s\n", "Linked list is empty\n");
        fclose(File);
        return;
    }

    NODE temp = head;

    while(temp != NULL)
    {
        fprintf( File ,"%d -> ", temp->data);
        temp= temp->next;
    }

    fprintf( File , "%s" , "NULL\n");


    fclose(File);


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






void deleteAtPosition(int pos) 
{
	if(pos<= 0)
	{
		printf("No such position in SLL so deletion is not possible\n");
		return ;
	}

	NODE prev = head;
	NODE curr = head;
	if( pos ==1 )
	{
		printf("The deleted element from SLL : %d\n" , head->data );
		head =  head->next;
        return ;
	}

    for(int i =1; i<pos ; i++)
    {
        if(curr == NULL)
        {
            printf("No such position in SLL so deletion is not possible\n");
            return ;
        }
        prev = curr;
        curr = curr->next;
        
    }

		
    if(curr == NULL)
    {
        printf("No such position in SLL so deletion is not possible\n");
        return ;
    }
    
    printf("The deleted element from SLL : %d\n" , curr->data);
    prev->next = curr->next;

}



int main()
{
    while(1)
    {
        printf("1.Insertionatend\n2.Deletionatend\n3.Deletionatfront\n4.Insertionatfront\n5.Insertatposition\n6.Deleteatpos\n\n\nEnter choices : ");
        int c ;
        scanf("%d", &c) ;
        if( c== 1 )
        {
            int v;
            scanf("%d", &v) ;
            insertatend(v);
        }
        if( c== 2)
        {
            deleteatend();
        }
        if( c== 3 )
        {
            deleteatfront();
        }
        if( c== 4 )
        {
            int v;
            scanf("%d", &v) ;
            inseratfront(v);
        }
        if( c== 5 )
        {
            int pos;
            int v;
            scanf("%d", &pos) ;
            scanf("%d", &v) ;
            insertAtPosition(pos , v);
        }
        if (c== 6 )
        {
            int pos;
            scanf("%d", &pos) ;
            deleteAtPosition(pos);
        }
        
        transversal();
        system("cls");
    }
}