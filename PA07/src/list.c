////////////////////////////////////////////////////////////////////////////////
///                                  list.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

Node *delete_node(Node *head,Node *node);
Node *search(Node *startNode,int interval,Node *head);
/*
 * The documentation for the functions to be defined in this file appears in
 * list.h. Note that only the function definitions with preprocessor guards
 * around them will be graded. You may use the print_list() function for
 * debugging convenience in some instances.
 */


Node *alloc_node(int value)
{
      Node *node = malloc(sizeof(Node));
      if(node == NULL)
      {
            fprintf(stderr,"[ERROR] in allocing memory");
            return NULL;
      }
      node->value = value;
      return node;
}

Node *delete_node(Node *head,Node *node)
{
      Node *ptr = head;
      if(head == node)
      {
            Node *temp = node -> next;
            if(temp-> next == head)
            {
                  temp->next = temp;
                  free_node(node);
                  return temp;
            }
            node -> next = NULL;
            free_node(node);
            return temp;
            
      }
      while(ptr != NULL)
      {
            if(ptr->next == node)
            {
                  ptr->next = node->next;
                  break;
            }
            ptr = ptr->next;
      }
      node->next = NULL;
      free_node(node);
      return head;
}

Node *search(Node *startNode,int interval,Node *head)
{
      Node* temp = head;
      while(temp != NULL)
      {
            if(temp->next == NULL)
            {
                  temp->next = head;
                  break;
            }
            temp = temp->next;
      }

      Node *ptr = startNode;
      int k = 1;
      while(k != interval)
      {
                   k++;
                   ptr = ptr->next;
           
      }

      Node* temp1 = head;
      while(temp1 != NULL)
      {
            if(temp1->next == head)
            {
                  temp->next = NULL;
                  break;
            }
            temp1 = temp1->next;
      }
      return ptr;
}

void free_node(Node *node)
{
      free(node);
      return;
}


void print_list(Node *head)
{
      Node *ptr = head;
      int flag = 0;
      //int flag2 = 1;
      while(ptr != NULL && ptr->next != head )
      {
            
            printf("%d\n", ptr->value);
            //flag2 = 0;
            ptr = ptr->next;
            if(ptr != NULL && ptr ->next == head)
            {
                  printf("%d\n", ptr->value);
            }
            flag = 1;
      }

      if(!flag)
      {
            if(ptr != NULL)
            {
                   printf("%d\n", ptr->value);
            }
            else if(ptr == NULL)
            {
                  printf("The linked list is empty");
            }
      }
      return;
}


#if   !defined(GRADE_INSERT_TAIL) &&	\
      !defined(GRADE_LENGTH) && 	\
      !defined(GRADE_FREE_LIST) && 	\
      !defined(GRADE_CREATE) && 	\
      !defined(GRADE_ELIMINATE)
Node *insert_node_at_head(Node *head, Node *node)
{
      node->next = head;
      return node;      
}
#endif


#if   !defined(GRADE_INSERT_HEAD) && 	\
      !defined(GRADE_LENGTH) && 	\
      !defined(GRADE_FREE_LIST) && 	\
      !defined(GRADE_CREATE) && 	\
      !defined(GRADE_ELIMINATE)
Node *insert_node_at_tail(Node *head, Node *node)
{
      Node *ptr = head;
      while(ptr != NULL)
      {     if(ptr->next == NULL)
            {
                  ptr->next = node;
                  break;
            }

            ptr = ptr->next;
      }
      node->next = NULL;
      return head;
      
}
#endif


#if   !defined(GRADE_INSERT_HEAD) && 	\
      !defined(GRADE_INSERT_TAIL) && 	\
      !defined(GRADE_FREE_LIST) && 	\
      !defined(GRADE_CREATE) && 	\
      !defined(GRADE_ELIMINATE)
int get_list_length(Node *head)
{
      Node *ptr = head;
      int count = 0;
      //ptr->next != head && ptr->next != NULL;
      while(ptr != NULL)
      {
            count++;
            ptr = ptr->next;
           
      }


      return count;
}
#endif


#if   !defined(GRADE_INSERT_HEAD) &&	\
      !defined(GRADE_INSERT_TAIL) && 	\
      !defined(GRADE_LENGTH) && 	\
      !defined(GRADE_CREATE) && 	\
      !defined(GRADE_ELIMINATE)
void free_list(Node *head)
{
      Node *temp = NULL;
      while(head  != NULL)
      { 
            temp = head;
            head = head->next;
            free_node(temp);
      }
      return;
}
#endif
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
