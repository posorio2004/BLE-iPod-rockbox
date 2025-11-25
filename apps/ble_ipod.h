

#define MAX_ENTRIES 10
#define NAME_LENGTH 32



typedef struct devices {
    //10 32 byte names
    char device_names[MAX_ENTRIES][NAME_LENGTH];
    int num_of_devices;

}  ble_devices_list_t;

extern ble_devices_list_t devices;



void add_entry(char * new_device_name);
void select_entry(int index);
void clear_entries(void);
void start_scanning(void); 


