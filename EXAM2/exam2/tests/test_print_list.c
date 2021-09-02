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
    print_list(head);
    TEST_CHECK( head == NULL);
    TEST_MSG("Node not printed properly");

}

void test_one_element_list()
{
    Node *head = NULL;
    int i;
    for( i = 0 ; i< 1; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    print_list(head);
    TEST_CHECK( head->value == 0);
    TEST_MSG("Node not printed properly"); 
}

void test_multiple_element_list()
{
    Node *head = NULL;
    int i;
    for( i = 0 ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    print_list(head);
    TEST_CHECK( head->value == 4);
    TEST_MSG("Node not printed properly"); 
    
}



TEST_LIST = {
  { "test_empty_list", test_empty_list },
  { "test_one_element_list", test_one_element_list },
  { "test_multiple_element_list",test_multiple_element_list },
  { NULL, NULL }
};