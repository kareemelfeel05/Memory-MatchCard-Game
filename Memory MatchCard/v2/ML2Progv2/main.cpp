#include <iostream>
#include <random>
using namespace std;
#include "card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Deck.h"
#include <algorithm>
#include "Player.h"
#include "Game.h"


//class card
Card::Card() {
    faceUp=false;
    value=" Card ";
}
Card::Card( string value) {
    faceUp=false;
    this->value=value;
}
 void Card:: display() {
    if(getfaceUp()) {
        cout<<value;
    }
    else {
        cout<<" * ";
    }
}
bool Card::getfaceUp(){
        return faceUp;
    }
void Card::setFaceup(bool faceup) {
    this->faceUp = faceup;
}
string Card::getValue() {
    return value;
}
 void Card:: setValue(string value) {
    this->value = value;
}
Card::~ Card() = default;

void Card::reveal() {
    this->setFaceup(true);
}
void Card:: hide() {
    this->setFaceup(false);
}



//StandardCard
StandardCard::StandardCard(): Card("Standard Card") {

}
StandardCard::StandardCard( string value):Card(value) {

}

StandardCard:: ~StandardCard()= default;




//Bonus Card
BonusCard::BonusCard():Card(" 7 "){


}
BonusCard::BonusCard(  string value):Card(value) {

}
BonusCard:: ~BonusCard() = default;


//PenaltyCard
PenaltyCard::PenaltyCard():Card(" 8 "){
   //Penalty

}

PenaltyCard::PenaltyCard( string value):Card(value) {

}

PenaltyCard:: ~PenaltyCard() = default;

//Player
Player::Player() {
    name="noName";
    score=0;

}
Player::Player( string name) {
   this-> name=name;
    score=0;
}
string Player:: getName() {
    return name;
}
int Player:: getScore()  {
   return score;
}
void Player:: setScore(int score) {
    this->score=score;
}
void Player:: setName(string &Name) {
    name=Name;
}
void Player:: displayScore() {
    cout<<name<<" : "<<score<<endl;
}

void Player::updateScore(int score) {
    this->score+=score;
}
void Player::displayInfo() {
    cout<<getName()<<" : "<<getScore()<<endl;
}

Player::~Player(){};

Card** Deck:: getCards() {
    return cards;
}
Card* Deck:: getCardByIndex(int index) {
    return cards[index];

}
//game
void Game::upateScoree(Player* p,int s) {
    p->setScore(player1->getScore()+s);

}


int main()
{

    Game* D=new Game();
   D->initializeGame();
    D->getDeck()->displayGrid();
    D->playGame();
   D->~Game();

   delete D;
    return 0;
}
