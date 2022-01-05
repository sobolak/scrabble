#include "History_GUI.h"
#include "Menu_GUI.h"
#include "Logging_GUI.h"
#include "Replay_GUI.h"
#include "accounts.h"

using std::to_string;
using std::stoi;

History_GUI::History_GUI(QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

History_GUI::History_GUI(User* user, QWidget *parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	auto model = ui.tableWidget->model();
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
	vector<Match*>* matchesList = globalUserManager->getAllMatchesList(this->user);
	int i = 0;
	Match* currMatch = NULL;
	vector<string>* opponents = NULL;
	while (i < 10 && !matchesList->empty())
	{
		currMatch = (*matchesList).back();
		model->setData(model->index(i, 0), QString::fromStdString(to_string(currMatch->getMid())));

		opponents = currMatch->getOpponents();
		int j = 1;
		while (j < 4 && !opponents->empty())
		{
			model->setData(model->index(i, j), QString::fromStdString((*opponents).back().c_str()));
			opponents->pop_back();
			++j;
		}
		model->setData(model->index(i, 4), QString::fromStdString(currMatch->getWinner().c_str()));

		matchesList->pop_back();
		++i;
	}
}

History_GUI::~History_GUI()
{
}

void History_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->hide();
	login.setModal(true);
	login.exec();
}

void History_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->hide();
	menu.setModal(true);
	menu.exec();
}

void History_GUI::on_pushButton_replay_clicked()
{
	auto model = ui.tableWidget->model();
	int matchID;
	try
	{
		if (ui.radioButton_1->isChecked())
			matchID = stoi(model->data(model->index(0, 0)).toString().toStdString());
		else if (ui.radioButton_2->isChecked())
			matchID = stoi(model->data(model->index(1, 0)).toString().toStdString());
		else if (ui.radioButton_3->isChecked())
			matchID = stoi(model->data(model->index(2, 0)).toString().toStdString());
		else if (ui.radioButton_4->isChecked())
			matchID = stoi(model->data(model->index(3, 0)).toString().toStdString());
		else if (ui.radioButton_5->isChecked())
			matchID = stoi(model->data(model->index(4, 0)).toString().toStdString());
		else if (ui.radioButton_6->isChecked())
			matchID = stoi(model->data(model->index(5, 0)).toString().toStdString());
		else if (ui.radioButton_7->isChecked())
			matchID = stoi(model->data(model->index(6, 0)).toString().toStdString());
		else if (ui.radioButton_8->isChecked())
			matchID = stoi(model->data(model->index(7, 0)).toString().toStdString());
		else if (ui.radioButton_9->isChecked())
			matchID = stoi(model->data(model->index(8, 0)).toString().toStdString());
		else if (ui.radioButton_10->isChecked())
			matchID = stoi(model->data(model->index(9, 0)).toString().toStdString());
	}
	catch (const std::exception&)
	{
		return;
	}

	Replay_GUI rep(this->user, matchID);
	this->hide();
	rep.setModal(true);
	rep.exec();
}