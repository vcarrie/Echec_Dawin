#include "Tour.h"
#include "Echiquier.h"


Tour::Tour() { }

Tour::Tour(bool white, bool left) : Piece((left?1:8),(white?1:8),white) { }

bool
Tour::mouvementValide(Echiquier &e, int x, int y)
{
    int direction = 0;

    if((x < 1) || (y < 1) || (x > 8) || (y > 8)){ return false; } //hors limite
    if(((m_x == x)&&(y == m_y))){ return false; }//même position ?
    if(((m_x != x)&&(y != m_y))){ return false; }//déplacement hors de l'échiquier ?

    if(e.getPiece(x, y) != NULL){
        if(e.getPiece(x, y)->get_white() == m_white){ return false; }
    }//On regarde si la pièce est de la même couleur que la couleur de la pièce déplacée

    //path is blocked or not?
    if((x==m_x)&&(y>m_y)){ direction = 0;}//bas
    if((x==m_x)&&(y<m_y)){ direction = 1;}//haut
    if((x>m_x)&&(y==m_y)){ direction = 2;}//gauche
    if((x<m_x)&&(y==m_y)){ direction = 3;}//droite

    switch (direction) { //en fonction de la direction on regarde si il n'y a aucune case sur le chemin
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
