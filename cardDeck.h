/*/

 Refrences :
 
http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero
 ============================================================================
 */
#ifndef cardDeck
#define cardDeck

#include <iostream>
#include "cardStack.h"

using namespace std;
// methods 
void initCard(CARD *card,deckStack *pdst);
// method for swapping cards 
void swap(CARD *card1, CARD *card2);
// method for shuffling the cards
void shuffleCard(deckStack *pdst);
// methods for diaplying the deck 
void displayDeck(deckStack *pdst);

#endif