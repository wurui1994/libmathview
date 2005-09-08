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

#ifndef __Shaper_hh__
#define __Shaper_hh__

#include "Area.hh"

class GMV_MathView_EXPORT Shaper : public Object
{
protected:
  Shaper(void) { }
  virtual ~Shaper() { }

public:
  virtual void registerShaper(const SmartPtr<class ShaperManager>&, unsigned) = 0;
  virtual void unregisterShaper(const SmartPtr<class ShaperManager>&, unsigned) = 0;
  virtual void shape(class ShapingContext&) const = 0;

protected:
  virtual AreaRef composeStretchyCharV(const SmartPtr<class AreaFactory>&,
				       const AreaRef&, const AreaRef&, const AreaRef&, const AreaRef&, const AreaRef&,
				       const scaled&) const;
  virtual AreaRef composeStretchyCharH(const SmartPtr<class AreaFactory>&,
				       const AreaRef&, const AreaRef&, const AreaRef&, const AreaRef&,
				       const scaled&) const;
};

#endif // __Shaper_hh__

