/*
   Copyright (c) 2010, The Mineserver Project
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
 * Neither the name of the The Mineserver Project nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//
// Mineserver trxlogger.cpp
//

#include <cstdio>
//#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

#include "trxlogger.h"
#include "logger.h"
#include "config.h"

TrxLogger::TrxLogger (std::string filename) {
  log_stream.open(filename.c_str(), std::ios::in | std::ios::out | std::ios::app | std::ios::binary);
  if (!log_stream.is_open()) {
    LOG("Failed to open binary log!");
  } 
}

TrxLogger &TrxLogger::get()
{
  static TrxLogger instance(Conf::get().sValue("binlog"));
  return instance;
}

// Log action to binary log 
void TrxLogger::log(event_t event)
{
  if(!log_stream.good()) {
    LOG("Binary log stream is bad!");
  }
  time_t seconds;
  seconds = time (NULL);
  log_stream << event;
}

// Get logs based on nick and timestamp
bool TrxLogger:getLogs(time_t t, std::string nick, event_t *logs[]) {
  return true;
}

// Get logs based on timestamp
bool TrxLogger::getLogs(time_t t, event_t *logs[]) {
  return true;
}

TrxLogger::~TrxLogger() {
  log_stream.close();
}
