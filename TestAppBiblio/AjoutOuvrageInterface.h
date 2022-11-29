/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutOuvrageInterface.h
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 19:36
 */

#ifndef _AJOUTOUVRAGEINTERFACE_H
#define _AJOUTOUVRAGEINTERFACE_H

#include "ui_AjoutOuvrageInterface.h"

/**
 * \class AjoutOuvrageInterface
 * \brief Classe pour la gestion de l'interface d'ajout d'ouvrage.
 */
class AjoutOuvrageInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutOuvrageInterface (QWidget *parent = 0);
  virtual ~AjoutOuvrageInterface ();

  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqEditeur () const;
  QString reqVille () const;

private slots:
  void confirmationDonnees ();


private:
  Ui::AjoutOuvrageInterface widget;
};

#endif /* _AJOUTOUVRAGEINTERFACE_H */
