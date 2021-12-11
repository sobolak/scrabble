#pragma once

#include <QDialog>
#include "ui_Logging_GUI.h"

class Logging_GUI : public QDialog
{
	Q_OBJECT

public:
	Logging_GUI(QWidget *parent = Q_NULLPTR);
	~Logging_GUI();

private:
	Ui::Logging_GUI ui;
private slots:
	void on_pushButton_login_clicked();
};
