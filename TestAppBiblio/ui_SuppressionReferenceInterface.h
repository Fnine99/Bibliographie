/********************************************************************************
** Form generated from reading UI file 'SuppressionReferenceInterface.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPPRESSIONREFERENCEINTERFACE_H
#define UI_SUPPRESSIONREFERENCEINTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SuppressionReferenceInterface
{
public:
    QLabel *label;
    QLineEdit *entreeid;
    QPushButton *Confirmer;

    void setupUi(QDialog *SuppressionReferenceInterface)
    {
        if (SuppressionReferenceInterface->objectName().isEmpty())
            SuppressionReferenceInterface->setObjectName(QString::fromUtf8("SuppressionReferenceInterface"));
        SuppressionReferenceInterface->resize(636, 470);
        label = new QLabel(SuppressionReferenceInterface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 91, 21));
        entreeid = new QLineEdit(SuppressionReferenceInterface);
        entreeid->setObjectName(QString::fromUtf8("entreeid"));
        entreeid->setGeometry(QRect(160, 50, 261, 28));
        Confirmer = new QPushButton(SuppressionReferenceInterface);
        Confirmer->setObjectName(QString::fromUtf8("Confirmer"));
        Confirmer->setGeometry(QRect(250, 170, 90, 28));

        retranslateUi(SuppressionReferenceInterface);
        QObject::connect(Confirmer, SIGNAL(clicked()), SuppressionReferenceInterface, SLOT(confirmationDonnees()));

        QMetaObject::connectSlotsByName(SuppressionReferenceInterface);
    } // setupUi

    void retranslateUi(QDialog *SuppressionReferenceInterface)
    {
        SuppressionReferenceInterface->setWindowTitle(QApplication::translate("SuppressionReferenceInterface", "SuppressionReferenceInterface", nullptr));
        label->setText(QApplication::translate("SuppressionReferenceInterface", "Identification :", nullptr));
        Confirmer->setText(QApplication::translate("SuppressionReferenceInterface", "Confirmer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuppressionReferenceInterface: public Ui_SuppressionReferenceInterface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPPRESSIONREFERENCEINTERFACE_H
