#include <stdio.h>
#include <stdlib.h>

#include "list.h"

Node *alloc_node(int value)
{
    Node *node = malloc(sizeof(Node));
    if(node == NULL)
    {
        printf("[ERROR] malloc failed");
        return NULL;
    }
    node->value = value;
    node->next = node;
    node->prev = node;
    return node;
}

int get_length(Node *head)
{
      Node *ptr = head;
      int count = 0;
      if(ptr != NULL)
      {
          count = 1;
          ptr = ptr->next;
      }
      while(ptr  != head)
      {
            count++;
            ptr = ptr->next;
           
      }


      return count; 
}

void print_list(Node *head)
{
      Node *ptr = head;
      if(ptr != NULL)
      {
          printf("%d\n",ptr->value);
          ptr = ptr->next;
      }
      while(ptr  != head)
      {
            printf("%d\n",ptr->value);
            ptr = ptr->next;   
      }


      return; 
}

Node *push_node(Node *head, Node *newNode)
{
    if(head == NULL)
    {
        head = newNode;
    }
    else{
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    }
    return newNode;

    
}

Node *pop_node(Node *head)
{
    if(head != NULL)
    {
        head->prev->next = head->next;
        head->next->prev = head ->prev;
        head->next = head;
        head->prev = head;
    }
    return head;
}

Node *search_node(Node *head, int value)
{
    Node *ptr = head;
    Node *temp = NULL;
    if(ptr != NULL)
    {
          if(ptr->value == value)
          {
              return ptr;
          }
          else{
          ptr = ptr->next;
          }
    }
    while(ptr != head)
    {
            if(ptr->value == value)
            {
                temp = ptr;
                break;
            }
            
            ptr = ptr->next;
    }
    return temp;


}

Node *remove_nth_node(Node *head, int n)
{
    int length = get_length(head);
    Node *ptr = head;
    int count;
    if(n > 0 && n <= length && length > 0)
    {
      if( n == 1)
      {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr ->prev;
        if (ptr->next == ptr && ptr->prev == ptr)
        {
            head = NULL;
        }
        else
        {
        head = ptr-> next;
        }
        //return head;
      }
      else{
         ptr = ptr->next ;
         count = 1;
        while(ptr != head)
        {
            count++;
            if(n == count)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr ->prev;
                break;
            }
            ptr = ptr->next;   
        }
        //return head;
      }

    }
    return head;
   
}
