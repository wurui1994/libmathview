// Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
// Copyright (C) 2014, Khaled Hosny <khaledhosny@eglug.org>.
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

#ifndef __Cairo_RenderingContext_hh__
#define __Cairo_RenderingContext_hh__

#include <cairo/cairo.h>

#include "SmartPtr.hh"
#include "Rectangle.hh"
#include "RenderingContext.hh"

class Cairo_RenderingContext : public RenderingContext
{
public:
  Cairo_RenderingContext(cairo_t* cr);
  virtual ~Cairo_RenderingContext();

  void fill(const scaled&, const scaled&, const BoundingBox&) const;
  void draw(const scaled&, const scaled&, cairo_scaled_font_t*, unsigned) const;

  virtual double toDevicePixels(const scaled& s)
  { return Cairo_RenderingContext::toCairoPixels(s); }
  virtual scaled fromDevicePixels(double s)
  { return Cairo_RenderingContext::fromCairoPixels(s); }

  static double toCairoPixels(const scaled& s)
  { return (s * (72.27 / 72.0)).toDouble(); }
  static scaled fromCairoPixels(double s)
  { return scaled(s * (72.0 / 72.27)); }

  static double toCairoX(const scaled& x)
  { return toCairoPixels(x); }
  static double toCairoY(const scaled& y)
  { return toCairoPixels(-y); }

  static scaled fromCairoX(double x)
  { return fromCairoPixels(x); }
  static scaled fromCairoY(double y)
  { return fromCairoPixels(-y); }

private:
  cairo_t* m_cr;
};

#endif // __Cairo_RenderingContext_hh__
