//
// Created by ASUS on 11/15/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
class Player {
private:
    string name;
    int score;
public:
    Player();
    Player(string name);
    string getName();
    int getScore() ;
    void setScore(int score);
    void setName(string &Name);
    void displayScore();
    void updateScore(int score);
    void displayInfo();



    ~Player();



};
#endif //PLAYER_H
