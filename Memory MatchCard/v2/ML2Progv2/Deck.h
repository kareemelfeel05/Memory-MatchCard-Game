//
// Created by ASUS on 11/15/2024.
//
#include <iostream>

#include "card.h"
#ifndef DECK_H
#define DECK_H
class Deck {
private:
    Card** cards;
    int size;
public:
    Deck();
    Deck(int size);
    void shuffle();
    void displayGrid();
    Card** getCards();
    void setCards(Card** cards);
    void openCard(int row,int col);
    Card* getCard(int row,int col);
    Card* getCardByIndex(int index);
    void closeCard(int row,int col);
    void removeCard(int row,int col);

    ~Deck();
};
#endif //DECK_H
