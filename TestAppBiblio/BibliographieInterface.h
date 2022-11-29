/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   BibliographieInterface.h
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 16:45
 */

#ifndef _BIBLIOGRAPHIEINTERFACE_H
#define _BIBLIOGRAPHIEINTERFACE_H

#include <QWidget>
#include "ui_BibliographieInterface.h"
#include "Bibliographie.h"
#include <vector>
#include <string>

/**
 * \class BibliographieInterface
 * \brief Classe pour la gestion de l'interface d'une bibliographie.
 */
class BibliographieInterface : public QMainWindow
{
  Q_OBJECT
public:
  BibliographieInterface (QWidget *parent = 0);
  virtual ~BibliographieInterface ();

  void ajouterJournal (const std::string& p_auteurs,
                       const std::string& p_titre,
                       int p_annee,
                       const std::string& p_id,
                       const std::string& p_nom,
                       int p_volume,
                       int p_numero,
                       int p_page);

  void ajouterOuvrage (const std::string& p_auteurs,
                       const std::string& p_titre,
                       int p_annee,
                       const std::string& p_id,
                       const std::string& p_editeur,
                       const std::string& p_ville);

  void supprimerReference (const std::string& p_id);


  std::string reqBiblioFormate ()const;



private slots:
  void dialAjoutJournal ();
  void dialAjoutOuvrage ();
  void dialSupReference ();


private:
  Ui::BibliographieInterface widget;
  biblio::Bibliographie m_biblio;

};


#endif /* _BIBLIOGRAPHIEINTERFACE_H */
