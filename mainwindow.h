#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QPixmap>
#include <QStackedWidget>
#include <QMediaPlayer>


class PlayingWindow;
class TutorialWindow;
class StartMenuWindow;



//QT_BEGIN_NAMESPACE
//namespace Ui { class GameWindow; }
//QT_END_NAMESPACE

class HoldingWindow : public QWidget //window for playing game
{
  Q_OBJECT

public:
  HoldingWindow(QWidget *parent = nullptr);
  ~HoldingWindow();

public slots:
  void DisplayMenu();
  void DisplayPlaying();
  void DisplayTutorial();
private:
  QStackedWidget* widget_holder = nullptr;
  StartMenuWindow* menu_win = nullptr;
  PlayingWindow* start_win = nullptr;
  TutorialWindow* tutorial_win = nullptr;
  QMediaPlayer* music = nullptr;

  QVBoxLayout* HoldingLayout = nullptr; //maybe dont do grid layout

};


class StartMenuWindow : public QWidget
{
  Q_OBJECT

public:
  StartMenuWindow(QWidget *parent = nullptr);
  ~StartMenuWindow();

  void setUpConnections();
signals:
  // emits a signal which will be recieved by the holding window
  // tells holding widget to switch to play window
  void tellHWSwitchToPlay();

  // emits a signal which will be recieved by the holding window
  // tells holding widget to switch to tutorial window
  void tellHWSwitchToTutorial();

public slots:
  // slot is activated when the startButton is clicked()
  // will call signal that tells holding widget to switch
  void startButtonPressed();

  // slot is activated when the tutorialButton is clicked()
  // will call signal that tells holding widget to switch
  void tutorialButtonPressed();

private:

  QPushButton* startButton = nullptr;
  QPushButton* quitButton = nullptr;
  QPushButton* tutorialButton = nullptr;

  QGridLayout* startMenuLayout = nullptr;
  QGridLayout* gamePlayLayout = nullptr; // same for tutorial (probably dont need this layout here)

  //QPixmap startBackground(":/pixel_ocean.png");

 // Ui::GameWindow *ui;
};

class PlayingWindow : public QWidget //window for playing game
{
  Q_OBJECT

public:
  PlayingWindow(QWidget *parent = nullptr);
  ~PlayingWindow();
public slots:
  //void start(); //creates
private:
  QGridLayout* gamePlayLayout = nullptr; // same for tutorial


  QVBoxLayout* layout = nullptr;
  QLabel* label = nullptr;
};


class TutorialWindow : public QWidget
{
  Q_OBJECT

public:
  TutorialWindow(QWidget *parent = nullptr);
  ~TutorialWindow();

private:
  QGridLayout* gamePlayLayout = nullptr; // same for tutorial

  QVBoxLayout* layout = nullptr;
  QLabel* label = nullptr;

};
#endif // MAINWINDOW_H

