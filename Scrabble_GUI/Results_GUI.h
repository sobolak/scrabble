#pragma once

#include <QDialog>
#include "ui_Results_GUI.h"

class Results_GUI : public QDialog
{
	Q_OBJECT

public:
	Results_GUI(QWidget *parent = Q_NULLPTR);
	~Results_GUI();

private:
	Ui::Results_GUI ui;
};
