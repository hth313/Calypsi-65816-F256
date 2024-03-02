#ifndef __F256_H__
#define __F256_H__

#include <stdint.h>
#include <f256/dma.h>
#include <f256/interrupt.h>
#include <f256/rtc.h>
#include <f256/sdc.h>
#include <f256/sid.h>
#include <f256/system.h>
#include <f256/uart.h>
#include <f256/via.h>
#include <f256/vicky.h>

struct CompleteF256 {
  uint8_t gamma_blue[0x400];
  uint8_t gamma_green[0x400];
  uint8_t gamma_red[0x400];
  uint8_t mouse_graphic[0x400];

  union {
    struct _Vicky vicky;
    char _skip_vicky[0x400];
  };

  union {
    struct _SID sid_left;
    char _skip_sid_left[0x80];
  };

  union {
    struct _SID sid_mono;
    char _skip_sid_mono[0x80];
  };

  union {
    struct _SID sid_right;
    char _skip_sid_right[0x80];
  };

  union {
    struct {
      uint8_t opl3_address_low;
      uint8_t opl3_data;
      uint8_t opl3_address_high;
    };
    char _skip_opl3[0x80];
  };

  union {
    union {
      uint8_t psg_left;
      char _skip_psg_left[0x08];
    };
    union {
      uint8_t psg_mono;
      char _skip_psg_mono[0x08];
    };
    union {
      uint8_t psg_right;
      char _skip_psg_right[0x10];
    };
    char _skip_psg[0x20];
  };

  char _skip_codec[0x10];

  union {
    struct _UART uart;
    char _skip_uart[0x10];
  };

  char _skip_ps2[0x10];
  char _skip_timers[0x10];

  union {
    struct {
      struct _InterruptController interrupt_pending;
      struct _InterruptController interrupt_mask;
    };
    char _skip_interrupt_controller[0x10];
  };

  union {
    struct _DIP_switch dip;
    char _skip_dip_switch[0x10];
  };

  char _skip_iec_controller[0x10];

  union {
    struct _RTC rtc;
    char _skip_rtc[0x10];
  };

  union {
    struct _SystemControl system_control;
    char _skip_system_control[0x10];
  };

  char _skip_reserved_1[0x30];
  char _skip_mouse[11];
  char _skip_pcb_version[5];
  char _skip_reserved_2[0x110];
  uint8_t text_foreground_color[0x40];
  uint8_t text_background_color[0x40];
  char _skip_snes_joystick[0x10];
  sprite_t sprite[64];
  char _skip_via1[0x10];
  char _skip_via0[0x10];

  union {
    struct _SDC sdc;
    char _skip_sdc[0x10];
  };

  char _skip_math[0x20];
  char _skip_reserved_3[0xd0];

  union {
    struct _DMA dma;
    char _skip_dma[0x100];
  };

  uint8_t text_font[2][0x800];
  uint8_t graphics_color_lut[4][0x400];
  uint8_t text_memory[0x2000];
  uint8_t color_memory[0x2000];
};

// If compiler is not configured to use the Near data model, we set it
// up so that Near is the I/O bank.
#ifdef __CALYPSI_DATA_MODEL_NEAR__
#define __IO __attribute__((near))
#else
#define __IO __attribute__((far))
#endif

// Vicky base address has been set up by C startup.
#define _CompleteF256 (* (volatile struct CompleteF256 __IO *)0xf00000)

#define SystemControl        _CompleteGavin.system_control
//#define RTC                  _CompleteGavin.rtc
//#define InterruptController  _CompleteGavin.interrupt_controller
//#define Timer                _CompleteGavin.timer
//#define Joystick             _CompleteGavin.joystick
//#define UART                 _CompleteGavin.uart

#endif // __F256_H__
