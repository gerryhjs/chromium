// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_PLUGINS_PLUGIN_METADATA_H_
#define CHROME_BROWSER_PLUGINS_PLUGIN_METADATA_H_

#include <map>

#include "base/string16.h"
#include "base/version.h"
#include "googleurl/src/gurl.h"

namespace webkit {
struct WebPluginInfo;
}

class PluginMetadata {
 public:
  // Information about a certain version of the plug-in.
  enum SecurityStatus {
    SECURITY_STATUS_UP_TO_DATE,
    SECURITY_STATUS_OUT_OF_DATE,
    SECURITY_STATUS_REQUIRES_AUTHORIZATION,
  };

  PluginMetadata(const std::string& identifier,
                 const string16& name,
                 bool url_for_display,
                 const GURL& plugin_url,
                 const GURL& help_url,
                 const string16& group_name_matcher);
  ~PluginMetadata();

  // Unique identifier for the plug-in.
  const std::string& identifier() const { return identifier_; }

  // Human-readable name of the plug-in.
  const string16& name() const { return name_; }

  // If |url_for_display| is false, |plugin_url| is the URL of the download page
  // for the plug-in, which should be opened in a new tab. If it is true,
  // |plugin_url| is the URL of the plug-in installer binary, which can be
  // directly downloaded.
  bool url_for_display() const { return url_for_display_; }
  const GURL& plugin_url() const { return plugin_url_; }

  // URL to open when the user clicks on the "Problems installing?" link.
  const GURL& help_url() const { return help_url_; }

  // Adds information about a plug-in version.
  void AddVersion(const Version& version, SecurityStatus status);

  // Checks if the plug-in matches the group matcher.
  bool MatchesPlugin(const webkit::WebPluginInfo& plugin);

  // If |status_str| describes a valid security status, writes it to |status|
  // and returns true, else returns false and leaves |status| unchanged.
  static bool ParseSecurityStatus(const std::string& status_str,
                                  SecurityStatus* status);

  // Returns the security status for the given plug-in (i.e. whether it is
  // considered out-of-date, etc.)
  SecurityStatus GetSecurityStatus(const webkit::WebPluginInfo& plugin) const;

 private:
  struct VersionComparator {
    bool operator() (const Version& lhs, const Version& rhs) const;
  };

  std::string identifier_;
  string16 name_;
  string16 group_name_matcher_;
  bool url_for_display_;
  GURL plugin_url_;
  GURL help_url_;
  std::map<Version, SecurityStatus, VersionComparator> versions_;
};

#endif  // CHROME_BROWSER_PLUGINS_PLUGIN_METADATA_H_
