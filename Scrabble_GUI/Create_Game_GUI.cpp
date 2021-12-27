#include "Create_Game_GUI.h"
#include "Logging_GUI.h"
#include "Menu_GUI.h"
#include "Game_GUI.h"
#include "Game_GUI_2.h"
#include "Game_GUI_3.h"
#include "Game_GUI_4.h"


Create_Game_GUI::Create_Game_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
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
	Menu_GUI menu;
	this->hide();
	menu.setModal(true);
	menu.exec();
}

void Create_Game_GUI::on_pushButton_start_clicked()
{
	this->hide();
	Game_GUI_4 game;
	game.setModal(true);
	game.exec();

}

