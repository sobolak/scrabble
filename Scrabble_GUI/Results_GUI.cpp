#include "Results_GUI.h"
#include "Menu_GUI.h"


Results_GUI::Results_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Results_GUI::Results_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
}

Results_GUI::~Results_GUI()
{
}

void Results_GUI::on_pushButton_continue_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}

