/*********************************************************************
 *        _       _         _
 *  _ __ | |_  _ | |  __ _ | |__   ___
 * | '__|| __|(_)| | / _` || '_ \ / __|
 * | |   | |_  _ | || (_| || |_) |\__ \
 * |_|    \__|(_)|_| \__,_||_.__/ |___/
 *
 * www.rt-labs.com
 * Copyright 2017 rt-labs AB, Sweden.
 *
 * This software is licensed under the terms of the BSD 3-clause
 * license. See the file LICENSE distributed with this software for
 * full license information.
 ********************************************************************/

#include "osal_log.h"
#include "osal.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

void os_log (uint8_t type, const char * fmt, ...)
{
   va_list list;

   switch (LOG_LEVEL_GET (type))
   {
   case LOG_LEVEL_DEBUG:
      printf ("[%u] [DEBUG] ", os_get_current_time_us());
      break;
   case LOG_LEVEL_INFO:
      printf ("[%u] [INFO ] ", os_get_current_time_us());
      break;
   case LOG_LEVEL_WARNING:
      printf ("[%u] [WARN ] ", os_get_current_time_us());
      break;
   case LOG_LEVEL_ERROR:
      printf ("[%u] [ERROR] ", os_get_current_time_us());
      break;
   case LOG_LEVEL_FATAL:
      printf ("[%u] [FATAL] ", os_get_current_time_us());
      break;
   default:
      break;
   }

   va_start (list, fmt);
   vprintf (fmt, list);
   va_end (list);
   fflush (stdout);
}
