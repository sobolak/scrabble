#include "Statistics_GUI.h"
#include "Logging_GUI.h"
#include "Menu_GUI.h"
#include "Logging_GUI.h"

Statistics_GUI::Statistics_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Statistics_GUI::~Statistics_GUI()
{
}

void Statistics_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu;
	this->hide();
	menu.setModal(true);
	menu.exec();
}

void Statistics_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}