#include <sfrcommon.h>
#ifndef __HY17P52SFR__
#define __HY17P52SFR__
#define USE_HY17P52 1
__SFRDEF(_SWTGTID,0xA43354DA)
__SFRDEF(INDF0,0x0)
__SFRDEF(POINC0,0x1)
__SFRDEF(PODEC0,0x2)
__SFRDEF(PRINC0,0x3)
__SFRDEF(PLUSW0,0x4)
__SFRDEF(INDF1,0x5)
__SFRDEF(POINC1,0x6)
__SFRDEF(PODEC1,0x7)
__SFRDEF(PRINC1,0x8)
__SFRDEF(PLUSW1,0x9)
__SFRDEF(INDF2,0xA)
__SFRDEF(POINC2,0xB)
__SFRDEF(PODEC2,0xC)
__SFRDEF(PRINC2,0xD)
__SFRDEF(PLUSW2,0xE)
__SFRDEF(FSR0H,0xF)
__SFRDEF(FSR0L,0x10)
__SFRDEF(FSR1H,0x11)
__SFRDEF(FSR1L,0x12)
__SFRDEF(FSR2H,0x13)
__SFRDEF(FSR2L,0x14)
__SFRDEF(TOSH,0x16)
__SFRDEF(TOSL,0x17)
__SFRDEF(SKCN,0x18)
__SFRDEF(PCLATH,0x1A)
__SFRDEF(PCLATL,0x1B)
__SFRDEF(TBLPTRH,0x1D)
__SFRDEF(TBLPTRL,0x1E)
__SFRDEF(TBLDH,0x1F)
__SFRDEF(TBLDL,0x20)
__SFRDEF(PRODH,0x21)
__SFRDEF(PRODL,0x22)
__SFRDEF(INTE0,0x23)
__SFRDEF(INTE1,0x24)
__SFRDEF(INTF0,0x26)
__SFRDEF(INTF1,0x27)
__SFRDEF(WREG,0x29)
__SFRDEF(BSRCN,0x2A)
__SFRDEF(STATUS,0x2B)
__SFRDEF(MSTAT,0x2B)
__SFRDEF(PSTAT,0x2C)
__SFRDEF(BIECN,0x2E)
__SFRDEF(BIEARH,0x2F)
__SFRDEF(BIEARL,0x30)
__SFRDEF(BIEDRH,0x31)
__SFRDEF(BIEDRL,0x32)
__SFRDEF(PWRCN,0x33)
__SFRDEF(OSCCN0,0x34)
__SFRDEF(OSCCN1,0x35)
__SFRDEF(OSCCN2,0x36)
__SFRDEF(CSFCN0,0x37)
__SFRDEF(CSFCN1,0x38)
__SFRDEF(WDTCN,0x39)
__SFRDEF(AD1H,0x3A)
__SFRDEF(AD1M,0x3B)
__SFRDEF(AD1L,0x3C)
__SFRDEF(AD1CN0,0x3D)
__SFRDEF(AD1CN1,0x3E)
__SFRDEF(AD1CN2,0x3F)
__SFRDEF(AD1CN3,0x40)
__SFRDEF(AD1CN4,0x41)
__SFRDEF(AD1CN5,0x42)
__SFRDEF(LVDCN,0x43)
__SFRDEF(TMA1CN,0x44)
__SFRDEF(TMA1R,0x45)
__SFRDEF(TMA1C,0x46)
__SFRDEF(PT1,0x47)
__SFRDEF(TRISC1,0x48)
__SFRDEF(PT1DA,0x49)
__SFRDEF(PT1PU,0x4A)
__SFRDEF(PT1M1,0x4B)
__SFRDEF(PT2,0x4C)
__SFRDEF(TRISC2,0x4D)
__SFRDEF(PT2DA,0x4E)
__SFRDEF(PT2PU,0x4F)

__SFRDEF(PT8,0x50)
__SFRDEF(TRISC8,0x51)

__SFRDEF(PT8PU,0x53)

__SFRDEF(UR0CN,0x54)
__SFRDEF(UR0STA,0x55)
__SFRDEF(BA0CN,0x56)
__SFRDEF(BG0RH,0x57)
__SFRDEF(BG0RL,0x58)
__SFRDEF(TX0R,0x59)
__SFRDEF(RC0REG,0x5A)

__SFRDEF(LCDCN1,0x5B)
__SFRDEF(LCDCN2,0x5C)
__SFRDEF(LCDCN3,0x5D)
__SFRDEF(LCDCN4,0x5E)


__SFRDEF(LCD0,0x5F)
__SFRDEF(LCD1,0x60)
__SFRDEF(LCD2,0x61)
__SFRDEF(LCD3,0x62)
__SFRDEF(LCD4,0x63)
__SFRDEF(LCD5,0x64)
__SFRDEF(LCD6,0x65)
__SFRDEF(Filter,0x66)


extern volatile __data unsigned char *FSR0;
extern volatile __data unsigned char *FSR1;
extern volatile __data unsigned char *FSR2;
#define __xdata __data
__SFRDEF(ADCRH,0x3A)
__SFRDEF(ADCRM,0x3B)
__SFRDEF(ADCRL,0x3C)
extern volatile signed long ADCR;
#endif
#ifndef __SDCC
#define _SWTGTID (*((volatile unsigned char *)0xA6A6B2CF))
#define INDF0 (*((volatile unsigned char *)0x0))
#define POINC0 (*((volatile unsigned char *)0x1))
#define PODEC0 (*((volatile unsigned char *)0x2))
#define PRINC0 (*((volatile unsigned char *)0x3))
#define PLUSW0 (*((volatile unsigned char *)0x4))
#define INDF1 (*((volatile unsigned char *)0x5))
#define POINC1 (*((volatile unsigned char *)0x6))
#define PODEC1 (*((volatile unsigned char *)0x7))
#define PRINC1 (*((volatile unsigned char *)0x8))
#define PLUSW1 (*((volatile unsigned char *)0x9))
#define INDF2 (*((volatile unsigned char *)0xA))
#define POINC2 (*((volatile unsigned char *)0xB))
#define PODEC2 (*((volatile unsigned char *)0xC))
#define PRINC2 (*((volatile unsigned char *)0xD))
#define PLUSW2 (*((volatile unsigned char *)0xE))
#define FSR0H 		(*((volatile unsigned char *)0xF))
#define FSR0L 		(*((volatile unsigned char *)0x10))
#define FSR1H 		(*((volatile unsigned char *)0x11))
#define FSR1L 		(*((volatile unsigned char *)0x12))
#define FSR2H 		(*((volatile unsigned char *)0x13))
#define FSR2L 		(*((volatile unsigned char *)0x14))
#define TOSH 		(*((volatile unsigned char *)0x16))
#define TOSL 		(*((volatile unsigned char *)0x17))
#define SKCN 		(*((volatile unsigned char *)0x18))
#define PCLATH 		(*((volatile unsigned char *)0x1A))
#define PCLATL 		(*((volatile unsigned char *)0x1B))
#define TBLPTRH 	(*((volatile unsigned char *)0x1D))
#define TBLPTRL 	(*((volatile unsigned char *)0x1E))
#define TBLDH 		(*((volatile unsigned char *)0x1F))
#define TBLDL 		(*((volatile unsigned char *)0x20))
#define PRODH 		(*((volatile unsigned char *)0x21))
#define PRODL 		(*((volatile unsigned char *)0x22))
#define INTE0 		(*((volatile unsigned char *)0x23))
#define INTE1 		(*((volatile unsigned char *)0x24))
#define INTE2 		(*((volatile unsigned char *)0x25))
#define INTF0 		(*((volatile unsigned char *)0x26))
#define INTF1 		(*((volatile unsigned char *)0x27))
#define INTF2 		(*((volatile unsigned char *)0x28))
#define WREG 		(*((volatile unsigned char *)0x29))
#define BSRCN 		(*((volatile unsigned char *)0x2A))
#define STATUS 		(*((volatile unsigned char *)0x2B))
#define MSTAT 		(*((volatile unsigned char *)0x2B))
#define PSTAT 		(*((volatile unsigned char *)0x2C))
#define BIECN 		(*((volatile unsigned char *)0x2E))
#define BIEARH 		(*((volatile unsigned char *)0x2F))
#define BIEARL 		(*((volatile unsigned char *)0x30))
#define BIEDRH 		(*((volatile unsigned char *)0x31))
#define BIEDRL 		(*((volatile unsigned char *)0x32))
#define PWRCN 		(*((volatile unsigned char *)0x33))
#define OSCCN0 		(*((volatile unsigned char *)0x34))
#define OSCCN1 		(*((volatile unsigned char *)0x35))
#define OSCCN2 		(*((volatile unsigned char *)0x36))
#define CSFCN0 		(*((volatile unsigned char *)0x37))
#define CSFCN1 		(*((volatile unsigned char *)0x38))
#define WDTCN 		(*((volatile unsigned char *)0x39))
#define AD1H 		(*((volatile unsigned char *)0x3A))
#define AD1M 		(*((volatile unsigned char *)0x3B))
#define AD1L 		(*((volatile unsigned char *)0x3C))
#define AD1CN0 		(*((volatile unsigned char *)0x3D))
#define AD1CN1 		(*((volatile unsigned char *)0x3E))
#define AD1CN2 		(*((volatile unsigned char *)0x3F))
#define AD1CN3 		(*((volatile unsigned char *)0x40))
#define AD1CN4 		(*((volatile unsigned char *)0x41))
#define AD1CN5 		(*((volatile unsigned char *)0x42))
#define LVDCN 		(*((volatile unsigned char *)0x43))
#define TMA1CN 		(*((volatile unsigned char *)0x44))
#define TMA1R 		(*((volatile unsigned char *)0x45))
#define TMA1C 		(*((volatile unsigned char *)0x46))

#define PT1 		(*((volatile unsigned char *)0x47))
#define TRISC1 		(*((volatile unsigned char *)0x48))
#define PT1DA 		(*((volatile unsigned char *)0x49))
#define PT1PU 		(*((volatile unsigned char *)0x4A))
#define PT1M1 		(*((volatile unsigned char *)0x4B))

#define PT2 		(*((volatile unsigned char *)0x4C))
#define TRISC2 		(*((volatile unsigned char *)0x4D))
#define PT2DA 		(*((volatile unsigned char *)0x4E))
#define PT2PU 		(*((volatile unsigned char *)0x4F))

#define PT8 		(*((volatile unsigned char *)0x50))
#define TRISC8 		(*((volatile unsigned char *)0x51))
#define PT8DA 		(*((volatile unsigned char *)0x52))
#define PT8PU 		(*((volatile unsigned char *)0x53))

#define UR0CN 		(*((volatile unsigned char *)0x54))
#define UR0STA 		(*((volatile unsigned char *)0x55))
#define BA0CN 		(*((volatile unsigned char *)0x56))
#define BG0RH 		(*((volatile unsigned char *)0x57))
#define BG0RL 		(*((volatile unsigned char *)0x58))
#define TX0R 		(*((volatile unsigned char *)0x59))
#define RC0REG 		(*((volatile unsigned char *)0x5A))

#define LCDCN1 (*((volatile unsigned char *)0x5B))
#define LCDCN2 (*((volatile unsigned char *)0x5C))
#define LCDCN3 (*((volatile unsigned char *)0x5D)) /* COM0 ,COM1,COM2,COM3 register*/
#define LCDCN4 (*((volatile unsigned char *)0x5E))

#define LCD0 (*((volatile unsigned char *)0x5F))
#define LCD1 (*((volatile unsigned char *)0x60))
#define LCD2 (*((volatile unsigned char *)0x61))
#define LCD3 (*((volatile unsigned char *)0x62))
#define LCD4 (*((volatile unsigned char *)0x63))
#define LCD5 (*((volatile unsigned char *)0x64))
#define LCD6 (*((volatile unsigned char *)0x65))

#define Filter  (*((volatile unsigned char *)0x66))
#endif
