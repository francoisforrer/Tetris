#include "Piece.h"
#include <iostream>
#include <string>


Piece::Piece(){

    m_id=rand() % 7;
    creationPiece();
    for(int i=0; i<(rand() % 4);i++){
        rotationPiece();
    }
}


void Piece::creationPiece(){
	
    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            m_grille[i][j] = 0;
        }
    }

	if (m_id==0){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][2] = 1;
            	m_grille[1][2] = 1;
            	m_grille[2][2] = 1;
            	m_grille[2][1] = 1;
            	
        	}
        	
    	}
	}

	if (m_id==1){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][1] = 1;
            	m_grille[1][1] = 1;
            	m_grille[2][1] = 1;
            	m_grille[2][2] = 1;
            	
        	}
        	
    	}
	}
	
	if (m_id==2){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][1] = 1;
            	m_grille[1][1] = 1;
            	m_grille[2][1] = 1;
            	m_grille[3][1] = 1;
            	
        	}
        	
    	}
	}

	if (m_id==3){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][2] = 1;
            	m_grille[1][2] = 1;
            	m_grille[1][1] = 1;
            	m_grille[2][2] = 1;
            	
        	}
        	
    	}
	}

	if (m_id==4){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][1] = 1;
            	m_grille[1][1] = 1;
            	m_grille[0][2] = 1;
            	m_grille[1][2] = 1;
            	
        	}
        	
    	}
	}

	if (m_id==5){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][2] = 1;
            	m_grille[1][1] = 1;
            	m_grille[1][2] = 1;
            	m_grille[2][1] = 1;
            	
        	}
        	
    	}
	}
	
	if (m_id==6){
		for (int i=0; i<4; i++){
        	for(int j=0; j<4; j++){
            	m_grille[0][1] = 1;
            	m_grille[1][1] = 1;
            	m_grille[1][2] = 1;
            	m_grille[2][2] = 1;
            	
        	}
        	
    	}
	}
}

void Piece::affichagePiece(){
    for (int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                QDebug deb = qDebug();
                deb<<m_grille[i][j];
            }

    }
}

void Piece::rotationPiece(){
    /*int t_grille[4][4]; //grille tampon
    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            t_grille[i][j] = m_grille[i][j];
        }
    }*/

    for (int i=0; i<2; i++){
        for(int j=i; j<3-i; j++){
            int t_grille = m_grille[i][j]; //valeur tampon

            m_grille[i][j] = m_grille[j][3-i];
            m_grille[j][3-i] = m_grille[3-i][3-j];
            m_grille[3-i][3-j] = m_grille[3-j][i];
            m_grille[3-j][i] = t_grille;
        }
    }

}

void Piece::setCoords(int index, int x, int y){
    for(int i=0; i<index; i++){
        coords[i][0] = x;
        coords[i][1] = y;
    }

}

int Piece::CoordXmax(){
    int Xmax = 10;
    for (int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if (m_grille[i][j] = 1){
                    if(Xmax==10)
                        Xmax=j;
                    else if(Xmax<=j){
                            Xmax=j;
                    }
                }
            }
        }
    return Xmax;
}

int Piece::CoordYmax(){
    int Ymax = 10;
    for (int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if (m_grille[i][j] = 1){
                    if(Ymax==10)
                        Ymax=i;
                    else if(Ymax<=i){
                        Ymax=i;
                    }
                }
            }
        }
    return Ymax;
}

int Piece::CoordXmin(){
    int Xmin = 10;
    for (int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if (m_grille[i][j] = 1){
                    if(Xmin==10)
                        Xmin=j;
                    else if(Xmin>=j){
                        Xmin=j;
                    }
                }
            }
        }
    return Xmin;
}

int Piece::CoordYmin(){
    int Ymin = 10;
    for (int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if (m_grille[i][j] = 1){
                    if(Ymin==10)
                        Ymin=i;
                    else if(Ymin>=i){
                    Ymin=i;
                    }
                }
            }
        }
    return Ymin;
}

int Piece::getX(int index){
    return coords[index][0];
}
int Piece::getY(int index){
    return coords[index][1];
}
