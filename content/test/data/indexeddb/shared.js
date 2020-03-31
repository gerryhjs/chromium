// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

window.indexedDB = window.indexedDB || window.webkitIndexedDB;

function result(message) {
    document.title = message;
}

function unexpectedErrorCallback()
{
  result('fail - unexpected error callback');
}

function unexpectedAbortCallback()
{
  result('fail - unexpected abort callback');
}

function unexpectedCompleteCallback()
{
  result('fail - unexpected complete callback');
}
