

#define MAX_ENTRIES 10
#define NAME_LENGTH 32



typedef struct devices {
    //10 32 byte names
    char device_names[MAX_ENTRIES][NAME_LENGTH];
    int num_of_devices;

}  ble_devices_list_t;

extern ble_devices_list_t devices;



void ble_add_entry(char * new_device_name);
void ble_select_entry(int index);
void ble_clear_entries(void);
void ble_start_scanning(void); 

void ble_toggle_enable(void);
void ble_toggle_scanning(void);


int ble_get_scanning_status(void);
int ble_get_power_status(void);