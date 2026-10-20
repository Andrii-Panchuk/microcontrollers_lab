#ifndef SENSORS_H
#define SENSORS_H

#include "config.h"

void sensors_init(void);

int button_1_pressed(void);
int button_2_pressed(void);

SensorData read_all_sensors(void);

#endif // SENSORS_H 