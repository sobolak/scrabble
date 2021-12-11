#include "Player_GUI.h"
#include "Menu_GUI.h"

Player_GUI::Player_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Player_GUI::~Player_GUI()
{
}

void Player_GUI::on_pushButton_menu_clicked()
{
	Menu_GUI menu;
	this->hide();
	menu.setModal(true);
	menu.exec();
}