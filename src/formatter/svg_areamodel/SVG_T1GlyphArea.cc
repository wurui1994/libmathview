// Copyright (C) 2000-2005, Luca Padovani <luca.padovani@cs.unibo.it>.
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
// http://helm.cs.unibo.it/mml-widget/, or send a mail to
// <lpadovan@cs.unibo.it>

#include <config.h>

#include <cassert>

#include "Char.hh"
#include "SVG_T1Font.hh"
#include "SVG_RenderingContext.hh"
#include "SVG_T1GlyphArea.hh"

SVG_T1GlyphArea::SVG_T1GlyphArea(const SmartPtr<SVG_T1Font>& f, Char8 i)
  : font(f), index(i)
{ }

SVG_T1GlyphArea::~SVG_T1GlyphArea()
{ }

SmartPtr<SVG_T1GlyphArea>
SVG_T1GlyphArea::create(const SmartPtr<SVG_T1Font>& font, Char8 index)
{ return new SVG_T1GlyphArea(font, index); }

SmartPtr<SVG_T1Font>
SVG_T1GlyphArea::getFont() const
{ return font; }

BoundingBox
SVG_T1GlyphArea::box() const
{ return font->getGlyphBoundingBox(index); }

scaled
SVG_T1GlyphArea::leftEdge() const
{ return font->getGlyphLeftEdge(index); }

scaled
SVG_T1GlyphArea::rightEdge() const
{ return font->getGlyphRightEdge(index); }

void
SVG_T1GlyphArea::render(RenderingContext& c, const scaled& x, const scaled& y) const
{
  SVG_RenderingContext& context = dynamic_cast<SVG_RenderingContext&>(c);
  context.draw(x, y, font, index);
}
