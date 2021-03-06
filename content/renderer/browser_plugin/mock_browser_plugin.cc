// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/renderer/browser_plugin/mock_browser_plugin.h"

namespace content {

MockBrowserPlugin::MockBrowserPlugin(
    int id,
    RenderViewImpl* render_view,
    WebKit::WebFrame* frame,
    const WebKit::WebPluginParams& params)
    : BrowserPlugin(id, render_view, frame, params) {
}

MockBrowserPlugin::~MockBrowserPlugin() {}

}  // namespace content
