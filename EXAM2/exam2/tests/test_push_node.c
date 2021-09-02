#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/list.h"

void test_empty_list()
{
    Node *head = NULL;
    int i;
    for( i = 0 ; i< 0; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    int length = get_length(head);
    TEST_CHECK(length == 0 && head == NULL);
    TEST_MSG("Node not pushed properly");

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
    int length = get_length(head);
    TEST_CHECK(length == 1 && head->value == 0 ); 
    TEST_MSG("Node not pushed properly");  
}

void test_multiple_elements_list()
{
    Node *head = NULL;
    int i;
    for( i = 0  ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    int length = get_length(head);
    TEST_CHECK(length == 5 && head ->value == 4); 
    TEST_MSG("Node not pushed properly");
}



TEST_LIST = {
  { "test_empty_list", test_empty_list },
  { "test_one_element_list", test_one_element_list },
  { "test_multiple_elements_list", test_multiple_elements_list },
  { NULL, NULL }
};