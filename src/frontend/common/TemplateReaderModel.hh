// Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
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

#ifndef __TemplateReaderModel_hh__
#define __TemplateReaderModel_hh__

#include "SmartPtr.hh"
#include "String.hh"

#include "TemplateReaderNodeIterator.hh"
#include "TemplateReaderElementIterator.hh"

template <class Reader>
struct TemplateReaderModel
{
  enum {
    TEXT_NODE = Reader::TEXT_NODE,
    ELEMENT_NODE = Reader::ELEMENT_NODE
  };

  typedef SmartPtr<Reader> Node;
  typedef SmartPtr<Reader> Element;
  typedef SmartPtr<Reader> Document;
  typedef TemplateReaderNodeIterator<Reader> NodeIterator;
  typedef TemplateReaderElementIterator<Reader> ElementIterator;

  static SmartPtr<Reader> document(const class AbstractLogger&, const std::string& path, bool subst = false)
  { return Reader::create(path, subst); }

  static SmartPtr<Reader> getDocumentElement(const SmartPtr<Reader>& reader) { return reader; }

  static void             reset(const SmartPtr<Reader>& reader) { reader->reset(); }
  static SmartPtr<Reader> asNode(const SmartPtr<Reader>& reader) { return reader; }
  static SmartPtr<Reader> asElement(const SmartPtr<Reader>& reader) { return reader; }

  static unsigned getNodeType(const SmartPtr<Reader>& reader) { return reader->getNodeType(); }
  static std::string getNodeName(const SmartPtr<Reader>& reader) { return reader->getNodeName(); }
  static std::string getNodeValue(const SmartPtr<Reader>& reader) { return reader->getNodeValue(); }
  static std::string getNodeNamespaceURI(const SmartPtr<Reader>& reader) { return reader->getNodeNamespaceURI(); }
  
  static std::string getElementValue(const SmartPtr<Reader>& reader)
  {
    std::string value;
    for (NodeIterator iter(reader); iter.more(); iter.next())
      if (reader->getNodeType() == TEXT_NODE) value += reader->getNodeValue();
    return value;
  }
  static std::string getAttribute(const SmartPtr<Reader>& reader, const std::string& name) { return reader->getAttribute(name); }
  static bool hasAttribute(const SmartPtr<Reader>& reader, const std::string& name) { return reader->hasAttribute(name); }

  struct Hash
  {
    size_t operator()(const SmartPtr<Reader>& reader) const
    { return reader->getNodeId(); }
  };
};

#endif // __TemplateReaderModel_hh__
