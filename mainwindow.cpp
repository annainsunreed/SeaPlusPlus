#include "mainwindow.h"
#include "ui_mainwindow.h"

StartWindow::StartWindow(QWidget *parent) : QWidget(parent) {

    // initialize start menu buttons
    startButton = new QPushButton("start");
    quitButton = new QPushButton("quit");
    tutorialButton = new QPushButton("tutorial");

    // initialize spin box
    levelSelector = new QSpinBox();
    levelSelector->setRange(1,5);

    // set layout
    startMenuLayout = new QGridLayout();
    setLayout(startMenuLayout);
    startMenuLayout->addWidget(startButton);
    startMenuLayout->addWidget(quitButton);
    startMenuLayout->addWidget(tutorialButton);

    // set background
    QPixmap startBackground(":/new/prefix1/pixel_ocean.png");
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

StartWindow::~StartWindow(){}

void StartWindow::setUpConnections(){
    // set up start menu connections
    // 1. connect start to gameplay paint event
    // 2. connect tutorial to tutorial paint event
    QObject::connect(quitButton, SIGNAL(clicked()),
                                             qApp, SLOT(quit()));
}
