#include "mainwindow.h"
#include "ui_mainwindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent) {

    // initialize start menu buttons
    startButton = new QPushButton("start");
    quitButton = new QPushButton("quit");
    tutorialButton = new QPushButton("tutorial");

    // set layout
    startMenuLayout = new QGridLayout();
    setLayout(startMenuLayout);
    startMenuLayout->addWidget(startButton);
    startMenuLayout->addWidget(quitButton);
    startMenuLayout->addWidget(tutorialButton);

    // set background
    //‎⁨iCloud Drive⁩ ▸ ⁨Desktop⁩ ▸ ⁨PIC10C⁩ ▸ ⁨SeaPlusPlus⁩
    QPixmap startBackground("/SeaPlusPlus/pixel_ocean.png");
    startBackground =
            startBackground.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,startBackground);
    this->setPalette(palette);

    // set up start menu connections
    // 1. connect start to gameplay paint event
    // 2. connect tutorial to tutorial paint event
    setUpConnections();
}

GameWindow::~GameWindow(){}

void GameWindow::setUpConnections(){
    // set up start menu connections
    // 1. connect start to gameplay paint event
    // 2. connect tutorial to tutorial paint event
    QObject::connect(quitButton, SIGNAL(clicked()),
                                             qApp, SLOT(quit()));
}
