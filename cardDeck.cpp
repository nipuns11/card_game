/*/

 Refrences :
 
http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero
 ============================================================================
 */


#include "cardDeck.h"
#include <vector>
using namespace std;
void initCard(CARD *card,deckStack *pdst){
	int cardNum;
	pdst->top=EMPTY;
	card = new CARD();
	for(cardNum=0; cardNum<DECKSTACKMAX; cardNum++){
		card->pips = (PIPS)(cardNum%13+1);
		card->suit = (SUIT)(cardNum/13);
		pushDeckStack(*card, pdst);
	}
}

void swap(CARD *card1, CARD *card2){
	//Swapping of 2 cards
	CARD temp;
	temp = *card1;
	*card1 = *card2;
	*card2 = temp;
}
	
void shuffleCard(deckStack *pdst){//shuffle the deck
	int i, j;
	for(i=0; i<DECKSTACKMAX; i++){
		j=rand()%DECKSTACKMAX;
		swap(pdst->deck+i, pdst->deck+j);
	}
}

void displayDeck(deckStack *pdst){// display the deck of cards
	char *cardPips[13] = {"ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"};
	// change of arraylist to vector 
	vector<char*>cardSuits;
	cardSuits.push_back("SPADES");
	cardSuits.push_back("CLUBS");
	cardSuits.push_back("HEARTS");
	cardSuits.push_back("DIAMONDS");
	int i;
	cout << "Deck of CARDs: \n";
	resetToTop(pdst);
	for(i=0; i<13; i++){

		cout << cardPips[popDeckStack(pdst).pips-1] << " of " << cardSuits.at(popDeckStack(pdst).suit) << endl;
	}
}
