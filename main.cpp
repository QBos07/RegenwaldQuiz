#include "RegenwaldQuiz.h"

#ifdef LINUX
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
#include <QtWidgets/QApplication>
#ifdef LINUX
#pragma GCC diagnostic pop
#endif


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RegenwaldQuiz w;
    w.show();
    return a.exec();
}
