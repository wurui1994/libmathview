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

#ifndef __Gtk_AdobeShaper_hh__
#define __Gtk_AdobeShaper_hh__

#include <functional>

#include "HashMap.hh"
#include "Shaper.hh"

class Gtk_AdobeShaper : public Shaper
{
protected:
  Gtk_AdobeShaper(void);
  virtual ~Gtk_AdobeShaper();

public:
  enum { N_FONTS = 10 };

  static SmartPtr<Gtk_AdobeShaper> create(void)
  { return new Gtk_AdobeShaper(); }

  void setFontManager(const SmartPtr<class Gtk_PangoFontManager>&);

  virtual void registerShaper(const SmartPtr<class ShaperManager>&, unsigned);
  virtual void unregisterShaper(const SmartPtr<class ShaperManager>&, unsigned);
  virtual void shape(const class MathFormattingContext&, class ShapingResult&) const;

protected:
  virtual AreaRef createGlyphArea(const SmartPtr<class Gtk_AreaFactory>&, unsigned, unsigned, const scaled&) const;

  AreaRef createPangoGlyphArea(const SmartPtr<class Gtk_AreaFactory>&, unsigned, unsigned, const scaled&) const;
  AreaRef getGlyphArea(const SmartPtr<class Gtk_AreaFactory>&, unsigned, unsigned, const scaled&) const;

  AreaRef shapeChar(const class MathFormattingContext&, const class GlyphSpec&) const;
  AreaRef shapeStretchyCharV(const class MathFormattingContext&, const class GlyphSpec&, const scaled&) const;
  AreaRef shapeStretchyCharH(const class MathFormattingContext&, const class GlyphSpec&, const scaled&) const;

  struct CachedAreaKey
  {
    CachedAreaKey(unsigned g, const scaled& s) : glyph(g), size(s) { }

    unsigned glyph;
    scaled size;

    bool operator==(const CachedAreaKey& k) const
    { return glyph == k.glyph && size == k.size; }
  };

  struct CachedAreaKeyHash
  {
    bool operator()(const CachedAreaKey& key) const
    { return key.glyph ^ key.size.getValue(); }
  };

  typedef HASH_MAP_NS::hash_map<CachedAreaKey,AreaRef,CachedAreaKeyHash> AreaCache;

  mutable AreaCache areaCache[N_FONTS];
  SmartPtr<class Gtk_PangoFontManager> fontManager;
};

#endif // __Gtk_AdobeShaper_hh__
