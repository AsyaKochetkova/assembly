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
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    clearScreenAct = new QAction("C&learScreen", this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()), scribbleArea, SLOT(clearScreen()));

    circlePenColorAct = new QAction("CirclePenColor",this);
    connect(circlePenColorAct, SIGNAL(triggered()), this, SLOT(circlePenColor()));

    circleBrushAct = new QAction("CircleBrush",this);

    circleWidthAct = new QAction("CircleWidth",this);

    arrowPenColorAct = new QAction("ArrowPenColor",this);

    arrowWidthAct = new QAction("ArrowWidth",this);


    file = new QMenu(tr("File"),this);
    file->addAction(quit);

    optionMenu = new QMenu(tr("Options"),this);
    optionMenu->addAction(circlePenColorAct);
    optionMenu->addAction(circleBrushAct);
    optionMenu->addAction(circleWidthAct);
    optionMenu->addAction(arrowPenColorAct);
    optionMenu->addAction(arrowWidthAct);




    menuBar()->addMenu(file);
    menuBar()->addMenu(optionMenu);
    menuBar()->addSeparator();
    menuBar()->addAction(clearScreenAct);

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

    deleteBut = new QPushButton(tr("&Delete"),this);
    deleteBut->setCheckable(false);
    deleteBut->setShortcut(tr("CTRL+D"));
    deleteBut->setChecked(false);
    connect(deleteBut, SIGNAL(clicked()), scribbleArea, SLOT(clickedDeleteButton()));

    toolbar = addToolBar("main toolbar");
    toolbar->addWidget(circle);
    toolbar->addWidget(arrow);
    toolbar->addWidget(deleteBut);
}

void Appearance::circlePenColor()
{
    QColor newColor = QColorDialog::getColor(scribbleArea->circlePenColor());

    if (newColor.isValid())
        scribbleArea->setCirclePenColor(newColor);
}
