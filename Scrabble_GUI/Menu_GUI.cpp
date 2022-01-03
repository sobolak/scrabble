#include "Menu_GUI.h"
#include "Create_Game_GUI.h"
#include "Logging_GUI.h"
#include "Statistics_GUI.h"
#include "History_GUI.h"
#include "Player_GUI.h"

Menu_GUI::Menu_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Menu_GUI::Menu_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
}

Menu_GUI::~Menu_GUI()
{
}

void Menu_GUI::on_pushButton_play_clicked()
{
	Create_Game_GUI create_game(this->user);
	this->hide();
	create_game.setModal(true);
	create_game.exec();
}

void Menu_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}

void Menu_GUI::on_pushButton_statistics_clicked()
{
	Statistics_GUI stats(this->user);
	this->hide();
	stats.setModal(true);
	stats.exec();
}

void Menu_GUI::on_pushButton_history_clicked()
{
	History_GUI hist(this->user);
	this->hide();
	hist.setModal(true);
	hist.exec();
}

void Menu_GUI::on_pushButton_profile_clicked()
{
	Player_GUI player(this->user);
	this->hide();
	player.setModal(true);
	player.exec();
}
