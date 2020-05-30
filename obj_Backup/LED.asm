;--------------------------------------------------------
; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
; Version 3.9.3 #4ad52972e (MSVC)
;--------------------------------------------------------
; Port for HYCON CPU
;--------------------------------------------------------
;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
;;	.file	"E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"
	.module LED
	;.list	p=HY17P52
	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
	;--cdb--F:LED:G$GetDisplay$0$0({2}DF,SC:U),C,0,0,0,0,0
	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:LED:G$LEDSetting$0$0({2}DF,SV:S),C,0,0,0,0,0
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
.area CCODE (code,REL,CON) ; LED-code 
.globl _GetDisplay

;--------------------------------------------------------
	.FUNC _GetDisplay:2:$L:r0x1141:$L:_GetDisplay_STK00:$L:r0x1143:$L:r0x1144
;--------------------------------------------------------
;	;.line	63; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRTemp=(RRTemp<<1);
_GetDisplay:	;Function start
	MVF	r0x1141,1,0
	BCF	_STATUS,4
	RLFC	r0x1141,0,0
	MVF	r0x1144,1,0
;	;.line	64; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR=(RRR<<ledx);
	SETF	r0x1143,0
	MVF	_GetDisplay_STK00,0,0
	SUBL	0x00
	BTSZ	_STATUS,0
	JMP	_00112_DS_
_00111_DS_:
	RLFC	r0x1143,1,0
	ADDL	0x01
	BTSS	_STATUS,4
	JMP	_00111_DS_
_00112_DS_:
;	;.line	65; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRTemp &= RRR;
	MVF	r0x1143,0,0
	ANDF	r0x1144,1,0
;	;.line	68; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR=RRR>>(8-ledx);
	MVF	_GetDisplay_STK00,0,0
	SUBL	0x08
	MVF	_GetDisplay_STK00,1,0
	SETF	r0x1143,0
	MVF	_GetDisplay_STK00,0,0
	SUBL	0x00
	BTSZ	_STATUS,0
	JMP	_00114_DS_
_00113_DS_:
	RRFC	r0x1143,1,0
	ADDL	0x01
	BTSS	_STATUS,4
	JMP	_00113_DS_
_00114_DS_:
;	;.line	69; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RLTemp &= RRR;
	MVF	r0x1143,0,0
	ANDF	r0x1141,1,0
;	;.line	70; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR= RLTemp | RRTemp;
	MVF	r0x1141,0,0
	IORF	r0x1144,1,0
;	;.line	72; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	return RRR;
	MVF	r0x1144,0,0
;	;.line	73; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	}
	RET	
; exit point of _GetDisplay
	.ENDFUNC	_GetDisplay
;--------------------------------------------------------

.globl _LEDSetting

;--------------------------------------------------------
	.FUNC _LEDSetting:1:$L:r0x113F
;--------------------------------------------------------
;	;.line	33; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	void LEDSetting(unsigned char cclevel)
_LEDSetting:	;Function start
	MVF	r0x113F,1,0
;	;.line	35; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	CCNT_CCLevelSel(cclevel);
	MVL	0xf8
	ANDF	_CCNT,0,0
	IORF	r0x113F,0,0
	MVF	_CCNT,1,0
;	;.line	36; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	ENCCALL_Enable();
	SETF	_ENCCMode,0
;	;.line	37; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	PT12DA=0x00;
	CLRF	_PT12DA,0
;	;.line	38; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	INTE2 |= 0x40;
	BSF	_INTE2,6
;	;.line	39; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	TMA2CN=0xc0;
	MVL	0xc0
	MVF	_TMA2CN,1,0
;	;.line	40; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	TMA2C=2;		     //Set Scan Rate
	MVL	0x02
	MVF	_TMA2C,1,0
;	;.line	41; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\LED.c"	}
	RET	
; exit point of _LEDSetting
	.ENDFUNC	_LEDSetting
;--------------------------------------------------------

	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$FSR0$0$0({2}DX,SC:U),E,0,0
	;--cdb--S:G$FSR1$0$0({2}DX,SC:U),E,0,0
	;--cdb--S:G$FSR2$0$0({2}DX,SC:U),E,0,0
	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTE2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTF2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTE3$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTF3$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1FLAG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1CN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1CN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1RH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1RL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C0H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C0L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C1H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C1L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C2H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TB1C2L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1CN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1CN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1R0H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1R0L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1R1H$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TC1R1L$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1M2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1INT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2INT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2INTE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2INTF$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4INT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4INTE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4INTF$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT12$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC12$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT12DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT12PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA2CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA2R$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TMA2C$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SSPCN0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SSPSTA0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SSPBUF0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CFG0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ACT0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$STA0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CRG0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TOC0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$RDB0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TDB0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SID0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CFG2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ACT2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$STA2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CRG2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TOC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$RDB2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TDB2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$SID2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR2CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR2STA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BA2CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG2RH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG2RL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TX2R$0$0({1}SC:U),I,0,0
	;--cdb--S:G$RC2REG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$CCNT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ENCCMode$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1AIE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2AIE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT4AIE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT6AIE$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
	;--cdb--S:LLED.LEDSetting._LEDSetting_cclevel_65536_3$cclevel$10000$3({1}SC:U),R,0,0,[r0x113F]
	;--cdb--S:LLED.GetDisplay._GetDisplay_ledx_65536_5$ledx$10000$5({1}SC:U),R,0,0,[_GetDisplay_STK00]
	;--cdb--S:LLED.GetDisplay._GetDisplay_show_65536_5$show$10000$5({1}SC:U),R,0,0,[r0x1141]
	;--cdb--S:LLED.GetDisplay._GetDisplay_RRTemp_65536_6$RRTemp$10000$6({1}SC:U),R,0,0,[r0x1144]
	;--cdb--S:LLED.GetDisplay._GetDisplay_RLTemp_65536_6$RLTemp$10000$6({1}SC:U),R,0,0,[r0x1141]
	;--cdb--S:LLED.GetDisplay._GetDisplay_RRR_65536_6$RRR$10000$6({1}SC:U),R,0,0,[r0x1143]
	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	.globl	_FSR0
	.globl	_FSR1
	.globl	_FSR2
	.globl	_ADCR

	.globl WSAVE
	.globl STK07
	.globl STK07_SAVE
	.globl STK06
	.globl STK06_SAVE
	.globl STK05
	.globl STK05_SAVE
	.globl STK04
	.globl STK04_SAVE
	.globl STK03
	.globl STK03_SAVE
	.globl STK02
	.globl STK02_SAVE
	.globl STK01
	.globl STK01_SAVE
	.globl STK00
	.globl STK00_SAVE
;--------------------------------------------------------
; global -1 declarations
;--------------------------------------------------------
	.globl	_GetDisplay
	.globl	_LEDSetting

	.globl	_memcpy
;--------------------------------------------------------
; global -2 definitions
;--------------------------------------------------------
	.area DSEG(DATA)
__SWTGTID	.equ	0x93E79486

	.area DSEG(DATA)
_INDF0	.equ	0x0

	.area DSEG(DATA)
_POINC0	.equ	0x1

	.area DSEG(DATA)
_PODEC0	.equ	0x2

	.area DSEG(DATA)
_PRINC0	.equ	0x3

	.area DSEG(DATA)
_PLUSW0	.equ	0x4

	.area DSEG(DATA)
_INDF1	.equ	0x5

	.area DSEG(DATA)
_POINC1	.equ	0x6

	.area DSEG(DATA)
_PODEC1	.equ	0x7

	.area DSEG(DATA)
_PRINC1	.equ	0x8

	.area DSEG(DATA)
_PLUSW1	.equ	0x9

	.area DSEG(DATA)
_INDF2	.equ	0xA

	.area DSEG(DATA)
_POINC2	.equ	0xB

	.area DSEG(DATA)
_PODEC2	.equ	0xC

	.area DSEG(DATA)
_PRINC2	.equ	0xD

	.area DSEG(DATA)
_PLUSW2	.equ	0xE

	.area DSEG(DATA)
_FSR0H	.equ	0xF

	.area DSEG(DATA)
_FSR0L	.equ	0x10

	.area DSEG(DATA)
_FSR1H	.equ	0x11

	.area DSEG(DATA)
_FSR1L	.equ	0x12

	.area DSEG(DATA)
_FSR2H	.equ	0x13

	.area DSEG(DATA)
_FSR2L	.equ	0x14

	.area DSEG(DATA)
_TOSH	.equ	0x16

	.area DSEG(DATA)
_TOSL	.equ	0x17

	.area DSEG(DATA)
_SKCN	.equ	0x18

	.area DSEG(DATA)
_PCLATH	.equ	0x1A

	.area DSEG(DATA)
_PCLATL	.equ	0x1B

	.area DSEG(DATA)
_TBLPTRH	.equ	0x1D

	.area DSEG(DATA)
_TBLPTRL	.equ	0x1E

	.area DSEG(DATA)
_TBLDH	.equ	0x1F

	.area DSEG(DATA)
_TBLDL	.equ	0x20

	.area DSEG(DATA)
_PRODH	.equ	0x21

	.area DSEG(DATA)
_PRODL	.equ	0x22

	.area DSEG(DATA)
_INTE0	.equ	0x23

	.area DSEG(DATA)
_INTE1	.equ	0x24

	.area DSEG(DATA)
_INTE2	.equ	0x25

	.area DSEG(DATA)
_INTF0	.equ	0x26

	.area DSEG(DATA)
_INTF1	.equ	0x27

	.area DSEG(DATA)
_INTF2	.equ	0x28

	.area DSEG(DATA)
_WREG	.equ	0x29

	.area DSEG(DATA)
_BSRCN	.equ	0x2A

	.area DSEG(DATA)
_STATUS	.equ	0x2B

	.area DSEG(DATA)
_MSTAT	.equ	0x2B

	.area DSEG(DATA)
_PSTAT	.equ	0x2C

	.area DSEG(DATA)
_INTE3	.equ	0x2E

	.area DSEG(DATA)
_INTF3	.equ	0x30

	.area DSEG(DATA)
_BIECN	.equ	0x31

	.area DSEG(DATA)
_BIEARL	.equ	0x33

	.area DSEG(DATA)
_BIEDRH	.equ	0x34

	.area DSEG(DATA)
_BIEDRL	.equ	0x35

	.area DSEG(DATA)
_PWRCN	.equ	0x36

	.area DSEG(DATA)
_OSCCN0	.equ	0x37

	.area DSEG(DATA)
_OSCCN1	.equ	0x38

	.area DSEG(DATA)
_OSCCN2	.equ	0x39

	.area DSEG(DATA)
_CSFCN0	.equ	0x3A

	.area DSEG(DATA)
_CSFCN1	.equ	0x3B

	.area DSEG(DATA)
_WDTCN	.equ	0x3E

	.area DSEG(DATA)
_AD1H	.equ	0x3F

	.area DSEG(DATA)
_AD1M	.equ	0x40

	.area DSEG(DATA)
_AD1L	.equ	0x41

	.area DSEG(DATA)
_AD1CN0	.equ	0x42

	.area DSEG(DATA)
_AD1CN1	.equ	0x43

	.area DSEG(DATA)
_AD1CN2	.equ	0x44

	.area DSEG(DATA)
_AD1CN3	.equ	0x45

	.area DSEG(DATA)
_AD1CN4	.equ	0x46

	.area DSEG(DATA)
_AD1CN5	.equ	0x47

	.area DSEG(DATA)
_LVDCN	.equ	0x48

	.area DSEG(DATA)
_TMA1CN	.equ	0x49

	.area DSEG(DATA)
_TMA1R	.equ	0x4A

	.area DSEG(DATA)
_TMA1C	.equ	0x4B

	.area DSEG(DATA)
_TB1FLAG	.equ	0x4C

	.area DSEG(DATA)
_TB1CN0	.equ	0x4D

	.area DSEG(DATA)
_TB1CN1	.equ	0x4E

	.area DSEG(DATA)
_TB1RH	.equ	0x4F

	.area DSEG(DATA)
_TB1RL	.equ	0x50

	.area DSEG(DATA)
_TB1C0H	.equ	0x51

	.area DSEG(DATA)
_TB1C0L	.equ	0x52

	.area DSEG(DATA)
_TB1C1H	.equ	0x53

	.area DSEG(DATA)
_TB1C1L	.equ	0x54

	.area DSEG(DATA)
_TB1C2H	.equ	0x55

	.area DSEG(DATA)
_TB1C2L	.equ	0x56

	.area DSEG(DATA)
_TC1CN0	.equ	0x57

	.area DSEG(DATA)
_TC1CN1	.equ	0x58

	.area DSEG(DATA)
_TC1R0H	.equ	0x59

	.area DSEG(DATA)
_TC1R0L	.equ	0x5A

	.area DSEG(DATA)
_TC1R1H	.equ	0x5B

	.area DSEG(DATA)
_TC1R1L	.equ	0x5C

	.area DSEG(DATA)
_PT1	.equ	0x5D

	.area DSEG(DATA)
_TRISC1	.equ	0x5E

	.area DSEG(DATA)
_PT1DA	.equ	0x5F

	.area DSEG(DATA)
_PT1PU	.equ	0x60

	.area DSEG(DATA)
_PT1M1	.equ	0x61

	.area DSEG(DATA)
_PT1M2	.equ	0x62

	.area DSEG(DATA)
_PT1INT	.equ	0x63

	.area DSEG(DATA)
_PT2	.equ	0x64

	.area DSEG(DATA)
_TRISC2	.equ	0x65

	.area DSEG(DATA)
_PT2DA	.equ	0x66

	.area DSEG(DATA)
_PT2PU	.equ	0x67

	.area DSEG(DATA)
_PT2INT	.equ	0x6A

	.area DSEG(DATA)
_PT2INTE	.equ	0x6B

	.area DSEG(DATA)
_PT2INTF	.equ	0x6C

	.area DSEG(DATA)
_PT4	.equ	0x6D

	.area DSEG(DATA)
_PT4DA	.equ	0x6F

	.area DSEG(DATA)
_PT4PU	.equ	0x70

	.area DSEG(DATA)
_PT4INT	.equ	0x73

	.area DSEG(DATA)
_PT4INTE	.equ	0x74

	.area DSEG(DATA)
_PT4INTF	.equ	0x75

	.area DSEG(DATA)
_PT12	.equ	0x76

	.area DSEG(DATA)
_TRISC12	.equ	0x77

	.area DSEG(DATA)
_PT12DA	.equ	0x78

	.area DSEG(DATA)
_PT12PU	.equ	0x79

	.area DSEG(DATA)
_TMA2CN	.equ	0x7A

	.area DSEG(DATA)
_TMA2R	.equ	0x7B

	.area DSEG(DATA)
_TMA2C	.equ	0x7C

	.area DSEG(DATA)
_SSPCN0	.equ	0x7D

	.area DSEG(DATA)
_SSPSTA0	.equ	0x7E

	.area DSEG(DATA)
_SSPBUF0	.equ	0x7F

	.area DSEG(DATA)
_CFG0	.equ	0x180

	.area DSEG(DATA)
_ACT0	.equ	0x181

	.area DSEG(DATA)
_STA0	.equ	0x182

	.area DSEG(DATA)
_CRG0	.equ	0x183

	.area DSEG(DATA)
_TOC0	.equ	0x184

	.area DSEG(DATA)
_RDB0	.equ	0x185

	.area DSEG(DATA)
_TDB0	.equ	0x186

	.area DSEG(DATA)
_SID0	.equ	0x187

	.area DSEG(DATA)
_CFG2	.equ	0x188

	.area DSEG(DATA)
_ACT2	.equ	0x189

	.area DSEG(DATA)
_STA2	.equ	0x18A

	.area DSEG(DATA)
_CRG2	.equ	0x18B

	.area DSEG(DATA)
_TOC2	.equ	0x18C

	.area DSEG(DATA)
_RDB2	.equ	0x18D

	.area DSEG(DATA)
_TDB2	.equ	0x18E

	.area DSEG(DATA)
_SID2	.equ	0x18F

	.area DSEG(DATA)
_UR0CN	.equ	0x190

	.area DSEG(DATA)
_UR0STA	.equ	0x191

	.area DSEG(DATA)
_BA0CN	.equ	0x192

	.area DSEG(DATA)
_BG0RH	.equ	0x193

	.area DSEG(DATA)
_BG0RL	.equ	0x194

	.area DSEG(DATA)
_TX0R	.equ	0x195

	.area DSEG(DATA)
_RC0REG	.equ	0x196

	.area DSEG(DATA)
_UR2CN	.equ	0x197

	.area DSEG(DATA)
_UR2STA	.equ	0x198

	.area DSEG(DATA)
_BA2CN	.equ	0x199

	.area DSEG(DATA)
_BG2RH	.equ	0x19A

	.area DSEG(DATA)
_BG2RL	.equ	0x19B

	.area DSEG(DATA)
_TX2R	.equ	0x19C

	.area DSEG(DATA)
_RC2REG	.equ	0x19D

	.area DSEG(DATA)
_CCNT	.equ	0x19E

	.area DSEG(DATA)
_ENCCMode	.equ	0x19F

	.area DSEG(DATA)
_PT1AIE	.equ	0x1B0

	.area DSEG(DATA)
_PT2AIE	.equ	0x1B1

	.area DSEG(DATA)
_PT4AIE	.equ	0x1B3

	.area DSEG(DATA)
_PT6AIE	.equ	0x1B5

	.area DSEG(DATA)
_ADCRH	.equ	0x3F

	.area DSEG(DATA)
_ADCRM	.equ	0x40

	.area DSEG(DATA)
_ADCRL	.equ	0x41

;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
	.area IDATA (DATA,REL,CON); pre-def
	.area IDATAROM (CODE,REL,CON); pre-def
	.area UDATA (DATA,REL,CON); pre-def
	.area UDATA (DATA,REL,CON) ;UDL_LED_0	udata
r0x113F:	.ds	1
r0x1141:	.ds	1
r0x1143:	.ds	1
r0x1144:	.ds	1
	.area LOCALSTK (STK); local stack var
_GetDisplay_STK00:	.ds	1
	.globl _GetDisplay_STK00
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized data - mirror
;--------------------------------------------------------
	;Following is optimization info, 
	;xxcdbxxW:dst:src+offset:srclit:just-remove
	;--cdb--W:r0x1143:r0x1141+0:-1:0
	;--cdb--W:r0x1141:NULL+0:-1:1
	;--cdb--W:r0x1140:NULL+0:-1:1
	end
