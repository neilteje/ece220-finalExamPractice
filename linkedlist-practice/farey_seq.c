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
    if (n == 0) return NULL;
	// working with head
    node* head = (node*)malloc(sizeof(node));
	head->numerator = 0;
	head->denominator = 1;

    // working with next
	head->next = (node*)malloc(sizeof(node));
	head->next->numerator = 1;
	head->next->denominator = 1;
	head->next->next = NULL;

    // starting farey sequence
    if (n == 1){
        print_list(head, n);
        return head;
    }

    // farey sequence for n > 1
    print_list(head, 1);
    int a,b,c,d;
    node* temp;
    int x, y;
    node* temp2 = head;
	for (int i = 2; i<=n ; i++){
		head = temp2;
        while ((head) && (head->next)){
            a = head->numerator;
            b = head->next->numerator;
            c = head->denominator;
            d = head->next->denominator;
            if (c + d<=i){
                temp = head->next;
                x = a+b;
                y = c+d;
                head->next = (node*)malloc(sizeof(node));
                head->next->numerator = x;
                head->next->denominator = y;
                head->next->next = temp2;
            }
            head = head->next;
        }
        print_list(temp2, i);
	}
	return temp2;
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
