/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutOuvrageInterface.cpp
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 19:36
 */

#include "AjoutOuvrageInterface.h"
#include "validationFormat.h"
#include "QMessageBox"


/**
 * \brief Constructeur de la classe AjoutOuvrageInterface.
 * @param *parent
 *
 */
AjoutOuvrageInterface::AjoutOuvrageInterface (QWidget *parent) :
QDialog (parent)
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe AjoutOuvrageInterface.
 *
 */
AjoutOuvrageInterface::~AjoutOuvrageInterface () { }


/*!
 *
 * \brief L'accesseur du nom d'auteur entré.
 * \return Le nom d'auteur.
 */
QString
AjoutOuvrageInterface::reqAuteurs () const
{
  return widget.entreeauteurs ->text ();

}


/*!
 *
 * \brief L'accesseur du nom du titre entré.
 * \return Le titre du titre de la référence.
 */
QString
AjoutOuvrageInterface::reqTitre () const
{
  return widget.entreetitre ->text ();

}


/*!
 *
 * \brief L'accesseur de l'année entrée.
 * \return L'année de la rérérence.
 */
int
AjoutOuvrageInterface::reqAnnee () const
{
  return widget.codeannee ->value ();
}


/*!
 *
 * \brief L'accesseur de l'identifiant entré.
 * \return L'identifiant de la référence.
 */
QString
AjoutOuvrageInterface::reqIdentifiant () const
{
  return widget.entreeid ->text ();

}


/*!
 *
 * \brief L'accesseur de l'éditeur entré.
 * \return L'éditeur.
 */
QString
AjoutOuvrageInterface::reqEditeur () const
{
  return widget.entreeediteur ->text ();

}


/*!
 *
 * \brief L'accesseur de la ville entrée.
 * \return La ville.
 */
QString
AjoutOuvrageInterface::reqVille () const
{
  return widget.entreeville ->text ();

}


/*!
 *
 * \brief Méthode de validation des données entrées sur l'interface.
 *
 */
void
AjoutOuvrageInterface::confirmationDonnees ()
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

  if (reqAnnee () <= 0)
    {

      QString erreur ("L'année doit etre strictement positive");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }


  if (reqIdentifiant ().isEmpty ())
    {

      QString erreur ("L'identifiant ISSN ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (!(util::validerCodeIsbn (reqIdentifiant ().toStdString ())))
    {

      QString erreur ("L'identifiant ISBN n'est pas valide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }



  if (reqEditeur ().isEmpty ())
    {

      QString erreur ("Le nom de l'éditeur ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  if (reqVille ().isEmpty ())
    {

      QString erreur ("Le nom de la ville ne doit pas etre vide");
      QMessageBox::information (this, "ERREUR", erreur);
      return;

    }

  accept ();
}