/********************************************************************************
** Form generated from reading UI file 'AjoutOuvrageInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AJOUTOUVRAGEINTERFACE_H
#define UI_AJOUTOUVRAGEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_AjoutOuvrageInterface
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *entreeauteurs;
    QLineEdit *entreetitre;
    QLineEdit *entreeid;
    QLineEdit *entreeediteur;
    QLineEdit *entreeville;
    QSpinBox *codeannee;
    QPushButton *Confirmer;

    void setupUi(QDialog *AjoutOuvrageInterface)
    {
        if (AjoutOuvrageInterface->objectName().isEmpty())
            AjoutOuvrageInterface->setObjectName(QString::fromUtf8("AjoutOuvrageInterface"));
        AjoutOuvrageInterface->resize(708, 548);
        label = new QLabel(AjoutOuvrageInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 71, 21));
        label_2 = new QLabel(AjoutOuvrageInterface);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 100, 61, 21));
        label_3 = new QLabel(AjoutOuvrageInterface);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 140, 58, 16));
        label_4 = new QLabel(AjoutOuvrageInterface);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 180, 71, 16));
        label_5 = new QLabel(AjoutOuvrageInterface);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 220, 61, 16));
        label_6 = new QLabel(AjoutOuvrageInterface);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 260, 58, 16));
        entreeauteurs = new QLineEdit(AjoutOuvrageInterface);
        entreeauteurs->setObjectName(QString::fromUtf8("entreeauteurs"));
        entreeauteurs->setGeometry(QRect(150, 60, 381, 28));
        entreetitre = new QLineEdit(AjoutOuvrageInterface);
        entreetitre->setObjectName(QString::fromUtf8("entreetitre"));
        entreetitre->setGeometry(QRect(150, 100, 381, 28));
        entreeid = new QLineEdit(AjoutOuvrageInterface);
        entreeid->setObjectName(QString::fromUtf8("entreeid"));
        entreeid->setGeometry(QRect(150, 180, 191, 28));
        entreeediteur = new QLineEdit(AjoutOuvrageInterface);
        entreeediteur->setObjectName(QString::fromUtf8("entreeediteur"));
        entreeediteur->setGeometry(QRect(150, 220, 191, 28));
        entreeville = new QLineEdit(AjoutOuvrageInterface);
        entreeville->setObjectName(QString::fromUtf8("entreeville"));
        entreeville->setGeometry(QRect(150, 260, 191, 28));
        codeannee = new QSpinBox(AjoutOuvrageInterface);
        codeannee->setObjectName(QString::fromUtf8("codeannee"));
        codeannee->setGeometry(QRect(150, 140, 46, 26));
        Confirmer = new QPushButton(AjoutOuvrageInterface);
        Confirmer->setObjectName(QString::fromUtf8("Confirmer"));
        Confirmer->setGeometry(QRect(290, 350, 101, 31));

        retranslateUi(AjoutOuvrageInterface);
        QObject::connect(Confirmer, SIGNAL(clicked()), AjoutOuvrageInterface, SLOT(confirmationDonnees()));

        QMetaObject::connectSlotsByName(AjoutOuvrageInterface);
    } // setupUi

    void retranslateUi(QDialog *AjoutOuvrageInterface)
    {
        AjoutOuvrageInterface->setWindowTitle(QApplication::translate("AjoutOuvrageInterface", "AjoutOuvrageInterface", nullptr));
        label->setText(QApplication::translate("AjoutOuvrageInterface", "Auteurs(s) :", nullptr));
        label_2->setText(QApplication::translate("AjoutOuvrageInterface", "Titre :", nullptr));
        label_3->setText(QApplication::translate("AjoutOuvrageInterface", "Ann\303\251e : ", nullptr));
        label_4->setText(QApplication::translate("AjoutOuvrageInterface", "Identifiant :", nullptr));
        label_5->setText(QApplication::translate("AjoutOuvrageInterface", "\303\211diteur :", nullptr));
        label_6->setText(QApplication::translate("AjoutOuvrageInterface", "Ville :", nullptr));
        Confirmer->setText(QApplication::translate("AjoutOuvrageInterface", "Confirmer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AjoutOuvrageInterface: public Ui_AjoutOuvrageInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AJOUTOUVRAGEINTERFACE_H
