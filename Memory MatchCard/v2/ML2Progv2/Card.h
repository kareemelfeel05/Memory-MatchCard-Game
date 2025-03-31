//
// Created by ASUS on 11/14/2024.
//
#include <iostream>
#ifndef CARD_H
#define CARD_H
using namespace std;

class Card {
private:
    bool faceUp;
    string value;
public:
    Card();
    Card(string value);
    virtual void display();
    virtual string getValue();
    virtual bool getfaceUp();
    virtual void setFaceup(bool faceupdown);
    virtual void setValue(string value);
    virtual void reveal();
    virtual void hide();

    virtual ~Card();
};


#endif //CARD_H
