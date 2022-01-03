#include "History_GUI.h"
#include "Menu_GUI.h"
#include "Logging_GUI.h"

History_GUI::History_GUI(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

History_GUI::History_GUI(User* user, QWidget *parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
}

History_GUI::~History_GUI()
{
}

void History_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}

void History_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}

//void History_GUI::on_pushButton_replay_clicked()
//{
//	History_GUI stats(this->user);
//	this->hide();
//	stats.setModal(true);
//	stats.exec();
//}