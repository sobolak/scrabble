#include "Logging_GUI.h"
#include "Menu_GUI.h"

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
	Menu_GUI menu;
	this->hide();
	menu.setModal(true);
	menu.exec();
}
