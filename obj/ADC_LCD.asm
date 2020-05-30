;--------------------------------------------------------
; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
; Version 3.9.3 #4ad52972e (MSVC)
;--------------------------------------------------------
; Port for HYCON CPU
;--------------------------------------------------------
;	;CCFROM:"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft"
;;	.file	".\ADC_LCD.c"
	.module ADC_LCD
	;.list	p=HY17P52
	;--cdb--T:FADC_LCD$_MCUSTATUS[({0}S:S$_byte$0$0({1}SC:U),Z,0,0)({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
	;--cdb--T:FADC_LCD$__00000000[({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
	;--cdb--T:FADC_LCD$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_PositiveDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_PositiveDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({9}S:S$eepromRead_NegativeDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({10}S:S$eepromRead_NegativeDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({11}S:S$eepromRead_UnithHigh_bit$0$0({1}SC:U),Z,0,0)({12}S:S$eepromRead_UnitLow_bit$0$0({1}SC:U),Z,0,0)({13}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({14}S:S$delayTimes_5$0$0({2}SI:U),Z,0,0)({16}S:S$delayTimes_3$0$0({2}SI:U),Z,0,0)({18}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({20}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
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
	;--cdb--S:G$ShowADC$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GPIO_Init$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_LCD:G$main$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
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
:$L:r0x11C3
;--------------------------------------------------------
;	;.line	871; ".\ADC_LCD.c"	if(ADIF_IsFlag())
_ISR:	;Function start
	BTSS	_INTF0,5
	JMP	_00720_DS_
;	;.line	873; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	874; ".\ADC_LCD.c"	ADC=ADC_GetData();
	CALL	_ADC_GetData
	.CHKPARA _ADC_GetData 0
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	875; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=1;
	BSF	_MCUSTATUSbits,0
_00720_DS_:
;	;.line	878; ".\ADC_LCD.c"	if(TA1IF_IsFlag())  //PT1.0  Timer A1 interrupt flag 
	BTSS	_INTF1,7
	JMP	_00726_DS_
;	;.line	880; ".\ADC_LCD.c"	TA1IF_ClearFlag();
	BCF	_INTF1,7
;	;.line	881; ".\ADC_LCD.c"	adS.delayTimes_3 ++;
	MVF	(_adS + 16),0,0
	MVF	r0x11C3,1,0
	MVF	(_adS + 17),0,0
	INSUZ	r0x11C3,1,0
	ADDL	0x01
	MVSF	r0x11C3,(_adS + 16)
	MVF	(_adS + 17),1,0
;	;.line	882; ".\ADC_LCD.c"	adS.delayTimes_5++;
	MVF	(_adS + 14),0,0
	MVF	r0x11C3,1,0
	MVF	(_adS + 15),0,0
	INSUZ	r0x11C3,1,0
	ADDL	0x01
	MVSF	r0x11C3,(_adS + 14)
	MVF	(_adS + 15),1,0
;	;.line	884; ".\ADC_LCD.c"	if(adS.key_flag ==1||adS.key_flag==0) {
	DCSUZ	(_adS + 4),0,0
	JMP	_00721_DS_
	TFSZ	(_adS + 4),0
	JMP	_00726_DS_
_00721_DS_:
;	;.line	885; ".\ADC_LCD.c"	adS.delayTimes_5 = 0;
	CLRF	(_adS + 14),0
	CLRF	(_adS + 15),0
;	;.line	887; ".\ADC_LCD.c"	adS.delayTimes_3 =0;
	CLRF	(_adS + 16),0
	CLRF	(_adS + 17),0
;	;.line	889; ".\ADC_LCD.c"	adS.key_flag =2;
	MVL	0x02
	MVF	(_adS + 4),1,0
;	;.line	890; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
	MVL	0xdf
	ANDF	_PT1,0,0
	IORL	0x20
	MVF	_PT1,1,0
_00726_DS_:
;	;.line	900; ".\ADC_LCD.c"	}
	RETI	 1
; exit point of _ISR
	.ENDFUNC	_ISR
;--------------------------------------------------------

.area CCODE (code,REL,CON) ; ADC_LCD-code 
.globl _main

;--------------------------------------------------------
	.FUNC _main:0:$C:_GPIO_Iint:$C:_ADC_Open:$C:_PGAandADCAccuracyMode:$C:_DisplayUnit\
:$C:_Display2Er:$C:___slong2fs:$C:___fsmul:$C:___fs2slong:$C:_Delay\
:$C:_PositivePressureWorks_Mode:$C:___fssub:$C:_DisplayNum:$C:___fsadd:$C:_HY17P52WR3\
:$L:r0x1140:$L:r0x1141:$L:r0x1143:$L:r0x1142:$L:r0x1144\
:$L:r0x1145:$L:r0x1146:$L:r0x1147:$L:r0x1148:$L:r0x1149\
:$L:r0x114D:$L:r0x114C
;--------------------------------------------------------
;	;.line	100; ".\ADC_LCD.c"	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
_main:	;Function start
	BSF	0x35,7
	MVL	0x3f
	ANDF	_OSCCN0,1,0
;	;.line	101; ".\ADC_LCD.c"	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
	MVL	0xce
	ANDF	_OSCCN0,1,0
;	;.line	102; ".\ADC_LCD.c"	GPIO_Iint() ;
	CALL	_GPIO_Iint
	.CHKPARA _GPIO_Iint 0
;	;.line	105; ".\ADC_LCD.c"	PWR_BGREnable();
	BSF	_PWRCN,7
;	;.line	106; ".\ADC_LCD.c"	PWR_LDOPLEnable();
	BSF	_AD1CN5,4
;	;.line	107; ".\ADC_LCD.c"	PWR_LDOEnable();
	BSF	_PWRCN,1
;	;.line	108; ".\ADC_LCD.c"	PWR_LDOSel(LDOC_2V4);
	MVL	0x8f
	ANDF	_PWRCN,1,0
;	;.line	110; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
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
;	;.line	113; ".\ADC_LCD.c"	PGAandADCAccuracyMode();
	CALL	_PGAandADCAccuracyMode
	.CHKPARA _PGAandADCAccuracyMode 0
;	;.line	120; ".\ADC_LCD.c"	LCD_Enable();
	BSF	_LCDCN1,7
;	;.line	121; ".\ADC_LCD.c"	LCD_ChargePumpSelect(LCDV_3V0);
	MVL	0x8f
	ANDF	_LCDCN1,0,0
	IORL	0x40
	MVF	_LCDCN1,1,0
;	;.line	122; ".\ADC_LCD.c"	LCD_OutBufferEnable();
	BSF	_LCDCN1,3
;	;.line	123; ".\ADC_LCD.c"	LCD_ChargePumpClk(SELPCLK_14KHZ);
	BCF	_LCDCN1,2
;	;.line	125; ".\ADC_LCD.c"	LCD_DisplayOn();
	BCF	_LCDCN2,1
;	;.line	128; ".\ADC_LCD.c"	LCD_PT60Mode(LCD);   //COM0
	MVF	_LCDCN3,0,0
	ANDL	0xfc
	IORL	0x03
	MVF	_LCDCN3,1,0
	ANDL	0xf3
;	;.line	129; ".\ADC_LCD.c"	LCD_PT61Mode(LCD);	 //COM1
	IORL	0x0c
	MVF	_LCDCN3,1,0
	ANDL	0xcf
;	;.line	130; ".\ADC_LCD.c"	LCD_PT62Mode(LCD);   //COM2
	IORL	0x30
	MVF	_LCDCN3,1,0
	ANDL	0x3f
;	;.line	131; ".\ADC_LCD.c"	LCD_PT63Mode(LCD);   //COM3
	IORL	0xc0
	MVF	_LCDCN3,1,0
;	;.line	133; ".\ADC_LCD.c"	TMA1_CLKSelect(TMAS1_DMSCK); //freq = DMS_CK = 3.686Mhz/256 = 0.014398MHz      0.014398Mhz / 2= 7.2KHz
	BCF	_TMA1CN,5
;	;.line	134; ".\ADC_LCD.c"	TMA1_CLKDiv(DTMA1_TMA1CKDIV2); // fdiv = 7.2KHz ,T = 0.138ms
	MVL	0xe3
	ANDF	_TMA1CN,1,0
;	;.line	135; ".\ADC_LCD.c"	TMA1_CompSet(255);    //TMA1C cycle=10*TMA1R cycle 8bit = 255
	SETF	_TMA1C,0
;	;.line	136; ".\ADC_LCD.c"	TA1IE_Enable();
	BSF	_INTE1,7
;	;.line	138; ".\ADC_LCD.c"	TA1IF_ClearFlag();
	BCF	_INTF1,7
;	;.line	140; ".\ADC_LCD.c"	TMA1_ClearTMA1();    //Clear TMA count
	CLRF	_TMA1R,0
;	;.line	141; ".\ADC_LCD.c"	TMA1Enable();
	BSF	_TMA1CN,7
;	;.line	143; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	144; ".\ADC_LCD.c"	ADIE_Enable();
	BSF	_INTE0,5
;	;.line	145; ".\ADC_LCD.c"	GIE_Enable();
	BSF	_INTE0,7
_00173_DS_:
;	;.line	151; ".\ADC_LCD.c"	if(GPIO_READ_PT10())
	MVF	_PT1,0,0
	ANDL	0x01
	BTSZ	_STATUS,0
	JMP	_00170_DS_
;	;.line	157; ".\ADC_LCD.c"	if(adS.delayTimes_5 >= 10000){ /*unit set mode*/
	MVL	0xf0
	ADDF	(_adS + 14),0,0
	MVL	0xd8
	ADDC	(_adS + 15),0,0
	BTSS	_STATUS,4
	JMP	_00113_DS_
;	;.line	159; ".\ADC_LCD.c"	if(GPIO_READ_PT10()){
	MVF	_PT1,0,0
	ANDL	0x01
	BTSZ	_STATUS,0
	JMP	_00113_DS_
;	;.line	161; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
	MVL	0x40
	MVF	(_adS + 14),1,0
	MVL	0x1f
	MVF	(_adS + 15),1,0
;	;.line	162; ".\ADC_LCD.c"	adS.delayTimes_5 =0;
	CLRF	(_adS + 14),0
	CLRF	(_adS + 15),0
;	;.line	163; ".\ADC_LCD.c"	adS.unit_setMode =1;
	BSF	_adS,1
;	;.line	165; ".\ADC_LCD.c"	adS.testMode =1;
	BSF	(_adS+3),0
;	;.line	166; ".\ADC_LCD.c"	DisplayUnit();
	CALL	_DisplayUnit
	.CHKPARA _DisplayUnit 0
;	;.line	168; ".\ADC_LCD.c"	adS.delayTimes_3=0;
	CLRF	(_adS + 16),0
	CLRF	(_adS + 17),0
;	;.line	170; ".\ADC_LCD.c"	switch(adS.plus_uint){
	MVF	(_adS + 1),0,0
	MVF	r0x1140,1,0
	ADDL	0xfc
	BTSZ	_STATUS,4
	JMP	_00113_DS_
	MVL	HIGHD2(_00340_DS_)
	MVF	_PCLATH,1,0
	MVL	D2(_00340_DS_)
	ADDF	r0x1140,0,0
	BTSZ	_STATUS,4
	INF	_PCLATH,1,0
	MVF	_PCLATL,1,0
_00340_DS_:
	RJ	_00105_DS_
	RJ	_00106_DS_
	RJ	_00107_DS_
	RJ	_00108_DS_
_00105_DS_:
;	;.line	172; ".\ADC_LCD.c"	adS.plus_uint++;
	INF	r0x1140,0,0
	MVF	(_adS + 1),1,0
;	;.line	173; ".\ADC_LCD.c"	adS.unitChoose = psi;
	CLRF	(_adS + 2),0
;	;.line	174; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	175; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
	MVL	0x40
	MVF	(_adS + 14),1,0
	MVL	0x1f
	MVF	(_adS + 15),1,0
;	;.line	176; ".\ADC_LCD.c"	break;
	JMP	_00113_DS_
_00106_DS_:
;	;.line	178; ".\ADC_LCD.c"	adS.plus_uint++;
	INF	r0x1140,0,0
	MVF	(_adS + 1),1,0
;	;.line	179; ".\ADC_LCD.c"	adS.unitChoose = bar;
	MVL	0x01
	MVF	(_adS + 2),1,0
;	;.line	180; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
	MVL	0x02
	MVF	_LCD4,1,0
;	;.line	181; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
	MVL	0x40
	MVF	(_adS + 14),1,0
	MVL	0x1f
	MVF	(_adS + 15),1,0
;	;.line	182; ".\ADC_LCD.c"	break;
	JMP	_00113_DS_
_00107_DS_:
;	;.line	184; ".\ADC_LCD.c"	adS.plus_uint++;
	INF	r0x1140,1,0
	MVF	r0x1140,0,0
	MVF	(_adS + 1),1,0
;	;.line	185; ".\ADC_LCD.c"	adS.unitChoose = kgf;
	MVL	0x02
	MVF	(_adS + 2),1,0
;	;.line	186; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	187; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
	MVL	0x40
	MVF	(_adS + 14),1,0
	MVL	0x1f
	MVF	(_adS + 15),1,0
;	;.line	188; ".\ADC_LCD.c"	break;
	JMP	_00113_DS_
_00108_DS_:
;	;.line	190; ".\ADC_LCD.c"	adS.plus_uint=0;
	CLRF	(_adS + 1),0
;	;.line	191; ".\ADC_LCD.c"	adS.unitChoose = mpa;
	MVL	0x03
	MVF	(_adS + 2),1,0
;	;.line	192; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
	MVL	0x08
	MVF	_LCD4,1,0
;	;.line	193; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
	MVL	0x40
	MVF	(_adS + 14),1,0
	MVL	0x1f
	MVF	(_adS + 15),1,0
_00113_DS_:
;	;.line	199; ".\ADC_LCD.c"	if(adS.delayTimes_3 >=5000){ /* zero point mode*/
	MVL	0x78
	ADDF	(_adS + 16),0,0
	MVL	0xec
	ADDC	(_adS + 17),0,0
	BTSS	_STATUS,4
	JMP	_00173_DS_
;	;.line	201; ".\ADC_LCD.c"	if(GPIO_READ_PT10()){
	MVF	_PT1,0,0
	ANDL	0x01
	BTSZ	_STATUS,0
	JMP	_00173_DS_
;	;.line	202; ".\ADC_LCD.c"	adS.zeroPoint_Mode = 1;
	BSF	(_adS+3),1
;	;.line	204; ".\ADC_LCD.c"	adS.testMode =1;
	BSF	(_adS+3),0
;	;.line	205; ".\ADC_LCD.c"	adS.delayTimes_3=0;
	CLRF	(_adS + 16),0
	CLRF	(_adS + 17),0
;	;.line	207; ".\ADC_LCD.c"	Display2Er();
	CALL	_Display2Er
	.CHKPARA _Display2Er 0
	JMP	_00173_DS_
_00170_DS_:
;	;.line	218; ".\ADC_LCD.c"	if(adS.testMode == 0){ /* measure mode */
	BTSZ	(_adS+3),0
	JMP	_00138_DS_
;	;.line	219; ".\ADC_LCD.c"	adS.zeroPoint_Mode=0;
	BCF	(_adS+3),1
;	;.line	220; ".\ADC_LCD.c"	adS.key_flag =0;
	CLRF	(_adS + 4),0
;	;.line	221; ".\ADC_LCD.c"	adS.unit_setMode=0;
	BCF	_adS,1
;	;.line	222; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
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
;	;.line	223; ".\ADC_LCD.c"	ADIF_ClearFlag();
	BCF	_INTF0,5
;	;.line	224; ".\ADC_LCD.c"	ADIE_Enable();
	BSF	_INTE0,5
;	;.line	225; ".\ADC_LCD.c"	GIE_Enable();
	BSF	_INTE0,7
;	;.line	227; ".\ADC_LCD.c"	if(MCUSTATUSbits.b_ADCdone==1)
	BTSS	_MCUSTATUSbits,0
	JMP	_00138_DS_
;	;.line	229; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=0;
	BCF	_MCUSTATUSbits,0
;	;.line	231; ".\ADC_LCD.c"	ADC=ADC>>6;
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
;	;.line	233; ".\ADC_LCD.c"	ADC = ADC * 0.1 ;
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
;	;.line	234; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
;	;.line	235; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	236; ".\ADC_LCD.c"	GPIO_PT16_LOW();
	BCF	_PT1,6
;	;.line	237; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
	BTSZ	(_ADC + 3),7
	JMP	_00122_DS_
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,4
	JMP	_00123_DS_
_00122_DS_:
;	;.line	240; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00124_DS_
_00123_DS_:
;	;.line	244; ".\ADC_LCD.c"	if( ADC < 1600 && ADC >=0 ) {
	MVL	0xc0
	ADDF	_ADC,0,0
	MVL	0xf9
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSZ	_STATUS,1
	JMP	_00119_DS_
	BTSZ	(_ADC + 3),7
	JMP	_00119_DS_
;	;.line	245; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00124_DS_
_00119_DS_:
;	;.line	249; ".\ADC_LCD.c"	adS.Pressure_sign =0;
	BCF	(_adS+6),6
_00124_DS_:
;	;.line	255; ".\ADC_LCD.c"	if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/
	BTSZ	(_adS+6),6
	JMP	_00133_DS_
;	;.line	257; ".\ADC_LCD.c"	PositivePressureWorks_Mode();
	CALL	_PositivePressureWorks_Mode
	.CHKPARA _PositivePressureWorks_Mode 0
	JMP	_00138_DS_
_00133_DS_:
;	;.line	261; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
;	;.line	264; ".\ADC_LCD.c"	theta= abs(ADC) - adS.m_offset_value;  
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00177_DS_
	MVF	_ADC,0,0
	MVF	r0x1144,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1145,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1146,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1147,1,0
	JMP	_00178_DS_
_00177_DS_:
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
_00178_DS_:
	MVL	0x00
	BTSZ	(_adS + 19),7
	MVL	0xff
	MVF	r0x114D,1,0
	MVF	r0x114C,1,0
	MVF	(_adS + 18),0,0
	SUBF	r0x1144,1,0
	MVF	(_adS + 19),0,0
	SUBC	r0x1145,1,0
	MVF	r0x114C,0,0
	SUBC	r0x1146,1,0
	MVF	r0x114D,0,0
	SUBC	r0x1147,1,0
;	;.line	265; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
	BTSS	(_adS+6),4
	JMP	_00130_DS_
;	;.line	270; ".\ADC_LCD.c"	if(delta >=0 ){
	BTSZ	(_ADC + 3),7
	JMP	_00127_DS_
;	;.line	271; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
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
;	;.line	272; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
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
;	;.line	273; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00138_DS_
_00127_DS_:
;	;.line	284; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
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
;	;.line	285; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
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
;	;.line	286; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00138_DS_
_00130_DS_:
;	;.line	293; ".\ADC_LCD.c"	ADC = abs(ADC);
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00179_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1142,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x1143,1,0
	JMP	_00180_DS_
_00179_DS_:
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
_00180_DS_:
	MVF	r0x1140,0,0
	MVF	_ADC,1,0
	MVF	r0x1141,0,0
	MVF	(_ADC + 1),1,0
	MVF	r0x1142,0,0
	MVF	(_ADC + 2),1,0
	MVF	r0x1143,0,0
	MVF	(_ADC + 3),1,0
;	;.line	294; ".\ADC_LCD.c"	DisplayNum(ADC);
	MVF	_ADC,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	295; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00138_DS_:
;	;.line	300; ".\ADC_LCD.c"	if(adS.zeroPoint_Mode == 1){ /*zero point mode */
	BTSS	(_adS+3),1
	JMP	_00147_DS_
;	;.line	302; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
;	;.line	303; ".\ADC_LCD.c"	adS.testMode=0;
	BCF	(_adS+3),0
;	;.line	304; ".\ADC_LCD.c"	ADC=ADC>>6;
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
;	;.line	305; ".\ADC_LCD.c"	ADC = ADC * 0.1;
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
;	;.line	306; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
	BTSZ	(_ADC + 3),7
	JMP	_00139_DS_
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,4
	JMP	_00140_DS_
_00139_DS_:
;	;.line	309; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00141_DS_
_00140_DS_:
;	;.line	313; ".\ADC_LCD.c"	adS.Pressure_sign =0;
	BCF	(_adS+6),6
_00141_DS_:
;	;.line	319; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
	BTSS	(_adS+6),6
	JMP	_00144_DS_
;	;.line	320; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00181_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	JMP	_00182_DS_
_00181_DS_:
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
_00182_DS_:
	MVL	0x37
	ADDF	r0x1140,0,0
	MVF	r0x1140,1,0
	MVL	0xe7
	ADDC	r0x1141,0,0
	MVSF	r0x1140,(_adS + 18)
	MVF	(_adS + 19),1,0
;	;.line	321; ".\ADC_LCD.c"	adS.minus_revise_flag=1;
	BSF	(_adS+6),4
	JMP	_00147_DS_
_00144_DS_:
;	;.line	327; ".\ADC_LCD.c"	adS.p_offset_value= abs(STD_VALUE) -abs(ADC) + 1; 
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00183_DS_
	MVF	_ADC,0,0
	MVF	r0x1140,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1141,1,0
	JMP	_00184_DS_
_00183_DS_:
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
_00184_DS_:
	COMF	r0x1140,0,0
	ADDL	0x7e
	MVF	r0x1140,1,0
	COMF	r0x1141,1,0
	MVL	0x19
	ADDC	r0x1141,1,0
	MVF	r0x1140,0,0
	MVF	(_adS + 20),1,0
	MVF	r0x1141,0,0
	MVF	(_adS + 21),1,0
;	;.line	328; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
	BSF	(_adS+6),3
;	;.line	329; ".\ADC_LCD.c"	DisplayNum( adS.p_offset_value);
	MVL	0x00
	BTSZ	r0x1141,7
	MVL	0xff
	MVF	r0x1149,1,0
	MVF	r0x1148,1,0
	MVF	r0x1140,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	r0x1141,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	r0x1148,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x1149,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	330; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00147_DS_:
;	;.line	336; ".\ADC_LCD.c"	if(adS.unit_setMode ==1){
	BTSS	_adS,1
	JMP	_00173_DS_
;	;.line	338; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
	BCF	_adS,1
;	;.line	339; ".\ADC_LCD.c"	adS.testMode = 0;
	BCF	(_adS+3),0
;	;.line	343; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,0x02);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
	MVL	0x02
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0xaa
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x00
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	344; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00152_DS_
;	;.line	346; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00149_DS_:
;	;.line	347; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00149_DS_
_00152_DS_:
;	;.line	351; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
	CLRF	_BIEARL,0
;	;.line	352; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00153_DS_:
;	;.line	353; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1140,1,0
	DCF	r0x1140,0,0
	RRF	_WREG,0,0
	BTSZ	_STATUS,0
	JMP	_00153_DS_
;	;.line	354; ".\ADC_LCD.c"	delta=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	r0x1140,1,0
;	;.line	356; ".\ADC_LCD.c"	if(delta==0)  LCD_WriteData(&LCD4, seg_bar) ; 
	IORL	0x00
	TFSZ	_WREG,0
	JMP	_00165_DS_
	MVL	0x02
	MVF	_LCD4,1,0
	JMP	_00173_DS_
_00165_DS_:
;	;.line	357; ".\ADC_LCD.c"	else if(delta==1)LCD_WriteData(&LCD4, seg_kgf) ; 
	DCF	r0x1140,0,0
	TFSZ	_WREG,0
	JMP	_00162_DS_
	MVL	0x01
	MVF	_LCD4,1,0
	JMP	_00173_DS_
_00162_DS_:
;	;.line	358; ".\ADC_LCD.c"	else if(delta==2)LCD_WriteData(&LCD4, seg_mpa) ; 
	MVF	r0x1140,0,0
	XORL	0x02
	TFSZ	_WREG,0
	JMP	_00159_DS_
	MVL	0x08
	MVF	_LCD4,1,0
	JMP	_00173_DS_
_00159_DS_:
;	;.line	359; ".\ADC_LCD.c"	else if(delta==3)LCD_WriteData(&LCD4, seg_psi) ; 
	MVF	r0x1140,0,0
	XORL	0x03
	TFSZ	_WREG,0
	JMP	_00173_DS_
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	370; ".\ADC_LCD.c"	}
	JMP	_00173_DS_
	.ENDFUNC	_main
;--------------------------------------------------------

.globl _SetupUnitAndZeroPoint_Mode

;--------------------------------------------------------
	.FUNC _SetupUnitAndZeroPoint_Mode:0:$C:_DisplayUnit:$C:_Delay\
:$L:r0x11C1
;--------------------------------------------------------
;	;.line	815; ".\ADC_LCD.c"	adS.unit_setMode =1;
_SetupUnitAndZeroPoint_Mode:	;Function start
	BSF	_adS,1
;	;.line	816; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
;	;.line	817; ".\ADC_LCD.c"	adS.testMode =1;
	BSF	(_adS+3),0
;	;.line	818; ".\ADC_LCD.c"	DisplayUnit();
	CALL	_DisplayUnit
	.CHKPARA _DisplayUnit 0
;	;.line	822; ".\ADC_LCD.c"	switch(adS.unitChoose){
	MVF	(_adS + 2),0,0
	MVF	r0x11C1,1,0
	MVL	0x04
	CPSL	r0x11C1,0
	JMP	_00708_DS_
	MVL	HIGHD2(_00714_DS_)
	MVF	_PCLATH,1,0
	MVL	D2(_00714_DS_)
	ADDF	r0x11C1,0,0
	BTSZ	_STATUS,4
	INF	_PCLATH,1,0
	MVF	_PCLATL,1,0
_00714_DS_:
	RJ	_00703_DS_
	RJ	_00704_DS_
	RJ	_00705_DS_
	RJ	_00706_DS_
_00703_DS_:
;	;.line	824; ".\ADC_LCD.c"	adS.unitChoose++;
	INF	r0x11C1,0,0
	MVF	(_adS + 2),1,0
;	;.line	825; ".\ADC_LCD.c"	adS.unitChoose = psi;
	CLRF	(_adS + 2),0
;	;.line	828; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
	MVL	0xdf
	ANDF	_PT1,0,0
	IORL	0x20
	MVF	_PT1,1,0
;	;.line	829; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	830; ".\ADC_LCD.c"	Delay(20000);  
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	831; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	832; ".\ADC_LCD.c"	break;
	JMP	_00708_DS_
_00704_DS_:
;	;.line	834; ".\ADC_LCD.c"	adS.unitChoose++;
	INF	r0x11C1,0,0
	MVF	(_adS + 2),1,0
;	;.line	835; ".\ADC_LCD.c"	adS.unitChoose = bar;
	MVL	0x01
	MVF	(_adS + 2),1,0
;	;.line	836; ".\ADC_LCD.c"	GPIO_PT15_LOW();
	BCF	_PT1,5
;	;.line	838; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
	MVL	0x02
	MVF	_LCD4,1,0
;	;.line	839; ".\ADC_LCD.c"	Delay(20000); 
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	840; ".\ADC_LCD.c"	Delay(10000);
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	841; ".\ADC_LCD.c"	break;
	JMP	_00708_DS_
_00705_DS_:
;	;.line	843; ".\ADC_LCD.c"	adS.unitChoose++;
	INF	r0x11C1,1,0
	MVF	r0x11C1,0,0
	MVF	(_adS + 2),1,0
;	;.line	844; ".\ADC_LCD.c"	adS.unitChoose = kgf;
	MVL	0x02
	MVF	(_adS + 2),1,0
;	;.line	845; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
	MVL	0xdf
	ANDF	_PT1,0,0
	IORL	0x20
	MVF	_PT1,1,0
;	;.line	847; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	848; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	849; ".\ADC_LCD.c"	Delay(10000);  
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	851; ".\ADC_LCD.c"	break;
	JMP	_00708_DS_
_00706_DS_:
;	;.line	853; ".\ADC_LCD.c"	adS.unitChoose=0;
	CLRF	(_adS + 2),0
;	;.line	854; ".\ADC_LCD.c"	adS.unitChoose = mpa;
	MVL	0x03
	MVF	(_adS + 2),1,0
;	;.line	855; ".\ADC_LCD.c"	GPIO_PT15_LOW();
	BCF	_PT1,5
;	;.line	857; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
	MVL	0x08
	MVF	_LCD4,1,0
;	;.line	859; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	860; ".\ADC_LCD.c"	Delay(10000);  
	MVL	0x10
	MVF	_Delay_STK00,1,0
	MVL	0x27
	CALL	_Delay
	.CHKPARA _Delay 2
_00708_DS_:
;	;.line	863; ".\ADC_LCD.c"	}
	RET	
; exit point of _SetupUnitAndZeroPoint_Mode
	.ENDFUNC	_SetupUnitAndZeroPoint_Mode
;--------------------------------------------------------

.globl _NegativePressureWorks_Mode

;--------------------------------------------------------
	.FUNC _NegativePressureWorks_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fssub:$C:___fs2slong\
:$C:_Reverse_Data:$C:_UnitConverter:$C:_DisplayNum:$C:_LowVoltageDisplay:$C:_Delay\
:$C:___fsadd\
:$L:r0x11AF:$L:r0x11B0:$L:r0x11B1:$L:r0x11B2:$L:r0x11B3\
:$L:r0x11B4:$L:r0x11B5:$L:r0x11B6:$L:r0x11B7:$L:r0x11B8\
:$L:r0x11B9:$L:r0x11BA:$L:r0x11BC:$L:r0x11BB:$L:r0x11BE\
:$L:r0x11C0:$L:r0x11BF
;--------------------------------------------------------
;	;.line	732; ".\ADC_LCD.c"	adS.Pressure_sign =1;
_NegativePressureWorks_Mode:	;Function start
	BSF	(_adS+6),6
;	;.line	734; ".\ADC_LCD.c"	BIEARL=3;                                //addr=1
	MVL	0x03
	MVF	_BIEARL,1,0
;	;.line	735; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00624_DS_:
;	;.line	736; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x11B3,1,0
	DCF	r0x11B3,0,0
	BTSZ	_STATUS,0
	JMP	_00624_DS_
;	;.line	737; ".\ADC_LCD.c"	adS.eepromRead_NegativeDeltaLow_bit1=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 9),1,0
;	;.line	740; ".\ADC_LCD.c"	BIEARL=4;                                //addr=1
	MVL	0x04
	MVF	_BIEARL,1,0
;	;.line	741; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00627_DS_:
;	;.line	742; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x11B3,1,0
	DCF	r0x11B3,0,0
	BTSZ	_STATUS,0
	JMP	_00627_DS_
;	;.line	743; ".\ADC_LCD.c"	adS.eepromRead_NegativeDeltaLow_bit2=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 10),1,0
;	;.line	745; ".\ADC_LCD.c"	if(adS.eepromRead_NegativeDeltaLow_bit1 ==0 ){
	TFSZ	(_adS + 9),0
	JMP	_00631_DS_
;	;.line	747; ".\ADC_LCD.c"	theta =abs(ADC) + adS.eepromRead_NegativeDeltaLow_bit2 ;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00641_DS_
	MVF	_ADC,0,0
	MVF	r0x11B3,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x11B4,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x11B5,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x11B6,1,0
	JMP	_00642_DS_
_00641_DS_:
	COMF	_ADC,0,0
	MVF	r0x11B3,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x11B4,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x11B5,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x11B6,1,0
	INF	r0x11B3,1,0
	MVL	0x00
	ADDC	r0x11B4,1,0
	ADDC	r0x11B5,1,0
	ADDC	r0x11B6,1,0
_00642_DS_:
	CLRF	r0x11BA,0
	MVL	0x00
	BTSZ	r0x11BA,7
	MVL	0xff
	MVF	r0x11BC,1,0
	MVF	r0x11BB,1,0
	MVF	(_adS + 10),0,0
	ADDF	r0x11B3,1,0
	MVF	r0x11BA,0,0
	ADDC	r0x11B4,1,0
	MVF	r0x11BB,0,0
	ADDC	r0x11B5,1,0
	MVF	r0x11BC,0,0
	ADDC	r0x11B6,1,0
	JMP	_00632_DS_
_00631_DS_:
;	;.line	751; ".\ADC_LCD.c"	theta =abs(ADC) - adS.eepromRead_NegativeDeltaLow_bit1 ;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00643_DS_
	MVF	_ADC,0,0
	MVF	r0x11B7,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x11B8,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x11B9,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x11BA,1,0
	JMP	_00644_DS_
_00643_DS_:
	COMF	_ADC,0,0
	MVF	r0x11B7,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x11B8,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x11B9,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x11BA,1,0
	INF	r0x11B7,1,0
	MVL	0x00
	ADDC	r0x11B8,1,0
	ADDC	r0x11B9,1,0
	ADDC	r0x11BA,1,0
_00644_DS_:
	CLRF	r0x11BE,0
	MVL	0x00
	BTSZ	r0x11BE,7
	MVL	0xff
	MVF	r0x11C0,1,0
	MVF	r0x11BF,1,0
	MVF	(_adS + 9),0,0
	SUBF	r0x11B7,0,0
	MVF	r0x11B3,1,0
	MVF	r0x11BE,0,0
	SUBC	r0x11B8,0,0
	MVF	r0x11B4,1,0
	MVF	r0x11BF,0,0
	SUBC	r0x11B9,0,0
	MVF	r0x11B5,1,0
	MVF	r0x11C0,0,0
	SUBC	r0x11BA,0,0
	MVF	r0x11B6,1,0
_00632_DS_:
;	;.line	755; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
	BTSS	(_adS+6),4
	JMP	_00637_DS_
;	;.line	758; ".\ADC_LCD.c"	if( omega >=0 ){
	BTSZ	(_ADC + 3),7
	JMP	_00634_DS_
;	;.line	759; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
	MVF	r0x11B3,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x11B4,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x11B5,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x11B6,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x11B2,0,0
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
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK06,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK05,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK04,1,0
	MVF	r0x11B2,0,0
	MVF	___fssub_STK03,1,0
	CLRF	___fssub_STK02,0
	CLRF	___fssub_STK01,0
	MVL	0x48
	MVF	___fssub_STK00,1,0
	MVL	0x43
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	760; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	761; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_UnitConverter
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	762; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	763; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	765; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00639_DS_
_00634_DS_:
;	;.line	776; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
	MVF	r0x11B3,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x11B4,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x11B5,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x11B6,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x11B2,0,0
	MVF	___fsmul_STK03,1,0
	CLRF	___fsmul_STK02,0
	CLRF	___fsmul_STK01,0
	CLRF	___fsmul_STK00,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x11B2,1,0
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
	MVF	r0x11B2,0,0
	CALL	___fsadd
	.CHKPARA ___fsadd 8
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	777; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	778; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_UnitConverter
	MVF	r0x11B2,1,0
	MVF	STK02,0,0
;	;.line	779; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x11B2,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	780; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	782; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00639_DS_
_00637_DS_:
;	;.line	788; ".\ADC_LCD.c"	ADC = abs(ADC);
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00645_DS_
	MVF	_ADC,0,0
	MVF	r0x11AF,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x11B0,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x11B1,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x11B2,1,0
	JMP	_00646_DS_
_00645_DS_:
	COMF	_ADC,0,0
	MVF	r0x11AF,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x11B0,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x11B1,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x11B2,1,0
	INF	r0x11AF,1,0
	MVL	0x00
	ADDC	r0x11B0,1,0
	ADDC	r0x11B1,1,0
	ADDC	r0x11B2,1,0
_00646_DS_:
	MVF	r0x11AF,0,0
	MVF	_ADC,1,0
	MVF	r0x11B0,0,0
	MVF	(_ADC + 1),1,0
	MVF	r0x11B1,0,0
	MVF	(_ADC + 2),1,0
	MVF	r0x11B2,0,0
	MVF	(_ADC + 3),1,0
;	;.line	789; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
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
;	;.line	790; ".\ADC_LCD.c"	DisplayNum(ADC);
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	791; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	793; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00639_DS_:
;	;.line	798; ".\ADC_LCD.c"	}
	RET	
; exit point of _NegativePressureWorks_Mode
	.ENDFUNC	_NegativePressureWorks_Mode
;--------------------------------------------------------

.globl _PositivePressureWorks_Mode

;--------------------------------------------------------
	.FUNC _PositivePressureWorks_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fssub:$C:___fs2slong\
:$C:_DisplayNum:$C:__mullong:$C:_Reverse_Data:$C:_UnitConverter:$C:_LowVoltageDisplay\
:$C:_Delay\
:$L:r0x1197:$L:r0x1198:$L:r0x1199:$L:r0x119A:$L:r0x119B\
:$L:r0x119C:$L:r0x119D:$L:r0x119E:$L:r0x11A0:$L:r0x119F\
:$L:r0x11A2:$L:r0x11A4:$L:r0x11A3
;--------------------------------------------------------
;	;.line	657; ".\ADC_LCD.c"	BIEARL=1;                                //addr=1
_PositivePressureWorks_Mode:	;Function start
	MVL	0x01
	MVF	_BIEARL,1,0
;	;.line	658; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00544_DS_:
;	;.line	659; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1197,1,0
	DCF	r0x1197,0,0
	BTSZ	_STATUS,0
	JMP	_00544_DS_
;	;.line	660; ".\ADC_LCD.c"	adS.eepromRead_PositiveDeltaLow_bit1=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 7),1,0
;	;.line	663; ".\ADC_LCD.c"	BIEARL=2;                                //addr=1
	MVL	0x02
	MVF	_BIEARL,1,0
;	;.line	664; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00547_DS_:
;	;.line	665; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1197,1,0
	DCF	r0x1197,0,0
	BTSZ	_STATUS,0
	JMP	_00547_DS_
;	;.line	666; ".\ADC_LCD.c"	adS.eepromRead_PositiveDeltaLow_bit2=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 8),1,0
;	;.line	668; ".\ADC_LCD.c"	if(adS.eepromRead_PositiveDeltaLow_bit1 ==0 ){
	TFSZ	(_adS + 7),0
	JMP	_00551_DS_
;	;.line	670; ".\ADC_LCD.c"	delta =abs(ADC) + adS.eepromRead_PositiveDeltaLow_bit2 ;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00564_DS_
	MVF	_ADC,0,0
	MVF	r0x1197,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x1198,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x1199,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x119A,1,0
	JMP	_00565_DS_
_00564_DS_:
	COMF	_ADC,0,0
	MVF	r0x1197,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x1198,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1199,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x119A,1,0
	INF	r0x1197,1,0
	MVL	0x00
	ADDC	r0x1198,1,0
	ADDC	r0x1199,1,0
	ADDC	r0x119A,1,0
_00565_DS_:
	CLRF	r0x119E,0
	MVL	0x00
	BTSZ	r0x119E,7
	MVL	0xff
	MVF	r0x11A0,1,0
	MVF	r0x119F,1,0
	MVF	(_adS + 8),0,0
	ADDF	r0x1197,1,0
	MVF	r0x119E,0,0
	ADDC	r0x1198,1,0
	MVF	r0x119F,0,0
	ADDC	r0x1199,1,0
	MVF	r0x11A0,0,0
	ADDC	r0x119A,1,0
	JMP	_00552_DS_
_00551_DS_:
;	;.line	674; ".\ADC_LCD.c"	delta =abs(ADC) - adS.eepromRead_PositiveDeltaLow_bit1 ;
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00566_DS_
	MVF	_ADC,0,0
	MVF	r0x119B,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x119C,1,0
	MVF	(_ADC + 2),0,0
	MVF	r0x119D,1,0
	MVF	(_ADC + 3),0,0
	MVF	r0x119E,1,0
	JMP	_00567_DS_
_00566_DS_:
	COMF	_ADC,0,0
	MVF	r0x119B,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x119C,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x119D,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x119E,1,0
	INF	r0x119B,1,0
	MVL	0x00
	ADDC	r0x119C,1,0
	ADDC	r0x119D,1,0
	ADDC	r0x119E,1,0
_00567_DS_:
	CLRF	r0x11A2,0
	MVL	0x00
	BTSZ	r0x11A2,7
	MVL	0xff
	MVF	r0x11A4,1,0
	MVF	r0x11A3,1,0
	MVF	(_adS + 7),0,0
	SUBF	r0x119B,0,0
	MVF	r0x1197,1,0
	MVF	r0x11A2,0,0
	SUBC	r0x119C,0,0
	MVF	r0x1198,1,0
	MVF	r0x11A3,0,0
	SUBC	r0x119D,0,0
	MVF	r0x1199,1,0
	MVF	r0x11A4,0,0
	SUBC	r0x119E,0,0
	MVF	r0x119A,1,0
_00552_DS_:
;	;.line	677; ".\ADC_LCD.c"	LCDDisplay= (0.1 * delta)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
	MVF	r0x1197,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	r0x1198,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	r0x1199,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x119A,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x119E,1,0
	MVF	STK00,0,0
	MVF	r0x119D,1,0
	MVF	STK01,0,0
	MVF	r0x119C,1,0
	MVF	STK02,0,0
	MVF	r0x119B,1,0
	MVF	___fsmul_STK06,1,0
	MVF	r0x119C,0,0
	MVF	___fsmul_STK05,1,0
	MVF	r0x119D,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x119E,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x11A2,1,0
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
	MVF	r0x11A2,0,0
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x11A2,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x11A2,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x11A2,1,0
;	;.line	679; ".\ADC_LCD.c"	if(adS.plus_revise_flag ==1){
	BTSS	(_adS+6),3
	JMP	_00560_DS_
;	;.line	681; ".\ADC_LCD.c"	if(delta<2000)DisplayNum(ADC);
	MVL	0x30
	ADDF	r0x1197,0,0
	MVL	0xf8
	ADDC	r0x1198,0,0
	MVL	0xff
	ADDC	r0x1199,0,0
	MVL	0x7f
	ADDC	r0x119A,0,0
	BTSZ	_STATUS,1
	JMP	_00557_DS_
	MVF	_ADC,0,0
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
	JMP	_00562_DS_
_00557_DS_:
;	;.line	683; ".\ADC_LCD.c"	else if( (LCDDisplay *10) < 2875){
	MVF	STK02,0,0
	MVF	__mullong_STK06,1,0
	MVF	STK01,0,0
	MVF	__mullong_STK05,1,0
	MVF	STK00,0,0
	MVF	__mullong_STK04,1,0
	MVF	r0x11A2,0,0
	MVF	__mullong_STK03,1,0
	MVL	0x0a
	MVF	__mullong_STK02,1,0
	CLRF	__mullong_STK01,0
	CLRF	__mullong_STK00,0
	MVL	0x00
	CALL	__mullong
	.CHKPARA __mullong 8
	MVF	r0x119A,1,0
	MVF	STK02,0,0
	ADDL	0xc5
	MVL	0xf4
	ADDC	STK01,0,0
	MVL	0xff
	ADDC	STK00,0,0
	MVL	0x7f
	ADDC	r0x119A,0,0
	BTSZ	_STATUS,1
	JMP	_00554_DS_
;	;.line	684; ".\ADC_LCD.c"	LCDDisplay= 0.125 *delta- 202.86; //y = 0.0125x - 20.286
	MVF	r0x119B,0,0
	MVF	___fsmul_STK06,1,0
	MVF	r0x119C,0,0
	MVF	___fsmul_STK05,1,0
	MVF	r0x119D,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x119E,0,0
	MVF	___fsmul_STK03,1,0
	CLRF	___fsmul_STK02,0
	CLRF	___fsmul_STK01,0
	CLRF	___fsmul_STK00,0
	MVL	0x3e
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x119A,1,0
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
	MVF	r0x119A,0,0
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x119A,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x119A,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	685; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	686; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_UnitConverter
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	687; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	688; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	690; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00562_DS_
_00554_DS_:
;	;.line	696; ".\ADC_LCD.c"	LCDDisplay= 56193  - (8.47 * delta) ;//y=-0.846x + 5619.3
	MVF	r0x119B,0,0
	MVF	___fsmul_STK06,1,0
	MVF	r0x119C,0,0
	MVF	___fsmul_STK05,1,0
	MVF	r0x119D,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x119E,0,0
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
	MVF	r0x119A,1,0
	MVF	STK02,0,0
	MVF	___fssub_STK06,1,0
	MVF	STK01,0,0
	MVF	___fssub_STK05,1,0
	MVF	STK00,0,0
	MVF	___fssub_STK04,1,0
	MVF	r0x119A,0,0
	MVF	___fssub_STK03,1,0
	CLRF	___fssub_STK02,0
	MVL	0x81
	MVF	___fssub_STK01,1,0
	MVL	0x5b
	MVF	___fssub_STK00,1,0
	MVL	0x47
	CALL	___fssub
	.CHKPARA ___fssub 8
	MVF	r0x119A,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x119A,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	697; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
	MVF	_Reverse_Data_STK02,1,0
	MVF	STK01,0,0
	MVF	_Reverse_Data_STK01,1,0
	MVF	STK00,0,0
	MVF	_Reverse_Data_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_Reverse_Data
	.CHKPARA _Reverse_Data 4
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	698; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
	MVF	_UnitConverter_STK02,1,0
	MVF	STK01,0,0
	MVF	_UnitConverter_STK01,1,0
	MVF	STK00,0,0
	MVF	_UnitConverter_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_UnitConverter
	MVF	r0x119A,1,0
	MVF	STK02,0,0
;	;.line	699; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
	MVF	_DisplayNum_STK02,1,0
	MVF	STK01,0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	STK00,0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	r0x119A,0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	700; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	702; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
	JMP	_00562_DS_
_00560_DS_:
;	;.line	709; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
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
;	;.line	710; ".\ADC_LCD.c"	DisplayNum(ADC);
	MVF	_DisplayNum_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	_DisplayNum_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	_DisplayNum_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	_DisplayNum
	.CHKPARA _DisplayNum 4
;	;.line	711; ".\ADC_LCD.c"	LowVoltageDisplay();
	CALL	_LowVoltageDisplay
;	;.line	713; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
_00562_DS_:
;	;.line	717; ".\ADC_LCD.c"	}
	RET	
; exit point of _PositivePressureWorks_Mode
	.ENDFUNC	_PositivePressureWorks_Mode
;--------------------------------------------------------

.globl _SetupUnit_Mode

;--------------------------------------------------------
	.FUNC _SetupUnit_Mode:0:$C:_Delay:$C:_HY17P52WR3\
:$L:r0x1195
;--------------------------------------------------------
;	;.line	606; ".\ADC_LCD.c"	adS.Presskey_flag=0;
_SetupUnit_Mode:	;Function start
	BCF	(_adS+6),5
;	;.line	607; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
	BCF	_adS,1
;	;.line	608; ".\ADC_LCD.c"	adS.testMode = 0;
	BCF	(_adS+3),0
;	;.line	609; ".\ADC_LCD.c"	adS.reload_ADCInterrupt = 1;
	BSF	(_adS+13),0
;	;.line	610; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
	CLRF	(_adS + 5),0
;	;.line	611; ".\ADC_LCD.c"	adS.key_flag =0;
	CLRF	(_adS + 4),0
;	;.line	613; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
;	;.line	614; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	615; ".\ADC_LCD.c"	GPIO_PT16_LOW();
	BCF	_PT1,6
;	;.line	616; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	617; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
;	;.line	618; ".\ADC_LCD.c"	Delay(20000);
	MVL	0x20
	MVF	_Delay_STK00,1,0
	MVL	0x4e
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	619; ".\ADC_LCD.c"	GPIO_PT16_LOW();
	BCF	_PT1,6
;	;.line	622; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
	MVF	(_adS + 2),0,0
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0xaa
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x00
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	623; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00490_DS_
;	;.line	625; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00487_DS_:
;	;.line	626; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00487_DS_
_00490_DS_:
;	;.line	630; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
	CLRF	_BIEARL,0
;	;.line	631; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00491_DS_:
;	;.line	632; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1195,1,0
	DCF	r0x1195,0,0
	BTSZ	_STATUS,0
	JMP	_00491_DS_
;	;.line	633; ".\ADC_LCD.c"	adS.eepromRead_UnitLow_bit=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 12),1,0
	MVF	r0x1195,1,0
;	;.line	635; ".\ADC_LCD.c"	if(adS.eepromRead_UnitLow_bit==0)  LCD_WriteData(&LCD4, seg_bar) ; 
	TFSZ	_WREG,0
	JMP	_00503_DS_
	MVL	0x02
	MVF	_LCD4,1,0
	JMP	_00505_DS_
_00503_DS_:
;	;.line	636; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==1)LCD_WriteData(&LCD4, seg_kgf) ; 
	DCSZ	r0x1195,0,0
	JMP	_00500_DS_
	MVL	0x01
	MVF	_LCD4,1,0
	JMP	_00505_DS_
_00500_DS_:
;	;.line	637; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==2)LCD_WriteData(&LCD4, seg_mpa) ; 
	MVF	r0x1195,0,0
	XORL	0x02
	BTSS	_STATUS,0
	JMP	_00497_DS_
	MVL	0x08
	MVF	_LCD4,1,0
	JMP	_00505_DS_
_00497_DS_:
;	;.line	638; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==3)LCD_WriteData(&LCD4, seg_psi) ; 
	MVF	r0x1195,0,0
	XORL	0x03
	BTSS	_STATUS,0
	JMP	_00505_DS_
	MVL	0x04
	MVF	_LCD4,1,0
_00505_DS_:
;	;.line	642; ".\ADC_LCD.c"	}
	RET	
; exit point of _SetupUnit_Mode
	.ENDFUNC	_SetupUnit_Mode
;--------------------------------------------------------

.globl _SetupZeroPoint_Mode

;--------------------------------------------------------
	.FUNC _SetupZeroPoint_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fs2slong:$C:_HY17P52WR3\
:$L:r0x1190:$L:r0x118F:$L:r0x118E:$L:r0x118D:$L:r0x1191\
:$L:r0x1192
;--------------------------------------------------------
;	;.line	504; ".\ADC_LCD.c"	adS.key_flag =0;
_SetupZeroPoint_Mode:	;Function start
	CLRF	(_adS + 4),0
;	;.line	505; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
	CLRF	(_adS + 5),0
;	;.line	506; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
	BCF	(_adS+3),1
;	;.line	507; ".\ADC_LCD.c"	adS.testMode=0;
	BCF	(_adS+3),0
;	;.line	508; ".\ADC_LCD.c"	ADC=ADC>>6;
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
;	;.line	509; ".\ADC_LCD.c"	ADC = ADC * 0.1;
	MVF	_ADC,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	(_ADC + 1),0,0
	MVF	___slong2fs_STK01,1,0
	MVF	(_ADC + 2),0,0
	MVF	___slong2fs_STK00,1,0
	MVF	(_ADC + 3),0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1190,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1190,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1190,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1190,0,0
	CALL	___fs2slong
	.CHKPARA ___fs2slong 4
	MVF	(_ADC + 3),1,0
	MVF	STK00,0,0
	MVF	(_ADC + 2),1,0
	MVF	STK01,0,0
	MVF	(_ADC + 1),1,0
	MVF	STK02,0,0
	MVF	_ADC,1,0
;	;.line	510; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
	BTSZ	(_ADC + 3),7
	JMP	_00417_DS_
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,4
	JMP	_00418_DS_
_00417_DS_:
;	;.line	513; ".\ADC_LCD.c"	adS.Pressure_sign =1;
	BSF	(_adS+6),6
	JMP	_00419_DS_
_00418_DS_:
;	;.line	517; ".\ADC_LCD.c"	adS.Pressure_sign =0;
	BCF	(_adS+6),6
_00419_DS_:
;	;.line	523; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
	BTSS	(_adS+6),6
	JMP	_00468_DS_
;	;.line	525; ".\ADC_LCD.c"	adS.minus_revise_flag=1;   
	BSF	(_adS+6),4
;	;.line	526; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1; //
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00472_DS_
	MVF	_ADC,0,0
	MVF	r0x118D,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x118E,1,0
	JMP	_00473_DS_
_00472_DS_:
	COMF	_ADC,0,0
	MVF	r0x118D,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x118E,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x118F,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1190,1,0
	INF	r0x118D,1,0
	MVL	0x00
	ADDC	r0x118E,1,0
	ADDC	r0x118F,1,0
	ADDC	r0x1190,1,0
_00473_DS_:
	MVL	0x37
	ADDF	r0x118D,0,0
	MVF	r0x118D,1,0
	MVL	0xe7
	ADDC	r0x118E,0,0
	MVSF	r0x118D,(_adS + 18)
	MVF	(_adS + 19),1,0
;	;.line	527; ".\ADC_LCD.c"	if(adS.m_offset_value >=0){
	BTSZ	_STATUS,2
	JMP	_00442_DS_
;	;.line	529; ".\ADC_LCD.c"	HY17P52WR3(3,0x33,adS.m_offset_value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
	MVF	(_adS + 18),0,0
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0x33
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x03
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	530; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00425_DS_
;	;.line	532; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00422_DS_:
;	;.line	533; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00422_DS_
_00425_DS_:
;	;.line	535; ".\ADC_LCD.c"	HY17P52WR3(4,0x20,0x0);
	CLRF	_HY17P52WR3_STK01,0
	MVL	0x20
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x04
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	536; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00470_DS_
;	;.line	538; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00427_DS_:
;	;.line	539; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00427_DS_
_00442_DS_:
;	;.line	543; ".\ADC_LCD.c"	adS.m_offset_value = abs(adS.m_offset_value); //write delta data in eeprom
	DCF	(_adS + 18),0,0
	MVL	0x7f
	ADDC	(_adS + 19),0,0
	BTSS	_STATUS,1
	JMP	_00474_DS_
	MVF	(_adS + 18),0,0
	MVF	r0x118D,1,0
	JMP	_00475_DS_
_00474_DS_:
	COMF	(_adS + 18),0,0
	MVF	r0x118D,1,0
	COMF	(_adS + 19),0,0
	INSUZ	r0x118D,1,0
	ADDL	0x01
	MVF	r0x118E,1,0
_00475_DS_:
	MVF	r0x118D,0,0
	MVF	(_adS + 18),1,0
;	;.line	544; ".\ADC_LCD.c"	HY17P52WR3(4,0x44,adS.m_offset_value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
	MVSF	r0x118E,(_adS + 19)
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0x44
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x04
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	545; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00435_DS_
;	;.line	547; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00432_DS_:
;	;.line	548; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00432_DS_
_00435_DS_:
;	;.line	550; ".\ADC_LCD.c"	HY17P52WR3(3,0x20,0x0);
	CLRF	_HY17P52WR3_STK01,0
	MVL	0x20
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x03
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	551; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00470_DS_
;	;.line	553; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00437_DS_:
;	;.line	554; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00437_DS_
_00468_DS_:
;	;.line	560; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
	BSF	(_adS+6),3
;	;.line	561; ".\ADC_LCD.c"	adS.p_offset_value= abs(ADC) -STD_VALUE + 1; 
	DCF	_ADC,0,0
	MVL	0xff
	ADDC	(_ADC + 1),0,0
	MVL	0xff
	ADDC	(_ADC + 2),0,0
	MVL	0x7f
	ADDC	(_ADC + 3),0,0
	BTSS	_STATUS,1
	JMP	_00476_DS_
	MVF	_ADC,0,0
	MVF	r0x118D,1,0
	MVF	(_ADC + 1),0,0
	MVF	r0x118E,1,0
	JMP	_00477_DS_
_00476_DS_:
	COMF	_ADC,0,0
	MVF	r0x118D,1,0
	COMF	(_ADC + 1),0,0
	MVF	r0x118E,1,0
	COMF	(_ADC + 2),0,0
	MVF	r0x1191,1,0
	COMF	(_ADC + 3),0,0
	MVF	r0x1192,1,0
	INF	r0x118D,1,0
	MVL	0x00
	ADDC	r0x118E,1,0
	ADDC	r0x1191,1,0
	ADDC	r0x1192,1,0
_00477_DS_:
	MVL	0x85
	ADDF	r0x118D,0,0
	MVF	r0x118D,1,0
	MVL	0xe6
	ADDC	r0x118E,0,0
	MVSF	r0x118D,(_adS + 20)
	MVF	(_adS + 21),1,0
;	;.line	562; ".\ADC_LCD.c"	if(adS.p_offset_value >=0){
	BTSZ	_STATUS,2
	JMP	_00465_DS_
;	;.line	564; ".\ADC_LCD.c"	adS.p_offset_value = abs(adS.p_offset_value); //Write delta data in eeprom
	DCF	(_adS + 20),0,0
	MVL	0x7f
	ADDC	(_adS + 21),0,0
	BTSS	_STATUS,1
	JMP	_00478_DS_
	MVF	(_adS + 20),0,0
	MVF	r0x118D,1,0
	JMP	_00479_DS_
_00478_DS_:
	COMF	(_adS + 20),0,0
	MVF	r0x118D,1,0
	COMF	(_adS + 21),0,0
	INSUZ	r0x118D,1,0
	ADDL	0x01
	MVF	r0x118E,1,0
_00479_DS_:
	MVF	r0x118D,0,0
	MVF	(_adS + 20),1,0
;	;.line	565; ".\ADC_LCD.c"	HY17P52WR3(1,0x11,adS.p_offset_value);	//addr=01,BIE_DataH=0xAA,BIE_DataL=0x11
	MVSF	r0x118E,(_adS + 21)
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0x11
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x01
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	566; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00448_DS_
;	;.line	568; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00445_DS_:
;	;.line	569; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00445_DS_
_00448_DS_:
;	;.line	571; ".\ADC_LCD.c"	HY17P52WR3(2,0x10,0x0);
	CLRF	_HY17P52WR3_STK01,0
	MVL	0x10
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x02
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	572; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00470_DS_
;	;.line	574; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00450_DS_:
;	;.line	575; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00450_DS_
_00465_DS_:
;	;.line	579; ".\ADC_LCD.c"	adS.p_offset_value = abs(adS.p_offset_value); //Write delta data in eeprom
	DCF	(_adS + 20),0,0
	MVL	0x7f
	ADDC	(_adS + 21),0,0
	BTSS	_STATUS,1
	JMP	_00480_DS_
	MVF	(_adS + 20),0,0
	MVF	r0x118D,1,0
	JMP	_00481_DS_
_00480_DS_:
	COMF	(_adS + 20),0,0
	MVF	r0x118D,1,0
	COMF	(_adS + 21),0,0
	INSUZ	r0x118D,1,0
	ADDL	0x01
	MVF	r0x118E,1,0
_00481_DS_:
	MVF	r0x118D,0,0
	MVF	(_adS + 20),1,0
;	;.line	580; ".\ADC_LCD.c"	HY17P52WR3(2,0x22,adS.p_offset_value);	//addr=01,BIE_DataH=0xAA,BIE_DataL=0x11
	MVSF	r0x118E,(_adS + 21)
	MVF	_HY17P52WR3_STK01,1,0
	MVL	0x22
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x02
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	581; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00458_DS_
;	;.line	583; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00455_DS_:
;	;.line	584; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00455_DS_
_00458_DS_:
;	;.line	586; ".\ADC_LCD.c"	HY17P52WR3(1,0x11,0x0);
	CLRF	_HY17P52WR3_STK01,0
	MVL	0x11
	MVF	_HY17P52WR3_STK00,1,0
	MVL	0x01
	CALL	_HY17P52WR3
	.CHKPARA _HY17P52WR3 3
;	;.line	587; ".\ADC_LCD.c"	if(Flag== 1)
	DCSZ	_Flag,0,0
	JMP	_00470_DS_
;	;.line	589; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
	MVL	0xbf
	ANDF	_PT1,0,0
	IORL	0x40
	MVF	_PT1,1,0
_00460_DS_:
;	;.line	590; ".\ADC_LCD.c"	while(1);    //fail
	JMP	_00460_DS_
_00470_DS_:
;	;.line	596; ".\ADC_LCD.c"	}
	RET	
; exit point of _SetupZeroPoint_Mode
	.ENDFUNC	_SetupZeroPoint_Mode
;--------------------------------------------------------

.globl _LowVoltageDisplay

;--------------------------------------------------------
	.FUNC _LowVoltageDisplay:0:$C:_LowVoltageDetect_3V:$C:_DisplayBatteryCapacityFull:$C:_LowVoltageDetect_2V4:$C:_DisplayBatteryCapacityHalf\
:$C:_DispalyBatteryCapacityLow\
:$L:r0x118C
;--------------------------------------------------------
;	;.line	473; ".\ADC_LCD.c"	adS.LVD_3V_flag = LowVoltageDetect_3V();
_LowVoltageDisplay:	;Function start
	CALL	_LowVoltageDetect_3V
	MVF	r0x118C,1,0
	RRFC	r0x118C,0,0
	BTSS	_STATUS,4
	BCF	(_adS+6),2
	BTSZ	_STATUS,4
	BSF	(_adS+6),2
;	;.line	474; ".\ADC_LCD.c"	if(adS.LVD_3V_flag==0){ /* battery capacity is full*/
	BTSZ	(_adS+6),2
	JMP	_00410_DS_
;	;.line	477; ".\ADC_LCD.c"	DisplayBatteryCapacityFull(); 
	CALL	_DisplayBatteryCapacityFull
	.CHKPARA _DisplayBatteryCapacityFull 0
	JMP	_00412_DS_
_00410_DS_:
;	;.line	480; ".\ADC_LCD.c"	adS.LVD_2V4_flag = LowVoltageDetect_2V4();
	CALL	_LowVoltageDetect_2V4
	MVF	r0x118C,1,0
	RRFC	r0x118C,0,0
	BTSS	_STATUS,4
	BCF	(_adS+6),1
	BTSZ	_STATUS,4
	BSF	(_adS+6),1
;	;.line	481; ".\ADC_LCD.c"	if(adS.LVD_2V4_flag == 0){
	BTSZ	(_adS+6),1
	JMP	_00407_DS_
;	;.line	484; ".\ADC_LCD.c"	DisplayBatteryCapacityHalf();
	CALL	_DisplayBatteryCapacityHalf
	.CHKPARA _DisplayBatteryCapacityHalf 0
	JMP	_00412_DS_
_00407_DS_:
;	;.line	488; ".\ADC_LCD.c"	DispalyBatteryCapacityLow();
	CALL	_DispalyBatteryCapacityLow
	.CHKPARA _DispalyBatteryCapacityLow 0
_00412_DS_:
;	;.line	492; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDisplay
	.ENDFUNC	_LowVoltageDisplay
;--------------------------------------------------------

.globl _LowVoltageDetect_2V4

;--------------------------------------------------------
	.FUNC _LowVoltageDetect_2V4:0:$C:_Delay\
:$L:r0x118B
;--------------------------------------------------------
;	;.line	448; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_24);  
_LowVoltageDetect_2V4:	;Function start
	MVL	0xe1
	ANDF	_LVDCN,0,0
	IORL	0x0a
	MVF	_LVDCN,1,0
;	;.line	449; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
	BCF	_LVDCN,5
;	;.line	450; ".\ADC_LCD.c"	Delay(10);
	MVL	0x0a
	MVF	_Delay_STK00,1,0
	MVL	0x00
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	451; ".\ADC_LCD.c"	if(LVD_GetLVDO())
	BTSS	_LVDCN,0
	JMP	_00400_DS_
;	;.line	453; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
	CLRF	r0x118B,0
	JMP	_00401_DS_
_00400_DS_:
;	;.line	457; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
	MVL	0x01
	MVF	r0x118B,1,0
_00401_DS_:
;	;.line	459; ".\ADC_LCD.c"	return flag;
	MVF	r0x118B,0,0
;	;.line	460; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDetect_2V4
	.ENDFUNC	_LowVoltageDetect_2V4
;--------------------------------------------------------

.globl _LowVoltageDetect_3V

;--------------------------------------------------------
	.FUNC _LowVoltageDetect_3V:0:$C:_Delay\
:$L:r0x118A
;--------------------------------------------------------
;	;.line	422; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_30 );  
_LowVoltageDetect_3V:	;Function start
	MVL	0xe1
	ANDF	_LVDCN,0,0
	IORL	0x16
	MVF	_LVDCN,1,0
;	;.line	423; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
	BCF	_LVDCN,5
;	;.line	424; ".\ADC_LCD.c"	Delay(10);
	MVL	0x0a
	MVF	_Delay_STK00,1,0
	MVL	0x00
	CALL	_Delay
	.CHKPARA _Delay 2
;	;.line	425; ".\ADC_LCD.c"	if(LVD_GetLVDO())
	BTSS	_LVDCN,0
	JMP	_00393_DS_
;	;.line	427; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
	CLRF	r0x118A,0
	JMP	_00394_DS_
_00393_DS_:
;	;.line	431; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
	MVL	0x01
	MVF	r0x118A,1,0
_00394_DS_:
;	;.line	433; ".\ADC_LCD.c"	return flag;
	MVF	r0x118A,0,0
;	;.line	434; ".\ADC_LCD.c"	}
	RET	
; exit point of _LowVoltageDetect_3V
	.ENDFUNC	_LowVoltageDetect_3V
;--------------------------------------------------------

.globl _UnitConverter

;--------------------------------------------------------
	.FUNC _UnitConverter:4:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
:$L:r0x1181:$L:_UnitConverter_STK00:$L:_UnitConverter_STK01:$L:_UnitConverter_STK02:$L:r0x1182\
:$L:r0x1186:$L:r0x1185
;--------------------------------------------------------
;	;.line	379; ".\ADC_LCD.c"	long UnitConverter(long data)
_UnitConverter:	;Function start
	MVF	r0x1181,1,0
;	;.line	382; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
	CLRF	_BIEARL,0
;	;.line	383; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
	BSF	_BIECN,0
_00346_DS_:
;	;.line	384; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
	MVF	_BIECN,0,0
	ANDL	0x01
	MVF	r0x1182,1,0
	DCF	r0x1182,0,0
	BTSZ	_STATUS,0
	JMP	_00346_DS_
;	;.line	385; ".\ADC_LCD.c"	adS.eepromRead_UnitLow_bit=BIEDRL;
	MVF	_BIEDRL,0,0
	MVF	(_adS + 12),1,0
	MVF	r0x1182,1,0
;	;.line	387; ".\ADC_LCD.c"	if(adS.eepromRead_UnitLow_bit==0){ /*psi*/
	TFSZ	_WREG,0
	JMP	_00359_DS_
;	;.line	389; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_psi) ;
	MVL	0x04
	MVF	_LCD4,1,0
;	;.line	390; ".\ADC_LCD.c"	return  kgfTOpsi(data) ;
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1181,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1186,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1186,0,0
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
	MVF	r0x1186,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1186,0,0
	CALL	___fs2slong
	JMP	_00361_DS_
_00359_DS_:
;	;.line	392; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==1){ /*unit bar*/
	DCSZ	r0x1182,0,0
	JMP	_00356_DS_
;	;.line	393; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_bar) ;
	MVL	0x02
	MVF	_LCD4,1,0
;	;.line	394; ".\ADC_LCD.c"	return	kgfTObar(data);
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1181,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1186,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1186,0,0
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
	MVF	r0x1186,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1186,0,0
	CALL	___fs2slong
	JMP	_00361_DS_
_00356_DS_:
;	;.line	396; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==2){ /* unit kgf*/
	MVF	r0x1182,0,0
	XORL	0x02
	BTSS	_STATUS,0
	JMP	_00353_DS_
;	;.line	398; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	399; ".\ADC_LCD.c"	return data;
	MVF	_UnitConverter_STK02,0,0
	MVF	STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	STK00,1,0
	MVF	r0x1181,0,0
	JMP	_00361_DS_
_00353_DS_:
;	;.line	401; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==3){ /*uint mpa*/
	MVF	r0x1182,0,0
	XORL	0x03
	BTSS	_STATUS,0
	JMP	_00350_DS_
;	;.line	403; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_mpa) ;
	MVL	0x08
	MVF	_LCD4,1,0
;	;.line	404; ".\ADC_LCD.c"	return kgfTOmpa(data);
	MVF	_UnitConverter_STK02,0,0
	MVF	___slong2fs_STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	___slong2fs_STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	___slong2fs_STK00,1,0
	MVF	r0x1181,0,0
	CALL	___slong2fs
	.CHKPARA ___slong2fs 4
	MVF	r0x1185,1,0
	MVF	STK02,0,0
	MVF	___fsmul_STK06,1,0
	MVF	STK01,0,0
	MVF	___fsmul_STK05,1,0
	MVF	STK00,0,0
	MVF	___fsmul_STK04,1,0
	MVF	r0x1185,0,0
	MVF	___fsmul_STK03,1,0
	MVL	0xcd
	MVF	___fsmul_STK02,1,0
	MVL	0xcc
	MVF	___fsmul_STK01,1,0
	MVF	___fsmul_STK00,1,0
	MVL	0x3d
	CALL	___fsmul
	.CHKPARA ___fsmul 8
	MVF	r0x1185,1,0
	MVF	STK02,0,0
	MVF	___fs2slong_STK02,1,0
	MVF	STK01,0,0
	MVF	___fs2slong_STK01,1,0
	MVF	STK00,0,0
	MVF	___fs2slong_STK00,1,0
	MVF	r0x1185,0,0
	CALL	___fs2slong
	JMP	_00361_DS_
_00350_DS_:
;	;.line	407; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
	MVL	0x01
	MVF	_LCD4,1,0
;	;.line	408; ".\ADC_LCD.c"	return data;
	MVF	_UnitConverter_STK02,0,0
	MVF	STK02,1,0
	MVF	_UnitConverter_STK01,0,0
	MVF	STK01,1,0
	MVF	_UnitConverter_STK00,0,0
	MVF	STK00,1,0
	MVF	r0x1181,0,0
_00361_DS_:
;	;.line	411; ".\ADC_LCD.c"	}
	RET	
; exit point of _UnitConverter
	.ENDFUNC	_UnitConverter
;--------------------------------------------------------

	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
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
	;--cdb--S:G$ShowADC$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$GPIO_Init$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
	;--cdb--S:G$adS$0$0({22}ST_adc_works_:S),E,0,0
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
	;--cdb--S:LADC_LCD.main._main_LCDDisplay_65536_37$LCDDisplay$10000$37({4}SF:S),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
	;--cdb--S:LADC_LCD.main._main_delta_65536_37$delta$10000$37({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1146,r0x1147]
	;--cdb--S:LADC_LCD.main._main_theta_65536_37$theta$10000$37({4}SL:SL),R,0,0,[r0x1144,r0x1145,r0x1146,r0x1147]
	;--cdb--S:LADC_LCD.main._main_n_65536_37$n$10000$37({4}SL:SL),R,0,0,[]
	;--cdb--S:LADC_LCD.UnitConverter._UnitConverter_data_65536_65$data$10000$65({4}SL:SL),R,0,0,[_UnitConverter_STK02,_UnitConverter_STK01,_UnitConverter_STK00,r0x1181]
	;--cdb--S:LADC_LCD.LowVoltageDetect_3V._LowVoltageDetect_3V_flag_65536_73$flag$10000$73({1}SC:U),R,0,0,[r0x118A]
	;--cdb--S:LADC_LCD.LowVoltageDetect_2V4._LowVoltageDetect_2V4_flag_65536_77$flag$10000$77({1}SC:U),R,0,0,[r0x118B]
	;--cdb--S:LADC_LCD.PositivePressureWorks_Mode._PositivePressureWorks_Mode_delta_65536_108$delta$10000$108({4}SL:SL),R,0,0,[r0x1197,r0x1198,r0x1199,r0x119A]
	;--cdb--S:LADC_LCD.PositivePressureWorks_Mode._PositivePressureWorks_Mode_LCDDisplay_65536_108$LCDDisplay$10000$108({4}SL:SL),R,0,0,[r0x1197,r0x1198,r0x1199,r0x119A]
	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_theta_65536_116$theta$10000$116({4}SL:SL),R,0,0,[r0x11B3,r0x11B4,r0x11B5,r0x11B6]
	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_omega_65536_116$omega$10000$116({4}SL:SL),R,0,0,[r0x11AF,r0x11B0,r0x11B1,r0x11B2]
	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_LCDDisplay_65536_116$LCDDisplay$10000$116({4}SL:SL),R,0,0,[r0x11AF,r0x11B0,r0x11B1,r0x11B2]
	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
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
	.globl	_DisplayNum
	.globl	___slong2fs
	.globl	___fsmul
	.globl	___fs2slong
	.globl	___fssub
	.globl	___fsadd
	.globl	__mullong
	.globl	_FSR0
	.globl	_FSR1
	.globl	_FSR2
	.globl	_ADCR
	.globl	_adS
	.globl	__sdcc_gsinit_startup256fsr2
;--------------------------------------------------------
; global -1 declarations
;--------------------------------------------------------
	.globl	_LowVoltageDisplay
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
r0x114C:	.ds	1
r0x114D:	.ds	1
r0x1181:	.ds	1
r0x1182:	.ds	1
r0x1185:	.ds	1
r0x1186:	.ds	1
r0x118A:	.ds	1
r0x118B:	.ds	1
r0x118C:	.ds	1
r0x118D:	.ds	1
r0x118E:	.ds	1
r0x118F:	.ds	1
r0x1190:	.ds	1
r0x1191:	.ds	1
r0x1192:	.ds	1
r0x1195:	.ds	1
r0x1197:	.ds	1
r0x1198:	.ds	1
r0x1199:	.ds	1
r0x119A:	.ds	1
r0x119B:	.ds	1
r0x119C:	.ds	1
r0x119D:	.ds	1
r0x119E:	.ds	1
r0x119F:	.ds	1
r0x11A0:	.ds	1
r0x11A2:	.ds	1
r0x11A3:	.ds	1
r0x11A4:	.ds	1
r0x11AF:	.ds	1
r0x11B0:	.ds	1
r0x11B1:	.ds	1
r0x11B2:	.ds	1
r0x11B3:	.ds	1
r0x11B4:	.ds	1
r0x11B5:	.ds	1
r0x11B6:	.ds	1
r0x11B7:	.ds	1
r0x11B8:	.ds	1
r0x11B9:	.ds	1
r0x11BA:	.ds	1
r0x11BB:	.ds	1
r0x11BC:	.ds	1
r0x11BE:	.ds	1
r0x11BF:	.ds	1
r0x11C0:	.ds	1
r0x11C1:	.ds	1
r0x11C3:	.ds	1
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
	.globl _Delay_STK00
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
	.globl ___fsadd_STK06
	.globl ___fsadd_STK05
	.globl ___fsadd_STK04
	.globl ___fsadd_STK03
	.globl ___fsadd_STK02
	.globl ___fsadd_STK01
	.globl ___fsadd_STK00
	.globl _HY17P52WR3_STK01
	.globl _HY17P52WR3_STK00
_UnitConverter_STK00:	.ds	1
	.globl _UnitConverter_STK00
_UnitConverter_STK01:	.ds	1
	.globl _UnitConverter_STK01
_UnitConverter_STK02:	.ds	1
	.globl _UnitConverter_STK02
	.globl __mullong_STK06
	.globl __mullong_STK05
	.globl __mullong_STK04
	.globl __mullong_STK03
	.globl __mullong_STK02
	.globl __mullong_STK01
	.globl __mullong_STK00
	.globl _Reverse_Data_STK02
	.globl _Reverse_Data_STK01
	.globl _Reverse_Data_STK00
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized data - mirror
;--------------------------------------------------------
	;Following is optimization info, 
	;xxcdbxxW:dst:src+offset:srclit:just-remove
	;--cdb--W:r0x11C2:NULL+0:-1:1
	;--cdb--W:r0x11C1:NULL+0:-1:1
	;--cdb--W:r0x11AF:NULL+0:-1:1
	;--cdb--W:r0x11B0:NULL+0:-1:1
	;--cdb--W:r0x11B1:NULL+0:-1:1
	;--cdb--W:r0x11B4:NULL+0:-1:1
	;--cdb--W:r0x11B3:NULL+0:-1:1
	;--cdb--W:r0x11B7:NULL+0:-1:1
	;--cdb--W:r0x11BB:NULL+0:-1:1
	;--cdb--W:r0x11AF:STK02+0:-1:0
	;--cdb--W:r0x11B0:STK01+0:-1:0
	;--cdb--W:r0x11B1:STK00+0:-1:0
	;--cdb--W:r0x11B4:NULL+0:0:0
	;--cdb--W:r0x11B7:r0x11B8+0:-1:0
	;--cdb--W:r0x11B9:NULL+0:0:0
	;--cdb--W:r0x11BD:NULL+0:0:0
	;--cdb--W:r0x11B9:NULL+0:-1:1
	;--cdb--W:r0x11BD:NULL+0:-1:1
	;--cdb--W:r0x1198:NULL+0:-1:1
	;--cdb--W:r0x1197:NULL+0:-1:1
	;--cdb--W:r0x119B:NULL+0:-1:1
	;--cdb--W:r0x119F:NULL+0:-1:1
	;--cdb--W:r0x1197:STK02+0:-1:0
	;--cdb--W:r0x1198:NULL+0:0:0
	;--cdb--W:r0x1198:STK01+0:-1:0
	;--cdb--W:r0x1199:STK00+0:-1:0
	;--cdb--W:r0x119B:r0x119C+0:-1:0
	;--cdb--W:r0x119D:NULL+0:0:0
	;--cdb--W:r0x11A0:STK01+0:-1:0
	;--cdb--W:r0x119F:STK02+0:-1:0
	;--cdb--W:r0x11A1:NULL+0:0:0
	;--cdb--W:r0x11A1:STK00+0:-1:0
	;--cdb--W:r0x119D:NULL+0:-1:1
	;--cdb--W:r0x11A1:NULL+0:-1:1
	;--cdb--W:r0x1195:NULL+0:-1:1
	;--cdb--W:r0x1196:NULL+0:-1:1
	;--cdb--W:r0x1196:NULL+0:0:0
	;--cdb--W:r0x118D:NULL+0:-1:1
	;--cdb--W:r0x118F:NULL+0:-1:1
	;--cdb--W:r0x1190:NULL+0:-1:1
	;--cdb--W:r0x1191:NULL+0:-1:1
	;--cdb--W:r0x1192:NULL+0:-1:1
	;--cdb--W:r0x118F:STK00+0:-1:0
	;--cdb--W:r0x118E:STK01+0:-1:0
	;--cdb--W:r0x1191:r0x118D+0:-1:0
	;--cdb--W:r0x1192:r0x118E+1:-1:0
	;--cdb--W:r0x1193:r0x118D+0:-1:0
	;--cdb--W:r0x1194:r0x118E+1:-1:0
	;--cdb--W:r0x118E:NULL+0:-1:1
	;--cdb--W:r0x118B:NULL+0:-1:1
	;--cdb--W:r0x118A:NULL+0:-1:1
	;--cdb--W:r0x1183:NULL+0:-1:1
	;--cdb--W:r0x1182:NULL+0:-1:1
	;--cdb--W:r0x1183:NULL+0:0:0
	;--cdb--W:r0x1183:STK01+0:-1:0
	;--cdb--W:r0x1185:STK00+0:-1:0
	;--cdb--W:r0x1184:STK01+0:-1:0
	;--cdb--W:r0x1184:STK00+0:-1:0
	;--cdb--W:r0x1186:NULL+0:-1:1
	;--cdb--W:r0x1185:NULL+0:-1:1
	;--cdb--W:r0x1140:NULL+0:-1:1
	;--cdb--W:r0x1141:NULL+0:-1:1
	;--cdb--W:r0x1142:NULL+0:-1:1
	;--cdb--W:r0x1143:NULL+0:-1:1
	;--cdb--W:r0x1144:NULL+0:-1:1
	;--cdb--W:r0x1145:NULL+0:-1:1
	;--cdb--W:r0x1140:STK02+0:-1:0
	;--cdb--W:r0x1141:STK01+0:-1:0
	;--cdb--W:r0x1141:NULL+0:0:0
	;--cdb--W:r0x1142:STK00+0:-1:0
	;--cdb--W:r0x1144:r0x1140+0:-1:0
	;--cdb--W:r0x1145:r0x1141+1:-1:0
	;--cdb--W:r0x1146:r0x1140+0:-1:0
	;--cdb--W:r0x1146:NULL+0:0:0
	;--cdb--W:r0x1147:r0x1141+1:-1:0
	;--cdb--W:r0x1147:NULL+0:0:0
	;--cdb--W:r0x1146:NULL+0:-1:1
	;--cdb--W:r0x1147:NULL+0:-1:1
	;--cdb--W:r0x11C3:NULL+0:-1:1
	;--cdb--W:r0x11C4:NULL+0:-1:1
	end
