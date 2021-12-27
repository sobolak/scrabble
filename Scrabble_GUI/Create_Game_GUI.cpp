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
	this->hide();
	Game_GUI game(this->user);
	game.setModal(true);
	game.exec();

}

