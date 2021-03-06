// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "remoting/host/branding.h"

#include "base/file_util.h"
#include "base/path_service.h"

namespace {

// TODO(lambroslambrou): The default locations should depend on whether Chrome
// branding is enabled - this means also modifying the Python daemon script.
// The actual location of the files is ultimately determined by the service
// daemon and NPAPI implementation - these defaults are only used in case the
// command-line switches are absent.
#if defined(OS_WIN)
#ifdef OFFICIAL_BUILD
const FilePath::CharType kConfigDir[] =
    FILE_PATH_LITERAL("Google\\Chrome Remote Desktop");
#else
const FilePath::CharType kConfigDir[] =
    FILE_PATH_LITERAL("Chromoting");
#endif
#elif defined(OS_MACOSX)
const FilePath::CharType kConfigDir[] =
    FILE_PATH_LITERAL("Chrome Remote Desktop");
#else
const FilePath::CharType kConfigDir[] =
    FILE_PATH_LITERAL(".config/chrome-remote-desktop");
#endif

} // namespace

namespace remoting {

#if defined(OS_WIN)
const wchar_t kWindowsServiceName[] = L"chromoting";
#endif

FilePath GetConfigDir() {
  FilePath app_data_dir;

#if defined(OS_WIN)
  PathService::Get(base::DIR_COMMON_APP_DATA, &app_data_dir);
#elif defined(OS_MACOSX)
  PathService::Get(base::DIR_APP_DATA, &app_data_dir);
#else
  app_data_dir = file_util::GetHomeDir();
#endif

  return app_data_dir.Append(kConfigDir);
}

} // namespace remoting
