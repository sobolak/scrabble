#include "Statistics_GUI.h"
#include "Logging_GUI.h"
#include "Menu_GUI.h"
#include "Logging_GUI.h"
#include "fstream"

Statistics_GUI::Statistics_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Statistics_GUI::Statistics_GUI(User* user, QWidget* parent)
	: QDialog(parent)
{
	this->user = user;
	ui.setupUi(this);
	
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
	auto model = ui.tableWidget_stats->model();
	model->setData(model->index(0, 0), globalUserManager->getPlayedMatches(user));
	model->setData(model->index(1, 0), globalUserManager->getWonMatches(user));
	model->setData(model->index(2, 0), globalUserManager->getWonMatchesPercentage(user));
	model->setData(model->index(3, 0), globalUserManager->getLostMatches(user));
	model->setData(model->index(4, 0), globalUserManager->getLostMatchesPercentage(user));
	model->setData(model->index(5, 0), globalUserManager->getWonMatchesTrain(user));
	model->setData(model->index(6, 0), globalUserManager->getWonMatchesMax(user));
	model->setData(model->index(7, 0), globalUserManager->getWordsCount(user));
	model->setData(model->index(8, 0), globalUserManager->getMeanLetterCount(user));
	model->setData(model->index(9, 0), globalUserManager->getMeanWordScore(user));

}

Statistics_GUI::~Statistics_GUI()
{
}

void Statistics_GUI::on_pushButton_return_clicked()
{
	Menu_GUI menu(this->user);
	this->destroy();
	menu.setModal(true);
	menu.exec();
}

void Statistics_GUI::on_pushButton_logout_clicked()
{
	Logging_GUI login;
	this->destroy();
	login.setModal(true);
	login.exec();
}