#include"playingwindow.h"

PlayingWindow::PlayingWindow(QWidget *parent) : QWidget(parent) {

label = new QLabel("You have opened the PlayingWindow");
layout = new QVBoxLayout();
back_button = new QPushButton("Back");
layout->addWidget(label);
layout->addWidget(back_button);
setLayout(layout);

connect(back_button,SIGNAL(pressed()),this,SLOT(handlePlayWinBackPressed()));
}

PlayingWindow::~PlayingWindow(){}

void PlayingWindow::handlePlayWinBackPressed(){
    emit playWinBackPressed();
}
