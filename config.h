#include "sht3x.h"

#ifndef SHT3X_PARAM_MODE
#define SHT3X_PARAM_MODE        (sht3x_single_shot)
#endif
#ifndef SHT3X_PARAM_REPEAT
#define SHT3X_PARAM_REPEAT      (sht3x_low)
#endif

#ifndef GPS
#define GPS                     (0)
#endif
#ifndef FINGERPRINTING
#define FINGERPRINTING          (1)
#endif