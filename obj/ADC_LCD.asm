;--------------------------------------------------------
; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
; Version 3.9.3 #4ad52972e (MSVC)
;--------------------------------------------------------
; Port for HYCON CPU
;--------------------------------------------------------
;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
;;	.file	".\ADC_LCD.c"
	.module ADC_LCD
	;.list	p=HY17P52
	;--cdb--T:FADC_LCD$_MCUSTATUS[({0}S:S$_byte$0$0({1}SC:U),Z,0,0)({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
	;--cdb--T:FADC_LCD$__00000000[({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
	;--cdb--T:FADC_LCD$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_high_bit$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_low_bit$0$0({1}SC:U),Z,0,0)({9}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({10}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({12}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
	;--cdb--F:ADC_LCD:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0,0,0,0
	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
	;--cdb--F:ADC_LCD:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0,0,0,0
	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
	;--cdb--F:ADC_LCD:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0,0,0,0
	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$main$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fslt$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$ISR$0$0({2}DF,SV:S),C,0,0,1,256,0
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
	.globl _main
;--------------------------------------------------------
; reset vector 
;--------------------------------------------------------
	.area STARTUP	(code,REL,CON) 
	nop
	jmp	__sdcc_gsinit_startup256fsr2
	nop
;--------------------------------------------------------
; interrupt and initialization code
;--------------------------------------------------------
	.area c_interrupt	(code,REL,CON)
__sdcc_interrupt:
.globl _ISR

;--------------------------------------------------------
	.FUNC _ISR:0:$C:_ADC_GetData\

;--------------------------------------------------------
;	;.line	572; ".\ADC_LCD.c"	if(ADIF_IsFlag()&&(adS.Presskey_flag !=1))
_ISR:	;Function start
	BTSZ	_INTF0,5
	BTSZ	(_adS+6),5
	JMP	_00461_DS_
;	;.line	574; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	575; ".\ADC_LCD.c"	ADC=ADC_GetData();
	CALL	_ADC_GetData
	.CHKPARA _ADC_GetData 0
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	576; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=1;
	BSF	_MCUSTATUSbits,0
_00461_DS_:
;	;.line	580; ".\ADC_LCD.c"	}
	RETI	 1
; exit point of _ISR
	.ENDFUNC	_ISR
;--------------------------------------------------------

.area CCODE (code,REL,CON) ; ADC_LCD-code 
.globl _main

;--------------------------------------------------------
	.FUNC _main:0:$C:_GPIO_Iint:$C:_ADC_Open:$C:_PGAandADCAccuracyMode:$C:_Delay\
:$C:_Display2Er:$C:_DisplayUnit:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
:$C:___fssub:$C:_DisplayNum:$C:___fslt:$C:_Reverse_Data:$C:_UnitConverter\
:$C:_LowVoltageDisplay:$C:___fsadd:$C:_HY17P52WR3\
:$L:r0x1140:$L:r0x1143:$L:r0x1142:$L:r0x1141:$L:r0x1147\
:$L:r0x1146:$L:r0x1145:$L:r0x1144:$L:r0x114B:$L:r0x114A\
:$L:r0x1149:$L:r0x1148:$L:r0x114D:$L:r0x114C
;--------------------------------------------------------
;	;.line	93; ".\ADC_LCD.c"	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
_main:	;Function start
	BSF	0x35,7
	MVL	0x3f
	ANDF	_OSCCN0,1,0
;	;.line	94; ".\ADC_LCD.c"	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
	MVL	0xce
	ANDF	_OSCCN0,1,0
;	;.line	95; ".\ADC_LCD.c"	GPIO_Iint() ;
	CALL	_GPIO_Iint
	.CHKPARA _GPIO_Iint 0
;	;.line	98; ".\ADC_LCD.c"	PWR_BGREnable();
	BSF	_PWRCN,7
;	;.line	99; ".\ADC_LCD.c"	PWR_LDOPLEnable();
	BSF	_AD1CN5,4
;	;.line	100; ".\ADC_LCD.c"	PWR_LDOEnable();
	BSF	_PWRCN,1
;	;.line	101; ".\ADC_LCD.c"	PWR_LDOSel(LDOC_2V4);
	MVL	0x8f
	ANDF	_PWRCN,1,0
;	;.line	103; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
	MVL	0x20
	MVF	_ADC_Open_STK10,1,0
	CLRF	_ADC_Open_STK09,0
	MVL	0x08
	MVF	_ADC_Open_STK08,1,0
	MVL	0x20
	MVF	_ADC_Open_STK07,1,0
	MVL	0x18
	MVF	_ADC_Open_STK06,1,0
	MVL	0x06
	MVF	_ADC_Open_STK05,1,0
	MVL	0x10
	MVF	_ADC_Open_STK04,1,0
	CLRF	_ADC_Open_STK03,0
	MVL	0x01
	MVF	_ADC_Open_STK02,1,0
	MVL	0x90
	MVF	_ADC_Open_STK01,1,0
	MVL	0x01
	MVF	_ADC_Open_STK00,1,0
	MVL	0x10
	CALL	_ADC_Open
	.CHKPARA _ADC_Open 12
;	;.line	106; ".\ADC_LCD.c"	PGAandADCAccuracyMode();
	CALL	_PGAandADCAccuracyMode
	.CHKPARA _PGAandADCAccuracyMode 0
;	;.line	113; ".\ADC_LCD.c"	LCD_Enable();
	BSF	_LCDCN1,7
;	;.line	114; ".\ADC_LCD.c"	LCD_ChargePumpSelect(LCDV_3V0);
	MVL	0x8f
	ANDF	_LCDCN1,0,0
	IORL	0x40
	MVF	_LCDCN1,1,0
;	;.line	115; ".\ADC_LCD.c"	LCD_OutBufferEnable();
	BSF	_LCDCN1,3
;	;.line	116; ".\ADC_LCD.c"	LCD_ChargePumpClk(SELPCLK_14KHZ);
	BCF	_LCDCN1,2
;	;.line	118; ".\ADC_LCD.c"	LCD_DisplayOn();
	BCF	_LCDCN2,1
;	;.line	121; ".\ADC_LCD.c"	LCD_PT60Mode(LCD);   //COM0
	MVF	_LCDCN3,0,0
	ANDL	0xfc
	IORL	0x03
	MVF	_LCDCN3,1,0
	ANDL	0xf3
;	;.line	122; ".\ADC_LCD.c"	LCD_PT61Mode(LCD);	 //COM1
	IORL	0x0c
	MVF	_LCDCN3,1,0
	ANDL	0xcf
;	;.line	123; ".\ADC_LCD.c"	LCD_PT62Mode(LCD);   //COM2
	IORL	0x30
	MVF	_LCDCN3,1,0
	ANDL	0x3f
;	;.line	124; ".\ADC_LCD.c"	LCD_PT63Mode(LCD);   //COM3
	IORL	0xc0
	MVF	_LCDCN3,1,0
;	;.line	128; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	129; ".\ADC_LCD.c"	ADIE_Enable();
	BSF	_INTE0,5
;	;.line	130; ".\ADC_LCD.c"	GIE_Enable();
	BSF	_INTE0,7
_00105_DS_:
;	;.line	136; ".\ADC_LCD.c"	if(GPIO_READ_PT10())
	MVF	_PT1,0,0
	ANDL	0x01
	BTSZ	_STATUS,0
	JMP	_00178_DS_
;	;.line	140; ".\ADC_LCD.c"	GIE_Disable();
	BCF	_INTE0,7
;	;.line	142; ".\ADC_LCD.c"	if(adS.Presskey_flag==0){
	BTSZ	(_adS+6),5
	JMP	_00109_DS_
;	;.line	143; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	144; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	145; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	146; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
;	;.line	148; ".\ADC_LCD.c"	if(adS.resetZeroDisplay==0 ){ /* zero point mode*/
	TFSZ	(_adS + 5),0
	JMP	_00107_DS_
;	;.line	150; ".\ADC_LCD.c"	adS.resetZeroDisplay++;
	MVL	0x01
	ADDF	(_adS + 5),1,0
;	;.line	151; ".\ADC_LCD.c"	adS.zeroPoint_Mode =1;
	BSF	(_adS+3),1
;	;.line	152; ".\ADC_LCD.c"	adS.unit_setMode =0;
	BCF	_adS,1
;	;.line	153; ".\ADC_LCD.c"	adS.testMode=0;
	BCF	(_adS+3),0
;	;.line	154; ".\ADC_LCD.c"	Display2Er();
	CALL	_Display2Er
	.CHKPARA _Display2Er 0
;	;.line	155; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	156; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	157; ".\ADC_LCD.c"	goto zeroPoint ;
	JMP	_00105_DS_
_00107_DS_:
;	;.line	160; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	161; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	162; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	163; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	164; ".\ADC_LCD.c"	adS.Presskey_flag=1;
	BSF	(_adS+6),5
;	;.line	165; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
	JMP	_00110_DS_
_00109_DS_:
;	;.line	173; ".\ADC_LCD.c"	Delay(20000);	
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	174; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
_00110_DS_:
;	;.line	181; ".\ADC_LCD.c"	adS.unit_setMode =1;
	BSF	_adS,1
;	;.line	182; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
;	;.line	183; ".\ADC_LCD.c"	adS.testMode =1;
	BSF	(_adS+3),0
;	;.line	184; ".\ADC_LCD.c"	DisplayUnit();
	CALL	_DisplayUnit
	.CHKPARA _DisplayUnit 0
;	;.line	188; ".\ADC_LCD.c"	switch(adS.plus_uint){
	MVF	(_adS + 1),0,0
	ADDL	0xfc
	BTSZ	_STATUS,4
	JMP	_00105_DS_
	MVL	HIGHD2(_00381_DS_)
	MVF	_PCLATH,1,0
	MVL	D2(_00381_DS_)
	ADDF	(_adS + 1),0,0
	BTSZ	_STATUS,4
	INF	_PCLATH,1,0
	MVF	_PCLATL,1,0
_00381_DS_:
	RJ	_00111_DS_
	RJ	_00112_DS_
	RJ	_00113_DS_
	RJ	_00114_DS_
_00111_DS_:
;	;.line	190; ".\ADC_LCD.c"	adS.plus_uint++;
	MVL	0x01
	ADDF	(_adS + 1),1,0
;	;.line	191; ".\ADC_LCD.c"	adS.unitChoose = psi;
	CLRF	(_adS + 2),0
;	;.line	194; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
	MVL	0xdf
	ANDF	_PT1,0,0
	IORL	0x20
	MVF	_PT1,1,0
;	;.line	195; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	196; ".\ADC_LCD.c"	Delay(20000);	
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	197; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	198; ".\ADC_LCD.c"	break;
	JMP	_00105_DS_
_00112_DS_:
;	;.line	200; ".\ADC_LCD.c"	adS.plus_uint++;
	MVL	0x01
	ADDF	(_adS + 1),1,0
;	;.line	201; ".\ADC_LCD.c"	adS.unitChoose = bar;
	MVL	0x01
	MVF	(_adS + 2),1,0
;	;.line	202; ".\ADC_LCD.c"	GPIO_PT15_LOW();
	BCF	_PT1,5
;	;.line	204; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
	MVL	0x02
	MVF	_LCD4,1,0
;	;.line	205; ".\ADC_LCD.c"	Delay(20000);	
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	206; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	207; ".\ADC_LCD.c"	break;
	JMP	_00105_DS_
_00113_DS_:
;	;.line	209; ".\ADC_LCD.c"	adS.plus_uint++;
	MVL	0x01
	ADDF	(_adS + 1),1,0
;	;.line	210; ".\ADC_LCD.c"	adS.unitChoose = kgf;
	MVL	0x02
	MVF	(_adS + 2),1,0
;	;.line	211; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
	MVL	0xdf
	ANDF	_PT1,0,0
	IORL	0x20
	MVF	_PT1,1,0
;	;.line	213; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	214; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	215; ".\ADC_LCD.c"	Delay(10000);	
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	217; ".\ADC_LCD.c"	break;
	JMP	_00105_DS_
_00114_DS_:
;	;.line	219; ".\ADC_LCD.c"	adS.plus_uint=0;
	CLRF	(_adS + 1),0
;	;.line	220; ".\ADC_LCD.c"	adS.unitChoose = mpa;
	MVL	0x03
	MVF	(_adS + 2),1,0
;	;.line	221; ".\ADC_LCD.c"	GPIO_PT15_LOW();
	BCF	_PT1,5
;	;.line	223; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
	MVL	0x08
	MVF	_LCD4,1,0
;	;.line	225; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	226; ".\ADC_LCD.c"	Delay(10000);	
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	228; ".\ADC_LCD.c"	}
	JMP	_00105_DS_
_00178_DS_:
;	;.line	234; ".\ADC_LCD.c"	if(adS.testMode == 0){ /* measure mode */
	BTSZ	(_adS+3),0
	JMP	_00146_DS_
;	;.line	235; ".\ADC_LCD.c"	adS.zeroPoint_Mode=0;
	BCF	(_adS+3),1
;	;.line	236; ".\ADC_LCD.c"	adS.unit_setMode=0;
	BCF	_adS,1
;	;.line	237; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
	CLRF	(_adS + 5),0
;	;.line	238; ".\ADC_LCD.c"	if(adS.reload_ADCInterrupt == 1){
	BTSS	(_adS+9),0
	JMP	_00117_DS_
;	;.line	239; ".\ADC_LCD.c"	adS.reload_ADCInterrupt =0;
	BCF	(_adS+9),0
;	;.line	240; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
	MVL	0x20
	MVF	_ADC_Open_STK10,1,0
	CLRF	_ADC_Open_STK09,0
	MVL	0x08
	MVF	_ADC_Open_STK08,1,0
	MVL	0x20
	MVF	_ADC_Open_STK07,1,0
	MVL	0x18
	MVF	_ADC_Open_STK06,1,0
	MVL	0x06
	MVF	_ADC_Open_STK05,1,0
	MVL	0x10
	MVF	_ADC_Open_STK04,1,0
	CLRF	_ADC_Open_STK03,0
	MVL	0x01
	MVF	_ADC_Open_STK02,1,0
	MVL	0x90
	MVF	_ADC_Open_STK01,1,0
	MVL	0x01
	MVF	_ADC_Open_STK00,1,0
	MVL	0x10
	CALL	_ADC_Open
	.CHKPARA _ADC_Open 12
;	;.line	241; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	242; ".\ADC_LCD.c"	ADIE_Enable();
	BSF	_INTE0,5
;	;.line	243; ".\ADC_LCD.c"	GIE_Enable();
	BSF	_INTE0,7
_00117_DS_:
;	;.line	246; ".\ADC_LCD.c"	if(MCUSTATUSbits.b_ADCdone==1)
	BTSS	_MCUSTATUSbits,0
	JMP	_00146_DS_
;	;.line	250; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=0;
	BCF	_MCUSTATUSbits,0
;	;.line	254; ".\ADC_LCD.c"	ADC=ADC>>6;
	SWPF	_ADC,0,0
	ANDL	0x0f
	MVF	_ADC,1,0
	SWPF	(_ADC + 1),0,0
	MVF	(_ADC + 1),1,0
	ANDL	0xf0
	IORF	_ADC,1,0
	XORF	(_ADC + 1),1,0
	SWPF	(_ADC + 2),0,0
	MVF	(_ADC + 2),1,0
	ANDL	0xf0
	IORF	(_ADC + 1),1,0
	XORF	(_ADC + 2),1,0
	SWPF	(_ADC + 3),0,0
	MVF	(_ADC + 3),1,0
	ANDL	0xf0
	IORF	(_ADC + 2),1,0
	XORF	(_ADC + 3),1,0
	MVL	0xf0
	BTSZ	(_ADC + 3),3
	IORF	(_ADC + 3),1,0
	ARRC	(_ADC + 3),1,0
	RRFC	(_ADC + 2),1,0
	RRFC	(_ADC + 1),1,0
	RRFC	_ADC,1,0
	ARRC	(_ADC + 3),1,0
	RRFC	(_ADC + 2),1,0
	RRFC	(_ADC + 1),1,0
	RRFC	_ADC,1,0
;	;.line	256; ".\ADC_LCD.c"	ADC = ADC * 0.1 ;
	MVF	_ADC,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	___slong2fs_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	___slong2fs_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	258; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
	BTSZ	(_ADC + 3),7
	JMP	_00118_DS_
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,4
	JMP	_00119_DS_
_00118_DS_:
;	;.line	261; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00120_DS_
_00119_DS_:
;	;.line	265; ".\ADC_LCD.c"	adS.Pressure_sign =0;
	BCF	(_adS+6),6
_00120_DS_:
;	;.line	268; ".\ADC_LCD.c"	if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/
	BTSZ	(_adS+6),6
	JMP	_00141_DS_
;	;.line	270; ".\ADC_LCD.c"	n = ADC ;
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
;	;.line	271; ".\ADC_LCD.c"	LCDDisplay= (0.1 * n)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
	MVF	r0x1140,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x1141,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x1142,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1147,1,0
	MVF	STK00,0,0
	MVF	r0x1146,1,0
	MVF	STK01,0,0
	MVF	r0x1145,1,0
	MVF	STK02,0,0
	MVF	r0x1144,1,0
	MVF	___fsmul_STK06,1,0
	MVF	r0x1145,0,0
	MVF	___fsmul_STK05,1,0
	MVF	r0x1146,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1147,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x114B,1,0
	CLRF	___fssub_STK06,0
	CLRF	___fssub_STK05,0
	MVL	0xb6
	MVF	___fssub_STK04,1,0
	MVL	0x43
	MVF	___fssub_STK03,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK02,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK01,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK00,1,0
	MVF	r0x114B,0,0
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x114B,1,0
;	;.line	274; ".\ADC_LCD.c"	if(adS.plus_revise_flag ==1){
	BTSS	(_adS+6),3
	JMP	_00132_DS_
;	;.line	276; ".\ADC_LCD.c"	if(n<2000)DisplayNum(ADC);
	MVL	0x30
	ADDF	r0x1140,0,0
	MVL	0xf8
	ADDC	r0x1141,0,0
	MVL	0xff
	ADDC	r0x1142,0,0
	MVL	0x7f
	ADDC	r0x1143,0,0
	BTSZ	_STATUS,1
	JMP	_00129_DS_
	MVF	_ADC,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
	JMP	_00146_DS_
_00129_DS_:
;	;.line	278; ".\ADC_LCD.c"	else if( (LCDDisplay *10) < 2875){
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x114B,0,0
	MVF	___fsmul_STK03,1,0
	CLRF	___fsmul_STK02,0
	CLRF	___fsmul_STK01,0
	MVL	0x20
	MVF	___fsmul_STK00,1,0
	MVL	0x41
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	CLRF	___fslt_STK06,0
	MVL	0xb0
	MVF	___fslt_STK05,1,0
	MVL	0x33
	MVF	___fslt_STK04,1,0
	MVL	0x45
	MVF	___fslt_STK03,1,0
	MVF	STK02,0,0
	MVF	___fslt_STK02,1,0
	MVF	STK01,0,0
	MVF	___fslt_STK01,1,0
	MVF	STK00,0,0
	MVF	___fslt_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fslt
	IORL	0x00
	BTSZ	_STATUS,0
	JMP	_00126_DS_
;	;.line	279; ".\ADC_LCD.c"	LCDDisplay= 0.125 *n- 202.86; //y = 0.0125x - 20.286
	MVF	r0x1144,0,0
	MVF	___fsmul_STK06,1,0
	MVF	r0x1145,0,0
	MVF	___fsmul_STK05,1,0
	MVF	r0x1146,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1147,0,0
	MVF	___fsmul_STK03,1,0
	CLRF	___fsmul_STK02,0
	CLRF	___fsmul_STK01,0
	CLRF	___fsmul_STK00,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	MVL	0x29
	MVF	___fssub_STK06,1,0
	MVL	0xdc
	MVF	___fssub_STK05,1,0
	MVL	0x4a
	MVF	___fssub_STK04,1,0
	MVL	0x43
	MVF	___fssub_STK03,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK02,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK01,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	280; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	281; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_UnitConverter
	.CHKPARA _UnitConverter 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	282; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	283; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	285; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00146_DS_
_00126_DS_:
;	;.line	290; ".\ADC_LCD.c"	if(adS.p_offset_value >=0) //WT.EDIT 2020-05-28
	BTSZ	(_adS + 13),7
	JMP	_00123_DS_
;	;.line	291; ".\ADC_LCD.c"	n =abs(ADC)- abs(adS.p_offset_value);
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00185_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	JMP	_00186_DS_
_00185_DS_:
	COMF	_ADC,0,0
	MVF	r0x1140,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	INF	r0x1140,1,0
	MVL	0x00
	ADDC	r0x1141,1,0
	ADDC	r0x1142,1,0
	ADDC	r0x1143,1,0
_00186_DS_:
	DCF	(_adS + 12),0,0
	MVL	0x7f
	ADDC	(_adS + 13),0,0
	BTSS	_STATUS,1
	JMP	_00187_DS_
	MVF	(_adS + 12),0,0
	MVF	r0x1146,1,0
	MVF	(_adS + 13),0,0
	MVF	r0x1147,1,0
	JMP	_00188_DS_
_00187_DS_:
	COMF	(_adS + 12),0,0
	MVF	r0x1146,1,0
	COMF	(_adS + 13),0,0
	INSUZ	r0x1146,1,0
	ADDL	0x01
	MVF	r0x1147,1,0
_00188_DS_:
	MVL	0x00
	BTSZ	r0x1147,7
	MVL	0xff
	MVF	r0x1149,1,0
	MVF	r0x1148,1,0
	MVF	r0x1146,0,0
	SUBF	r0x1140,1,0
	MVF	r0x1147,0,0
	SUBC	r0x1141,1,0
	MVF	r0x1148,0,0
	SUBC	r0x1142,1,0
	MVF	r0x1149,0,0
	SUBC	r0x1143,1,0
	JMP	_00124_DS_
_00123_DS_:
;	;.line	292; ".\ADC_LCD.c"	else  n =abs(ADC) + abs(adS.p_offset_value);
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00189_DS_
	MVF	_ADC,0,0
	MVF	r0x1144,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1145,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1146,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1147,1,0
	JMP	_00190_DS_
_00189_DS_:
	COMF	_ADC,0,0
	MVF	r0x1144,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1145,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1146,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1147,1,0
	INF	r0x1144,1,0
	MVL	0x00
	ADDC	r0x1145,1,0
	ADDC	r0x1146,1,0
	ADDC	r0x1147,1,0
_00190_DS_:
	DCF	(_adS + 12),0,0
	MVL	0x7f
	ADDC	(_adS + 13),0,0
	BTSS	_STATUS,1
	JMP	_00191_DS_
	MVF	(_adS + 12),0,0
	MVF	r0x114A,1,0
	MVF	(_adS + 13),0,0
	MVF	r0x114B,1,0
	JMP	_00192_DS_
_00191_DS_:
	COMF	(_adS + 12),0,0
	MVF	r0x114A,1,0
	COMF	(_adS + 13),0,0
	INSUZ	r0x114A,1,0
	ADDL	0x01
	MVF	r0x114B,1,0
_00192_DS_:
	MVL	0x00
	BTSZ	r0x114B,7
	MVL	0xff
	MVF	r0x114D,1,0
	MVF	r0x114C,1,0
	MVF	r0x114A,0,0
	ADDF	r0x1144,0,0
	MVF	r0x1140,1,0
	MVF	r0x1145,0,0
	ADDC	r0x114B,0,0
	MVF	r0x1141,1,0
	MVF	r0x1146,0,0
	ADDC	r0x114C,0,0
	MVF	r0x1142,1,0
	MVF	r0x1147,0,0
	ADDC	r0x114D,0,0
	MVF	r0x1143,1,0
_00124_DS_:
;	;.line	293; ".\ADC_LCD.c"	LCDDisplay= 56193  - (8.47 * n) ;//y=-0.846x + 5619.3
	MVF	r0x1140,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x1141,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x1142,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0x1f
	MVF	___fsmul_STK02,1,0
	MVL	0x85
	MVF	___fsmul_STK01,1,0
	MVL	0x07
	MVF	___fsmul_STK00,1,0
	MVL	0x41
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK06,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK05,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fssub_STK03,1,0
	CLRF	___fssub_STK02,0
	MVL	0x81
	MVF	___fssub_STK01,1,0
	MVL	0x5b
	MVF	___fssub_STK00,1,0
	MVL	0x47
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	294; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	295; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_UnitConverter
	.CHKPARA _UnitConverter 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	296; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	297; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	299; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00146_DS_
_00132_DS_:
;	;.line	306; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
	MVF	_ADC,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	307; ".\ADC_LCD.c"	DisplayNum(ADC);
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	308; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	310; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00146_DS_
_00141_DS_:
;	;.line	316; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
;	;.line	319; ".\ADC_LCD.c"	theta= abs(ADC) - adS.m_offset_value;  
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00193_DS_
	MVF	_ADC,0,0
	MVF	r0x1144,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1145,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1146,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1147,1,0
	JMP	_00194_DS_
_00193_DS_:
	COMF	_ADC,0,0
	MVF	r0x1144,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1145,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1146,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1147,1,0
	INF	r0x1144,1,0
	MVL	0x00
	ADDC	r0x1145,1,0
	ADDC	r0x1146,1,0
	ADDC	r0x1147,1,0
_00194_DS_:
	MVL	0x00
	BTSZ	(_adS + 11),7
	MVL	0xff
	MVF	r0x114D,1,0
	MVF	r0x114C,1,0
	MVF	(_adS + 10),0,0
	SUBF	r0x1144,1,0
	MVF	(_adS + 11),0,0
	SUBC	r0x1145,1,0
	MVF	r0x114C,0,0
	SUBC	r0x1146,1,0
	MVF	r0x114D,0,0
	SUBC	r0x1147,1,0
;	;.line	320; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
	BTSS	(_adS+6),4
	JMP	_00138_DS_
;	;.line	323; ".\ADC_LCD.c"	if(delta >=0 ){
	BTSZ	(_ADC + 3),7
	JMP	_00135_DS_
;	;.line	324; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
	MVF	r0x1144,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x1145,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x1146,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1147,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0x25
	MVF	___fsmul_STK02,1,0
	MVL	0x06
	MVF	___fsmul_STK01,1,0
	MVL	0x01
	MVF	___fsmul_STK00,1,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK06,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK05,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fssub_STK03,1,0
	CLRF	___fssub_STK02,0
	CLRF	___fssub_STK01,0
	MVL	0x48
	MVF	___fssub_STK00,1,0
	MVL	0x43
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	325; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	326; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_UnitConverter
	.CHKPARA _UnitConverter 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	327; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	328; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	330; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00146_DS_
_00135_DS_:
;	;.line	341; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
	MVF	r0x1144,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x1145,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x1146,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1147,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fsmul_STK03,1,0
	CLRF	___fsmul_STK02,0
	CLRF	___fsmul_STK01,0
	CLRF	___fsmul_STK00,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	CLRF	___fsadd_STK06,0
	CLRF	___fsadd_STK05,0
	MVL	0x4c
	MVF	___fsadd_STK04,1,0
	MVL	0x43
	MVF	___fsadd_STK03,1,0
	MVF	STK02,0,0
	MVF	___fsadd_STK02,1,0
	MVF	STK01,0,0
	MVF	___fsadd_STK01,1,0
	MVF	STK00,0,0
	MVF	___fsadd_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fsadd
	.CHKPARA ___fsadd 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	342; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	343; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_UnitConverter
	.CHKPARA _UnitConverter 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
;	;.line	344; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1143,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	345; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	347; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00146_DS_
_00138_DS_:
;	;.line	353; ".\ADC_LCD.c"	ADC = abs(ADC);
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00195_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	JMP	_00196_DS_
_00195_DS_:
	COMF	_ADC,0,0
	MVF	r0x1140,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	INF	r0x1140,1,0
	MVL	0x00
	ADDC	r0x1141,1,0
	ADDC	r0x1142,1,0
	ADDC	r0x1143,1,0
_00196_DS_:
	MVF	r0x1140,0,0
	MVF	_ADC,1,0
	MVF	r0x1141,0,0
	MVF	(_ADC + 1),1,0
	MVF	r0x1142,0,0
	MVF	(_ADC + 2),1,0
	MVF	r0x1143,0,0
	MVF	(_ADC + 3),1,0
;	;.line	354; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
	MVF	_ADC,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	355; ".\ADC_LCD.c"	DisplayNum(ADC);
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	356; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
	.CHKPARA _LowVoltageDisplay 0
;	;.line	358; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00146_DS_:
;	;.line	364; ".\ADC_LCD.c"	if(adS.zeroPoint_Mode == 1){ /*zero point mode */
	BTSS	(_adS+3),1
	JMP	_00155_DS_
;	;.line	366; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
	CLRF	(_adS + 5),0
;	;.line	367; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
;	;.line	368; ".\ADC_LCD.c"	adS.testMode=0;
	BCF	(_adS+3),0
;	;.line	369; ".\ADC_LCD.c"	ADC=ADC>>6;
	SWPF	_ADC,0,0
	ANDL	0x0f
	MVF	_ADC,1,0
	SWPF	(_ADC + 1),0,0
	MVF	(_ADC + 1),1,0
	ANDL	0xf0
	IORF	_ADC,1,0
	XORF	(_ADC + 1),1,0
	SWPF	(_ADC + 2),0,0
	MVF	(_ADC + 2),1,0
	ANDL	0xf0
	IORF	(_ADC + 1),1,0
	XORF	(_ADC + 2),1,0
	SWPF	(_ADC + 3),0,0
	MVF	(_ADC + 3),1,0
	ANDL	0xf0
	IORF	(_ADC + 2),1,0
	XORF	(_ADC + 3),1,0
	MVL	0xf0
	BTSZ	(_ADC + 3),3
	IORF	(_ADC + 3),1,0
	ARRC	(_ADC + 3),1,0
	RRFC	(_ADC + 2),1,0
	RRFC	(_ADC + 1),1,0
	RRFC	_ADC,1,0
	ARRC	(_ADC + 3),1,0
	RRFC	(_ADC + 2),1,0
	RRFC	(_ADC + 1),1,0
	RRFC	_ADC,1,0
;	;.line	370; ".\ADC_LCD.c"	ADC = ADC * 0.1;
	MVF	_ADC,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	___slong2fs_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	___slong2fs_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1143,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1143,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1143,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	371; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
	BTSZ	(_ADC + 3),7
	JMP	_00147_DS_
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,4
	JMP	_00148_DS_
_00147_DS_:
;	;.line	374; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00149_DS_
_00148_DS_:
;	;.line	378; ".\ADC_LCD.c"	adS.Pressure_sign =0;
	BCF	(_adS+6),6
_00149_DS_:
;	;.line	384; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
	BTSS	(_adS+6),6
	JMP	_00152_DS_
;	;.line	385; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00197_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	JMP	_00198_DS_
_00197_DS_:
	COMF	_ADC,0,0
	MVF	r0x1140,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	INF	r0x1140,1,0
	MVL	0x00
	ADDC	r0x1141,1,0
	ADDC	r0x1142,1,0
	ADDC	r0x1143,1,0
_00198_DS_:
	MVL	0x37
	ADDF	r0x1140,0,0
	MVF	r0x1140,1,0
	MVL	0xe7
	ADDC	r0x1141,0,0
	MVSF	r0x1140,(_adS + 10)
	MVF	(_adS + 11),1,0
;	;.line	386; ".\ADC_LCD.c"	adS.minus_revise_flag=1;
	BSF	(_adS+6),4
	JMP	_00155_DS_
_00152_DS_:
;	;.line	392; ".\ADC_LCD.c"	adS.p_offset_value= abs(STD_VALUE) -abs(ADC) + 1; 
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00199_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	JMP	_00200_DS_
_00199_DS_:
	COMF	_ADC,0,0
	MVF	r0x1140,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1144,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1145,1,0
	INF	r0x1140,1,0
	MVL	0x00
	ADDC	r0x1141,1,0
	ADDC	r0x1144,1,0
	ADDC	r0x1145,1,0
_00200_DS_:
	COMF	r0x1140,0,0
	ADDL	0x7e
	MVF	r0x1140,1,0
	COMF	r0x1141,1,0
	MVL	0x19
	ADDC	r0x1141,1,0
	MVF	r0x1140,0,0
	MVF	(_adS + 12),1,0
	MVF	r0x1141,0,0
	MVF	(_adS + 13),1,0
;	;.line	393; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
	BSF	(_adS+6),3
;	;.line	394; ".\ADC_LCD.c"	adS.p_offset_value=Reverse_Data(adS.p_offset_value);
	MVL	0x00
	BTSZ	r0x1141,7
	MVL	0xff
	MVF	r0x1149,1,0
	MVF	r0x1148,1,0
	MVF	r0x1140,0,0
	MVF	_Reverse_Data_STK02,1,0
	MVF	r0x1141,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	r0x1148,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x1149,0,0
	CALL	_Reverse_Data
	MVF	STK02,0,0
	MVF	(_adS + 12),1,0
	MVF	STK01,0,0
	MVF	(_adS + 13),1,0
;	;.line	395; ".\ADC_LCD.c"	DisplayNum( adS.p_offset_value);
	MVL	0x00
	BTSZ	STK01,7
	MVL	0xff
	MVF	r0x1147,1,0
	MVF	r0x1146,1,0
	MVF	STK02,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	r0x1146,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1147,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	396; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00155_DS_:
;	;.line	401; ".\ADC_LCD.c"	if(adS.unit_setMode ==1){
	BTSS	_adS,1
	JMP	_00105_DS_
;	;.line	403; ".\ADC_LCD.c"	adS.Presskey_flag=0;
	BCF	(_adS+6),5
;	;.line	404; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
	BCF	_adS,1
;	;.line	405; ".\ADC_LCD.c"	adS.testMode = 0;
	BCF	(_adS+3),0
;	;.line	406; ".\ADC_LCD.c"	adS.reload_ADCInterrupt = 1;
	BSF	(_adS+9),0
;	;.line	407; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
	CLRF	(_adS + 5),0
;	;.line	410; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
;	;.line	411; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	412; ".\ADC_LCD.c"	GPIO_PT16_LOW();
	BCF	_PT1,6
;	;.line	413; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	414; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
;	;.line	415; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	416; ".\ADC_LCD.c"	GPIO_PT16_LOW();
	BCF	_PT1,6
;	;.line	419; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
	MVF	(_adS + 2),0,0
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0xaa
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x00
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	420; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00160_DS_
;	;.line	422; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00157_DS_:
;	;.line	423; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00157_DS_
_00160_DS_:
;	;.line	427; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
	CLRF	_BIEARL,0
;	;.line	428; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00161_DS_:
;	;.line	429; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1140,1,0
	DCF	r0x1140,0,0
	RRF	_WREG,0,0
	BTSZ	_STATUS,0
	JMP	_00161_DS_
;	;.line	430; ".\ADC_LCD.c"	adS.eepromRead_low_bit=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 8),1,0
;	;.line	432; ".\ADC_LCD.c"	if(adS.eepromRead_low_bit==0)  LCD_WriteData(&LCD4, seg_bar) ; 
	MVF	r0x1140,1,0
	TFSZ	r0x1140,0
	JMP	_00173_DS_
	MVL	0x02
	MVF	_LCD4,1,0
	JMP	_00105_DS_
_00173_DS_:
;	;.line	433; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==1)LCD_WriteData(&LCD4, seg_kgf) ; 
	DCSZ	(_adS + 8),0,0
	JMP	_00170_DS_
	MVL	0x01
	MVF	_LCD4,1,0
	JMP	_00105_DS_
_00170_DS_:
;	;.line	434; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==2)LCD_WriteData(&LCD4, seg_mpa) ; 
	MVF	(_adS + 8),0,0
	XORL	0x02
	BTSS	_STATUS,0
	JMP	_00167_DS_
	MVL	0x08
	MVF	_LCD4,1,0
	JMP	_00105_DS_
_00167_DS_:
;	;.line	435; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==3)LCD_WriteData(&LCD4, seg_psi) ; 
	MVF	(_adS + 8),0,0
	XORL	0x03
	BTSS	_STATUS,0
	JMP	_00105_DS_
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	446; ".\ADC_LCD.c"	}
	JMP	_00105_DS_
	.ENDFUNC	_main
;--------------------------------------------------------

.globl _LowVoltageDisplay

;--------------------------------------------------------
	.FUNC _LowVoltageDisplay:0:$C:_LowVoltageDetect_3V:$C:_DisplayBatteryCapacityFull:$C:_LowVoltageDetect_2V4:$C:_DisplayBatteryCapacityHalf\
:$C:_DispalyBatteryCapacityLow\
:$L:r0x1196
;--------------------------------------------------------
;	;.line	543; ".\ADC_LCD.c"	adS.LVD_3V_flag = LowVoltageDetect_3V();
_LowVoltageDisplay:	;Function start
	CALL	_LowVoltageDetect_3V
	MVF	r0x1196,1,0
	RRFC	r0x1196,0,0
	BTSS	_STATUS,4
	BCF	(_adS+6),2
	BTSZ	_STATUS,4
	BSF	(_adS+6),2
;	;.line	544; ".\ADC_LCD.c"	if(adS.LVD_3V_flag==0){ /* battery capacity is full*/
	BTSZ	(_adS+6),2
	JMP	_00451_DS_
;	;.line	547; ".\ADC_LCD.c"	DisplayBatteryCapacityFull(); 
	CALL	_DisplayBatteryCapacityFull
	.CHKPARA _DisplayBatteryCapacityFull 0
	JMP	_00453_DS_
_00451_DS_:
;	;.line	550; ".\ADC_LCD.c"	adS.LVD_2V4_flag = LowVoltageDetect_2V4();
	CALL	_LowVoltageDetect_2V4
	MVF	r0x1196,1,0
	RRFC	r0x1196,0,0
	BTSS	_STATUS,4
	BCF	(_adS+6),1
	BTSZ	_STATUS,4
	BSF	(_adS+6),1
;	;.line	551; ".\ADC_LCD.c"	if(adS.LVD_2V4_flag == 0){
	BTSZ	(_adS+6),1
	JMP	_00448_DS_
;	;.line	554; ".\ADC_LCD.c"	DisplayBatteryCapacityHalf();
	CALL	_DisplayBatteryCapacityHalf
	.CHKPARA _DisplayBatteryCapacityHalf 0
	JMP	_00453_DS_
_00448_DS_:
;	;.line	558; ".\ADC_LCD.c"	DispalyBatteryCapacityLow();
	CALL	_DispalyBatteryCapacityLow
	.CHKPARA _DispalyBatteryCapacityLow 0
_00453_DS_:
;	;.line	562; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDisplay
	.ENDFUNC	_LowVoltageDisplay
;--------------------------------------------------------

.globl _LowVoltageDetect_2V4

;--------------------------------------------------------
	.FUNC _LowVoltageDetect_2V4:0:$C:_Delay\
:$L:r0x1195
;--------------------------------------------------------
;	;.line	521; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_24);  
_LowVoltageDetect_2V4:	;Function start
	MVL	0xe1
	ANDF	_LVDCN,0,0
	IORL	0x0a
	MVF	_LVDCN,1,0
;	;.line	522; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
	BCF	_LVDCN,5
;	;.line	523; ".\ADC_LCD.c"	Delay(10);
	MVL	0x0a
	MVF	_Delay_STK00,1,0
	MVL	0x00
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	524; ".\ADC_LCD.c"	if(LVD_GetLVDO())
	BTSS	_LVDCN,0
	JMP	_00441_DS_
;	;.line	526; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
	CLRF	r0x1195,0
	JMP	_00442_DS_
_00441_DS_:
;	;.line	530; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
	MVL	0x01
	MVF	r0x1195,1,0
_00442_DS_:
;	;.line	532; ".\ADC_LCD.c"	return flag;
	MVF	r0x1195,0,0
;	;.line	533; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDetect_2V4
	.ENDFUNC	_LowVoltageDetect_2V4
;--------------------------------------------------------

.globl _LowVoltageDetect_3V

;--------------------------------------------------------
	.FUNC _LowVoltageDetect_3V:0:$C:_Delay\
:$L:r0x1194
;--------------------------------------------------------
;	;.line	498; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_30 );  
_LowVoltageDetect_3V:	;Function start
	MVL	0xe1
	ANDF	_LVDCN,0,0
	IORL	0x16
	MVF	_LVDCN,1,0
;	;.line	499; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
	BCF	_LVDCN,5
;	;.line	500; ".\ADC_LCD.c"	Delay(10);
	MVL	0x0a
	MVF	_Delay_STK00,1,0
	MVL	0x00
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	501; ".\ADC_LCD.c"	if(LVD_GetLVDO())
	BTSS	_LVDCN,0
	JMP	_00434_DS_
;	;.line	503; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
	CLRF	r0x1194,0
	JMP	_00435_DS_
_00434_DS_:
;	;.line	507; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
	MVL	0x01
	MVF	r0x1194,1,0
_00435_DS_:
;	;.line	509; ".\ADC_LCD.c"	return flag;
	MVF	r0x1194,0,0
;	;.line	510; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDetect_3V
	.ENDFUNC	_LowVoltageDetect_3V
;--------------------------------------------------------

.globl _UnitConverter

;--------------------------------------------------------
	.FUNC _UnitConverter:4:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
:$L:r0x118E:$L:_UnitConverter_STK00:$L:_UnitConverter_STK01:$L:_UnitConverter_STK02:$L:r0x118F\
:$L:r0x1193:$L:r0x1192
;--------------------------------------------------------
;	;.line	455; ".\ADC_LCD.c"	long UnitConverter(long data)
_UnitConverter:	;Function start
	MVF	r0x118E,1,0
;	;.line	458; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
	CLRF	_BIEARL,0
;	;.line	459; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00387_DS_:
;	;.line	460; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x118F,1,0
	DCF	r0x118F,0,0
	BTSZ	_STATUS,0
	JMP	_00387_DS_
;	;.line	461; ".\ADC_LCD.c"	adS.eepromRead_low_bit=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 8),1,0
	MVF	r0x118F,1,0
;	;.line	463; ".\ADC_LCD.c"	if(adS.eepromRead_low_bit==0){ /*psi*/
	TFSZ	_WREG,0
	JMP	_00400_DS_
;	;.line	465; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_psi) ;
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	466; ".\ADC_LCD.c"	return  kgfTOpsi(data) ;
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x118E,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1193,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1193,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xe1
	MVF	___fsmul_STK02,1,0
	MVL	0x7a
	MVF	___fsmul_STK01,1,0
	MVL	0x14
	MVF	___fsmul_STK00,1,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1193,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1193,0,0
	CALL	___fs2slong
	JMP	_00402_DS_
_00400_DS_:
;	;.line	468; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==1){ /*unit bar*/
	DCSZ	r0x118F,0,0
	JMP	_00397_DS_
;	;.line	469; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_bar) ;
	MVL	0x02
	MVF	_LCD4,1,0
;	;.line	470; ".\ADC_LCD.c"	return	kgfTObar(data);
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x118E,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1193,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1193,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0x0a
	MVF	___fsmul_STK02,1,0
	MVL	0xd7
	MVF	___fsmul_STK01,1,0
	MVL	0x23
	MVF	___fsmul_STK00,1,0
	MVL	0x3c
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1193,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1193,0,0
	CALL	___fs2slong
	JMP	_00402_DS_
_00397_DS_:
;	;.line	472; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==2){ /* unit kgf*/
	MVF	r0x118F,0,0
	XORL	0x02
	BTSS	_STATUS,0
	JMP	_00394_DS_
;	;.line	474; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	475; ".\ADC_LCD.c"	return data;
	MVF	_UnitConverter_STK02,0,0
	MVF	STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	STK00,1,0
	MVF	r0x118E,0,0
	JMP	_00402_DS_
_00394_DS_:
;	;.line	477; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==3){ /*uint mpa*/
	MVF	r0x118F,0,0
	XORL	0x03
	BTSS	_STATUS,0
	JMP	_00391_DS_
;	;.line	479; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_mpa) ;
	MVL	0x08
	MVF	_LCD4,1,0
;	;.line	480; ".\ADC_LCD.c"	return kgfTOmpa(data);
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x118E,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1192,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1192,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1192,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1192,0,0
	CALL	___fs2slong
	JMP	_00402_DS_
_00391_DS_:
;	;.line	483; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	484; ".\ADC_LCD.c"	return data;
	MVF	_UnitConverter_STK02,0,0
	MVF	STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	STK00,1,0
	MVF	r0x118E,0,0
_00402_DS_:
;	;.line	487; ".\ADC_LCD.c"	}
	RET	
; exit point of _UnitConverter
	.ENDFUNC	_UnitConverter
;--------------------------------------------------------

	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fslt$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
	;--cdb--S:G$adS$0$0({14}ST_adc_works_:S),E,0,0
	;--cdb--S:G$Flag$0$0({1}SC:U),E,0,0
	;--cdb--S:G$ADC$0$0({4}SL:SL),E,0,0
	;--cdb--S:G$MCUSTATUSbits$0$0({1}ST_MCUSTATUS:S),E,0,0
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
	;--cdb--S:LADC_LCD.main._main_LCDDisplay_65536_29$LCDDisplay$10000$29({4}SF:S),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
	;--cdb--S:LADC_LCD.main._main_delta_65536_29$delta$10000$29({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
	;--cdb--S:LADC_LCD.main._main_theta_65536_29$theta$10000$29({4}SL:SL),R,0,0,[r0x1144,r0x1145,r0x1146,r0x1147]
	;--cdb--S:LADC_LCD.main._main_n_65536_29$n$10000$29({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
	;--cdb--S:LADC_LCD.UnitConverter._UnitConverter_data_65536_59$data$10000$59({4}SL:SL),R,0,0,[_UnitConverter_STK02,_UnitConverter_STK01,_UnitConverter_STK00,r0x118E]
	;--cdb--S:LADC_LCD.LowVoltageDetect_3V._LowVoltageDetect_3V_flag_65536_67$flag$10000$67({1}SC:U),R,0,0,[r0x1194]
	;--cdb--S:LADC_LCD.LowVoltageDetect_2V4._LowVoltageDetect_2V4_flag_65536_71$flag$10000$71({1}SC:U),R,0,0,[r0x1195]
	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
	;--cdb--S:G$_PCLATH$0$0({0}:U),Z,0,0
	;--cdb--S:G$_PCLATL$0$0({0}:U),Z,0,0
	;--cdb--S:G$_WREG$0$0({0}:U),Z,0,0
	;--cdb--S:G$_INTE0$0$0({0}:U),Z,0,0
;--------------------------------------------------------
; external declarations
;--------------------------------------------------------
	.globl	_ADC_Open
	.globl	_ADC_GetData
	.globl	_DisplayNum
	.globl	_Display2Er
	.globl	_DisplayUnit
	.globl	_Delay
	.globl	_GPIO_Iint
	.globl	_Reverse_Data
	.globl	_DisplayBatteryCapacityFull
	.globl	_DisplayBatteryCapacityHalf
	.globl	_DispalyBatteryCapacityLow
	.globl	_HY17P52WR3
	.globl	_PGAandADCAccuracyMode
	.globl	___slong2fs
	.globl	___fsmul
	.globl	___fs2slong
	.globl	___fssub
	.globl	___fslt
	.globl	___fsadd
	.globl	_FSR0
	.globl	_FSR1
	.globl	_FSR2
	.globl	_ADCR
	.globl	_adS
	.globl	__sdcc_gsinit_startup256fsr2
;--------------------------------------------------------
; global -1 declarations
;--------------------------------------------------------
	.globl	_LowVoltageDetect_2V4
	.globl	_LowVoltageDetect_3V
	.globl	_UnitConverter
	.globl	_Flag
	.globl	_ADC
	.globl	_MCUSTATUSbits

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
	.globl _FSR0L_SAVE
	.globl _FSR0H_SAVE
	.globl _FSR1L_SAVE
	.globl _FSR1H_SAVE
	.globl _FSR2L_SAVE
	.globl _FSR2H_SAVE
	.globl	_TBLPTRH_SAVE

.area UDATA (DATA,REL,CON)
STK07:	.ds	 1
STK06:	.ds	 1
STK05:	.ds	 1
STK04:	.ds	 1
STK03:	.ds	 1
STK02:	.equ	 0x1E
STK01:	.equ	 0x1F
STK00:	.equ	 0x20
WSAVE:	.ds 1
STK07_SAVE:	.ds	 1
STK06_SAVE:	.ds	 1
STK05_SAVE:	.ds	 1
STK04_SAVE:	.ds	 1
STK03_SAVE:	.ds	 1
STK02_SAVE:	.ds	 1
STK01_SAVE:	.ds	 1
STK00_SAVE:	.ds	 1
_FSR0L_SAVE:	.ds	 1
_FSR0H_SAVE:	.ds	 1
_FSR1L_SAVE:	.ds	 1
_FSR1H_SAVE:	.ds	 1
_FSR2L_SAVE:	.ds	 1
_FSR2H_SAVE:	.ds	 1
_TBLPTRH_SAVE:	.ds	 1

	.globl	_memcpy
;--------------------------------------------------------
; global -2 definitions
;--------------------------------------------------------
	.area DSEG(DATA)
_Flag:	.ds	1

	.area DSEG(DATA)
_ADC:	.ds	4

	.area DSEG(DATA)
_MCUSTATUSbits:	.ds	1

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
	.area UDATA (DATA,REL,CON) ;UDL_ADC_LCD_0	udata
r0x1140:	.ds	1
r0x1141:	.ds	1
r0x1142:	.ds	1
r0x1143:	.ds	1
r0x1144:	.ds	1
r0x1145:	.ds	1
r0x1146:	.ds	1
r0x1147:	.ds	1
r0x1148:	.ds	1
r0x1149:	.ds	1
r0x114A:	.ds	1
r0x114B:	.ds	1
r0x114C:	.ds	1
r0x114D:	.ds	1
r0x118E:	.ds	1
r0x118F:	.ds	1
r0x1192:	.ds	1
r0x1193:	.ds	1
r0x1194:	.ds	1
r0x1195:	.ds	1
r0x1196:	.ds	1
	.area LOCALSTK (STK); local stack var
	.globl _ADC_Open_STK10
	.globl _ADC_Open_STK09
	.globl _ADC_Open_STK08
	.globl _ADC_Open_STK07
	.globl _ADC_Open_STK06
	.globl _ADC_Open_STK05
	.globl _ADC_Open_STK04
	.globl _ADC_Open_STK03
	.globl _ADC_Open_STK02
	.globl _ADC_Open_STK01
	.globl _ADC_Open_STK00
	.globl _Delay_STK00
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
	.globl ___fssub_STK06
	.globl ___fssub_STK05
	.globl ___fssub_STK04
	.globl ___fssub_STK03
	.globl ___fssub_STK02
	.globl ___fssub_STK01
	.globl ___fssub_STK00
	.globl _DisplayNum_STK02
	.globl _DisplayNum_STK01
	.globl _DisplayNum_STK00
	.globl ___fslt_STK06
	.globl ___fslt_STK05
	.globl ___fslt_STK04
	.globl ___fslt_STK03
	.globl ___fslt_STK02
	.globl ___fslt_STK01
	.globl ___fslt_STK00
	.globl _Reverse_Data_STK02
	.globl _Reverse_Data_STK01
	.globl _Reverse_Data_STK00
_UnitConverter_STK02:	.ds	1
	.globl _UnitConverter_STK02
_UnitConverter_STK01:	.ds	1
	.globl _UnitConverter_STK01
_UnitConverter_STK00:	.ds	1
	.globl _UnitConverter_STK00
	.globl ___fsadd_STK06
	.globl ___fsadd_STK05
	.globl ___fsadd_STK04
	.globl ___fsadd_STK03
	.globl ___fsadd_STK02
	.globl ___fsadd_STK01
	.globl ___fsadd_STK00
	.globl _HY17P52WR3_STK01
	.globl _HY17P52WR3_STK00
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized data - mirror
;--------------------------------------------------------
	;Following is optimization info, 
	;xxcdbxxW:dst:src+offset:srclit:just-remove
	;--cdb--W:r0x1195:NULL+0:-1:1
	;--cdb--W:r0x1194:NULL+0:-1:1
	;--cdb--W:r0x1190:NULL+0:-1:1
	;--cdb--W:r0x118F:NULL+0:-1:1
	;--cdb--W:r0x1190:NULL+0:0:0
	;--cdb--W:r0x1190:STK01+0:-1:0
	;--cdb--W:r0x1192:STK00+0:-1:0
	;--cdb--W:r0x1191:STK01+0:-1:0
	;--cdb--W:r0x1191:STK00+0:-1:0
	;--cdb--W:r0x1193:NULL+0:-1:1
	;--cdb--W:r0x1192:NULL+0:-1:1
	;--cdb--W:r0x1140:NULL+0:-1:1
	;--cdb--W:r0x1141:NULL+0:-1:1
	;--cdb--W:r0x1142:NULL+0:-1:1
	;--cdb--W:r0x1143:NULL+0:-1:1
	;--cdb--W:r0x1144:NULL+0:-1:1
	;--cdb--W:r0x1145:NULL+0:-1:1
	;--cdb--W:r0x1147:NULL+0:-1:1
	;--cdb--W:r0x1146:NULL+0:-1:1
	;--cdb--W:r0x1140:STK02+0:-1:0
	;--cdb--W:r0x1140:r0x1148+0:-1:0
	;--cdb--W:r0x1142:STK00+0:-1:0
	;--cdb--W:r0x1141:STK01+0:-1:0
	;--cdb--W:r0x1141:r0x1149+1:-1:0
	;--cdb--W:r0x1141:NULL+0:0:0
	;--cdb--W:r0x1147:r0x1141+1:-1:0
	;--cdb--W:r0x1146:r0x1140+0:-1:0
	;--cdb--W:r0x1145:r0x1147+1:-1:0
	;--cdb--W:r0x1145:r0x1141+1:-1:0
	;--cdb--W:r0x1144:r0x1146+0:-1:0
	;--cdb--W:r0x1144:r0x1140+0:-1:0
	;--cdb--W:r0x114B:r0x1149+1:-1:0
	;--cdb--W:r0x114A:STK00+0:-1:0
	;--cdb--W:r0x114A:r0x1148+0:-1:0
	;--cdb--W:r0x1149:STK01+0:-1:0
	;--cdb--W:r0x1149:r0x114B+1:-1:0
	;--cdb--W:r0x1148:STK02+0:-1:0
	;--cdb--W:r0x1148:r0x114A+0:-1:0
	end
