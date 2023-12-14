#ifndef __DECK__
#define __DECK__

#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef unsigned char BOOL;

/**
 * struct card_s - Playing card
 *
 * @value: The value of the card
 * From "Ace" to "King"
 * @kind: A kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - The Deck of card
 *
 * @card: A Pointer to the card of the node
 * @prev: A Pointer to the prev node of the list
 * @next: A Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* __DECK__ */
