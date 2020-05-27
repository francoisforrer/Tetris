#ifndef FENETRE_H
#define FENETRE_H

#include <QWidget>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include "Tableau.h"
#include <QCoreApplication>
#include <QGridLayout>

class Fenetre : public QWidget
{
    Q_OBJECT

public:
    Fenetre(QWidget *parent = nullptr);

private:
    QLabel *createLabel(const QString &text);

    Tableau *tableau;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *levelLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};
#endif // FENETRE_H
