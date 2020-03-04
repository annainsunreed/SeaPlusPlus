#include"tutorialwindow.h"

TutorialWindow::TutorialWindow(QWidget *parent) : QWidget(parent) {
   label = new QLabel("You have opened the TutorialWindow");
   layout = new QVBoxLayout;
   back_button=new QPushButton("back");

   layout->addWidget(label);
   layout->addWidget(back_button);
   setLayout(layout);

   connect(back_button,SIGNAL(pressed()),this,SLOT(handleTutorialWinBackPressed()));
}

TutorialWindow::~TutorialWindow(){}

void TutorialWindow::handleTutorialWinBackPressed(){
    emit tutorialWinBackPressed();
}
