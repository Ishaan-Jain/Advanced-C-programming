#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 

#include "list.h"

int main()
{
    Node *head = NULL;
    int i;
    for( i = 0  ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = remove_nth_node(head,1);
    int length = get_length(temp);
    printf("%d\n",length);
    printf("%d\n",temp->value);



    return 0;
}