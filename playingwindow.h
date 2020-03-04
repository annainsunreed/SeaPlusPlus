#ifndef PLAYINGWINDOW_H
#define PLAYINGWINDOW_H

#include<QWidget>
#include<QObject>
#include<QLayout>
#include<QLabel>
#include<QPushButton>
class PlayingWindow : public QWidget
{
  Q_OBJECT

public:
  PlayingWindow(QWidget *parent = nullptr);
  ~PlayingWindow();
signals:
  void playWinBackPressed();
public slots:
  void handlePlayWinBackPressed();
private:
  QGridLayout* gamePlayLayout = nullptr;
  QPushButton* back_button=nullptr;
  QVBoxLayout* layout = nullptr;
  QLabel* label = nullptr;
};

#endif // PLAYINGWINDOW_H
