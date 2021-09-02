////////////////////////////////////////////////////////////////////////////////
///                                  cake.h                                  ///
////////////////////////////////////////////////////////////////////////////////
#ifndef __CAKE_H__
#define __CAKE_H__

#include "list.h"

/*
 * create_players()
 *
 * Create a linked list of numPlayers nodes representing the players in the
 * 'Who Gets the Cake' game. Return the head of the list on success, NULL on
 * failure. Leaks the number of bytes required to allocate the linked list on
 * the heap. The value attributes for each node should be set from zero to 
 * (numPlayers - 1).
 */
Node *create_players(int numPlayers);

/*
 * eliminate()
 *
 * Iteratively eliminates every k-th player, where k is the interval, from the
 * linked list of players, until one player remains, the winner. Returns the 
 * index (i.e. the value attribute) of the winner.
 */
int eliminate(int numPlayers, int interval);

#endif // __CAKE_H__
////////////////////////////////////////////////////////////////////////////////
///                                END OF FILE                               ///
////////////////////////////////////////////////////////////////////////////////
