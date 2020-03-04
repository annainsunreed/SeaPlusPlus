#include<QMainWindow>
#include<QtWidgets>
#include<QPushButton>
#include<QWidget>
#include "holdingwidget.h"

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   HoldingWidget h;
   h.setFixedSize(600,480);
   h.show();

   return app.exec();
}
