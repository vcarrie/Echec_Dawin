#include "Pion.h"
#include "Echiquier.h"

Pion::Pion(int x, bool white) : Piece(x, (white?2:7), white) { first_move = true;}

bool
Pion::mouvementValide(Echiquier &e, int x, int y)
{

    bool front_is_empty = (e.getPiece(x, y)==NULL);
    bool move_is_ok = false;

    if(m_white){ //si le pion est blanc
        if(first_move && y == (m_y+2) && x == m_x){ move_is_ok = true; first_move = false; } //Si premier mouvment et qu'il veut avancer de deux cases

        if(front_is_empty && y == (m_y+1) && x == m_x){ move_is_ok = true; } //Si il veut avancer de un et qu'il n'y a rien devant lui

        if((x==m_x+1)&&(y==m_y+1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; } //Si il veut aller en diagonale droite et qu'il y ai une pièce noir

        if((x==m_x-1)&&(y==m_y+1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; } //Si il veut aller en diagonale gauche et qu'il y ai une pièce noir

    }else{ //Pareil mais pour la couleur oposée
        if(first_move && y == (m_y-2) && x == m_x){ move_is_ok = true; first_move = false; }

        if(front_is_empty && y == (m_y-1) && x == m_x){ move_is_ok = true; }

        if((x==m_x+1)&&(y==m_y-1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

        if((x==m_x-1)&&(y==m_y-1)&&(e.getPiece(x, y)!=NULL)){ move_is_ok = true; }

    }
    return move_is_ok;
}

char
Pion::type()
{
    return m_white ? 'P' : 'p';
}
