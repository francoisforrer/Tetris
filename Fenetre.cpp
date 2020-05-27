#include "Fenetre.h"


Fenetre::Fenetre(QWidget *parent) : QWidget(parent), tableau(new Tableau) {
    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

    connect(startButton, &QPushButton::clicked, tableau, &Tableau::start);
    connect(quitButton , &QPushButton::clicked, qApp, &QCoreApplication::quit);
    connect(pauseButton, &QPushButton::clicked, tableau, &Tableau::pause);
#if __cplusplus >= 201402L
    connect(board, &TetrixBoard::scoreChanged,
            scoreLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::levelChanged,
            levelLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::linesRemovedChanged,
            linesLcd, qOverload<int>(&QLCDNumber::display));
#else
    connect(tableau, &Tableau::scoreChanged,
            scoreLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(tableau, &Tableau::levelChanged,
            levelLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(tableau, &Tableau::linesRemovedChanged,
            linesLcd, QOverload<int>::of(&QLCDNumber::display));
#endif
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("NEXT")), 0, 0);
    layout->addWidget(nextPieceLabel, 1, 0);
    layout->addWidget(createLabel(tr("LEVEL")), 2, 0);
    layout->addWidget(levelLcd, 3, 0);
    layout->addWidget(startButton, 4, 0);
    layout->addWidget(tableau, 0, 1, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 0, 2);
    layout->addWidget(scoreLcd, 1, 2);
    layout->addWidget(createLabel(tr("LINES REMOVED")), 2, 2);
    layout->addWidget(linesLcd, 3, 2);
    layout->addWidget(quitButton, 4, 2);
    layout->addWidget(pauseButton, 5, 2);
    setLayout(layout);

    setWindowTitle(tr("Tetrix"));
    resize(550, 370);
}


QLabel *Tableau::createLabel(const QString &text){
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}

