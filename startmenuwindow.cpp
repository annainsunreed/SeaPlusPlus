#include "startmenuwindow.h"

StartMenuWindow::StartMenuWindow(QWidget *parent) : QWidget(parent) {
   // initialize start menu buttons
   startButton = new QPushButton("start");
   quitButton = new QPushButton("quit");
   tutorialButton = new QPushButton("tutorial");
   soundButton = new QPushButton("toggle sound");

   // set layout
   startMenuLayout = new QVBoxLayout();
   startMenuLayout->addWidget(startButton);
   startMenuLayout->addWidget(tutorialButton);
   startMenuLayout->addWidget(quitButton);
   startMenuLayout->addWidget(soundButton);

   setLayout(startMenuLayout);

   connect(startButton,SIGNAL(pressed()),this,SLOT(handleStartButtontPressed()));
   connect(tutorialButton,SIGNAL(pressed()),this,SLOT(handleTutorialButtonPressed()));
   connect(quitButton,SIGNAL(pressed()),this,SLOT(handleQuitButtonPressed()));
   connect(soundButton, SIGNAL(pressed()),this, SLOT(handleSoundButtonPressed()));
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

void StartMenuWindow::handleSoundButtonPressed(){
    emit soundButtonPressed();
}

StartMenuWindow::~StartMenuWindow(){}


