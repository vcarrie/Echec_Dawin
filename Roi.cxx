#include "Roi.h"


Roi::Roi(bool white) : Piece(5,(white?1:8),white) { }

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    if((x < 1) || (y < 1) || (x > 8) || (y > 8)){ return false; } //hors limite
    if(((m_x == x)&&(y == m_y))){ return false; }//same place


  cout << "mouvementValide de Roi" << endl;
  return false;
}

char
Roi::type()
{
  return m_white ? 'R' : 'r';
}
