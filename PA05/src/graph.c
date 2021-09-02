////////////////////////////////////////////////////////////////////////////////
///                                graph.c                                   ///
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

Graph *alloc_graph(int numVertices) {
	/*
 	 * This function is not directly being graded, but you should implement
 	 * it stand-alone nonetheless. Simply allocate a Graph structure, 
 	 * populate it, and allocate it adjacency matrix. Return the address of
 	 * the allocated Graph on success, return NULL on failure. Your graph
 	 * reading function should probably call this function once it has
 	 * counted the number of vertices in the input file.
 	 */ 
	  Graph *Gstruc = (Graph *)malloc(1*sizeof(Graph));
	  if (Gstruc == NULL) {
        printf("Memory not allocated.\n");
        return NULL;
      }

	  Gstruc->numVertices = numVertices;

      
	  int i = 0;
	  Gstruc -> adjMatrix = (int **)malloc(numVertices * sizeof(int *));
	  if(Gstruc -> adjMatrix == NULL && numVertices != 0) {
		printf("[ERROR] malloc() failed.\n");
		return NULL;
	  }
	  for(i = 0; i < numVertices;i++)
	  {
		    Gstruc->adjMatrix[i] = (int *)calloc(numVertices,sizeof(int));
		   	if (Gstruc->adjMatrix[i] == NULL) {
        	printf("Memory not allocated.\n");
        	return NULL;
          }

	  }

	  return Gstruc;

	  
}

void free_graph(Graph *graph) {
	/*
 	 * Just like with the allocation function above, this function is not
 	 * directly being graded, but you should implement it stand-alone
 	 * nonetheless. Simply free the heap memory allocated for a Graph
 	 * structure. Don't forget to free the memory for the adjacency matrix
 	 * as well, otherwise, there will be a memory leak! Use Valgrind to test
 	 * whether this function is successfully freeing all memory associated
 	 * with a given Graph structure.
 	 */
	  if(graph == NULL)
	  {
		  return;
	  }
	  for(int i = 0; i < graph->numVertices; i++)
	  {
		  
			  free(graph->adjMatrix[i]);
	  }

	  free(graph->adjMatrix);

	  free(graph);
	  return;
}

#if     !defined(GRADE_WRITE) && \
        !defined(GRADE_TRANSPOSE) && \
        !defined(GRADE_COMBINE)
Graph *read_graph_from_file(char const *filename)
{
	/*
 	 * 'filename' is the name of a file to read from. This file contains
 	 * data representing a graph. This function should allocate a graph
 	 * structure and populate it with the data from the input file. The
 	 * input file follows the format specified in the README. This function
 	 * should return the address of the allocated graph if it succeeds, NULL
 	 * otherwise.
 	 */

	  FILE * input = fopen(filename,"r");
	  if(input == NULL)
	  {
		  printf("[ERROR] in opening input file\n");
		  return NULL;
	  }

	  int nodesnum = 0;
	  Graph *Igraph = NULL;
	  int flag;
	  //int flag2 = 0;

	  while(1)
	  {
		  int ch = fgetc(input);
          /*if( ch == EOF && flag2 == 0)
		  {
			  return NULL;
		  }*/
		  if(ch == EOF)
		  {
			  break;
		  }
		  else if(ch == '#')
		  {
			  flag = 1;
			  //flag2 = 1;
			  continue;
		  }
		  else if(ch == '\n')
		  {                 
			  flag = 0;
			  continue;
		  }
		  else if(flag == 1)
		  {
			  continue;
		  }
		  else if(ch == ' ')
		  { 
			  continue;
		  }
		  else
		  {   
			  int first = 1;
			  //flag2 = 1;
			  if(ungetc(ch,input) != ch)
			  {
				  printf("[ERROR] in ungetc");
				  return NULL;
			  }

			  char string[101];
			  if(first == 1)
			  {
				  fgets(string,101,input);
			      sscanf(string,"%d",&nodesnum);
			  }
              
			  Igraph = alloc_graph(nodesnum);
			  int i;
			  int j;
			  while(fgets(string,101,input) != NULL)  //fscanf(input," %d %d",&i,&j) != EOF)
			  {
				    sscanf(string,"%d %d",&i,&j);
                    Igraph->adjMatrix[i][j] = 1;
			  }

			  //fseek(input,-1,SEEK_CUR);
			    
		     
		  }

	  }
	  if(Igraph == NULL)
	  {
		  Igraph = alloc_graph(nodesnum);
	  }

      fclose(input);
	  return Igraph;


}
#endif // GRADE_READ

#if     !defined(GRADE_READ) && \
        !defined(GRADE_TRANSPOSE) && \
        !defined(GRADE_COMBINE)
bool write_graph_to_file(char const *filename, const Graph *graph)
{
	/*
 	 * 'filename' is the name of a file to write into. 'graph' is the graph
 	 * representation in dynamic memory of a valid graph. This function must
 	 * write the graph out into the file 'filename', following the format
 	 * specified by the README. Remember that edges should be sorted in
 	 * ascending order according to their source vertices first, and their
 	 * destination vertices second. This function should return true if it
 	 * succeeds, false otherwise.
 	 */

	  FILE * output = fopen(filename,"w");
	  if(output == NULL)
	  {
		  return false;
	  }
      
	  if(graph != NULL)
	  {
		   fprintf(output,"%d\n",graph->numVertices);

	 	 for(int i = 0; i < graph->numVertices; i++)
	 	 {
		  	for (int j = 0; j<graph->numVertices; j++)
		  	{
			  if(graph->adjMatrix[i][j] == 1)
			  {
				  fprintf(output,"%d %d\n",i,j);
			  }
		  	}
	     }
	  }
	  
	 //free_graph(graph); Getting error ask if they will call free function

	 fclose(output);
     return true;
}
#endif // GRADE_WRITE

#if     !defined(GRADE_READ) && \
        !defined(GRADE_WRITE) && \
        !defined(GRADE_UNION)
bool transpose_graph(Graph *graph)
{
	/*
 	 * 'graph' is an exsting graph representation stored in dnyamic memory.
 	 * This function must compute the transpose of the graph in place,
 	 * meaning that the graph structure pointed to by 'graph' should be 
 	 * directly modified as a result of the transposition (and you should
 	 * not create a new graph structure). Transposing the graph essentially
 	 * means inverting all edges. This function should return true if it is
 	 * successful. It should return false otherwise. This function should
 	 * not leak any memory (whatever is allocated here must be freed by the
 	 * end of the function).
 	 */
      
	  Graph *Tgraph = alloc_graph(graph->numVertices);
	  for(int i =0; i< graph->numVertices; i++)
	  {
		  for(int j= 0; j < graph->numVertices; j++ )
		  {
			  if(graph->adjMatrix[i][j] == 1)
			  {
				  Tgraph->adjMatrix[j][i] = 1;
				  graph->adjMatrix[i][j] = 0;
			  }
		  }
	  }

	  for(int i =0; i< graph->numVertices; i++)
	  {
		  for(int j= 0; j < graph->numVertices; j++ )
		  {
			   if(Tgraph->adjMatrix[i][j] == 1)
			  {
				  graph->adjMatrix[i][j] = 1;
			  }
		  }
		 
	  }
   
    free_graph(Tgraph);
    return true;
       
}
#endif// GRADE_TRANSPOSE

#if     !defined(GRADE_READ) && \
        !defined(GRADE_WRITE) && \
        !defined(GRADE_TRANSPOSE)
Graph *combine_graph(Graph *first, Graph *second)
{
	/*
 	 * 'first' and 'second' are valid graph representations in dynamic
 	 * memory. This function must compute the union of the two graphs,
 	 * such that the resulting graph contains the union of all edges in
 	 * both input graphs. The resulting graph must be allocated on the heap
 	 * by this function. If successful, this function returns the address
 	 * of the new graph and frees the memory allocated for the two input
 	 * graphs. If failed, this function should not allocate any memory,
 	 * the two input graphs should not be freed or modified, and it should 
 	 * return NULL. You may assume that the two input graphs have the same 
 	 * set of vertices. This function is expected to leak the exact amount 
 	 * of memory required to allocate one graph structure (when it 
 	 * succeeds). No additional amoounts of memory may be leaked.
 	 */
      
	  Graph * g3;
	  g3 = alloc_graph(first->numVertices);
	  if(g3 == NULL)
	  {
		  free(g3);
		  return NULL;
	  }

	   for(int i =0; i< first->numVertices; i++)
	  {
		  for(int j= 0; j < first->numVertices; j++ )
		  {
			  if(first->adjMatrix[i][j] == 1 || second->adjMatrix[i][j] == 1 )
			  {
				  g3->adjMatrix[i][j] = 1;
			  }
		  }
	  }

	  free_graph(first);
	  free_graph(second);

	  return g3;
}
#endif // GRADE_COMBINE
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
