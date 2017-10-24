#ifndef CAVALIER_H
#define CAVALIER_H

#include "Piece.h"
#include <iostream>

using namespace std;

class Cavalier : public Piece
{
public:
  Cavalier();
  int* get_move_possible();
  Cavalier(bool white, bool left);
  void calcul_move_possible(int x, int y);
  bool mouvementValide(Echiquier &e, int x, int y);
  char type();

private:
  int liste_move[8];
};
#endif // CAVALIER_H
