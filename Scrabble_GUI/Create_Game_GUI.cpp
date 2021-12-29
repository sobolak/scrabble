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
	this->hide();
	login.setModal(true);
	login.exec();
}

void Create_Game_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}

void Create_Game_GUI::on_pushButton_start_clicked()
{
	if (ui.radioButton_computer->isChecked())
	{
		Game_GUI game(this->user);
		this->hide();
		game.setModal(true);
		game.exec();
	}
	else if (ui.radioButton_second->isChecked())
	{
		Game_GUI_2 game(this->user);
		this->hide();
		game.setModal(true);
		game.exec();
	}
	else if (ui.radioButton_third->isChecked())
	{
		Game_GUI_3 game(this->user);
		this->hide();
		game.setModal(true);
		game.exec();
	}
	else if (ui.radioButton_forth->isChecked())
	{
		Game_GUI_4 game(this->user);
		this->hide();
		game.setModal(true);
		game.exec();
	}
}

void Create_Game_GUI::on_radioButton_computer_clicked()
{
	ui.comboBox_computer_difficulty->show();
	ui.comboBox_second_name->hide();
	ui.comboBox_third_name->hide();
	ui.comboBox_forth_name->hide();
}

void Create_Game_GUI::on_radioButton_second_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->hide();
	ui.comboBox_forth_name->hide();
	ui.comboBox_computer_difficulty->hide();
	for (vector<string>::iterator itr = *(globalUserManager->getRemainingLogins(this->user))->begin(); )
	{
		ui.comboBox_second_name->addItem(QString::fromStdString(login));
	}
}

void Create_Game_GUI::on_radioButton_third_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->show();
	ui.comboBox_forth_name->hide();
	ui.comboBox_computer_difficulty->hide();
}

void Create_Game_GUI::on_radioButton_forth_clicked()
{
	ui.comboBox_second_name->show();
	ui.comboBox_third_name->show();
	ui.comboBox_forth_name->show();
	ui.comboBox_computer_difficulty->hide();

}
