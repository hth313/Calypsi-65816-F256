#ifndef __F256_RTC_H__
#define __F256_RTC_H__

#include <stdint.h>

struct _RTC {
  uint8_t time_seconds;
  uint8_t alarm_seconds;
  uint8_t time_minutes;
  uint8_t alarm_minutes;
  uint8_t time_hours;
  uint8_t alarm_hours;
  uint8_t time_days;
  uint8_t alarm_days;
  uint8_t dow;
  uint8_t month;
  uint8_t year;
  union {
    struct {
      uint8_t res    : 4;
      uint8_t wd     : 3;
      uint8_t        : 1;
    };
    uint8_t rates;
  };
  union {
    struct {
      uint8_t abe    : 1;
      uint8_t pwrie  : 1;
      uint8_t pie    : 1;
      uint8_t aie    : 1;
      uint8_t        : 4;
    };
    uint8_t enables;
  };
  union {
    struct {
      uint8_t bvf    : 1;
      uint8_t pwrf   : 1;
      uint8_t pf     : 1;
      uint8_t af     : 1;
      uint8_t        : 4;
    };
    uint8_t flags;
  };
  union {
    struct {
      uint8_t dse    : 1;
      uint8_t t12_24 : 1;
      uint8_t stopn  : 1;
      uint8_t uti    : 1;
      uint8_t        : 4;
    };
    uint8_t control;
  };
  uint8_t century;
};

#endif // __F256_RTC_H__
