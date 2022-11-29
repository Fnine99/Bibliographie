/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Ouvrage.h
 * Author: etudiant
 *
 * Created on 24 juin 2022, 21:17
 */

#ifndef OUVRAGE_H
#define OUVRAGE_H

#include "Reference.h"


namespace biblio
{

  /* \class Ouvrage - creer un objet de type ouvrage
   * \brief Classe héritant de la classe Reference.
   */
  class Ouvrage : public biblio::Reference
  {
  public:

    Ouvrage (const std::string& p_auteurs,
             const std::string& p_titre,
             int p_annee,
             const std::string& p_id,
             const std::string p_editeur,
             const std::string p_ville
             );

    const std::string& reqEditeur () const;

    const std::string& reqVille () const;

    virtual std::string reqReferenceFormate () const;

    virtual Reference*
    clone () const;

  private:
    std::string m_editeur;
    std::string m_ville;
    void verifieInvariant () const;

  };
}




#endif /* OUVRAGE_H */

