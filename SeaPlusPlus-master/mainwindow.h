#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QObject>
#include <QLayout>
#include <QPixmap>

//QT_BEGIN_NAMESPACE
//namespace Ui { class GameWindow; }
//QT_END_NAMESPACE

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    void setUpConnections();
private:
    QPushButton* startButton = nullptr;
    QPushButton* quitButton = nullptr;
    QPushButton* tutorialButton = nullptr;

    QGridLayout* startMenuLayout = nullptr;
    QGridLayout* gamePlayLayout = nullptr; // same for tutorial

    //QPixmap startBackground(":/pixel_ocean.png");

   // Ui::GameWindow *ui;
};
#endif // MAINWINDOW_H
