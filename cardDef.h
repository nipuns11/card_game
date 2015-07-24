/*/

http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero
 ============================================================================
 */
#ifndef cardDef
#define cardDef

#include <stdio.h>
#include <stdlib.h>

#define DECKSTACKMAX 52
#define HANDSTACK 5
#define FULL DECKSTACKMAX-1
#define EMPTY -1

enum PIPS {ACE=1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} ;
enum SUIT {SPADES, CLUBS, HEARTS, DIAMONDS};
struct CARD{
	//member variables are defined for the struct CARD:
	PIPS pips;
	SUIT suit;
	int totalCount;
	int rfCount; 
	int sfCount; 
	int fCount; 
	int sCount;
	int fhCount; 
	int fokCount;
	int tokCount; 
	int tpCount;
	CARD() //Constructor of the CARD struct
	{
		 totalCount=0;
		 rfCount=0; 
		 sfCount=0; 
		 fCount=0; 
		 sCount=0;
		 fhCount=0; 
		 fokCount=0;
		 tokCount=0; 
		 tpCount=0;
	}
};




#endif
