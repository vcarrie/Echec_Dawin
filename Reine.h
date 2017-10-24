#ifndef REINE_H
#define REINE_H


#include "Piece.h"
#include "Tour.h"
#include "Fou.h"
#include <iostream>

using namespace std;


class Reine : public Fou, public Tour
{
public:
    Reine();
  Reine(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // REINE_H
