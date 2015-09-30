/*=============================================================================
#     FileName: 6-type.c
#         Desc: race! 
#       Author: Max Lee (Ho Suk Lee)
#        Email: hoso1312@gmail.com
#     HomePage: http://imnotbermuda.com
#      Version: 0.0.1
#   LastChange: 2015-09-30 22:19:13
=============================================================================*/
#define CAR_COUNT 30
#define LAP_COUNT 100

typedef struct {
    char first[20];
    char last[30];
} name_t;

typedef struct {
    name_t driver_name;
    int serial_num;
    int laps_completed;
    double total_race_time;
    double lap_time[LAP_COUNT];
    int pos;
} car_t;

typedef struct {
    char notes[LAP_COUNT];
} lap_t;

typedef struct {
    lap_t laps[LAP_COUNT];
    car_t cars[CAR_COUNT];
} car_race_t;
