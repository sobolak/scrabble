#include "Logging_GUI.h"
#include "Menu_GUI.h"
#include <fstream>
#include "mysql.h"

Logging_GUI::Logging_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Logging_GUI::~Logging_GUI()
{
}

void Logging_GUI::on_pushButton_login_clicked()
{
	QString login = ui.lineEdit_login->text();
	QString password = ui.lineEdit_password->text();
	string DBConfig[4];

	std::ifstream DBconfigFile("db_config.txt");

	if (DBconfigFile.is_open()) {
		int i = 0;
		while (DBconfigFile.good() && i < 4) {
			DBconfigFile >> DBConfig[i++];
		}
	}

	UserManager* U = new UserManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
	User* user = U->logIn(login.toStdString(), password.toStdString());

	if (user != NULL)
	{
		Menu_GUI menu(user);
		this->hide();
		menu.setModal(true);
		menu.exec();
	}
}

void Logging_GUI::on_pushButton_register_clicked()
{
	QString login = ui.lineEdit_reg_login->text();
	QString confirm_password = ui.lineEdit_confirm_password->text();
	QString reg_password = ui.lineEdit_reg_password->text();
	string DBConfig[4];
	std::string confirm_passwordS = confirm_password.toStdString();
	std::string reg_passwordS = reg_password.toStdString();
	if (std::strcmp(confirm_passwordS.c_str(), reg_passwordS.c_str()) == 0)
	{
		std::ifstream DBconfigFile("db_config.txt");

		if (DBconfigFile.is_open()) {
			int i = 0;
			while (DBconfigFile.good() && i < 4) {
				DBconfigFile >> DBConfig[i++];
			}
		}
		
		UserManager* U = new UserManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
		User* user = U->createUser(login.toStdString(), reg_password.toStdString());

		if (user != NULL)
		{
			Menu_GUI menu(user);
			this->hide();
			menu.setModal(true);
			menu.exec();
		}
	}
}
