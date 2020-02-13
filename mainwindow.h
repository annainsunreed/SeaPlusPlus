#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QPixmap>
#include <QSpinBox>

//QT_BEGIN_NAMESPACE
//namespace Ui { class StartWindow; }
//QT_END_NAMESPACE

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

    void setUpConnections();
private:

    QPushButton* startButton = nullptr;
    QPushButton* quitButton = nullptr;
    QPushButton* tutorialButton = nullptr;
    QSpinBox* levelSelector = nullptr;

    QGridLayout* startMenuLayout = nullptr;
    QGridLayout* gamePlayLayout = nullptr; // same for tutorial

    //QPixmap startBackground(":/pixel_ocean.png");

   // Ui::GameWindow *ui;
};

class PlayWindow : public QWidget
{
    // game play
    // has holding widget that holds all game levels
};

class TutorialWindow : public QWidget
{

};

class Level : public QWidget
{
    // make 5 different constructors for different levels
};

class HoldingWindow : public QWidget
{
    Q_OBJECT

public:

private:

};

#endif // MAINWINDOW_H
