// Copyright (C) 2001, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://cs.unibo.it/helm/mml-widget/, or send a mail to
// <luca.padovani@cs.unibo.it>

#include <config.h>
#include <assert.h>

#include "unidefs.h"
#include "Globals.hh"
#include "CharMapper.hh"
#include "MathMLElement.hh"
#include "MathMLHorizBarNode.hh"
#include "RenderingEnvironment.hh"

MathMLHorizBarNode::MathMLHorizBarNode(Char c) : MathMLCharNode(c)
{
  assert(c == U_OVERLINE || c == U_UNDERLINE || c == U_HORIZBAR);
  thickness = 0;
}

MathMLHorizBarNode::~MathMLHorizBarNode()
{
}

void
MathMLHorizBarNode::Setup(RenderingEnvironment& env)
{
  thickness = env.GetRuleThickness();
}

void
MathMLHorizBarNode::DoLayout(const FormattingContext&)
{
  box.Set(0, thickness / 2, thickness - thickness / 2);
}

void
MathMLHorizBarNode::DoVerticalStretchyLayout(const scaled&, const scaled&, const scaled&, bool)
{
  // this character cannot be stretched vertically
  return;
}

void
MathMLHorizBarNode::DoHorizontalStretchyLayout(const scaled& desiredSize, bool)
{
  box.width = desiredSize;
}

void
MathMLHorizBarNode::Render(const DrawingArea& area)
{
  assert(GetParent());
  const GraphicsContext* gc = GetParent()->GetForegroundGC();
  area.Clear(gc, GetX(), GetY() - box.descent, box.width, box.GetHeight());
}

bool
MathMLHorizBarNode::IsStretchyChar() const
{
  return true;
}

bool
MathMLHorizBarNode::HasDecimalPoint() const
{
  return false;
}

scaled
MathMLHorizBarNode::GetDecimalPointEdge() const
{
  return 0;
}

StretchId
MathMLHorizBarNode::GetStretch() const
{
  return STRETCH_HORIZONTAL;
}
