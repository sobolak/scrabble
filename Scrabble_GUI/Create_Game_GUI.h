#pragma once

#include <QDialog>
#include "ui_Create_Game_GUI.h"

class Create_Game_GUI : public QDialog
{
	Q_OBJECT

public:
	Create_Game_GUI(QWidget *parent = Q_NULLPTR);
	~Create_Game_GUI();

private:
	Ui::Create_Game_GUI ui;
};
