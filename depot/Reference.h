/**
 * \file Reference.h
 * \brief
 */

#ifndef REFERENCE_H
#define REFERENCE_H

#include <string>
#include <iostream>
#include <sstream>

#include "validationFormat.h"
#include "ContratException.h"

/*namespace*/


/**
 * \class Reference
 * \brief Classe de base
 */
namespace biblio
{

  class Reference
  {
  public:

    Reference (const std::string& p_auteurs,
               const std::string& p_titre,
               int p_annee,
               const std::string& p_id);

    virtual
    ~Reference () { };

    const std::string& reqAuteurs () const;

    const std::string& reqTitre () const;

    int reqAnnee () const;

    const std::string& reqIdentifiant () const;

    void editeAnnee (int nouvelleAnnee);

    virtual std::string reqReferenceFormate () const = 0;

    virtual Reference* clone () const = 0;

    bool operator== (const Reference* p_reference) const;

  protected:

    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_id;


  private:

    void verifieInvariant () const;

  };

}


#endif /* REFERENCE_H */

