#ifndef PLAYINGWINDOW_H
#define PLAYINGWINDOW_H

#include<QWidget>
#include<QObject>
#include<QLayout>
#include<QLabel>
#include<QPushButton>
#include"gameview.h"
class PlayingWindow : public QWidget
{
  Q_OBJECT

public:
  PlayingWindow(QWidget *parent = nullptr);
  ~PlayingWindow();
signals:
  void playWinBackPressed();
public slots:
  void playLevelOne();
  void playLevelTwo();
  void playLevelThree();
  void handlePlayWinBackPressed();
private:
  QGridLayout* gamePlayLayout = nullptr;
  QPushButton* back_button=nullptr;
  QVBoxLayout* layout = nullptr;
  QLabel* label = nullptr;
  QPushButton* level_one_button=nullptr;
  QPushButton* level_two_button=nullptr;
  QPushButton* level_three_button=nullptr;
  GameView* game=nullptr;
};

#endif // PLAYINGWINDOW_H
