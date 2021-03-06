#include "RegenwaldQuiz.h"

#ifdef LINUX
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
#include <QString>
#include <QMessageBox>
#ifdef LINUX
#pragma GCC diagnostic pop
#endif

#include <string>
#include <fstream>

#define ASK(f, a1, a1b, a2, a2b, a3, a3b) questions.push_back(Frage((std::string)f, Antwort((std::string)a1, (bool)a1b), Antwort((std::string)a2, (bool)a2b), Antwort((std::string)a3, (bool)a3b)))

RegenwaldQuiz::RegenwaldQuiz(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(weiter()));

    ASK(" 1. In welcher Klimazone liegt der tropische Regenwald?", u8"\u00C4quatoriale Klimazone", true, "Zone des tropischen Wechelklimas", true, "Gar keine", false);
    ASK(" 2. Wie ist es im tropischen Regenwald?", u8"schw\u00FChl", true, u8"dr\u00FCckend hei\u00DF", true, "feucht", true);
    ASK(u8" 3. Wie ver\u00E4ndert sich der Lichteinfall zum Boden hin?", u8"Er wird schw\u00E4cher", true, "Er wird mehr", false, "Er bliebt gleich", false);
    ASK(u8" 4. Wie ver\u00E4ndert sich die Temperatur zum Boden hin?", u8"Es wird hei\u00DFer", false, u8"Es wird k\u00FChler", true, "Es bleibt gleich", false);
    ASK(u8" 5. Wie ver\u00E4ndert sich die Luftfeuchtigkeit zum Boden hin?", "Sie bleibt gleich", false, "Sie wird weniger", false, "Sie wird mehr", true);
    ASK(" 6. Wie ist die Tierwelt?", u8"gro\u00DF", true, "klein", false,"unterschiedlich", true);
    ASK(u8" 7. Wie hoch ist die h\u00F6chste Schicht?", "30m", false, "40m", false, "50m", false);
    ASK(" 8. Was ist der Wichtigste Geofaktor?", "Boden", false, "Klima", true, "Bios", false);
    ASK(" 9. Was ist die Maximum und die minimum Temperatur?", u8"30 \u00B0C", false, u8"35 \u00B0C", true, u8"25 \u00B0C", true);
    ASK("10. Wie haben sich die Wurzeln an das Fehlen von Gestein angepasst?", "Gar nicht", false, "Sie wurzeln sehr viel tiefer", false, "Sie wachsen flach", true);

    maxPoints = questions.size() * 3;
    Frage elm = questions.front();
    ui.label->setText(QString::fromStdString(elm.getText()));
    ui.checkBox->setText(QString::fromStdString(elm.getCasses()[0].getText()));
    ui.checkBox_2->setText(QString::fromStdString(elm.getCasses()[1].getText()));
    ui.checkBox_3->setText(QString::fromStdString(elm.getCasses()[2].getText()));
    ui.checkBox->setChecked(false);
    ui.checkBox_2->setChecked(false);
    ui.checkBox_3->setChecked(false);
    ui.label_2->setText("Punkte: " + QString("%1").arg(points) + " / " + QString("%1").arg(maxPoints));

#ifdef DEBUG
    try {
        std::ofstream fout1("Fragebogen.txt");
        for (auto i = questions.begin(); i != questions.end(); ++i)
        {
            fout1 << std::endl;
            fout1 << i->getText() << std::endl;
            fout1 << std::endl;
            fout1 << "a) " << i->getCasses()[0].getText() << std::endl;
            fout1 << "b) " << i->getCasses()[1].getText() << std::endl;
            fout1 << "c) " << i->getCasses()[2].getText() << std::endl;
            fout1 << std::endl;
        }
        fout1.close();
        std::ofstream fout2("Loesungen.txt");
        auto questions2 = questions;
        for (size_t i = 0; questions2.size() > 0; i++)
        {
            fout2 << i + 1;
            if (questions2.front().getCasses()[0].getIsTrue()) fout2 << "a";
            if (questions2.front().getCasses()[1].getIsTrue()) fout2 << "b";
            if (questions2.front().getCasses()[2].getIsTrue()) fout2 << "c";
            fout2 << std::endl;
            questions2.pop_front();
        }
    }
    catch (std::exception &){}
#endif
}

void RegenwaldQuiz::weiter()
{
    Frage elm = questions.front();

    //bool state1 = ui.checkBox->isChecked();
    //bool state2 = ui.checkBox_2->isChecked();
    //bool state3 = ui.checkBox_3->isChecked();

    //unsigned int err = elm.Test(state1, state2, state3);

    unsigned int err = elm.Test(ui.checkBox->isChecked(), ui.checkBox_2->isChecked(), ui.checkBox_3->isChecked());
    QMessageBox::information(this, "Information", QString("%1").arg(err) + " Fehler", QMessageBox::StandardButton::Close);
    points += 3 - err;
    ui.label_2->setText("Punkte: " + QString("%1").arg(points) + " / " + QString("%1").arg(maxPoints));

    /*if (ui.checkBox->isChecked())
        QMessageBox::information(this, "info", "true");
    else
        QMessageBox::information(this, "info", "false");*/

    questions.pop_front();

    if (questions.size() < 1)
    {
        QMessageBox::information(this, "Auswertung", "Du hast " + QString("%1").arg(points) + " von " + QString("%1").arg(maxPoints) + " Punkten!", QMessageBox::StandardButton::Close);
        close();
        return;
    }

    elm = questions.front();

    ui.label->setText(QString::fromStdString(elm.getText()));
    ui.checkBox->setText(QString::fromStdString(elm.getCasses()[0].getText()));
    ui.checkBox_2->setText(QString::fromStdString(elm.getCasses()[1].getText()));
    ui.checkBox_3->setText(QString::fromStdString(elm.getCasses()[2].getText()));
    ui.checkBox->setChecked(false);
    ui.checkBox_2->setChecked(false);
    ui.checkBox_3->setChecked(false);
}
