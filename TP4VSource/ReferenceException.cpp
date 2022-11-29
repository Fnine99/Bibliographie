/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ReferenceException.h"
#include <sstream>

using namespace std;


/**
 * \brief Constructeur de la classe ReferenceException.
 * @param p_raison - cause de l'erreur
 */
ReferenceException::ReferenceException (const string& p_raison) :
runtime_error (p_raison) { }


/**
 * \brief Constructeur de la classe ReferenceDejaPresenteException.
 * @param p_raison - cause de l'erreur
 */
ReferenceDejaPresenteException::ReferenceDejaPresenteException (const string& p_raison) :
ReferenceException (p_raison) { }


/**
 * \brief Constructeur de la classe ReferenceAbsenteException.
 * @param p_raison - cause de l'erreur
 */
ReferenceAbsenteException::ReferenceAbsenteException (const string& p_raison) :
ReferenceException (p_raison) { }
