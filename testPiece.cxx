/** 
 * Programme test de Piece
 *
 * @file testPiece.cxx
 */

// Utile pour l'affichage
#include <iostream>
#include <assert.h>
#include "Piece.h"
#include "Joueur.h"
#include "Echiquier.h"
#include "Pion.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Fou.h"



// Pour utiliser les flux de iostream sans mettre "std::" tout le temps.
using namespace std;


/**
 * Programme principal
 */
int main( int argc, char** argv )
{
  JoueurNoir jn;
  JoueurBlanc jb;

  Echiquier e;
  e.affiche();

  bool piecesOK;
  piecesOK = jn.placerPieces(e);
  assert(piecesOK);
  piecesOK = jb.placerPieces(e);
  assert(piecesOK);
  Pion p4(1, true);
  assert(!e.placer(&p4));
  Piece *p_empty = NULL;
  assert(!e.placer(p_empty));
  Piece *p_bad = new Pion(10, true);
  assert(!e.placer(p_bad));
  delete p_bad;
  e.affiche();

  e.enleverPiece(1, 8);
  assert(!e.enleverPiece(10, 8));
  assert(!e.enleverPiece(1, 8));
  e.affiche();

  jn.affiche();
  jb.affiche();


  Piece* ptr = e.getPiece(7, 1);

  Piece* ptrPion = e.getPiece(1, 7);


  Piece* ptrTour = e.getPiece(1, 1);

  Piece* ptrFou = e.getPiece(3, 1);


//  Cavalier* cav = dynamic_cast<Cavalier*> (ptr);
//  if(cav==0){ cerr <<"Pas le bon type" << endl; }
//  int z = 0;
//  if (cav->mouvementValide(e, 8, 3)) {  z = 5; } else { z = 6; }
//  cout << z << endl;

//    Pion* pion = dynamic_cast<Pion*> (ptrPion);
//    if(pion==0){ cerr <<"Pas le bon type" << endl; }
//    int z = 0;
//    if (pion->mouvementValide(e, 2, 5)) {  z = 5; } else { z = 6; }
//    cout << z << endl;

//      Tour* tour = dynamic_cast<Tour*> (ptrTour);
//      if(tour==0){ cerr <<"Pas le bon type" << endl; }
//      int z = 0;
//      if (tour->mouvementValide(e, 1, 5)) {  z = 5; } else { z = 6; }
//      cout << z << endl;

        Fou* fou = dynamic_cast<Fou*> (ptrFou);
        if(fou==0){ cerr <<"Pas le bon type" << endl; }
        int z = 0;
        e.enleverPiece(2,2);
        e.affiche();
        if (fou->mouvementValide(e, 2, 2)) {  z = 5; } else { z = 6; }
        cout << z << endl;


  // les objets definis dans cette fonction sont automatiquement détruits.
  // Ex : p1

  return 0;
}
