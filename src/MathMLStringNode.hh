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

#ifndef MathMLStringNode_hh
#define MathMLStringNode_hh

#include "Area.hh"
#include "MathMLTextNode.hh"

class MathMLStringNode: public MathMLTextNode
{
protected:
  MathMLStringNode(const String&);
  virtual ~MathMLStringNode();

public:
  static SmartPtr<MathMLStringNode> create(const String& s)
  { return new MathMLStringNode(s); }

  virtual AreaRef  format(class MathFormattingContext&);
#if 0
  virtual void     Setup(class RenderingEnvironment&);
  virtual void     DoLayout(const class FormattingContext&);
  virtual void     Render(const DrawingArea&);
#endif

  virtual bool     HasDecimalPoint(void) const;
  virtual bool     IsString(void) const;

#if 0
  virtual scaled   GetDecimalPointEdge(void) const;
#endif

  virtual unsigned GetLogicalContentLength(void) const;
  virtual String   GetRawContent(void) const;

  static unsigned visited;

private:
  String content;
  AreaRef area;
};

#endif // MathMLStringNode_hh
