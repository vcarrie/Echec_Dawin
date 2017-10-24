#ifndef ROI_H
#define ROI_H

#include "Piece.h"
#include <iostream>

using namespace std;



class Roi : public Piece
{
public:
    Roi();
  Roi(bool white);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();
};

#endif // ROI_H
