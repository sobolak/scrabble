#include "Scrabble_GUI.h"
#include "Game_GUI.h"
#include "Logging_GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scrabble_GUI w;
    w.show();
    return a.exec();
}
