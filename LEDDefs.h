// LEDDefs.h

#ifndef _LEDDEFS_h
#define _LEDDEFS_h

/* LED Libraries */
#include <FastLED.h>

#define NUM_LEDS 120
#define PIN            D2

enum LEDState {
	Sunrise,
	Sunset,
	DoNothing,
	Off,
	ReadingLightSybi,
	ReadingLightMichi,
	Set
};
LEDState currentLightState = Set;
LEDState lastLightState = DoNothing;
LEDState sunTransitionState;

CRGBArray<NUM_LEDS> leds;
CRGBArray<NUM_LEDS> ledsTmp;
CRGBArray<NUM_LEDS> NachtlichtMichi;
CRGBArray<NUM_LEDS> NachtlichtSybi;

#define HUE_SUNRISE_TARGET 35
#define SAT_SUNRISE_TARGET 80
#define VAL_SUNRISE_TARGET 255

#define HUE_SUNSET_TARGET 10
#define SAT_SUNSET_TARGET 255
#define VAL_SUNSET_TARGET 0

CHSV SUNRISE_TARGET = CHSV(HUE_SUNRISE_TARGET, SAT_SUNRISE_TARGET, VAL_SUNRISE_TARGET);
CHSV SUNSET_TARGET = CHSV(HUE_SUNSET_TARGET, SAT_SUNSET_TARGET, VAL_SUNSET_TARGET);
CHSV currentHSV = SUNSET_TARGET;
CHSV lastHSV = CHSV(0, 0, 0);

#define SPEED_SEC 32
uint8_t hue = HUE_SUNSET_TARGET;
uint8_t sat = 255;
uint8_t val = 0;
uint32_t nSpeed = SPEED_SEC;
uint32_t nSteps = 0;
uint32_t nTransitionTime = 0;
uint8_t  nDelay = 30;
bool bTransitionReady = false;

#endif

