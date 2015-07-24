/*/
 
 Refrences :
 
http://rosettacode.org/wiki/Playing_cards

https://github.com/AndrewZures/Poker_C/blob/master/cardgame.c

http://stackoverflow.com/questions/22596874/how-would-i-implement-a-stack-for-an-array-of-structs

https://web.cs.dal.ca/~hawkey/csci1100/assignments/Deck.java

http://stackoverflow.com/questions/22697107/why-is-my-hand-counter-resetting-itself-to-zero
 ============================================================================
 */

#include "playCard.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;
// using a class template for print out 
template <typename T1, typename T2>
class printer
{

public:
	
	void print(T1 object1, T2 object2)
	{
		cout << object1 << object2 << endl;
	}
};


int main(){

	FILE *ap;
     char msc[25];
     int start;
     ap = fopen("ASSIGNMENT3.TXT","w"); /* open for writing */
  

	//Memory management is represented by using pointers to the structures
	CARD *card;
	deckStack *pdst;
	handStack *phst;
	//counter *pCount;
	//pCount = &counter;
	//Memory is allocated using operator new
	try{
		card = new CARD();
		pdst = new deckStack();
	}
	catch (std::bad_alloc){
		cout << "can't allocate memory";
		return EXIT_FAILURE;
	}
	initCard(card, pdst);
	shuffleCard(pdst);

	phst = new handStack();
	//pCount = malloc(9*sizeof(int));
	//pCount = &counter;
	resetToTop(pdst);
	int count;
	cout << "Please, enter the number of hands to be played" << endl;
	cin >> count;
	printer<string,int> p;
	while(card->totalCount < count){
		//count++;
		handOfCard(pdst,phst);
		arrangeHand(phst);
		//displayHand(phst);
		if(isRoyalFlush(phst)) card->rfCount++;
		else if(isStraightFlush(phst))  card->sfCount++;
		else if(isFlush(phst))  card->fCount++;
		else if(isStraight(phst))  card->sCount++;
		else if(isFourOfAKind(phst))  card->fokCount++;
		else if(isFullHouse(phst))  card->fhCount++;
		else if(isThreeOfAKind(phst))  card->tokCount++;
		else if(isTwoPair(phst))  card->tpCount++;
		card->totalCount++;
		p.print("Total: ", card->totalCount); p.print("\n RoyalFlush: ", card->rfCount);
		p.print("\n StriaghtFlush: ", card->sfCount); p.print("\n Flush: ",card->fCount);
		p.print("\n Straight: " , card->sCount); p.print("\n FourofaKind ", card->fokCount);
		p.print("\n ThreeOfaKind: ", card->tokCount); p.print("\n Twopair: ", card->tpCount);
	}
	//write to file
	fprintf(ap, "Total: %d\n RoyalFlush: %d", card->totalCount, card->rfCount);
	fprintf(ap, "\n StriaghtFlush: %d, \n Flush: %d",card->sfCount, card->fCount);
	fprintf(ap, "\n Straight: %d\n FourofaKind: %d ",card->sCount, card->fokCount);
	fprintf(ap, "\n ThreeOfaKind: %d\n Twopair: %d",card->tokCount , card->tpCount);

	cout << "\nEnter any key to exit..." << endl;
	char c;
	cin >> c;
	
	fclose(ap); /* close the file before ending program */
	//deallocation is done by using operator delete
	delete phst;
	delete card;
	delete pdst;
	return EXIT_SUCCESS;

	
}
