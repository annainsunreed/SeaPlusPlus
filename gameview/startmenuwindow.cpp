#include "startmenuwindow.h"

StartMenuWindow::StartMenuWindow(QWidget *parent) : QWidget(parent) {

   // initialize start menu buttons
   startButton = new QPushButton("start");
   quitButton = new QPushButton("quit");
   tutorialButton = new QPushButton("tutorial");
   soundPlayButton = new QPushButton("play music");
   soundPauseButton = new QPushButton("pause music");
   QVBoxLayout* miniLayoutTop = new QVBoxLayout;
   QVBoxLayout* miniLayoutBottom = new QVBoxLayout;

   // set layout
   startMenuLayout = new QGridLayout();
   startMenuLayout->addLayout(miniLayoutTop, 2, 2);
   startMenuLayout->addLayout(miniLayoutBottom, 3, 0);
   miniLayoutTop->addWidget(startButton);
   miniLayoutTop->addWidget(tutorialButton);
   startMenuLayout->addWidget(quitButton, 3, 3);
   //startMenuLayout->addWidget(soundPlayButton, 9, 0);
   miniLayoutBottom->addWidget(soundPlayButton);
   miniLayoutBottom->addWidget(soundPauseButton);
   //startMenuLayout->addWidget(soundPauseButton, 10, 0);

   setLayout(startMenuLayout);

   connect(startButton,SIGNAL(pressed()),this,SLOT(handleStartButtontPressed()));
   connect(tutorialButton,SIGNAL(pressed()),this,SLOT(handleTutorialButtonPressed()));
   connect(quitButton,SIGNAL(pressed()),this,SLOT(handleQuitButtonPressed()));
   connect(soundPlayButton, SIGNAL(clicked()),this, SLOT(handleSoundPlayButtonPressed()));
   connect(soundPauseButton, SIGNAL(clicked()),this, SLOT(handleSoundPauseButtonPressed()));
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

void StartMenuWindow::handleSoundPlayButtonPressed(){
    emit soundPlayButtonPressed();
}

void StartMenuWindow::handleSoundPauseButtonPressed(){
    emit soundPauseButtonPressed();
}


StartMenuWindow::~StartMenuWindow(){}


