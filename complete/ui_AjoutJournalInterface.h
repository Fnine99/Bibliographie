/********************************************************************************
** Form generated from reading UI file 'AjoutJournalInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTJOURNALINTERFACE_H
#define UI_AJOUTJOURNALINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutJournalInterface
{
public:
    QLabel *label;
    QLineEdit *entreeauteurs;
    QLabel *label_2;
    QLineEdit *entreetitre;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QSpinBox *codeannee;
    QLineEdit *entreeid;
    QLineEdit *entreejournal;
    QPushButton *Confirmer;
    QSpinBox *codevolume;
    QSpinBox *codenumero;
    QSpinBox *codepage;

    void setupUi(QDialog *AjoutJournalInterface)
    {
        if (AjoutJournalInterface->objectName().isEmpty())
            AjoutJournalInterface->setObjectName(QString::fromUtf8("AjoutJournalInterface"));
        AjoutJournalInterface->resize(694, 578);
        label = new QLabel(AjoutJournalInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 71, 31));
        entreeauteurs = new QLineEdit(AjoutJournalInterface);
        entreeauteurs->setObjectName(QString::fromUtf8("entreeauteurs"));
        entreeauteurs->setGeometry(QRect(180, 50, 371, 28));
        label_2 = new QLabel(AjoutJournalInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 61, 21));
        entreetitre = new QLineEdit(AjoutJournalInterface);
        entreetitre->setObjectName(QString::fromUtf8("entreetitre"));
        entreetitre->setGeometry(QRect(180, 100, 371, 31));
        label_3 = new QLabel(AjoutJournalInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 150, 61, 21));
        label_4 = new QLabel(AjoutJournalInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 200, 81, 21));
        label_5 = new QLabel(AjoutJournalInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 250, 101, 31));
        label_6 = new QLabel(AjoutJournalInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 310, 58, 16));
        label_7 = new QLabel(AjoutJournalInterface);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(60, 360, 58, 16));
        label_8 = new QLabel(AjoutJournalInterface);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(60, 410, 58, 16));
        codeannee = new QSpinBox(AjoutJournalInterface);
        codeannee->setObjectName(QString::fromUtf8("codeannee"));
        codeannee->setGeometry(QRect(180, 150, 61, 26));
        entreeid = new QLineEdit(AjoutJournalInterface);
        entreeid->setObjectName(QString::fromUtf8("entreeid"));
        entreeid->setGeometry(QRect(180, 200, 191, 28));
        entreejournal = new QLineEdit(AjoutJournalInterface);
        entreejournal->setObjectName(QString::fromUtf8("entreejournal"));
        entreejournal->setGeometry(QRect(180, 250, 281, 28));
        Confirmer = new QPushButton(AjoutJournalInterface);
        Confirmer->setObjectName(QString::fromUtf8("Confirmer"));
        Confirmer->setGeometry(QRect(290, 490, 101, 31));
        codevolume = new QSpinBox(AjoutJournalInterface);
        codevolume->setObjectName(QString::fromUtf8("codevolume"));
        codevolume->setGeometry(QRect(180, 310, 61, 26));
        codenumero = new QSpinBox(AjoutJournalInterface);
        codenumero->setObjectName(QString::fromUtf8("codenumero"));
        codenumero->setGeometry(QRect(180, 360, 61, 26));
        codepage = new QSpinBox(AjoutJournalInterface);
        codepage->setObjectName(QString::fromUtf8("codepage"));
        codepage->setGeometry(QRect(180, 410, 61, 26));

        retranslateUi(AjoutJournalInterface);
        QObject::connect(Confirmer, SIGNAL(clicked()), AjoutJournalInterface, SLOT(confirmationDonnees()));

        QMetaObject::connectSlotsByName(AjoutJournalInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutJournalInterface)
    {
        AjoutJournalInterface->setWindowTitle(QApplication::translate("AjoutJournalInterface", "AjoutJournalInterface", nullptr));
        label->setText(QApplication::translate("AjoutJournalInterface", "Auteur(s) :", nullptr));
        label_2->setText(QApplication::translate("AjoutJournalInterface", "Titre :", nullptr));
        label_3->setText(QApplication::translate("AjoutJournalInterface", "Ann\303\251e :", nullptr));
        label_4->setText(QApplication::translate("AjoutJournalInterface", "Identifiant :", nullptr));
        label_5->setText(QApplication::translate("AjoutJournalInterface", "Nom du journal :", nullptr));
        label_6->setText(QApplication::translate("AjoutJournalInterface", "Volume :", nullptr));
        label_7->setText(QApplication::translate("AjoutJournalInterface", "Num\303\251ro :", nullptr));
        label_8->setText(QApplication::translate("AjoutJournalInterface", "Page :", nullptr));
        Confirmer->setText(QApplication::translate("AjoutJournalInterface", "Confirmer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutJournalInterface: public Ui_AjoutJournalInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTJOURNALINTERFACE_H
