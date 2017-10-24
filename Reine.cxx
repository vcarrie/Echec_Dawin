#include "Reine.h"

Reine::Reine(bool white) : Piece(4,(white?1:8),white) { }


bool
Reine::mouvementValide(Echiquier &e, int x, int y)
{
  cout << "mouvementValide de Reine" << endl;
  return Tour::mouvementValide(e, x, y) || Fou::mouvementValide(e, x, y);
}

char
Reine::type()
{
  return m_white ? 'Q' : 'q';
}

