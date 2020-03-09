#include"tutorialwindow.h"

TutorialWindow::TutorialWindow(QWidget *parent) : QWidget(parent) {
   title = new QLabel("You have opened the Tutorial Window");
   how_to=new QLabel(this);
   layout = new QVBoxLayout;
   back_button=new QPushButton("back");
   QString how_to_txt(QString("-move with the W, A, S and D keys<br>") +
                        QString("-shoot with space<br>") +
                        QString("-kill enemy ships to win<br>") +
                        QString("*turn up your volume (there is music!)")
                        );
   how_to->setText(how_to_txt);
   layout->addWidget(title);
   layout->addWidget(how_to);
   layout->addWidget(back_button);
   setLayout(layout);

   connect(back_button,SIGNAL(pressed()),this,SLOT(handleTutorialWinBackPressed()));
}

TutorialWindow::~TutorialWindow(){}

void TutorialWindow::handleTutorialWinBackPressed(){
    emit tutorialWinBackPressed();
}
