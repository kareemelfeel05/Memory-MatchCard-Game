//
// Created by yousef on 12/16/2024.
//
//Deck

#include "Deck.h"

#include "BonusCard.h"
#include "PenaltyCard.h"
#include "StandardCard.h"
using namespace std;
Deck::Deck() {
    this->size=16;
    cards=new Card*[16];
    for(int i=0;i<6;i++) {

        string s1=" "+to_string(i+1)+" ";

        cards[i*2]=new StandardCard(s1);
        cards[i*2+1]=new StandardCard(s1);
    }
    cards[12]=new BonusCard();
    cards[13]=new BonusCard();
    cards[14]=new PenaltyCard();
    cards[15]=new PenaltyCard();
}
Deck::Deck(int size) {
    this->size=size;
    cards=new Card*[size];
    int s=size/2 -2;
    for(int i=0;i<s;i++) {

        string s1=" "+to_string(i+1)+" ";
        if(i<10&&s>10)
            s1+=" ";
        cards[i*2]=new StandardCard(s1);
        cards[i*2+1]=new StandardCard(s1);
    }
    cards[s*2]=new BonusCard();
    cards[s*2+1]=new BonusCard();
    cards[s*2+2]=new PenaltyCard();
    cards[s*2+3]=new PenaltyCard();
}
void Deck:: shuffle() {
    srand(time(NULL));
    for (int i = 0; i < 15; i++) {

        int j = i + rand() % (16 - i);
        Card* temp=cards[i];
        cards[i]=cards[j];
        cards[j]=temp;

    }
}

void Deck:: displayGrid() {
    for(int i=0;i<16;i++) {
        if(cards[i]==nullptr) {
            cout<<"   ";
        }
        else{
            (*(cards[i])).display();
            if(i%4==3) {
                cout<<endl;
            }

        }
    }
}
void Deck:: openCard(int row,int col) {
    int index=(col-1)+(4*(row-1));
    cards[index]->reveal();
}
void Deck:: closeCard(int row,int col) {
    int index=(col-1)+(4*(row-1));
    cards[index]->hide();
}
void Deck:: removeCard(int row,int col) {
    int index=(col-1)+(4*(row-1));
    cards[index]=nullptr;
}
Card* Deck:: getCard(int row,int col) {
    if(row<1||row>4||col<1||col>4) {
        cout<<"Out of range";
        return nullptr;
    }
    int index=(col-1)+(4*(row-1));
    return cards[index];
}

Deck::~Deck() {
    for(int i=0;i<size;i++) {
        (*(cards[i])).~Card();

    }
    delete cards;
}