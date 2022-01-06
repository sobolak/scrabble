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
	this->matchesList = globalUserManager->getAllMatchesList(this->user);
	int i = 0;
	vector<Match*>::iterator mIter = this->matchesList->begin();
	vector<string>::iterator oIter;

	while (i < 10 && mIter != this->matchesList->end())
	{
		model->setData(model->index(i, 0), QString::fromStdString(to_string(this->matchesList->size()-i)));
		oIter = (*mIter)->getOpponents()->begin();
		int j = 1;
		while (j < 4 && oIter != (*mIter)->getOpponents()->end())
		{
			model->setData(model->index(i, j), QString::fromStdString((*oIter).c_str()));
			++oIter;
			++j;
		}
		model->setData(model->index(i, 4), QString::fromStdString((*mIter)->getWinner().c_str()));
		++mIter;
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
			matchID = this->matchesList->at(0)->getMid();
		else if (ui.radioButton_2->isChecked())
			matchID = this->matchesList->at(1)->getMid();
		else if (ui.radioButton_3->isChecked())
			matchID = this->matchesList->at(2)->getMid();
		else if (ui.radioButton_4->isChecked())
			matchID = this->matchesList->at(3)->getMid();
		else if (ui.radioButton_5->isChecked())
			matchID = this->matchesList->at(4)->getMid();
		else if (ui.radioButton_6->isChecked())
			matchID = this->matchesList->at(5)->getMid();
		else if (ui.radioButton_7->isChecked())
			matchID = this->matchesList->at(6)->getMid();
		else if (ui.radioButton_8->isChecked())
			matchID = this->matchesList->at(7)->getMid();
		else if (ui.radioButton_9->isChecked())
			matchID = this->matchesList->at(8)->getMid();
		else if (ui.radioButton_10->isChecked())
			matchID = this->matchesList->at(9)->getMid();
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