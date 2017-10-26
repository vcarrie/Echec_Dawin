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

    bool piecesOK;
    piecesOK = jn.placerPieces(e);
    assert(piecesOK);
    piecesOK = jb.placerPieces(e);
    assert(piecesOK);

    int x_before, y_before, x_after, y_after;
    bool joueur = true; //White player = true, Black player = false
    bool endGame = false;
    string joueurString;



    cout << "La partie commence !" << endl;
    cout << e.getPiece(5,8)->isRoi() << endl;
    while(!endGame){
        e.affiche();

        joueurString = joueur?"blanc":"noir";

        cout << endl << "Au tour du joueur " << joueurString << " !" << endl << endl;

        cout << "Quelle pièce voulez-vous déplacer ?" << endl;
        bool x1 = true;
        bool x2 = true;
        bool y1 = true;
        bool y2 = true;

        while(x1){
            cout << "x : ";
            cin >> x_before;
            cout << endl;

            if((x_before >= 1) && (x_before <= 8)){ x1 = false; }
        }


        while(y1){
            cout << "y : ";
            cin >> y_before;
            cout << endl;

            if((y_before >= 1) && (y_before <= 8)){ y1 = false; }
        }

        cout << "Où voulez-vous la poser ?" << endl;


         while(x2){
            cout << "x : ";
            cin >> x_after;
            cout << endl;

            if((x_after >= 1) && (x_after <= 8)){ x2 = false; }
         }

        while(y2){
            cout << "y : ";
            cin >> y_after;
            cout << endl;

            if((y_after >= 1) && (y_after <= 8)){ y2 = false; }
         }

        if(e.getPiece(x_before, y_before)->get_white() == joueur){
            if(e.deplacer(e.getPiece(x_before, y_before), x_after, y_after)){
                system("clear");
                joueur = !joueur;
            }
            else {
                system("clear");
                cout << "Mouvement invalide ! Veuillez recommencer." << endl;
            }
        }
        else{
            system("clear");
            cout << "Vous essayez de déplacer le pion de votre adversaire !" << endl;
        }
    }

    return 0;
}
