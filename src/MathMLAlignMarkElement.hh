// Copyright (C) 2000-2003, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget, or send a mail to
// <luca.padovani@cs.unibo.it>

#ifndef MathMLAlignMarkElement_hh
#define MathMLAlignMarkElement_hh

#include "token.hh"
#include "MathMLElement.hh"

class MathMLAlignMarkElement : public MathMLElement
{
protected:
  MathMLAlignMarkElement(const SmartPtr<class MathMLView>& view);
  virtual ~MathMLAlignMarkElement();

public:
  static SmartPtr<MathMLAlignMarkElement> create(const SmartPtr<class MathMLView>& view)
  { return new MathMLAlignMarkElement(view); }

  virtual void refine(class AbstractRefinementContext&);
#if 0
  virtual void Setup(RenderingEnvironment&);
  virtual void DoLayout(const class FormattingContext&);
#endif

  virtual bool IsSpaceLike(void) const;
#if 0
  virtual void SetDirty(const Rectangle* = NULL);
#endif

  TokenId GetAlignmentEdge(void) const { return edge; }

protected:
  TokenId edge;
};

#endif // MathMLAlignMarkElement_hh
