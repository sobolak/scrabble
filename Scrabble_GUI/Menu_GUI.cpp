#include "Menu_GUI.h"
#include "Create_Game_GUI.h"
#include "Logging_GUI.h"
#include "Statistics_GUI.h"

Menu_GUI::Menu_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Menu_GUI::~Menu_GUI()
{
}

void Menu_GUI::on_pushButton_play_clicked()
{
	Create_Game_GUI create_game;
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

void Menu_GUI::on_pushButton_ranking_clicked()
{
	Statistics_GUI stats;
	this->hide();
	stats.setModal(true);
	stats.exec();
}