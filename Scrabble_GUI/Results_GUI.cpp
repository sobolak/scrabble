#include "Results_GUI.h"
#include "Menu_GUI.h"
#include <map>

using std::vector;
using std::string;
using std::pair;
using std::to_string;

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
	vector<pair<string, int>> score;
	score.push_back({ user->getLogin(), globalMatchManager->getScoreInMatch(user, match) });
	score.push_back({ estebanUser->getLogin(), globalMatchManager->getScoreInMatch(estebanUser, match) });
	if (zeromskiUser != nullptr)
		score.push_back({ zeromskiUser->getLogin(), globalMatchManager->getScoreInMatch(zeromskiUser, match) });
	if (rokokoUser != nullptr)
		score.push_back({ rokokoUser->getLogin(), globalMatchManager->getScoreInMatch(rokokoUser, match) });

	sort(score.begin(), score.end(), [](pair<string, int>& a, pair<string, int>& b) { return a.second > b.second; });
	
	int i = 0;
	for (auto item : score)
	{
		// LOGIN
		model->setData(model->index(i, 0), QString::fromStdString(item.first));
		// SCORE
		model->setData(model->index(i, 1), QString::fromStdString(to_string(item.second)));
		++i;
	}
}

Results_GUI::~Results_GUI()
{
}

void Results_GUI::on_pushButton_continue_clicked()
{
	Menu_GUI menu(this->user);
	this->destroy();
	menu.setModal(true);
	menu.exec();
}

