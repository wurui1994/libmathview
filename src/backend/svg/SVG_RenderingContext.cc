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
#include <iomanip>

#include "AbstractLogger.hh"
#include "SVG_RenderingContext.hh"
#include "scaledAux.hh"
#include "BoundingBoxAux.hh"
#include "RGBColorAux.hh"
#include "TFM.hh"
#include "TFMFont.hh"

SVG_RenderingContext::SVG_RenderingContext(const SmartPtr<AbstractLogger>& l)
  : logger(l)
{
  assert(logger);
}

SVG_RenderingContext::~SVG_RenderingContext()
{ }

String
SVG_RenderingContext::toSVGLength(const scaled& s)
{
  std::ostringstream buffer;
  buffer << std::fixed << std::setprecision(2) << s.toFloat() << "pt";
  return buffer.str();
}

String
SVG_RenderingContext::toSVGColor(const RGBColor& c)
{
  return toString(RGBColor(c.red, c.green, c.blue));
}

String
SVG_RenderingContext::toSVGOpacity(const RGBColor& c)
{
  std::ostringstream buffer;
  buffer << static_cast<float>(c.alpha) / 255;
  return buffer.str();
}

void
SVG_RenderingContext::documentStart(const BoundingBox& bbox)
{
  beginDocument(bbox);
  metadata("Created by "PACKAGE" version "VERSION);
}

void
SVG_RenderingContext::documentEnd()
{
  endDocument();
}

void
SVG_RenderingContext::fill(const scaled& x, const scaled& y, const BoundingBox& box)
{
  rect(toSVGX(x), toSVGY(y + box.height), box.horizontalExtent(), box.verticalExtent(),
       getForegroundColor(), getForegroundColor(), scaled::zero());
}

void
SVG_RenderingContext::draw(const scaled& x, const scaled& y, const SmartPtr<TFMFont>& font, Char8 index)
{
  SmartPtr<TFM> tfm = font->getTFM();
  assert(tfm);
  const int mappedIndex = (index < 32) ? 256 + index : index;

  std::ostringstream familyS;
  familyS << tfm->getFamily() << tfm->getDesignSize().toInt();
  std::ostringstream contentS;
  contentS << "&#" << mappedIndex << ";";
  const String family = familyS.str();
  const String content = contentS.str();
  text(toSVGX(x), toSVGY(y), family, font->getSize(),
       getForegroundColor(), getForegroundColor(), scaled::zero(), content);
}

void
SVG_RenderingContext::wrapperStart(const scaled&, const scaled&, const BoundingBox&, 
				   const SmartPtr<Element>&)
{ }

void
SVG_RenderingContext::wrapperEnd()
{ }

void
SVG_RenderingContext::beginDocument(const BoundingBox&)
{ }

void
SVG_RenderingContext::endDocument()
{ }

void
SVG_RenderingContext::metadata(const String&)
{ }

void
SVG_RenderingContext::text(const scaled&, const scaled&, const String&, const scaled&,
			   const RGBColor&, const RGBColor&, const scaled&, const String&)
{ }

void
SVG_RenderingContext::rect(const scaled&, const scaled&, const scaled&, const scaled&,
			   const RGBColor&, const RGBColor&, const scaled&)
{ }

void
SVG_RenderingContext::line(const scaled&, const scaled&, const scaled&, const scaled&,
			   const RGBColor&, const scaled&)
{ }
