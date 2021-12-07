#include "Menu_GUI.h"
#include "Game_GUI.h"
#include "Logging_GUI.h"

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
	Game_GUI game;
	this->hide();
	game.setModal(true);
	game.exec();
}

void Menu_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}