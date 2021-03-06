// Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
//
// This file is part of GtkMathView, a flexible, high-quality rendering
// engine for MathML documents.
// 
// GtkMathView is free software; you can redistribute it and/or modify it
// either under the terms of the GNU Lesser General Public License version
// 3 as published by the Free Software Foundation (the "LGPL") or, at your
// option, under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation (the "GPL").  If you do not
// alter this notice, a recipient may use your version of this file under
// either the GPL or the LGPL.
//
// GtkMathView is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the LGPL or
// the GPL for more details.
// 
// You should have received a copy of the LGPL and of the GPL along with
// this program in the files COPYING-LGPL-3 and COPYING-GPL-2; if not, see
// <http://www.gnu.org/licenses/>.

#ifndef __MathMLMultiScriptsElement_hh__
#define __MathMLMultiScriptsElement_hh__

#include "MathMLEmbellishment.hh"
#include "MathMLContainerElement.hh"
#include "BinContainerTemplate.hh"
#include "LinearContainerTemplate.hh"

class MathMLMultiScriptsElement
  : public MathMLContainerElement, public MathMLEmbellishment
{
protected:
  MathMLMultiScriptsElement(const SmartPtr<class MathMLNamespaceContext>&);
  virtual ~MathMLMultiScriptsElement();

public:
  static SmartPtr<MathMLMultiScriptsElement> create(const SmartPtr<class MathMLNamespaceContext>& view)
  { return new MathMLMultiScriptsElement(view); }

  unsigned getScriptsSize(void) const { return subScript.getSize(); }
  void setScriptsSize(unsigned size) { subScript.setSize(this, size); }
  unsigned getPreScriptsSize(void) const { return preSubScript.getSize(); }
  void setPreScriptsSize(unsigned size) { preSubScript.setSize(this, size); }
  void setBase(const SmartPtr<MathMLElement>& child) { base.setChild(this, child); }
  void setSubScript(unsigned i, const SmartPtr<MathMLElement>& child) { subScript.setChild(this, i, child); }
  void setSuperScript(unsigned i, const SmartPtr<MathMLElement>& child) { superScript.setChild(this, i, child); }
  void setPreSubScript(unsigned i, const SmartPtr<MathMLElement>& child) { preSubScript.setChild(this, i, child); }
  void setPreSuperScript(unsigned i, const SmartPtr<MathMLElement>& child) { preSuperScript.setChild(this, i, child); }
  SmartPtr<MathMLElement> getBase(void) const { return base.getChild(); }
  SmartPtr<MathMLElement> getSubScript(unsigned i) const { return subScript.getChild(i); }
  SmartPtr<MathMLElement> getSuperScript(unsigned i) const { return superScript.getChild(i); }
  SmartPtr<MathMLElement> getPreSubScript(unsigned i) const { return preSubScript.getChild(i); }
  SmartPtr<MathMLElement> getPreSuperScript(unsigned i) const { return preSuperScript.getChild(i); }

  virtual AreaRef format(class FormattingContext&);

  virtual void setFlagDown(Flags);
  virtual void resetFlagDown(Flags);
  virtual SmartPtr<class MathMLOperatorElement> getCoreOperator(void);

private:
  static void formatScripts(class FormattingContext&,
			    const std::vector<SmartPtr<MathMLElement> >::const_iterator&,
			    const std::vector<SmartPtr<MathMLElement> >::const_iterator&,
			    std::vector<AreaRef>&);

  BinContainerTemplate<MathMLMultiScriptsElement,MathMLElement> base;
  LinearContainerTemplate<MathMLMultiScriptsElement,MathMLElement> subScript;
  LinearContainerTemplate<MathMLMultiScriptsElement,MathMLElement> superScript;
  LinearContainerTemplate<MathMLMultiScriptsElement,MathMLElement> preSubScript;
  LinearContainerTemplate<MathMLMultiScriptsElement,MathMLElement> preSuperScript;

  scaled subShiftX;
  scaled subShiftY;

  scaled superShiftX;
  scaled superShiftY;
};

#endif // __MathMLMultiScriptsElement_hh__
