#pragma once

#ifdef LINUX
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion" 
#endif
#include <QtWidgets/QMainWindow>
#include "ui_RegenwaldQuiz.h"
#ifdef LINUX
#pragma GCC diagnostic pop
#endif

#include <list>
#include "Frage.h"

class RegenwaldQuiz : public QMainWindow
{
    Q_OBJECT

public:
    RegenwaldQuiz(QWidget *parent = Q_NULLPTR);

private:
    unsigned int points = 0;
    long unsigned int maxPoints;
    std::list<Frage> questions;
    Ui::RegenwaldQuizClass ui;

private slots:
    void weiter();

};
