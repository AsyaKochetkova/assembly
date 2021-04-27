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
private:
    void createMenus();
    void createTools();

    ScribbleArea *scribbleArea;

    QMenu *file;
    QAction *quit;
    QToolBar *toolbar;
    QPushButton *circle;
    QPushButton *arrow;


};






#endif // APPEARANCE_H
