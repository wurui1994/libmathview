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

#include <config.h>

#include "HorizontalFillerArea.hh"
#include "HorizontalSpaceArea.hh"

SmartPtr<HorizontalFillerArea>
HorizontalFillerArea::create()
{
  return new HorizontalFillerArea();
}

BoundingBox
HorizontalFillerArea::box() const
{
  return BoundingBox();
}

AreaRef
HorizontalFillerArea::fit(const scaled& width, const scaled&, const scaled&) const
{
  //std::cout << "filler becoming space of " << width.toInt() << std::endl;
  return HorizontalSpaceArea::create(width);
}

void
HorizontalFillerArea::strength(int& w, int& h, int& d) const
{
  w = 1;
  h = d = 0;
}

DOM::Element
HorizontalFillerArea::dump(const DOM::Document& doc) const
{
  return doc.createElementNS(STD_AREAMODEL_NAMESPACE_URI, "a:h-fill");
}

scaled
HorizontalFillerArea::leftEdge() const
{
  return scaled::min();
}

scaled
HorizontalFillerArea::rightEdge() const
{
  return scaled::min();
}
