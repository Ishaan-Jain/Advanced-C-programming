#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/list.h"

void test_empty_list()
{
    Node *head = NULL;
   int i;
    for( i = 0  ; i< 0; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = remove_nth_node(head,3);
    int length = get_length(temp);
    TEST_CHECK(length == 0 && temp == NULL);
    TEST_MSG("Node not removed properly");

}

void test_one_element_list_remove_first_node()
{
    Node *head = NULL;
    int i;
    for( i = 0  ; i< 1; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = remove_nth_node(head,1);
    int length = get_length(temp);
    TEST_CHECK( length == 0 && temp == NULL ); 
    TEST_MSG("Node not removed properly");  
}

void test_multiple_elements_list_remove_head_node()
{
    Node *head = NULL;
    int i;
    for( i = 0  ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    head = remove_nth_node(head,1);
    int length = get_length(head);
    TEST_CHECK(length == 4 &&  head->value == 3); 
    TEST_MSG("Node not removed properly");
}

void test_multiple_elements_list_out_of_bounds()
{
    Node *head = NULL;
    int i;
    int length;
    for( i = 0  ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = remove_nth_node(head,6);
    length = get_length(head);
    TEST_CHECK(length == 5 && head ->value == 4); 
    TEST_MSG("Node not removed properly");
}



TEST_LIST = {
  { "test_empty_list", test_empty_list },
  { "test_one_element_list_remove_first_node", test_one_element_list_remove_first_node },
  { "test_multiple_elements_list_remove_head_node",test_multiple_elements_list_remove_head_node },
  { "test_multiple_elements_list_out_of_bounds",test_multiple_elements_list_out_of_bounds},
  { NULL, NULL }
};