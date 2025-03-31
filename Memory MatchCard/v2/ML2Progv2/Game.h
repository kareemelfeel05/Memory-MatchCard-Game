//
// Created by ASUS on 11/15/2024.
//

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.h"
#include "Deck.h"
#include "Player.h"
using namespace std;
#include <cstddef> // Include this to use std::byte

class Game {
private:
    Player *player1;
    Player *player2;
    Deck* deck;
    int remaningCards;
    Player* currentPlayer;
    bool skipNextTurn;
public:
    Game();
    Game(string player1, string player2);
    Game(Player *player1, Player *player2);

    void initializeGame() ;
    Player *getPlayer1();
    Player *getPlayer2();
    Deck *getDeck();
    void setPlayer1(Player *player1);
    void setPlayer2(Player *player2);
    void setDeck(Deck *deck);
    void Taketurn(Player* p, int row1, int col1, int row2,int clo2);
    void Taketurn( Card* card1, Card* card2);
    bool isOver();
    void upateScoree(Player* p,int s);
    void playGame();
    Card* getCard(Player p,int cardnum);
    void switchPlayer();
    Player* getCurrentPlayer();


    ~Game();

};
#endif //GAME_H
