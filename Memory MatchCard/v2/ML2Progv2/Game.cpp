//
// Created by yousef on 12/16/2024.
//

#include "Game.h"
#include "Player.h"
#include <iostream>

using namespace std;


Game::Game() {
    player1=new Player("noName");
    player2=new Player("noName");
    deck=new Deck();
    remaningCards=16;
    currentPlayer=player1;
    skipNextTurn=false;
}
Game::Game(string player1, string player2) {
    this->player1=new Player(player1);
    this-> player2=new Player(player2);
    deck=new Deck();
    remaningCards=16;
    currentPlayer=this->player1;
    skipNextTurn=false;

}
Game::Game(Player *player1, Player *player2){
    this->player1=player1;
    this->player2=player2;
    deck=new Deck();
    remaningCards=16;
    currentPlayer=player1;
    skipNextTurn=false;

}
////////////////////////////////////////////////////////////////////////////////
void Game:: initializeGame()  {
    cout<<"please enter player 1 name :";
    string name1;
    cin>>name1;
    cout<<"please enter player 2 name :";
    string name2;
    cin>>name2;
    deck=new Deck();
   // deck->shuffle();
    player1->setScore(0);
    player1->setName(name1);
    player2->setScore(0);
    player2->setName(name2);
}
Player* Game:: getPlayer1()  {
    return player1;
}

void Game:: setPlayer1(Player *player1) {
    this->player1 = player1;
}

Player * Game:: getPlayer2()  {
    return player2;
}

void Game:: setPlayer2(Player *player2) {
    this->player2 = player2;
}

Deck * Game:: getDeck()  {
    return deck;

}

void Game::setDeck(Deck *deck) {
    this->deck = deck;
}
bool Game::isOver() {

    return remaningCards<=1;
}
Card* Game::getCard(Player p,int cardnum) {
cout<<"Player "<<p.getName()<<" Please enter row and coloum of card "<<cardnum<<endl;
    int row,col;
    cin>>row;
    cin>>col;
   Card* card= deck->getCard(row,col);
    while (card==nullptr||card->getfaceUp()/*||card->getValue()=="   "*/) {

      cout<<"Invalid card please enter again"<<endl;
        cout<<"Player "<<p.getName()<<" Please enter row and coloum of card "<<cardnum<<endl;
        cin>>row;
        cin>>col;
        card= deck->getCard(row,col);
    }
  return deck->getCard(row,col);
}

void Game::switchPlayer() {
if(skipNextTurn) {
skipNextTurn=false;
    return;

}




    if(currentPlayer==player1) {
        currentPlayer=player2;
    }
    else {
        currentPlayer=player1;
    }
}
Player* Game::getCurrentPlayer() {
    return currentPlayer;
}
void Game::Taketurn( Card *card1, Card *card2) {
    card1->reveal();
    card2->reveal();
    deck->displayGrid();
    cout<<endl;
    int effect=0;
    int  value1= stoi(card1->getValue());
    int  value2=stoi(card2->getValue());

if(value1!=value2) {
  if(value1==7 ||value2== 7 ||value1== 8 ||value2== 8 ) {
remaningCards--;
      switch (value1) {
      case  7 :effect++;card1->setValue("   ");break;
      case  8 :effect--;card1->setValue("   ");break;
          default:card1->hide();
      }
        switch (value2) {
            case  7 :effect++;card2->setValue("   ");break;
            case  8 :effect--;card2->setValue("   ");break;
            default:card2->hide();
        }

 }
    else
        {
        card1->hide();
        card2->hide();
        cout<<"Cards do not match"<<endl;
       }

  currentPlayer->updateScore(effect);
    switchPlayer();


}


    else {
        int option=0;
      switch (value1) {
          case  8 :
          card1->setValue("   ");card2->setValue("   ");
          cout<<"select option 1: lose 1 point and skip the next turn"<<endl;
          cout<<"select option 2: -2 "<<endl;
          cin>>option;
          while (option!=1&&option!=2) {
              cout<<"Invalid option please enter again"<<endl;
              cout<<"select option 1: lose 1 point and skip the next turn"<<endl;
              cout<<"select option 2: -2 "<<endl;
              cin>>option;
          }

          if(option==1) {
              currentPlayer->updateScore(-1);
              switchPlayer();
                skipNextTurn=true;
          }
          else {
              currentPlayer->updateScore(-2);
              switchPlayer();
          }

          break;

          case  7 :
          card1->setValue("   ");card2->setValue("   ");
          cout<<"select option 1: another round"<<endl;
          cout<<"select option 2: +2 "<<endl;

            cin>>option;
          while (option!=1&&option!=2) {
              cout<<"Invalid option please enter again"<<endl;
              cout<<"select option 1: another round"<<endl;
              cout<<"select option 2: +2 "<<endl;
              cin>>option;
          }

          if(option==1) {
              currentPlayer->updateScore(1);
          }
          else {
              currentPlayer->updateScore(2);
              switchPlayer();
          }
          break;

            default:
                currentPlayer->updateScore(1);
          card1->setValue("   ");card2->setValue("   ");
        }
     remaningCards-=2;
}
cout << "Current scores:\n";
    cout << player1->getName() << " : " << player1->getScore() << endl;
    cout << player2->getName() << " : " << player2->getScore() << endl;
if(!isOver())
    deck->displayGrid();
}


void Game::playGame() {
    while(!isOver()) {


        cout<<"Player "<<getCurrentPlayer()->getName()<<"'s turn"<<endl;
        Card* card1=getCard(*getCurrentPlayer(),1);
        Card* card2=getCard(*getCurrentPlayer(),2);
        while (card1==card2) {
            cout<<"You selected same card twice"<<endl;
            cout<<"Please enter another Card"<<endl;
            card2=getCard(*getCurrentPlayer(),2);
        }

        Taketurn(card1,card2);
      //  system("cls");
        if(isOver()) {
            break;
        }


    }
    cout<<"Game Over"<<endl;
    if(player1->getScore()==player2->getScore()) {
        cout<<"draw";
    }
    else {
        if(player1->getScore()>player2->getScore()) {
            cout<<"Player 1 is winner";
            player1->displayInfo();
        } else {
            cout<<"Player 2 is winner";
            player2->displayInfo();
        }
    }
}

Game::~Game() {
    delete player1;
    delete player2;
    delete deck;
}
