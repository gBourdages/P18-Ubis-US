
#include <QApplication>
#include "CommunicationFPGA.h"
#include "MenuWindow.h"

int main( int argc, char ** argv ) {
    QApplication app(argc, argv);

    MenuWindow gui("TITRE");

    app.exec();
}
