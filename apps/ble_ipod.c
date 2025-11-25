
#include "ble_ipod.h"
// #include "string.h"
#include "iap/iap-core.h"

ble_devices_list_t devices = {.device_names[0] = "test1", .num_of_devices=1};
int ble_scanning = 0;
int ble_enable = 0;


void ble_add_entry(char * new_device_name){

    //Shift strings over by 1
    memmove(devices.device_names[1], devices.device_names[0], devices.num_of_devices*NAME_LENGTH);
    //Add new one to list
    memcpy(devices.device_names[0], new_device_name, NAME_LENGTH);
    if (devices.num_of_devices != MAX_ENTRIES){
        devices.num_of_devices++;
    }
}
void ble_select_entry(int index){
    IAP_TX_INIT(0x08, 0x10);
    IAP_TX_PUT(index);
    iap_send_tx();

}
void ble_clear_entries(){
    //Set all to 0
    memset(devices.device_names[0], 0, MAX_ENTRIES * NAME_LENGTH);
    devices.num_of_devices = 0;
}

void ble_toggle_scanning(){
    IAP_TX_INIT(0x08, 0x02);
    IAP_TX_PUT(ble_scanning);
    ble_scanning = !ble_scanning;
    iap_send_tx();

}


//Put the BLE in low power - hopefully
void ble_toggle_enable(){
    IAP_TX_INIT(0x08, 0x01);
    IAP_TX_PUT(ble_enable);
    ble_enable = !ble_enable;
    iap_send_tx();
}


int ble_get_scanning_status(){
    IAP_TX_INIT(0x08, 0x02)
    return 0;
}

int ble_get_power_status(){
    return 0;
}
