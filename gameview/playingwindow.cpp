#include"playingwindow.h"
#include"gameview.h"

PlayingWindow::PlayingWindow(QWidget *parent) : QWidget(parent) {

label = new QLabel("Difficulty");
layout = new QVBoxLayout();
level_one_button=new QPushButton("Easy");
level_two_button=new QPushButton("Medium");
level_three_button=new QPushButton("Hard");
back_button = new QPushButton("Back");
layout->addWidget(label);
layout->addWidget(level_one_button);
layout->addWidget(level_two_button);
layout->addWidget(level_three_button);
layout->addWidget(back_button);
setLayout(layout);

connect(back_button,SIGNAL(pressed()),this,SLOT(handlePlayWinBackPressed()));
connect(level_one_button,SIGNAL(pressed()),this, SLOT(playLevelOne()));
connect(level_two_button,SIGNAL(pressed()),this, SLOT(playLevelTwo()));
connect(level_three_button,SIGNAL(pressed()),this, SLOT(playLevelThree()));
}

PlayingWindow::~PlayingWindow(){}

void PlayingWindow::handlePlayWinBackPressed(){
    emit playWinBackPressed();
}

void PlayingWindow::playLevelOne(){
    game=new GameView();
    game->showFullScreen();
}

void PlayingWindow::playLevelTwo(){
    game=new GameView();
    game->showFullScreen();
}

void PlayingWindow::playLevelThree(){
    game=new GameView();
    game->showFullScreen();
}
