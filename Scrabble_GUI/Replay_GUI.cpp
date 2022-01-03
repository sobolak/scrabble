#include "Replay_GUI.h"
#include "Menu_GUI.h"

Replay_GUI::Replay_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Replay_GUI::Replay_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	ui.mufasaLabel->setText(QString::fromStdString(this->user->getLogin()));
}

Replay_GUI::~Replay_GUI()
{
}

void Replay_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}
