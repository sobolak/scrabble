#pragma once

#include <QDialog>
#include "ui_Game_GUI_2.h"

class Game_GUI_2 : public QDialog
{
	Q_OBJECT

public:
	Game_GUI_2(QWidget *parent = Q_NULLPTR);
	~Game_GUI_2();

private:
	Ui::Game_GUI_2 ui;
};
