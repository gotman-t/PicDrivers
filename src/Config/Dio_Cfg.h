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
} DioType; // •ÏX‚Í NUM_DIO ‚Ì’è‹`•ÏX‚àÀ{‚·‚é‚±‚Æ

#define NUM_DIO (DIO_RC5 + 1)

#endif  /* DIO_CFG_H */

