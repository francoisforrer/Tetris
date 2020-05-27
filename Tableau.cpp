#include "Tableau.h"


Tableau::Tableau(){
    m_points = 0;
    //m_timer->start();
    m_pieceCur = new Piece();
    m_pieceSuiv = new Piece();
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            tab[i][j]=0;
        }
    }
}

QElapsedTimer* Tableau::getTime(){
    qDebug()<<(m_timer->nsecsElapsed())/1000000000<<"seconds";
    return m_timer;
}

void Tableau::quit(){
    m_enCours = false;
}

void Tableau::pause(){
    m_enPause = true;
}

void Tableau::check(){
    if(isGameOver())
        quit();
    if(isLineComplete())
        deleteLine();
}

bool Tableau::isLineComplete(){
    int sum=0;
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            sum+=tab[i][j];
        }
        if(sum==WIDTH) //si la somme d'une ligne est egale à la largeur, alors la ligne est pleine
            return true;
        else
            sum=0;
    }
    return false;
}

bool Tableau::isGameOver(){
    //si on peut pas descendre
    return false;
}

void Tableau::deleteLine(){ //cherche toutes les lignes completes, et il descend toutes les lignes en haut
    int sum=0;
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            sum+=tab[i][j];
        }
        if(sum==WIDTH){ //si la somme d'une ligne est egale à la largeur, alors la ligne est pleine
            
            for(int z=0; z<WIDTH; z++){
                tab[i][z]=0;
            }
            if(i!=0){ //on deplace les lignes vers le bas d'un cran
                for(int new_i=i; new_i>0;new_i--){
                    for(int new_j=0; new_j<WIDTH; new_j++){
                        tab[new_i][new_j] = tab[new_i-1][new_j];
                    }
                }
            }
        }
        sum=0;
    }

}

void Tableau::resetTableau(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            tab[i][j]=0;
        }
    }
}

void Tableau::afficherTableau(){
    for(int i=0; i<HEIGHT; i++){
        QDebug deb = qDebug();
        for(int j=0; j<WIDTH; j++){
            deb<<tab[i][j];
        }

    }
}

void Tableau::pieceSuivante(){
    m_pieceCur = m_pieceSuiv;
    m_pieceSuiv = new Piece();
}

