
#ifndef Platform_types_h
#define Platform_types_h
#include <stdbool.h>
#include <stdint.h>
typedef _Bool 			boolean;
typedef int8_t 			sint8;
typedef uint8_t 		uint8;
typedef int16_t			sint16;
typedef uint16_t		uint16;

typedef char 			char_t;
typedef int32_t			sint32;
typedef uint32_t		uint32;
typedef int64_t			sint64;
typedef uint64_t		uint64;

typedef volatile int8_t vint8;
typedef volatile uint8_t vuint8;
typedef volatile int16_t vint16;
typedef volatile uint16_t vuint16;
typedef volatile int32_t vint32;
typedef volatile uint32_t vuint32;
typedef volatile int64_t vint64;
typedef volatile uint64_t vuint64;

typedef float       float32;
typedef double      float64;


#ifndef TRUE
#define TRUE    ((boolean) 1)
#endif

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif

#endif
