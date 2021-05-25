#ifndef DIO_INTERNAL_H
#define DIO_INTERNAL_H

typedef DioLevelType(*ReadFunc)(void);
typedef void(*WriteFunc)(DioLevelType);

typedef struct {
    ReadFunc Read;
    WriteFunc Write;
} DioCfg;

extern const DioCfg k_DioCfg[];

#endif  /* DIO_INTERNAL_H */

