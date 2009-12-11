#include <QtGui/QApplication>
#include "qttd.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTD w;
    w.show();
    return a.exec();
}
