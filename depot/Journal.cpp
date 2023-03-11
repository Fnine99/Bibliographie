/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Journal.h"

using namespace std;
using namespace util;
using namespace biblio;


/**
 * \brief Constructeur de la classe Journal.
 * @param p_auteurs
 * @param p_titre
 * @param p_annee
 * @param p_id
 * @param p_nom
 * @param p_volume
 * @param p_numero
 * @param p_page
 */
Journal::Journal (const string& p_auteurs,
                  const string& p_titre,
                  int p_annee,
                  const string& p_id,
                  const string p_nom,
                  int p_volume,
                  int p_numero,
                  int p_page
                  ) : biblio::Reference (p_auteurs, p_titre, p_annee, p_id),
m_nom (p_nom), m_volume (p_volume), m_numero (p_numero), m_page (p_page)
{


  PRECONDITION (!(p_nom.empty ()));
  PRECONDITION (p_volume > 0);
  PRECONDITION (p_numero > 0);
  PRECONDITION (p_page > 0);

  POSTCONDITION (m_nom == p_nom);
  POSTCONDITION (m_volume == p_volume);
  POSTCONDITION (m_numero == p_numero);
  POSTCONDITION (m_page == p_page);

  INVARIANTS ();

}


/*!
 *
 * \brief L'accesseur de l'attribut m_nom.
 * \return La valeur de m_nom.
 */
const string&
Journal::reqNom () const
{
  return m_nom;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_volume.
 * \return La valeur de m_volume.
 */
int
Journal::reqVolume () const
{
  return m_volume;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_numero.
 * \return La valeur de m_numero.
 */
int
Journal::reqNumero () const
{
  return m_numero;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_page.
 * \return La valeur de m_page.
 */
int
Journal::reqPage () const
{
  return m_page;
}


/**
 * \brief Méthode de formatage des informations du journal.
 * @return L'objet string formaté.
 */

string
Journal::reqReferenceFormate () const
{
  ostringstream oss;
  oss << m_nom << ", " << "vol. " << m_volume << ", no. " << m_numero << ", pp. "
          << m_page << ", " << m_annee  << ". " << m_id << "." << endl;
  return oss.str ();
}


/**
 * \brief Méthode pour faire une copie allouée sur le monceau de l'objet courant.
 * @return Clone de l'objet Journal courant.
 */
Reference*
Journal::clone () const
{
  return new Journal (*this);
}


/**
 * \brief Méthode de vérification des invariants pour assurer la validité de la classe.
 *
 */
void
Journal::verifieInvariant ()
{
  INVARIANT (!(m_nom.empty ()));
  INVARIANT (m_volume > 0);
  INVARIANT (m_numero > 0);
  INVARIANT (m_page > 0);
}



