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
	this->destroy();
	menu.setModal(true);
	menu.exec();
}

void Player_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->destroy();
	login.setModal(true);
	login.exec();
}

void Player_GUI::on_pushButton_change_clicked()
{

	string oldPassword = ui.lineEdit_password->text().toStdString();
	string newPassword = ui.lineEdit_new_password->text().toStdString();
	string newPassword2 = ui.lineEdit_confirm_password->text().toStdString();

	if (globalUserManager->changePassword(this->user, oldPassword, newPassword, newPassword2))
	{
		ui.lineEdit_confirm_password->clear();
		ui.lineEdit_new_password->clear();
		ui.lineEdit_password->clear();
	}
}