//
// Created by ASUS on 11/15/2024.
//

#ifndef STANDARDCARD_H
#define STANDARDCARD_H
#include "Card.h"
class StandardCard:public Card {

public:
    StandardCard();
    StandardCard(string value);
    ~StandardCard() override;

};
#endif //STANDARDCARD_H
