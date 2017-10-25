#ifndef PION_H
#define PION_H

#include "Piece.h"
#include <iostream>

using namespace std;


class Pion : public Piece
{
private:
    bool first_move;
public:
  Pion();
  Pion(int x, bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // PION_H
