/**
 * \file BibliographieTesteur.cpp
 */


#include "Bibliographie.h"
#include "ContratException.h"

using namespace std;
using namespace biblio;


/**
 * \brief Test du Constructeur de la classe Bibliographie : Nom valide
 */
TEST (Bibliographie, ConstructeurValide)
{
  Bibliographie Testeur ("Une Bibliographie");
  ASSERT_EQ ("Une Bibliographie", Testeur.reqNomBiblio ());
}


/**
 * \brief Test du Constructeur de la classe Bibliographie : Nom invalide
 */
TEST (Bibliographie, ConstructeurInvalide)
{
  ASSERT_THROW (Bibliographie Testeur (""), PreconditionException);
}


/**
 * \brief Test d'ajout d'un ouvrage.
 */
TEST (Bibliographie, ajoutReference)
{
  Bibliographie Testeur ("Une Bibliographie");
  Ouvrage OuvrageTest (	"Homayoon Beigi",
                       "Fundamentals of Speaker Recognition",
                       2011,
                       "ISBN 978-0-387-77591-3",
                       "New York",
                       "Springer");

  Testeur.ajouterReference (OuvrageTest);

}


/**
 * \brief Test d'ajout de multiples références(2) a l'aide de la méthode extra.
 */
TEST (Bibliographie, ajout2References)
{
  Bibliographie Testeur ("Deux Bibliographies");
  Ouvrage OuvrageTest (	"Homayoon Beigi",
                       "Fundamentals of Speaker Recognition",
                       2011,
                       "ISBN 978-0-387-77591-3",
                       "New York",
                       "Springer");
  Journal JournalTest (	"Hart",
                       "A survey of source code management tools for programming courses",
                       2009,
                       "ISSN 1937-4771",
                       "Journal of Computing Sciences in Colleges",
                       24,
                       6,
                       113);

  Testeur.ajouterReference (OuvrageTest);
  Testeur.ajouterReference (JournalTest);

  ASSERT_EQ (2, Testeur.comptageReference ());

}


/**
 * \brief Test de formatage de la bibliographie
 */
TEST (Bibliographie, reqBibliographieFormate)
{
  ostringstream oss;
  Bibliographie Testeur ("Une Bibliographie");
  Ouvrage OuvrageTest (	"Homayoon Beigi",
                       "Fundamentals of Speaker Recognition",
                       2011,
                       "ISBN 978-0-387-77591-3",
                       "New York",
                       "Springer");
  Testeur.ajouterReference (OuvrageTest);
  oss << "Une Bibliographie" << endl;
  oss << "===============================" << endl;
  oss << "[" << 1 << "] – " << OuvrageTest.reqReferenceFormate () << endl;
  ASSERT_EQ (oss.str (), Testeur.reqBibliographieFormate ());

}


/**
 * \brief Test d'ajout d'une référence deja existante
 */
TEST (Bibliographie, ajoutReferenceExistante)
{
  Bibliographie Testeur ("Une Bibliographie");
  Ouvrage OuvrageTesteur (	"Homayoon Beigi",
                          "Fundamentals of Speaker Recognition",
                          2011,
                          "ISBN 978-0-387-77591-3",
                          "New York",
                          "Springer");
  Testeur.ajouterReference (OuvrageTesteur);

  Ouvrage OuvrageTesteur2 (	"Homayoon Beigi",
                           "Fundamentals of Speaker Recognition",
                           2011,
                           "ISBN 978-0-387-77591-3",
                           "New York",
                           "Springer");


  EXPECT_THROW (Testeur.ajouterReference (OuvrageTesteur2), ReferenceDejaPresenteException);
}






