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
	string DBConfig[4];

	std::ifstream DBconfigFile("db_config.txt");

	if (DBconfigFile.is_open()) {
		int i = 0;
		while (DBconfigFile.good() && i < 4) {
			DBconfigFile >> DBConfig[i++];
		}
	}

	UserManager* U = new UserManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
	MatchManager* M = new MatchManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
	MoveManager* MV = new MoveManager(DBConfig[0], DBConfig[1], DBConfig[2], DBConfig[3]);
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
	auto model = ui.tableWidget_stats->model();
	model->setData(model->index(0, 0), U->getPlayedMatches(user));
	model->setData(model->index(1, 0), U->getWonMatches(user));
	model->setData(model->index(2, 0), U->getWonMatchesPercentage(user));
	model->setData(model->index(3, 0), U->getLostMatches(user));
	model->setData(model->index(4, 0), U->getLostMatchesPercentage(user));
	model->setData(model->index(5, 0), U->getWonMatchesTrain(user));
	model->setData(model->index(6, 0), U->getWonMatchesMax(user));
	model->setData(model->index(7, 0), U->getWordsCount(user));
	model->setData(model->index(8, 0), U->getMeanLetterCount(user));
	model->setData(model->index(9, 0), U->getMeanWordScore(user));

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