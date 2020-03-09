#include<QMainWindow>
#include<QtWidgets>
#include<QPushButton>
#include<QWidget>
#include "holdingwidget.h"
#include "gameview.h"

//GameView * game;

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   HoldingWidget h;
   h.setFixedSize(600,400);
   h.show();

   return app.exec();
}
