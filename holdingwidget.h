#ifndef HOLDINGWIDGET_H
#define HOLDINGWIDGET_H

#include"playingwindow.h"
#include"startmenuwindow.h"
#include"tutorialwindow.h"
#include <QStackedWidget>
#include <QLayout>
#include <QWidget>
#include <QApplication>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class HoldingWidget : public QWidget
{
    Q_OBJECT
public:
   HoldingWidget(QWidget *parent = nullptr);
   ~HoldingWidget();

public slots:
    void DisplayStartWin();
    void DisplayPlayingWin();
    void DisplayTutorialWin();
    void toggleSound();

private:
    QStackedWidget* widget_holder = nullptr;
    StartMenuWindow* start_win = nullptr;
    PlayingWindow* play_win = nullptr;
    TutorialWindow* tutorial_win=nullptr;
    QVBoxLayout* main_layout=nullptr;
    QMediaPlayer* music=nullptr;
};

#endif // HOLDINGWIDGET_H
