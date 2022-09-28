/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Bibliographie.cpp
 * Author: etudiant
 *
 * Created on 7 juillet 2022, 14:10
 */

#include "Bibliographie.h"

using namespace std;
using namespace biblio;


/**
 * \brief Constructeur de la classe Bibliographie
 * @param p_nomBiblio
 */

Bibliographie::Bibliographie (const string& p_nomBiblio) : m_nomBiblio (p_nomBiblio)
{
  PRECONDITION (!(p_nomBiblio.empty ()));

  POSTCONDITION (m_nomBiblio == p_nomBiblio);
  INVARIANTS ();
}


/**
 * \brief Destructeur :Iterateur qui supp. chaque pointeurs dans m_vRef (STL)
 */
Bibliographie::~Bibliographie ()
{
  vector<Reference*>::iterator iterVector;
  for (iterVector = m_vReferences.begin (); iterVector < m_vReferences.end (); iterVector++)
    {
      delete *iterVector;
    }
}


/*!
 *
 * \brief L'accesseur de l'attribut m_NomBiblio.
 * \return La valeur de m_NomBiblio.
 */
const string&
Bibliographie::reqNomBiblio () const
{
  return m_nomBiblio;
}


/*!
 *
 * \brief Méthode de formatage du contenu de la bibliographie.
 *
 */
string
Bibliographie::reqBibliographieFormate () const
{
  int i = 0;
  ostringstream oss;
  oss << reqNomBiblio () << "\n===============================" << endl;

  vector<Reference*>::const_iterator vRefIter;
  for (vRefIter = m_vReferences.begin (); vRefIter < m_vReferences.end (); vRefIter++)
    {
      oss << "[" << i + 1 << "] – " << (*vRefIter) ->reqReferenceFormate () << endl;
      i++;
    }
  return oss.str ();
}


/*!
 *
 * \brief Méthode pour confirmer la présence d'une référence dans la bibliographie.
 * \param p_reference - Objet de type Journal ou Ouvrage correspondant à la référence bibliographique.
 * \return Un boléen.
 */
bool
Bibliographie::referenceEstDejaPresente (const Reference& p_reference) const
{

  vector<Reference*>::const_iterator vRefIter;
  for (vRefIter = m_vReferences.begin (); vRefIter < m_vReferences.end (); vRefIter++)
    {


      if ((*(*vRefIter)).reqIdentifiant () == p_reference.reqIdentifiant ())
        return true;
    }
  return false;
}


/*!
 *
 * \brief Méthode (extra) retournant le nombre de références présentes dans la bibliographie.
 *
 * \return L'entier du nombre de référence.
 */
int
Bibliographie::comptageReference () const
{
  int compte = 0;
  vector<Reference*>::const_iterator vRefIter;
  for (vRefIter = m_vReferences.begin (); vRefIter < m_vReferences.end (); vRefIter++)
    {
      compte++;
    }

  return compte;

}


/*!
 *
 * \brief Méthode permettant d'ajouter une référence a la bibliographie.
 * \param p_reference - Objet de type Journal ou Ouvrage correspondant à la référence bibliographique.
 *
 */
void
Bibliographie::ajouterReference (const Reference& p_reference)
{
  if (!(referenceEstDejaPresente (p_reference)))
    {
      m_vReferences.push_back (p_reference.clone ());
    }
  else
    {

      throw ReferenceDejaPresenteException
              (p_reference.reqReferenceFormate ());
    }

  POSTCONDITION (referenceEstDejaPresente (p_reference));
  INVARIANTS ();
}


/*!
 *
 * \brief Méthode permettant de supprimer une référence de la bibliographie a partir de son identifiant.
 * \param p_identifiant - Objet string correspondant a un identifiant (ISSN ou ISBN).
 *
 */
void
Bibliographie::supprimerReference (const string& p_identifiant)
{


  vector<Reference*>::iterator vRefIter;
  for (vRefIter = m_vReferences.begin (); vRefIter < m_vReferences.end (); vRefIter++)
    {

      if ((*vRefIter)->reqIdentifiant () == p_identifiant)
        {
          delete (*vRefIter);
          vRefIter = m_vReferences.erase (vRefIter);
          return;
        }
    }

  throw ReferenceAbsenteException
          ("Cette référence n'existe pas");

}


/**
 * \brief Méthode de vérification des invariants pour assurer la validité de la classe.
 *
 */
void
Bibliographie::verifieInvariant () const
{

  INVARIANT (!(m_nomBiblio.empty ()));
}