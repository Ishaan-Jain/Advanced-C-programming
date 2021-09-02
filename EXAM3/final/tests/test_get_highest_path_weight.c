#include <stdio.h>
#include <stdbool.h>

#include "acutest.h"
#include "../src/tree.h"

void test_nonexistent_tree()
{     
    char *input1 = "tests/preorder_No_nodes.txt";
    char *input2 = "tests/inorder_No_nodes.txt";

   TreeNode *root = build_tree_from_files(input1,input2);
   int weight = get_highest_path_weight(root);
   free_allNodes(root);
   TEST_CHECK(weight == 0);
   TEST_MSG("The weight is incorrect ");
}

void test_tree_with_only_root()
{
    char *input1 = "tests/preorder_root_only_nodes.txt";
    char *input2 = "tests/inorder_root_only_nodes.txt";

   TreeNode *root = build_tree_from_files(input1,input2);
   int weight = get_highest_path_weight(root);
   free_allNodes(root);
   TEST_CHECK(weight == 1);
   TEST_MSG("The weight is incorrect %d",weight);
}

void test_simple_tree()
{
   char *input1 = "tests/preorder_simple_tree.txt";
   char *input2 = "tests/inorder_simple_tree.txt";

   TreeNode *root = build_tree_from_files(input1,input2);
   int weight = get_highest_path_weight(root);
   free_allNodes(root);
   TEST_CHECK(weight == 10);
   TEST_MSG("The weight is incorrect %d",weight);
}

void test_complex_tree()
{
   char *input1 = "tests/preorder_complex_tree.txt";
   char *input2 = "tests/inorder_complex_tree.txt";

   TreeNode *root = build_tree_from_files(input1,input2);
   int weight = get_highest_path_weight(root);
   free_allNodes(root);
   TEST_CHECK(weight == 235);
   TEST_MSG("The weight is incorrect %d",weight);
}

// Add more test cases below until you have a thorough test suite.

TEST_LIST = {
  { "test_nonexistent_tree", test_nonexistent_tree },
  { "test_tree_with_only_root", test_tree_with_only_root },
  { "test_simple_tree", test_simple_tree },
  { "test_simple_tree", test_simple_tree },
  { "test_complex_tree", test_complex_tree},
  { NULL, NULL }
};