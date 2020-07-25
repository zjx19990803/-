#include <QApplication>
#include "widgettable.h"

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);

    WidgetTable *mainWin = new WidgetTable();
    mainWin->show();

    return a.exec();
}
