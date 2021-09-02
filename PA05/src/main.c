#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "graph.h"

int main(int argc, char **argv)
{
  
   if (argc != 3) {
       printf("[ERROR] Usage: %s <vocab file> <intput file>", argv[0]);
       return EXIT_FAILURE;
   }

    char *input = argv[1];
    char *input2 = "input.txt";
    Graph *graph;
    Graph *graph2;
    char *output = argv[2];
    graph = read_graph_from_file(input);
    graph2 = read_graph_from_file(input2);
    //printf("nodes = %d\n",graph->numVertices);
    graph = combine_graph(graph,graph2);
    //transpose_graph(graph);
    if(!write_graph_to_file(output,graph))
    {
        return EXIT_FAILURE;
    }
    //free_graph(graph);
    return EXIT_SUCCESS;

}