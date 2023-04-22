#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"

int main()
{
	int n;
	printf("Please enter n: ");
	scanf("%d", &n);
	node * head;
	head = farey_seq(n);
	if(head == NULL)
		printf("The linked list is empty");
	delete_list(head);
}

node * farey_seq(int n)
{
	/*You code goes here*/
}
void print_list(node * head, int n)
{
	if(head == NULL)
		return;	
	printf("level %d: ", n);
	while(head != NULL)
	{
		printf("%d/%d ", head->numerator, head->denominator);
		head = head->next;
	}
	printf("\n");
}

void delete_list(node * head)
{
	node * temp;	
	while(head != NULL){
		temp = head->next;
		free(head);
		head = temp;
	}
}
