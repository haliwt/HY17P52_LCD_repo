;--------------------------------------------------------
; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
; Version 3.9.3 #4ad52972e (MSVC)
;--------------------------------------------------------
; Port for HYCON CPU
;--------------------------------------------------------
;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
;;	.file	"E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"
	.module ADC_52
	;.list	p=HY17P52
	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
	;--cdb--F:ADC_52:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0,0,0,0
	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_52:G$ADC_Open$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_52:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0,0,0,0
	;--cdb--S:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--F:ADC_52:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0,0,0,0
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;	udata_ovr
.area CCODE (code,REL,CON) ; ADC_52-code 
.globl _ENSDRVDisable

;--------------------------------------------------------
	.FUNC _ENSDRVDisable:0
;--------------------------------------------------------
;	;.line	120; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONEnable();
_ENSDRVDisable:	;Function start
	BSF	_PWRCN,0
;	;.line	121; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CSFCN1 &= 0x7F;
	BCF	_CSFCN1,7
;	;.line	122; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONDisable();
	BCF	_PWRCN,0
;	;.line	123; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
	RET	
; exit point of _ENSDRVDisable
	.ENDFUNC	_ENSDRVDisable
;--------------------------------------------------------

.globl _ENSDRVEnable

;--------------------------------------------------------
	.FUNC _ENSDRVEnable:0
;--------------------------------------------------------
;	;.line	114; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONEnable();
_ENSDRVEnable:	;Function start
	BSF	_PWRCN,0
;	;.line	115; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CSFCN1 |= 0x80;
	BSF	_CSFCN1,7
;	;.line	116; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONDisable();
	BCF	_PWRCN,0
;	;.line	117; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
	RET	
; exit point of _ENSDRVEnable
	.ENDFUNC	_ENSDRVEnable
;--------------------------------------------------------

.globl _ADC_GetData

;--------------------------------------------------------
	.FUNC _ADC_GetData:0:$L:_ADC_GetData_ADCData_65536_8
;--------------------------------------------------------
;	;.line	98; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[0] = AD1L; /* ADC low byte register*/
_ADC_GetData:	;Function start
	MVF	_AD1L,0,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 0),1,0
;	;.line	99; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[1] = AD1M; /* ADC middle byte*/
	MVF	_AD1M,0,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 1),1,0
;	;.line	100; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[2] = AD1H; /* ADC high byte register */
	MVF	_AD1H,0,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 2),1,0
;	;.line	102; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	if (ADCData&0x800000L)  //2^(24-1) -1 = 8388607  
	BTSS	(_ADC_GetData_ADCData_65536_8 + 2),7
	JMP	_00110_DS_
;	;.line	103; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[3] = 0xFF;
	SETF	(_ADC_GetData_ADCData_65536_8 + 3),0
	JMP	_00111_DS_
_00110_DS_:
;	;.line	105; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[3] = 0x00;
	CLRF	(_ADC_GetData_ADCData_65536_8 + 3),0
_00111_DS_:
;	;.line	106; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	return ADCData;
	MVF	_ADC_GetData_ADCData_65536_8,0,0
	MVF	STK02,1,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 1),0,0
	MVF	STK01,1,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 2),0,0
	MVF	STK00,1,0
	MVF	(_ADC_GetData_ADCData_65536_8 + 3),0,0
;	;.line	107; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
	RET	
; exit point of _ADC_GetData
	.ENDFUNC	_ADC_GetData
;--------------------------------------------------------

.globl _ADC_Open

;--------------------------------------------------------
	.FUNC _ADC_Open:12:$L:r0x113F:$L:_ADC_Open_STK00:$L:_ADC_Open_STK01:$L:_ADC_Open_STK02:$L:_ADC_Open_STK03\
:$L:_ADC_Open_STK04:$L:_ADC_Open_STK05:$L:_ADC_Open_STK06:$L:_ADC_Open_STK07:$L:_ADC_Open_STK08\
:$L:_ADC_Open_STK09:$L:_ADC_Open_STK10
;--------------------------------------------------------
;	;.line	52; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	void ADC_Open(unsigned char ck,    //Selector of SD18 peripheral operating clock source
_ADC_Open:	;Function start
	MVF	r0x113F,1,0
;	;.line	67; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_CLK_DivSelect(ck);
	MVL	0xcf
	ANDF	_OSCCN1,0,0
	IORF	r0x113F,0,0
	MVF	_OSCCN1,1,0
;	;.line	68; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CLK_DHSCKSelect(cks);
	MVL	0xcf
	ANDF	_OSCCN0,0,0
	IORF	_ADC_Open_STK00,0,0
	MVF	_OSCCN0,1,0
;	;.line	71; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VINSelect(inh,inl);             // Config ADC Input Channel
	MVF	_ADC_Open_STK02,0,0
	IORF	_ADC_Open_STK01,0,0
	MVF	_AD1CN3,1,0
;	;.line	72; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VRINSelect(vrh,vrl);            // Config ADC Ref. Voltage Input Channel
	MVL	0x0f
	ANDF	_AD1CN4,0,0
	MVF	r0x113F,1,0
	MVF	_ADC_Open_STK04,0,0
	IORF	_ADC_Open_STK03,1,0
	MVF	_ADC_Open_STK03,0,0
	IORF	r0x113F,0,0
	MVF	_AD1CN4,1,0
;	;.line	73; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_GainSelect(adgn,pgagn);         // Config PGA Gain and AD Gain
	MVL	0xe0
	ANDF	_AD1CN1,0,0
	MVF	r0x113F,1,0
	MVF	_ADC_Open_STK06,0,0
	IORF	_ADC_Open_STK05,1,0
	MVF	_ADC_Open_STK05,0,0
	IORF	r0x113F,0,0
	MVF	_AD1CN1,1,0
;	;.line	74; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VRXSelect(vrgn);             // Config Ref. Gain and DC offset
	MVL	0xdf
	ANDF	_AD1CN1,0,0
	IORF	_ADC_Open_STK07,0,0
	MVF	_AD1CN1,1,0
;	;.line	75; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_DCSETSelect(dcset);             // Config Ref. Gain and DC offset
	MVL	0xf0
	ANDF	_AD1CN2,0,0
	IORF	_ADC_Open_STK08,0,0
	MVF	_AD1CN2,1,0
;	;.line	76; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_OSRSelect(osr);                 // Config Over sampling ratio
	MVL	0xe1
	ANDF	_AD1CN0,0,0
	IORF	_ADC_Open_STK09,0,0
	MVF	_AD1CN0,1,0
;	;.line	77; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VCMSSelect(vcms); 
	MVL	0xdf
	ANDF	_AD1CN5,0,0
	IORF	_ADC_Open_STK10,0,0
	MVF	_AD1CN5,1,0
;	;.line	79; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_ENACMEnable();
	BSF	_AD1CN5,7
;	;.line	80; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_Enable();
	BSF	_AD1CN0,7
;	;.line	81; "E:\HY17P52_TestSoft\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
	RET	
; exit point of _ADC_Open
	.ENDFUNC	_ADC_Open
;--------------------------------------------------------

	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
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
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vcms_65536_5$vcms$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK10]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_osr_65536_5$osr$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK09]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_dcset_65536_5$dcset$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK08]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrgn_65536_5$vrgn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK07]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_pgagn_65536_5$pgagn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK06]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_adgn_65536_5$adgn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK05]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrl_65536_5$vrl$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK04]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrh_65536_5$vrh$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK03]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_inl_65536_5$inl$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK02]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_inh_65536_5$inh$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK01]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_cks_65536_5$cks$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK00]
	;--cdb--S:LADC_52.ADC_Open._ADC_Open_ck_65536_5$ck$10000$5({1}SC:U),R,0,0,[r0x113F]
	;--cdb--S:LADC_52.ADC_GetData._ADC_GetData_ADCData_65536_8$ADCData$10000$8({4}SL:SL),E,0,0
	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
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
	.globl	_ADC_Open

	.globl	_memcpy
;--------------------------------------------------------
; global -2 definitions
;--------------------------------------------------------
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
	.area UDATA (DATA,REL,CON) ;UDL_ADC_52_0	udata
r0x113F:	.ds	1
	.area LOCALSTK (STK); local stack var
_ADC_Open_STK00:	.ds	1
	.globl _ADC_Open_STK00
_ADC_Open_STK01:	.ds	1
	.globl _ADC_Open_STK01
_ADC_Open_STK02:	.ds	1
	.globl _ADC_Open_STK02
_ADC_Open_STK03:	.ds	1
	.globl _ADC_Open_STK03
_ADC_Open_STK04:	.ds	1
	.globl _ADC_Open_STK04
_ADC_Open_STK05:	.ds	1
	.globl _ADC_Open_STK05
_ADC_Open_STK06:	.ds	1
	.globl _ADC_Open_STK06
_ADC_Open_STK07:	.ds	1
	.globl _ADC_Open_STK07
_ADC_Open_STK08:	.ds	1
	.globl _ADC_Open_STK08
_ADC_Open_STK09:	.ds	1
	.globl _ADC_Open_STK09
_ADC_Open_STK10:	.ds	1
	.globl _ADC_Open_STK10
_ADC_GetData_ADCData_65536_8:	.ds	4
;--------------------------------------------------------
; initialized data
;--------------------------------------------------------
;--------------------------------------------------------
; initialized data - mirror
;--------------------------------------------------------
	;Following is optimization info, 
	;xxcdbxxW:dst:src+offset:srclit:just-remove
	;--cdb--W:r0x114B:NULL+0:-1:1
	;--cdb--W:r0x113F:NULL+0:-1:1
	end
