/*
Mod Organizer archive handling

Copyright (C) 2012 Sebastian Herbord. All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef OPENCALLBACK_H
#define OPENCALLBACK_H

#include "archive/callback.h"
#include "archive/unknown_impl.h"

// TODO: Use Bit7z
// FIXME: COM Mess.
//#include "7zip/Archive/IArchive.h"
//#include "7zip/IPassword.h"

#include <QDir>
#include <QFileInfo>

#include <string>

class CArchiveOpenCallback {
  public:
    CArchiveOpenCallback(PasswordCallback* passwordCallback, QFileInfo const& fileinfo);

    ~CArchiveOpenCallback() {}

    QString GetPassword() const { return m_Password; }

    // ICryptoGetTextPassword interface
    // STDMETHOD(CryptoGetTextPassword)(BSTR* password);
    // Not implemented STDMETHOD(CryptoGetTextPassword2)(Int32 *passwordIsDefined, BSTR *password);

    // IArchiveOpenSetSubArchiveName interface
    // STDMETHOD(SetSubArchiveName)(const wchar_t* name);

  private:
    PasswordCallback* m_PasswordCallback;
    QString m_Password;

    QDir m_Path;
    QFileInfo m_FileInfo;

    bool m_SubArchiveMode;
    std::wstring m_SubArchiveName;
};

#endif // OPENCALLBACK_H
