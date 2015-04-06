/****************************************************************************
 *   Copyright (C) 2015 by Savoir-Faire Linux                               *
 *   Author : Emmanuel Lepage Vallee <emmanuel.lepage@savoirfairelinux.com> *
 *                                                                          *
 *   This library is free software; you can redistribute it and/or          *
 *   modify it under the terms of the GNU Lesser General Public             *
 *   License as published by the Free Software Foundation; either           *
 *   version 2.1 of the License, or (at your option) any later version.     *
 *                                                                          *
 *   This library is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 *   Lesser General Public License for more details.                        *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/
#ifndef SECURITYVALIDATIONMODELPRIVATE_H
#define SECURITYVALIDATIONMODELPRIVATE_H

class SecurityFlaw;
class Account;
class Certificate;

class SecurityValidationModelPrivate
{
public:
   SecurityValidationModelPrivate(Account* account, SecurityValidationModel* parent);

   //Attributes
   QList<SecurityFlaw*>  m_lCurrentFlaws       ;
   SecurityValidationModel::SecurityLevel m_CurrentSecurityLevel;
   Account*      m_pAccount            ;
   QHash< int, QHash< int, SecurityFlaw* > > m_hFlaws;
   Certificate* m_pCa;
   Certificate* m_pCert;
   Certificate* m_pPrivateKey;

   //Mutator
   void update();

   ///Messages to show to the end user
   static const QString messages[enum_class_size<SecurityValidationModel::AccountSecurityFlaw>()];

   //Static mapping
   static const TypedStateMachine< SecurityValidationModel::SecurityLevel , SecurityValidationModel::AccountSecurityFlaw > maximumSecurityLevel;
   static const TypedStateMachine< SecurityValidationModel::Severity      , SecurityValidationModel::AccountSecurityFlaw > flawSeverity        ;

   SecurityValidationModel* q_ptr;
};

#endif