/*
 * Copyright (C) 2000, Luca Padovani <luca.padovani@cs.unibo.it>.
 * 
 * This file is part of GtkMathView, a Gtk widget for MathML.
 * 
 * GtkMathView is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * GtkMathView is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GtkMathView; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 * For details, see the GtkMathView World-Wide-Web page,
 * http://cs.unibo.it/~lpadovan/mml-widget, or send a mail to
 * <luca.padovani@cs.unibo.it>
 */

#ifndef config_h
#define config_h

@TOP@

/* Is FLOATING_SCALED is defined use floating-points arithmetics
 * for scaled values (slower, larger, better precision). Otherwise
 * use fixed point arithmetics (faster, smaller).
 */
#undef FLOATING_SCALED

#ifndef FLOATING_SCALED
#define FIXED_SCALED
#endif

/* If defined the widget will perform a huge amount
 * of validity checks while running
 */
#undef ENABLE_CHECKS

#ifdef ENABLE_CHECKS
#define DEBUG
#else
#define NDEBUG
#endif

/* Define to compile with libxml 2.x (recommended) */
#undef HAVE_LIBXML2

/* Define to compile with t1lib for Type 1 fonts */
#undef HAVE_LIBT1

/* Define if iconv has a const second argument */
#undef ICONV_CONST

@BOTTOM@

#endif /* config_h */
