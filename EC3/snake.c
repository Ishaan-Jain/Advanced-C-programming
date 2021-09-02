////////////////////////////////////////////////////////////////////////////////
///                                  snake.c                                 ///
////////////////////////////////////////////////////////////////////////////////
//
// You are tasked with implementing a simplified version of the timeless snake
// video game. In this version, the game operates as follows:
// 	
// 	1. The snake is initially five blocks long, and is positioned somewhere
// 	   in the center of the game box.
// 	2. The snake does not move unless a directional key is pressed by the
// 	   player (big difference from the original snake game).
// 	3. The snake may not move over its own body. So, at any time, the snake
// 	   should only be able to move in at most three directions (less if near
// 	   a border).
// 	4. It doesn't matter what character you use to represent the snake's
// 	   body.
// 	3. The snake must stay within the boxed window. The player does not
// 	   loose the game by hitting a border of that box though. There is no
// 	   way for the player to loose the game in this version of the game in
// 	   fact.
// 	4. Exactly one cherry is present inside the box at all times, at a 
// 	   random location. The snake can pick it up and grow by one block
// 	   as a result. A new cherry should then by spawned at another location
// 	   (that does not overlap with the snake's body).
// 	5. The player can press 'q' at any time to exit out of the game.
//
// The game should be implemented using the curses library, which is an
// extremely simple yet versatile tool for character window manipulations.
// The template code in this file implements most of the setup and 
// initialization for that library. You will need to scour the library and 
// identify the additional functions you will need to use to implement your
// game. I recommend starting off with a tutorial (e.g. 
// https://invisible-island.net/ncurses/ncurses-intro.html), making sure you
// understand the code already present in this file, before moving to using
// the manual pages for documentation.
//
// As for the game itself, well, everything is up to you. For example, you will
// need to decide how you will implement your snake. It could be an array of 
// coordinate points for example, where each entry stores the row and column
// of each block in the snake's body. However, since the snake should grow each
// time it eats a cherry, maybe a linked list would be better. Regardless of 
// your choice, you should initialize the snake's position inside the game
// initialization function. The game loop skeleton is provided inside of main().
// You will have to implement the code that determines what should happen when
// one of the directional keys is pressed.
//
// Some of the curses functions you may find useful: getch(), addch(), move(),
// addstr(), mvaddch(), mvaddstr().
//


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>

/*
 * The game window's dimensions.
 */
#define WIN_H	24
#define WIN_W	80
typedef struct node {
	int row;
    int column;
	struct node *next;
} Node;

Node *insert_node_at_head(Node *head, Node *node);
Node *insert_node_at_tail(Node *head, Node *node);
Node *initialize_game(WINDOW *window);
void free_list(Node *head);
void free_node(Node *node);
Node *delete_node(Node *head,Node *node);



Node *insert_node_at_head(Node *head, Node *node)
{
	node->next = head;
	return node;
}

void free_node(Node *node)
{
      free(node);
      return;
}

Node *insert_node_at_tail(Node *head, Node *node)
{
      Node *ptr = head;
      while(ptr != NULL)
      {     if(ptr->next == NULL)
            {
                  ptr->next = node;
                  break;
            }

            ptr = ptr->next;
      }
      node->next = NULL;
      return head;
      
}

void free_list(Node *head)
{
      Node *temp = NULL;
      while(head  != NULL)
      { 
            temp = head;
            head = head->next;
            free_node(temp);
      }
      return;
}

Node *delete_node(Node *head,Node *node)
{
      Node *ptr = head;
      if(head == node)
      {
            Node *temp = node -> next;
            if(temp-> next == head)
            {
                  temp->next = temp;
                  free_node(node);
                  return temp;
            }
            node -> next = NULL;
            free_node(node);
            return temp;
            
      }
      while(ptr != NULL)
      {
            if(ptr->next == node)
            {
                  ptr->next = node->next;
                  break;
            }
            ptr = ptr->next;
      }
      node->next = NULL;
      free_node(node);
      return head;
}


WINDOW *initialize_window(void);
void cleanup(Node *head);


/*
 * Almost all functions from the curses library return either ERR on error, or
 * OK on success. This enables us to create the following short routine for 
 * general error checking. Simply call this right after any such function call.
 */
void check(int status, char *function, int line)
{
	if(status == ERR) {
		//cleanup();
		fprintf(stderr, "[ERROR] on line %d: %s() failed.\n", line, function);
		exit(EXIT_FAILURE);
	}
}


/*
 * Initialization and paramterization of the game window is done in this
 * function. initscr() must be called first. Use the manual pages to find out
 * what the other functions do. This function calls refresh().
 */
WINDOW *initialize_window(void)
{
	int status;

	WINDOW *window = initscr();
	if(window == NULL) {
		fprintf(stderr, "[ERROR] on line %d: %s() failed.\n", 28, "initscr");
		exit(EXIT_FAILURE);
	}

	/*
 	 * The window is parametrized below, but feel free to modify and/or
 	 * expand on this.
 	 */

	status = resizeterm(WIN_H, WIN_W);
	check(status, "resizeterm", __LINE__);

	status = cbreak();
	check(status, "cbreak", __LINE__);

	status = noecho();
	check(status, "noecho", __LINE__);

	status = keypad(window, TRUE);
	check(status, "keypad", __LINE__);

	status = refresh();
	check(status, "refresh", __LINE__);

	status = curs_set(0);
	check(status, "refresh", __LINE__);


	return window;
}


/*
 * Use this function to clean up any messes before exiting the program, lest
 * the terminal becomes unusable. If you are allocating memory on the heap,
 * you may want to use this function to free it.
 */
void cleanup(Node *head)
{
	free_list(head);
	endwin();
}


/*
 * Use this function to initialize the game elements (e.g. draw a box around
 * the window, initialize the snake's position, etc.).
 */
Node *initialize_game(WINDOW *window)
{
	int status;

	status = box(window, 0, 0);
	check(status, "box", __LINE__);

	/* Your code here. */
    Node *head = NULL;
    int flag = 0;
    for(int i = 0;i < 5;i++)
    {
        Node *node = malloc(sizeof(Node));
        node->row = (WIN_H/2);
        node->column = ((WIN_W/2) - i);
		node->next = NULL;
        if(flag == 0)
        {
             head = insert_node_at_head(head,node);
             flag = 1;
        }
        else{
            head = insert_node_at_tail(head,node);
        }
    }

	//int y = (rand() % (22 - 1 + 1)) + 1;
	//int x = (rand() % (78 - 1 + 1)) + 1;
	//mvprintw(y,x,"c");
   
	status = refresh();
	check(status, "refresh", __LINE__);

    Node *ptr = head;
    while(ptr != NULL)
    {
        mvprintw(ptr->row,ptr->column,"o");
		status = refresh();
	    check(status, "refresh", __LINE__);
        ptr = ptr->next;
    }

	move(head->row,head->column + 1);
	status = refresh();
	check(status, "refresh", __LINE__);


	return head;
}


int main()
{
	int status;

	WINDOW *window = initialize_window();
    Node *head = initialize_game(window);
	int y = 5;
	int x = 3;
	mvprintw(y,x,"c");

	
	/*
 	 * The game loop. The player can press 'q' to exit out of it and end
 	 * the game. To keep things simple, you need only worry about 
 	 * implementing the snake's movement using the arrow keys. Of course,
 	 * if you wish, feel free to add some functionality (e.g. a key to reset
 	 * the game, a key to pause the game, etc.).
 	 */
	while(1) {

		//int key = getch();
		//int size = 5;
		int cherry = 0;
		if(head-> row == y && head->column == x)
		{
			cherry = 1;

			Node *ptr = head;
			y = (rand() % (22 - 1 + 1)) + 1;
			x = (rand() % (78 - 1 + 1)) + 1;
			int endflag = 0;
			while(endflag != 1 && ptr != NULL)
			{
				ptr = head;
				while(ptr != NULL)
				{
					
					if(y == ptr->row && x == ptr->column)
					{
						y = (rand() % (22)) + 1;
		    			x = (rand() % (78)) + 1;
						break;
					}
					ptr = ptr->next;
					if(ptr == NULL)
					{
						endflag = 1;
					}
				}
			}
			mvprintw(y,x,"c");
			status = refresh();
			check(status, "refresh", __LINE__);
		}

		int key = getch();


		if(key == KEY_LEFT) {
			Node *ptr = head;
			Node *ptr2 = head;
			int flagr = 1; 
			int row;
			int col;
			while(ptr2 != NULL)
			{
				if(ptr2 == head)
				{
					if(ptr2->next->column == (ptr2->column - 1))
					{
						flagr = 0;
						break;
					}
					else if(ptr2->column < 2)
					{
						flagr = 0;
						break;
					}
					row = ptr2->row;
					col = ptr2->column;
					
				}
				if((col - 1) == ptr2->column && row == ptr2->row)
				{
					flagr = 0;
					break;
				}
				ptr2 = ptr2->next;

			}
			if(flagr)
			{
    		while(ptr != NULL)
    		{
				if(ptr  == head)
				{
					if(ptr->column > 1)
					{
						Node *node = malloc(sizeof(Node));
        				node->row = ptr->row;
        				node->column = (ptr->column - 1);
						head = insert_node_at_head(head,node);
					 	mvprintw(node->row,node->column,"o");
						status = refresh();
						check(status, "refresh", __LINE__);	
					}

				}
				else if(ptr -> next == NULL && cherry != 1 )
				{
					mvaddch(ptr->row,ptr->column,' ');
					status = refresh();
					check(status, "refresh", __LINE__);
					head = delete_node(head,ptr);
					break;
				}
       			ptr = ptr->next;
    		}
			move(head->row,head->column -1);
			

        	}
			

		}

		 if(key == KEY_RIGHT) {
			Node *ptr = head;
			Node *ptr2 = head;
			int flagr = 1; 
			int row;
			int col;
			while(ptr2 != NULL)
			{
				if(ptr2 == head)
				{
					if(ptr2->next->column == (ptr2->column + 1))
					{
						flagr = 0;
						break;
					}
				    if(ptr2->column >= 78)
					{
						flagr = 0;
						break;
					}

					row = ptr2->row;
					col = ptr2->column;
					
				}
				if((col + 1) == ptr2->column && row == ptr2->row)
				{
					flagr = 0;
					break;
				}
				ptr2 = ptr2->next;

			}
			if(flagr)
			{
    		while(ptr != NULL)
    		{
				if(ptr  == head)
				{
					if(ptr->column <= 78)
					{
						Node *node = malloc(sizeof(Node));
        				node->row = ptr->row;
        				node->column = (ptr->column + 1);
						head = insert_node_at_head(head,node);
					 	mvprintw(node->row,node->column,"o");
						status = refresh();
						check(status, "refresh", __LINE__);	
					}

				}
				else if(ptr -> next == NULL  && cherry != 1)
				{
					mvaddch(ptr->row,ptr->column,' ');
					status = refresh();
					check(status, "refresh", __LINE__);
					head = delete_node(head,ptr);
					break;
				}
				ptr = ptr->next;
       			
    		}
			move(head->row,head->column +1);
			

        	}
		}

			
		

		else if(key == KEY_UP) {
			Node *ptr = head;
			Node *ptr2 = head;
			int flagr = 1; 
			int row;
			int col;
			while(ptr2 != NULL)
			{
				if(ptr2 == head)
				{
					if(ptr2->next->row == (ptr2->row - 1))
					{
						flagr = 0;
						break;
					}
					else if(ptr2->row <= 1)
					{
						flagr = 0;
						break;
					}

					row = ptr2->row;
					col = ptr2->column;
					
				}
				if(col == ptr2->column && (row - 1) == ptr2->row)
				{
					flagr = 0;
					break;
				}
				ptr2 = ptr2->next;

			}
			if(flagr)
			{
    		while(ptr != NULL)
    		{
				if(ptr  == head)
				{
					if(ptr->row > 1)
					{
						Node *node = malloc(sizeof(Node));
        				node->row = (ptr->row - 1);
        				node->column = ptr->column;
						head = insert_node_at_head(head,node);
					 	mvprintw(node->row,node->column,"o");
						status = refresh();
						check(status, "refresh", __LINE__);	
					}

				}
				else if(ptr -> next == NULL && cherry != 1)
				{
					mvaddch(ptr->row,ptr->column,' ');
					status = refresh();
					check(status, "refresh", __LINE__);
					head = delete_node(head,ptr);
					break;
				}
       			ptr = ptr->next;
    		}
			move(head->row - 1,head->column);
			

        	}


		}

		else if(key == KEY_DOWN) {
			Node *ptr = head;
			Node *ptr2 = head;
			int flagr = 1; 
			int row;
			int col;
			while(ptr2 != NULL)
			{
				if(ptr2 == head)
				{
					if(ptr2->next->row == (ptr2->row + 1))
					{
						flagr = 0;
						break;
					}
					else if(ptr2->row >= 22)
					{
						flagr = 0;
						break;
					}
					row = ptr2->row;
					col = ptr2->column;
					
				}
				if(col == ptr2->column && (row + 1) == ptr2->row)
				{
					flagr = 0;
					break;
				}
				ptr2 = ptr2->next;

			}
			if(flagr)
			{
    		while(ptr != NULL)
    		{
				if(ptr  == head)
				{
					if(ptr->row <= 22)
					{
						Node *node = malloc(sizeof(Node));
        				node->row = (ptr->row + 1);
        				node->column = ptr->column;
						head = insert_node_at_head(head,node);
					 	mvprintw(node->row,node->column,"o");
						status = refresh();
						check(status, "refresh", __LINE__);	
					}

				}
				else if(ptr -> next == NULL && cherry != 1)
				{
					mvaddch(ptr->row,ptr->column,' ');
					status = refresh();
					check(status, "refresh", __LINE__);
					head = delete_node(head,ptr);
					break;
				}
       			ptr = ptr->next;
    		}
			move(head->row + 1,head->column);
			

        	}

		}

		else if(key == 'q') {
			break;
		}
	}

	cleanup(head);
	return EXIT_SUCCESS;
}
