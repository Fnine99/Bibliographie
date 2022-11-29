/*
 * File:   Journal.h
 * Author: etudiant
 *
 * Created on 24 juin 2022, 21:18
 */

#ifndef JOURNAL_H
#define JOURNAL_H


#include "Reference.h"

namespace biblio
{

  /*
   * \class Journal - Creer un objet de type journal
   * \brief Classe dérivée de la classe Reference.
   */
  class Journal : public biblio::Reference
  {
  public:

    Journal (const std::string& p_auteurs,
             const std::string& p_titre,
             int p_annee,
             const std::string& p_id,
             const std::string p_nom,
             int p_volume,
             int p_numero,
             int p_page
             );


    const std::string& reqNom () const;

    int reqVolume () const;

    int reqNumero () const;

    int reqPage () const;

    virtual Reference*
    clone () const;

    virtual std::string reqReferenceFormate () const;

  private:
    std::string m_nom;
    int m_volume;
    int m_numero;
    int m_page;
    void verifieInvariant ();

  };
}







#endif /* JOURNAL_H */

