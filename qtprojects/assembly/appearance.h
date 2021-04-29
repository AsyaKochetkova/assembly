#ifndef APPEARANCE_H
#define APPEARANCE_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QtWidgets>


class ScribbleArea;

class Appearance : public QMainWindow{
    Q_OBJECT

public:
    Appearance(QWidget *parent=0);

private slots:
    void circlePenColor();

private:
    void createMenus();
    void createTools();

    ScribbleArea *scribbleArea;

    QMenu *file;
    QMenu *optionMenu;
    QAction *quit;
    QAction *clearScreenAct;
    QAction *circlePenColorAct;
    QAction *circleBrushAct;
    QAction *circleWidthAct;
    QAction *arrowPenColorAct;
    QAction *arrowWidthAct;
    QToolBar *toolbar;
    QPushButton *circle;
    QPushButton *arrow;
    QPushButton *deleteBut;


};






#endif // APPEARANCE_H
