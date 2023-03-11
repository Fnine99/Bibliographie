/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ouvrage.h"

using namespace std;
using namespace util;
using namespace biblio;


/**
 * \brief Constructeur, construit un objet avec
 * @param p_auteurs
 * @param p_titre
 * @param p_annee
 * @param p_id
 * @param p_editeur
 * @param p_ville
 */


Ouvrage::Ouvrage (const string& p_auteurs,
                  const string& p_titre,
                  int p_annee,
                  const string& p_id,
                  const string p_editeur,
                  const string p_ville) : biblio::Reference (p_auteurs, p_titre, p_annee, p_id),
m_editeur (p_editeur), m_ville (p_ville)
{
  PRECONDITION (util::validerFormatNom (p_editeur));
  PRECONDITION (util::validerFormatNom (p_ville));

  POSTCONDITION (m_editeur == p_editeur);
  POSTCONDITION (m_ville == p_ville);

  INVARIANTS ();
  //  valider format nom p_editeur
  //  validier format nom ville

  //  PRECOND
  //  POSTCOND
  //  INVARIANTS
}


/*!
 *
 * \brief L'accesseur de l'attribut m_editeur.
 * \return La valeur de m_editeur.
 */
const string&
Ouvrage::reqEditeur () const
{
  return m_editeur;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_ville.
 * \return La valeur de m_ville.
 */
const string&
Ouvrage::reqVille () const
{
  return m_ville;
}


/**
 * \brief Méthode de formatage des informations de l'ouvrage.
 * @return L'objet string formaté.
 */
string
Ouvrage::reqReferenceFormate () const
{
  ostringstream oss;
  oss << Reference::reqReferenceFormate () << m_ville << " : "
          << m_editeur << ", " << m_annee  << ". " << m_id << "." << endl;
  return oss.str ();
}


/**
 * \brief Méthode pour faire une copie allouée sur le monceau de l'objet courant.
 * @return Clone de l'objet Ouvrage courant.
 */
Reference*
Ouvrage::clone () const
{
  return new Ouvrage (*this);
}


/**
 * \brief Méthode de vérification des invariants pour assurer la validité de la classe.
 *
 */
void
Ouvrage::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (m_editeur));
  INVARIANT (util::validerFormatNom (m_ville));
}

