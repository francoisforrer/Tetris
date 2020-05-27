#ifndef TABLEAU_H
#define TABLEAU_H
#include <iostream>
#include "Piece.h"
#include <QFrame>

#include <QElapsedTimer>


#define HEIGHT 22
#define WIDTH 10



class Tableau : public QFrame{
private:
    QElapsedTimer* m_timer = new QElapsedTimer(); //chrono
    int m_points; //pts du joueur
    bool m_enCours; //1 = debuté
    bool m_enPause; //1 = en pause
    Piece* m_pieceCur;  //piece courante
    Piece* m_pieceSuiv; //piece suivante
    int tab[HEIGHT][WIDTH]; //largeur

public:
    Tableau();
    QElapsedTimer* getTime(); //return le temps ecoulé

    void quit(); //ferme le jeu
    //void pause(); //met en pause le jeu

    void check(); //check à chaque fin de tour
    bool isLineComplete(); //verifie que la ligne est finie
    bool isGameOver(); //verifie si on a perdu

    void deleteLine(); //supprime les lignes completés
    void pieceSuivante(); //passe a la piece d'apres

    void resetTableau(); //efface tout et restart
    void afficherTableau(); //affiche les pieces du tableau

public slots:
    void start();
    void pause();

signals:
    void scoreChanged(int score);
    void levelChanged(int level);
    void linesRemovedChanged(int numLines);
};

#endif // TABLEAU_H
