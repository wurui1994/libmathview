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

#include <config.h>

#include <cassert>

#include "MathMLTextNode.hh"
#include "MathMLElement.hh"

// A MathMLTextNode is used to represent an UNBREAKABLE chunk of
// text and/or space. This means that TextNode is an Atom.
// The breakability of the chunk is somehow determined by the
// node content

MathMLTextNode::MathMLTextNode()
{
  SetSpacing(0);
}

MathMLTextNode::~MathMLTextNode()
{
}

bool
MathMLTextNode::IsText() const
{
  return true;
}

#if 0
void
MathMLTextNode::SetPosition(const scaled& x, const scaled& y)
{
  position.x = x;
  position.y = y;
}
#endif

void
MathMLTextNode::SetSpacing(int s)
{
  spacing = s;
}

void
MathMLTextNode::AddSpacing(int ds)
{
  spacing += ds;
}

#if 0
bool
MathMLTextNode::IsInside(const scaled& x, const scaled& y) const
{
  return
    x >= position.x &&
    y >= position.y - box.height &&
    x <= position.x + box.width &&
    y <= position.y + box.depth;
}

scaled
MathMLTextNode::GetLeftEdge() const
{
  return GetX();
}

scaled
MathMLTextNode::GetRightEdge() const
{
  return GetX() + box.width;
}
#endif

bool
MathMLTextNode::HasDecimalPoint() const
{
  return false;
}

#if 0
scaled
MathMLTextNode::GetDecimalPointEdge() const
{
  return 0;
}
#endif