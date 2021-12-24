#pragma once

#include <QDialog>
#include "ui_Statistics_GUI.h"
#include "accounts.h"

class Statistics_GUI : public QDialog
{
	Q_OBJECT

public:
	User* user;
	Statistics_GUI(QWidget *parent = Q_NULLPTR);
	Statistics_GUI(User* user, QWidget* parent = Q_NULLPTR);
	~Statistics_GUI();

private:
	Ui::Statistics_GUI ui;
private slots:
	void on_pushButton_return_clicked();
private slots:
	void on_pushButton_logout_clicked();
};
