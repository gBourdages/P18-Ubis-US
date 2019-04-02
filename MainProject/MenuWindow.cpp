
#include "MenuWindow.h"

MenuWindow::MenuWindow(const char *titre) {
    widget = new QWidget;
    setCentralWidget(widget);

    setWindowTitle(tr(titre));
    setMinimumSize(160, 160);
    resize(420, 320);

    //----------Création Actions----------

    ActFichierOuvrir = new QAction(tr("&Ouvrir"), this);
    connect(ActFichierOuvrir, &QAction::triggered, this, &MenuWindow::FichierOuvrir);

    ActFichierFermer = new QAction(tr("&Fermer"), this);
    connect(ActFichierFermer, &QAction::triggered, this, &MenuWindow::FichierFermer);

    ActEditionTrouver = new QAction(tr("&Trouver"), this);
    connect(ActEditionTrouver, &QAction::triggered, this, &MenuWindow::EditionTrouver);

    //----------Création Menus------------

    FichierMenu = menuBar()->addMenu(tr("&Fichier"));
    FichierMenu->addAction(ActFichierOuvrir);
    FichierMenu->addAction(ActFichierFermer);

    EditionMenu = menuBar()->addMenu(tr("&Edition"));
    EditionMenu->addAction(ActEditionTrouver);

    //----------Création des Widgets------

    button = new QPushButton(tr("&CLIQUER ICI!"), this);
    connect(button, &QPushButton::clicked, this, &MenuWindow::Cliquer);


    

    //----------Création du layout--------

    layout = new QVBoxLayout;
    layout->addWidget(button);
    widget->setLayout(layout);





    show();
}


MenuWindow::~MenuWindow() {

}

void MenuWindow::FichierOuvrir() {

}

void MenuWindow::FichierFermer() {

}

void MenuWindow::EditionTrouver() {

}

void MenuWindow::Cliquer() {

}


