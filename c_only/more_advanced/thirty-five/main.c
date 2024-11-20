#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

const int MIN = 1;
const int MAX = 52;

typedef enum
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
}Suit;

typedef enum {
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, HEIGHT, NINE, TEN, JAKE, QUEEN, KING
}Value;

typedef struct CARD {
    Suit s;
    Value v;
}Card;

typedef struct {
    Card cards[52];
    int count;
}Deck;

// declarations
void printCard(Card);
void initializeDeck(Deck *);
void playCard(Card *);
int generator(int min, int max);


int main()
{
    Deck deck;
    initializeDeck(&deck);
    srand(time(NULL));
    int randomCardNbr = generator(MIN, MAX);

    printCard(deck.cards[randomCardNbr]);
    // Print the entire deck
    // for (int i = 0; i < deck.count; i++) {
    //     if(deck.count == randomCardNbr)
    //         printCard(deck.cards[i]);
    // }

    return 0;
}

void initializeDeck(Deck *deck) {
    deck->count = 0;
    for (int suit = HEARTS; suit <= SPADES; suit++) {
        for (int value = ACE; value <= KING; value++) {
            deck->cards[deck->count].s = suit;
            deck->cards[deck->count].v = value;
            deck->count++;
        }
    }
}

// Function to print a card
void printCard(Card card) {
    const char *suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char *values[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

    printf("%s of %s\n", values[card.v - 1], suits[card.s]);
}

int generator(int min, int max)
{
    return (rand() % (max - min + 1)) + min; 
}

void playCard(Card *){

}