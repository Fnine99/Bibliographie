/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutJournalInterface.cpp
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 16:30
 */

#include "AjoutJournalInterface.h"
#include "validationFormat.h"
#include "QMessageBox"


/**
 * \brief Constructeur de la classe AjoutJournalInterface.
 * @param *parent
 *
 */
AjoutJournalInterface::AjoutJournalInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe AjoutJournalInterface.
 *
 */
AjoutJournalInterface::~AjoutJournalInterface () { }


//On récupere ici les valeurs tapées sur l'interface


/*!
 *
 * \brief L'accesseur du nom d'auteur entré.
 * \return Le nom d'auteur.
 */
QString
AjoutJournalInterface::reqAuteurs () const
{
  return widget.entreeauteurs ->text ();

}


/*!
 *
 * \brief L'accesseur du nom du titre entré.
 * \return Le titre du titre de la référence.
 */
QString
AjoutJournalInterface::reqTitre () const
{
  return widget.entreetitre ->text ();

}


/*!
 *
 * \brief L'accesseur de l'année entrée.
 * \return L'année de la rérérence.
 */
int
AjoutJournalInterface::reqAnnee () const
{
  return widget.codeannee ->value ();
}


/*!
 *
 * \brief L'accesseur de l'identifiant entré.
 * \return L'identifiant de la référence.
 */
QString
AjoutJournalInterface::reqIdentifiant () const
{
  return widget.entreeid ->text ();

}


/*!
 *
 * \brief L'accesseur du nom du journal entré.
 * \return Le nom du journal.
 */
QString
AjoutJournalInterface::reqNom () const
{
  return widget.entreejournal ->text ();

}


/*!
 *
 * \brief L'accesseur du volume entré.
 * \return Le volume.
 */
int
AjoutJournalInterface::reqVolume () const
{
  return widget.codevolume ->value ();

}


/*!
 *
 * \brief L'accesseur du numéro entré.
 * \return Le numéro.
 */
int
AjoutJournalInterface::reqNumero () const
{
  return widget.codenumero ->value ();

}


/*!
 *
 * \brief L'accesseur de la page entrée.
 * \return La page.
 */
int
AjoutJournalInterface::reqPage () const
{
  return widget.codepage ->value ();

}


/*!
 *
 * \brief Méthode de validation des données entrées sur l'interface.
 *
 */
void
AjoutJournalInterface::confirmationDonnees ()
{

  if (reqAuteurs ().isEmpty ())
    {

      QString erreur ("Le nom d'auteur ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (!(util::validerFormatNom (reqAuteurs ().toStdString ())))
    {

      QString erreur ("Le nom d'auteur n'est pas valide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }



  if (reqTitre ().isEmpty ())
    {

      QString erreur ("Le titre ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }


  if (reqIdentifiant ().isEmpty ())
    {

      QString erreur ("L'identifiant ISBN ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (!(util::validerCodeIssn (reqIdentifiant ().toStdString ())))
    {

      QString erreur ("L'identifiant ISSN n'est pas valide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }



  if (reqNom ().isEmpty ())
    {

      QString erreur ("Le nom du journal ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (reqAnnee () <= 0)
    {

      QString erreur ("L'année doit etre strictement positive");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }


  if (reqVolume () <= 0)
    {

      QString erreur ("Le volume doit etre strictement positif");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }


  if (reqAnnee () <= 0)
    {

      QString erreur ("Le numero doit etre strictement positif");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (reqPage () <= 0)
    {

      QString erreur ("La page doit etre strictement positive");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  accept ();
}