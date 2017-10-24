#include "Pion.h"
#include "Echiquier.h"

Pion::Pion(int x, bool white) : Piece(x, (white?2:7), white) { first_move = true;}

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{

  bool front_is_empty = (e.getPiece(x, y)==NULL);
  bool move_is_ok = false;

if(m_white){
    if(first_move && y == (m_y+2) && x == m_x){ move_is_ok = true; first_move = false; }

  if(front_is_empty && y == (m_y+1) && x == m_x){ move_is_ok = true; }

  if((x==m_x+1)&&(y==m_y+1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

  if((x==m_x-1)&&(y==m_y+1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

}else{
    if(first_move && y == (m_y-2) && x == m_x){ move_is_ok = true; first_move = false; }

    if(front_is_empty && y == (m_y-1) && x == m_x){ move_is_ok = true; }

    if((x==m_x+1)&&(y==m_y-1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

    if((x==m_x-1)&&(y==m_y-1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

}
  cout << move_is_ok << endl;
  return move_is_ok;
}

char
Pion::type()
{
  return m_white ? 'P' : 'p';
}
