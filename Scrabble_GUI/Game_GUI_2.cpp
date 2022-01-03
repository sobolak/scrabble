#include "Game_GUI_2.h"
#include "Results_GUI.h"


Game_GUI_2::Game_GUI_2(QWidget *parent)
	: QDialog(parent)
{	
	ui.setupUi(this);
	//this->user = user;
	//ui.mufasaLabel->setText(QString::fromStdString(this->user->getLogin()));
	gameMap gameMap1;
	mufasa.setNick("mufasa");
	esteban.setNick("esteban");
	srand(time(NULL));
	mufasa.randomCards(gameMap1.cybant);
	esteban.randomCards(gameMap1.cybant);
	mufasa.setCurrentlyPlay(true);
	playerLetterRefresh('m');
	playerLetterRefresh('e');
	refreshGameMap();
	privacyBoard('e');
	ui.estebanHorizontal->setChecked(false);
	ui.estebanVertical->setChecked(false);
	ui.estebanHorizontal->setCheckable(false);
	ui.estebanVertical->setCheckable(false);
	ui.mufasaHorizontal->setCheckable(true);
	ui.mufasaVertical->setCheckable(true);
	ui.mufasaHorizontal->setChecked(true);

	/*QTime time = QTime::fromString("8.30", "m.s");
	ui.mufasaTimer->setTime(time);
	connect(&timer, SIGNAL(timeout()), this, SLOT(mufasaTimer()));
	timer.start(1000);*/
}

Game_GUI_2::Game_GUI_2(User* user, User* user2, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->user = user;
	this->user2 = user2;
	this->passCounter = 0;
	ui.mufasaLabel->setText(QString::fromStdString(this->user->getLogin()));
	ui.estebanLabel->setText(QString::fromStdString(this->user2->getLogin()));
	gameMap gameMap1;
	this->match = globalMatchManager->createMatch();
	mufasa.setNick("mufasa");
	esteban.setNick("esteban");
	srand(time(NULL));
	mufasa.randomCards(gameMap1.cybant);
	esteban.randomCards(gameMap1.cybant);
	mufasa.setCurrentlyPlay(true);
	playerLetterRefresh('m');
	playerLetterRefresh('e');
	refreshGameMap();
	privacyBoard('e');
	ui.estebanHorizontal->setChecked(false);
	ui.estebanVertical->setChecked(false);
	ui.estebanHorizontal->setCheckable(false);
	ui.estebanVertical->setCheckable(false);
	ui.mufasaHorizontal->setCheckable(true);
	ui.mufasaVertical->setCheckable(true);
	ui.mufasaHorizontal->setChecked(true);
	QTime time = QTime::fromString("8.30", "m.s");

	ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
	ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
}

Game_GUI_2::~Game_GUI_2()
{
}


void Game_GUI_2::on_mufasaAdd_clicked()
{
	if (mufasa.getCurrentlyPlay() == true && (ui.mufasaHorizontal->isChecked() || ui.mufasaVertical->isChecked())) {
		this->passCounter = 0;
		playerMove(mufasa, 'm');
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color :darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color :darkRed; color : cyan;}");
		refreshGameMap();
		playerLetterRefresh('e');
		privacyBoard('m');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
}

void Game_GUI_2::on_estebanAdd_clicked()
{
	if (esteban.getCurrentlyPlay() == true && (ui.estebanHorizontal->isChecked() || ui.estebanVertical->isChecked() )) {
		this->passCounter = 0;
		playerMove(esteban, 'e');
		mufasa.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		privacyBoard('e');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
}

void Game_GUI_2::on_mufasaChange_clicked() {
	if (mufasa.getCurrentlyPlay() == true) {
		this->passCounter++;
		gatherLetterToChange_1(mufasa, 'm');
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color :  darkBlue; color : white; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan;}");
		playerLetterRefresh('e');
		privacyBoard('m');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
	if (this->passCounter == 6)
	{
		on_pushButton_end_clicked();
	}
}

void Game_GUI_2::on_estebanChange_clicked() {
	if (esteban.getCurrentlyPlay() == true) {
		this->passCounter++;
		gatherLetterToChange_1(esteban, 'e');
		mufasa.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		playerLetterRefresh('m');
		privacyBoard('e');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
	if (this->passCounter == 6)
	{
		on_pushButton_end_clicked();
	}
}

void Game_GUI_2::on_mufasaPass_clicked() {
	if (mufasa.getCurrentlyPlay() == true) {
		this->passCounter++;
		mufasa.setCurrentlyPlay(false);
		esteban.setCurrentlyPlay(true);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color :  darkBlue; color : white;  }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		refreshGameMap();
		playerLetterRefresh('e');
		privacyBoard('m');
		ui.mufasaHorizontal->setChecked(false);
		ui.mufasaVertical->setChecked(false);
		ui.mufasaHorizontal->setCheckable(false);
		ui.mufasaVertical->setCheckable(false);
		ui.estebanHorizontal->setCheckable(true);
		ui.estebanVertical->setCheckable(true);
		ui.estebanHorizontal->setChecked(true);
	}
	if (this->passCounter == 6)
	{
		on_pushButton_end_clicked();
	}
}

void Game_GUI_2::on_estebanPass_clicked() {
	if (esteban.getCurrentlyPlay() == true) {
		this->passCounter++;
		mufasa.setCurrentlyPlay(true);
		esteban.setCurrentlyPlay(false);
		ui.mufasaLabel->setStyleSheet("QLabel { background-color : darkRed; color : cyan; }");
		ui.estebanLabel->setStyleSheet("QLabel { background-color : darkBlue; color : white; }");
		refreshGameMap();
		playerLetterRefresh('m');
		privacyBoard('e');
		ui.estebanHorizontal->setChecked(false);
		ui.estebanVertical->setChecked(false);
		ui.estebanHorizontal->setCheckable(false);
		ui.estebanVertical->setCheckable(false);
		ui.mufasaHorizontal->setCheckable(true);
		ui.mufasaVertical->setCheckable(true);
		ui.mufasaHorizontal->setChecked(true);
	}
	if (this->passCounter == 6)
	{
		on_pushButton_end_clicked();
	}
}

void Game_GUI_2::privacyBoard(char c) {
	QString tmp = '#';
	if (c == 'm') {
		auto model = ui.mufasaBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'e') {
		auto model = ui.estebanBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			model->setData(model->index(0, i), tmp);
		}
	}
}

void Game_GUI_2::playerLetterRefresh(char c) {
	if (c == 'm') {
		auto model = ui.mufasaBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(mufasa.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
	else if (c == 'e') {
		auto model = ui.estebanBoard->model();
		for (int i{ 0 }; i < 10; ++i) {
			QString tmp = char(esteban.getPlayerCardsName(i));
			model->setData(model->index(0, i), tmp);
		}
	}
}

void Game_GUI_2::playerMove(player& playerPlay, char c) {
	if (c == 'm') {
		auto model = ui.tableWidget_game->model();
		std::string word = ui.mufasaWord->text().toStdString();
		bool check_word = true;
		if (word == "") {
			check_word = false;
		}
		if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
			int x = ui.mufasaColumn->currentText().toInt();
			int y = ui.mufasaRow->currentText().toInt();
			int cnt = 0;
			int s = 0;
			for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
				if (ui.mufasaHorizontal->isChecked()) {
					if (this->gameMap1.board[y][x + cnt].isOccupied()) {
						if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
								this->gameMap1.board[y][x + cnt].setSession(1);
								this->gameMap1.board[y][x + cnt].setLetter(lett);
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
						if (this->gameMap1.board[y + cnt][x].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
								this->gameMap1.board[y + cnt][x].setSession(1);
								this->gameMap1.board[y + cnt][x].setLetter(lett);
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
			for (int i{ 0 }; i < 10; ++i) {
				playerPlay.setPlayerCardsChoiceToWrite(i, false);
			}
			if (check_word == true) {
				check_word = this->gameMap1.correctMove(mufasa);
				if (check_word == true) {
					int x = ui.mufasaColumn->currentText().toInt();
					int y = ui.mufasaRow->currentText().toInt();
					int cnt = 0;
					for (auto lett : word) {
						if (ui.mufasaHorizontal->isChecked()) {
							model->setData(model->index(y, x + cnt), QString(lett));
							this->gameMap1.board[y][x + cnt].setSession(2);
							this->gameMap1.board[y][x + cnt].setLetter(lett);
						}
						else {
							model->setData(model->index(y + cnt, x), QString(lett));
							this->gameMap1.board[y + cnt][x].setSession(2);
							this->gameMap1.board[y + cnt][x].setLetter(lett);
						}
						++cnt;
					}
					playerPlay.changeUsedCards(word, gameMap1.cybant);
					gameMap1.playerPointsCount(playerPlay, user, match);
					ui.mufasaWord->setText(""); //zmiana tabelki
					playerLetterRefresh('m');
				}
			}
			if (!check_word) {
				gameMap1.incorrextMoveOfPlayer();
				ui.mufasaWord->setText(""); //zmiana tabelki
			}
		}
	}
	else if (c == 'e') {
		auto model = ui.tableWidget_game->model();
		std::string word = ui.estebanWord->text().toStdString();
		bool check_word = true;
		if (word == "") {
			check_word = false;
		}
		if (check_word) { //trzeba dodac jakies rzeczy gdy slowo nie znajduje sie w slowniku dic
			int x = ui.estebanColumn->currentText().toInt();
			int y = ui.estebanRow->currentText().toInt();
			int cnt = 0;
			int s = 0;
			for (auto lett : word) { //sprawdzenie czy na odpowiednich pozycjach jest to samo i czy litery istnieja odpowiednio
				if (ui.estebanHorizontal->isChecked()) {
					if (this->gameMap1.board[y][x + cnt].isOccupied()) {
						if (this->gameMap1.board[y][x + cnt].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
								this->gameMap1.board[y][x + cnt].setSession(1);
								this->gameMap1.board[y][x + cnt].setLetter(lett);
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
						if (this->gameMap1.board[y + cnt][x].getLetter() != lett) {
							check_word = false;
						}
					}
					else {
						check_word = false;
						for (int i{ 0 }; i < 10; ++i) {
							if (lett == char(playerPlay.getPlayerCardsName(i)) && playerPlay.getPlayerCardsChoiceToWrite(i) == false) {
								playerPlay.setPlayerCardsChoiceToWrite(i, true);
								this->gameMap1.board[y + cnt][x].setSession(1);
								this->gameMap1.board[y + cnt][x].setLetter(lett);
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
			for (int i{ 0 }; i < 10; ++i) {
				playerPlay.setPlayerCardsChoiceToWrite(i, false);
			}
			if (check_word == true) {
				check_word = this->gameMap1.correctMove(mufasa);
				if (check_word == true) {
					int x = ui.estebanColumn->currentText().toInt();
					int y = ui.estebanRow->currentText().toInt();
					int cnt = 0;
					for (auto lett : word) {
						if (ui.estebanHorizontal->isChecked()) {
							model->setData(model->index(y, x + cnt), QString(lett));
							this->gameMap1.board[y][x + cnt].setSession(2);
							this->gameMap1.board[y][x + cnt].setLetter(lett);
						}
						else {
							model->setData(model->index(y + cnt, x), QString(lett));
							this->gameMap1.board[y + cnt][x].setSession(2);
							this->gameMap1.board[y + cnt][x].setLetter(lett);
						}
						++cnt;
					}
					playerPlay.changeUsedCards(word, gameMap1.cybant);
					gameMap1.playerPointsCount(playerPlay, user2, match);
					ui.estebanWord->setText(""); //zmiana tabelki
					playerLetterRefresh('e');
				}
			}
			if (!check_word) {
				gameMap1.incorrextMoveOfPlayer();
				ui.estebanWord->setText(""); //zmiana tabelki
			}
		}
	}
}

void Game_GUI_2::refreshGameMap() {
	auto model = ui.tableWidget_game->model();
	for (int i = 0; i < 15; i++) { // refresh tablicy
		for (int j = 0; j < 15; j++) {
			if (gameMap1.board[i][j].getSession() == 1 || gameMap1.board[i][j].getSession() == 2)
				model->setData(model->index(i, j), QString(gameMap1.board[i][j].getLetter()));
		}
	}

	QString x = QString::number(mufasa.getPlayerPoints());
	auto bufforM = ui.mufasaPoint;
	bufforM->setText(x);

	QString y = QString::number(esteban.getPlayerPoints());
	auto bufforE = ui.estebanPoint;
	bufforE->setText(y);
}

void Game_GUI_2::gatherLetterToChange_1(player& playerGane, char c) {
	if (c == 'm') {
		if (ui.checkBox_1->isChecked()) {
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
		playerLetterRefresh('m');

		playerGane.changeChosenCardsUnchecked();
		ui.checkBox_1->setCheckState(Qt::Unchecked);
		ui.checkBox_2->setCheckState(Qt::Unchecked);
		ui.checkBox_3->setCheckState(Qt::Unchecked);
		ui.checkBox_4->setCheckState(Qt::Unchecked);
		ui.checkBox_5->setCheckState(Qt::Unchecked);
		ui.checkBox_6->setCheckState(Qt::Unchecked);
		ui.checkBox_7->setCheckState(Qt::Unchecked);
		ui.checkBox_8->setCheckState(Qt::Unchecked);
		ui.checkBox_9->setCheckState(Qt::Unchecked);
		ui.checkBox_10->setCheckState(Qt::Unchecked);
	}
	else if (c == 'e') {
		if (ui.checkBox_11->isChecked()) {
			playerGane.setPlayerCardsToChange(0, true);
		}
		if (ui.checkBox_12->isChecked()) {
			playerGane.setPlayerCardsToChange(1, true);
		}
		if (ui.checkBox_13->isChecked()) {
			playerGane.setPlayerCardsToChange(2, true);
		}
		if (ui.checkBox_14->isChecked()) {
			playerGane.setPlayerCardsToChange(3, true);
		}
		if (ui.checkBox_15->isChecked()) {
			playerGane.setPlayerCardsToChange(4, true);
		}
		if (ui.checkBox_16->isChecked()) {
			playerGane.setPlayerCardsToChange(5, true);
		}
		if (ui.checkBox_17->isChecked()) {
			playerGane.setPlayerCardsToChange(6, true);
		}
		if (ui.checkBox_18->isChecked()) {
			playerGane.setPlayerCardsToChange(7, true);
		}
		if (ui.checkBox_19->isChecked()) {
			playerGane.setPlayerCardsToChange(8, true);
		}
		if (ui.checkBox_20->isChecked()) {
			playerGane.setPlayerCardsToChange(9, true);
		}
		playerGane.changeChosenCards(gameMap1.cybant);
		playerLetterRefresh('e');

		playerGane.changeChosenCardsUnchecked();
		ui.checkBox_11->setCheckState(Qt::Unchecked);
		ui.checkBox_12->setCheckState(Qt::Unchecked);
		ui.checkBox_13->setCheckState(Qt::Unchecked);
		ui.checkBox_14->setCheckState(Qt::Unchecked);
		ui.checkBox_15->setCheckState(Qt::Unchecked);
		ui.checkBox_16->setCheckState(Qt::Unchecked);
		ui.checkBox_17->setCheckState(Qt::Unchecked);
		ui.checkBox_18->setCheckState(Qt::Unchecked);
		ui.checkBox_19->setCheckState(Qt::Unchecked);
		ui.checkBox_20->setCheckState(Qt::Unchecked);
	}
	refreshGameMap();
}

void Game_GUI_2::on_pushButton_end_clicked()
{
	Results_GUI results(this->user, this->user2, nullptr, nullptr, this->match);
	this->hide();
	results.setModal(true);
	results.exec();
}