#include "Create_Game_GUI.h"
#include "Menu_GUI.h"
#include "Game_GUI.h"
#include "Game_GUI_2.h"
#include "Game_GUI_3.h"
#include "Game_GUI_4.h"
#include "Logging_GUI.h"
#include "accounts.h"

Create_Game_GUI::Create_Game_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Create_Game_GUI::Create_Game_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
	ui.radioButton_computer->clicked();
}

Create_Game_GUI::~Create_Game_GUI()
{
}

void Create_Game_GUI::on_pushButton_logout_clicked()
{	
	Logging_GUI login;
	this->destroy();
	login.setModal(true);
	login.exec();
}

void Create_Game_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->destroy();
	menu.setModal(true);
	menu.exec();
}

void Create_Game_GUI::on_pushButton_start_clicked()
{
	if (ui.radioButton_computer->isChecked())
	{
		auto loginComputer = ui.comboBox_computer_difficulty->currentText();
		string passComputer = "e83VmB9=JG3XA!df";
		User* userComputer = globalUserManager->logIn(loginComputer.toStdString(), passComputer);
		Game_GUI game(this->user, userComputer);
		this->destroy();
		game.setModal(true);
		game.exec();
	}
	else if (ui.radioButton_second->isChecked())
	{
		auto login2 = ui.comboBox_second_name->currentText();
		auto pass2 = ui.passwordUser2->text();
		User* user2 = globalUserManager->logIn(login2.toStdString(), pass2.toStdString());

		if (user2 != NULL && strcmp(user2->getLogin().c_str(),user->getLogin().c_str()) != 0)
		{
			Game_GUI_2 game(this->user,user2);
			this->destroy();
			game.setModal(true);
			game.exec();
		}
	}
	else if (ui.radioButton_third->isChecked())
	{
		auto login2 = ui.comboBox_second_name->currentText();
		auto pass2 = ui.passwordUser2->text();
		auto login3 = ui.comboBox_third_name->currentText();
		auto pass3 = ui.passwordUser3->text();
		User* user2 = globalUserManager->logIn(login2.toStdString(), pass2.toStdString());
		User* user3 = globalUserManager->logIn(login3.toStdString(), pass3.toStdString());

		if (user2 != NULL && user3 != NULL 
			&& strcmp(user2->getLogin().c_str(), user->getLogin().c_str()) != 0 
			&& strcmp(user2->getLogin().c_str(), user3->getLogin().c_str()) != 0 
			&& strcmp(user->getLogin().c_str(), user3->getLogin().c_str()) != 0)
		{
			Game_GUI_3 game(this->user, user2, user3);
			this->destroy();
			game.setModal(true);
			game.exec();
		}
	}
	else if (ui.radioButton_forth->isChecked())
	{
		auto login2 = ui.comboBox_second_name->currentText();
		auto pass2 = ui.passwordUser2->text();
		auto login3 = ui.comboBox_third_name->currentText();
		auto pass3 = ui.passwordUser3->text();
		auto login4 = ui.comboBox_forth_name->currentText();
		auto pass4 = ui.passwordUser4->text();
		User* user2 = globalUserManager->logIn(login2.toStdString(), pass2.toStdString());
		User* user3 = globalUserManager->logIn(login3.toStdString(), pass3.toStdString());
		User* user4 = globalUserManager->logIn(login4.toStdString(), pass4.toStdString());
		if (user2 != NULL && user3 != NULL && user4 != NULL 
			&&  strcmp(user2->getLogin().c_str(), user->getLogin().c_str()) != 0 
			&& strcmp(user2->getLogin().c_str(), user3->getLogin().c_str()) != 0 
			&& strcmp(user->getLogin().c_str(), user3->getLogin().c_str()) != 0 
			&&  strcmp(user4->getLogin().c_str(), user3->getLogin().c_str()) != 0 
			&& strcmp(user4->getLogin().c_str(), user2->getLogin().c_str()) != 0 
			&& strcmp(user4->getLogin().c_str(), user->getLogin().c_str()) != 0)
		{
			Game_GUI_4 game(this->user, user2, user3, user4);
			this->destroy();
			game.setModal(true);
			game.exec();
		}
	}
}

void Create_Game_GUI::on_radioButton_computer_clicked()
{
	ui.comboBox_computer_difficulty->clear();
	ui.comboBox_computer_difficulty->show();
	ui.comboBox_second_name->hide();
	ui.comboBox_third_name->hide();
	ui.comboBox_forth_name->hide();
	ui.passwordUser2->hide();
	ui.passwordUser3->hide();
	ui.passwordUser4->hide();
	ui.comboBox_computer_difficulty-> addItem(QString::fromStdString("easy"));
	ui.comboBox_computer_difficulty->addItem(QString::fromStdString("medium"));
	ui.comboBox_computer_difficulty->addItem(QString::fromStdString("hard"));
}

void Create_Game_GUI::on_radioButton_second_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->hide();
	ui.comboBox_forth_name->hide();
	ui.comboBox_computer_difficulty->hide();
	ui.comboBox_second_name->clear();
	ui.passwordUser2->show();
	ui.passwordUser3->hide();
	ui.passwordUser4->hide();
	vector<string>* logins = globalUserManager->getRemainingLogins(this->user);

	for (string login : *logins)
		ui.comboBox_second_name->addItem(QString::fromStdString(login));
}

void Create_Game_GUI::on_radioButton_third_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->show();
	ui.comboBox_forth_name->hide();
	ui.comboBox_computer_difficulty->hide();
	ui.comboBox_second_name->clear();
	ui.comboBox_third_name->clear();
	ui.passwordUser2->show();
	ui.passwordUser3->show();
	ui.passwordUser4->hide();
	vector<string>* logins = globalUserManager->getRemainingLogins(this->user);
	for (string login : *logins)
	{
		ui.comboBox_second_name->addItem(QString::fromStdString(login));
		ui.comboBox_third_name->addItem(QString::fromStdString(login));
	}
}

void Create_Game_GUI::on_radioButton_forth_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->show();
	ui.comboBox_forth_name->show();
	ui.comboBox_computer_difficulty->hide();
	ui.comboBox_second_name->clear();
	ui.comboBox_third_name->clear();
	ui.comboBox_forth_name->clear();
	ui.passwordUser2->show();
	ui.passwordUser3->show();
	ui.passwordUser4->show();
	vector<string>* logins = globalUserManager->getRemainingLogins(this->user);
	for (string login : *logins)
	{
		ui.comboBox_second_name->addItem(QString::fromStdString(login));
		ui.comboBox_third_name->addItem(QString::fromStdString(login));
		ui.comboBox_forth_name->addItem(QString::fromStdString(login));
	}
}
