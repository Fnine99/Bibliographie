/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AjoutJournalInterface.h
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 16:30
 */

#ifndef _AJOUTJOURNALINTERFACE_H
#define _AJOUTJOURNALINTERFACE_H

#include "ui_AjoutJournalInterface.h"

/**
 * \class AjoutJournalInterface
 * \brief Classe pour la gestion de l'interface d'ajout de journal.
 */
class AjoutJournalInterface : public QDialog
{
  Q_OBJECT
public:
  AjoutJournalInterface (QWidget *parent = 0);
  virtual ~AjoutJournalInterface ();

  QString reqAuteurs () const;
  QString reqTitre () const;
  int reqAnnee () const;
  QString reqIdentifiant () const;
  QString reqNom () const;
  int reqVolume () const;
  int reqNumero () const;
  int reqPage () const;

private slots:
  void confirmationDonnees ();






private:
  Ui::AjoutJournalInterface widget;
};

#endif /* _AJOUTJOURNALINTERFACE_H */
