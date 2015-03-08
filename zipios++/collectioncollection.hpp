#pragma once
/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000-2015  Thomas Sondergaard

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

/** \file
 * \brief Header file that defines CollectionCollection.
 */

#include "zipios++/filecollection.hpp"


namespace zipios
{


class CollectionCollection : public FileCollection
{
public:
    explicit                        CollectionCollection();
                                    CollectionCollection(CollectionCollection const& src);
    virtual pointer_t               clone() const;
    CollectionCollection const&     operator = (CollectionCollection const& src);
    virtual                         ~CollectionCollection();

    bool                            addCollection(FileCollection const& collection);
    bool                            addCollection(FileCollection::pointer_t collection);
    virtual void                    close();
    virtual FileEntry::vector_t     entries() const;
    virtual FileEntry::pointer_t    getEntry(std::string const& name, MatchPath matchpath = MatchPath::MATCH) const;
    virtual stream_pointer_t        getInputStream(FileEntry::pointer_t entry);
    virtual stream_pointer_t        getInputStream(std::string const& entry_name, MatchPath matchpath = MatchPath::MATCH);
    virtual size_t                  size() const;

protected:
    vector_t                        m_collections;
};


} // namespace
// vim: ts=4 sw=4 et