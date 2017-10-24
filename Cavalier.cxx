#include "Cavalier.h"
#include "Echiquier.h"
Cavalier::Cavalier(bool white, bool left) : Piece((left?2:7),(white?1:8),white) { }

bool
Cavalier::mouvementValide(Echiquier &ech, int x, int y)
{
    x -=1;
    y -=1;
    int indiceDemande = x + y * 8;
    int IndiceActuel = (m_x-1) + (m_y-1) * 8;

    Cavalier::calcul_move_possible(m_x-1, m_y-1);
    bool is_in_tab = false;
    bool is_not_empty = (ech.getPiece(x+1, y+1)!= NULL);
    bool move_is_okay = true;

    for ( int i = 0; i < 8; i++ ) {
        if(liste_move[i]==indiceDemande){ is_in_tab = true; }
         cout << liste_move[i] << endl;
    }

    if( is_not_empty){ if(ech.getPiece(x+1, y+1)->get_white() == m_white){ move_is_okay=false; } }

    Piece *p = ech.getPiece(x, y);
    if (p)
    {
        cout << p->type() << endl;
        cout << x << endl;
        cout << y << endl;
    }
    cout << is_not_empty << endl;
cout << is_in_tab << endl;
cout << move_is_okay << endl;


  cout << "mouvementValide de Cavalier" << endl;
  return (is_in_tab && move_is_okay);
}

char
Cavalier::type()
{
  return m_white ? 'C' : 'c';
}

int*
Cavalier::get_move_possible()
{
  return liste_move;
}

void
Cavalier::calcul_move_possible(int x, int y)
{
    if ((x-1>=0)&&(y-2>=0)){ liste_move[0] = (x-1)+(y-2)*8; }else { liste_move[0] = -1; }
    if ((x+1<=7)&&(y-2>=0)){ liste_move[1] = (x+1)+(y-2)*8; }else { liste_move[1] = -1; }
    if ((x-1>=0)&&(y+2<=7)){ liste_move[2] = (x-1)+(y+2)*8; }else { liste_move[2] = -1; }
    if ((x+1<=7)&&(y+2<=7)){ liste_move[3] = (x+1)+(y+2)*8; }else { liste_move[3] = -1; }
    if ((x+2<=7)&&(y+1<=7)){ liste_move[4] = (x+2)+(y+1)*8; }else { liste_move[4] = -1; }
    if ((x-2>=0)&&(y-1>=0)){ liste_move[5] = (x-2)+(y-1)*8; }else { liste_move[5] = -1; }
    if ((x+2<=7)&&(y-1>=0)){ liste_move[6] = (x+2)+(y-1)*8; }else { liste_move[6] = -1; }
    if ((x-2>=0)&&(y+1<=7)){ liste_move[7] = (x-2)+(y+1)*8; }else { liste_move[7] = -1; }

}
