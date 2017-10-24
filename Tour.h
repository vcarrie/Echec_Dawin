#ifndef TOUR_H
#define TOUR_H

#include "Piece.h"
#include <iostream>

using namespace std;


class Tour : virtual public Piece
{
public:
  Tour();
  Tour(bool white, bool left);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // TOUR_H
