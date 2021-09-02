#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/list.h"

void test_empty_list()
{
    Node *head = NULL;
    int i;
    for(i = 0 ; i< 0; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = search_node(head,2);
    TEST_CHECK( temp == NULL);
    TEST_MSG("Node not searched properly");

}

void test_value_not_in_list()
{
    Node *head = NULL;
    int i;
    for( i = 0 ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = search_node(head,9);
    TEST_CHECK( temp == NULL);
    TEST_MSG("Node not searched properly");  
}

void test_value_in_the_list()
{
    Node *head = NULL;
    int i;
    for( i = 0 ; i< 5; i++)
    {
        Node* node = alloc_node(i);
        head = push_node(head,node);
    }
    Node *temp = search_node(head,2);
    TEST_CHECK( temp->value == 2);
    TEST_MSG("Node not searched properly");
}



TEST_LIST = {
  { "test_empty_list", test_empty_list },
  { "test_value_not_in_list", test_value_not_in_list },
  { "test_value_in_the_list",test_value_in_the_list },
  { NULL, NULL }
};