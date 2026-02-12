/***************************************************************************
 *             __________               __   ___.
 *   Open      \______   \ ____   ____ |  | _\_ |__   _______  ___
 *   Source     |       _//  _ \_/ ___\|  |/ /| __ \ /  _ \  \/  /
 *   Jukebox    |    |   (  <_> )  \___|    < | \_\ (  <_> > <  <
 *   Firmware   |____|_  /\____/ \___  >__|_ \|___  /\____/__/\_ \
 *                     \/            \/     \/    \/            \/
 * $Id$
 *
 * Copyright (C) 2002 by Alan Korr & Nick Robinson
 *
 * All files in this archive are subject to the GNU General Public License.
 * See the file COPYING in the source tree root for full license agreement.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ****************************************************************************/

/* Lingo 0x08: BLEiPodV2 board Lingo
 */

#include "iap-core.h"
#include "iap-lingo.h"

#include "ble_ipod.h"
#include <string.h>
#include <stdlib.h>

/*
 * This macro is meant to be used inside an IAP mode message handler.
 * It is passed the expected minimum length of the message buffer.
 * If the buffer does not have the required lenght an ACK
 * packet with a Bad Parameter error is generated.
 */
#define CHECKLEN(x) do { \
        if (len < (x)) { \
            cmd_ack(cmd, IAP_ACK_BAD_PARAM); \
            return; \
        }} while(0)

/* Check for authenticated state, and return an ACK Not
 * Authenticated on failure.
 */
#define CHECKAUTH do { \
        if (!DEVICE_AUTHENTICATED) { \
            cmd_ack(cmd, IAP_ACK_NO_AUTHEN); \
            return; \
        }} while(0)

static void cmd_ack(const unsigned char cmd, const unsigned char status)
{
    IAP_TX_INIT(0x08, 0x00);
    IAP_TX_PUT(status);
    IAP_TX_PUT(cmd);

    iap_send_tx();
}


void iap_handlepkt_mode8(const unsigned int len, const unsigned char *buf)
{
    unsigned int cmd = buf[1];

    /* Lingo 0x08 commands are at least 2 bytes in length */
    CHECKLEN(2);

    /* Lingo 0x08 must have been negotiated */
    if (!DEVICE_LINGO_SUPPORTED(0x08)) {
        cmd_ack(cmd, IAP_ACK_BAD_PARAM);
        return;
    }

    /* Authentication required for all commands */
    // CHECKAUTH;

    switch (cmd)
    {
        //     0x04 - Found Newly Scanned Device
        //     - Parameter: String Length      1 byte
        //     - Parameters: Device Name       N bytes
        case 0x04:
            CHECKLEN(4);

            ble_devices.num_of_devices++;
            memmove(&ble_devices.device_names[ble_devices.num_of_devices], &buf[3], buf[2]); //Copy buf[2] bytes from buffer to struct
            
            //Send ACK
            IAP_TX_INIT(0x08, 0xFF);
            iap_send_tx();
        break;



        default:
        {
#ifdef LOGF_ENABLE
            logf("iap: Unsupported Mode1 Command");
#endif
            cmd_ack(cmd, IAP_ACK_BAD_PARAM);
            break;
        }
    }
}
