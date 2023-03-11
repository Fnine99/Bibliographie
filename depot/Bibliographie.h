/*
 * File:   Bibliographie.h
 * Author: etudiant
 *
 * Created on 24 juin 2022, 22:20
 */

#ifndef BIBLIOGRAPHIE_H
#define BIBLIOGRAPHIE_H

#include <vector>

#include "Reference.h"
#include "Ouvrage.h"
#include "Journal.h"

/* J'ai copié-collé mon fichier Biblio.h pour pouvoir continuer en implantant
 * la théorie du contrat. Modifie et améliore à ta guise.  */

#include "ReferenceException.h"


namespace biblio
{

  /**
   * \class Bibliographie
   * \brief Classe pour la gestion de bibliographies.
   */
  class Bibliographie
  {
  public:
    Bibliographie (const std::string& p_nomBiblio);

    ~Bibliographie ();


    const std::string& reqNomBiblio () const;

    void ajouterReference (const Reference& p_nouvelleReference);

    void supprimerReference (const std::string& p_identifiant);

    std::string reqBibliographieFormate () const;

    int comptageReference () const;


  private:
    std::string m_nomBiblio;
    std::vector<Reference*> m_vReferences;

    bool referenceEstDejaPresente (const Reference& p_reference) const;

    Bibliographie (const biblio::Bibliographie&);
    const Bibliographie& operator= (const Bibliographie& p_biblio);

    /* ajout */
    void verifieInvariant () const;

  };
}



#endif /* BIBLIOGRAPHIE_H */
