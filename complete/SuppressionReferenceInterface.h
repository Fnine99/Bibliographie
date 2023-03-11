/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   SuppressionReferenceInterface.h
 * Author: etudiant
 *
 * Created on 11 juillet 2022, 20:51
 */

#ifndef _SUPPRESSIONREFERENCEINTERFACE_H
#define _SUPPRESSIONREFERENCEINTERFACE_H

#include "ui_SuppressionReferenceInterface.h"

/**
 * \class SuppressionReferenceInterface
 * \brief Classe pour la gestion de l'interface de supression de reference.
 */
class SuppressionReferenceInterface : public QDialog
{
  Q_OBJECT
public:
  SuppressionReferenceInterface (QWidget *parent = 0);
  virtual ~SuppressionReferenceInterface ();

  QString reqIdentifiant () const;


private slots:
  void confirmationDonnees ();


private:
  Ui::SuppressionReferenceInterface widget;
};

#endif /* _SUPPRESSIONREFERENCEINTERFACE_H */
