/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BibliographieInterface.cpp
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 16:45
 */

#include "Bibliographie.h"
#include "BibliographieInterface.h"
#include "Journal.h"
#include "AjoutJournalInterface.h"
#include "Ouvrage.h"
#include "AjoutOuvrageInterface.h"
#include "SuppressionReferenceInterface.h"
#include "ReferenceException.h"
#include "QMessageBox"
#include <sstream>
#include <QWidget>

using namespace biblio;
using namespace std;


/**
 * \brief Constructeur de la classe BibliographieInterface.
 * @param *parent
 *
 */
BibliographieInterface::BibliographieInterface (QWidget *parent) :  QMainWindow (parent), m_biblio ("Bibliographie TP4")
{
  widget.setupUi (this);
}


/**
 * \brief Destructeur de la classe BibliographieInterface.
 *
 */
BibliographieInterface::~BibliographieInterface () { }


/*!
 *
 * \brief Méthode permettant d'ajouter un journal a la bibliographie.
 * @param p_auteurs
 * @param p_titre
 * @param p_annee
 * @param p_id
 * @param p_nom
 * @param p_volume
 * @param p_numero
 * @param p_page
 *
 */
void
BibliographieInterface::ajouterJournal (const string& p_auteurs,
                                        const string& p_titre,
                                        int p_annee,
                                        const string& p_id,
                                        const string& p_nom,
                                        int p_volume,
                                        int p_numero,
                                        int p_page
                                        )
{

  try
    {


      Journal refjournal (p_auteurs, p_titre, p_annee, p_id, p_nom, p_volume, p_numero, p_page);


      m_biblio.ajouterReference (refjournal);

    }

  catch (ReferenceDejaPresenteException& excp)
    {
      QString erreur = (excp.what ());
      QMessageBox::information (this, "ERREUR", erreur);
    }

}


/*!
 *
 * \brief Méthode permettant d'ajouter un ouvrage a la bibliographie.
 * @param p_auteurs
 * @param p_titre
 * @param p_annee
 * @param p_id
 * @param p_editeur
 * @param p_ville
 *
 */
void
BibliographieInterface::ajouterOuvrage (const std::string& p_auteurs,
                                        const std::string& p_titre,
                                        int p_annee,
                                        const std::string& p_id,
                                        const std::string& p_editeur,
                                        const std::string& p_ville)
{

  try
    {


      Ouvrage refouvrage (p_auteurs, p_titre, p_annee, p_id, p_editeur, p_ville);


      m_biblio.ajouterReference (refouvrage);
    }
  catch (ReferenceDejaPresenteException& excp)
    {
      QString erreur = (excp.what ());
      QMessageBox::information (this, "ERREUR", erreur);
    }

}


/*!
 *
 * \brief Méthode permettant de supprimer une référence de la bibliographie a partir de son identifiant.
 * \param p_id - Objet string correspondant a un identifiant (ISSN ou ISBN).
 *
 */
void
BibliographieInterface::supprimerReference (const std::string& p_id)
{

  try
    {
      m_biblio.supprimerReference (p_id);
    }
  catch (ReferenceAbsenteException& excp)
    {
      QString erreur = (excp.what ());
      QMessageBox::information (this, "ERREUR", erreur);
    }

}


/*!
 *
 * \brief Méthode de lien entre l'interface et le code pour enregistrer un journal.
 *
 */
void
BibliographieInterface::dialAjoutJournal ()
{

  AjoutJournalInterface journ;
  if (journ.exec ())
    {


      ajouterJournal  (journ.reqAuteurs ().toStdString (),
                       journ.reqTitre ().toStdString (),
                       journ.reqAnnee (),
                       journ.reqIdentifiant ().toStdString (),
                       journ.reqNom ().toStdString (),
                       journ.reqVolume (),
                       journ.reqNumero (),
                       journ.reqPage ());
      widget.affichagebiblio->setText (m_biblio.reqBibliographieFormate ().c_str ());
    }

}


/*!
 *
 * \brief Méthode de lien entre l'interface et le code pour enregistrer un ouvrage.
 *
 */
void
BibliographieInterface::dialAjoutOuvrage ()

{

  AjoutOuvrageInterface ouv;
  if (ouv.exec ())
    {

      ajouterOuvrage (ouv.reqAuteurs ().toStdString (),
                      ouv.reqTitre ().toStdString (),
                      ouv.reqAnnee (),
                      ouv.reqIdentifiant ().toStdString (),
                      ouv.reqEditeur ().toStdString (),
                      ouv.reqVille ().toStdString ());
      widget.affichagebiblio->setText (m_biblio.reqBibliographieFormate ().c_str ());
    }

}


/*!
 *
 * \brief Méthode de lien entre l'interface et le code pour supprimer une référence.
 *
 */
void
BibliographieInterface::dialSupReference ()

{

  SuppressionReferenceInterface sup;
  if (sup.exec ())
    {

      supprimerReference  (sup.reqIdentifiant ().toStdString ());
      widget.affichagebiblio->setText (m_biblio.reqBibliographieFormate ().c_str ());
    }

}