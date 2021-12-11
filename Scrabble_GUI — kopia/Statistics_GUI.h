#pragma once

#include <QDialog>
#include "ui_Statistics_GUI.h"

class Statistics_GUI : public QDialog
{
	Q_OBJECT

public:
	Statistics_GUI(QWidget *parent = Q_NULLPTR);
	~Statistics_GUI();

private:
	Ui::Statistics_GUI ui;
private slots:
	void on_pushButton_return_clicked();
private slots:
	void on_pushButton_logout_clicked();
};
