/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SuppressionReferenceInterface.cpp
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 20:51
 */

#include "SuppressionReferenceInterface.h"
#include "validationFormat.h"
#include <QMessageBox>


/**
 * \brief Constructeur de la classe SuppressionReferenceInterface.
 * @param *parent
 *
 */
SuppressionReferenceInterface::SuppressionReferenceInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe SuppressionReferenceInterface.
 *
 */
SuppressionReferenceInterface::~SuppressionReferenceInterface () { }


/*!
 *
 * \brief L'accesseur de l'identifiant entré.
 * \return L'identifiant de la référence.
 */
QString
SuppressionReferenceInterface::reqIdentifiant () const
{
  return widget.entreeid ->text ();

}


/*!
 *
 * \brief Méthode de validation des données entrées sur l'interface.
 *
 */
void
SuppressionReferenceInterface::confirmationDonnees ()
{


  if (reqIdentifiant ().isEmpty ())
    {

      QString message ("L'identifiant ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", message);
      return;

    }

  if (!(util::validerCodeIsbn (reqIdentifiant ().toStdString ())
        || util::validerCodeIssn (reqIdentifiant ().toStdString ())))
    {

      QString erreur ("L'identifiant n'est pas valide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  accept ();

}