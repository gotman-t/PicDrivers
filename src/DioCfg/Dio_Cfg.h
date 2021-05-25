#ifndef DIO_CFG_H
#define DIO_CFG_H

typedef enum {
    DIO_RA2,
    DIO_RA4,
    DIO_RA5,
    DIO_RC2,
    DIO_RC3,
    DIO_RC4,
    DIO_RC5,
} DioType; // 変更時は NUM_DIO の定義変更も実施すること

#define NUM_DIO (DIO_RC5 + 1)

#endif  /* DIO_CFG_H */

