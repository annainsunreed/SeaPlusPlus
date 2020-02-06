#include<QMainWindow>
#include<QtWidgets>
#include<QPushButton>
#include<QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GameWindow game;
    game.show();

    return app.exec();
}
