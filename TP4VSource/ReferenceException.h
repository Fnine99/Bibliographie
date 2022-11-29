/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ReferenceException.h
 * Author: Pierre-Michel et Franck
 *
 * Created on 9 juillet 2022, 15:54
 */

#ifndef REFERENCEEXCEPTION_H
#define REFERENCEEXCEPTION_H

#include <string>
#include <stdexcept>

/*!
 * \class ReferenceEsception  - gere les erreurs de runtime des Ref.
 * \brief Classe principale de la hierarchie des classes de RefException
 */
class ReferenceException : public std::runtime_error
{
public:
  ReferenceException (const std::string& p_raison);

private:
  std::string p_raison;
};

/*!
 * \class ReferenceDejaPresenteException - Gere l'ajout de doublon
 * \brief Classe héritant de la classe ReferenceExeption.
 */

class ReferenceDejaPresenteException : public ReferenceException
{
public:
  ReferenceDejaPresenteException (const std::string& p_raison);

};

/*!
 * \class ReferenceAbsenteException - Gere l'abscence de doublon
 * \brief Classe héritant de la classe ReferenceExeption.
 */
class ReferenceAbsenteException : public ReferenceException
{
public:
  ReferenceAbsenteException (const std::string& p_raison);

};

#endif /* REFERENCEEXCEPTION_H */

