/**
 * \file Reference.cpp
 * \brief
 */

#include "Reference.h"


using namespace std;
using namespace util;

/**
 * \brief Constucteur de Reference qui initialise les parametres avec les valeurs passees; initialise sous condition
 * \@param p_auteurs; nom de l´auteur (string)
 * \@param titre; nom de l´ouvrage (string)
 * \@param p_annee; anneee d´edition (int)
 * \@param p_id; identifiant de l´ouvrage (string)
 */
using namespace biblio;
//{


Reference::Reference (const string& p_auteurs,
                      const string& p_titre,
                      int p_annee,
                      const string& p_id) :
m_auteurs (p_auteurs),
m_titre (p_titre),
m_annee (p_annee),
m_id (p_id)
{
  PRECONDITION (util::validerFormatNom (p_auteurs));
  PRECONDITION (!(p_titre.empty ()));
  PRECONDITION (p_annee > 0);
  PRECONDITION (util::validerCodeIsbn (p_id) || util::validerCodeIssn (p_id));

  //  if (util::validerFormatNom (p_auteurs) && (!(p_titre.empty ()) && (p_annee > 0) &&
  //                                             (util::validerCodeIssn (p_id) || util::validerCodeIsbn (p_id))))
  //    {
  //      m_auteurs = p_auteurs;
  //      m_titre = p_titre;
  //      m_annee = p_annee;
  //      m_identifiant = p_id;
  //    }
  //  else cout << "Les parametres n´ont pu etre initialises " << endl;

  POSTCONDITION (m_auteurs == p_auteurs);
  POSTCONDITION (m_titre == p_titre);
  POSTCONDITION (m_annee == p_annee);
  POSTCONDITION (m_id == p_id);

  INVARIANTS ();

}


/*!
 *
 * \brief L'accesseur de l'attribut m_auteurs.
 * \return La valeur de m_auteurs.
 */
const string&
Reference::reqAuteurs () const
{
  return m_auteurs;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_titre.
 * \return La valeur de m_titre.
 */
const string&
Reference::reqTitre () const
{
  return m_titre;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_annee.
 * \return La valeur de m_annee.
 */
int
Reference::reqAnnee () const
{
  return m_annee;
}


/*!
 *
 * \brief L'accesseur de l'attribut m_id.
 * \return La valeur de m_id.
 */
const string&
Reference::reqIdentifiant () const
{
  return m_id;
}


/**
 * \brief Mutateur de l'attribut m_année.
 * @param nouvelleAnnee Nouvelle année passée en parametre.
 */
void
Reference::editeAnnee (int nouvelleAnnee)
{
  PRECONDITION (nouvelleAnnee > 0);
  {
    m_annee = nouvelleAnnee;
  }
  POSTCONDITION (m_annee == nouvelleAnnee);
  INVARIANTS ();
}


/**
 * \brief Opérateur qui détermine si deux objets Reference sont égaux en comparant leur attributs.
 * @param p_reference Pointeur d'un objet Reference.
 * @return bool
 */
bool Reference::operator== (const Reference* p_reference) const
{
  return ((p_reference-> m_auteurs == m_auteurs) && (p_reference-> m_titre == m_titre) &&
          (p_reference-> m_id == m_id) &&(p_reference->m_annee == m_annee));
}


/**
 * \brief Méthode de formatage des informations de la référence.
 * @return string
 */
string
Reference::reqReferenceFormate () const
{
  ostringstream oss;
  oss << m_auteurs << ". " << m_titre << "." << endl;
  return oss.str ();
}


/**
 * \brief Méthode de vérification des invariants pour assurer la validité de la classe.
 *
 */
void
Reference::verifieInvariant () const
{
  INVARIANT (util::validerFormatNom (m_auteurs));
  INVARIANT (!(m_titre.empty ()));
  INVARIANT (m_annee > 0);
  INVARIANT (util::validerCodeIsbn (m_id) || util::validerCodeIssn (m_id));

}

//}  /* namespace biblio */