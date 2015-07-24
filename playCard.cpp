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

#include "playCard.h"
// method for hand of card 
void handOfCard(deckStack *pdst, handStack *phst){
	int cardNum;
	phst->top = -1;
	for(cardNum=0; cardNum<5; cardNum++){
		pushHandStack(popDeckStack(pdst), phst);
		if(pdst->top<4){
			resetToTop(pdst);
			shuffleCard(pdst);		
		}		
	}
}
// method for arranging the card hand 
void arrangeHand(handStack *phst){
	int i, j;
	for(i=0;i<HANDSTACK; i++){
		for(j=HANDSTACK-1; j>i; j--){
			if(phst->hand[i].pips>phst->hand[j].pips)
				swap(phst->hand+i, phst->hand+j);
		}		
	}	
}
// display the hand 
void displayHand(handStack *phst){
	char *cardPips[13] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
	char *cardSuits[4] = {"SPADES", "CLUBS", "HEARTS", "DIAMONDS"};
	int i;
	phst->top=4;
	cout << "Hand of cards:" << endl;
	for(i=0; i<HANDSTACK; i++){	
		popHandStack(phst);
		cout << cardPips[phst->hand[i].pips-1] << " of " << cardSuits[phst->hand[i].suit] << endl;
	}
}
// if a flush is the hand
int isFlush(handStack *phst){
	if(phst->hand[0].suit==phst->hand[1].suit && phst->hand[0].suit==phst->hand[2].suit
		&&phst->hand[0].suit==phst->hand[3].suit&&phst->hand[0].suit==phst->hand[4].suit
		&&phst->hand[0].suit==phst->hand[5].suit) return 1;
	else return 0;	
}
// if its a stright 
int isStraight(handStack *phst){
	if(phst->hand[1].pips==phst->hand[0].pips+1 && phst->hand[2].pips==phst->hand[1].pips+1 && 
			phst->hand[3].pips==phst->hand[2].pips+1&& phst->hand[4].pips==phst->hand[3].pips+1)
			return 1;
	else return 0;
}
// if its one of a kind 
int isXofAKind(handStack *phst, int x, int pipsIgnored){
	switch(x){
		case 4:
			if(phst->hand[0].pips==phst->hand[1].pips && phst->hand[0].pips==phst->hand[2].pips 
				&&phst->hand[0].pips==phst->hand[3].pips)
				return phst->hand[0].pips;
			else if(phst->hand[1].pips==phst->hand[2].pips && phst->hand[1].pips==phst->hand[3].pips
					&& phst->hand[1].pips==phst->hand[4].pips)
				return  phst->hand[1].pips;
			else
				return 0;
			break;
		case 3:
			if(phst->hand[0].pips==phst->hand[1].pips && phst->hand[0].pips==phst->hand[2].pips)
				return phst->hand[0].pips;
			else if(phst->hand[1].pips==phst->hand[2].pips && phst->hand[1].pips==phst->hand[3].pips)
				return  phst->hand[1].pips;
			else if(phst->hand[2].pips==phst->hand[3].pips && phst->hand[4].pips==phst->hand[3].pips)
				return phst->hand[2].pips;
			else
				return 0;
			break;
		case 2:
			if(phst->hand[0].pips!=pipsIgnored && phst->hand[0].pips==phst->hand[1].pips)
				return phst->hand[0].pips;
			else if(phst->hand[1].pips!=pipsIgnored && phst->hand[1].pips==phst->hand[2].pips)
				return phst->hand[1].pips ;
			else if(phst->hand[2].pips!=pipsIgnored && phst->hand[2].pips==phst->hand[3].pips)
				return phst->hand[2].pips;
			else if(phst->hand[3].pips!=pipsIgnored && phst->hand[3].pips==phst->hand[4].pips)
				return phst->hand[3].pips;
			else
				return 0;
			break;
	}
}
// incase of a royal flush 
int isRoyalFlush(handStack *phst){
	if(isFlush(phst) && (phst->hand[0].pips==ACE && phst->hand[1].pips==TEN && phst->hand[2].pips==JACK && 
			phst->hand[3].pips==QUEEN && phst->hand[4].pips==KING))
			return 1;
	else return 0;
}
// if the user gets a straight flush 
int isStraightFlush(handStack *phst){
	if(isFlush(phst) && isStraight(phst)) return 1;
	else return 0;
}
// if the user gets a hand  full house 
int isFullHouse(handStack *phst){
	if(isXofAKind(phst, 3, 0) && isXofAKind(phst, 2, isXofAKind(phst, 3, 0))) return 1;
	else return 0;
}
// if the user gets a hand four of a kind 
int isFourOfAKind(handStack *phst){
	if(isXofAKind(phst, 4, 0)) return 1;
	else return 0;
}
// if the hand gets three of a kind 
int isThreeOfAKind(handStack *phst){
	if(isXofAKind(phst, 3, 0) && !(isFullHouse(phst))) return 1;
	else return 0;
}
// two pairs 
int isTwoPair(handStack *phst){
	if(isXofAKind(phst, 2, 0) && isXofAKind(phst, 2, isXofAKind(phst, 2, 0)) && !(isFullHouse(phst)) && !(isFourOfAKind(phst))) 
		return 1;
	else return 0;
}
