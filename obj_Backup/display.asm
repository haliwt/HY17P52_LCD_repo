;--------------------------------------------------------
; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
; Version 3.9.3 #4ad52972e (MSVC)
;--------------------------------------------------------
; Port for HYCON CPU
;--------------------------------------------------------
;	;CCFROM:"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft"
;;	.file	".\display.c"
	.module display
	;.list	p=HY17P52
	;--cdb--T:Fdisplay$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_PositiveDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_PositiveDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({9}S:S$eepromRead_NegativeDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({10}S:S$eepromRead_NegativeDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({11}S:S$eepromRead_UnithHigh_bit$0$0({1}SC:U),Z,0,0)({12}S:S$eepromRead_UnitLow_bit$0$0({1}SC:U),Z,0,0)({13}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({14}S:S$delayTimes_5$0$0({2}SI:U),Z,0,0)({16}S:S$delayTimes_3$0$0({2}SI:U),Z,0,0)({18}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({20}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
	;--cdb--F:display:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0,0,0,0
	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$Delay$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$Display2Er$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayHex$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayNum$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$ClearLCD$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:display:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$_modslong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$_divslong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
.area CCODE (code,REL,CON) ; display-code 
.globl _DispalyBatteryCapacityLow

;--------------------------------------------------------
	.FUNC _DispalyBatteryCapacityLow:0
;--------------------------------------------------------
;	;.line	204; ".\display.c"	LCD_WriteData(&LCD0,0x90);
_DispalyBatteryCapacityLow:	;Function start
	MVL	0x90
	MVF	_LCD0,1,0
;	;.line	206; ".\display.c"	}
	RET	
; exit point of _DispalyBatteryCapacityLow
	.ENDFUNC	_DispalyBatteryCapacityLow
;--------------------------------------------------------

.globl _DisplayBatteryCapacityHalf

;--------------------------------------------------------
	.FUNC _DisplayBatteryCapacityHalf:0
;--------------------------------------------------------
;	;.line	193; ".\display.c"	LCD_WriteData(&LCD0,0xd0);
_DisplayBatteryCapacityHalf:	;Function start
	MVL	0xd0
	MVF	_LCD0,1,0
;	;.line	195; ".\display.c"	}
	RET	
; exit point of _DisplayBatteryCapacityHalf
	.ENDFUNC	_DisplayBatteryCapacityHalf
;--------------------------------------------------------

.globl _DisplayBatteryCapacityFull

;--------------------------------------------------------
	.FUNC _DisplayBatteryCapacityFull:0
;--------------------------------------------------------
;	;.line	183; ".\display.c"	LCD_WriteData(&LCD0,0xff);
_DisplayBatteryCapacityFull:	;Function start
	SETF	_LCD0,0
;	;.line	184; ".\display.c"	}
	RET	
; exit point of _DisplayBatteryCapacityFull
	.ENDFUNC	_DisplayBatteryCapacityFull
;--------------------------------------------------------

.globl _DisplayLLL

;--------------------------------------------------------
	.FUNC _DisplayLLL:0
;--------------------------------------------------------
;	;.line	167; ".\display.c"	LCD_WriteData(&LCD0,0x00);
_DisplayLLL:	;Function start
	CLRF	_LCD0,0
;	;.line	168; ".\display.c"	LCD_WriteData(&LCD1,Char_L);
	MVL	0x70
	MVF	_LCD1,1,0
;	;.line	169; ".\display.c"	LCD_WriteData(&LCD2,Char_L);
	MVF	_LCD2,1,0
;	;.line	170; ".\display.c"	LCD_WriteData(&LCD3,Char_L); 
	MVF	_LCD3,1,0
;	;.line	172; ".\display.c"	}
	RET	
; exit point of _DisplayLLL
	.ENDFUNC	_DisplayLLL
;--------------------------------------------------------

.globl _DisplayHHH

;--------------------------------------------------------
	.FUNC _DisplayHHH:0
;--------------------------------------------------------
;	;.line	152; ".\display.c"	LCD_WriteData(&LCD0,0x00);
_DisplayHHH:	;Function start
	CLRF	_LCD0,0
;	;.line	153; ".\display.c"	LCD_WriteData(&LCD1,Char_H );
	MVL	0x6e
	MVF	_LCD1,1,0
;	;.line	154; ".\display.c"	LCD_WriteData(&LCD2,Char_H );
	MVF	_LCD2,1,0
;	;.line	155; ".\display.c"	LCD_WriteData(&LCD3,Char_H ); 
	MVF	_LCD3,1,0
;	;.line	157; ".\display.c"	}
	RET	
; exit point of _DisplayHHH
	.ENDFUNC	_DisplayHHH
;--------------------------------------------------------

.globl _Reverse_Data

;--------------------------------------------------------
	.FUNC _Reverse_Data:4:$C:__mullong:$C:__modslong:$C:___slong2fs:$C:___fsmul\
:$C:___fs2slong\
:$L:r0x116B:$L:_Reverse_Data_STK00:$L:_Reverse_Data_STK01:$L:_Reverse_Data_STK02:$L:r0x116C\
:$L:r0x116D:$L:r0x116E:$L:r0x116F:$L:r0x1173:$L:r0x1172\
:$L:r0x1171:$L:r0x1170:$L:r0x1177
;--------------------------------------------------------
;	;.line	133; ".\display.c"	long Reverse_Data(long number)
_Reverse_Data:	;Function start
	MVF	r0x116B,1,0
;	;.line	135; ".\display.c"	long tmp=0;
	CLRF	r0x116C,0
	CLRF	r0x116D,0
	CLRF	r0x116E,0
	CLRF	r0x116F,0
_00152_DS_:
;	;.line	136; ".\display.c"	while(number!=0)
	MVF	_Reverse_Data_STK02,0,0
	IORF	_Reverse_Data_STK01,0,0
	IORF	_Reverse_Data_STK00,0,0
	IORF	r0x116B,0,0
	BTSZ	_STATUS,0
	JMP	_00154_DS_
;	;.line	138; ".\display.c"	tmp=(tmp*10 + number%10);
	MVF	r0x116C,0,0
	MVF	__mullong_STK06,1,0
	MVF	r0x116D,0,0
	MVF	__mullong_STK05,1,0
	MVF	r0x116E,0,0
	MVF	__mullong_STK04,1,0
	MVF	r0x116F,0,0
	MVF	__mullong_STK03,1,0
	MVL	0x0a
	MVF	__mullong_STK02,1,0
	CLRF	__mullong_STK01,0
	CLRF	__mullong_STK00,0
	MVL	0x00
	CALL	__mullong
	.CHKPARA __mullong 8
	MVF	r0x1173,1,0
	MVF	STK00,0,0
	MVF	r0x1172,1,0
	MVF	STK01,0,0
	MVF	r0x1171,1,0
	MVF	STK02,0,0
	MVF	r0x1170,1,0
	MVL	0x0a
	MVF	__modslong_STK06,1,0
	CLRF	__modslong_STK05,0
	CLRF	__modslong_STK04,0
	CLRF	__modslong_STK03,0
	MVF	_Reverse_Data_STK02,0,0
	MVF	__modslong_STK02,1,0
	MVF	_Reverse_Data_STK01,0,0
	MVF	__modslong_STK01,1,0
	MVF	_Reverse_Data_STK00,0,0
	MVF	__modslong_STK00,1,0
	MVF	r0x116B,0,0
	CALL	__modslong
	.CHKPARA __modslong 8
	MVF	r0x1177,1,0
	MVF	STK02,0,0
	ADDF	r0x1170,0,0
	MVF	r0x116C,1,0
	MVF	r0x1171,0,0
	ADDC	STK01,0,0
	MVF	r0x116D,1,0
	MVF	r0x1172,0,0
	ADDC	STK00,0,0
	MVF	r0x116E,1,0
	MVF	r0x1173,0,0
	ADDC	r0x1177,0,0
	MVF	r0x116F,1,0
;	;.line	139; ".\display.c"	number=number*0.1;
	MVF	_Reverse_Data_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_Reverse_Data_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_Reverse_Data_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x116B,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1173,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1173,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1173,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1173,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x116B,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK02,0,0
	MVF	_Reverse_Data_STK02,1,0
	JMP	_00152_DS_
_00154_DS_:
;	;.line	141; ".\display.c"	if(number<0) return (-tmp);
	BTSS	r0x116B,7
	JMP	_00156_DS_
	COMF	r0x116C,0,0
	MVF	STK02,1,0
	COMF	r0x116D,0,0
	MVF	STK01,1,0
	COMF	r0x116E,0,0
	MVF	STK00,1,0
	COMF	r0x116F,0,0
	MVF	r0x116B,1,0
	INF	STK02,1,0
	MVL	0x00
	ADDC	STK01,1,0
	ADDC	STK00,1,0
	ADDC	r0x116B,0,0
	JMP	_00158_DS_
_00156_DS_:
;	;.line	142; ".\display.c"	else return tmp;
	MVF	r0x116C,0,0
	MVF	STK02,1,0
	MVF	r0x116D,0,0
	MVF	STK01,1,0
	MVF	r0x116E,0,0
	MVF	STK00,1,0
	MVF	r0x116F,0,0
_00158_DS_:
;	;.line	143; ".\display.c"	}
	RET	
; exit point of _Reverse_Data
	.ENDFUNC	_Reverse_Data
;--------------------------------------------------------

.globl _Delay

;--------------------------------------------------------
	.FUNC _Delay:2:$L:r0x1166:$L:_Delay_STK00
;--------------------------------------------------------
;	;.line	122; ".\display.c"	void Delay(unsigned int ms)
_Delay:	;Function start
	MVF	r0x1166,1,0
_00145_DS_:
;	;.line	124; ".\display.c"	for(;ms>0;ms--)
	MVF	_Delay_STK00,0,0
	IORF	r0x1166,0,0
	BTSZ	_STATUS,0
	JMP	_00147_DS_
;	;.line	125; ".\display.c"	 ..asm
	NOP
;	;.line	124; ".\display.c"	for(;ms>0;ms--)
	DCF	_Delay_STK00,1,0
	INSUZ	_Delay_STK00,0,0
	DCF	r0x1166,1,0
	JMP	_00145_DS_
_00147_DS_:
;	;.line	126; ".\display.c"	}
	RET	
; exit point of _Delay
	.ENDFUNC	_Delay
;--------------------------------------------------------

.globl _DisplayUnit

;--------------------------------------------------------
	.FUNC _DisplayUnit:0
;--------------------------------------------------------
;	;.line	114; ".\display.c"	LCD_WriteData(&LCD0,0x00);
_DisplayUnit:	;Function start
	CLRF	_LCD0,0
;	;.line	115; ".\display.c"	LCD_WriteData(&LCD1,Char_I);
	MVL	0x02
	MVF	_LCD1,1,0
;	;.line	116; ".\display.c"	LCD_WriteData(&LCD2,Char_N);
	MVL	0x26
	MVF	_LCD2,1,0
;	;.line	117; ".\display.c"	LCD_WriteData(&LCD3,Char_CAP_U); 
	MVL	0x7a
	MVF	_LCD3,1,0
;	;.line	118; ".\display.c"	}
	RET	
; exit point of _DisplayUnit
	.ENDFUNC	_DisplayUnit
;--------------------------------------------------------

.globl _Display2Er

;--------------------------------------------------------
	.FUNC _Display2Er:0
;--------------------------------------------------------
;	;.line	98; ".\display.c"	LCD_WriteData(&LCD0,0x00);
_Display2Er:	;Function start
	CLRF	_LCD0,0
;	;.line	99; ".\display.c"	LCD_WriteData(&LCD3,Char_2);
	MVL	0xbc
	MVF	_LCD3,1,0
;	;.line	100; ".\display.c"	LCD_WriteData(&LCD2,Char_E);
	MVL	0xf4
	MVF	_LCD2,1,0
;	;.line	101; ".\display.c"	LCD_WriteData(&LCD1,Char_R);   
	MVL	0x24
	MVF	_LCD1,1,0
;	;.line	104; ".\display.c"	}
	RET	
; exit point of _Display2Er
	.ENDFUNC	_Display2Er
;--------------------------------------------------------

.globl _DisplayHex

;--------------------------------------------------------
	.FUNC _DisplayHex:2
;--------------------------------------------------------
;	;.line	88; ".\display.c"	}
_DisplayHex:	;Function start
	RET	
; exit point of _DisplayHex
	.ENDFUNC	_DisplayHex
;--------------------------------------------------------

.globl _DisplayNum

;--------------------------------------------------------
	.FUNC _DisplayNum:4:$C:__modslong:$C:__g2ptrget1:$C:__g2ptrput1:$C:__divslong\
:$L:r0x1146:$L:_DisplayNum_STK00:$L:_DisplayNum_STK01:$L:_DisplayNum_STK02:$L:r0x1147\
:$L:r0x1148:$L:r0x1149:$L:r0x114A
;--------------------------------------------------------
;	;.line	61; ".\display.c"	void DisplayNum(long Num)
_DisplayNum:	;Function start
	MVF	r0x1146,1,0
;	;.line	66; ".\display.c"	LCDAddr=&LCD3;
	MVL	(_LCD3 + 0)
	MVF	r0x1147,1,0
	MVL	high (_LCD3 + 0)
	MVF	r0x1148,1,0
;	;.line	67; ".\display.c"	for(count=1;count<4;count++)
	MVL	0x03
	MVF	r0x1149,1,0
_00125_DS_:
;	;.line	69; ".\display.c"	LCDData=seg[Num%10];
	MVL	0x0a
	MVF	__modslong_STK06,1,0
	CLRF	__modslong_STK05,0
	CLRF	__modslong_STK04,0
	CLRF	__modslong_STK03,0
	MVF	_DisplayNum_STK02,0,0
	MVF	__modslong_STK02,1,0
	MVF	_DisplayNum_STK01,0,0
	MVF	__modslong_STK01,1,0
	MVF	_DisplayNum_STK00,0,0
	MVF	__modslong_STK00,1,0
	MVF	r0x1146,0,0
	CALL	__modslong
	MVF	STK02,0,0
	ADDL	(_seg + 0)
	MVF	r0x114A,1,0
	MVL	high (_seg + 0)
	ADDC	STK01,0,0
	MVSF	r0x114A,__g2ptrget1_STK00
	IORL	0x80
	CALL	__g2ptrget1
;	;.line	70; ".\display.c"	LCD_WriteData(LCDAddr,LCDData);
	MVF	__g2ptrput1_STK01,1,0
	MVF	r0x1147,0,0
	MVF	__g2ptrput1_STK00,1,0
	MVF	r0x1148,0,0
	CALL	__g2ptrput1
;	;.line	71; ".\display.c"	Num=Num/10 ;
	MVL	0x0a
	MVF	__divslong_STK06,1,0
	CLRF	__divslong_STK05,0
	CLRF	__divslong_STK04,0
	CLRF	__divslong_STK03,0
	MVF	_DisplayNum_STK02,0,0
	MVF	__divslong_STK02,1,0
	MVF	_DisplayNum_STK01,0,0
	MVF	__divslong_STK01,1,0
	MVF	_DisplayNum_STK00,0,0
	MVF	__divslong_STK00,1,0
	MVF	r0x1146,0,0
	CALL	__divslong
	.CHKPARA __divslong 8
	MVF	r0x1146,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
;	;.line	72; ".\display.c"	LCDAddr--;
	DCF	r0x1147,1,0
	INSUZ	r0x1147,0,0
	DCF	r0x1148,1,0
	DCSZ	r0x1149,1,0
;	;.line	67; ".\display.c"	for(count=1;count<4;count++)
	JMP	_00125_DS_
;	;.line	75; ".\display.c"	if(adS.Pressure_sign==1)
	BTSS	(_adS+6),6
	JMP	_00121_DS_
;	;.line	76; ".\display.c"	LCD_WriteData(&LCD0,0X08);
	MVL	0x08
	MVF	_LCD0,1,0
	JMP	_00126_DS_
_00121_DS_:
;	;.line	78; ".\display.c"	LCD_WriteData(&LCD0,0);
	CLRF	_LCD0,0
_00126_DS_:
;	;.line	80; ".\display.c"	}
	RET	
; exit point of _DisplayNum
	.ENDFUNC	_DisplayNum
;--------------------------------------------------------

.globl _DisplayHycon

;--------------------------------------------------------
	.FUNC _DisplayHycon:0
;--------------------------------------------------------
;	;.line	43; ".\display.c"	LCD_WriteData(&LCD0,0x00);
_DisplayHycon:	;Function start
	CLRF	_LCD0,0
;	;.line	44; ".\display.c"	LCD_WriteData(&LCD1,Char_L);
	MVL	0x70
	MVF	_LCD1,1,0
;	;.line	45; ".\display.c"	LCD_WriteData(&LCD2,Char_L);
	MVF	_LCD2,1,0
;	;.line	46; ".\display.c"	LCD_WriteData(&LCD3,Char_L);   /*HY17P52 com3 */
	MVF	_LCD3,1,0
;	;.line	47; ".\display.c"	LCD_WriteData(&LCD4,Char_L);
	MVF	_LCD4,1,0
;	;.line	48; ".\display.c"	LCD_WriteData(&LCD5,Char_L);
	MVF	_LCD5,1,0
;	;.line	49; ".\display.c"	LCD_WriteData(&LCD6,0x00);
	CLRF	_LCD6,0
;	;.line	50; ".\display.c"	}
	RET	
; exit point of _DisplayHycon
	.ENDFUNC	_DisplayHycon
;--------------------------------------------------------

.globl _ClearLCD

;--------------------------------------------------------
	.FUNC _ClearLCD:0:$L:r0x1140
;--------------------------------------------------------
_ClearLCD:	;Function start
	LDPR	(_LCD0 + 0),0
;	;.line	30; ".\display.c"	for(count=6;count>0;count--)
	MVL	0x06
	MVF	r0x1140,1,0
_00110_DS_:
;	;.line	31; ".\display.c"	POINC0=0;
	CLRF	_POINC0,0
;	;.line	30; ".\display.c"	for(count=6;count>0;count--)
	DCSZ	r0x1140,1,0
	JMP	_00110_DS_
;	;.line	32; ".\display.c"	}
	RET	
; exit point of _ClearLCD
	.ENDFUNC	_ClearLCD
;--------------------------------------------------------

.globl _GPIO_Iint

;--------------------------------------------------------
	.FUNC _GPIO_Iint:0
;--------------------------------------------------------
;	;.line	14; ".\display.c"	GPIO_PT15_OUTUT();  // SETTING PT4.4 OUTPUT
_GPIO_Iint:	;Function start
	MVL	0xdf
	ANDF	_TRISC1,0,0
	IORL	0x20
	MVF	_TRISC1,1,0
;	;.line	15; ".\display.c"	GPIO_PT16_OUTUT();  // SETTING PT4.3 OUTPUT
	MVL	0xbf
	ANDF	_TRISC1,0,0
	IORL	0x40
	MVF	_TRISC1,1,0
;	;.line	17; ".\display.c"	GPIO_PT10_INPUT();
	BCF	_TRISC1,0
;	;.line	18; ".\display.c"	}
	RET	
; exit point of _GPIO_Iint
	.ENDFUNC	_GPIO_Iint
;--------------------------------------------------------

	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$_modslong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$_divslong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
	;--cdb--S:G$adS$0$0({22}ST_adc_works_:S),E,0,0
	;--cdb--S:G$seg$0$0({29}DA29d,SC:U),D,0,0
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
	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BIEARH$0$0({1}SC:U),I,0,0
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
	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT8$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TRISC8$0$0({1}SC:U),I,0,0
	;--cdb--S:G$PT8PU$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCDCN1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCDCN2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCDCN3$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCDCN4$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD0$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD1$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD2$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD3$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD4$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD5$0$0({1}SC:U),I,0,0
	;--cdb--S:G$LCD6$0$0({1}SC:U),I,0,0
	;--cdb--S:G$Filter$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
	;--cdb--S:Ldisplay.ClearLCD._ClearLCD_count_65536_18$count$10000$18({1}SC:U),R,0,0,[r0x1140]
	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_Num_65536_22$Num$10000$22({4}SL:SL),R,0,0,[_DisplayNum_STK02,_DisplayNum_STK01,_DisplayNum_STK00,r0x1146]
	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_count_65536_23$count$10000$23({1}SC:U),R,0,0,[r0x1149]
	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_MINUS_65536_23$MINUS$10000$23({1}SC:U),E,0,0
	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_LCDAddr_65536_23$LCDAddr$10000$23({2}DT,SC:U),R,0,0,[]
	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_LCDData_65536_23$LCDData$10000$23({1}SC:U),R,0,0,[r0x114E]
	;--cdb--S:Ldisplay.DisplayHex._DisplayHex_Num_65536_26$Num$10000$26({2}SI:U),R,0,0,[]
	;--cdb--S:Ldisplay.Delay._Delay_ms_65536_33$ms$10000$33({2}SI:U),R,0,0,[_Delay_STK00,r0x1166]
	;--cdb--S:Ldisplay.Reverse_Data._Reverse_Data_number_65536_36$number$10000$36({4}SL:SL),R,0,0,[_Reverse_Data_STK02,_Reverse_Data_STK01,_Reverse_Data_STK00,r0x116B]
	;--cdb--S:Ldisplay.Reverse_Data._Reverse_Data_tmp_65536_37$tmp$10000$37({4}SL:SL),R,0,0,[r0x116C,r0x116D,r0x116E,r0x116F]
	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
	;--cdb--S:G$_POINC0$0$0({0}:U),Z,0,0
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	.globl	__modslong
	.globl	__divslong
	.globl	__mullong
	.globl	___slong2fs
	.globl	___fsmul
	.globl	___fs2slong
	.globl	_FSR0
	.globl	_FSR1
	.globl	_FSR2
	.globl	_ADCR
	.globl	__g2ptrget1
	.globl	__g2ptrput1

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
	.globl	_Reverse_Data
	.globl	_Delay
	.globl	_DisplayHex
	.globl	_DisplayNum
	.globl	_adS
	.globl	_seg

	.globl	_memcpy
;--------------------------------------------------------
; global -2 definitions
;--------------------------------------------------------
	.area DSEG(DATA)
_adS:	.ds	22

	.area DSEG(DATA)
__SWTGTID	.equ	0xA43354DA

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
_INTF0	.equ	0x26

	.area DSEG(DATA)
_INTF1	.equ	0x27

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
_BIECN	.equ	0x2E

	.area DSEG(DATA)
_BIEARH	.equ	0x2F

	.area DSEG(DATA)
_BIEARL	.equ	0x30

	.area DSEG(DATA)
_BIEDRH	.equ	0x31

	.area DSEG(DATA)
_BIEDRL	.equ	0x32

	.area DSEG(DATA)
_PWRCN	.equ	0x33

	.area DSEG(DATA)
_OSCCN0	.equ	0x34

	.area DSEG(DATA)
_OSCCN1	.equ	0x35

	.area DSEG(DATA)
_OSCCN2	.equ	0x36

	.area DSEG(DATA)
_CSFCN0	.equ	0x37

	.area DSEG(DATA)
_CSFCN1	.equ	0x38

	.area DSEG(DATA)
_WDTCN	.equ	0x39

	.area DSEG(DATA)
_AD1H	.equ	0x3A

	.area DSEG(DATA)
_AD1M	.equ	0x3B

	.area DSEG(DATA)
_AD1L	.equ	0x3C

	.area DSEG(DATA)
_AD1CN0	.equ	0x3D

	.area DSEG(DATA)
_AD1CN1	.equ	0x3E

	.area DSEG(DATA)
_AD1CN2	.equ	0x3F

	.area DSEG(DATA)
_AD1CN3	.equ	0x40

	.area DSEG(DATA)
_AD1CN4	.equ	0x41

	.area DSEG(DATA)
_AD1CN5	.equ	0x42

	.area DSEG(DATA)
_LVDCN	.equ	0x43

	.area DSEG(DATA)
_TMA1CN	.equ	0x44

	.area DSEG(DATA)
_TMA1R	.equ	0x45

	.area DSEG(DATA)
_TMA1C	.equ	0x46

	.area DSEG(DATA)
_PT1	.equ	0x47

	.area DSEG(DATA)
_TRISC1	.equ	0x48

	.area DSEG(DATA)
_PT1DA	.equ	0x49

	.area DSEG(DATA)
_PT1PU	.equ	0x4A

	.area DSEG(DATA)
_PT1M1	.equ	0x4B

	.area DSEG(DATA)
_PT2	.equ	0x4C

	.area DSEG(DATA)
_TRISC2	.equ	0x4D

	.area DSEG(DATA)
_PT2DA	.equ	0x4E

	.area DSEG(DATA)
_PT2PU	.equ	0x4F

	.area DSEG(DATA)
_PT8	.equ	0x50

	.area DSEG(DATA)
_TRISC8	.equ	0x51

	.area DSEG(DATA)
_PT8PU	.equ	0x53

	.area DSEG(DATA)
_UR0CN	.equ	0x54

	.area DSEG(DATA)
_UR0STA	.equ	0x55

	.area DSEG(DATA)
_BA0CN	.equ	0x56

	.area DSEG(DATA)
_BG0RH	.equ	0x57

	.area DSEG(DATA)
_BG0RL	.equ	0x58

	.area DSEG(DATA)
_TX0R	.equ	0x59

	.area DSEG(DATA)
_RC0REG	.equ	0x5A

	.area DSEG(DATA)
_LCDCN1	.equ	0x5B

	.area DSEG(DATA)
_LCDCN2	.equ	0x5C

	.area DSEG(DATA)
_LCDCN3	.equ	0x5D

	.area DSEG(DATA)
_LCDCN4	.equ	0x5E

	.area DSEG(DATA)
_LCD0	.equ	0x5F

	.area DSEG(DATA)
_LCD1	.equ	0x60

	.area DSEG(DATA)
_LCD2	.equ	0x61

	.area DSEG(DATA)
_LCD3	.equ	0x62

	.area DSEG(DATA)
_LCD4	.equ	0x63

	.area DSEG(DATA)
_LCD5	.equ	0x64

	.area DSEG(DATA)
_LCD6	.equ	0x65

	.area DSEG(DATA)
_Filter	.equ	0x66

	.area DSEG(DATA)
_ADCRH	.equ	0x3A

	.area DSEG(DATA)
_ADCRM	.equ	0x3B

	.area DSEG(DATA)
_ADCRL	.equ	0x3C

;--------------------------------------------------------
; absolute symbol definitions
;--------------------------------------------------------
;--------------------------------------------------------
; compiler-defined variables
;--------------------------------------------------------
	.area IDATA (DATA,REL,CON); pre-def
	.area IDATAROM (CODE,REL,CON); pre-def
	.area UDATA (DATA,REL,CON); pre-def
	.area UDATA (DATA,REL,CON) ;UDL_display_0	udata
r0x1140:	.ds	1
r0x1146:	.ds	1
r0x1147:	.ds	1
r0x1148:	.ds	1
r0x1149:	.ds	1
r0x114A:	.ds	1
r0x1166:	.ds	1
r0x116B:	.ds	1
r0x116C:	.ds	1
r0x116D:	.ds	1
r0x116E:	.ds	1
r0x116F:	.ds	1
r0x1170:	.ds	1
r0x1171:	.ds	1
r0x1172:	.ds	1
r0x1173:	.ds	1
r0x1177:	.ds	1
	.area LOCALSTK (STK); local stack var
_DisplayNum_STK00:	.ds	1
	.globl _DisplayNum_STK00
_DisplayNum_STK01:	.ds	1
	.globl _DisplayNum_STK01
_DisplayNum_STK02:	.ds	1
	.globl _DisplayNum_STK02
	.globl __modslong_STK06
	.globl __modslong_STK05
	.globl __modslong_STK04
	.globl __modslong_STK03
	.globl __modslong_STK02
	.globl __modslong_STK01
	.globl __modslong_STK00
	.globl __g2ptrget1_STK00
	.globl __g2ptrput1_STK01
	.globl __g2ptrput1_STK00
	.globl __divslong_STK06
	.globl __divslong_STK05
	.globl __divslong_STK04
	.globl __divslong_STK03
	.globl __divslong_STK02
	.globl __divslong_STK01
	.globl __divslong_STK00
_Delay_STK00:	.ds	1
	.globl _Delay_STK00
_Reverse_Data_STK00:	.ds	1
	.globl _Reverse_Data_STK00
_Reverse_Data_STK01:	.ds	1
	.globl _Reverse_Data_STK01
_Reverse_Data_STK02:	.ds	1
	.globl _Reverse_Data_STK02
	.globl __mullong_STK06
	.globl __mullong_STK05
	.globl __mullong_STK04
	.globl __mullong_STK03
	.globl __mullong_STK02
	.globl __mullong_STK01
	.globl __mullong_STK00
	.globl ___slong2fs_STK02
	.globl ___slong2fs_STK01
	.globl ___slong2fs_STK00
	.globl ___fsmul_STK06
	.globl ___fsmul_STK05
	.globl ___fsmul_STK04
	.globl ___fsmul_STK03
	.globl ___fsmul_STK02
	.globl ___fsmul_STK01
	.globl ___fsmul_STK00
	.globl ___fs2slong_STK02
	.globl ___fs2slong_STK01
	.globl ___fs2slong_STK00
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------

	.area	CONST   (CODE)	 ;display-0-code, const

_seg:
	.db #0xfa	; 250
	.db #0x0a	; 10
	.db #0xbc	; 188
	.db #0x9e	; 158
	.db #0x4e	; 78	'N'
	.db #0xd6	; 214
	.db #0xf6	; 246
	.db #0xca	; 202
	.db #0xfe	; 254
	.db #0xde	; 222
	.db #0xee	; 238
	.db #0x76	; 118	'v'
	.db #0xf0	; 240
	.db #0x3e	; 62
	.db #0xf4	; 244
	.db #0xe4	; 228
	.db #0x6e	; 110	'n'
	.db #0x02	; 2
	.db #0x1e	; 30
	.db #0x70	; 112	'p'
	.db #0x26	; 38
	.db #0x36	; 54	'6'
	.db #0xec	; 236
	.db #0xce	; 206
	.db #0x24	; 36
	.db #0x74	; 116	't'
	.db #0x32	; 50	'2'
	.db #0x5e	; 94
	.db #0x7a	; 122	'z'

;--------------------------------------------------------
; initialized data - mirror
;--------------------------------------------------------

	;Following is optimization info, 
	;xxcdbxxW:dst:src+offset:srclit:just-remove
	;--cdb--W:r0x1174:NULL+0:-1:1
	;--cdb--W:r0x1170:NULL+0:-1:1
	;--cdb--W:r0x1172:STK00+0:-1:0
	;--cdb--W:r0x1171:STK01+0:-1:0
	;--cdb--W:r0x1176:STK00+0:-1:0
	;--cdb--W:r0x1175:STK01+0:-1:0
	;--cdb--W:r0x114D:NULL+0:-1:1
	;--cdb--W:r0x114C:NULL+0:-1:1
	;--cdb--W:r0x114A:NULL+0:-1:1
	;--cdb--W:r0x114E:NULL+0:-1:1
	;--cdb--W:r0x114B:STK01+0:-1:0
	;--cdb--W:r0x114B:NULL+0:-1:1
	;--cdb--W:r0x113F:NULL+0:-1:1
	end
