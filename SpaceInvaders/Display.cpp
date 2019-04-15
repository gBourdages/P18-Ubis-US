#include "Display.h"



Display::Display() {
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1918, 1015);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setFocusPolicy(Qt::StrongFocus);

    setScene(scene);
    
    setCacheMode(QGraphicsView::CacheBackground);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setDragMode(QGraphicsView::ScrollHandDrag);

    resize(1280, 720);
}


Display::~Display() {

}

void Display::addSprite(Sprites* s) {
    scene->addItem(s);
    connect(s, &Sprites::deleteThis, this, &Display::removeSprites);
    connect(this, &Display::pause, s, &Sprites::pause);
    connect(s, &Sprites::score, this, &Display::scorePlus);
}

void Display::removeSprites(Sprites* s) {
    scene->removeItem(s);
    delete s;

}

void Display::scorePlus() {
    score += 10;
}







