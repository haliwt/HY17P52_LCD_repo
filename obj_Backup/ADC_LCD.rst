001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft"
008                     ;;	.file	".\ADC_LCD.c"
009                     	.module ADC_LCD
010                     	;.list	p=HY17P52
011                     	;--cdb--T:FADC_LCD$_MCUSTATUS[({0}S:S$_byte$0$0({1}SC:U),Z,0,0)({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
012                     	;--cdb--T:FADC_LCD$__00000000[({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
013                     	;--cdb--T:FADC_LCD$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_PositiveDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_PositiveDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({9}S:S$eepromRead_NegativeDeltaLow_bit1$0$0({1}SC:U),Z,0,0)({10}S:S$eepromRead_NegativeDeltaLow_bit2$0$0({1}SC:U),Z,0,0)({11}S:S$eepromRead_UnithHigh_bit$0$0({1}SC:U),Z,0,0)({12}S:S$eepromRead_UnitLow_bit$0$0({1}SC:U),Z,0,0)({13}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({14}S:S$delayTimes_5$0$0({2}SI:U),Z,0,0)({16}S:S$delayTimes_3$0$0({2}SI:U),Z,0,0)({18}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({20}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
014                     	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
015                     	;--cdb--F:ADC_LCD:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
016                     	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
017                     	;--cdb--F:ADC_LCD:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
018                     	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
019                     	;--cdb--F:ADC_LCD:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
020                     	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
021                     	;--cdb--F:ADC_LCD:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
022                     	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
023                     	;--cdb--F:ADC_LCD:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0,0,0,0
024                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
025                     	;--cdb--F:ADC_LCD:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0,0,0,0
026                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
027                     	;--cdb--F:ADC_LCD:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0,0,0,0
028                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
029                     	;--cdb--F:ADC_LCD:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0,0,0,0
030                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
031                     	;--cdb--F:ADC_LCD:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0,0,0,0
032                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
033                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
034                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
035                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
036                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
037                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
038                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
039                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
040                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
041                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
042                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
043                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
044                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
045                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
046                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
047                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
048                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
049                     	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
050                     	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
051                     	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
052                     	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
053                     	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
054                     	;--cdb--S:G$ShowADC$0$0({2}DF,SV:S),C,0,0
055                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
056                     	;--cdb--S:G$GPIO_Init$0$0({2}DF,SV:S),C,0,0
057                     	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
058                     	;--cdb--F:ADC_LCD:G$main$0$0({2}DF,SV:S),C,0,0,0,0,0
059                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
060                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
061                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
062                     	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
063                     	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
064                     	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
065                     	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
066                     	;--cdb--F:ADC_LCD:G$ISR$0$0({2}DF,SV:S),C,0,0,1,256,0
067                     ;--------------------------------------------------------
068                     ; overlayable items in internal ram 
069                     ;--------------------------------------------------------
070                     ;	udata_ovr
071                     	.globl _main
072                     ;--------------------------------------------------------
073                     ; reset vector 
074                     ;--------------------------------------------------------
075                     	.area STARTUP	(code,REL,CON) 
076 0000 0000           	nop
077 0001 C200 FC42      	jmp	__sdcc_gsinit_startup256fsr2
078 0003 0000           	nop
079                     ;--------------------------------------------------------
080                     ; interrupt and initialization code
081                     ;--------------------------------------------------------
082                     	.area c_interrupt	(code,REL,CON)
083                     __sdcc_interrupt:
084                     .globl _ISR
085                     
086                     ;--------------------------------------------------------
087                     	.FUNC _ISR:0:$C:_ADC_GetData\
088                     :$L:r0x11C3
089                     ;--------------------------------------------------------
090                     ;	;.line	871; ".\ADC_LCD.c"	if(ADIF_IsFlag())
091 0004 [00] C481 D020 
091 0006 F163 D01F F162 
091 0009 D01E F161      _ISR:	;Function start
092 000B [01] BA26      	BTSS	_INTF0,5
093 000C [01] 780B      	JMP	_00720_DS_
094                     ;	;.line	873; ".\ADC_LCD.c"	ADIF_ClearFlag();
095 000D [01] 8A26      	BCF	_INTF0,5
096                     ;	;.line	874; ".\ADC_LCD.c"	ADC=ADC_GetData();
097 000E [01] C871 0011 	CALL	_ADC_GetData
098                     	.CHKPARA _ADC_GetData 0
099 0010 [01] 6768      	MVF	(_ADC + 3),1,0
100 0011 [01] D020      	MVF	STK00,0,0
101 0012 [01] F167      	MVF	(_ADC + 2),1,0
102 0013 [01] D01F      	MVF	STK01,0,0
103 0014 [01] F166      	MVF	(_ADC + 1),1,0
104 0015 [01] 641E      	MVF	STK02,0,0
105 0016 [01] 6765      	MVF	_ADC,1,0
106                     ;	;.line	875; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=1;
107 0017 [01] 9169      	BSF	_MCUSTATUSbits,0
108                     _00720_DS_:
109                     ;	;.line	878; ".\ADC_LCD.c"	if(TA1IF_IsFlag())  //PT1.0  Timer A1 interrupt flag 
110 0018 [01] BE27      	BTSS	_INTF1,7
111 0019 [01] 7820      	JMP	_00726_DS_
112                     ;	;.line	880; ".\ADC_LCD.c"	TA1IF_ClearFlag();
113 001A [01] 8E27 0011 	BCF	_INTF1,7
114                     ;	;.line	881; ".\ADC_LCD.c"	adS.delayTimes_3 ++;
115 001C [01] 657A      	MVF	(_adS + 16),0,0
116 001D [01] 6680      	MVF	r0x11C3,1,0
117 001E [01] 657B      	MVF	(_adS + 17),0,0
118 001F [01] 4280      	INSUZ	r0x11C3,1,0
119 0020 [01] 0401      	ADDL	0x01
120 0021 [01] C600 F17A 	MVSF	r0x11C3,(_adS + 16)
121 0023 [01] 677B      	MVF	(_adS + 17),1,0
122                     ;	;.line	882; ".\ADC_LCD.c"	adS.delayTimes_5++;
123 0024 [01] 6578      	MVF	(_adS + 14),0,0
124 0025 [01] 6680      	MVF	r0x11C3,1,0
125 0026 [01] 6579      	MVF	(_adS + 15),0,0
126 0027 [01] 4280      	INSUZ	r0x11C3,1,0
127 0028 [01] 0401      	ADDL	0x01
128 0029 [01] C600 F178 	MVSF	r0x11C3,(_adS + 14)
129 002B [01] 6779      	MVF	(_adS + 15),1,0
130                     ;	;.line	884; ".\ADC_LCD.c"	if(adS.key_flag ==1||adS.key_flag==0) {
131 002C [01] 456E      	DCSUZ	(_adS + 4),0,0
132 002D [01] 7802      	JMP	_00721_DS_
133 002E [01] 6F6E      	TFSZ	(_adS + 4),0
134 002F [01] 780A      	JMP	_00726_DS_
135                     _00721_DS_:
136                     ;	;.line	885; ".\ADC_LCD.c"	adS.delayTimes_5 = 0;
137 0030 [01] 0D78      	CLRF	(_adS + 14),0
138 0031 [01] 0D79      	CLRF	(_adS + 15),0
139                     ;	;.line	887; ".\ADC_LCD.c"	adS.delayTimes_3 =0;
140 0032 [01] 0D7A      	CLRF	(_adS + 16),0
141 0033 [01] 0D7B      	CLRF	(_adS + 17),0
142                     ;	;.line	889; ".\ADC_LCD.c"	adS.key_flag =2;
143 0034 [01] 0602      	MVL	0x02
144 0035 [01] 676E      	MVF	(_adS + 4),1,0
145                     ;	;.line	890; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
146 0036 [01] 06DF      	MVL	0xdf
147 0037 [01] 2847      	ANDF	_PT1,0,0
148 0038 [01] 0220      	IORL	0x20
149 0039 [01] 6647      	MVF	_PT1,1,0
150 003A [01] D163 F020 
150 003C D162 F01F D161 
150 003F F01E           _00726_DS_:
151                     ;	;.line	900; ".\ADC_LCD.c"	}
152 0040 [01] C4BF 0009 	RETI	 1
153                     ; exit point of _ISR
154                     	.ENDFUNC	_ISR
155                     ;--------------------------------------------------------
156                     
157                     .area CCODE (code,REL,CON) ; ADC_LCD-code 
158                     .globl _main
159                     
160                     ;--------------------------------------------------------
161                     	.FUNC _main:0:$C:_GPIO_Iint:$C:_ADC_Open:$C:_PGAandADCAccuracyMode:$C:_DisplayUnit\
162                     :$C:_Display2Er:$C:___slong2fs:$C:___fsmul:$C:___fs2slong:$C:_Delay\
163                     :$C:_PositivePressureWorks_Mode:$C:___fssub:$C:_DisplayNum:$C:___fsadd:$C:_HY17P52WR3\
164                     :$L:r0x1140:$L:r0x1141:$L:r0x1143:$L:r0x1142:$L:r0x1144\
165                     :$L:r0x1145:$L:r0x1146:$L:r0x1147:$L:r0x1148:$L:r0x1149\
166                     :$L:r0x114D:$L:r0x114C
167                     ;--------------------------------------------------------
168                     ;	;.line	100; ".\ADC_LCD.c"	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
169 017E [00] C48C      _main:	;Function start
170 017F [12] 9E35      	BSF	0x35,7
171 0180 [12] 063F      	MVL	0x3f
172 0181 [12] 2A34      	ANDF	_OSCCN0,1,0
173                     ;	;.line	101; ".\ADC_LCD.c"	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
174 0182 [12] 06CE      	MVL	0xce
175 0183 [12] 2A34      	ANDF	_OSCCN0,1,0
176                     ;	;.line	102; ".\ADC_LCD.c"	GPIO_Iint() ;
177 0184 [12] CF74      	CALL	_GPIO_Iint
178                     	.CHKPARA _GPIO_Iint 0
179                     ;	;.line	105; ".\ADC_LCD.c"	PWR_BGREnable();
180 0185 [12] 9E33      	BSF	_PWRCN,7
181                     ;	;.line	106; ".\ADC_LCD.c"	PWR_LDOPLEnable();
182 0186 [12] 9842      	BSF	_AD1CN5,4
183                     ;	;.line	107; ".\ADC_LCD.c"	PWR_LDOEnable();
184 0187 [12] 9233      	BSF	_PWRCN,1
185                     ;	;.line	108; ".\ADC_LCD.c"	PWR_LDOSel(LDOC_2V4);
186 0188 [12] 068F      	MVL	0x8f
187 0189 [12] 2A33      	ANDF	_PWRCN,1,0
188                     ;	;.line	110; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
189 018A [12] C520      	MVL	0x20
190                     	MVF	_ADC_Open_STK10,1,0
191 018B [13] 0C0D      	CLRF	_ADC_Open_STK09,0
192 018C [14] C508      	MVL	0x08
193                     	MVF	_ADC_Open_STK08,1,0
194 018D [15] C520      	MVL	0x20
195                     	MVF	_ADC_Open_STK07,1,0
196 018E [16] C518      	MVL	0x18
197                     	MVF	_ADC_Open_STK06,1,0
198 018F [17] C506      	MVL	0x06
199                     	MVF	_ADC_Open_STK05,1,0
200 0190 [18] C510      	MVL	0x10
201                     	MVF	_ADC_Open_STK04,1,0
202 0191 [19] 0C0D      	CLRF	_ADC_Open_STK03,0
203 0192 [20] C501      	MVL	0x01
204                     	MVF	_ADC_Open_STK02,1,0
205 0193 [21] C590      	MVL	0x90
206                     	MVF	_ADC_Open_STK01,1,0
207 0194 [22] C501      	MVL	0x01
208                     	MVF	_ADC_Open_STK00,1,0
209 0195 [23] 0610      	MVL	0x10
210 0196 [23] CEFD      	CALL	_ADC_Open
211                     	.CHKPARA _ADC_Open 12
212                     ;	;.line	113; ".\ADC_LCD.c"	PGAandADCAccuracyMode();
213 0197 [12] CEAA      	CALL	_PGAandADCAccuracyMode
214                     	.CHKPARA _PGAandADCAccuracyMode 0
215                     ;	;.line	120; ".\ADC_LCD.c"	LCD_Enable();
216 0198 [12] 9E5B      	BSF	_LCDCN1,7
217                     ;	;.line	121; ".\ADC_LCD.c"	LCD_ChargePumpSelect(LCDV_3V0);
218 0199 [12] 068F      	MVL	0x8f
219 019A [12] 285B      	ANDF	_LCDCN1,0,0
220 019B [12] 0240      	IORL	0x40
221 019C [12] 665B      	MVF	_LCDCN1,1,0
222                     ;	;.line	122; ".\ADC_LCD.c"	LCD_OutBufferEnable();
223 019D [12] 965B      	BSF	_LCDCN1,3
224                     ;	;.line	123; ".\ADC_LCD.c"	LCD_ChargePumpClk(SELPCLK_14KHZ);
225 019E [12] 845B      	BCF	_LCDCN1,2
226                     ;	;.line	125; ".\ADC_LCD.c"	LCD_DisplayOn();
227 019F [12] 825C      	BCF	_LCDCN2,1
228                     ;	;.line	128; ".\ADC_LCD.c"	LCD_PT60Mode(LCD);   //COM0
229 01A0 [12] 645D      	MVF	_LCDCN3,0,0
230 01A1 [12] 01FC      	ANDL	0xfc
231 01A2 [12] 0203      	IORL	0x03
232 01A3 [12] 665D      	MVF	_LCDCN3,1,0
233 01A4 [12] 01F3      	ANDL	0xf3
234                     ;	;.line	129; ".\ADC_LCD.c"	LCD_PT61Mode(LCD);	 //COM1
235 01A5 [12] 020C      	IORL	0x0c
236 01A6 [12] 665D      	MVF	_LCDCN3,1,0
237 01A7 [12] 01CF      	ANDL	0xcf
238                     ;	;.line	130; ".\ADC_LCD.c"	LCD_PT62Mode(LCD);   //COM2
239 01A8 [12] 0230      	IORL	0x30
240 01A9 [12] 665D      	MVF	_LCDCN3,1,0
241 01AA [12] 013F      	ANDL	0x3f
242                     ;	;.line	131; ".\ADC_LCD.c"	LCD_PT63Mode(LCD);   //COM3
243 01AB [12] 02C0      	IORL	0xc0
244 01AC [12] 665D      	MVF	_LCDCN3,1,0
245                     ;	;.line	133; ".\ADC_LCD.c"	TMA1_CLKSelect(TMAS1_DMSCK); //freq = DMS_CK = 3.686Mhz/256 = 0.014398MHz      0.014398Mhz / 2= 7.2KHz
246 01AD [12] 8A44      	BCF	_TMA1CN,5
247                     ;	;.line	134; ".\ADC_LCD.c"	TMA1_CLKDiv(DTMA1_TMA1CKDIV2); // fdiv = 7.2KHz ,T = 0.138ms
248 01AE [12] 06E3      	MVL	0xe3
249 01AF [12] 2A44      	ANDF	_TMA1CN,1,0
250                     ;	;.line	135; ".\ADC_LCD.c"	TMA1_CompSet(255);    //TMA1C cycle=10*TMA1R cycle 8bit = 255
251 01B0 [12] 0A46      	SETF	_TMA1C,0
252                     ;	;.line	136; ".\ADC_LCD.c"	TA1IE_Enable();
253 01B1 [12] 9E24      	BSF	_INTE1,7
254                     ;	;.line	138; ".\ADC_LCD.c"	TA1IF_ClearFlag();
255 01B2 [12] 8E27      	BCF	_INTF1,7
256                     ;	;.line	140; ".\ADC_LCD.c"	TMA1_ClearTMA1();    //Clear TMA count
257 01B3 [12] 0C45      	CLRF	_TMA1R,0
258                     ;	;.line	141; ".\ADC_LCD.c"	TMA1Enable();
259 01B4 [12] 9E44      	BSF	_TMA1CN,7
260                     ;	;.line	143; ".\ADC_LCD.c"	ADIF_ClearFlag();
261 01B5 [12] 8A26      	BCF	_INTF0,5
262                     ;	;.line	144; ".\ADC_LCD.c"	ADIE_Enable();
263 01B6 [12] 9A23      	BSF	_INTE0,5
264                     ;	;.line	145; ".\ADC_LCD.c"	GIE_Enable();
265 01B7 [12] 9E23      	BSF	_INTE0,7
266                     _00173_DS_:
267                     ;	;.line	151; ".\ADC_LCD.c"	if(GPIO_READ_PT10())
268 01B8 [12] 6447      	MVF	_PT1,0,0
269 01B9 [12] 0101      	ANDL	0x01
270 01BA [12] A02B      	BTSZ	_STATUS,0
271 01BB [12] 7864      	JMP	_00170_DS_
272                     ;	;.line	157; ".\ADC_LCD.c"	if(adS.delayTimes_5 >= 10000){ /*unit set mode*/
273 01BC [12] 06F0 0011 	MVL	0xf0
274 01BE [12] 1178      	ADDF	(_adS + 14),0,0
275 01BF [12] 06D8      	MVL	0xd8
276 01C0 [12] 1579      	ADDC	(_adS + 15),0,0
277 01C1 [12] B82B      	BTSS	_STATUS,4
278 01C2 [12] 784D      	JMP	_00113_DS_
279                     ;	;.line	159; ".\ADC_LCD.c"	if(GPIO_READ_PT10()){
280 01C3 [12] 6447      	MVF	_PT1,0,0
281 01C4 [12] 0101      	ANDL	0x01
282 01C5 [12] A02B      	BTSZ	_STATUS,0
283 01C6 [12] 7849      	JMP	_00113_DS_
284                     ;	;.line	161; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
285 01C7 [12] 0640      	MVL	0x40
286 01C8 [12] 6778      	MVF	(_adS + 14),1,0
287 01C9 [12] 061F      	MVL	0x1f
288 01CA [12] 6779      	MVF	(_adS + 15),1,0
289                     ;	;.line	162; ".\ADC_LCD.c"	adS.delayTimes_5 =0;
290 01CB [12] 0D78      	CLRF	(_adS + 14),0
291 01CC [12] 0D79      	CLRF	(_adS + 15),0
292                     ;	;.line	163; ".\ADC_LCD.c"	adS.unit_setMode =1;
293 01CD [12] 936A      	BSF	_adS,1
294                     ;	;.line	165; ".\ADC_LCD.c"	adS.testMode =1;
295 01CE [12] 916D      	BSF	(_adS+3),0
296                     ;	;.line	166; ".\ADC_LCD.c"	DisplayUnit();
297 01CF [12] CEFC 0011 	CALL	_DisplayUnit
298                     	.CHKPARA _DisplayUnit 0
299                     ;	;.line	168; ".\ADC_LCD.c"	adS.delayTimes_3=0;
300 01D1 [12] 0D7A      	CLRF	(_adS + 16),0
301 01D2 [12] 0D7B      	CLRF	(_adS + 17),0
302                     ;	;.line	170; ".\ADC_LCD.c"	switch(adS.plus_uint){
303 01D3 [12] 656B      	MVF	(_adS + 1),0,0
304 01D4 [12] 668B      	MVF	r0x1140,1,0
305 01D5 [12] 04FC      	ADDL	0xfc
306 01D6 [12] A82B      	BTSZ	_STATUS,4
307 01D7 [12] 7838      	JMP	_00113_DS_
308 01D8 [12] 0601      	MVL	HIGHD2(_00340_DS_)
309 01D9 [12] 661A      	MVF	_PCLATH,1,0
310 01DA [12] 06DF      	MVL	D2(_00340_DS_)
311 01DB [12] 108B      	ADDF	r0x1140,0,0
312 01DC [12] A82B      	BTSZ	_STATUS,4
313 01DD [12] 3A1A      	INF	_PCLATH,1,0
314 01DE [12] 661B      	MVF	_PCLATL,1,0
315                     _00340_DS_:
316 01DF [12] 7803      	RJ	_00105_DS_
317 01E0 [12] 780C      	RJ	_00106_DS_
318 01E1 [12] 7817      	RJ	_00107_DS_
319 01E2 [12] 7823      	RJ	_00108_DS_
320                     _00105_DS_:
321                     ;	;.line	172; ".\ADC_LCD.c"	adS.plus_uint++;
322 01E3 [12] 388B      	INF	r0x1140,0,0
323 01E4 [12] 676B      	MVF	(_adS + 1),1,0
324                     ;	;.line	173; ".\ADC_LCD.c"	adS.unitChoose = psi;
325 01E5 [12] 0D6C      	CLRF	(_adS + 2),0
326                     ;	;.line	174; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
327 01E6 [12] 0604      	MVL	0x04
328 01E7 [12] 6663      	MVF	_LCD4,1,0
329                     ;	;.line	175; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
330 01E8 [12] 0640      	MVL	0x40
331 01E9 [12] 6778      	MVF	(_adS + 14),1,0
332 01EA [12] 061F      	MVL	0x1f
333 01EB [12] 6779      	MVF	(_adS + 15),1,0
334                     ;	;.line	176; ".\ADC_LCD.c"	break;
335 01EC [12] 7823      	JMP	_00113_DS_
336                     _00106_DS_:
337                     ;	;.line	178; ".\ADC_LCD.c"	adS.plus_uint++;
338 01ED [12] 388B 0011 	INF	r0x1140,0,0
339 01EF [12] 676B      	MVF	(_adS + 1),1,0
340                     ;	;.line	179; ".\ADC_LCD.c"	adS.unitChoose = bar;
341 01F0 [12] 0601      	MVL	0x01
342 01F1 [12] 676C      	MVF	(_adS + 2),1,0
343                     ;	;.line	180; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
344 01F2 [12] 0602      	MVL	0x02
345 01F3 [12] 6663      	MVF	_LCD4,1,0
346                     ;	;.line	181; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
347 01F4 [12] 0640      	MVL	0x40
348 01F5 [12] 6778      	MVF	(_adS + 14),1,0
349 01F6 [12] 061F      	MVL	0x1f
350 01F7 [12] 6779      	MVF	(_adS + 15),1,0
351                     ;	;.line	182; ".\ADC_LCD.c"	break;
352 01F8 [12] 7817      	JMP	_00113_DS_
353                     _00107_DS_:
354                     ;	;.line	184; ".\ADC_LCD.c"	adS.plus_uint++;
355 01F9 [12] 3A8B      	INF	r0x1140,1,0
356 01FA [12] C60B      	MVF	r0x1140,0,0
357 01FB [12] F16B      	MVF	(_adS + 1),1,0
358                     ;	;.line	185; ".\ADC_LCD.c"	adS.unitChoose = kgf;
359 01FC [12] 0602 0011 	MVL	0x02
360 01FE [12] 676C      	MVF	(_adS + 2),1,0
361                     ;	;.line	186; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
362 01FF [12] 0601      	MVL	0x01
363 0200 [12] 6663      	MVF	_LCD4,1,0
364                     ;	;.line	187; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
365 0201 [12] 0640      	MVL	0x40
366 0202 [12] 6778      	MVF	(_adS + 14),1,0
367 0203 [12] 061F      	MVL	0x1f
368 0204 [12] 6779      	MVF	(_adS + 15),1,0
369                     ;	;.line	188; ".\ADC_LCD.c"	break;
370 0205 [12] 780A      	JMP	_00113_DS_
371 0206 [00] 0011      _00108_DS_:
372                     ;	;.line	190; ".\ADC_LCD.c"	adS.plus_uint=0;
373 0207 [12] 0D6B      	CLRF	(_adS + 1),0
374                     ;	;.line	191; ".\ADC_LCD.c"	adS.unitChoose = mpa;
375 0208 [12] 0603      	MVL	0x03
376 0209 [12] 676C      	MVF	(_adS + 2),1,0
377                     ;	;.line	192; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
378 020A [12] 0608      	MVL	0x08
379 020B [12] 6663      	MVF	_LCD4,1,0
380                     ;	;.line	193; ".\ADC_LCD.c"	adS.delayTimes_5=8000;
381 020C [12] 0640      	MVL	0x40
382 020D [12] 6778      	MVF	(_adS + 14),1,0
383 020E [12] 061F      	MVL	0x1f
384 020F [12] 6779      	MVF	(_adS + 15),1,0
385                     _00113_DS_:
386                     ;	;.line	199; ".\ADC_LCD.c"	if(adS.delayTimes_3 >=5000){ /* zero point mode*/
387 0210 [12] 0678      	MVL	0x78
388 0211 [12] 117A      	ADDF	(_adS + 16),0,0
389 0212 [12] 06EC      	MVL	0xec
390 0213 [12] 157B      	ADDC	(_adS + 17),0,0
391 0214 [12] B82B      	BTSS	_STATUS,4
392 0215 [12] 7FA2      	JMP	_00173_DS_
393                     ;	;.line	201; ".\ADC_LCD.c"	if(GPIO_READ_PT10()){
394 0216 [12] 6447      	MVF	_PT1,0,0
395 0217 [12] 0101      	ANDL	0x01
396 0218 [12] A02B      	BTSZ	_STATUS,0
397 0219 [12] 7F9E      	JMP	_00173_DS_
398                     ;	;.line	202; ".\ADC_LCD.c"	adS.zeroPoint_Mode = 1;
399 021A [12] 936D      	BSF	(_adS+3),1
400                     ;	;.line	204; ".\ADC_LCD.c"	adS.testMode =1;
401 021B [12] 916D      	BSF	(_adS+3),0
402                     ;	;.line	205; ".\ADC_LCD.c"	adS.delayTimes_3=0;
403 021C [12] 0D7A      	CLRF	(_adS + 16),0
404 021D [12] 0D7B      	CLRF	(_adS + 17),0
405                     ;	;.line	207; ".\ADC_LCD.c"	Display2Er();
406 021E [12] CEB5      	CALL	_Display2Er
407                     	.CHKPARA _Display2Er 0
408 021F [12] 7F98      	JMP	_00173_DS_
409 0220 [00] 0011      _00170_DS_:
410                     ;	;.line	218; ".\ADC_LCD.c"	if(adS.testMode == 0){ /* measure mode */
411 0221 [12] A16D      	BTSZ	(_adS+3),0
412 0222 [12] 7966      	JMP	_00138_DS_
413                     ;	;.line	219; ".\ADC_LCD.c"	adS.zeroPoint_Mode=0;
414 0223 [12] 836D      	BCF	(_adS+3),1
415                     ;	;.line	220; ".\ADC_LCD.c"	adS.key_flag =0;
416 0224 [12] 0D6E      	CLRF	(_adS + 4),0
417                     ;	;.line	221; ".\ADC_LCD.c"	adS.unit_setMode=0;
418 0225 [12] 836A      	BCF	_adS,1
419                     ;	;.line	222; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
420 0226 [12] C520      	MVL	0x20
421                     	MVF	_ADC_Open_STK10,1,0
422 0227 [13] 0C0D      	CLRF	_ADC_Open_STK09,0
423 0228 [14] C508      	MVL	0x08
424                     	MVF	_ADC_Open_STK08,1,0
425 0229 [15] C520      	MVL	0x20
426                     	MVF	_ADC_Open_STK07,1,0
427 022A [16] C518      	MVL	0x18
428                     	MVF	_ADC_Open_STK06,1,0
429 022B [17] C506      	MVL	0x06
430                     	MVF	_ADC_Open_STK05,1,0
431 022C [18] C510      	MVL	0x10
432                     	MVF	_ADC_Open_STK04,1,0
433 022D [19] 0C0D      	CLRF	_ADC_Open_STK03,0
434 022E [20] C501      	MVL	0x01
435                     	MVF	_ADC_Open_STK02,1,0
436 022F [21] C590      	MVL	0x90
437                     	MVF	_ADC_Open_STK01,1,0
438 0230 [22] C501      	MVL	0x01
439                     	MVF	_ADC_Open_STK00,1,0
440 0231 [23] 0610      	MVL	0x10
441 0232 [23] CE61      	CALL	_ADC_Open
442                     	.CHKPARA _ADC_Open 12
443                     ;	;.line	223; ".\ADC_LCD.c"	ADIF_ClearFlag();
444 0233 [12] 8A26      	BCF	_INTF0,5
445                     ;	;.line	224; ".\ADC_LCD.c"	ADIE_Enable();
446 0234 [12] 9A23      	BSF	_INTE0,5
447                     ;	;.line	225; ".\ADC_LCD.c"	GIE_Enable();
448 0235 [12] 9E23 0011 	BSF	_INTE0,7
449                     ;	;.line	227; ".\ADC_LCD.c"	if(MCUSTATUSbits.b_ADCdone==1)
450 0237 [12] B169      	BTSS	_MCUSTATUSbits,0
451 0238 [12] 7950      	JMP	_00138_DS_
452                     ;	;.line	229; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=0;
453 0239 [12] 8169      	BCF	_MCUSTATUSbits,0
454                     ;	;.line	231; ".\ADC_LCD.c"	ADC=ADC>>6;
455 023A [12] 6165      	SWPF	_ADC,0,0
456 023B [12] 010F      	ANDL	0x0f
457 023C [12] 6765      	MVF	_ADC,1,0
458 023D [12] 6166      	SWPF	(_ADC + 1),0,0
459 023E [12] 6766      	MVF	(_ADC + 1),1,0
460 023F [12] 01F0      	ANDL	0xf0
461 0240 [12] 2F65      	IORF	_ADC,1,0
462 0241 [12] 2366      	XORF	(_ADC + 1),1,0
463 0242 [12] 6167      	SWPF	(_ADC + 2),0,0
464 0243 [12] 6767      	MVF	(_ADC + 2),1,0
465 0244 [12] 01F0      	ANDL	0xf0
466 0245 [12] 2F66      	IORF	(_ADC + 1),1,0
467 0246 [12] 2367      	XORF	(_ADC + 2),1,0
468 0247 [12] 6168      	SWPF	(_ADC + 3),0,0
469 0248 [12] 6768      	MVF	(_ADC + 3),1,0
470 0249 [12] 01F0      	ANDL	0xf0
471 024A [12] 2F67      	IORF	(_ADC + 2),1,0
472 024B [12] 2368      	XORF	(_ADC + 3),1,0
473 024C [12] 06F0      	MVL	0xf0
474 024D [12] A768      	BTSZ	(_ADC + 3),3
475 024E [12] 2F68      	IORF	(_ADC + 3),1,0
476 024F [12] 5F68      	ARRC	(_ADC + 3),1,0
477 0250 [12] 5367      	RRFC	(_ADC + 2),1,0
478 0251 [12] 5366      	RRFC	(_ADC + 1),1,0
479 0252 [12] 5365      	RRFC	_ADC,1,0
480 0253 [12] 5F68      	ARRC	(_ADC + 3),1,0
481 0254 [12] 5367      	RRFC	(_ADC + 2),1,0
482 0255 [12] 5366      	RRFC	(_ADC + 1),1,0
483 0256 [12] 5365      	RRFC	_ADC,1,0
484                     ;	;.line	233; ".\ADC_LCD.c"	ADC = ADC * 0.1 ;
485 0257 [12] D165      	MVF	_ADC,0,0
486 0258 [12] F00D      	MVF	___slong2fs_STK02,1,0
487 0259 [13] D166      	MVF	(_ADC + 1),0,0
488 025A [13] F00D      	MVF	___slong2fs_STK01,1,0
489 025B [14] D167      	MVF	(_ADC + 2),0,0
490 025C [14] F00D      	MVF	___slong2fs_STK00,1,0
491 025D [15] 6568      	MVF	(_ADC + 3),0,0
492 025E [15] CA92      	CALL	___slong2fs
493                     	.CHKPARA ___slong2fs 4
494 025F [12] 6689      	MVF	r0x1143,1,0
495 0260 [12] D01E      	MVF	STK02,0,0
496 0261 [12] F00D      	MVF	___fsmul_STK06,1,0
497 0262 [13] D01F      	MVF	STK01,0,0
498 0263 [13] F00D      	MVF	___fsmul_STK05,1,0
499 0264 [14] D020      	MVF	STK00,0,0
500 0265 [14] F00D      	MVF	___fsmul_STK04,1,0
501 0266 [15] C60C      	MVF	r0x1143,0,0
502 0267 [15] F00D      	MVF	___fsmul_STK03,1,0
503 0268 [16] C5CD      	MVL	0xcd
504                     	MVF	___fsmul_STK02,1,0
505 0269 [17] C5CC      	MVL	0xcc
506                     	MVF	___fsmul_STK01,1,0
507 026A [18] C5CC      	MVF	___fsmul_STK00,1,0
508 026B [19] 063D      	MVL	0x3d
509 026C [19] C000 F922 	CALL	___fsmul
510                     	.CHKPARA ___fsmul 8
511 026E [12] 6689      	MVF	r0x1143,1,0
512 026F [12] D01E      	MVF	STK02,0,0
513 0270 [12] F00D      	MVF	___fs2slong_STK02,1,0
514 0271 [13] D01F      	MVF	STK01,0,0
515 0272 [13] F00D      	MVF	___fs2slong_STK01,1,0
516 0273 [14] D020      	MVF	STK00,0,0
517 0274 [14] F00D      	MVF	___fs2slong_STK00,1,0
518 0275 [15] 648C      	MVF	r0x1143,0,0
519 0276 [15] C000 F69C 
519 0278 0011           	CALL	___fs2slong
520                     	.CHKPARA ___fs2slong 4
521 0279 [12] 6768      	MVF	(_ADC + 3),1,0
522 027A [12] D020      	MVF	STK00,0,0
523 027B [12] F167      	MVF	(_ADC + 2),1,0
524 027C [12] D01F      	MVF	STK01,0,0
525 027D [12] F166      	MVF	(_ADC + 1),1,0
526 027E [12] D01E      	MVF	STK02,0,0
527 027F [12] F165      	MVF	_ADC,1,0
528                     ;	;.line	234; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
529 0280 [12] 06BF      	MVL	0xbf
530 0281 [12] 2847      	ANDF	_PT1,0,0
531 0282 [12] 0240      	IORL	0x40
532 0283 [12] 6647      	MVF	_PT1,1,0
533                     ;	;.line	235; ".\ADC_LCD.c"	Delay(20000);
534 0284 [12] C520      	MVL	0x20
535                     	MVF	_Delay_STK00,1,0
536 0285 [13] 064E      	MVL	0x4e
537 0286 [13] CE66      	CALL	_Delay
538                     	.CHKPARA _Delay 2
539                     ;	;.line	236; ".\ADC_LCD.c"	GPIO_PT16_LOW();
540 0287 [12] 8C47 0011 	BCF	_PT1,6
541                     ;	;.line	237; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
542 0289 [12] AF68      	BTSZ	(_ADC + 3),7
543 028A [12] 7809      	JMP	_00122_DS_
544 028B [12] 3165      	DCF	_ADC,0,0
545 028C [12] 06FF      	MVL	0xff
546 028D [12] 1566      	ADDC	(_ADC + 1),0,0
547 028E [12] 06FF      	MVL	0xff
548 028F [12] 1567      	ADDC	(_ADC + 2),0,0
549 0290 [12] 067F      	MVL	0x7f
550 0291 [12] 1568      	ADDC	(_ADC + 3),0,0
551 0292 [12] B82B      	BTSS	_STATUS,4
552 0293 [12] 7802      	JMP	_00123_DS_
553                     _00122_DS_:
554                     ;	;.line	240; ".\ADC_LCD.c"	adS.Pressure_sign =1;
555 0294 [12] 9D70      	BSF	(_adS+6),6
556 0295 [12] 7811      	JMP	_00124_DS_
557                     _00123_DS_:
558                     ;	;.line	244; ".\ADC_LCD.c"	if( ADC < 1600 && ADC >=0 ) {
559 0296 [12] 06C0 0011 	MVL	0xc0
560 0298 [12] 1165      	ADDF	_ADC,0,0
561 0299 [12] 06F9      	MVL	0xf9
562 029A [12] 1566      	ADDC	(_ADC + 1),0,0
563 029B [12] 06FF      	MVL	0xff
564 029C [12] 1567      	ADDC	(_ADC + 2),0,0
565 029D [12] 067F      	MVL	0x7f
566 029E [12] 1568      	ADDC	(_ADC + 3),0,0
567 029F [12] A22B      	BTSZ	_STATUS,1
568 02A0 [12] 7804      	JMP	_00119_DS_
569 02A1 [12] AF68      	BTSZ	(_ADC + 3),7
570 02A2 [12] 7802      	JMP	_00119_DS_
571                     ;	;.line	245; ".\ADC_LCD.c"	adS.Pressure_sign =1;
572 02A3 [12] 9D70      	BSF	(_adS+6),6
573 02A4 [12] 7802      	JMP	_00124_DS_
574 02A5 [00] 0011      _00119_DS_:
575                     ;	;.line	249; ".\ADC_LCD.c"	adS.Pressure_sign =0;
576 02A6 [12] 8D70      	BCF	(_adS+6),6
577                     _00124_DS_:
578                     ;	;.line	255; ".\ADC_LCD.c"	if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/
579 02A7 [12] AD70      	BTSZ	(_adS+6),6
580 02A8 [12] 7802      	JMP	_00133_DS_
581                     ;	;.line	257; ".\ADC_LCD.c"	PositivePressureWorks_Mode();
582 02A9 [12] CA6D      	CALL	_PositivePressureWorks_Mode
583                     	.CHKPARA _PositivePressureWorks_Mode 0
584 02AA [12] 78DE      	JMP	_00138_DS_
585 02AB [00] 0011      _00133_DS_:
586                     ;	;.line	261; ".\ADC_LCD.c"	adS.Pressure_sign =1;
587 02AC [12] 9D70      	BSF	(_adS+6),6
588                     ;	;.line	264; ".\ADC_LCD.c"	theta= abs(ADC) - adS.m_offset_value;  
589 02AD [12] 3165      	DCF	_ADC,0,0
590 02AE [12] 06FF      	MVL	0xff
591 02AF [12] 1566      	ADDC	(_ADC + 1),0,0
592 02B0 [12] 06FF      	MVL	0xff
593 02B1 [12] 1567      	ADDC	(_ADC + 2),0,0
594 02B2 [12] 067F      	MVL	0x7f
595 02B3 [12] 1568      	ADDC	(_ADC + 3),0,0
596 02B4 [12] B22B      	BTSS	_STATUS,1
597 02B5 [12] 7809      	JMP	_00177_DS_
598 02B6 [12] 6565      	MVF	_ADC,0,0
599 02B7 [12] 6687      	MVF	r0x1144,1,0
600 02B8 [12] 6566      	MVF	(_ADC + 1),0,0
601 02B9 [12] 6686      	MVF	r0x1145,1,0
602 02BA [12] 6567      	MVF	(_ADC + 2),0,0
603 02BB [12] 6685      	MVF	r0x1146,1,0
604 02BC [12] 6568      	MVF	(_ADC + 3),0,0
605 02BD [12] 6684      	MVF	r0x1147,1,0
606 02BE [12] 780E      	JMP	_00178_DS_
607 02BF [00] 0011      _00177_DS_:
608 02C0 [12] 2565      	COMF	_ADC,0,0
609 02C1 [12] 6687      	MVF	r0x1144,1,0
610 02C2 [12] 2566      	COMF	(_ADC + 1),0,0
611 02C3 [12] 6686      	MVF	r0x1145,1,0
612 02C4 [12] 2567      	COMF	(_ADC + 2),0,0
613 02C5 [12] 6685      	MVF	r0x1146,1,0
614 02C6 [12] 2568      	COMF	(_ADC + 3),0,0
615 02C7 [12] 6684      	MVF	r0x1147,1,0
616 02C8 [12] 3A87      	INF	r0x1144,1,0
617 02C9 [12] 0600      	MVL	0x00
618 02CA [12] 1686      	ADDC	r0x1145,1,0
619 02CB [12] 1685      	ADDC	r0x1146,1,0
620 02CC [12] 1684      	ADDC	r0x1147,1,0
621                     _00178_DS_:
622 02CD [12] 0600      	MVL	0x00
623 02CE [12] AF7D      	BTSZ	(_adS + 19),7
624 02CF [12] 06FF      	MVL	0xff
625 02D0 [12] 6681      	MVF	r0x114D,1,0
626 02D1 [12] 6680      	MVF	r0x114C,1,0
627 02D2 [12] 657C      	MVF	(_adS + 18),0,0
628 02D3 [12] 1A87      	SUBF	r0x1144,1,0
629 02D4 [12] 657D      	MVF	(_adS + 19),0,0
630 02D5 [12] 1E86      	SUBC	r0x1145,1,0
631 02D6 [12] 6480      	MVF	r0x114C,0,0
632 02D7 [12] 1E85      	SUBC	r0x1146,1,0
633 02D8 [12] 6481      	MVF	r0x114D,0,0
634 02D9 [12] 1E84      	SUBC	r0x1147,1,0
635                     ;	;.line	265; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
636 02DA [12] B970      	BTSS	(_adS+6),4
637 02DB [12] 7879      	JMP	_00130_DS_
638                     ;	;.line	270; ".\ADC_LCD.c"	if(delta >=0 ){
639 02DC [12] AF68      	BTSZ	(_ADC + 3),7
640 02DD [12] 783C      	JMP	_00127_DS_
641                     ;	;.line	271; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
642 02DE [12] C607      	MVF	r0x1144,0,0
643 02DF [12] F00D      	MVF	___slong2fs_STK02,1,0
644 02E0 [13] C607      	MVF	r0x1145,0,0
645 02E1 [13] F00D      	MVF	___slong2fs_STK01,1,0
646 02E2 [14] C607      	MVF	r0x1146,0,0
647 02E3 [14] F00D      	MVF	___slong2fs_STK00,1,0
648 02E4 [15] 6487      	MVF	r0x1147,0,0
649 02E5 [15] CA0B      	CALL	___slong2fs
650                     	.CHKPARA ___slong2fs 4
651 02E6 [12] 6689      	MVF	r0x1143,1,0
652 02E7 [12] D01E      	MVF	STK02,0,0
653 02E8 [12] F00D      	MVF	___fsmul_STK06,1,0
654 02E9 [13] D01F      	MVF	STK01,0,0
655 02EA [13] F00D      	MVF	___fsmul_STK05,1,0
656 02EB [14] D020      	MVF	STK00,0,0
657 02EC [14] F00D      	MVF	___fsmul_STK04,1,0
658 02ED [15] C60C      	MVF	r0x1143,0,0
659 02EE [15] F00D      	MVF	___fsmul_STK03,1,0
660 02EF [16] C525      	MVL	0x25
661                     	MVF	___fsmul_STK02,1,0
662 02F0 [17] C506      	MVL	0x06
663                     	MVF	___fsmul_STK01,1,0
664 02F1 [18] C501      	MVL	0x01
665                     	MVF	___fsmul_STK00,1,0
666 02F2 [19] 063E      	MVL	0x3e
667 02F3 [19] C000 F922 	CALL	___fsmul
668                     	.CHKPARA ___fsmul 8
669 02F5 [12] 6689      	MVF	r0x1143,1,0
670 02F6 [12] D01E      	MVF	STK02,0,0
671 02F7 [12] F00D      	MVF	___fssub_STK06,1,0
672 02F8 [13] D01F      	MVF	STK01,0,0
673 02F9 [13] F00D      	MVF	___fssub_STK05,1,0
674 02FA [14] D020      	MVF	STK00,0,0
675 02FB [14] F00D      	MVF	___fssub_STK04,1,0
676 02FC [15] 648C      	MVF	r0x1143,0,0
677 02FD [15] 660D      	MVF	___fssub_STK03,1,0
678 02FE [16] 0C0D      	CLRF	___fssub_STK02,0
679 02FF [17] 0C0D      	CLRF	___fssub_STK01,0
680 0300 [18] C548      	MVL	0x48
681                     	MVF	___fssub_STK00,1,0
682 0301 [19] 0643      	MVL	0x43
683 0302 [19] C000 F718 	CALL	___fssub
684                     	.CHKPARA ___fssub 8
685 0304 [12] 6689      	MVF	r0x1143,1,0
686 0305 [12] D01E      	MVF	STK02,0,0
687                     ;	;.line	272; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
688 0306 [12] F00D      	MVF	___fs2slong_STK02,1,0
689 0307 [13] D01F      	MVF	STK01,0,0
690 0308 [13] F00D      	MVF	___fs2slong_STK01,1,0
691 0309 [14] D020      	MVF	STK00,0,0
692 030A [14] F00D      	MVF	___fs2slong_STK00,1,0
693 030B [15] 648C      	MVF	r0x1143,0,0
694 030C [15] CB8F      	CALL	___fs2slong
695                     	.CHKPARA ___fs2slong 4
696 030D [12] 6689      	MVF	r0x1143,1,0
697 030E [12] D01E      	MVF	STK02,0,0
698 030F [12] F00D      	MVF	_DisplayNum_STK02,1,0
699 0310 [13] D01F      	MVF	STK01,0,0
700 0311 [13] F00D      	MVF	_DisplayNum_STK01,1,0
701 0312 [14] D020      	MVF	STK00,0,0
702 0313 [14] F00D      	MVF	_DisplayNum_STK00,1,0
703 0314 [15] 648C      	MVF	r0x1143,0,0
704 0315 [15] CBC0      	CALL	_DisplayNum
705                     	.CHKPARA _DisplayNum 4
706                     ;	;.line	273; ".\ADC_LCD.c"	Delay(20000);
707 0316 [12] C520      	MVL	0x20
708                     	MVF	_Delay_STK00,1,0
709 0317 [13] 064E      	MVL	0x4e
710 0318 [13] CDD4      	CALL	_Delay
711                     	.CHKPARA _Delay 2
712 0319 [12] 786F      	JMP	_00138_DS_
713                     _00127_DS_:
714                     ;	;.line	284; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
715 031A [12] C607      	MVF	r0x1144,0,0
716 031B [12] F00D      	MVF	___slong2fs_STK02,1,0
717 031C [13] C607      	MVF	r0x1145,0,0
718 031D [13] F00D      	MVF	___slong2fs_STK01,1,0
719 031E [14] C607      	MVF	r0x1146,0,0
720 031F [14] F00D      	MVF	___slong2fs_STK00,1,0
721 0320 [15] 6487      	MVF	r0x1147,0,0
722 0321 [15] C9CF      	CALL	___slong2fs
723                     	.CHKPARA ___slong2fs 4
724 0322 [12] 6689      	MVF	r0x1143,1,0
725 0323 [12] D01E      	MVF	STK02,0,0
726 0324 [12] F00D      	MVF	___fsmul_STK06,1,0
727 0325 [13] D01F      	MVF	STK01,0,0
728 0326 [13] F00D      	MVF	___fsmul_STK05,1,0
729 0327 [14] D020      	MVF	STK00,0,0
730 0328 [14] F00D      	MVF	___fsmul_STK04,1,0
731 0329 [15] 648C      	MVF	r0x1143,0,0
732 032A [15] 660D      	MVF	___fsmul_STK03,1,0
733 032B [16] 0C0D      	CLRF	___fsmul_STK02,0
734 032C [17] 0C0D      	CLRF	___fsmul_STK01,0
735 032D [18] 0C0D      	CLRF	___fsmul_STK00,0
736 032E [19] 063E      	MVL	0x3e
737 032F [19] C000 F922 	CALL	___fsmul
738                     	.CHKPARA ___fsmul 8
739 0331 [12] 6689      	MVF	r0x1143,1,0
740 0332 [12] 0C0D      	CLRF	___fsadd_STK06,0
741 0333 [13] 0C0D      	CLRF	___fsadd_STK05,0
742 0334 [14] C54C      	MVL	0x4c
743                     	MVF	___fsadd_STK04,1,0
744 0335 [15] C543      	MVL	0x43
745                     	MVF	___fsadd_STK03,1,0
746 0336 [16] D01E      	MVF	STK02,0,0
747 0337 [16] F00D      	MVF	___fsadd_STK02,1,0
748 0338 [17] D01F      	MVF	STK01,0,0
749 0339 [17] F00D      	MVF	___fsadd_STK01,1,0
750 033A [18] D020      	MVF	STK00,0,0
751 033B [18] F00D      	MVF	___fsadd_STK00,1,0
752 033C [19] 6490      	MVF	r0x1143,0,0
753 033D [19] C000 FA8B 	CALL	___fsadd
754                     	.CHKPARA ___fsadd 8
755 033F [12] 6689      	MVF	r0x1143,1,0
756 0340 [12] D01E      	MVF	STK02,0,0
757                     ;	;.line	285; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
758 0341 [12] F00D      	MVF	___fs2slong_STK02,1,0
759 0342 [13] D01F      	MVF	STK01,0,0
760 0343 [13] F00D      	MVF	___fs2slong_STK01,1,0
761 0344 [14] D020      	MVF	STK00,0,0
762 0345 [14] F00D      	MVF	___fs2slong_STK00,1,0
763 0346 [15] 648C      	MVF	r0x1143,0,0
764 0347 [15] CB54      	CALL	___fs2slong
765                     	.CHKPARA ___fs2slong 4
766 0348 [12] 6689      	MVF	r0x1143,1,0
767 0349 [12] D01E      	MVF	STK02,0,0
768 034A [12] F00D      	MVF	_DisplayNum_STK02,1,0
769 034B [13] D01F      	MVF	STK01,0,0
770 034C [13] F00D      	MVF	_DisplayNum_STK01,1,0
771 034D [14] D020      	MVF	STK00,0,0
772 034E [14] F00D      	MVF	_DisplayNum_STK00,1,0
773 034F [15] 648C      	MVF	r0x1143,0,0
774 0350 [15] CB85      	CALL	_DisplayNum
775                     	.CHKPARA _DisplayNum 4
776                     ;	;.line	286; ".\ADC_LCD.c"	Delay(20000);
777 0351 [12] C520      	MVL	0x20
778                     	MVF	_Delay_STK00,1,0
779 0352 [13] 064E      	MVL	0x4e
780 0353 [13] CD99      	CALL	_Delay
781                     	.CHKPARA _Delay 2
782 0354 [12] 7834      	JMP	_00138_DS_
783 0355 [00] 0011      _00130_DS_:
784                     ;	;.line	293; ".\ADC_LCD.c"	ADC = abs(ADC);
785 0356 [12] 3165      	DCF	_ADC,0,0
786 0357 [12] 06FF      	MVL	0xff
787 0358 [12] 1566      	ADDC	(_ADC + 1),0,0
788 0359 [12] 06FF      	MVL	0xff
789 035A [12] 1567      	ADDC	(_ADC + 2),0,0
790 035B [12] 067F      	MVL	0x7f
791 035C [12] 1568      	ADDC	(_ADC + 3),0,0
792 035D [12] B22B      	BTSS	_STATUS,1
793 035E [12] 7809      	JMP	_00179_DS_
794 035F [12] 6565      	MVF	_ADC,0,0
795 0360 [12] 668B      	MVF	r0x1140,1,0
796 0361 [12] 6566      	MVF	(_ADC + 1),0,0
797 0362 [12] 668A      	MVF	r0x1141,1,0
798 0363 [12] 6567      	MVF	(_ADC + 2),0,0
799 0364 [12] 6688      	MVF	r0x1142,1,0
800 0365 [12] 6568      	MVF	(_ADC + 3),0,0
801 0366 [12] 6689      	MVF	r0x1143,1,0
802 0367 [12] 780E      	JMP	_00180_DS_
803 0368 [00] 0011      _00179_DS_:
804 0369 [12] 2565      	COMF	_ADC,0,0
805 036A [12] 668B      	MVF	r0x1140,1,0
806 036B [12] 2566      	COMF	(_ADC + 1),0,0
807 036C [12] 668A      	MVF	r0x1141,1,0
808 036D [12] 2567      	COMF	(_ADC + 2),0,0
809 036E [12] 6688      	MVF	r0x1142,1,0
810 036F [12] 2568      	COMF	(_ADC + 3),0,0
811 0370 [12] 6689      	MVF	r0x1143,1,0
812 0371 [12] 3A8B      	INF	r0x1140,1,0
813 0372 [12] 0600      	MVL	0x00
814 0373 [12] 168A      	ADDC	r0x1141,1,0
815 0374 [12] 1688      	ADDC	r0x1142,1,0
816 0375 [12] 1689      	ADDC	r0x1143,1,0
817                     _00180_DS_:
818 0376 [12] C60B      	MVF	r0x1140,0,0
819 0377 [12] F165      	MVF	_ADC,1,0
820 0378 [12] C60A      	MVF	r0x1141,0,0
821 0379 [12] F166      	MVF	(_ADC + 1),1,0
822 037A [12] C608      	MVF	r0x1142,0,0
823 037B [12] F167      	MVF	(_ADC + 2),1,0
824 037C [12] C609      	MVF	r0x1143,0,0
825 037D [12] F168      	MVF	(_ADC + 3),1,0
826                     ;	;.line	294; ".\ADC_LCD.c"	DisplayNum(ADC);
827 037E [12] D165      	MVF	_ADC,0,0
828 037F [12] F00D      	MVF	_DisplayNum_STK02,1,0
829 0380 [13] D166      	MVF	(_ADC + 1),0,0
830 0381 [13] F00D      	MVF	_DisplayNum_STK01,1,0
831 0382 [14] D167      	MVF	(_ADC + 2),0,0
832 0383 [14] F00D      	MVF	_DisplayNum_STK00,1,0
833 0384 [15] 6568      	MVF	(_ADC + 3),0,0
834 0385 [15] CB50      	CALL	_DisplayNum
835                     	.CHKPARA _DisplayNum 4
836                     ;	;.line	295; ".\ADC_LCD.c"	Delay(20000);
837 0386 [12] C520      	MVL	0x20
838                     	MVF	_Delay_STK00,1,0
839 0387 [13] 064E      	MVL	0x4e
840 0388 [13] CD64      	CALL	_Delay
841                     	.CHKPARA _Delay 2
842 0389 [00] 0011      _00138_DS_:
843                     ;	;.line	300; ".\ADC_LCD.c"	if(adS.zeroPoint_Mode == 1){ /*zero point mode */
844 038A [12] B36D      	BTSS	(_adS+3),1
845 038B [12] 78B6      	JMP	_00147_DS_
846                     ;	;.line	302; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
847 038C [12] 836D      	BCF	(_adS+3),1
848                     ;	;.line	303; ".\ADC_LCD.c"	adS.testMode=0;
849 038D [12] 816D      	BCF	(_adS+3),0
850                     ;	;.line	304; ".\ADC_LCD.c"	ADC=ADC>>6;
851 038E [12] 6165      	SWPF	_ADC,0,0
852 038F [12] 010F      	ANDL	0x0f
853 0390 [12] 6765      	MVF	_ADC,1,0
854 0391 [12] 6166      	SWPF	(_ADC + 1),0,0
855 0392 [12] 6766      	MVF	(_ADC + 1),1,0
856 0393 [12] 01F0      	ANDL	0xf0
857 0394 [12] 2F65      	IORF	_ADC,1,0
858 0395 [12] 2366      	XORF	(_ADC + 1),1,0
859 0396 [12] 6167      	SWPF	(_ADC + 2),0,0
860 0397 [12] 6767      	MVF	(_ADC + 2),1,0
861 0398 [12] 01F0      	ANDL	0xf0
862 0399 [12] 2F66      	IORF	(_ADC + 1),1,0
863 039A [12] 2367      	XORF	(_ADC + 2),1,0
864 039B [12] 6168      	SWPF	(_ADC + 3),0,0
865 039C [12] 6768      	MVF	(_ADC + 3),1,0
866 039D [12] 01F0      	ANDL	0xf0
867 039E [12] 2F67      	IORF	(_ADC + 2),1,0
868 039F [12] 2368      	XORF	(_ADC + 3),1,0
869 03A0 [12] 06F0      	MVL	0xf0
870 03A1 [12] A768      	BTSZ	(_ADC + 3),3
871 03A2 [12] 2F68      	IORF	(_ADC + 3),1,0
872 03A3 [12] 5F68      	ARRC	(_ADC + 3),1,0
873 03A4 [12] 5367      	RRFC	(_ADC + 2),1,0
874 03A5 [12] 5366      	RRFC	(_ADC + 1),1,0
875 03A6 [12] 5365      	RRFC	_ADC,1,0
876 03A7 [12] 5F68      	ARRC	(_ADC + 3),1,0
877 03A8 [12] 5367      	RRFC	(_ADC + 2),1,0
878 03A9 [12] 5366      	RRFC	(_ADC + 1),1,0
879 03AA [12] 5365      	RRFC	_ADC,1,0
880                     ;	;.line	305; ".\ADC_LCD.c"	ADC = ADC * 0.1;
881 03AB [12] D165      	MVF	_ADC,0,0
882 03AC [12] F00D      	MVF	___slong2fs_STK02,1,0
883 03AD [13] D166      	MVF	(_ADC + 1),0,0
884 03AE [13] F00D      	MVF	___slong2fs_STK01,1,0
885 03AF [14] D167      	MVF	(_ADC + 2),0,0
886 03B0 [14] F00D      	MVF	___slong2fs_STK00,1,0
887 03B1 [15] 6568      	MVF	(_ADC + 3),0,0
888 03B2 [15] C93E      	CALL	___slong2fs
889                     	.CHKPARA ___slong2fs 4
890 03B3 [12] 6689      	MVF	r0x1143,1,0
891 03B4 [12] D01E      	MVF	STK02,0,0
892 03B5 [12] F00D      	MVF	___fsmul_STK06,1,0
893 03B6 [13] D01F      	MVF	STK01,0,0
894 03B7 [13] F00D      	MVF	___fsmul_STK05,1,0
895 03B8 [14] D020      	MVF	STK00,0,0
896 03B9 [14] F00D      	MVF	___fsmul_STK04,1,0
897 03BA [15] C60C      	MVF	r0x1143,0,0
898 03BB [15] F00D      	MVF	___fsmul_STK03,1,0
899 03BC [16] C5CD      	MVL	0xcd
900                     	MVF	___fsmul_STK02,1,0
901 03BD [17] C5CC      	MVL	0xcc
902                     	MVF	___fsmul_STK01,1,0
903 03BE [18] C5CC      	MVF	___fsmul_STK00,1,0
904 03BF [19] 063D      	MVL	0x3d
905 03C0 [19] C000 F922 	CALL	___fsmul
906                     	.CHKPARA ___fsmul 8
907 03C2 [12] 6689      	MVF	r0x1143,1,0
908 03C3 [12] D01E      	MVF	STK02,0,0
909 03C4 [12] F00D      	MVF	___fs2slong_STK02,1,0
910 03C5 [13] D01F      	MVF	STK01,0,0
911 03C6 [13] F00D      	MVF	___fs2slong_STK01,1,0
912 03C7 [14] D020      	MVF	STK00,0,0
913 03C8 [14] F00D      	MVF	___fs2slong_STK00,1,0
914 03C9 [15] 648C      	MVF	r0x1143,0,0
915 03CA [15] CAD1 0011 	CALL	___fs2slong
916                     	.CHKPARA ___fs2slong 4
917 03CC [12] 6768      	MVF	(_ADC + 3),1,0
918 03CD [12] D020      	MVF	STK00,0,0
919 03CE [12] F167      	MVF	(_ADC + 2),1,0
920 03CF [12] D01F      	MVF	STK01,0,0
921 03D0 [12] F166      	MVF	(_ADC + 1),1,0
922 03D1 [12] 641E      	MVF	STK02,0,0
923 03D2 [12] 6765      	MVF	_ADC,1,0
924                     ;	;.line	306; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
925 03D3 [12] AF68      	BTSZ	(_ADC + 3),7
926 03D4 [12] 7809      	JMP	_00139_DS_
927 03D5 [12] 3165      	DCF	_ADC,0,0
928 03D6 [12] 06FF      	MVL	0xff
929 03D7 [12] 1566      	ADDC	(_ADC + 1),0,0
930 03D8 [12] 06FF      	MVL	0xff
931 03D9 [12] 1567      	ADDC	(_ADC + 2),0,0
932 03DA [12] 067F      	MVL	0x7f
933 03DB [12] 1568      	ADDC	(_ADC + 3),0,0
934 03DC [12] B82B      	BTSS	_STATUS,4
935 03DD [12] 7802      	JMP	_00140_DS_
936                     _00139_DS_:
937                     ;	;.line	309; ".\ADC_LCD.c"	adS.Pressure_sign =1;
938 03DE [12] 9D70      	BSF	(_adS+6),6
939 03DF [12] 7802      	JMP	_00141_DS_
940 03E0 [00] 0011      _00140_DS_:
941                     ;	;.line	313; ".\ADC_LCD.c"	adS.Pressure_sign =0;
942 03E1 [12] 8D70      	BCF	(_adS+6),6
943                     _00141_DS_:
944                     ;	;.line	319; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
945 03E2 [12] BD70      	BTSS	(_adS+6),6
946 03E3 [12] 7826      	JMP	_00144_DS_
947                     ;	;.line	320; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1;
948 03E4 [12] 3165      	DCF	_ADC,0,0
949 03E5 [12] 06FF      	MVL	0xff
950 03E6 [12] 1566      	ADDC	(_ADC + 1),0,0
951 03E7 [12] 06FF      	MVL	0xff
952 03E8 [12] 1567      	ADDC	(_ADC + 2),0,0
953 03E9 [12] 067F      	MVL	0x7f
954 03EA [12] 1568      	ADDC	(_ADC + 3),0,0
955 03EB [12] B22B      	BTSS	_STATUS,1
956 03EC [12] 7805      	JMP	_00181_DS_
957 03ED [12] 6565      	MVF	_ADC,0,0
958 03EE [12] 668B      	MVF	r0x1140,1,0
959 03EF [12] 6566      	MVF	(_ADC + 1),0,0
960 03F0 [12] 668A      	MVF	r0x1141,1,0
961 03F1 [12] 780E      	JMP	_00182_DS_
962 03F2 [00] 0011      _00181_DS_:
963 03F3 [12] 2565      	COMF	_ADC,0,0
964 03F4 [12] 668B      	MVF	r0x1140,1,0
965 03F5 [12] 2566      	COMF	(_ADC + 1),0,0
966 03F6 [12] 668A      	MVF	r0x1141,1,0
967 03F7 [12] 2567      	COMF	(_ADC + 2),0,0
968 03F8 [12] 6688      	MVF	r0x1142,1,0
969 03F9 [12] 2568      	COMF	(_ADC + 3),0,0
970 03FA [12] 6689      	MVF	r0x1143,1,0
971 03FB [12] 3A8B      	INF	r0x1140,1,0
972 03FC [12] 0600      	MVL	0x00
973 03FD [12] 168A      	ADDC	r0x1141,1,0
974 03FE [12] 1688      	ADDC	r0x1142,1,0
975 03FF [12] 1689      	ADDC	r0x1143,1,0
976                     _00182_DS_:
977 0400 [12] 0637      	MVL	0x37
978 0401 [12] 108B      	ADDF	r0x1140,0,0
979 0402 [12] 668B      	MVF	r0x1140,1,0
980 0403 [12] 06E7      	MVL	0xe7
981 0404 [12] 148A      	ADDC	r0x1141,0,0
982 0405 [12] C60B F17C 	MVSF	r0x1140,(_adS + 18)
983 0407 [12] 677D      	MVF	(_adS + 19),1,0
984                     ;	;.line	321; ".\ADC_LCD.c"	adS.minus_revise_flag=1;
985 0408 [12] 9970      	BSF	(_adS+6),4
986 0409 [12] 7838      	JMP	_00147_DS_
987 040A [00] 0011      _00144_DS_:
988                     ;	;.line	327; ".\ADC_LCD.c"	adS.p_offset_value= abs(STD_VALUE) -abs(ADC) + 1; 
989 040B [12] 3165      	DCF	_ADC,0,0
990 040C [12] 06FF      	MVL	0xff
991 040D [12] 1566      	ADDC	(_ADC + 1),0,0
992 040E [12] 06FF      	MVL	0xff
993 040F [12] 1567      	ADDC	(_ADC + 2),0,0
994 0410 [12] 067F      	MVL	0x7f
995 0411 [12] 1568      	ADDC	(_ADC + 3),0,0
996 0412 [12] B22B      	BTSS	_STATUS,1
997 0413 [12] 7805      	JMP	_00183_DS_
998 0414 [12] 6565      	MVF	_ADC,0,0
999 0415 [12] 668B      	MVF	r0x1140,1,0
1000 0416 [12] 6566      	MVF	(_ADC + 1),0,0
1001 0417 [12] 668A      	MVF	r0x1141,1,0
1002 0418 [12] 780E      	JMP	_00184_DS_
1003 0419 [00] 0011      _00183_DS_:
1004 041A [12] 2565      	COMF	_ADC,0,0
1005 041B [12] 668B      	MVF	r0x1140,1,0
1006 041C [12] 2566      	COMF	(_ADC + 1),0,0
1007 041D [12] 668A      	MVF	r0x1141,1,0
1008 041E [12] 2567      	COMF	(_ADC + 2),0,0
1009 041F [12] 6687      	MVF	r0x1144,1,0
1010 0420 [12] 2568      	COMF	(_ADC + 3),0,0
1011 0421 [12] 6686      	MVF	r0x1145,1,0
1012 0422 [12] 3A8B      	INF	r0x1140,1,0
1013 0423 [12] 0600      	MVL	0x00
1014 0424 [12] 168A      	ADDC	r0x1141,1,0
1015 0425 [12] 1687      	ADDC	r0x1144,1,0
1016 0426 [12] 1686      	ADDC	r0x1145,1,0
1017                     _00184_DS_:
1018 0427 [12] 248B      	COMF	r0x1140,0,0
1019 0428 [12] 047E      	ADDL	0x7e
1020 0429 [12] 668B      	MVF	r0x1140,1,0
1021 042A [12] 268A      	COMF	r0x1141,1,0
1022 042B [12] 0619      	MVL	0x19
1023 042C [12] 168A      	ADDC	r0x1141,1,0
1024 042D [12] C60B      	MVF	r0x1140,0,0
1025 042E [12] F17E      	MVF	(_adS + 20),1,0
1026 042F [12] 648A      	MVF	r0x1141,0,0
1027 0430 [12] 677F      	MVF	(_adS + 21),1,0
1028                     ;	;.line	328; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
1029 0431 [12] 9770      	BSF	(_adS+6),3
1030                     ;	;.line	329; ".\ADC_LCD.c"	DisplayNum( adS.p_offset_value);
1031 0432 [12] 0600      	MVL	0x00
1032 0433 [12] AE8A      	BTSZ	r0x1141,7
1033 0434 [12] 06FF      	MVL	0xff
1034 0435 [12] 6682      	MVF	r0x1149,1,0
1035 0436 [12] 6683      	MVF	r0x1148,1,0
1036 0437 [12] C60B      	MVF	r0x1140,0,0
1037 0438 [12] F00D      	MVF	_DisplayNum_STK02,1,0
1038 0439 [13] C60B      	MVF	r0x1141,0,0
1039 043A [13] F00D      	MVF	_DisplayNum_STK01,1,0
1040 043B [14] C605      	MVF	r0x1148,0,0
1041 043C [14] F00D      	MVF	_DisplayNum_STK00,1,0
1042 043D [15] 6485      	MVF	r0x1149,0,0
1043 043E [15] CA97      	CALL	_DisplayNum
1044                     	.CHKPARA _DisplayNum 4
1045                     ;	;.line	330; ".\ADC_LCD.c"	Delay(20000);
1046 043F [12] C520      	MVL	0x20
1047                     	MVF	_Delay_STK00,1,0
1048 0440 [13] 064E      	MVL	0x4e
1049 0441 [13] CCAB      	CALL	_Delay
1050                     	.CHKPARA _Delay 2
1051 0442 [00] 0011      _00147_DS_:
1052                     ;	;.line	336; ".\ADC_LCD.c"	if(adS.unit_setMode ==1){
1053 0443 [12] B36A      	BTSS	_adS,1
1054 0444 [12] 7D73      	JMP	_00173_DS_
1055                     ;	;.line	338; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
1056 0445 [12] 836A      	BCF	_adS,1
1057                     ;	;.line	339; ".\ADC_LCD.c"	adS.testMode = 0;
1058 0446 [12] 816D      	BCF	(_adS+3),0
1059                     ;	;.line	343; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,0x02);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
1060 0447 [12] C502      	MVL	0x02
1061                     	MVF	_HY17P52WR3_STK01,1,0
1062 0448 [13] C5AA      	MVL	0xaa
1063                     	MVF	_HY17P52WR3_STK00,1,0
1064 0449 [14] 0600      	MVL	0x00
1065 044A [14] CCCB 0011 	CALL	_HY17P52WR3
1066                     	.CHKPARA _HY17P52WR3 3
1067                     ;	;.line	344; ".\ADC_LCD.c"	if(Flag== 1)
1068 044C [12] 3564      	DCSZ	_Flag,0,0
1069 044D [12] 7805      	JMP	_00152_DS_
1070                     ;	;.line	346; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
1071 044E [12] 06BF      	MVL	0xbf
1072 044F [12] 2847      	ANDF	_PT1,0,0
1073 0450 [12] 0240      	IORL	0x40
1074 0451 [12] 6647      	MVF	_PT1,1,0
1075                     _00149_DS_:
1076                     ;	;.line	347; ".\ADC_LCD.c"	while(1);    //fail
1077 0452 [12] 7FFF      	JMP	_00149_DS_
1078                     _00152_DS_:
1079                     ;	;.line	351; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
1080 0453 [12] 0C30      	CLRF	_BIEARL,0
1081                     ;	;.line	352; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1082 0454 [12] 902E      	BSF	_BIECN,0
1083                     _00153_DS_:
1084                     ;	;.line	353; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1085 0455 [12] 642E      	MVF	_BIECN,0,0
1086 0456 [12] 0101      	ANDL	0x01
1087 0457 [12] 668B      	MVF	r0x1140,1,0
1088 0458 [12] 308B      	DCF	r0x1140,0,0
1089 0459 [12] 4C29      	RRF	_WREG,0,0
1090 045A [12] A02B      	BTSZ	_STATUS,0
1091 045B [12] 7FF9      	JMP	_00153_DS_
1092                     ;	;.line	354; ".\ADC_LCD.c"	delta=BIEDRL;
1093 045C [12] 6432      	MVF	_BIEDRL,0,0
1094 045D [12] 668B      	MVF	r0x1140,1,0
1095                     ;	;.line	356; ".\ADC_LCD.c"	if(delta==0)  LCD_WriteData(&LCD4, seg_bar) ; 
1096 045E [12] 0200      	IORL	0x00
1097 045F [12] 6E29      	TFSZ	_WREG,0
1098 0460 [12] 7803      	JMP	_00165_DS_
1099 0461 [12] 0602      	MVL	0x02
1100 0462 [12] 6663      	MVF	_LCD4,1,0
1101 0463 [12] 7D54      	JMP	_00173_DS_
1102                     _00165_DS_:
1103                     ;	;.line	357; ".\ADC_LCD.c"	else if(delta==1)LCD_WriteData(&LCD4, seg_kgf) ; 
1104 0464 [12] 308B      	DCF	r0x1140,0,0
1105 0465 [12] 6E29      	TFSZ	_WREG,0
1106 0466 [12] 7803      	JMP	_00162_DS_
1107 0467 [12] 0601      	MVL	0x01
1108 0468 [12] 6663      	MVF	_LCD4,1,0
1109 0469 [12] 7D4E      	JMP	_00173_DS_
1110                     _00162_DS_:
1111                     ;	;.line	358; ".\ADC_LCD.c"	else if(delta==2)LCD_WriteData(&LCD4, seg_mpa) ; 
1112 046A [12] 648B      	MVF	r0x1140,0,0
1113 046B [12] 0302      	XORL	0x02
1114 046C [12] 6E29      	TFSZ	_WREG,0
1115 046D [12] 7803      	JMP	_00159_DS_
1116 046E [12] 0608      	MVL	0x08
1117 046F [12] 6663      	MVF	_LCD4,1,0
1118 0470 [12] 7D47      	JMP	_00173_DS_
1119                     _00159_DS_:
1120                     ;	;.line	359; ".\ADC_LCD.c"	else if(delta==3)LCD_WriteData(&LCD4, seg_psi) ; 
1121 0471 [12] 648B      	MVF	r0x1140,0,0
1122 0472 [12] 0303      	XORL	0x03
1123 0473 [12] 6E29      	TFSZ	_WREG,0
1124 0474 [12] 7D43      	JMP	_00173_DS_
1125 0475 [12] 0604      	MVL	0x04
1126 0476 [12] 6663      	MVF	_LCD4,1,0
1127                     ;	;.line	370; ".\ADC_LCD.c"	}
1128 0477 [12] 7D40      	JMP	_00173_DS_
1129                     	.ENDFUNC	_main
1130                     ;--------------------------------------------------------
1131                     
1132                     .globl _SetupUnitAndZeroPoint_Mode
1133                     
1134                     ;--------------------------------------------------------
1135                     	.FUNC _SetupUnitAndZeroPoint_Mode:0:$C:_DisplayUnit:$C:_Delay\
1136                     :$L:r0x11C1
1137                     ;--------------------------------------------------------
1138                     ;	;.line	815; ".\ADC_LCD.c"	adS.unit_setMode =1;
1139                     _SetupUnitAndZeroPoint_Mode:	;Function start
1140                     	BSF	_adS,1
1141                     ;	;.line	816; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
1142                     	BCF	(_adS+3),1
1143                     ;	;.line	817; ".\ADC_LCD.c"	adS.testMode =1;
1144                     	BSF	(_adS+3),0
1145                     ;	;.line	818; ".\ADC_LCD.c"	DisplayUnit();
1146                     	CALL	_DisplayUnit
1147                     	.CHKPARA _DisplayUnit 0
1148                     ;	;.line	822; ".\ADC_LCD.c"	switch(adS.unitChoose){
1149                     	MVF	(_adS + 2),0,0
1150                     	MVF	r0x11C1,1,0
1151                     	MVL	0x04
1152                     	CPSL	r0x11C1,0
1153                     	JMP	_00708_DS_
1154                     	MVL	HIGHD2(_00714_DS_)
1155                     	MVF	_PCLATH,1,0
1156                     	MVL	D2(_00714_DS_)
1157                     	ADDF	r0x11C1,0,0
1158                     	BTSZ	_STATUS,4
1159                     	INF	_PCLATH,1,0
1160                     	MVF	_PCLATL,1,0
1161                     _00714_DS_:
1162                     	RJ	_00703_DS_
1163                     	RJ	_00704_DS_
1164                     	RJ	_00705_DS_
1165                     	RJ	_00706_DS_
1166                     _00703_DS_:
1167                     ;	;.line	824; ".\ADC_LCD.c"	adS.unitChoose++;
1168                     	INF	r0x11C1,0,0
1169                     	MVF	(_adS + 2),1,0
1170                     ;	;.line	825; ".\ADC_LCD.c"	adS.unitChoose = psi;
1171                     	CLRF	(_adS + 2),0
1172                     ;	;.line	828; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
1173                     	MVL	0xdf
1174                     	ANDF	_PT1,0,0
1175                     	IORL	0x20
1176                     	MVF	_PT1,1,0
1177                     ;	;.line	829; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
1178                     	MVL	0x04
1179                     	MVF	_LCD4,1,0
1180                     ;	;.line	830; ".\ADC_LCD.c"	Delay(20000);  
1181                     	MVL	0x20
1182                     	MVF	_Delay_STK00,1,0
1183                     	MVL	0x4e
1184                     	CALL	_Delay
1185                     	.CHKPARA _Delay 2
1186                     ;	;.line	831; ".\ADC_LCD.c"	Delay(10000);
1187                     	MVL	0x10
1188                     	MVF	_Delay_STK00,1,0
1189                     	MVL	0x27
1190                     	CALL	_Delay
1191                     	.CHKPARA _Delay 2
1192                     ;	;.line	832; ".\ADC_LCD.c"	break;
1193                     	JMP	_00708_DS_
1194                     _00704_DS_:
1195                     ;	;.line	834; ".\ADC_LCD.c"	adS.unitChoose++;
1196                     	INF	r0x11C1,0,0
1197                     	MVF	(_adS + 2),1,0
1198                     ;	;.line	835; ".\ADC_LCD.c"	adS.unitChoose = bar;
1199                     	MVL	0x01
1200                     	MVF	(_adS + 2),1,0
1201                     ;	;.line	836; ".\ADC_LCD.c"	GPIO_PT15_LOW();
1202                     	BCF	_PT1,5
1203                     ;	;.line	838; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
1204                     	MVL	0x02
1205                     	MVF	_LCD4,1,0
1206                     ;	;.line	839; ".\ADC_LCD.c"	Delay(20000); 
1207                     	MVL	0x20
1208                     	MVF	_Delay_STK00,1,0
1209                     	MVL	0x4e
1210                     	CALL	_Delay
1211                     	.CHKPARA _Delay 2
1212                     ;	;.line	840; ".\ADC_LCD.c"	Delay(10000);
1213                     	MVL	0x10
1214                     	MVF	_Delay_STK00,1,0
1215                     	MVL	0x27
1216                     	CALL	_Delay
1217                     	.CHKPARA _Delay 2
1218                     ;	;.line	841; ".\ADC_LCD.c"	break;
1219                     	JMP	_00708_DS_
1220                     _00705_DS_:
1221                     ;	;.line	843; ".\ADC_LCD.c"	adS.unitChoose++;
1222                     	INF	r0x11C1,1,0
1223                     	MVF	r0x11C1,0,0
1224                     	MVF	(_adS + 2),1,0
1225                     ;	;.line	844; ".\ADC_LCD.c"	adS.unitChoose = kgf;
1226                     	MVL	0x02
1227                     	MVF	(_adS + 2),1,0
1228                     ;	;.line	845; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
1229                     	MVL	0xdf
1230                     	ANDF	_PT1,0,0
1231                     	IORL	0x20
1232                     	MVF	_PT1,1,0
1233                     ;	;.line	847; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
1234                     	MVL	0x01
1235                     	MVF	_LCD4,1,0
1236                     ;	;.line	848; ".\ADC_LCD.c"	Delay(20000);
1237                     	MVL	0x20
1238                     	MVF	_Delay_STK00,1,0
1239                     	MVL	0x4e
1240                     	CALL	_Delay
1241                     	.CHKPARA _Delay 2
1242                     ;	;.line	849; ".\ADC_LCD.c"	Delay(10000);  
1243                     	MVL	0x10
1244                     	MVF	_Delay_STK00,1,0
1245                     	MVL	0x27
1246                     	CALL	_Delay
1247                     	.CHKPARA _Delay 2
1248                     ;	;.line	851; ".\ADC_LCD.c"	break;
1249                     	JMP	_00708_DS_
1250                     _00706_DS_:
1251                     ;	;.line	853; ".\ADC_LCD.c"	adS.unitChoose=0;
1252                     	CLRF	(_adS + 2),0
1253                     ;	;.line	854; ".\ADC_LCD.c"	adS.unitChoose = mpa;
1254                     	MVL	0x03
1255                     	MVF	(_adS + 2),1,0
1256                     ;	;.line	855; ".\ADC_LCD.c"	GPIO_PT15_LOW();
1257                     	BCF	_PT1,5
1258                     ;	;.line	857; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
1259                     	MVL	0x08
1260                     	MVF	_LCD4,1,0
1261                     ;	;.line	859; ".\ADC_LCD.c"	Delay(20000);
1262                     	MVL	0x20
1263                     	MVF	_Delay_STK00,1,0
1264                     	MVL	0x4e
1265                     	CALL	_Delay
1266                     	.CHKPARA _Delay 2
1267                     ;	;.line	860; ".\ADC_LCD.c"	Delay(10000);  
1268                     	MVL	0x10
1269                     	MVF	_Delay_STK00,1,0
1270                     	MVL	0x27
1271                     	CALL	_Delay
1272                     	.CHKPARA _Delay 2
1273                     _00708_DS_:
1274                     ;	;.line	863; ".\ADC_LCD.c"	}
1275                     	RET	
1276                     ; exit point of _SetupUnitAndZeroPoint_Mode
1277                     	.ENDFUNC	_SetupUnitAndZeroPoint_Mode
1278                     ;--------------------------------------------------------
1279                     
1280                     .globl _NegativePressureWorks_Mode
1281                     
1282                     ;--------------------------------------------------------
1283                     	.FUNC _NegativePressureWorks_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fssub:$C:___fs2slong\
1284                     :$C:_Reverse_Data:$C:_UnitConverter:$C:_DisplayNum:$C:_LowVoltageDisplay:$C:_Delay\
1285                     :$C:___fsadd\
1286                     :$L:r0x11AF:$L:r0x11B0:$L:r0x11B1:$L:r0x11B2:$L:r0x11B3\
1287                     :$L:r0x11B4:$L:r0x11B5:$L:r0x11B6:$L:r0x11B7:$L:r0x11B8\
1288                     :$L:r0x11B9:$L:r0x11BA:$L:r0x11BC:$L:r0x11BB:$L:r0x11BE\
1289                     :$L:r0x11C0:$L:r0x11BF
1290                     ;--------------------------------------------------------
1291                     ;	;.line	732; ".\ADC_LCD.c"	adS.Pressure_sign =1;
1292                     _NegativePressureWorks_Mode:	;Function start
1293                     	BSF	(_adS+6),6
1294                     ;	;.line	734; ".\ADC_LCD.c"	BIEARL=3;                                //addr=1
1295                     	MVL	0x03
1296                     	MVF	_BIEARL,1,0
1297                     ;	;.line	735; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1298                     	BSF	_BIECN,0
1299                     _00624_DS_:
1300                     ;	;.line	736; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1301                     	MVF	_BIECN,0,0
1302                     	ANDL	0x01
1303                     	MVF	r0x11B3,1,0
1304                     	DCF	r0x11B3,0,0
1305                     	BTSZ	_STATUS,0
1306                     	JMP	_00624_DS_
1307                     ;	;.line	737; ".\ADC_LCD.c"	adS.eepromRead_NegativeDeltaLow_bit1=BIEDRL;
1308                     	MVF	_BIEDRL,0,0
1309                     	MVF	(_adS + 9),1,0
1310                     ;	;.line	740; ".\ADC_LCD.c"	BIEARL=4;                                //addr=1
1311                     	MVL	0x04
1312                     	MVF	_BIEARL,1,0
1313                     ;	;.line	741; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1314                     	BSF	_BIECN,0
1315                     _00627_DS_:
1316                     ;	;.line	742; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1317                     	MVF	_BIECN,0,0
1318                     	ANDL	0x01
1319                     	MVF	r0x11B3,1,0
1320                     	DCF	r0x11B3,0,0
1321                     	BTSZ	_STATUS,0
1322                     	JMP	_00627_DS_
1323                     ;	;.line	743; ".\ADC_LCD.c"	adS.eepromRead_NegativeDeltaLow_bit2=BIEDRL;
1324                     	MVF	_BIEDRL,0,0
1325                     	MVF	(_adS + 10),1,0
1326                     ;	;.line	745; ".\ADC_LCD.c"	if(adS.eepromRead_NegativeDeltaLow_bit1 ==0 ){
1327                     	TFSZ	(_adS + 9),0
1328                     	JMP	_00631_DS_
1329                     ;	;.line	747; ".\ADC_LCD.c"	theta =abs(ADC) + adS.eepromRead_NegativeDeltaLow_bit2 ;
1330                     	DCF	_ADC,0,0
1331                     	MVL	0xff
1332                     	ADDC	(_ADC + 1),0,0
1333                     	MVL	0xff
1334                     	ADDC	(_ADC + 2),0,0
1335                     	MVL	0x7f
1336                     	ADDC	(_ADC + 3),0,0
1337                     	BTSS	_STATUS,1
1338                     	JMP	_00641_DS_
1339                     	MVF	_ADC,0,0
1340                     	MVF	r0x11B3,1,0
1341                     	MVF	(_ADC + 1),0,0
1342                     	MVF	r0x11B4,1,0
1343                     	MVF	(_ADC + 2),0,0
1344                     	MVF	r0x11B5,1,0
1345                     	MVF	(_ADC + 3),0,0
1346                     	MVF	r0x11B6,1,0
1347                     	JMP	_00642_DS_
1348                     _00641_DS_:
1349                     	COMF	_ADC,0,0
1350                     	MVF	r0x11B3,1,0
1351                     	COMF	(_ADC + 1),0,0
1352                     	MVF	r0x11B4,1,0
1353                     	COMF	(_ADC + 2),0,0
1354                     	MVF	r0x11B5,1,0
1355                     	COMF	(_ADC + 3),0,0
1356                     	MVF	r0x11B6,1,0
1357                     	INF	r0x11B3,1,0
1358                     	MVL	0x00
1359                     	ADDC	r0x11B4,1,0
1360                     	ADDC	r0x11B5,1,0
1361                     	ADDC	r0x11B6,1,0
1362                     _00642_DS_:
1363                     	CLRF	r0x11BA,0
1364                     	MVL	0x00
1365                     	BTSZ	r0x11BA,7
1366                     	MVL	0xff
1367                     	MVF	r0x11BC,1,0
1368                     	MVF	r0x11BB,1,0
1369                     	MVF	(_adS + 10),0,0
1370                     	ADDF	r0x11B3,1,0
1371                     	MVF	r0x11BA,0,0
1372                     	ADDC	r0x11B4,1,0
1373                     	MVF	r0x11BB,0,0
1374                     	ADDC	r0x11B5,1,0
1375                     	MVF	r0x11BC,0,0
1376                     	ADDC	r0x11B6,1,0
1377                     	JMP	_00632_DS_
1378                     _00631_DS_:
1379                     ;	;.line	751; ".\ADC_LCD.c"	theta =abs(ADC) - adS.eepromRead_NegativeDeltaLow_bit1 ;
1380                     	DCF	_ADC,0,0
1381                     	MVL	0xff
1382                     	ADDC	(_ADC + 1),0,0
1383                     	MVL	0xff
1384                     	ADDC	(_ADC + 2),0,0
1385                     	MVL	0x7f
1386                     	ADDC	(_ADC + 3),0,0
1387                     	BTSS	_STATUS,1
1388                     	JMP	_00643_DS_
1389                     	MVF	_ADC,0,0
1390                     	MVF	r0x11B7,1,0
1391                     	MVF	(_ADC + 1),0,0
1392                     	MVF	r0x11B8,1,0
1393                     	MVF	(_ADC + 2),0,0
1394                     	MVF	r0x11B9,1,0
1395                     	MVF	(_ADC + 3),0,0
1396                     	MVF	r0x11BA,1,0
1397                     	JMP	_00644_DS_
1398                     _00643_DS_:
1399                     	COMF	_ADC,0,0
1400                     	MVF	r0x11B7,1,0
1401                     	COMF	(_ADC + 1),0,0
1402                     	MVF	r0x11B8,1,0
1403                     	COMF	(_ADC + 2),0,0
1404                     	MVF	r0x11B9,1,0
1405                     	COMF	(_ADC + 3),0,0
1406                     	MVF	r0x11BA,1,0
1407                     	INF	r0x11B7,1,0
1408                     	MVL	0x00
1409                     	ADDC	r0x11B8,1,0
1410                     	ADDC	r0x11B9,1,0
1411                     	ADDC	r0x11BA,1,0
1412                     _00644_DS_:
1413                     	CLRF	r0x11BE,0
1414                     	MVL	0x00
1415                     	BTSZ	r0x11BE,7
1416                     	MVL	0xff
1417                     	MVF	r0x11C0,1,0
1418                     	MVF	r0x11BF,1,0
1419                     	MVF	(_adS + 9),0,0
1420                     	SUBF	r0x11B7,0,0
1421                     	MVF	r0x11B3,1,0
1422                     	MVF	r0x11BE,0,0
1423                     	SUBC	r0x11B8,0,0
1424                     	MVF	r0x11B4,1,0
1425                     	MVF	r0x11BF,0,0
1426                     	SUBC	r0x11B9,0,0
1427                     	MVF	r0x11B5,1,0
1428                     	MVF	r0x11C0,0,0
1429                     	SUBC	r0x11BA,0,0
1430                     	MVF	r0x11B6,1,0
1431                     _00632_DS_:
1432                     ;	;.line	755; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
1433                     	BTSS	(_adS+6),4
1434                     	JMP	_00637_DS_
1435                     ;	;.line	758; ".\ADC_LCD.c"	if( omega >=0 ){
1436                     	BTSZ	(_ADC + 3),7
1437                     	JMP	_00634_DS_
1438                     ;	;.line	759; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
1439                     	MVF	r0x11B3,0,0
1440                     	MVF	___slong2fs_STK02,1,0
1441                     	MVF	r0x11B4,0,0
1442                     	MVF	___slong2fs_STK01,1,0
1443                     	MVF	r0x11B5,0,0
1444                     	MVF	___slong2fs_STK00,1,0
1445                     	MVF	r0x11B6,0,0
1446                     	CALL	___slong2fs
1447                     	.CHKPARA ___slong2fs 4
1448                     	MVF	r0x11B2,1,0
1449                     	MVF	STK02,0,0
1450                     	MVF	___fsmul_STK06,1,0
1451                     	MVF	STK01,0,0
1452                     	MVF	___fsmul_STK05,1,0
1453                     	MVF	STK00,0,0
1454                     	MVF	___fsmul_STK04,1,0
1455                     	MVF	r0x11B2,0,0
1456                     	MVF	___fsmul_STK03,1,0
1457                     	MVL	0x25
1458                     	MVF	___fsmul_STK02,1,0
1459                     	MVL	0x06
1460                     	MVF	___fsmul_STK01,1,0
1461                     	MVL	0x01
1462                     	MVF	___fsmul_STK00,1,0
1463                     	MVL	0x3e
1464                     	CALL	___fsmul
1465                     	.CHKPARA ___fsmul 8
1466                     	MVF	r0x11B2,1,0
1467                     	MVF	STK02,0,0
1468                     	MVF	___fssub_STK06,1,0
1469                     	MVF	STK01,0,0
1470                     	MVF	___fssub_STK05,1,0
1471                     	MVF	STK00,0,0
1472                     	MVF	___fssub_STK04,1,0
1473                     	MVF	r0x11B2,0,0
1474                     	MVF	___fssub_STK03,1,0
1475                     	CLRF	___fssub_STK02,0
1476                     	CLRF	___fssub_STK01,0
1477                     	MVL	0x48
1478                     	MVF	___fssub_STK00,1,0
1479                     	MVL	0x43
1480                     	CALL	___fssub
1481                     	.CHKPARA ___fssub 8
1482                     	MVF	r0x11B2,1,0
1483                     	MVF	STK02,0,0
1484                     	MVF	___fs2slong_STK02,1,0
1485                     	MVF	STK01,0,0
1486                     	MVF	___fs2slong_STK01,1,0
1487                     	MVF	STK00,0,0
1488                     	MVF	___fs2slong_STK00,1,0
1489                     	MVF	r0x11B2,0,0
1490                     	CALL	___fs2slong
1491                     	.CHKPARA ___fs2slong 4
1492                     	MVF	r0x11B2,1,0
1493                     	MVF	STK02,0,0
1494                     ;	;.line	760; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
1495                     	MVF	_Reverse_Data_STK02,1,0
1496                     	MVF	STK01,0,0
1497                     	MVF	_Reverse_Data_STK01,1,0
1498                     	MVF	STK00,0,0
1499                     	MVF	_Reverse_Data_STK00,1,0
1500                     	MVF	r0x11B2,0,0
1501                     	CALL	_Reverse_Data
1502                     	.CHKPARA _Reverse_Data 4
1503                     	MVF	r0x11B2,1,0
1504                     	MVF	STK02,0,0
1505                     ;	;.line	761; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
1506                     	MVF	_UnitConverter_STK02,1,0
1507                     	MVF	STK01,0,0
1508                     	MVF	_UnitConverter_STK01,1,0
1509                     	MVF	STK00,0,0
1510                     	MVF	_UnitConverter_STK00,1,0
1511                     	MVF	r0x11B2,0,0
1512                     	CALL	_UnitConverter
1513                     	MVF	r0x11B2,1,0
1514                     	MVF	STK02,0,0
1515                     ;	;.line	762; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
1516                     	MVF	_DisplayNum_STK02,1,0
1517                     	MVF	STK01,0,0
1518                     	MVF	_DisplayNum_STK01,1,0
1519                     	MVF	STK00,0,0
1520                     	MVF	_DisplayNum_STK00,1,0
1521                     	MVF	r0x11B2,0,0
1522                     	CALL	_DisplayNum
1523                     	.CHKPARA _DisplayNum 4
1524                     ;	;.line	763; ".\ADC_LCD.c"	LowVoltageDisplay();
1525                     	CALL	_LowVoltageDisplay
1526                     ;	;.line	765; ".\ADC_LCD.c"	Delay(20000);
1527                     	MVL	0x20
1528                     	MVF	_Delay_STK00,1,0
1529                     	MVL	0x4e
1530                     	CALL	_Delay
1531                     	.CHKPARA _Delay 2
1532                     	JMP	_00639_DS_
1533                     _00634_DS_:
1534                     ;	;.line	776; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
1535                     	MVF	r0x11B3,0,0
1536                     	MVF	___slong2fs_STK02,1,0
1537                     	MVF	r0x11B4,0,0
1538                     	MVF	___slong2fs_STK01,1,0
1539                     	MVF	r0x11B5,0,0
1540                     	MVF	___slong2fs_STK00,1,0
1541                     	MVF	r0x11B6,0,0
1542                     	CALL	___slong2fs
1543                     	.CHKPARA ___slong2fs 4
1544                     	MVF	r0x11B2,1,0
1545                     	MVF	STK02,0,0
1546                     	MVF	___fsmul_STK06,1,0
1547                     	MVF	STK01,0,0
1548                     	MVF	___fsmul_STK05,1,0
1549                     	MVF	STK00,0,0
1550                     	MVF	___fsmul_STK04,1,0
1551                     	MVF	r0x11B2,0,0
1552                     	MVF	___fsmul_STK03,1,0
1553                     	CLRF	___fsmul_STK02,0
1554                     	CLRF	___fsmul_STK01,0
1555                     	CLRF	___fsmul_STK00,0
1556                     	MVL	0x3e
1557                     	CALL	___fsmul
1558                     	.CHKPARA ___fsmul 8
1559                     	MVF	r0x11B2,1,0
1560                     	CLRF	___fsadd_STK06,0
1561                     	CLRF	___fsadd_STK05,0
1562                     	MVL	0x4c
1563                     	MVF	___fsadd_STK04,1,0
1564                     	MVL	0x43
1565                     	MVF	___fsadd_STK03,1,0
1566                     	MVF	STK02,0,0
1567                     	MVF	___fsadd_STK02,1,0
1568                     	MVF	STK01,0,0
1569                     	MVF	___fsadd_STK01,1,0
1570                     	MVF	STK00,0,0
1571                     	MVF	___fsadd_STK00,1,0
1572                     	MVF	r0x11B2,0,0
1573                     	CALL	___fsadd
1574                     	.CHKPARA ___fsadd 8
1575                     	MVF	r0x11B2,1,0
1576                     	MVF	STK02,0,0
1577                     	MVF	___fs2slong_STK02,1,0
1578                     	MVF	STK01,0,0
1579                     	MVF	___fs2slong_STK01,1,0
1580                     	MVF	STK00,0,0
1581                     	MVF	___fs2slong_STK00,1,0
1582                     	MVF	r0x11B2,0,0
1583                     	CALL	___fs2slong
1584                     	.CHKPARA ___fs2slong 4
1585                     	MVF	r0x11B2,1,0
1586                     	MVF	STK02,0,0
1587                     ;	;.line	777; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
1588                     	MVF	_Reverse_Data_STK02,1,0
1589                     	MVF	STK01,0,0
1590                     	MVF	_Reverse_Data_STK01,1,0
1591                     	MVF	STK00,0,0
1592                     	MVF	_Reverse_Data_STK00,1,0
1593                     	MVF	r0x11B2,0,0
1594                     	CALL	_Reverse_Data
1595                     	.CHKPARA _Reverse_Data 4
1596                     	MVF	r0x11B2,1,0
1597                     	MVF	STK02,0,0
1598                     ;	;.line	778; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
1599                     	MVF	_UnitConverter_STK02,1,0
1600                     	MVF	STK01,0,0
1601                     	MVF	_UnitConverter_STK01,1,0
1602                     	MVF	STK00,0,0
1603                     	MVF	_UnitConverter_STK00,1,0
1604                     	MVF	r0x11B2,0,0
1605                     	CALL	_UnitConverter
1606                     	MVF	r0x11B2,1,0
1607                     	MVF	STK02,0,0
1608                     ;	;.line	779; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
1609                     	MVF	_DisplayNum_STK02,1,0
1610                     	MVF	STK01,0,0
1611                     	MVF	_DisplayNum_STK01,1,0
1612                     	MVF	STK00,0,0
1613                     	MVF	_DisplayNum_STK00,1,0
1614                     	MVF	r0x11B2,0,0
1615                     	CALL	_DisplayNum
1616                     	.CHKPARA _DisplayNum 4
1617                     ;	;.line	780; ".\ADC_LCD.c"	LowVoltageDisplay();
1618                     	CALL	_LowVoltageDisplay
1619                     ;	;.line	782; ".\ADC_LCD.c"	Delay(20000);
1620                     	MVL	0x20
1621                     	MVF	_Delay_STK00,1,0
1622                     	MVL	0x4e
1623                     	CALL	_Delay
1624                     	.CHKPARA _Delay 2
1625                     	JMP	_00639_DS_
1626                     _00637_DS_:
1627                     ;	;.line	788; ".\ADC_LCD.c"	ADC = abs(ADC);
1628                     	DCF	_ADC,0,0
1629                     	MVL	0xff
1630                     	ADDC	(_ADC + 1),0,0
1631                     	MVL	0xff
1632                     	ADDC	(_ADC + 2),0,0
1633                     	MVL	0x7f
1634                     	ADDC	(_ADC + 3),0,0
1635                     	BTSS	_STATUS,1
1636                     	JMP	_00645_DS_
1637                     	MVF	_ADC,0,0
1638                     	MVF	r0x11AF,1,0
1639                     	MVF	(_ADC + 1),0,0
1640                     	MVF	r0x11B0,1,0
1641                     	MVF	(_ADC + 2),0,0
1642                     	MVF	r0x11B1,1,0
1643                     	MVF	(_ADC + 3),0,0
1644                     	MVF	r0x11B2,1,0
1645                     	JMP	_00646_DS_
1646                     _00645_DS_:
1647                     	COMF	_ADC,0,0
1648                     	MVF	r0x11AF,1,0
1649                     	COMF	(_ADC + 1),0,0
1650                     	MVF	r0x11B0,1,0
1651                     	COMF	(_ADC + 2),0,0
1652                     	MVF	r0x11B1,1,0
1653                     	COMF	(_ADC + 3),0,0
1654                     	MVF	r0x11B2,1,0
1655                     	INF	r0x11AF,1,0
1656                     	MVL	0x00
1657                     	ADDC	r0x11B0,1,0
1658                     	ADDC	r0x11B1,1,0
1659                     	ADDC	r0x11B2,1,0
1660                     _00646_DS_:
1661                     	MVF	r0x11AF,0,0
1662                     	MVF	_ADC,1,0
1663                     	MVF	r0x11B0,0,0
1664                     	MVF	(_ADC + 1),1,0
1665                     	MVF	r0x11B1,0,0
1666                     	MVF	(_ADC + 2),1,0
1667                     	MVF	r0x11B2,0,0
1668                     	MVF	(_ADC + 3),1,0
1669                     ;	;.line	789; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
1670                     	MVF	_ADC,0,0
1671                     	MVF	_Reverse_Data_STK02,1,0
1672                     	MVF	(_ADC + 1),0,0
1673                     	MVF	_Reverse_Data_STK01,1,0
1674                     	MVF	(_ADC + 2),0,0
1675                     	MVF	_Reverse_Data_STK00,1,0
1676                     	MVF	(_ADC + 3),0,0
1677                     	CALL	_Reverse_Data
1678                     	.CHKPARA _Reverse_Data 4
1679                     	MVF	(_ADC + 3),1,0
1680                     	MVF	STK00,0,0
1681                     	MVF	(_ADC + 2),1,0
1682                     	MVF	STK01,0,0
1683                     	MVF	(_ADC + 1),1,0
1684                     	MVF	STK02,0,0
1685                     	MVF	_ADC,1,0
1686                     ;	;.line	790; ".\ADC_LCD.c"	DisplayNum(ADC);
1687                     	MVF	_DisplayNum_STK02,1,0
1688                     	MVF	(_ADC + 1),0,0
1689                     	MVF	_DisplayNum_STK01,1,0
1690                     	MVF	(_ADC + 2),0,0
1691                     	MVF	_DisplayNum_STK00,1,0
1692                     	MVF	(_ADC + 3),0,0
1693                     	CALL	_DisplayNum
1694                     	.CHKPARA _DisplayNum 4
1695                     ;	;.line	791; ".\ADC_LCD.c"	LowVoltageDisplay();
1696                     	CALL	_LowVoltageDisplay
1697                     ;	;.line	793; ".\ADC_LCD.c"	Delay(20000);
1698                     	MVL	0x20
1699                     	MVF	_Delay_STK00,1,0
1700                     	MVL	0x4e
1701                     	CALL	_Delay
1702                     	.CHKPARA _Delay 2
1703                     _00639_DS_:
1704                     ;	;.line	798; ".\ADC_LCD.c"	}
1705                     	RET	
1706                     ; exit point of _NegativePressureWorks_Mode
1707                     	.ENDFUNC	_NegativePressureWorks_Mode
1708                     ;--------------------------------------------------------
1709                     
1710                     .globl _PositivePressureWorks_Mode
1711                     
1712                     ;--------------------------------------------------------
1713                     	.FUNC _PositivePressureWorks_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fssub:$C:___fs2slong\
1714                     :$C:_DisplayNum:$C:__mullong:$C:_Reverse_Data:$C:_UnitConverter:$C:_LowVoltageDisplay\
1715                     :$C:_Delay\
1716                     :$L:r0x1197:$L:r0x1198:$L:r0x1199:$L:r0x119A:$L:r0x119B\
1717                     :$L:r0x119C:$L:r0x119D:$L:r0x119E:$L:r0x11A0:$L:r0x119F\
1718                     :$L:r0x11A2:$L:r0x11A4:$L:r0x11A3
1719                     ;--------------------------------------------------------
1720                     ;	;.line	657; ".\ADC_LCD.c"	BIEARL=1;                                //addr=1
1721 0517 [00] C48D      _PositivePressureWorks_Mode:	;Function start
1722 0518 [13] 0601      	MVL	0x01
1723 0519 [13] 6630      	MVF	_BIEARL,1,0
1724                     ;	;.line	658; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1725 051A [13] 902E      	BSF	_BIECN,0
1726                     _00544_DS_:
1727                     ;	;.line	659; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1728 051B [13] 642E      	MVF	_BIECN,0,0
1729 051C [13] 0101      	ANDL	0x01
1730 051D [13] 668C      	MVF	r0x1197,1,0
1731 051E [13] 308C      	DCF	r0x1197,0,0
1732 051F [13] A02B      	BTSZ	_STATUS,0
1733 0520 [13] 7FFA      	JMP	_00544_DS_
1734                     ;	;.line	660; ".\ADC_LCD.c"	adS.eepromRead_PositiveDeltaLow_bit1=BIEDRL;
1735 0521 [13] D032      	MVF	_BIEDRL,0,0
1736 0522 [13] F171      	MVF	(_adS + 7),1,0
1737                     ;	;.line	663; ".\ADC_LCD.c"	BIEARL=2;                                //addr=1
1738 0523 [13] 0602      	MVL	0x02
1739 0524 [13] 6630      	MVF	_BIEARL,1,0
1740                     ;	;.line	664; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1741 0525 [13] 902E      	BSF	_BIECN,0
1742                     _00547_DS_:
1743                     ;	;.line	665; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1744 0526 [13] 642E      	MVF	_BIECN,0,0
1745 0527 [13] 0101      	ANDL	0x01
1746 0528 [13] 668C      	MVF	r0x1197,1,0
1747 0529 [13] 308C      	DCF	r0x1197,0,0
1748 052A [13] A02B      	BTSZ	_STATUS,0
1749 052B [13] 7FFA      	JMP	_00547_DS_
1750                     ;	;.line	666; ".\ADC_LCD.c"	adS.eepromRead_PositiveDeltaLow_bit2=BIEDRL;
1751 052C [13] 6432      	MVF	_BIEDRL,0,0
1752 052D [13] 6772      	MVF	(_adS + 8),1,0
1753                     ;	;.line	668; ".\ADC_LCD.c"	if(adS.eepromRead_PositiveDeltaLow_bit1 ==0 ){
1754 052E [13] 6F71      	TFSZ	(_adS + 7),0
1755 052F [13] 782F      	JMP	_00551_DS_
1756                     ;	;.line	670; ".\ADC_LCD.c"	delta =abs(ADC) + adS.eepromRead_PositiveDeltaLow_bit2 ;
1757 0530 [13] 3165      	DCF	_ADC,0,0
1758 0531 [13] 06FF      	MVL	0xff
1759 0532 [13] 1566      	ADDC	(_ADC + 1),0,0
1760 0533 [13] 06FF      	MVL	0xff
1761 0534 [13] 1567      	ADDC	(_ADC + 2),0,0
1762 0535 [13] 067F      	MVL	0x7f
1763 0536 [13] 1568      	ADDC	(_ADC + 3),0,0
1764 0537 [13] B22B      	BTSS	_STATUS,1
1765 0538 [13] 7809      	JMP	_00564_DS_
1766 0539 [13] 6565      	MVF	_ADC,0,0
1767 053A [13] 668C      	MVF	r0x1197,1,0
1768 053B [13] 6566      	MVF	(_ADC + 1),0,0
1769 053C [13] 668B      	MVF	r0x1198,1,0
1770 053D [13] 6567      	MVF	(_ADC + 2),0,0
1771 053E [13] 668A      	MVF	r0x1199,1,0
1772 053F [13] 6568      	MVF	(_ADC + 3),0,0
1773 0540 [13] 6689      	MVF	r0x119A,1,0
1774 0541 [13] 780E      	JMP	_00565_DS_
1775 0542 [00] 0011      _00564_DS_:
1776 0543 [13] 2565      	COMF	_ADC,0,0
1777 0544 [13] 668C      	MVF	r0x1197,1,0
1778 0545 [13] 2566      	COMF	(_ADC + 1),0,0
1779 0546 [13] 668B      	MVF	r0x1198,1,0
1780 0547 [13] 2567      	COMF	(_ADC + 2),0,0
1781 0548 [13] 668A      	MVF	r0x1199,1,0
1782 0549 [13] 2568      	COMF	(_ADC + 3),0,0
1783 054A [13] 6689      	MVF	r0x119A,1,0
1784 054B [13] 3A8C      	INF	r0x1197,1,0
1785 054C [13] 0600      	MVL	0x00
1786 054D [13] 168B      	ADDC	r0x1198,1,0
1787 054E [13] 168A      	ADDC	r0x1199,1,0
1788 054F [13] 1689      	ADDC	r0x119A,1,0
1789                     _00565_DS_:
1790 0550 [13] 0C85      	CLRF	r0x119E,0
1791 0551 [13] 0600      	MVL	0x00
1792 0552 [13] AE85      	BTSZ	r0x119E,7
1793 0553 [13] 06FF      	MVL	0xff
1794 0554 [13] 6684      	MVF	r0x11A0,1,0
1795 0555 [13] 6683      	MVF	r0x119F,1,0
1796 0556 [13] 6572      	MVF	(_adS + 8),0,0
1797 0557 [13] 128C      	ADDF	r0x1197,1,0
1798 0558 [13] 6485      	MVF	r0x119E,0,0
1799 0559 [13] 168B      	ADDC	r0x1198,1,0
1800 055A [13] 6483      	MVF	r0x119F,0,0
1801 055B [13] 168A      	ADDC	r0x1199,1,0
1802 055C [13] 6484      	MVF	r0x11A0,0,0
1803 055D [13] 1689      	ADDC	r0x119A,1,0
1804 055E [13] 7833      	JMP	_00552_DS_
1805 055F [00] 0011      _00551_DS_:
1806                     ;	;.line	674; ".\ADC_LCD.c"	delta =abs(ADC) - adS.eepromRead_PositiveDeltaLow_bit1 ;
1807 0560 [13] 3165      	DCF	_ADC,0,0
1808 0561 [13] 06FF      	MVL	0xff
1809 0562 [13] 1566      	ADDC	(_ADC + 1),0,0
1810 0563 [13] 06FF      	MVL	0xff
1811 0564 [13] 1567      	ADDC	(_ADC + 2),0,0
1812 0565 [13] 067F      	MVL	0x7f
1813 0566 [13] 1568      	ADDC	(_ADC + 3),0,0
1814 0567 [13] B22B      	BTSS	_STATUS,1
1815 0568 [13] 7809      	JMP	_00566_DS_
1816 0569 [13] 6565      	MVF	_ADC,0,0
1817 056A [13] 6688      	MVF	r0x119B,1,0
1818 056B [13] 6566      	MVF	(_ADC + 1),0,0
1819 056C [13] 6687      	MVF	r0x119C,1,0
1820 056D [13] 6567      	MVF	(_ADC + 2),0,0
1821 056E [13] 6686      	MVF	r0x119D,1,0
1822 056F [13] 6568      	MVF	(_ADC + 3),0,0
1823 0570 [13] 6685      	MVF	r0x119E,1,0
1824 0571 [13] 780E      	JMP	_00567_DS_
1825 0572 [00] 0011      _00566_DS_:
1826 0573 [13] 2565      	COMF	_ADC,0,0
1827 0574 [13] 6688      	MVF	r0x119B,1,0
1828 0575 [13] 2566      	COMF	(_ADC + 1),0,0
1829 0576 [13] 6687      	MVF	r0x119C,1,0
1830 0577 [13] 2567      	COMF	(_ADC + 2),0,0
1831 0578 [13] 6686      	MVF	r0x119D,1,0
1832 0579 [13] 2568      	COMF	(_ADC + 3),0,0
1833 057A [13] 6685      	MVF	r0x119E,1,0
1834 057B [13] 3A88      	INF	r0x119B,1,0
1835 057C [13] 0600      	MVL	0x00
1836 057D [13] 1687      	ADDC	r0x119C,1,0
1837 057E [13] 1686      	ADDC	r0x119D,1,0
1838 057F [13] 1685      	ADDC	r0x119E,1,0
1839                     _00567_DS_:
1840 0580 [13] 0C82      	CLRF	r0x11A2,0
1841 0581 [13] 0600      	MVL	0x00
1842 0582 [13] AE82      	BTSZ	r0x11A2,7
1843 0583 [13] 06FF      	MVL	0xff
1844 0584 [13] 6681      	MVF	r0x11A4,1,0
1845 0585 [13] 6680      	MVF	r0x11A3,1,0
1846 0586 [13] 6571      	MVF	(_adS + 7),0,0
1847 0587 [13] 1888      	SUBF	r0x119B,0,0
1848 0588 [13] 668C      	MVF	r0x1197,1,0
1849 0589 [13] 6482      	MVF	r0x11A2,0,0
1850 058A [13] 1C87      	SUBC	r0x119C,0,0
1851 058B [13] 668B      	MVF	r0x1198,1,0
1852 058C [13] 6480      	MVF	r0x11A3,0,0
1853 058D [13] 1C86      	SUBC	r0x119D,0,0
1854 058E [13] 668A      	MVF	r0x1199,1,0
1855 058F [13] 6481      	MVF	r0x11A4,0,0
1856 0590 [13] 1C85      	SUBC	r0x119E,0,0
1857 0591 [13] 6689      	MVF	r0x119A,1,0
1858                     _00552_DS_:
1859                     ;	;.line	677; ".\ADC_LCD.c"	LCDDisplay= (0.1 * delta)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
1860 0592 [13] C60C      	MVF	r0x1197,0,0
1861 0593 [13] F00D      	MVF	___slong2fs_STK02,1,0
1862 0594 [14] C60C      	MVF	r0x1198,0,0
1863 0595 [14] F00D      	MVF	___slong2fs_STK01,1,0
1864 0596 [15] C60C      	MVF	r0x1199,0,0
1865 0597 [15] F00D      	MVF	___slong2fs_STK00,1,0
1866 0598 [16] 648C      	MVF	r0x119A,0,0
1867 0599 [16] CF57      	CALL	___slong2fs
1868                     	.CHKPARA ___slong2fs 4
1869 059A [13] 6685      	MVF	r0x119E,1,0
1870 059B [13] 6420      	MVF	STK00,0,0
1871 059C [13] 6686      	MVF	r0x119D,1,0
1872 059D [13] 641F      	MVF	STK01,0,0
1873 059E [13] 6687      	MVF	r0x119C,1,0
1874 059F [13] 641E      	MVF	STK02,0,0
1875 05A0 [13] 6688      	MVF	r0x119B,1,0
1876 05A1 [13] 660D      	MVF	___fsmul_STK06,1,0
1877 05A2 [14] C608      	MVF	r0x119C,0,0
1878 05A3 [14] F00D      	MVF	___fsmul_STK05,1,0
1879 05A4 [15] C608      	MVF	r0x119D,0,0
1880 05A5 [15] F00D      	MVF	___fsmul_STK04,1,0
1881 05A6 [16] C608      	MVF	r0x119E,0,0
1882 05A7 [16] F00D      	MVF	___fsmul_STK03,1,0
1883 05A8 [17] C5CD      	MVL	0xcd
1884                     	MVF	___fsmul_STK02,1,0
1885 05A9 [18] C5CC      	MVL	0xcc
1886                     	MVF	___fsmul_STK01,1,0
1887 05AA [19] C5CC      	MVF	___fsmul_STK00,1,0
1888 05AB [20] 063D      	MVL	0x3d
1889 05AC [20] CB75      	CALL	___fsmul
1890                     	.CHKPARA ___fsmul 8
1891 05AD [13] 6682      	MVF	r0x11A2,1,0
1892 05AE [13] 0C0D      	CLRF	___fssub_STK06,0
1893 05AF [14] 0C0D      	CLRF	___fssub_STK05,0
1894 05B0 [15] C5B6      	MVL	0xb6
1895                     	MVF	___fssub_STK04,1,0
1896 05B1 [16] C543      	MVL	0x43
1897                     	MVF	___fssub_STK03,1,0
1898 05B2 [17] D01E      	MVF	STK02,0,0
1899 05B3 [17] F00D      	MVF	___fssub_STK02,1,0
1900 05B4 [18] D01F      	MVF	STK01,0,0
1901 05B5 [18] F00D      	MVF	___fssub_STK01,1,0
1902 05B6 [19] D020      	MVF	STK00,0,0
1903 05B7 [19] F00D      	MVF	___fssub_STK00,1,0
1904 05B8 [20] 6489      	MVF	r0x11A2,0,0
1905 05B9 [20] C95E      	CALL	___fssub
1906                     	.CHKPARA ___fssub 8
1907 05BA [13] 6682      	MVF	r0x11A2,1,0
1908 05BB [13] D01E      	MVF	STK02,0,0
1909 05BC [13] F00D      	MVF	___fs2slong_STK02,1,0
1910 05BD [14] D01F      	MVF	STK01,0,0
1911 05BE [14] F00D      	MVF	___fs2slong_STK01,1,0
1912 05BF [15] D020      	MVF	STK00,0,0
1913 05C0 [15] F00D      	MVF	___fs2slong_STK00,1,0
1914 05C1 [16] 6485      	MVF	r0x11A2,0,0
1915 05C2 [16] C8D9      	CALL	___fs2slong
1916                     	.CHKPARA ___fs2slong 4
1917 05C3 [13] 6682 0011 	MVF	r0x11A2,1,0
1918                     ;	;.line	679; ".\ADC_LCD.c"	if(adS.plus_revise_flag ==1){
1919 05C5 [13] B770      	BTSS	(_adS+6),3
1920 05C6 [13] 78B6      	JMP	_00560_DS_
1921                     ;	;.line	681; ".\ADC_LCD.c"	if(delta<2000)DisplayNum(ADC);
1922 05C7 [13] 0630      	MVL	0x30
1923 05C8 [13] 108C      	ADDF	r0x1197,0,0
1924 05C9 [13] 06F8      	MVL	0xf8
1925 05CA [13] 148B      	ADDC	r0x1198,0,0
1926 05CB [13] 06FF      	MVL	0xff
1927 05CC [13] 148A      	ADDC	r0x1199,0,0
1928 05CD [13] 067F      	MVL	0x7f
1929 05CE [13] 1489      	ADDC	r0x119A,0,0
1930 05CF [13] A22B      	BTSZ	_STATUS,1
1931 05D0 [13] 7809      	JMP	_00557_DS_
1932 05D1 [13] D165      	MVF	_ADC,0,0
1933 05D2 [13] F00D      	MVF	_DisplayNum_STK02,1,0
1934 05D3 [14] D166      	MVF	(_ADC + 1),0,0
1935 05D4 [14] F00D      	MVF	_DisplayNum_STK01,1,0
1936 05D5 [15] D167      	MVF	(_ADC + 2),0,0
1937 05D6 [15] F00D      	MVF	_DisplayNum_STK00,1,0
1938 05D7 [16] 6568      	MVF	(_ADC + 3),0,0
1939 05D8 [16] C8FD      	CALL	_DisplayNum
1940                     	.CHKPARA _DisplayNum 4
1941 05D9 [13] 78C1      	JMP	_00562_DS_
1942                     _00557_DS_:
1943                     ;	;.line	683; ".\ADC_LCD.c"	else if( (LCDDisplay *10) < 2875){
1944 05DA [13] D01E      	MVF	STK02,0,0
1945 05DB [13] F00D      	MVF	__mullong_STK06,1,0
1946 05DC [14] D01F      	MVF	STK01,0,0
1947 05DD [14] F00D      	MVF	__mullong_STK05,1,0
1948 05DE [15] D020      	MVF	STK00,0,0
1949 05DF [15] F00D      	MVF	__mullong_STK04,1,0
1950 05E0 [16] C605      	MVF	r0x11A2,0,0
1951 05E1 [16] F00D      	MVF	__mullong_STK03,1,0
1952 05E2 [17] C50A      	MVL	0x0a
1953                     	MVF	__mullong_STK02,1,0
1954 05E3 [18] 0C0D      	CLRF	__mullong_STK01,0
1955 05E4 [19] 0C0D      	CLRF	__mullong_STK00,0
1956 05E5 [20] 0600      	MVL	0x00
1957 05E6 [20] C948      	CALL	__mullong
1958                     	.CHKPARA __mullong 8
1959 05E7 [13] 6689      	MVF	r0x119A,1,0
1960 05E8 [13] 641E      	MVF	STK02,0,0
1961 05E9 [13] 04C5      	ADDL	0xc5
1962 05EA [13] 06F4      	MVL	0xf4
1963 05EB [13] 141F      	ADDC	STK01,0,0
1964 05EC [13] 06FF      	MVL	0xff
1965 05ED [13] 1420      	ADDC	STK00,0,0
1966 05EE [13] 067F      	MVL	0x7f
1967 05EF [13] 1489      	ADDC	r0x119A,0,0
1968 05F0 [13] A22B      	BTSZ	_STATUS,1
1969 05F1 [13] 7845      	JMP	_00554_DS_
1970                     ;	;.line	684; ".\ADC_LCD.c"	LCDDisplay= 0.125 *delta- 202.86; //y = 0.0125x - 20.286
1971 05F2 [13] C608      	MVF	r0x119B,0,0
1972 05F3 [13] F00D      	MVF	___fsmul_STK06,1,0
1973 05F4 [14] C608      	MVF	r0x119C,0,0
1974 05F5 [14] F00D      	MVF	___fsmul_STK05,1,0
1975 05F6 [15] C608      	MVF	r0x119D,0,0
1976 05F7 [15] F00D      	MVF	___fsmul_STK04,1,0
1977 05F8 [16] 6488      	MVF	r0x119E,0,0
1978 05F9 [16] 660D      	MVF	___fsmul_STK03,1,0
1979 05FA [17] 0C0D      	CLRF	___fsmul_STK02,0
1980 05FB [18] 0C0D      	CLRF	___fsmul_STK01,0
1981 05FC [19] 0C0D      	CLRF	___fsmul_STK00,0
1982 05FD [20] 063E      	MVL	0x3e
1983 05FE [20] CB23      	CALL	___fsmul
1984                     	.CHKPARA ___fsmul 8
1985 05FF [13] 6689      	MVF	r0x119A,1,0
1986 0600 [13] C529      	MVL	0x29
1987                     	MVF	___fssub_STK06,1,0
1988 0601 [14] C5DC      	MVL	0xdc
1989                     	MVF	___fssub_STK05,1,0
1990 0602 [15] C54A      	MVL	0x4a
1991                     	MVF	___fssub_STK04,1,0
1992 0603 [16] C543      	MVL	0x43
1993                     	MVF	___fssub_STK03,1,0
1994 0604 [17] D01E      	MVF	STK02,0,0
1995 0605 [17] F00D      	MVF	___fssub_STK02,1,0
1996 0606 [18] D01F      	MVF	STK01,0,0
1997 0607 [18] F00D      	MVF	___fssub_STK01,1,0
1998 0608 [19] D020      	MVF	STK00,0,0
1999 0609 [19] F00D      	MVF	___fssub_STK00,1,0
2000 060A [20] 6490      	MVF	r0x119A,0,0
2001 060B [20] C90C      	CALL	___fssub
2002                     	.CHKPARA ___fssub 8
2003 060C [13] 6689      	MVF	r0x119A,1,0
2004 060D [13] D01E      	MVF	STK02,0,0
2005 060E [13] F00D      	MVF	___fs2slong_STK02,1,0
2006 060F [14] D01F      	MVF	STK01,0,0
2007 0610 [14] F00D      	MVF	___fs2slong_STK01,1,0
2008 0611 [15] D020      	MVF	STK00,0,0
2009 0612 [15] F00D      	MVF	___fs2slong_STK00,1,0
2010 0613 [16] 648C      	MVF	r0x119A,0,0
2011 0614 [16] C887      	CALL	___fs2slong
2012                     	.CHKPARA ___fs2slong 4
2013 0615 [13] 6689      	MVF	r0x119A,1,0
2014 0616 [13] D01E      	MVF	STK02,0,0
2015                     ;	;.line	685; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
2016 0617 [13] F00D      	MVF	_Reverse_Data_STK02,1,0
2017 0618 [14] D01F      	MVF	STK01,0,0
2018 0619 [14] F00D      	MVF	_Reverse_Data_STK01,1,0
2019 061A [15] D020      	MVF	STK00,0,0
2020 061B [15] F00D      	MVF	_Reverse_Data_STK00,1,0
2021 061C [16] 648C      	MVF	r0x119A,0,0
2022 061D [16] CE5A      	CALL	_Reverse_Data
2023                     	.CHKPARA _Reverse_Data 4
2024 061E [13] 6689      	MVF	r0x119A,1,0
2025 061F [13] 641E      	MVF	STK02,0,0
2026                     ;	;.line	686; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
2027 0620 [13] 660D      	MVF	_UnitConverter_STK02,1,0
2028 0621 [14] 641F      	MVF	STK01,0,0
2029 0622 [14] 660D      	MVF	_UnitConverter_STK01,1,0
2030 0623 [15] 6420      	MVF	STK00,0,0
2031 0624 [15] 660D      	MVF	_UnitConverter_STK00,1,0
2032 0625 [16] 648C      	MVF	r0x119A,0,0
2033 0626 [16] C946      	CALL	_UnitConverter
2034 0627 [13] 6689      	MVF	r0x119A,1,0
2035 0628 [13] D01E      	MVF	STK02,0,0
2036                     ;	;.line	687; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
2037 0629 [13] F00D      	MVF	_DisplayNum_STK02,1,0
2038 062A [14] D01F      	MVF	STK01,0,0
2039 062B [14] F00D      	MVF	_DisplayNum_STK01,1,0
2040 062C [15] D020      	MVF	STK00,0,0
2041 062D [15] F00D      	MVF	_DisplayNum_STK00,1,0
2042 062E [16] 648C      	MVF	r0x119A,0,0
2043 062F [16] C8A6      	CALL	_DisplayNum
2044                     	.CHKPARA _DisplayNum 4
2045                     ;	;.line	688; ".\ADC_LCD.c"	LowVoltageDisplay();
2046 0630 [13] C000 F050 	CALL	_LowVoltageDisplay
2047                     ;	;.line	690; ".\ADC_LCD.c"	Delay(20000);
2048 0632 [13] C520      	MVL	0x20
2049                     	MVF	_Delay_STK00,1,0
2050 0633 [14] 064E      	MVL	0x4e
2051 0634 [14] C000 F0ED 	CALL	_Delay
2052                     	.CHKPARA _Delay 2
2053 0636 [13] 7864      	JMP	_00562_DS_
2054                     _00554_DS_:
2055                     ;	;.line	696; ".\ADC_LCD.c"	LCDDisplay= 56193  - (8.47 * delta) ;//y=-0.846x + 5619.3
2056 0637 [13] C608      	MVF	r0x119B,0,0
2057 0638 [13] F00D      	MVF	___fsmul_STK06,1,0
2058 0639 [14] C608      	MVF	r0x119C,0,0
2059 063A [14] F00D      	MVF	___fsmul_STK05,1,0
2060 063B [15] C608      	MVF	r0x119D,0,0
2061 063C [15] F00D      	MVF	___fsmul_STK04,1,0
2062 063D [16] C608      	MVF	r0x119E,0,0
2063 063E [16] F00D      	MVF	___fsmul_STK03,1,0
2064 063F [17] C51F      	MVL	0x1f
2065                     	MVF	___fsmul_STK02,1,0
2066 0640 [18] C585      	MVL	0x85
2067                     	MVF	___fsmul_STK01,1,0
2068 0641 [19] C507      	MVL	0x07
2069                     	MVF	___fsmul_STK00,1,0
2070 0642 [20] 0641      	MVL	0x41
2071 0643 [20] CADE      	CALL	___fsmul
2072                     	.CHKPARA ___fsmul 8
2073 0644 [13] 6689      	MVF	r0x119A,1,0
2074 0645 [13] D01E      	MVF	STK02,0,0
2075 0646 [13] F00D      	MVF	___fssub_STK06,1,0
2076 0647 [14] D01F      	MVF	STK01,0,0
2077 0648 [14] F00D      	MVF	___fssub_STK05,1,0
2078 0649 [15] D020      	MVF	STK00,0,0
2079 064A [15] F00D      	MVF	___fssub_STK04,1,0
2080 064B [16] 648C      	MVF	r0x119A,0,0
2081 064C [16] 660D      	MVF	___fssub_STK03,1,0
2082 064D [17] 0C0D      	CLRF	___fssub_STK02,0
2083 064E [18] C581      	MVL	0x81
2084                     	MVF	___fssub_STK01,1,0
2085 064F [19] C55B      	MVL	0x5b
2086                     	MVF	___fssub_STK00,1,0
2087 0650 [20] 0647      	MVL	0x47
2088 0651 [20] C8C6      	CALL	___fssub
2089                     	.CHKPARA ___fssub 8
2090 0652 [13] 6689      	MVF	r0x119A,1,0
2091 0653 [13] D01E      	MVF	STK02,0,0
2092 0654 [13] F00D      	MVF	___fs2slong_STK02,1,0
2093 0655 [14] D01F      	MVF	STK01,0,0
2094 0656 [14] F00D      	MVF	___fs2slong_STK01,1,0
2095 0657 [15] D020      	MVF	STK00,0,0
2096 0658 [15] F00D      	MVF	___fs2slong_STK00,1,0
2097 0659 [16] 648C      	MVF	r0x119A,0,0
2098 065A [16] C841      	CALL	___fs2slong
2099                     	.CHKPARA ___fs2slong 4
2100 065B [13] 6689      	MVF	r0x119A,1,0
2101 065C [13] D01E      	MVF	STK02,0,0
2102                     ;	;.line	697; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
2103 065D [13] F00D      	MVF	_Reverse_Data_STK02,1,0
2104 065E [14] D01F      	MVF	STK01,0,0
2105 065F [14] F00D      	MVF	_Reverse_Data_STK01,1,0
2106 0660 [15] D020      	MVF	STK00,0,0
2107 0661 [15] F00D      	MVF	_Reverse_Data_STK00,1,0
2108 0662 [16] 648C      	MVF	r0x119A,0,0
2109 0663 [16] CE14      	CALL	_Reverse_Data
2110                     	.CHKPARA _Reverse_Data 4
2111 0664 [13] 6689      	MVF	r0x119A,1,0
2112 0665 [13] 641E      	MVF	STK02,0,0
2113                     ;	;.line	698; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
2114 0666 [13] 660D      	MVF	_UnitConverter_STK02,1,0
2115 0667 [14] 641F      	MVF	STK01,0,0
2116 0668 [14] 660D      	MVF	_UnitConverter_STK01,1,0
2117 0669 [15] 6420      	MVF	STK00,0,0
2118 066A [15] 660D      	MVF	_UnitConverter_STK00,1,0
2119 066B [16] 648C      	MVF	r0x119A,0,0
2120 066C [16] C900      	CALL	_UnitConverter
2121 066D [13] 6689      	MVF	r0x119A,1,0
2122 066E [13] D01E      	MVF	STK02,0,0
2123                     ;	;.line	699; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
2124 066F [13] F00D      	MVF	_DisplayNum_STK02,1,0
2125 0670 [14] D01F      	MVF	STK01,0,0
2126 0671 [14] F00D      	MVF	_DisplayNum_STK01,1,0
2127 0672 [15] D020      	MVF	STK00,0,0
2128 0673 [15] F00D      	MVF	_DisplayNum_STK00,1,0
2129 0674 [16] 648C      	MVF	r0x119A,0,0
2130 0675 [16] C860      	CALL	_DisplayNum
2131                     	.CHKPARA _DisplayNum 4
2132                     ;	;.line	700; ".\ADC_LCD.c"	LowVoltageDisplay();
2133 0676 [13] C000 F050 	CALL	_LowVoltageDisplay
2134                     ;	;.line	702; ".\ADC_LCD.c"	Delay(20000);
2135 0678 [13] C520      	MVL	0x20
2136                     	MVF	_Delay_STK00,1,0
2137 0679 [14] 064E      	MVL	0x4e
2138 067A [14] C000 F0ED 	CALL	_Delay
2139                     	.CHKPARA _Delay 2
2140 067C [13] 781E      	JMP	_00562_DS_
2141                     _00560_DS_:
2142                     ;	;.line	709; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
2143 067D [13] D165      	MVF	_ADC,0,0
2144 067E [13] F00D      	MVF	_Reverse_Data_STK02,1,0
2145 067F [14] D166      	MVF	(_ADC + 1),0,0
2146 0680 [14] F00D      	MVF	_Reverse_Data_STK01,1,0
2147 0681 [15] D167      	MVF	(_ADC + 2),0,0
2148 0682 [15] F00D 0011 	MVF	_Reverse_Data_STK00,1,0
2149 0684 [16] 6568      	MVF	(_ADC + 3),0,0
2150 0685 [16] CDF2 0011 	CALL	_Reverse_Data
2151                     	.CHKPARA _Reverse_Data 4
2152 0687 [13] 6768      	MVF	(_ADC + 3),1,0
2153 0688 [13] D020      	MVF	STK00,0,0
2154 0689 [13] F167      	MVF	(_ADC + 2),1,0
2155 068A [13] D01F      	MVF	STK01,0,0
2156 068B [13] F166      	MVF	(_ADC + 1),1,0
2157 068C [13] 641E      	MVF	STK02,0,0
2158 068D [13] 6765      	MVF	_ADC,1,0
2159                     ;	;.line	710; ".\ADC_LCD.c"	DisplayNum(ADC);
2160 068E [13] 660D      	MVF	_DisplayNum_STK02,1,0
2161 068F [14] D166      	MVF	(_ADC + 1),0,0
2162 0690 [14] F00D      	MVF	_DisplayNum_STK01,1,0
2163 0691 [15] D167      	MVF	(_ADC + 2),0,0
2164 0692 [15] F00D      	MVF	_DisplayNum_STK00,1,0
2165 0693 [16] 6568      	MVF	(_ADC + 3),0,0
2166 0694 [16] C841      	CALL	_DisplayNum
2167                     	.CHKPARA _DisplayNum 4
2168                     ;	;.line	711; ".\ADC_LCD.c"	LowVoltageDisplay();
2169 0695 [13] C000 F050 	CALL	_LowVoltageDisplay
2170                     ;	;.line	713; ".\ADC_LCD.c"	Delay(20000);
2171 0697 [13] C520      	MVL	0x20
2172                     	MVF	_Delay_STK00,1,0
2173 0698 [14] 064E      	MVL	0x4e
2174 0699 [14] C000 F0ED 	CALL	_Delay
2175                     	.CHKPARA _Delay 2
2176                     _00562_DS_:
2177                     ;	;.line	717; ".\ADC_LCD.c"	}
2178 069B [13] C4F3      	RET	
2179                     ; exit point of _PositivePressureWorks_Mode
2180                     	.ENDFUNC	_PositivePressureWorks_Mode
2181                     ;--------------------------------------------------------
2182                     
2183                     .globl _SetupUnit_Mode
2184                     
2185                     ;--------------------------------------------------------
2186                     	.FUNC _SetupUnit_Mode:0:$C:_Delay:$C:_HY17P52WR3\
2187                     :$L:r0x1195
2188                     ;--------------------------------------------------------
2189                     ;	;.line	606; ".\ADC_LCD.c"	adS.Presskey_flag=0;
2190                     _SetupUnit_Mode:	;Function start
2191                     	BCF	(_adS+6),5
2192                     ;	;.line	607; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
2193                     	BCF	_adS,1
2194                     ;	;.line	608; ".\ADC_LCD.c"	adS.testMode = 0;
2195                     	BCF	(_adS+3),0
2196                     ;	;.line	609; ".\ADC_LCD.c"	adS.reload_ADCInterrupt = 1;
2197                     	BSF	(_adS+13),0
2198                     ;	;.line	610; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
2199                     	CLRF	(_adS + 5),0
2200                     ;	;.line	611; ".\ADC_LCD.c"	adS.key_flag =0;
2201                     	CLRF	(_adS + 4),0
2202                     ;	;.line	613; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2203                     	MVL	0xbf
2204                     	ANDF	_PT1,0,0
2205                     	IORL	0x40
2206                     	MVF	_PT1,1,0
2207                     ;	;.line	614; ".\ADC_LCD.c"	Delay(20000);
2208                     	MVL	0x20
2209                     	MVF	_Delay_STK00,1,0
2210                     	MVL	0x4e
2211                     	CALL	_Delay
2212                     	.CHKPARA _Delay 2
2213                     ;	;.line	615; ".\ADC_LCD.c"	GPIO_PT16_LOW();
2214                     	BCF	_PT1,6
2215                     ;	;.line	616; ".\ADC_LCD.c"	Delay(20000);
2216                     	MVL	0x20
2217                     	MVF	_Delay_STK00,1,0
2218                     	MVL	0x4e
2219                     	CALL	_Delay
2220                     	.CHKPARA _Delay 2
2221                     ;	;.line	617; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2222                     	MVL	0xbf
2223                     	ANDF	_PT1,0,0
2224                     	IORL	0x40
2225                     	MVF	_PT1,1,0
2226                     ;	;.line	618; ".\ADC_LCD.c"	Delay(20000);
2227                     	MVL	0x20
2228                     	MVF	_Delay_STK00,1,0
2229                     	MVL	0x4e
2230                     	CALL	_Delay
2231                     	.CHKPARA _Delay 2
2232                     ;	;.line	619; ".\ADC_LCD.c"	GPIO_PT16_LOW();
2233                     	BCF	_PT1,6
2234                     ;	;.line	622; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
2235                     	MVF	(_adS + 2),0,0
2236                     	MVF	_HY17P52WR3_STK01,1,0
2237                     	MVL	0xaa
2238                     	MVF	_HY17P52WR3_STK00,1,0
2239                     	MVL	0x00
2240                     	CALL	_HY17P52WR3
2241                     	.CHKPARA _HY17P52WR3 3
2242                     ;	;.line	623; ".\ADC_LCD.c"	if(Flag== 1)
2243                     	DCSZ	_Flag,0,0
2244                     	JMP	_00490_DS_
2245                     ;	;.line	625; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2246                     	MVL	0xbf
2247                     	ANDF	_PT1,0,0
2248                     	IORL	0x40
2249                     	MVF	_PT1,1,0
2250                     _00487_DS_:
2251                     ;	;.line	626; ".\ADC_LCD.c"	while(1);    //fail
2252                     	JMP	_00487_DS_
2253                     _00490_DS_:
2254                     ;	;.line	630; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
2255                     	CLRF	_BIEARL,0
2256                     ;	;.line	631; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
2257                     	BSF	_BIECN,0
2258                     _00491_DS_:
2259                     ;	;.line	632; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
2260                     	MVF	_BIECN,0,0
2261                     	ANDL	0x01
2262                     	MVF	r0x1195,1,0
2263                     	DCF	r0x1195,0,0
2264                     	BTSZ	_STATUS,0
2265                     	JMP	_00491_DS_
2266                     ;	;.line	633; ".\ADC_LCD.c"	adS.eepromRead_UnitLow_bit=BIEDRL;
2267                     	MVF	_BIEDRL,0,0
2268                     	MVF	(_adS + 12),1,0
2269                     	MVF	r0x1195,1,0
2270                     ;	;.line	635; ".\ADC_LCD.c"	if(adS.eepromRead_UnitLow_bit==0)  LCD_WriteData(&LCD4, seg_bar) ; 
2271                     	TFSZ	_WREG,0
2272                     	JMP	_00503_DS_
2273                     	MVL	0x02
2274                     	MVF	_LCD4,1,0
2275                     	JMP	_00505_DS_
2276                     _00503_DS_:
2277                     ;	;.line	636; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==1)LCD_WriteData(&LCD4, seg_kgf) ; 
2278                     	DCSZ	r0x1195,0,0
2279                     	JMP	_00500_DS_
2280                     	MVL	0x01
2281                     	MVF	_LCD4,1,0
2282                     	JMP	_00505_DS_
2283                     _00500_DS_:
2284                     ;	;.line	637; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==2)LCD_WriteData(&LCD4, seg_mpa) ; 
2285                     	MVF	r0x1195,0,0
2286                     	XORL	0x02
2287                     	BTSS	_STATUS,0
2288                     	JMP	_00497_DS_
2289                     	MVL	0x08
2290                     	MVF	_LCD4,1,0
2291                     	JMP	_00505_DS_
2292                     _00497_DS_:
2293                     ;	;.line	638; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==3)LCD_WriteData(&LCD4, seg_psi) ; 
2294                     	MVF	r0x1195,0,0
2295                     	XORL	0x03
2296                     	BTSS	_STATUS,0
2297                     	JMP	_00505_DS_
2298                     	MVL	0x04
2299                     	MVF	_LCD4,1,0
2300                     _00505_DS_:
2301                     ;	;.line	642; ".\ADC_LCD.c"	}
2302                     	RET	
2303                     ; exit point of _SetupUnit_Mode
2304                     	.ENDFUNC	_SetupUnit_Mode
2305                     ;--------------------------------------------------------
2306                     
2307                     .globl _SetupZeroPoint_Mode
2308                     
2309                     ;--------------------------------------------------------
2310                     	.FUNC _SetupZeroPoint_Mode:0:$C:___slong2fs:$C:___fsmul:$C:___fs2slong:$C:_HY17P52WR3\
2311                     :$L:r0x1190:$L:r0x118F:$L:r0x118E:$L:r0x118D:$L:r0x1191\
2312                     :$L:r0x1192
2313                     ;--------------------------------------------------------
2314                     ;	;.line	504; ".\ADC_LCD.c"	adS.key_flag =0;
2315                     _SetupZeroPoint_Mode:	;Function start
2316                     	CLRF	(_adS + 4),0
2317                     ;	;.line	505; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
2318                     	CLRF	(_adS + 5),0
2319                     ;	;.line	506; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
2320                     	BCF	(_adS+3),1
2321                     ;	;.line	507; ".\ADC_LCD.c"	adS.testMode=0;
2322                     	BCF	(_adS+3),0
2323                     ;	;.line	508; ".\ADC_LCD.c"	ADC=ADC>>6;
2324                     	SWPF	_ADC,0,0
2325                     	ANDL	0x0f
2326                     	MVF	_ADC,1,0
2327                     	SWPF	(_ADC + 1),0,0
2328                     	MVF	(_ADC + 1),1,0
2329                     	ANDL	0xf0
2330                     	IORF	_ADC,1,0
2331                     	XORF	(_ADC + 1),1,0
2332                     	SWPF	(_ADC + 2),0,0
2333                     	MVF	(_ADC + 2),1,0
2334                     	ANDL	0xf0
2335                     	IORF	(_ADC + 1),1,0
2336                     	XORF	(_ADC + 2),1,0
2337                     	SWPF	(_ADC + 3),0,0
2338                     	MVF	(_ADC + 3),1,0
2339                     	ANDL	0xf0
2340                     	IORF	(_ADC + 2),1,0
2341                     	XORF	(_ADC + 3),1,0
2342                     	MVL	0xf0
2343                     	BTSZ	(_ADC + 3),3
2344                     	IORF	(_ADC + 3),1,0
2345                     	ARRC	(_ADC + 3),1,0
2346                     	RRFC	(_ADC + 2),1,0
2347                     	RRFC	(_ADC + 1),1,0
2348                     	RRFC	_ADC,1,0
2349                     	ARRC	(_ADC + 3),1,0
2350                     	RRFC	(_ADC + 2),1,0
2351                     	RRFC	(_ADC + 1),1,0
2352                     	RRFC	_ADC,1,0
2353                     ;	;.line	509; ".\ADC_LCD.c"	ADC = ADC * 0.1;
2354                     	MVF	_ADC,0,0
2355                     	MVF	___slong2fs_STK02,1,0
2356                     	MVF	(_ADC + 1),0,0
2357                     	MVF	___slong2fs_STK01,1,0
2358                     	MVF	(_ADC + 2),0,0
2359                     	MVF	___slong2fs_STK00,1,0
2360                     	MVF	(_ADC + 3),0,0
2361                     	CALL	___slong2fs
2362                     	.CHKPARA ___slong2fs 4
2363                     	MVF	r0x1190,1,0
2364                     	MVF	STK02,0,0
2365                     	MVF	___fsmul_STK06,1,0
2366                     	MVF	STK01,0,0
2367                     	MVF	___fsmul_STK05,1,0
2368                     	MVF	STK00,0,0
2369                     	MVF	___fsmul_STK04,1,0
2370                     	MVF	r0x1190,0,0
2371                     	MVF	___fsmul_STK03,1,0
2372                     	MVL	0xcd
2373                     	MVF	___fsmul_STK02,1,0
2374                     	MVL	0xcc
2375                     	MVF	___fsmul_STK01,1,0
2376                     	MVF	___fsmul_STK00,1,0
2377                     	MVL	0x3d
2378                     	CALL	___fsmul
2379                     	.CHKPARA ___fsmul 8
2380                     	MVF	r0x1190,1,0
2381                     	MVF	STK02,0,0
2382                     	MVF	___fs2slong_STK02,1,0
2383                     	MVF	STK01,0,0
2384                     	MVF	___fs2slong_STK01,1,0
2385                     	MVF	STK00,0,0
2386                     	MVF	___fs2slong_STK00,1,0
2387                     	MVF	r0x1190,0,0
2388                     	CALL	___fs2slong
2389                     	.CHKPARA ___fs2slong 4
2390                     	MVF	(_ADC + 3),1,0
2391                     	MVF	STK00,0,0
2392                     	MVF	(_ADC + 2),1,0
2393                     	MVF	STK01,0,0
2394                     	MVF	(_ADC + 1),1,0
2395                     	MVF	STK02,0,0
2396                     	MVF	_ADC,1,0
2397                     ;	;.line	510; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
2398                     	BTSZ	(_ADC + 3),7
2399                     	JMP	_00417_DS_
2400                     	DCF	_ADC,0,0
2401                     	MVL	0xff
2402                     	ADDC	(_ADC + 1),0,0
2403                     	MVL	0xff
2404                     	ADDC	(_ADC + 2),0,0
2405                     	MVL	0x7f
2406                     	ADDC	(_ADC + 3),0,0
2407                     	BTSS	_STATUS,4
2408                     	JMP	_00418_DS_
2409                     _00417_DS_:
2410                     ;	;.line	513; ".\ADC_LCD.c"	adS.Pressure_sign =1;
2411                     	BSF	(_adS+6),6
2412                     	JMP	_00419_DS_
2413                     _00418_DS_:
2414                     ;	;.line	517; ".\ADC_LCD.c"	adS.Pressure_sign =0;
2415                     	BCF	(_adS+6),6
2416                     _00419_DS_:
2417                     ;	;.line	523; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
2418                     	BTSS	(_adS+6),6
2419                     	JMP	_00468_DS_
2420                     ;	;.line	525; ".\ADC_LCD.c"	adS.minus_revise_flag=1;   
2421                     	BSF	(_adS+6),4
2422                     ;	;.line	526; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1; //
2423                     	DCF	_ADC,0,0
2424                     	MVL	0xff
2425                     	ADDC	(_ADC + 1),0,0
2426                     	MVL	0xff
2427                     	ADDC	(_ADC + 2),0,0
2428                     	MVL	0x7f
2429                     	ADDC	(_ADC + 3),0,0
2430                     	BTSS	_STATUS,1
2431                     	JMP	_00472_DS_
2432                     	MVF	_ADC,0,0
2433                     	MVF	r0x118D,1,0
2434                     	MVF	(_ADC + 1),0,0
2435                     	MVF	r0x118E,1,0
2436                     	JMP	_00473_DS_
2437                     _00472_DS_:
2438                     	COMF	_ADC,0,0
2439                     	MVF	r0x118D,1,0
2440                     	COMF	(_ADC + 1),0,0
2441                     	MVF	r0x118E,1,0
2442                     	COMF	(_ADC + 2),0,0
2443                     	MVF	r0x118F,1,0
2444                     	COMF	(_ADC + 3),0,0
2445                     	MVF	r0x1190,1,0
2446                     	INF	r0x118D,1,0
2447                     	MVL	0x00
2448                     	ADDC	r0x118E,1,0
2449                     	ADDC	r0x118F,1,0
2450                     	ADDC	r0x1190,1,0
2451                     _00473_DS_:
2452                     	MVL	0x37
2453                     	ADDF	r0x118D,0,0
2454                     	MVF	r0x118D,1,0
2455                     	MVL	0xe7
2456                     	ADDC	r0x118E,0,0
2457                     	MVSF	r0x118D,(_adS + 18)
2458                     	MVF	(_adS + 19),1,0
2459                     ;	;.line	527; ".\ADC_LCD.c"	if(adS.m_offset_value >=0){
2460                     	BTSZ	_STATUS,2
2461                     	JMP	_00442_DS_
2462                     ;	;.line	529; ".\ADC_LCD.c"	HY17P52WR3(3,0x33,adS.m_offset_value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
2463                     	MVF	(_adS + 18),0,0
2464                     	MVF	_HY17P52WR3_STK01,1,0
2465                     	MVL	0x33
2466                     	MVF	_HY17P52WR3_STK00,1,0
2467                     	MVL	0x03
2468                     	CALL	_HY17P52WR3
2469                     	.CHKPARA _HY17P52WR3 3
2470                     ;	;.line	530; ".\ADC_LCD.c"	if(Flag== 1)
2471                     	DCSZ	_Flag,0,0
2472                     	JMP	_00425_DS_
2473                     ;	;.line	532; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2474                     	MVL	0xbf
2475                     	ANDF	_PT1,0,0
2476                     	IORL	0x40
2477                     	MVF	_PT1,1,0
2478                     _00422_DS_:
2479                     ;	;.line	533; ".\ADC_LCD.c"	while(1);    //fail
2480                     	JMP	_00422_DS_
2481                     _00425_DS_:
2482                     ;	;.line	535; ".\ADC_LCD.c"	HY17P52WR3(4,0x20,0x0);
2483                     	CLRF	_HY17P52WR3_STK01,0
2484                     	MVL	0x20
2485                     	MVF	_HY17P52WR3_STK00,1,0
2486                     	MVL	0x04
2487                     	CALL	_HY17P52WR3
2488                     	.CHKPARA _HY17P52WR3 3
2489                     ;	;.line	536; ".\ADC_LCD.c"	if(Flag== 1)
2490                     	DCSZ	_Flag,0,0
2491                     	JMP	_00470_DS_
2492                     ;	;.line	538; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2493                     	MVL	0xbf
2494                     	ANDF	_PT1,0,0
2495                     	IORL	0x40
2496                     	MVF	_PT1,1,0
2497                     _00427_DS_:
2498                     ;	;.line	539; ".\ADC_LCD.c"	while(1);    //fail
2499                     	JMP	_00427_DS_
2500                     _00442_DS_:
2501                     ;	;.line	543; ".\ADC_LCD.c"	adS.m_offset_value = abs(adS.m_offset_value); //write delta data in eeprom
2502                     	DCF	(_adS + 18),0,0
2503                     	MVL	0x7f
2504                     	ADDC	(_adS + 19),0,0
2505                     	BTSS	_STATUS,1
2506                     	JMP	_00474_DS_
2507                     	MVF	(_adS + 18),0,0
2508                     	MVF	r0x118D,1,0
2509                     	JMP	_00475_DS_
2510                     _00474_DS_:
2511                     	COMF	(_adS + 18),0,0
2512                     	MVF	r0x118D,1,0
2513                     	COMF	(_adS + 19),0,0
2514                     	INSUZ	r0x118D,1,0
2515                     	ADDL	0x01
2516                     	MVF	r0x118E,1,0
2517                     _00475_DS_:
2518                     	MVF	r0x118D,0,0
2519                     	MVF	(_adS + 18),1,0
2520                     ;	;.line	544; ".\ADC_LCD.c"	HY17P52WR3(4,0x44,adS.m_offset_value);	//addr=02,BIE_DataH=0xAA,BIE_DataL=0x11
2521                     	MVSF	r0x118E,(_adS + 19)
2522                     	MVF	_HY17P52WR3_STK01,1,0
2523                     	MVL	0x44
2524                     	MVF	_HY17P52WR3_STK00,1,0
2525                     	MVL	0x04
2526                     	CALL	_HY17P52WR3
2527                     	.CHKPARA _HY17P52WR3 3
2528                     ;	;.line	545; ".\ADC_LCD.c"	if(Flag== 1)
2529                     	DCSZ	_Flag,0,0
2530                     	JMP	_00435_DS_
2531                     ;	;.line	547; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2532                     	MVL	0xbf
2533                     	ANDF	_PT1,0,0
2534                     	IORL	0x40
2535                     	MVF	_PT1,1,0
2536                     _00432_DS_:
2537                     ;	;.line	548; ".\ADC_LCD.c"	while(1);    //fail
2538                     	JMP	_00432_DS_
2539                     _00435_DS_:
2540                     ;	;.line	550; ".\ADC_LCD.c"	HY17P52WR3(3,0x20,0x0);
2541                     	CLRF	_HY17P52WR3_STK01,0
2542                     	MVL	0x20
2543                     	MVF	_HY17P52WR3_STK00,1,0
2544                     	MVL	0x03
2545                     	CALL	_HY17P52WR3
2546                     	.CHKPARA _HY17P52WR3 3
2547                     ;	;.line	551; ".\ADC_LCD.c"	if(Flag== 1)
2548                     	DCSZ	_Flag,0,0
2549                     	JMP	_00470_DS_
2550                     ;	;.line	553; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2551                     	MVL	0xbf
2552                     	ANDF	_PT1,0,0
2553                     	IORL	0x40
2554                     	MVF	_PT1,1,0
2555                     _00437_DS_:
2556                     ;	;.line	554; ".\ADC_LCD.c"	while(1);    //fail
2557                     	JMP	_00437_DS_
2558                     _00468_DS_:
2559                     ;	;.line	560; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
2560                     	BSF	(_adS+6),3
2561                     ;	;.line	561; ".\ADC_LCD.c"	adS.p_offset_value= abs(ADC) -STD_VALUE + 1; 
2562                     	DCF	_ADC,0,0
2563                     	MVL	0xff
2564                     	ADDC	(_ADC + 1),0,0
2565                     	MVL	0xff
2566                     	ADDC	(_ADC + 2),0,0
2567                     	MVL	0x7f
2568                     	ADDC	(_ADC + 3),0,0
2569                     	BTSS	_STATUS,1
2570                     	JMP	_00476_DS_
2571                     	MVF	_ADC,0,0
2572                     	MVF	r0x118D,1,0
2573                     	MVF	(_ADC + 1),0,0
2574                     	MVF	r0x118E,1,0
2575                     	JMP	_00477_DS_
2576                     _00476_DS_:
2577                     	COMF	_ADC,0,0
2578                     	MVF	r0x118D,1,0
2579                     	COMF	(_ADC + 1),0,0
2580                     	MVF	r0x118E,1,0
2581                     	COMF	(_ADC + 2),0,0
2582                     	MVF	r0x1191,1,0
2583                     	COMF	(_ADC + 3),0,0
2584                     	MVF	r0x1192,1,0
2585                     	INF	r0x118D,1,0
2586                     	MVL	0x00
2587                     	ADDC	r0x118E,1,0
2588                     	ADDC	r0x1191,1,0
2589                     	ADDC	r0x1192,1,0
2590                     _00477_DS_:
2591                     	MVL	0x85
2592                     	ADDF	r0x118D,0,0
2593                     	MVF	r0x118D,1,0
2594                     	MVL	0xe6
2595                     	ADDC	r0x118E,0,0
2596                     	MVSF	r0x118D,(_adS + 20)
2597                     	MVF	(_adS + 21),1,0
2598                     ;	;.line	562; ".\ADC_LCD.c"	if(adS.p_offset_value >=0){
2599                     	BTSZ	_STATUS,2
2600                     	JMP	_00465_DS_
2601                     ;	;.line	564; ".\ADC_LCD.c"	adS.p_offset_value = abs(adS.p_offset_value); //Write delta data in eeprom
2602                     	DCF	(_adS + 20),0,0
2603                     	MVL	0x7f
2604                     	ADDC	(_adS + 21),0,0
2605                     	BTSS	_STATUS,1
2606                     	JMP	_00478_DS_
2607                     	MVF	(_adS + 20),0,0
2608                     	MVF	r0x118D,1,0
2609                     	JMP	_00479_DS_
2610                     _00478_DS_:
2611                     	COMF	(_adS + 20),0,0
2612                     	MVF	r0x118D,1,0
2613                     	COMF	(_adS + 21),0,0
2614                     	INSUZ	r0x118D,1,0
2615                     	ADDL	0x01
2616                     	MVF	r0x118E,1,0
2617                     _00479_DS_:
2618                     	MVF	r0x118D,0,0
2619                     	MVF	(_adS + 20),1,0
2620                     ;	;.line	565; ".\ADC_LCD.c"	HY17P52WR3(1,0x11,adS.p_offset_value);	//addr=01,BIE_DataH=0xAA,BIE_DataL=0x11
2621                     	MVSF	r0x118E,(_adS + 21)
2622                     	MVF	_HY17P52WR3_STK01,1,0
2623                     	MVL	0x11
2624                     	MVF	_HY17P52WR3_STK00,1,0
2625                     	MVL	0x01
2626                     	CALL	_HY17P52WR3
2627                     	.CHKPARA _HY17P52WR3 3
2628                     ;	;.line	566; ".\ADC_LCD.c"	if(Flag== 1)
2629                     	DCSZ	_Flag,0,0
2630                     	JMP	_00448_DS_
2631                     ;	;.line	568; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2632                     	MVL	0xbf
2633                     	ANDF	_PT1,0,0
2634                     	IORL	0x40
2635                     	MVF	_PT1,1,0
2636                     _00445_DS_:
2637                     ;	;.line	569; ".\ADC_LCD.c"	while(1);    //fail
2638                     	JMP	_00445_DS_
2639                     _00448_DS_:
2640                     ;	;.line	571; ".\ADC_LCD.c"	HY17P52WR3(2,0x10,0x0);
2641                     	CLRF	_HY17P52WR3_STK01,0
2642                     	MVL	0x10
2643                     	MVF	_HY17P52WR3_STK00,1,0
2644                     	MVL	0x02
2645                     	CALL	_HY17P52WR3
2646                     	.CHKPARA _HY17P52WR3 3
2647                     ;	;.line	572; ".\ADC_LCD.c"	if(Flag== 1)
2648                     	DCSZ	_Flag,0,0
2649                     	JMP	_00470_DS_
2650                     ;	;.line	574; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2651                     	MVL	0xbf
2652                     	ANDF	_PT1,0,0
2653                     	IORL	0x40
2654                     	MVF	_PT1,1,0
2655                     _00450_DS_:
2656                     ;	;.line	575; ".\ADC_LCD.c"	while(1);    //fail
2657                     	JMP	_00450_DS_
2658                     _00465_DS_:
2659                     ;	;.line	579; ".\ADC_LCD.c"	adS.p_offset_value = abs(adS.p_offset_value); //Write delta data in eeprom
2660                     	DCF	(_adS + 20),0,0
2661                     	MVL	0x7f
2662                     	ADDC	(_adS + 21),0,0
2663                     	BTSS	_STATUS,1
2664                     	JMP	_00480_DS_
2665                     	MVF	(_adS + 20),0,0
2666                     	MVF	r0x118D,1,0
2667                     	JMP	_00481_DS_
2668                     _00480_DS_:
2669                     	COMF	(_adS + 20),0,0
2670                     	MVF	r0x118D,1,0
2671                     	COMF	(_adS + 21),0,0
2672                     	INSUZ	r0x118D,1,0
2673                     	ADDL	0x01
2674                     	MVF	r0x118E,1,0
2675                     _00481_DS_:
2676                     	MVF	r0x118D,0,0
2677                     	MVF	(_adS + 20),1,0
2678                     ;	;.line	580; ".\ADC_LCD.c"	HY17P52WR3(2,0x22,adS.p_offset_value);	//addr=01,BIE_DataH=0xAA,BIE_DataL=0x11
2679                     	MVSF	r0x118E,(_adS + 21)
2680                     	MVF	_HY17P52WR3_STK01,1,0
2681                     	MVL	0x22
2682                     	MVF	_HY17P52WR3_STK00,1,0
2683                     	MVL	0x02
2684                     	CALL	_HY17P52WR3
2685                     	.CHKPARA _HY17P52WR3 3
2686                     ;	;.line	581; ".\ADC_LCD.c"	if(Flag== 1)
2687                     	DCSZ	_Flag,0,0
2688                     	JMP	_00458_DS_
2689                     ;	;.line	583; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2690                     	MVL	0xbf
2691                     	ANDF	_PT1,0,0
2692                     	IORL	0x40
2693                     	MVF	_PT1,1,0
2694                     _00455_DS_:
2695                     ;	;.line	584; ".\ADC_LCD.c"	while(1);    //fail
2696                     	JMP	_00455_DS_
2697                     _00458_DS_:
2698                     ;	;.line	586; ".\ADC_LCD.c"	HY17P52WR3(1,0x11,0x0);
2699                     	CLRF	_HY17P52WR3_STK01,0
2700                     	MVL	0x11
2701                     	MVF	_HY17P52WR3_STK00,1,0
2702                     	MVL	0x01
2703                     	CALL	_HY17P52WR3
2704                     	.CHKPARA _HY17P52WR3 3
2705                     ;	;.line	587; ".\ADC_LCD.c"	if(Flag== 1)
2706                     	DCSZ	_Flag,0,0
2707                     	JMP	_00470_DS_
2708                     ;	;.line	589; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
2709                     	MVL	0xbf
2710                     	ANDF	_PT1,0,0
2711                     	IORL	0x40
2712                     	MVF	_PT1,1,0
2713                     _00460_DS_:
2714                     ;	;.line	590; ".\ADC_LCD.c"	while(1);    //fail
2715                     	JMP	_00460_DS_
2716                     _00470_DS_:
2717                     ;	;.line	596; ".\ADC_LCD.c"	}
2718                     	RET	
2719                     ; exit point of _SetupZeroPoint_Mode
2720                     	.ENDFUNC	_SetupZeroPoint_Mode
2721                     ;--------------------------------------------------------
2722                     
2723                     .globl _LowVoltageDisplay
2724                     
2725                     ;--------------------------------------------------------
2726                     	.FUNC _LowVoltageDisplay:0:$C:_LowVoltageDetect_3V:$C:_DisplayBatteryCapacityFull:$C:_LowVoltageDetect_2V4:$C:_DisplayBatteryCapacityHalf\
2727                     :$C:_DispalyBatteryCapacityLow\
2728                     :$L:r0x118C
2729                     ;--------------------------------------------------------
2730                     ;	;.line	473; ".\ADC_LCD.c"	adS.LVD_3V_flag = LowVoltageDetect_3V();
2731 0050 [00] C481      _LowVoltageDisplay:	;Function start
2732 0051 [01] C81D      	CALL	_LowVoltageDetect_3V
2733 0052 [01] 6680      	MVF	r0x118C,1,0
2734 0053 [01] 5080 0011 	RRFC	r0x118C,0,0
2735 0055 [01] B82B      	BTSS	_STATUS,4
2736 0056 [01] 8570 0011 	BCF	(_adS+6),2
2737 0058 [01] A82B      	BTSZ	_STATUS,4
2738 0059 [01] 9570 0011 	BSF	(_adS+6),2
2739                     ;	;.line	474; ".\ADC_LCD.c"	if(adS.LVD_3V_flag==0){ /* battery capacity is full*/
2740 005B [01] A570      	BTSZ	(_adS+6),2
2741 005C [01] 7802      	JMP	_00410_DS_
2742                     ;	;.line	477; ".\ADC_LCD.c"	DisplayBatteryCapacityFull(); 
2743 005D [01] C86C      	CALL	_DisplayBatteryCapacityFull
2744                     	.CHKPARA _DisplayBatteryCapacityFull 0
2745 005E [01] 780F      	JMP	_00412_DS_
2746                     _00410_DS_:
2747                     ;	;.line	480; ".\ADC_LCD.c"	adS.LVD_2V4_flag = LowVoltageDetect_2V4();
2748 005F [01] C87C      	CALL	_LowVoltageDetect_2V4
2749 0060 [01] 6680      	MVF	r0x118C,1,0
2750 0061 [01] 5080 0011 	RRFC	r0x118C,0,0
2751 0063 [01] B82B      	BTSS	_STATUS,4
2752 0064 [01] 8370 0011 	BCF	(_adS+6),1
2753 0066 [01] A82B      	BTSZ	_STATUS,4
2754 0067 [01] 9370 0011 	BSF	(_adS+6),1
2755                     ;	;.line	481; ".\ADC_LCD.c"	if(adS.LVD_2V4_flag == 0){
2756 0069 [01] A370      	BTSZ	(_adS+6),1
2757 006A [01] 7802      	JMP	_00407_DS_
2758                     ;	;.line	484; ".\ADC_LCD.c"	DisplayBatteryCapacityHalf();
2759 006B [01] C85B      	CALL	_DisplayBatteryCapacityHalf
2760                     	.CHKPARA _DisplayBatteryCapacityHalf 0
2761 006C [01] 7801      	JMP	_00412_DS_
2762                     _00407_DS_:
2763                     ;	;.line	488; ".\ADC_LCD.c"	DispalyBatteryCapacityLow();
2764 006D [01] C856      	CALL	_DispalyBatteryCapacityLow
2765                     	.CHKPARA _DispalyBatteryCapacityLow 0
2766                     _00412_DS_:
2767                     ;	;.line	492; ".\ADC_LCD.c"	}
2768 006E [01] C4FF      	RET	
2769                     ; exit point of _LowVoltageDisplay
2770                     	.ENDFUNC	_LowVoltageDisplay
2771                     ;--------------------------------------------------------
2772                     
2773                     .globl _LowVoltageDetect_2V4
2774                     
2775                     ;--------------------------------------------------------
2776                     	.FUNC _LowVoltageDetect_2V4:0:$C:_Delay\
2777                     :$L:r0x118B
2778                     ;--------------------------------------------------------
2779                     ;	;.line	448; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_24);  
2780 00DC [00] C481      _LowVoltageDetect_2V4:	;Function start
2781 00DD [01] 06E1      	MVL	0xe1
2782 00DE [01] 2843      	ANDF	_LVDCN,0,0
2783 00DF [01] 020A      	IORL	0x0a
2784 00E0 [01] 6643      	MVF	_LVDCN,1,0
2785                     ;	;.line	449; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
2786 00E1 [01] 8A43      	BCF	_LVDCN,5
2787                     ;	;.line	450; ".\ADC_LCD.c"	Delay(10);
2788 00E2 [01] C50A      	MVL	0x0a
2789                     	MVF	_Delay_STK00,1,0
2790 00E3 [02] 0600      	MVL	0x00
2791 00E4 [02] C808      	CALL	_Delay
2792                     	.CHKPARA _Delay 2
2793                     ;	;.line	451; ".\ADC_LCD.c"	if(LVD_GetLVDO())
2794 00E5 [01] B043      	BTSS	_LVDCN,0
2795 00E6 [01] 7802      	JMP	_00400_DS_
2796                     ;	;.line	453; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
2797 00E7 [01] 0C80      	CLRF	r0x118B,0
2798 00E8 [01] 7802      	JMP	_00401_DS_
2799                     _00400_DS_:
2800                     ;	;.line	457; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
2801 00E9 [01] 0601      	MVL	0x01
2802 00EA [01] 6680      	MVF	r0x118B,1,0
2803                     _00401_DS_:
2804                     ;	;.line	459; ".\ADC_LCD.c"	return flag;
2805 00EB [01] 6480      	MVF	r0x118B,0,0
2806                     ;	;.line	460; ".\ADC_LCD.c"	}
2807 00EC [01] C4FF      	RET	
2808                     ; exit point of _LowVoltageDetect_2V4
2809                     	.ENDFUNC	_LowVoltageDetect_2V4
2810                     ;--------------------------------------------------------
2811                     
2812                     .globl _LowVoltageDetect_3V
2813                     
2814                     ;--------------------------------------------------------
2815                     	.FUNC _LowVoltageDetect_3V:0:$C:_Delay\
2816                     :$L:r0x118A
2817                     ;--------------------------------------------------------
2818                     ;	;.line	422; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_30 );  
2819 006F [00] C481      _LowVoltageDetect_3V:	;Function start
2820 0070 [01] 06E1      	MVL	0xe1
2821 0071 [01] 2843      	ANDF	_LVDCN,0,0
2822 0072 [01] 0216      	IORL	0x16
2823 0073 [01] 6643      	MVF	_LVDCN,1,0
2824                     ;	;.line	423; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
2825 0074 [01] 8A43      	BCF	_LVDCN,5
2826                     ;	;.line	424; ".\ADC_LCD.c"	Delay(10);
2827 0075 [01] C50A      	MVL	0x0a
2828                     	MVF	_Delay_STK00,1,0
2829 0076 [02] 0600      	MVL	0x00
2830 0077 [02] C875      	CALL	_Delay
2831                     	.CHKPARA _Delay 2
2832                     ;	;.line	425; ".\ADC_LCD.c"	if(LVD_GetLVDO())
2833 0078 [01] B043      	BTSS	_LVDCN,0
2834 0079 [01] 7802      	JMP	_00393_DS_
2835                     ;	;.line	427; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
2836 007A [01] 0C80      	CLRF	r0x118A,0
2837 007B [01] 7802      	JMP	_00394_DS_
2838                     _00393_DS_:
2839                     ;	;.line	431; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
2840 007C [01] 0601      	MVL	0x01
2841 007D [01] 6680      	MVF	r0x118A,1,0
2842                     _00394_DS_:
2843                     ;	;.line	433; ".\ADC_LCD.c"	return flag;
2844 007E [01] 6480      	MVF	r0x118A,0,0
2845                     ;	;.line	434; ".\ADC_LCD.c"	}
2846 007F [01] C4FF      	RET	
2847                     ; exit point of _LowVoltageDetect_3V
2848                     	.ENDFUNC	_LowVoltageDetect_3V
2849                     ;--------------------------------------------------------
2850                     
2851                     .globl _UnitConverter
2852                     
2853                     ;--------------------------------------------------------
2854                     	.FUNC _UnitConverter:4:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
2855                     :$L:r0x1181:$L:_UnitConverter_STK00:$L:_UnitConverter_STK01:$L:_UnitConverter_STK02:$L:r0x1182\
2856                     :$L:r0x1186:$L:r0x1185
2857                     ;--------------------------------------------------------
2858                     ;	;.line	379; ".\ADC_LCD.c"	long UnitConverter(long data)
2859 076D [00] C484      _UnitConverter:	;Function start
2860 076E [04] 6683      	MVF	r0x1181,1,0
2861                     ;	;.line	382; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
2862 076F [04] 0C30      	CLRF	_BIEARL,0
2863                     ;	;.line	383; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
2864 0770 [04] 902E      	BSF	_BIECN,0
2865                     _00346_DS_:
2866                     ;	;.line	384; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
2867 0771 [04] 642E      	MVF	_BIECN,0,0
2868 0772 [04] 0101      	ANDL	0x01
2869 0773 [04] 6682      	MVF	r0x1182,1,0
2870 0774 [04] 3082      	DCF	r0x1182,0,0
2871 0775 [04] A02B      	BTSZ	_STATUS,0
2872 0776 [04] 7FFA      	JMP	_00346_DS_
2873                     ;	;.line	385; ".\ADC_LCD.c"	adS.eepromRead_UnitLow_bit=BIEDRL;
2874 0777 [04] 6432 0011 	MVF	_BIEDRL,0,0
2875 0779 [04] 6776      	MVF	(_adS + 12),1,0
2876 077A [04] 6682      	MVF	r0x1182,1,0
2877                     ;	;.line	387; ".\ADC_LCD.c"	if(adS.eepromRead_UnitLow_bit==0){ /*psi*/
2878 077B [04] 6E29      	TFSZ	_WREG,0
2879 077C [04] 7822      	JMP	_00359_DS_
2880                     ;	;.line	389; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_psi) ;
2881 077D [04] 0604      	MVL	0x04
2882 077E [04] 6663      	MVF	_LCD4,1,0
2883                     ;	;.line	390; ".\ADC_LCD.c"	return  kgfTOpsi(data) ;
2884 077F [04] C606      	MVF	_UnitConverter_STK02,0,0
2885 0780 [04] F00D      	MVF	___slong2fs_STK02,1,0
2886 0781 [05] C606      	MVF	_UnitConverter_STK01,0,0
2887 0782 [05] F00D      	MVF	___slong2fs_STK01,1,0
2888 0783 [06] C606      	MVF	_UnitConverter_STK00,0,0
2889 0784 [06] F00D      	MVF	___slong2fs_STK00,1,0
2890 0785 [07] 6486      	MVF	r0x1181,0,0
2891 0786 [07] CD6A      	CALL	___slong2fs
2892                     	.CHKPARA ___slong2fs 4
2893 0787 [04] 6681      	MVF	r0x1186,1,0
2894 0788 [04] D01E      	MVF	STK02,0,0
2895 0789 [04] F00D      	MVF	___fsmul_STK06,1,0
2896 078A [05] D01F      	MVF	STK01,0,0
2897 078B [05] F00D      	MVF	___fsmul_STK05,1,0
2898 078C [06] D020      	MVF	STK00,0,0
2899 078D [06] F00D      	MVF	___fsmul_STK04,1,0
2900 078E [07] C604      	MVF	r0x1186,0,0
2901 078F [07] F00D      	MVF	___fsmul_STK03,1,0
2902 0790 [08] C5E1      	MVL	0xe1
2903                     	MVF	___fsmul_STK02,1,0
2904 0791 [09] C57A      	MVL	0x7a
2905                     	MVF	___fsmul_STK01,1,0
2906 0792 [10] C514      	MVL	0x14
2907                     	MVF	___fsmul_STK00,1,0
2908 0793 [11] 063E      	MVL	0x3e
2909 0794 [11] C98D      	CALL	___fsmul
2910                     	.CHKPARA ___fsmul 8
2911 0795 [04] 6681      	MVF	r0x1186,1,0
2912 0796 [04] D01E      	MVF	STK02,0,0
2913 0797 [04] F00D      	MVF	___fs2slong_STK02,1,0
2914 0798 [05] D01F      	MVF	STK01,0,0
2915 0799 [05] F00D      	MVF	___fs2slong_STK01,1,0
2916 079A [06] D020      	MVF	STK00,0,0
2917 079B [06] F00D      	MVF	___fs2slong_STK00,1,0
2918 079C [07] 6484      	MVF	r0x1186,0,0
2919 079D [07] CEFE      	CALL	___fs2slong
2920 079E [04] 7861      	JMP	_00361_DS_
2921                     _00359_DS_:
2922                     ;	;.line	392; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==1){ /*unit bar*/
2923 079F [04] 3482      	DCSZ	r0x1182,0,0
2924 07A0 [04] 7822      	JMP	_00356_DS_
2925                     ;	;.line	393; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_bar) ;
2926 07A1 [04] 0602      	MVL	0x02
2927 07A2 [04] 6663      	MVF	_LCD4,1,0
2928                     ;	;.line	394; ".\ADC_LCD.c"	return	kgfTObar(data);
2929 07A3 [04] C606      	MVF	_UnitConverter_STK02,0,0
2930 07A4 [04] F00D      	MVF	___slong2fs_STK02,1,0
2931 07A5 [05] C606      	MVF	_UnitConverter_STK01,0,0
2932 07A6 [05] F00D      	MVF	___slong2fs_STK01,1,0
2933 07A7 [06] C606      	MVF	_UnitConverter_STK00,0,0
2934 07A8 [06] F00D      	MVF	___slong2fs_STK00,1,0
2935 07A9 [07] 6486      	MVF	r0x1181,0,0
2936 07AA [07] CD46      	CALL	___slong2fs
2937                     	.CHKPARA ___slong2fs 4
2938 07AB [04] 6681      	MVF	r0x1186,1,0
2939 07AC [04] D01E      	MVF	STK02,0,0
2940 07AD [04] F00D      	MVF	___fsmul_STK06,1,0
2941 07AE [05] D01F      	MVF	STK01,0,0
2942 07AF [05] F00D      	MVF	___fsmul_STK05,1,0
2943 07B0 [06] D020      	MVF	STK00,0,0
2944 07B1 [06] F00D      	MVF	___fsmul_STK04,1,0
2945 07B2 [07] C604      	MVF	r0x1186,0,0
2946 07B3 [07] F00D      	MVF	___fsmul_STK03,1,0
2947 07B4 [08] C50A      	MVL	0x0a
2948                     	MVF	___fsmul_STK02,1,0
2949 07B5 [09] C5D7      	MVL	0xd7
2950                     	MVF	___fsmul_STK01,1,0
2951 07B6 [10] C523      	MVL	0x23
2952                     	MVF	___fsmul_STK00,1,0
2953 07B7 [11] 063C      	MVL	0x3c
2954 07B8 [11] C969      	CALL	___fsmul
2955                     	.CHKPARA ___fsmul 8
2956 07B9 [04] 6681      	MVF	r0x1186,1,0
2957 07BA [04] D01E      	MVF	STK02,0,0
2958 07BB [04] F00D      	MVF	___fs2slong_STK02,1,0
2959 07BC [05] D01F      	MVF	STK01,0,0
2960 07BD [05] F00D      	MVF	___fs2slong_STK01,1,0
2961 07BE [06] D020      	MVF	STK00,0,0
2962 07BF [06] F00D      	MVF	___fs2slong_STK00,1,0
2963 07C0 [07] 6484      	MVF	r0x1186,0,0
2964 07C1 [07] CEDA      	CALL	___fs2slong
2965 07C2 [04] 783D      	JMP	_00361_DS_
2966                     _00356_DS_:
2967                     ;	;.line	396; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==2){ /* unit kgf*/
2968 07C3 [04] 6482      	MVF	r0x1182,0,0
2969 07C4 [04] 0302      	XORL	0x02
2970 07C5 [04] B02B      	BTSS	_STATUS,0
2971 07C6 [04] 780A      	JMP	_00353_DS_
2972                     ;	;.line	398; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
2973 07C7 [04] 0601      	MVL	0x01
2974 07C8 [04] 6663      	MVF	_LCD4,1,0
2975                     ;	;.line	399; ".\ADC_LCD.c"	return data;
2976 07C9 [04] C606      	MVF	_UnitConverter_STK02,0,0
2977 07CA [04] F01E      	MVF	STK02,1,0
2978 07CB [04] C605      	MVF	_UnitConverter_STK01,0,0
2979 07CC [04] F01F      	MVF	STK01,1,0
2980 07CD [04] C604      	MVF	_UnitConverter_STK00,0,0
2981 07CE [04] F020      	MVF	STK00,1,0
2982 07CF [04] 6483      	MVF	r0x1181,0,0
2983 07D0 [04] 782F      	JMP	_00361_DS_
2984                     _00353_DS_:
2985                     ;	;.line	401; ".\ADC_LCD.c"	else if(adS.eepromRead_UnitLow_bit==3){ /*uint mpa*/
2986 07D1 [04] 6482      	MVF	r0x1182,0,0
2987 07D2 [04] 0303      	XORL	0x03
2988 07D3 [04] B02B      	BTSS	_STATUS,0
2989 07D4 [04] 7822      	JMP	_00350_DS_
2990                     ;	;.line	403; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_mpa) ;
2991 07D5 [04] 0608      	MVL	0x08
2992 07D6 [04] 6663      	MVF	_LCD4,1,0
2993                     ;	;.line	404; ".\ADC_LCD.c"	return kgfTOmpa(data);
2994 07D7 [04] C606      	MVF	_UnitConverter_STK02,0,0
2995 07D8 [04] F00D      	MVF	___slong2fs_STK02,1,0
2996 07D9 [05] C606      	MVF	_UnitConverter_STK01,0,0
2997 07DA [05] F00D      	MVF	___slong2fs_STK01,1,0
2998 07DB [06] C606      	MVF	_UnitConverter_STK00,0,0
2999 07DC [06] F00D      	MVF	___slong2fs_STK00,1,0
3000 07DD [07] 6486      	MVF	r0x1181,0,0
3001 07DE [07] CD12      	CALL	___slong2fs
3002                     	.CHKPARA ___slong2fs 4
3003 07DF [04] 6680      	MVF	r0x1185,1,0
3004 07E0 [04] D01E      	MVF	STK02,0,0
3005 07E1 [04] F00D      	MVF	___fsmul_STK06,1,0
3006 07E2 [05] D01F      	MVF	STK01,0,0
3007 07E3 [05] F00D      	MVF	___fsmul_STK05,1,0
3008 07E4 [06] D020      	MVF	STK00,0,0
3009 07E5 [06] F00D      	MVF	___fsmul_STK04,1,0
3010 07E6 [07] C603      	MVF	r0x1185,0,0
3011 07E7 [07] F00D      	MVF	___fsmul_STK03,1,0
3012 07E8 [08] C5CD      	MVL	0xcd
3013                     	MVF	___fsmul_STK02,1,0
3014 07E9 [09] C5CC      	MVL	0xcc
3015                     	MVF	___fsmul_STK01,1,0
3016 07EA [10] C5CC      	MVF	___fsmul_STK00,1,0
3017 07EB [11] 063D      	MVL	0x3d
3018 07EC [11] C935      	CALL	___fsmul
3019                     	.CHKPARA ___fsmul 8
3020 07ED [04] 6680      	MVF	r0x1185,1,0
3021 07EE [04] D01E      	MVF	STK02,0,0
3022 07EF [04] F00D      	MVF	___fs2slong_STK02,1,0
3023 07F0 [05] D01F      	MVF	STK01,0,0
3024 07F1 [05] F00D      	MVF	___fs2slong_STK01,1,0
3025 07F2 [06] D020      	MVF	STK00,0,0
3026 07F3 [06] F00D      	MVF	___fs2slong_STK00,1,0
3027 07F4 [07] 6483      	MVF	r0x1185,0,0
3028 07F5 [07] CEA6      	CALL	___fs2slong
3029 07F6 [04] 7809      	JMP	_00361_DS_
3030                     _00350_DS_:
3031                     ;	;.line	407; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
3032 07F7 [04] 0601      	MVL	0x01
3033 07F8 [04] 6663      	MVF	_LCD4,1,0
3034                     ;	;.line	408; ".\ADC_LCD.c"	return data;
3035 07F9 [04] C606      	MVF	_UnitConverter_STK02,0,0
3036 07FA [04] F01E      	MVF	STK02,1,0
3037 07FB [04] C605      	MVF	_UnitConverter_STK01,0,0
3038 07FC [04] F01F      	MVF	STK01,1,0
3039 07FD [04] C604      	MVF	_UnitConverter_STK00,0,0
3040 07FE [04] F020      	MVF	STK00,1,0
3041 07FF [04] 6483      	MVF	r0x1181,0,0
3042                     _00361_DS_:
3043                     ;	;.line	411; ".\ADC_LCD.c"	}
3044 0800 [04] C4F9      	RET	
3045                     ; exit point of _UnitConverter
3046                     	.ENDFUNC	_UnitConverter
3047                     ;--------------------------------------------------------
3048                     
3049                     	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
3050                     	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
3051                     	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
3052                     	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
3053                     	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
3054                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
3055                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
3056                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
3057                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
3058                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
3059                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
3060                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
3061                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
3062                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
3063                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
3064                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
3065                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
3066                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
3067                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
3068                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
3069                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
3070                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
3071                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
3072                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
3073                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
3074                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
3075                     	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
3076                     	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
3077                     	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
3078                     	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
3079                     	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
3080                     	;--cdb--S:G$ShowADC$0$0({2}DF,SV:S),C,0,0
3081                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
3082                     	;--cdb--S:G$GPIO_Init$0$0({2}DF,SV:S),C,0,0
3083                     	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
3084                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
3085                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
3086                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
3087                     	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
3088                     	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
3089                     	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
3090                     	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
3091                     	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
3092                     	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
3093                     	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
3094                     	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
3095                     	;--cdb--S:G$adS$0$0({22}ST_adc_works_:S),E,0,0
3096                     	;--cdb--S:G$Flag$0$0({1}SC:U),E,0,0
3097                     	;--cdb--S:G$ADC$0$0({4}SL:SL),E,0,0
3098                     	;--cdb--S:G$MCUSTATUSbits$0$0({1}ST_MCUSTATUS:S),E,0,0
3099                     	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
3100                     	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
3101                     	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
3102                     	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
3103                     	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
3104                     	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
3105                     	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
3106                     	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
3107                     	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
3108                     	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
3109                     	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
3110                     	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
3111                     	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
3112                     	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
3113                     	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
3114                     	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
3115                     	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
3116                     	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
3117                     	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
3118                     	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
3119                     	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
3120                     	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
3121                     	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
3122                     	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
3123                     	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
3124                     	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
3125                     	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
3126                     	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
3127                     	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
3128                     	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
3129                     	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
3130                     	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
3131                     	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
3132                     	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
3133                     	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
3134                     	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
3135                     	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
3136                     	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
3137                     	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
3138                     	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
3139                     	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
3140                     	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
3141                     	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
3142                     	;--cdb--S:G$BIEARH$0$0({1}SC:U),I,0,0
3143                     	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
3144                     	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
3145                     	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
3146                     	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
3147                     	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
3148                     	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
3149                     	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
3150                     	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
3151                     	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
3152                     	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
3153                     	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
3154                     	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
3155                     	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
3156                     	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
3157                     	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
3158                     	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
3159                     	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
3160                     	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
3161                     	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
3162                     	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
3163                     	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
3164                     	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
3165                     	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
3166                     	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
3167                     	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
3168                     	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
3169                     	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
3170                     	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
3171                     	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
3172                     	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
3173                     	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
3174                     	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
3175                     	;--cdb--S:G$PT8$0$0({1}SC:U),I,0,0
3176                     	;--cdb--S:G$TRISC8$0$0({1}SC:U),I,0,0
3177                     	;--cdb--S:G$PT8PU$0$0({1}SC:U),I,0,0
3178                     	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
3179                     	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
3180                     	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
3181                     	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
3182                     	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
3183                     	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
3184                     	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
3185                     	;--cdb--S:G$LCDCN1$0$0({1}SC:U),I,0,0
3186                     	;--cdb--S:G$LCDCN2$0$0({1}SC:U),I,0,0
3187                     	;--cdb--S:G$LCDCN3$0$0({1}SC:U),I,0,0
3188                     	;--cdb--S:G$LCDCN4$0$0({1}SC:U),I,0,0
3189                     	;--cdb--S:G$LCD0$0$0({1}SC:U),I,0,0
3190                     	;--cdb--S:G$LCD1$0$0({1}SC:U),I,0,0
3191                     	;--cdb--S:G$LCD2$0$0({1}SC:U),I,0,0
3192                     	;--cdb--S:G$LCD3$0$0({1}SC:U),I,0,0
3193                     	;--cdb--S:G$LCD4$0$0({1}SC:U),I,0,0
3194                     	;--cdb--S:G$LCD5$0$0({1}SC:U),I,0,0
3195                     	;--cdb--S:G$LCD6$0$0({1}SC:U),I,0,0
3196                     	;--cdb--S:G$Filter$0$0({1}SC:U),I,0,0
3197                     	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
3198                     	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
3199                     	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
3200                     	;--cdb--S:LADC_LCD.main._main_LCDDisplay_65536_37$LCDDisplay$10000$37({4}SF:S),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
3201                     	;--cdb--S:LADC_LCD.main._main_delta_65536_37$delta$10000$37({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1146,r0x1147]
3202                     	;--cdb--S:LADC_LCD.main._main_theta_65536_37$theta$10000$37({4}SL:SL),R,0,0,[r0x1144,r0x1145,r0x1146,r0x1147]
3203                     	;--cdb--S:LADC_LCD.main._main_n_65536_37$n$10000$37({4}SL:SL),R,0,0,[]
3204                     	;--cdb--S:LADC_LCD.UnitConverter._UnitConverter_data_65536_65$data$10000$65({4}SL:SL),R,0,0,[_UnitConverter_STK02,_UnitConverter_STK01,_UnitConverter_STK00,r0x1181]
3205                     	;--cdb--S:LADC_LCD.LowVoltageDetect_3V._LowVoltageDetect_3V_flag_65536_73$flag$10000$73({1}SC:U),R,0,0,[r0x118A]
3206                     	;--cdb--S:LADC_LCD.LowVoltageDetect_2V4._LowVoltageDetect_2V4_flag_65536_77$flag$10000$77({1}SC:U),R,0,0,[r0x118B]
3207                     	;--cdb--S:LADC_LCD.PositivePressureWorks_Mode._PositivePressureWorks_Mode_delta_65536_108$delta$10000$108({4}SL:SL),R,0,0,[r0x1197,r0x1198,r0x1199,r0x119A]
3208                     	;--cdb--S:LADC_LCD.PositivePressureWorks_Mode._PositivePressureWorks_Mode_LCDDisplay_65536_108$LCDDisplay$10000$108({4}SL:SL),R,0,0,[r0x1197,r0x1198,r0x1199,r0x119A]
3209                     	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_theta_65536_116$theta$10000$116({4}SL:SL),R,0,0,[r0x11B3,r0x11B4,r0x11B5,r0x11B6]
3210                     	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_omega_65536_116$omega$10000$116({4}SL:SL),R,0,0,[r0x11AF,r0x11B0,r0x11B1,r0x11B2]
3211                     	;--cdb--S:LADC_LCD.NegativePressureWorks_Mode._NegativePressureWorks_Mode_LCDDisplay_65536_116$LCDDisplay$10000$116({4}SL:SL),R,0,0,[r0x11AF,r0x11B0,r0x11B1,r0x11B2]
3212                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
3213                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
3214                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
3215                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
3216                     	;--cdb--S:G$SetupZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
3217                     	;--cdb--S:G$SetupUnit_Mode$0$0({2}DF,SV:S),C,0,0
3218                     	;--cdb--S:G$PositivePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
3219                     	;--cdb--S:G$NegativePressureWorks_Mode$0$0({2}DF,SV:S),C,0,0
3220                     	;--cdb--S:G$SetupUnitAndZeroPoint_Mode$0$0({2}DF,SV:S),C,0,0
3221                     	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
3222                     	;--cdb--S:G$_PCLATH$0$0({0}:U),Z,0,0
3223                     	;--cdb--S:G$_PCLATL$0$0({0}:U),Z,0,0
3224                     	;--cdb--S:G$_WREG$0$0({0}:U),Z,0,0
3225                     	;--cdb--S:G$_INTE0$0$0({0}:U),Z,0,0
3226                     ;--------------------------------------------------------
3227                     ; external declarations
3228                     ;--------------------------------------------------------
3229                     	.globl	_ADC_Open
3230                     	.globl	_ADC_GetData
3231                     	.globl	_Display2Er
3232                     	.globl	_DisplayUnit
3233                     	.globl	_Delay
3234                     	.globl	_GPIO_Iint
3235                     	.globl	_Reverse_Data
3236                     	.globl	_DisplayBatteryCapacityFull
3237                     	.globl	_DisplayBatteryCapacityHalf
3238                     	.globl	_DispalyBatteryCapacityLow
3239                     	.globl	_HY17P52WR3
3240                     	.globl	_PGAandADCAccuracyMode
3241                     	.globl	_DisplayNum
3242                     	.globl	___slong2fs
3243                     	.globl	___fsmul
3244                     	.globl	___fs2slong
3245                     	.globl	___fssub
3246                     	.globl	___fsadd
3247                     	.globl	__mullong
3248                     	.globl	_FSR0
3249                     	.globl	_FSR1
3250                     	.globl	_FSR2
3251                     	.globl	_ADCR
3252                     	.globl	_adS
3253                     	.globl	__sdcc_gsinit_startup256fsr2
3254                     ;--------------------------------------------------------
3255                     ; global -1 declarations
3256                     ;--------------------------------------------------------
3257                     	.globl	_LowVoltageDisplay
3258                     	.globl	_LowVoltageDetect_2V4
3259                     	.globl	_LowVoltageDetect_3V
3260                     	.globl	_UnitConverter
3261                     	.globl	_Flag
3262                     	.globl	_ADC
3263                     	.globl	_MCUSTATUSbits
3264                     
3265                     	.globl WSAVE
3266                     	.globl STK07
3267                     	.globl STK07_SAVE
3268                     	.globl STK06
3269                     	.globl STK06_SAVE
3270                     	.globl STK05
3271                     	.globl STK05_SAVE
3272                     	.globl STK04
3273                     	.globl STK04_SAVE
3274                     	.globl STK03
3275                     	.globl STK03_SAVE
3276                     	.globl STK02
3277                     	.globl STK02_SAVE
3278                     	.globl STK01
3279                     	.globl STK01_SAVE
3280                     	.globl STK00
3281                     	.globl STK00_SAVE
3282                     	.globl _FSR0L_SAVE
3283                     	.globl _FSR0H_SAVE
3284                     	.globl _FSR1L_SAVE
3285                     	.globl _FSR1H_SAVE
3286                     	.globl _FSR2L_SAVE
3287                     	.globl _FSR2H_SAVE
3288                     	.globl	_TBLPTRH_SAVE
3289                     
3290                     .area UDATA (DATA,REL,CON)
3291                     STK07:	.ds	 1
3292                     STK06:	.ds	 1
3293                     STK05:	.ds	 1
3294                     STK04:	.ds	 1
3295 0160 --             STK03:	.ds	 1
3296                     STK02:	.equ	 0x1E
3297                     STK01:	.equ	 0x1F
3298                     STK00:	.equ	 0x20
3299                     WSAVE:	.ds 1
3300                     STK07_SAVE:	.ds	 1
3301                     STK06_SAVE:	.ds	 1
3302                     STK05_SAVE:	.ds	 1
3303                     STK04_SAVE:	.ds	 1
3304                     STK03_SAVE:	.ds	 1
3305 0161 --             STK02_SAVE:	.ds	 1
3306 0162 --             STK01_SAVE:	.ds	 1
3307 0163 --             STK00_SAVE:	.ds	 1
3308                     _FSR0L_SAVE:	.ds	 1
3309                     _FSR0H_SAVE:	.ds	 1
3310                     _FSR1L_SAVE:	.ds	 1
3311                     _FSR1H_SAVE:	.ds	 1
3312                     _FSR2L_SAVE:	.ds	 1
3313                     _FSR2H_SAVE:	.ds	 1
3314                     _TBLPTRH_SAVE:	.ds	 1
3315                     
3316                     	.globl	_memcpy
3317                     ;--------------------------------------------------------
3318                     ; global -2 definitions
3319                     ;--------------------------------------------------------
3320                     	.area DSEG(DATA)
3321 0164 --             _Flag:	.ds	1
3322                     
3323                     	.area DSEG(DATA)
3324 0165 -- -- -- --    _ADC:	.ds	4
3325                     
3326                     	.area DSEG(DATA)
3327 0169 --             _MCUSTATUSbits:	.ds	1
3328                     
3329                     	.area DSEG(DATA)
3330                     __SWTGTID	.equ	0xA43354DA
3331                     
3332                     	.area DSEG(DATA)
3333                     _INDF0	.equ	0x0
3334                     
3335                     	.area DSEG(DATA)
3336                     _POINC0	.equ	0x1
3337                     
3338                     	.area DSEG(DATA)
3339                     _PODEC0	.equ	0x2
3340                     
3341                     	.area DSEG(DATA)
3342                     _PRINC0	.equ	0x3
3343                     
3344                     	.area DSEG(DATA)
3345                     _PLUSW0	.equ	0x4
3346                     
3347                     	.area DSEG(DATA)
3348                     _INDF1	.equ	0x5
3349                     
3350                     	.area DSEG(DATA)
3351                     _POINC1	.equ	0x6
3352                     
3353                     	.area DSEG(DATA)
3354                     _PODEC1	.equ	0x7
3355                     
3356                     	.area DSEG(DATA)
3357                     _PRINC1	.equ	0x8
3358                     
3359                     	.area DSEG(DATA)
3360                     _PLUSW1	.equ	0x9
3361                     
3362                     	.area DSEG(DATA)
3363                     _INDF2	.equ	0xA
3364                     
3365                     	.area DSEG(DATA)
3366                     _POINC2	.equ	0xB
3367                     
3368                     	.area DSEG(DATA)
3369                     _PODEC2	.equ	0xC
3370                     
3371                     	.area DSEG(DATA)
3372                     _PRINC2	.equ	0xD
3373                     
3374                     	.area DSEG(DATA)
3375                     _PLUSW2	.equ	0xE
3376                     
3377                     	.area DSEG(DATA)
3378                     _FSR0H	.equ	0xF
3379                     
3380                     	.area DSEG(DATA)
3381                     _FSR0L	.equ	0x10
3382                     
3383                     	.area DSEG(DATA)
3384                     _FSR1H	.equ	0x11
3385                     
3386                     	.area DSEG(DATA)
3387                     _FSR1L	.equ	0x12
3388                     
3389                     	.area DSEG(DATA)
3390                     _FSR2H	.equ	0x13
3391                     
3392                     	.area DSEG(DATA)
3393                     _FSR2L	.equ	0x14
3394                     
3395                     	.area DSEG(DATA)
3396                     _TOSH	.equ	0x16
3397                     
3398                     	.area DSEG(DATA)
3399                     _TOSL	.equ	0x17
3400                     
3401                     	.area DSEG(DATA)
3402                     _SKCN	.equ	0x18
3403                     
3404                     	.area DSEG(DATA)
3405                     _PCLATH	.equ	0x1A
3406                     
3407                     	.area DSEG(DATA)
3408                     _PCLATL	.equ	0x1B
3409                     
3410                     	.area DSEG(DATA)
3411                     _TBLPTRH	.equ	0x1D
3412                     
3413                     	.area DSEG(DATA)
3414                     _TBLPTRL	.equ	0x1E
3415                     
3416                     	.area DSEG(DATA)
3417                     _TBLDH	.equ	0x1F
3418                     
3419                     	.area DSEG(DATA)
3420                     _TBLDL	.equ	0x20
3421                     
3422                     	.area DSEG(DATA)
3423                     _PRODH	.equ	0x21
3424                     
3425                     	.area DSEG(DATA)
3426                     _PRODL	.equ	0x22
3427                     
3428                     	.area DSEG(DATA)
3429                     _INTE0	.equ	0x23
3430                     
3431                     	.area DSEG(DATA)
3432                     _INTE1	.equ	0x24
3433                     
3434                     	.area DSEG(DATA)
3435                     _INTF0	.equ	0x26
3436                     
3437                     	.area DSEG(DATA)
3438                     _INTF1	.equ	0x27
3439                     
3440                     	.area DSEG(DATA)
3441                     _WREG	.equ	0x29
3442                     
3443                     	.area DSEG(DATA)
3444                     _BSRCN	.equ	0x2A
3445                     
3446                     	.area DSEG(DATA)
3447                     _STATUS	.equ	0x2B
3448                     
3449                     	.area DSEG(DATA)
3450                     _MSTAT	.equ	0x2B
3451                     
3452                     	.area DSEG(DATA)
3453                     _PSTAT	.equ	0x2C
3454                     
3455                     	.area DSEG(DATA)
3456                     _BIECN	.equ	0x2E
3457                     
3458                     	.area DSEG(DATA)
3459                     _BIEARH	.equ	0x2F
3460                     
3461                     	.area DSEG(DATA)
3462                     _BIEARL	.equ	0x30
3463                     
3464                     	.area DSEG(DATA)
3465                     _BIEDRH	.equ	0x31
3466                     
3467                     	.area DSEG(DATA)
3468                     _BIEDRL	.equ	0x32
3469                     
3470                     	.area DSEG(DATA)
3471                     _PWRCN	.equ	0x33
3472                     
3473                     	.area DSEG(DATA)
3474                     _OSCCN0	.equ	0x34
3475                     
3476                     	.area DSEG(DATA)
3477                     _OSCCN1	.equ	0x35
3478                     
3479                     	.area DSEG(DATA)
3480                     _OSCCN2	.equ	0x36
3481                     
3482                     	.area DSEG(DATA)
3483                     _CSFCN0	.equ	0x37
3484                     
3485                     	.area DSEG(DATA)
3486                     _CSFCN1	.equ	0x38
3487                     
3488                     	.area DSEG(DATA)
3489                     _WDTCN	.equ	0x39
3490                     
3491                     	.area DSEG(DATA)
3492                     _AD1H	.equ	0x3A
3493                     
3494                     	.area DSEG(DATA)
3495                     _AD1M	.equ	0x3B
3496                     
3497                     	.area DSEG(DATA)
3498                     _AD1L	.equ	0x3C
3499                     
3500                     	.area DSEG(DATA)
3501                     _AD1CN0	.equ	0x3D
3502                     
3503                     	.area DSEG(DATA)
3504                     _AD1CN1	.equ	0x3E
3505                     
3506                     	.area DSEG(DATA)
3507                     _AD1CN2	.equ	0x3F
3508                     
3509                     	.area DSEG(DATA)
3510                     _AD1CN3	.equ	0x40
3511                     
3512                     	.area DSEG(DATA)
3513                     _AD1CN4	.equ	0x41
3514                     
3515                     	.area DSEG(DATA)
3516                     _AD1CN5	.equ	0x42
3517                     
3518                     	.area DSEG(DATA)
3519                     _LVDCN	.equ	0x43
3520                     
3521                     	.area DSEG(DATA)
3522                     _TMA1CN	.equ	0x44
3523                     
3524                     	.area DSEG(DATA)
3525                     _TMA1R	.equ	0x45
3526                     
3527                     	.area DSEG(DATA)
3528                     _TMA1C	.equ	0x46
3529                     
3530                     	.area DSEG(DATA)
3531                     _PT1	.equ	0x47
3532                     
3533                     	.area DSEG(DATA)
3534                     _TRISC1	.equ	0x48
3535                     
3536                     	.area DSEG(DATA)
3537                     _PT1DA	.equ	0x49
3538                     
3539                     	.area DSEG(DATA)
3540                     _PT1PU	.equ	0x4A
3541                     
3542                     	.area DSEG(DATA)
3543                     _PT1M1	.equ	0x4B
3544                     
3545                     	.area DSEG(DATA)
3546                     _PT2	.equ	0x4C
3547                     
3548                     	.area DSEG(DATA)
3549                     _TRISC2	.equ	0x4D
3550                     
3551                     	.area DSEG(DATA)
3552                     _PT2DA	.equ	0x4E
3553                     
3554                     	.area DSEG(DATA)
3555                     _PT2PU	.equ	0x4F
3556                     
3557                     	.area DSEG(DATA)
3558                     _PT8	.equ	0x50
3559                     
3560                     	.area DSEG(DATA)
3561                     _TRISC8	.equ	0x51
3562                     
3563                     	.area DSEG(DATA)
3564                     _PT8PU	.equ	0x53
3565                     
3566                     	.area DSEG(DATA)
3567                     _UR0CN	.equ	0x54
3568                     
3569                     	.area DSEG(DATA)
3570                     _UR0STA	.equ	0x55
3571                     
3572                     	.area DSEG(DATA)
3573                     _BA0CN	.equ	0x56
3574                     
3575                     	.area DSEG(DATA)
3576                     _BG0RH	.equ	0x57
3577                     
3578                     	.area DSEG(DATA)
3579                     _BG0RL	.equ	0x58
3580                     
3581                     	.area DSEG(DATA)
3582                     _TX0R	.equ	0x59
3583                     
3584                     	.area DSEG(DATA)
3585                     _RC0REG	.equ	0x5A
3586                     
3587                     	.area DSEG(DATA)
3588                     _LCDCN1	.equ	0x5B
3589                     
3590                     	.area DSEG(DATA)
3591                     _LCDCN2	.equ	0x5C
3592                     
3593                     	.area DSEG(DATA)
3594                     _LCDCN3	.equ	0x5D
3595                     
3596                     	.area DSEG(DATA)
3597                     _LCDCN4	.equ	0x5E
3598                     
3599                     	.area DSEG(DATA)
3600                     _LCD0	.equ	0x5F
3601                     
3602                     	.area DSEG(DATA)
3603                     _LCD1	.equ	0x60
3604                     
3605                     	.area DSEG(DATA)
3606                     _LCD2	.equ	0x61
3607                     
3608                     	.area DSEG(DATA)
3609                     _LCD3	.equ	0x62
3610                     
3611                     	.area DSEG(DATA)
3612                     _LCD4	.equ	0x63
3613                     
3614                     	.area DSEG(DATA)
3615                     _LCD5	.equ	0x64
3616                     
3617                     	.area DSEG(DATA)
3618                     _LCD6	.equ	0x65
3619                     
3620                     	.area DSEG(DATA)
3621                     _Filter	.equ	0x66
3622                     
3623                     	.area DSEG(DATA)
3624                     _ADCRH	.equ	0x3A
3625                     
3626                     	.area DSEG(DATA)
3627                     _ADCRM	.equ	0x3B
3628                     
3629                     	.area DSEG(DATA)
3630                     _ADCRL	.equ	0x3C
3631                     
3632                     ;--------------------------------------------------------
3633                     ; absolute symbol definitions
3634                     ;--------------------------------------------------------
3635                     ;--------------------------------------------------------
3636                     ; compiler-defined variables
3637                     ;--------------------------------------------------------
3638                     	.area IDATA (DATA,REL,CON); pre-def
3639                     	.area IDATAROM (CODE,REL,CON); pre-def
3640                     	.area UDATA (DATA,REL,CON); pre-def
3641                     	.area UDATA (DATA,REL,CON) ;UDL_ADC_LCD_0	udata
3642 @FSR2-01 --         r0x1140:	.ds	1
3643 @FSR2-02 --         r0x1141:	.ds	1
3644 @FSR2-04 --         r0x1142:	.ds	1
3645 @FSR2-03 --         r0x1143:	.ds	1
3646 @FSR2-05 --         r0x1144:	.ds	1
3647 @FSR2-06 --         r0x1145:	.ds	1
3648 @FSR2-07 --         r0x1146:	.ds	1
3649 @FSR2-08 --         r0x1147:	.ds	1
3650 @FSR2-09 --         r0x1148:	.ds	1
3651 @FSR2-10 --         r0x1149:	.ds	1
3652 @FSR2-12 --         r0x114C:	.ds	1
3653 @FSR2-11 --         r0x114D:	.ds	1
3654 @FSR2-01 --         r0x1181:	.ds	1
3655 @FSR2-02 --         r0x1182:	.ds	1
3656 @FSR2-04 --         r0x1185:	.ds	1
3657 @FSR2-03 --         r0x1186:	.ds	1
3658 @FSR2-01 --         r0x118A:	.ds	1
3659 @FSR2-01 --         r0x118B:	.ds	1
3660 @FSR2-01 --         r0x118C:	.ds	1
3661 0003 --             r0x118D:	.ds	1
3662 0002 --             r0x118E:	.ds	1
3663 0001 --             r0x118F:	.ds	1
3664 0000 --             r0x1190:	.ds	1
3665 0004 --             r0x1191:	.ds	1
3666 0005 --             r0x1192:	.ds	1
3667 0000 --             r0x1195:	.ds	1
3668 @FSR2-01 --         r0x1197:	.ds	1
3669 @FSR2-02 --         r0x1198:	.ds	1
3670 @FSR2-03 --         r0x1199:	.ds	1
3671 @FSR2-04 --         r0x119A:	.ds	1
3672 @FSR2-05 --         r0x119B:	.ds	1
3673 @FSR2-06 --         r0x119C:	.ds	1
3674 @FSR2-07 --         r0x119D:	.ds	1
3675 @FSR2-08 --         r0x119E:	.ds	1
3676 @FSR2-10 --         r0x119F:	.ds	1
3677 @FSR2-09 --         r0x11A0:	.ds	1
3678 @FSR2-11 --         r0x11A2:	.ds	1
3679 @FSR2-13 --         r0x11A3:	.ds	1
3680 @FSR2-12 --         r0x11A4:	.ds	1
3681 0000 --             r0x11AF:	.ds	1
3682 0001 --             r0x11B0:	.ds	1
3683 0002 --             r0x11B1:	.ds	1
3684 0003 --             r0x11B2:	.ds	1
3685 0004 --             r0x11B3:	.ds	1
3686 0005 --             r0x11B4:	.ds	1
3687 0006 --             r0x11B5:	.ds	1
3688 0007 --             r0x11B6:	.ds	1
3689 0008 --             r0x11B7:	.ds	1
3690 0009 --             r0x11B8:	.ds	1
3691 000A --             r0x11B9:	.ds	1
3692 000B --             r0x11BA:	.ds	1
3693 000D --             r0x11BB:	.ds	1
3694 000C --             r0x11BC:	.ds	1
3695 000E --             r0x11BE:	.ds	1
3696 0010 --             r0x11BF:	.ds	1
3697 000F --             r0x11C0:	.ds	1
3698 0000 --             r0x11C1:	.ds	1
3699 @FSR2-01 --         r0x11C3:	.ds	1
3700                     	.area LOCALSTK (STK); local stack var
3701                     	.globl _ADC_Open_STK10
3702                     	.globl _ADC_Open_STK09
3703                     	.globl _ADC_Open_STK08
3704                     	.globl _ADC_Open_STK07
3705                     	.globl _ADC_Open_STK06
3706                     	.globl _ADC_Open_STK05
3707                     	.globl _ADC_Open_STK04
3708                     	.globl _ADC_Open_STK03
3709                     	.globl _ADC_Open_STK02
3710                     	.globl _ADC_Open_STK01
3711                     	.globl _ADC_Open_STK00
3712                     	.globl ___slong2fs_STK02
3713                     	.globl ___slong2fs_STK01
3714                     	.globl ___slong2fs_STK00
3715                     	.globl ___fsmul_STK06
3716                     	.globl ___fsmul_STK05
3717                     	.globl ___fsmul_STK04
3718                     	.globl ___fsmul_STK03
3719                     	.globl ___fsmul_STK02
3720                     	.globl ___fsmul_STK01
3721                     	.globl ___fsmul_STK00
3722                     	.globl ___fs2slong_STK02
3723                     	.globl ___fs2slong_STK01
3724                     	.globl ___fs2slong_STK00
3725                     	.globl _Delay_STK00
3726                     	.globl ___fssub_STK06
3727                     	.globl ___fssub_STK05
3728                     	.globl ___fssub_STK04
3729                     	.globl ___fssub_STK03
3730                     	.globl ___fssub_STK02
3731                     	.globl ___fssub_STK01
3732                     	.globl ___fssub_STK00
3733                     	.globl _DisplayNum_STK02
3734                     	.globl _DisplayNum_STK01
3735                     	.globl _DisplayNum_STK00
3736                     	.globl ___fsadd_STK06
3737                     	.globl ___fsadd_STK05
3738                     	.globl ___fsadd_STK04
3739                     	.globl ___fsadd_STK03
3740                     	.globl ___fsadd_STK02
3741                     	.globl ___fsadd_STK01
3742                     	.globl ___fsadd_STK00
3743                     	.globl _HY17P52WR3_STK01
3744                     	.globl _HY17P52WR3_STK00
3745 @FSR2-00 --         _UnitConverter_STK00:	.ds	1
3746                     	.globl _UnitConverter_STK00
3747 @FSR2+01 --         _UnitConverter_STK01:	.ds	1
3748                     	.globl _UnitConverter_STK01
3749 @FSR2+02 --         _UnitConverter_STK02:	.ds	1
3750                     	.globl _UnitConverter_STK02
3751                     	.globl __mullong_STK06
3752                     	.globl __mullong_STK05
3753                     	.globl __mullong_STK04
3754                     	.globl __mullong_STK03
3755                     	.globl __mullong_STK02
3756                     	.globl __mullong_STK01
3757                     	.globl __mullong_STK00
3758                     	.globl _Reverse_Data_STK02
3759                     	.globl _Reverse_Data_STK01
3760                     	.globl _Reverse_Data_STK00
3761                     ;--------------------------------------------------------
3762                     ; initialized data
3763                     ;--------------------------------------------------------
3764                     ;--------------------------------------------------------
3765                     ; initialized data - mirror
3766                     ;--------------------------------------------------------
3767                     	;Following is optimization info, 
3768                     	;xxcdbxxW:dst:src+offset:srclit:just-remove
3769                     	;--cdb--W:r0x11C2:NULL+0:-1:1
3770                     	;--cdb--W:r0x11C1:NULL+0:-1:1
3771                     	;--cdb--W:r0x11AF:NULL+0:-1:1
3772                     	;--cdb--W:r0x11B0:NULL+0:-1:1
3773                     	;--cdb--W:r0x11B1:NULL+0:-1:1
3774                     	;--cdb--W:r0x11B4:NULL+0:-1:1
3775                     	;--cdb--W:r0x11B3:NULL+0:-1:1
3776                     	;--cdb--W:r0x11B7:NULL+0:-1:1
3777                     	;--cdb--W:r0x11BB:NULL+0:-1:1
3778                     	;--cdb--W:r0x11AF:STK02+0:-1:0
3779                     	;--cdb--W:r0x11B0:STK01+0:-1:0
3780                     	;--cdb--W:r0x11B1:STK00+0:-1:0
3781                     	;--cdb--W:r0x11B4:NULL+0:0:0
3782                     	;--cdb--W:r0x11B7:r0x11B8+0:-1:0
3783                     	;--cdb--W:r0x11B9:NULL+0:0:0
3784                     	;--cdb--W:r0x11BD:NULL+0:0:0
3785                     	;--cdb--W:r0x11B9:NULL+0:-1:1
3786                     	;--cdb--W:r0x11BD:NULL+0:-1:1
3787                     	;--cdb--W:r0x1198:NULL+0:-1:1
3788                     	;--cdb--W:r0x1197:NULL+0:-1:1
3789                     	;--cdb--W:r0x119B:NULL+0:-1:1
3790                     	;--cdb--W:r0x119F:NULL+0:-1:1
3791                     	;--cdb--W:r0x1197:STK02+0:-1:0
3792                     	;--cdb--W:r0x1198:NULL+0:0:0
3793                     	;--cdb--W:r0x1198:STK01+0:-1:0
3794                     	;--cdb--W:r0x1199:STK00+0:-1:0
3795                     	;--cdb--W:r0x119B:r0x119C+0:-1:0
3796                     	;--cdb--W:r0x119D:NULL+0:0:0
3797                     	;--cdb--W:r0x11A0:STK01+0:-1:0
3798                     	;--cdb--W:r0x119F:STK02+0:-1:0
3799                     	;--cdb--W:r0x11A1:NULL+0:0:0
3800                     	;--cdb--W:r0x11A1:STK00+0:-1:0
3801                     	;--cdb--W:r0x119D:NULL+0:-1:1
3802                     	;--cdb--W:r0x11A1:NULL+0:-1:1
3803                     	;--cdb--W:r0x1195:NULL+0:-1:1
3804                     	;--cdb--W:r0x1196:NULL+0:-1:1
3805                     	;--cdb--W:r0x1196:NULL+0:0:0
3806                     	;--cdb--W:r0x118D:NULL+0:-1:1
3807                     	;--cdb--W:r0x118F:NULL+0:-1:1
3808                     	;--cdb--W:r0x1190:NULL+0:-1:1
3809                     	;--cdb--W:r0x1191:NULL+0:-1:1
3810                     	;--cdb--W:r0x1192:NULL+0:-1:1
3811                     	;--cdb--W:r0x118F:STK00+0:-1:0
3812                     	;--cdb--W:r0x118E:STK01+0:-1:0
3813                     	;--cdb--W:r0x1191:r0x118D+0:-1:0
3814                     	;--cdb--W:r0x1192:r0x118E+1:-1:0
3815                     	;--cdb--W:r0x1193:r0x118D+0:-1:0
3816                     	;--cdb--W:r0x1194:r0x118E+1:-1:0
3817                     	;--cdb--W:r0x118E:NULL+0:-1:1
3818                     	;--cdb--W:r0x118B:NULL+0:-1:1
3819                     	;--cdb--W:r0x118A:NULL+0:-1:1
3820                     	;--cdb--W:r0x1183:NULL+0:-1:1
3821                     	;--cdb--W:r0x1182:NULL+0:-1:1
3822                     	;--cdb--W:r0x1183:NULL+0:0:0
3823                     	;--cdb--W:r0x1183:STK01+0:-1:0
3824                     	;--cdb--W:r0x1185:STK00+0:-1:0
3825                     	;--cdb--W:r0x1184:STK01+0:-1:0
3826                     	;--cdb--W:r0x1184:STK00+0:-1:0
3827                     	;--cdb--W:r0x1186:NULL+0:-1:1
3828                     	;--cdb--W:r0x1185:NULL+0:-1:1
3829                     	;--cdb--W:r0x1140:NULL+0:-1:1
3830                     	;--cdb--W:r0x1141:NULL+0:-1:1
3831                     	;--cdb--W:r0x1142:NULL+0:-1:1
3832                     	;--cdb--W:r0x1143:NULL+0:-1:1
3833                     	;--cdb--W:r0x1144:NULL+0:-1:1
3834                     	;--cdb--W:r0x1145:NULL+0:-1:1
3835                     	;--cdb--W:r0x1140:STK02+0:-1:0
3836                     	;--cdb--W:r0x1141:STK01+0:-1:0
3837                     	;--cdb--W:r0x1141:NULL+0:0:0
3838                     	;--cdb--W:r0x1142:STK00+0:-1:0
3839                     	;--cdb--W:r0x1144:r0x1140+0:-1:0
3840                     	;--cdb--W:r0x1145:r0x1141+1:-1:0
3841                     	;--cdb--W:r0x1146:r0x1140+0:-1:0
3842                     	;--cdb--W:r0x1146:NULL+0:0:0
3843                     	;--cdb--W:r0x1147:r0x1141+1:-1:0
3844                     	;--cdb--W:r0x1147:NULL+0:0:0
3845                     	;--cdb--W:r0x1146:NULL+0:-1:1
3846                     	;--cdb--W:r0x1147:NULL+0:-1:1
3847                     	;--cdb--W:r0x11C3:NULL+0:-1:1
3848                     	;--cdb--W:r0x11C4:NULL+0:-1:1
3849                     	end
