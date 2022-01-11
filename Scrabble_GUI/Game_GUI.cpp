#include "Game_GUI.h"
#include "Results_GUI.h"


Game_GUI::Game_GUI(QWidget* parent)
	: QDialog(parent)
{
	gameMap gameMap1;
	srand(time(NULL));

	mufasa.randomCards(gameMap1.cybant);
	mufasa.setNick("mufasa");

	ui.setupUi(this);
	changeCurrentPlayer(mufasa);
	playerLetterRefresh(mufasa);
}

Game_GUI::Game_GUI(User* user, User* userComputer, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->passCounter = 0;
	this->user = user;
	this->userComputer = userComputer;
	ui.label_user->setText(QString::fromStdString(this->user->getLogin()));
	string DBConfig[4];
	srand(time(NULL));
	this->match = globalMatchManager->createMatch();
	gameMap1.setDifficultyLevel(userComputer->getLogin()[0]);
	mufasa.randomCards(gameMap1.cybant);
	mufasa.setNick("mufasa");
	// mufasa to zawsze domyslny player 1 czy z kompem czy nie i zawsze robi 1 ruch i zawsze jeg literki
	changeCurrentPlayer(mufasa);
	playerLetterRefresh(mufasa);
	ui.label_user->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
	ui.label_name->setText(QString::fromStdString(this->user->getLogin()));
}

Game_GUI::~Game_GUI()
{
}

void Game_GUI::on_pushButton_add_clicked()
{
	this->passCounter = 0;
	playerMove(mufasa);
	gameMap1.computerAction(match, userComputer);
	refreshGameMap();
}

void Game_GUI::on_pushButton_change_clicked() {

	this->passCounter++;
	if (this->passCounter == 4)
	{
		on_pushButton_end_clicked();
	}
	gatherLetterToChange_1(mufasa);
}

void Game_GUI::on_pushButton_pass_clicked() {
	this->passCounter++;
	if (this->passCounter == 4)
	{
		on_pushButton_end_clicked();
	}
	gameMap1.computerAction(match, userComputer);
	refreshGameMap();
}

void Game_GUI::playerLetterRefresh(player player) {
	auto model = ui.tableWidget_letters->model();
	for (int i{ 0 }; i < 10; ++i) { 
		QString tmp = QChar(player.getPlayerCardsName(i));
		model->setData(model->index(0, i), tmp);
	}
}

void Game_GUI::playerMove(player& playerPlay) {
	auto model = ui.tableWidget_game->model();
	bool isConected = false;	
	std::string word = ui.lineEdit_word->text().toStdString();
	bool check_word = true;
	if (word == "") {
		check_word = false;
	}
	if (check_word) { 
		int x = ui.comboBox_column->currentText().toInt();
		int y = ui.comboBox_row->currentText().toInt();
		int cnt = 0;
		int s = 0;
		for (auto lett : word) { 
			if (ui.radioButton_horizontal->isChecked()) {
				if (this->gameMap1.board[y][x + cnt].isOccupied()) {
					isConected = true;
					if ((char)toupper(this->gameMap1.board[y][x + cnt].getLetter()) != (char)toupper(lett)) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if ((char)toupper(lett) == (char)toupper(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
							this->gameMap1.board[y][x + cnt].setSession(1);
							this->gameMap1.board[y][x + cnt].setLetter((char)toupper(lett));
							check_word = true;
							break;
						}
					}
				}
				if (check_word == false)
					break;
			}
			else
			{
				if (this->gameMap1.board[y + cnt][x].isOccupied()) {
					isConected = true;
					if ((char)toupper( this->gameMap1.board[y + cnt][x].getLetter()) != (char)toupper(lett)) {
						check_word = false;
					}
				}
				else {
					check_word = false;
					for (int i{ 0 }; i < 10; ++i) {
						if ((char)toupper(lett) == (char)toupper(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
							playerPlay.setPlayerCardsChoiceToWrite(i, true);
							this->gameMap1.board[y + cnt][x].setSession(1);
							this->gameMap1.board[y + cnt][x].setLetter((char)toupper(lett));
							check_word = true;
							break;
						}
					}
				}
				if (check_word == false)
					break;
			}
			++cnt;
		}

		// ////////////////////////////////////////////////////////////////////////////////////////
		if (check_word == true) {
			if (gameMap1.getFirstMove() == true) {
				if (gameMap1.board[7][7].getSession() != 1) {
					check_word = false;
				}
			}
			else if (isConected == false) {
				check_word = false;
			}
		}
		
		// ////////////////////////////////////////////////////////////////////////////////////////
		
		if (check_word == true) {
			check_word = this->gameMap1.correctMove(mufasa);
			if (check_word == true) {
				int x = ui.comboBox_column->currentText().toInt();
				int y = ui.comboBox_row->currentText().toInt();
				int cnt = 0;
				for (auto lett : word) {
					if (ui.radioButton_horizontal->isChecked()) {
						model->setData(model->index(y, x + cnt), QString((char)toupper(lett)));
						this->gameMap1.board[y][x + cnt].setSession(2);
						this->gameMap1.board[y][x + cnt].setLetter((char)toupper(lett));
					}
					else {
						model->setData(model->index(y + cnt, x), QString((char)toupper(lett)));
						this->gameMap1.board[y + cnt][x].setSession(2);
						this->gameMap1.board[y + cnt][x].setLetter((char)toupper(lett));
					}
					++cnt;
				}
				playerPlay.changeUsedCards(word, gameMap1.cybant);
				gameMap1.setFirstMove(false);
				gameMap1.playerPointsCount(playerPlay, user, match);
				ui.lineEdit_word->setText(""); //zmiana tabelki
				playerLetterRefresh(playerPlay);
			}
		}
		for (int i{ 0 }; i < 10; ++i) {
			playerPlay.setPlayerCardsChoiceToWrite(i, false);
		}
		if (!check_word) {
			gameMap1.incorrextMoveOfPlayer();
			ui.lineEdit_word->setText(""); //zmiana tabelki
		}
	}

}

void Game_GUI::changeCurrentPlayer(player playerPLay) {
	cout << "";
	mufasa.setCurrentlyPlay(true);
	cout << "";
};

void Game_GUI::refreshGameMap() {
	mufasa.setPossibilityToChangeCards(true);
	auto model = ui.tableWidget_game->model();
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 || gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(i, j), QString((char)toupper(gameMap1.board[i][j].getLetter())));
		}
	}


	QString x = QString::number(gameMap1.getComputerPoints());
	auto computerPoints = ui.textEdit;
	computerPoints->setText(x);

	QString y = QString::number(mufasa.getPlayerPoints());
	auto playerPoints = ui.player_point;
	playerPoints->setText(y);
}

void Game_GUI::gatherLetterToChange_1(player& playerGane) {
	if (ui.checkBox->isChecked()) {
		playerGane.setPlayerCardsToChange(0, true);
	}
	if (ui.checkBox_2->isChecked()) {
		playerGane.setPlayerCardsToChange(1, true);
	}
	if (ui.checkBox_3->isChecked()) {
		playerGane.setPlayerCardsToChange(2, true);
	}
	if (ui.checkBox_4->isChecked()) {
		playerGane.setPlayerCardsToChange(3, true);
	}
	if (ui.checkBox_5->isChecked()) {
		playerGane.setPlayerCardsToChange(4, true);
	}
	if (ui.checkBox_6->isChecked()) {
		playerGane.setPlayerCardsToChange(5, true);
	}
	if (ui.checkBox_7->isChecked()) {
		playerGane.setPlayerCardsToChange(6, true);
	}
	if (ui.checkBox_8->isChecked()) {
		playerGane.setPlayerCardsToChange(7, true);
	}
	if (ui.checkBox_9->isChecked()) {
		playerGane.setPlayerCardsToChange(8, true);
	}
	if (ui.checkBox_10->isChecked()) {
		playerGane.setPlayerCardsToChange(9, true);
	}
	playerGane.changeChosenCards(gameMap1.cybant);
	playerLetterRefresh(mufasa);

	playerGane.changeChosenCardsUnchecked();
	ui.checkBox->setCheckState(Qt::Unchecked);
	ui.checkBox_2->setCheckState(Qt::Unchecked);
	ui.checkBox_3->setCheckState(Qt::Unchecked);
	ui.checkBox_4->setCheckState(Qt::Unchecked);
	ui.checkBox_5->setCheckState(Qt::Unchecked);
	ui.checkBox_6->setCheckState(Qt::Unchecked);
	ui.checkBox_7->setCheckState(Qt::Unchecked);
	ui.checkBox_8->setCheckState(Qt::Unchecked);
	ui.checkBox_9->setCheckState(Qt::Unchecked);
	ui.checkBox_10->setCheckState(Qt::Unchecked);

	gameMap1.computerAction(match, userComputer);
	refreshGameMap();
}

void Game_GUI::on_pushButton_end_clicked()
{
	Results_GUI results(this->user, this->userComputer, nullptr, nullptr, this->match);
	this->hide();
	results.setModal(true);
	results.exec();
}