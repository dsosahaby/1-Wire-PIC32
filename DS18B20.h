
#ifndef _DS18B20_H_
#define _DS18B20_H_

//define ROM commands
#define SEARCH_ROM 0xF0
#define READ_ROM 0x33
#define MATCH_ROM 0x55
#define SKIP_ROM 0xCC
#define ALARM_SEARCH 0xEC

//define DS18B20 sensor commands
#define CONVERT_T 0x44
#define WRITE_SCRATCHPAD 0x4E
#define READ_SCRATCHPAD 0xBE
#define COPY_SCRATCHPAD 0x48
#define RECALL_E 0xB8
#define READ_POWER 0xB4



#endif /* _DS18B20_H */