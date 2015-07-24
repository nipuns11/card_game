/*/

 Refrences :
 
http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero
 ============================================================================
 */
#ifndef cardStack
#define cardStack

#include "cardDef.h"

typedef struct deckStack{
	CARD deck[DECKSTACKMAX];
	int top;
	CARD cardName[20];
} deckStack;

// hand stack struct
typedef struct handStack{
	CARD hand[HANDSTACK];
	int top;
} handStack;
// functions for the cards and the hands to be played 
bool deckIsEmpty(deckStack *pdst);
bool deckIsFull(deckStack *pdst);
bool handIsEmpty(handStack *phst);
bool handIsFull(handStack *phst);
void resetToTop(deckStack *pdst);
void pushDeckStack(CARD card, deckStack *pdst);
void pushHandStack(CARD card, handStack *phst);
CARD popDeckStack(deckStack *pdst);
CARD popHandStack(handStack *hdst);
#endif