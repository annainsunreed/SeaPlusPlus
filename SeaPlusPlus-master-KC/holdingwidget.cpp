#include"holdingwidget.h"

HoldingWidget::HoldingWidget(QWidget *parent):QWidget (parent){
    start_win=new StartMenuWindow;
    play_win=new PlayingWindow;
    tutorial_win=new TutorialWindow;
    widget_holder = new QStackedWidget;
    widget_holder->addWidget(start_win);
    widget_holder->addWidget(play_win);
    widget_holder->addWidget(tutorial_win);

    main_layout = new QVBoxLayout;
    main_layout->addWidget(widget_holder);

    QPixmap startBackground(":/new/prefix1/pixel_ocean.png");
    startBackground = startBackground.scaled(this->size(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background,startBackground);
    this->setPalette(palette);

    setLayout(main_layout);

    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/backgroundsound.mp3"));
    music->play();

    connect(start_win,SIGNAL(startButtonPressed()),this,SLOT(DisplayPlayingWin()));
    connect(start_win,SIGNAL(tutorialButtonPressed()),this,SLOT(DisplayTutorialWin()));
    connect(start_win,SIGNAL(quitButtonPressed()),this,SLOT(exit()));

    connect(play_win,SIGNAL(playWinBackPressed()),this,SLOT(DisplayStartWin()));
    connect(tutorial_win,SIGNAL(tutorialWinBackPressed()),this,SLOT(DisplayStartWin()));

    DisplayStartWin();
}

void HoldingWidget::DisplayStartWin(){
     widget_holder->setCurrentIndex(widget_holder->indexOf(start_win));
}
void HoldingWidget::DisplayTutorialWin(){
     widget_holder->setCurrentIndex(widget_holder->indexOf(tutorial_win));
}
void HoldingWidget::DisplayPlayingWin(){
     widget_holder->setCurrentIndex(widget_holder->indexOf(play_win));
}

HoldingWidget::~HoldingWidget(){}

