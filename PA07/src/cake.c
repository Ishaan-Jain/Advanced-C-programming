////////////////////////////////////////////////////////////////////////////////
///                                  cake.c                                  ///
////////////////////////////////////////////////////////////////////////////////
#include "list.h"
#include "cake.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//#include "list.c"

Node *delete_node(Node *head,Node *node);
Node *search(Node *startNode,int interval,Node *head);
/*
 * The documentation for the functions to be defined in this file appears in
 * cake.h.
 */


#if   !defined(GRADE_INSERT_HEAD) && 	\
      !defined(GRADE_INSERT_TAIL) && 	\
      !defined(GRADE_LENGTH) && 	\
      !defined(GRADE_FREE_LIST) && 	\
      !defined(GRADE_ELIMINATE)
Node * create_players(int numPlayers)
{
      if(numPlayers < 1)
      {
            return NULL;
      }
      Node *head = NULL;
      int flag = 0;
      for(int i = 0 ; i < numPlayers; i++)
      {
            Node *player = alloc_node(i);
            if(player == NULL)
            {
                  printf("Error in making liked list\n");
                  return NULL;
            }
            if(flag == 0){
                  head = insert_node_at_head(head,player);
                  flag = 1;
            }
            else{
                  head = insert_node_at_tail(head,player);
            } 
            

      }

      return head;
}
#endif


#if   !defined(GRADE_INSERT_HEAD) && 	\
      !defined(GRADE_INSERT_TAIL) && 	\
      !defined(GRADE_LENGTH) && 	\
      !defined(GRADE_FREE_LIST) && 	\
      !defined(GRADE_CREATE)
int eliminate(int numPlayers, int interval)
{
      Node *head = create_players(numPlayers);
      if(head == NULL)
      {
            printf("Error number of players should be at least 1\n");
            return -1;
      }
      //print_list(head);

      /*Node *ptr = head;
      while(ptr->next != NULL)
      {
            ptr = ptr->next;
      }
      ptr->next = head;*/
      //print_list(head);
      
      int count = get_list_length(head);
      Node *temp;
      Node *temp2 = head;
      while(count != 1)
      {
            temp = search(temp2,interval,head);
            if(temp->next == NULL)
            {
                  temp2 = head;
            }
            else{
                  temp2 = temp->next;
            }
            //print_list(head);
            head = delete_node(head,temp);
            //print_list(head);
            count = get_list_length(head);
      }
      //head->next = NULL;
      int x = head->value;
      free_list(head);
      return (x);


}
#endif
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
