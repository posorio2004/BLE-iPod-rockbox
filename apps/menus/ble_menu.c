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


static char *  get_bluetooth_power_status_text(int selected_item, void * data, char * buffer, size_t buffer_len){
    int ble_mode = ble_get_power_status();
    (void) data;
    (void) selected_item;

    snprintf(buffer, buffer_len, "%s", ble_mode ? "Disable Bluetooth" : "Enable Bluetooth");
    return buffer;
}

static char *  get_bluetooth_search_status_text(int selected_item, void * data, char * buffer, size_t buffer_len){
    int ble_mode = ble_get_scanning_status();
    (void) data;
    (void) selected_item;

    snprintf(buffer, buffer_len, "%s", ble_mode ? "Stop Searching" : "Start Searching");
    return buffer;
}


MENUITEM_FUNCTION_DYNTEXT(enable_bluetooth_scanning_toggle, 0, (void*) ble_toggle_scanning, get_bluetooth_search_status_text, NULL, NULL, NULL, Icon_NOICON);
MENUITEM_FUNCTION_DYNTEXT(enable_bluetooth_power_toggle, 0, (void*) ble_toggle_enable, get_bluetooth_power_status_text, NULL, NULL, NULL, Icon_NOICON);


MENUITEM_STRINGLIST(ble_devices_list, "Found Devices", NULL, 
    devices.device_names[0], devices.device_names[1], 
    devices.device_names[2], devices.device_names[3],
    devices.device_names[4], devices.device_names[5], 
    devices.device_names[6], devices.device_names[7], 
    devices.device_names[8], devices.device_names[9]);

MAKE_MENU(ble_settings, ID2P(BLE_MENU_TITLE), 0, Icon_Playback_menu, &enable_bluetooth_power_toggle, &enable_bluetooth_scanning_toggle, &ble_devices_list);



/*    Custom BLEiPodV2 MENU            */
/***********************************/



