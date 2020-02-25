#include<QMainWindow>
#include<QtWidgets>
#include<QPushButton>
#include<QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   StartMenuWindow game;   //changed to StartMenuWindow
   game.setFixedSize(600,480);
   game.show();

   return app.exec();
}
