/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2007 Jonathan Gordon
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "config.h"
#include "lang.h"
#include "action.h"
#include "settings.h"
#include "string-extra.h"
#include "menu.h"
#include "playlist_menu.h"

#include "ble_ipod.h"







/***********************************/
/*    Custom BLEiPodV2 MENU            */









MENUITEM_STRINGLIST(ble_devices_list, "Scan for Devices", NULL, devices.device_names[0], devices.device_names[1], devices.device_names[2], devices.device_names[3],devices.device_names[4], devices.device_names[5], devices.device_names[6],devices.device_names[7], devices.device_names[8], devices.device_names[9]);

MAKE_MENU(ble_settings, ID2P(BLE_FOUND_DEVICES), 0, Icon_Playback_menu, &ble_devices_list);



/*    Custom BLEiPodV2 MENU            */
/***********************************/



