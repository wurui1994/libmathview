// Copyright (C) 2000, Luca Padovani <luca.padovani@cs.unibo.it>.
// 
// This file is part of GtkMathView, a Gtk widget for MathML.
// 
// GtkMathView is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
// 
// GtkMathView is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GtkMathView; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
// 
// For details, see the GtkMathView World-Wide-Web page,
// http://cs.unibo.it/~lpadovan/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#ifndef OperatorDictionary_hh
#define OperatorDictionary_hh

#include <vector>

#include "SmartPtr.hh"
#include "String.hh"
#include "HashMap.hh"

class OperatorDictionary
{
public:
  OperatorDictionary(void);
  ~OperatorDictionary();

  bool Load(const char*);
  void Unload(void);
  void Search(const String&,
	      SmartPtr<class MathMLAttributeList>&,
	      SmartPtr<class MathMLAttributeList>&,
	      SmartPtr<class MathMLAttributeList>&) const;

private:
  struct FormDefaults
  {
    SmartPtr<class MathMLAttributeList> prefix;
    SmartPtr<class MathMLAttributeList> infix;
    SmartPtr<class MathMLAttributeList> postfix;
  };

  typedef HASH_MAP_NS::hash_map<String,FormDefaults,StringHash,StringEq> Dictionary;
  Dictionary items;
};

#endif // OperatorDictionary_hh
