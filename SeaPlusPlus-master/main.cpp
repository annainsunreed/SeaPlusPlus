#include<QMainWindow>
#include<QtWidgets>
#include<QPushButton>
#include<QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  HoldingWindow game;   //changed to be the holdingwindow
  game.setFixedSize(600,480);
  game.show();

  return app.exec();
}
