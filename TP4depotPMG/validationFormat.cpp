/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   validationFormat.cpp
 * Author: etudiant
 *
 * Created on 8 juillet 2022, 03:55
 */

#include "validationFormat.h"
#include <sstream>
using namespace std;


/**
 * \fn validerFormatNom
 * \brief Le validateur du format d'un nom.
 * \param p_nom - Objet string correspondant au nom a un nom.
 * \return Un boléen.
 */
bool
util::validerFormatNom (const std::string& p_nom)
{
  bool valide = true;
  int compteur = 0;
  for (unsigned i = 0; i < p_nom.size (); ++i)
    {
      if (p_nom[i] == ' '  || p_nom[i] == '-')
        {
          compteur++;
        }
      else
        {
          compteur = 0;
        }
      if ((!isalpha (p_nom[i]) && p_nom[i] != ' ' && p_nom[i] != '-' ) || compteur > 1)
        {


          valide = false;
        }
    }
  return valide;
}


/**
 * \fn validerCodeIssn
 * \brief Le validateur d'un code ISSN.
 * \param p_issn - Objet string correspondant a un code ISSN.
 * \return Un boléen.
 */
bool
util::validerCodeIssn (const std::string& p_issn)
{
  bool valide = false;
  int somme = 0;
  int multiplicateur = 8;

  if (p_issn.compare (0, 5, "ISSN ") == 0)
    {
      if (p_issn.length () == 14 && p_issn[9] == '-')
        {
          bool chiffre = true;
          for (unsigned int i = 5; i < p_issn.length () - 1; i++)
            {
              if (i == 9)
                {
                  i++;
                }

              if (isdigit (p_issn[i]))
                {
                  somme += (p_issn[i] - '0') * multiplicateur;
                  multiplicateur--;
                }
              else
                {
                  chiffre = false;

                }
            }
          if ((11 - somme % 11 == p_issn[13] - '0') && chiffre)
            {
              valide = true;
            }
        }
    }
  return valide;
}


/**
 * \fn validerCodeIsbn
 * \brief Le validateur d'un code ISBN.
 * \param p_isbn - Objet string correspondant a un code ISBN.
 * \return Un boléen.
 */
bool
util::validerCodeIsbn (const std::string& p_isbn)
{
  bool valide = false;
  istringstream is_isbn (p_isbn);
  //le code doit commencer par ISBN
  string prefixe;  // = p_isbn.substr(0, 5);
  char buffer[256];
  is_isbn.getline (buffer, 256, ' ');
  prefixe = buffer;
  if (prefixe == "ISBN")
    {
      string code_isbn;
      //ISBN-13
      if (p_isbn.size () == 5 + 13 + 4)
        {
          char buffer[256];
          //Bookland
          is_isbn.getline (buffer, 255, '-');
          code_isbn = buffer;
          if (code_isbn == "978" || code_isbn == "979")
            {
              //              cout << "pays valide" << endl;
              //groupe A
              is_isbn.getline (buffer, 255, '-');
              string domaine = buffer;
              int codeDomaine = atoi (domaine.c_str ());
              if ((codeDomaine >= 0 && codeDomaine <= 5) || codeDomaine == 7 || (codeDomaine >= 600 && codeDomaine <= 649) || (codeDomaine >= 80 && codeDomaine <= 94) || (codeDomaine >= 950 && codeDomaine <= 989) || (codeDomaine >= 9900 && codeDomaine <= 9989) || (codeDomaine >= 99900 && codeDomaine <= 99999))
                //    0-5, 7
                //    600-649
                //    80-94
                //    950-989
                //    9900-9989
                //    99900-99999
                {
                  //                  cout << "domaine valide" << endl;
                  code_isbn += domaine;
                  //groupe B
                  is_isbn.getline (buffer, 255, '-');
                  string editeur = buffer;
                  int numeroEditeur = atoi (editeur.c_str ());

                  if ((numeroEditeur >= 0 && numeroEditeur <= 19 ) || (numeroEditeur >= 200 && numeroEditeur <= 699) || ( numeroEditeur >= 7000 && numeroEditeur <= 8499 ) || (numeroEditeur >= 85000 && numeroEditeur <= 89999) || (numeroEditeur >= 900000 && numeroEditeur <= 949999) || (numeroEditeur >= 9500000 && numeroEditeur <= 9999999))
                    {
                      //00 - 19
                      //    200 - 699
                      //    7000 - 8499
                      //    85000 - 89999
                      //    900000 - 949999
                      //    9500000 - 9999999
                      //                      cout << "editeur valide" << endl;

                      code_isbn += editeur;
                      //groupe C
                      is_isbn.getline (buffer, 255, '-');
                      code_isbn += buffer;
                      //groupe D
                      string cle_str;
                      is_isbn >> cle_str;
                      code_isbn += cle_str;
                      //Validation du code ISBN-13 à partir de la clé de vérification
                      //                      cout << code_isbn << endl;
                      int sommeProduits = 0;
                      for (unsigned int position = 0; position < 12; position++)
                        {
                          sommeProduits += ((position % 2 == 0) ? 1 : 3)
                                  * (code_isbn[position] - '0');
                        }

                      //ajout de la clé de contôle
                      sommeProduits += (code_isbn[12] - '0');

                      //La somme de produits doit être un multiple de 10
                      if (sommeProduits % 10 == 0)
                        {
                          valide = true;
                        }
                    }
                }
            }
        }
    }
  //A : Code ISBN est valide : retourne vrai false sinon
  return valide;
}
