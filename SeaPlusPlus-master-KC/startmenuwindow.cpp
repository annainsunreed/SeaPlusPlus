#include "startmenuwindow.h"



StartMenuWindow::StartMenuWindow(QWidget *parent) : QWidget(parent) {

    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/backgroundsound.mp3"));
    music->play();

   // initialize start menu buttons
   startButton = new QPushButton("start");
   quitButton = new QPushButton("quit");
   tutorialButton = new QPushButton("tutorial");

   // set layout
   startMenuLayout = new QGridLayout();
   startMenuLayout->addWidget(startButton);
   startMenuLayout->addWidget(tutorialButton);
   startMenuLayout->addWidget(quitButton);

   // set background

   /*QPixmap startBackground(":/new/prefix1/pixel_ocean.png");
   startBackground = startBackground.scaled(this->size(),Qt::IgnoreAspectRatio);
   QPalette palette;
   palette.setBrush(QPalette::Background,startBackground);
   this->setPalette(palette);*/

   setLayout(startMenuLayout);

   connect(startButton,SIGNAL(pressed()),this,SLOT(handleStartButtontPressed()));
   connect(tutorialButton,SIGNAL(pressed()),this,SLOT(handleTutorialButtonPressed()));
   connect(quitButton,SIGNAL(pressed()),this,SLOT(handleQuitButtonPressed()));
}

void StartMenuWindow::handleStartButtontPressed(){
    emit startButtonPressed();
}

void StartMenuWindow::handleTutorialButtonPressed(){
    emit tutorialButtonPressed();
}

void StartMenuWindow::handleQuitButtonPressed(){
    emit quitButtonPressed();
}

StartMenuWindow::~StartMenuWindow(){}


