#include "appearance.h"
#include "scribblearea.h"
#include <iostream>


Appearance::Appearance(QWidget *parent): QMainWindow(parent){

    scribbleArea = new ScribbleArea;
    setCentralWidget(scribbleArea);

    createMenus();
    createTools();
    resize(500,500);
    setWindowTitle(QDir::currentPath()+"/text.txt");
}

void Appearance::createMenus(){
      quit = new QAction("&Quit", this);

      file = new QMenu(tr("File"),this);
      menuBar()->addMenu(file);
      file->addAction(quit);

      connect(quit, &QAction::triggered, qApp, &QApplication::quit);

}

void Appearance::createTools(){

    circle = new QPushButton(tr("&Circle"),this);
    circle->setCheckable(true);
    circle->setChecked(false);
    connect(circle, SIGNAL(clicked()), scribbleArea, SLOT(clickedCircleButton()));

    arrow = new QPushButton(tr("&Arrow"),this);
    arrow->setCheckable(true);
    arrow->setChecked(false);
    connect(arrow, SIGNAL(clicked()), scribbleArea, SLOT(clickedArrowButton()));

    toolbar = addToolBar("main toolbar");
    toolbar->addWidget(circle);
    toolbar->addWidget(arrow);
}
