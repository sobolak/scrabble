#pragma once

#include <QDialog>
#include "ui_Replay_GUI.h"

class Replay_GUI : public QDialog
{
	Q_OBJECT

public:
	Replay_GUI(QWidget *parent = Q_NULLPTR);
	~Replay_GUI();

private:
	Ui::Replay_GUI ui;
};
