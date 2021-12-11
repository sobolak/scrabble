#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Scrabble_GUI.h"

class Scrabble_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Scrabble_GUI(QWidget *parent = Q_NULLPTR);

private:
    Ui::Scrabble_GUIClass ui;

private slots:
    void on_pushButton_clicked();
};
