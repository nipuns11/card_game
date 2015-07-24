#ifndef playCard
#define playCard

#include "cardDeck.h"
void handOfCard(deckStack *pdst, handStack *phst);
void arrangeHand(handStack *phst);
void displayHand(handStack *phst);
int isFlush(handStack *phst);
int isStraight(handStack *phst);
int isXofAKind(handStack *phst, int x, int pipsIgnored);
int isRoyalFlush(handStack *phst);
int isStraightFlush(handStack *phst);
int isFullHouse(handStack *phst);
int isFourOfAKind(handStack *phst);
int isThreeOfAKind(handStack *phst);
int isTwoPair(handStack *phst);
#endif