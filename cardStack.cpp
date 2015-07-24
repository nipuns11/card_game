/*/

 Refrences :
 
http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero

http://www.experts-exchange.com/Programming/Languages/Java/J2EE/Q_24890882.html
 ============================================================================
 */

#include "cardStack.h"
	
bool deckIsEmpty(deckStack *pdst){
	return (bool)(pdst->top==EMPTY);// Assignments to the variables of structs
}
// function when deck is full
bool deckIsFull(deckStack *pdst){
	return (bool)(pdst->top==FULL);
}
// function when hand is empty
bool handIsEmpty(handStack *phst){
	return (bool)(phst->top==EMPTY);
}
// function when hand is full
bool handIsFull(handStack *phst){
	return (bool)(phst->top==FULL);
}
// resetting the deck
void resetToTop(deckStack *pdst){
	pdst->top=FULL;
}

void pushDeckStack(CARD card, deckStack *pdst){
	(pdst->top)++;
	pdst->deck[pdst->top]=card;
}
// function to pass hand stack
void pushHandStack(CARD card, handStack *phst){
	phst->top++;
	phst->hand[phst->top]=card;
}
// pop the deck
CARD popDeckStack(deckStack *pdst){
	return (pdst->deck[pdst->top--]);
}
// pop hand stack
CARD popHandStack(handStack *hdst){
	return (hdst->hand[hdst->top--]);
}
