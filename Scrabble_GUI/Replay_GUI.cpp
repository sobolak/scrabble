#include "Replay_GUI.h"
#include "Menu_GUI.h"
#include <algorithm>
#include <set>

using std::set;
using std::stoi;
using std::pair;
using std::for_each;

Replay_GUI::Replay_GUI(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

Replay_GUI::Replay_GUI(User* user, int matchID, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
	this->movesList = globalMatchManager->getAllMovesList(new Match(matchID));
	set<string> loginsSet;
	for_each(this->movesList->begin(), this->movesList->end(), [&](Move* move)
	{
		loginsSet.insert(move->getUser()->getLogin());
	});

	auto model = ui.tableWidget_score->model();
	int i = 0;
	for (auto login : loginsSet)
	{
		this->logins.insert(pair<string, int>(login, i));
		model->setData(model->index(i, 0), QString::fromStdString(login));
		model->setData(model->index(i, 1), 0);
		++i;
	}
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

void Replay_GUI::on_pushButton_continue_clicked()
{
	if (this->movesList->empty())
		return;

	Move* currMove = this->movesList->back();
	this->movesList->pop_back();

	auto scoreModel = ui.tableWidget_score->model();
	map<string, int>::iterator itr = this->logins.find(currMove->getUser()->getLogin());

	int currScore = stoi(scoreModel->data(scoreModel->index(itr->second, 1)).toString().toStdString());
	scoreModel->setData(scoreModel->index(itr->second, 1), currScore + currMove->getScore());

	auto gameModel = ui.tableWidget_game->model();
	int i = 0;
	if (currMove->getIsVert())
	{
		for (char letter : currMove->getWord())
		{
			gameModel->setData(gameModel->index(currMove->getRow() + i, currMove->getCol()), QString(letter));
			++i;
		}
	}
	else
	{
		for (char letter : currMove->getWord())
		{
			gameModel->setData(gameModel->index(currMove->getRow(), currMove->getCol() + i), QString(letter));
			++i;
		}
	}
}
