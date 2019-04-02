#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainwindow>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>

class MenuWindow : public QMainWindow {
    Q_OBJECT
public:
    MenuWindow(const char *titre = 0);
    ~MenuWindow();

public slots:
    void FichierOuvrir();
    void FichierFermer();
    void EditionTrouver();
    void Cliquer();

private:
    QWidget *widget;
    QVBoxLayout *layout;

    QTextEdit *textEdit;
    QPushButton *button;

    QMenu *FichierMenu;
    QMenu *EditionMenu;

    QAction *ActFichierOuvrir;
    QAction *ActFichierFermer;
    QAction *ActEditionTrouver;




};

#endif
