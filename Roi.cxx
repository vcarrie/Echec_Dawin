#include "Roi.h"

#include "Echiquier.h"


Roi::Roi(bool white) : Piece(5,(white?1:8),white) { is_roi = true; }

bool
Roi::mouvementValide(Echiquier &e, int x, int y)
{
    if((x < 1) || (y < 1) || (x > 8) || (y > 8)){ return false; } //hors limite ?
    if(((m_x == x)&&(y == m_y))){ return false; }//meme place ?

    if(e.getPiece(x, y) != NULL){ //On regarde si il y a une pièce sur la position où le roi veut aller
        if(e.getPiece(x, y)->isWhite()== m_white){ //on regarde si cette pièce n'est pas allié
            return false;
        }
    }

        if(!((abs(m_x - x) == 0 || abs(m_x - x) == 1) && (abs(m_y - y) == 0 || abs(m_y - y) == 1))){ return false; } //on regarde si le roi se déplace à une seule case autout de lui

  return true;
}

char
Roi::type()
{
  return m_white ? 'R' : 'r';
}
