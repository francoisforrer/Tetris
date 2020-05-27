#ifndef _Piece_h
#define _Piece_h

#include <time.h>
#include <QDebug>

class Piece{
private:
 	int m_id; //identifiant des pieces
    int m_grille[4][4]; //definition de la piece dans un espace 4x4
    int coords[4][2]; //cordonnes piece
 public:
    Piece(); //constructeur

 	//methodes
 	void creationPiece(); //fct utilisé dans le constructeur pour creer la piece
 	void affichagePiece(); //debug
 	void rotationPiece();

    void setCoords(int index, int x, int y);
    int getX(int index);
    int getY(int index);
};

#endif
