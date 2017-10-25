#include "Fou.h"

#include "Echiquier.h"

Fou::Fou() { }

Fou::Fou(bool white, bool left) : Piece((left?3:6),(white?1:8),white) { }

bool
Fou::mouvementValide(Echiquier &e, int x, int y)
{
    int direction = 0;

    if((x < 1) || (y < 1) || (x > 8) || (y > 8)){ return false; } //hors limite
    if(((m_x == x)&&(y == m_y))){ return false; }//same place
    if(abs(m_x - x) != abs(m_y - y)){ return false; }//move is not diagonal

    if(e.getPiece(x, y) != NULL){
        if(e.getPiece(x, y)->get_white() == m_white){ return false; }
    }//Same color on target

    //path is blocked or not?
    if((x>m_x)&&(y>m_y)){ direction = 0;}//right-down
    if((x<m_x)&&(y>m_y)){ direction = 1;}//down-left
    if((x>m_x)&&(y<m_y)){ direction = 2;} //right-up
    if((x<m_x)&&(y<m_y)){ direction = 3;}//left-up

    switch (direction) {
    case 0:
        for ( int i = 1; i < abs(m_x - x); i++ ) {
            if(e.getPiece(m_x + i, m_y + i)!=NULL){ return false; }
        }
        break;
    case 1:
        for ( int i = 1; i < abs(m_x - x); i++ ) {
            if(e.getPiece(m_x - i, m_y + i)!=NULL){ return false; }
        }
        break;
    case 2:
        for ( int i = 1; i < abs(m_x - x); i++ ) {
            if(e.getPiece(m_x + i, m_y - i)!=NULL){ return false; }
        }
        break;
    case 3:
        for ( int i = 1; i < abs(m_x - x); i++ ) {
            if(e.getPiece(m_x - i, m_y - i)!=NULL){ return false; }
        }
        break;
    default:
        return false;
    }

    return true;
}

char
Fou::type()
{
    return m_white ? 'F' : 'f';
}
