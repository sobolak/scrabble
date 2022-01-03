#include "Player_GUI.h"
#include "Menu_GUI.h"
#include "Logging_GUI.h"

Player_GUI::Player_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Player_GUI::Player_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
}

Player_GUI::~Player_GUI()
{
}

void Player_GUI::on_pushButton_menu_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}

void Player_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}