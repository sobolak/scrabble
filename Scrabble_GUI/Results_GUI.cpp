#include "Results_GUI.h"
#include "Menu_GUI.h"


Results_GUI::Results_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Results_GUI::Results_GUI(User* user, User* estebanUser, User* zeromskiUser, User* rokokoUser, Match* match, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	auto model = ui.tableWidget->model();
	model->setData(model->index(0, 0), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(1, 0), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(2, 0), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(3, 0), QString::fromStdString(this->user->getLogin()));

	model->setData(model->index(0, 1), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(1, 1), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(2, 1), QString::fromStdString(this->user->getLogin()));
	model->setData(model->index(3, 1), QString::fromStdString(this->user->getLogin()));
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

