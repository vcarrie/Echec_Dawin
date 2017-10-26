#include "Tour.h"
#include "Echiquier.h"


Tour::Tour() { }

Tour::Tour(bool white, bool left) : Piece((left?1:8),(white?1:8),white) { }

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
    int direction = 0;

    if((x < 1) || (y < 1) || (x > 8) || (y > 8)){ return false; } //hors limite
    if(((m_x == x)&&(y == m_y))){ return false; }//same place
    if(((m_x != x)&&(y != m_y))){ return false; }//move is not straight

    if(e.getPiece(x, y) != NULL){
        if(e.getPiece(x, y)->get_white() == m_white){ return false; }
    }//Same color on target

    //path is blocked or not?
    if((x==m_x)&&(y>m_y)){ direction = 0;}//down
    if((x==m_x)&&(y<m_y)){ direction = 1;}//up
    if((x>m_x)&&(y==m_y)){ direction = 2;} //right
    if((x<m_x)&&(y==m_y)){ direction = 3;}//left

    switch (direction) {
    case 0:
        for ( int i = m_y+1; i < y; i++ ) {
            if(e.getPiece(x, i)!=NULL){ return false; }
        }
        break;
    case 1:
        for ( int i = m_y-1; i > y; i-- ) {
            if(e.getPiece(x, i)!=NULL){ return false; }
        }
        break;
    case 2:
        for ( int i = m_x+1; i < x; i++ ) {
            if(e.getPiece(y, i)!=NULL){ return false; }
        }
        break;
    case 3:
        for ( int i = m_x-1; i > x; i++ ) {
            if(e.getPiece(y, i)!=NULL){ return false; }
        }
        break;
    default:
        return false;
        break;
    }

    return true;
}

char
Tour::type()
{
    return m_white ? 'T' : 't';
}
