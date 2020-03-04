#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H

#include<QWidget>
#include<QObject>
#include<QLayout>
#include<QLabel>
#include<QPushButton>

class TutorialWindow : public QWidget
{
  Q_OBJECT

public:
  TutorialWindow(QWidget *parent = nullptr);
  ~TutorialWindow();
signals:
  void tutorialWinBackPressed();
public slots:
  void handleTutorialWinBackPressed();
private:
  QGridLayout* gamePlayLayout = nullptr; // same for tutorial
  QPushButton* back_button=nullptr;
  QVBoxLayout* layout = nullptr;
  QLabel* label = nullptr;

};

#endif // TUTORIALWINDOW_H
