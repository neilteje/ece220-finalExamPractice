#include <stdio.h>
#include <stdlib.h>
#include "farey_seq.h"
typedef struct node {
    int numerator;
    int denominator;
    node *next;
} node;

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
    node *head = (node *)malloc(sizeof(node));
    head->numerator = 0;
    head->denominator = 1;
    head->next = NULL;
    node *second = (node *)malloc(sizeof(node));
    second->numerator = 1;
    second->denominator = 1;
    second->next = NULL;
    head->next = second;
    for (int order = 2; order <= n; order++) {
        node *current = head;
        while (current->next != NULL) {
            int a = current->numerator;
            int b = current->denominator;
            int c = current->next->numerator;
            int d = current->next->denominator;
            if (c + d <= order) {
                node *new_node = (node *)malloc(sizeof(node));
                new_node->numerator = a + c;
                new_node->denominator = b + d;
                new_node->next = current->next;
                current->next = new_node;
            }
            current = current->next;
        }
    }
    return head;
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
