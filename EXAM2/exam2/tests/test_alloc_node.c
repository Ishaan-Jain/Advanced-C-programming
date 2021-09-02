#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/list.h"

void test_one_malloc()
{
    Node* node = alloc_node(0);
    TEST_CHECK(node->value == 0);
    TEST_MSG("The value is %d\n",node->value);
}

void test_two_malloc()
{
    Node* node = alloc_node(0);
    Node* temp = alloc_node(1);
    TEST_CHECK(node->value == 0 && temp->value == 1);
    TEST_MSG("The value is %d  %d \n",node->value,temp->value);

}

void test_three_malloc()
{
    Node* node = alloc_node(0);
    Node* temp = alloc_node(1);
    Node *temp1 = alloc_node(2);
    TEST_CHECK(node->value == 0 && temp->value == 1 && temp1->value == 2);
    TEST_MSG("The value is %d  %d  %d\n",node->value,temp->value,temp1->value);

}



TEST_LIST = {
  { "test_one_malloc", test_one_malloc },
  { "test_two_malloc", test_two_malloc },
  { "test_three_malloc", test_three_malloc },
  { NULL, NULL }
};