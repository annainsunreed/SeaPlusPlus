#include "mainwindow.h"
#include "ui_mainwindow.h"


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
   //‎⁨iCloud Drive⁩ ▸ ⁨Desktop⁩ ▸ ⁨PIC10C⁩ ▸ ⁨SeaPlusPlus⁩
   QPixmap startBackground(":/new/prefix1/pixel_ocean.png");
   startBackground =
           startBackground.scaled(this->size(),Qt::IgnoreAspectRatio);
   QPalette palette;
   palette.setBrush(QPalette::Background,startBackground);
   this->setPalette(palette);


   widget_holder = new QStackedWidget;  //creating stacked widget


   start_win = new PlayingWindow;
   widget_holder->addWidget(start_win);

   tutorial_win = new TutorialWindow;
   widget_holder->addWidget(tutorial_win);

   //startMenuLayout->addWidget(widget_holder);
    setLayout(startMenuLayout);





   // set up start menu connections
   // 1. connect start to gameplay paint event
   // 2. connect tutorial to tutorial paint event
    //setUpConnections();

}

StartMenuWindow::~StartMenuWindow(){}



void StartMenuWindow::DisplayPlaying() {
  //widget_holder->setCurrentIndex(0);
  widget_holder->setCurrentIndex(widget_holder->indexOf(start_win));
}
void StartMenuWindow::DisplayTutorial() {
  //widget_holder->setCurrentIndex(0);
  widget_holder->setCurrentIndex(widget_holder->indexOf(tutorial_win));
}

void StartMenuWindow::setUpConnections(){

   // set up start menu connections
   // 1. connect start to gameplay paint event
   // 2. connect tutorial to tutorial paint event


   QObject::connect(startButton, SIGNAL(clicked()), this, SLOT(DisplayPlaying()));
   QObject::connect(tutorialButton, SIGNAL(clicked()), this, SLOT(DisplayTutorial()));
   QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

PlayingWindow::~PlayingWindow(){}

PlayingWindow::PlayingWindow(QWidget *parent) : QWidget(parent) {

label = new QLabel("You have opened the PlayingWindow");
layout = new QVBoxLayout;

layout->addWidget(label);
setLayout(layout);
}

TutorialWindow::~TutorialWindow(){}

TutorialWindow::TutorialWindow(QWidget *parent) : QWidget(parent) {
   label = new QLabel("You have opened the TutorialWindow");
   layout = new QVBoxLayout;

   layout->addWidget(label);
   setLayout(layout);
}
