////////////////////////////////////////////////////////////////////////////////
///                                graph.h                                   ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdbool.h>

typedef struct _graph {
	int numVertices;
	int **adjMatrix;
} Graph;

Graph *alloc_graph(int numVertices);
void free_graph(Graph *graph);
Graph *read_graph_from_file(char const *filename);
bool write_graph_to_file(char const *filename, const Graph *graph);
bool transpose_graph(Graph *graph);
Graph *combine_graph(Graph *firstGraph, Graph *secondGraph);

#endif // __GRAPH_H__
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
