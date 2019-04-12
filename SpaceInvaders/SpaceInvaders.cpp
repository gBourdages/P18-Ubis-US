#include <QApplication>

#include "MainWindow.h"

int main( int argc, char ** argv ) {
    QApplication app(argc, argv);
    
    //Game game;

    //game.show();

    MenuWindow gui("Exam Invaders");
    gui.show();

    app.exec();
}
