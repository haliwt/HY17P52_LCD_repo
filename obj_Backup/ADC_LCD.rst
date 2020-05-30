001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
008                     ;;	.file	".\ADC_LCD.c"
009                     	.module ADC_LCD
010                     	;.list	p=HY17P52
011                     	;--cdb--T:FADC_LCD$_MCUSTATUS[({0}S:S$_byte$0$0({1}SC:U),Z,0,0)({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
012                     	;--cdb--T:FADC_LCD$__00000000[({0}S:S$b_ADCdone$0$0({1}SB0$1:U),Z,0,0)]
013                     	;--cdb--T:FADC_LCD$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_high_bit$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_low_bit$0$0({1}SC:U),Z,0,0)({9}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({10}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({12}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
014                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
015                     	;--cdb--F:ADC_LCD:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0,0,0,0
016                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
017                     	;--cdb--F:ADC_LCD:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0,0,0,0
018                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
019                     	;--cdb--F:ADC_LCD:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0,0,0,0
020                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
021                     	;--cdb--F:ADC_LCD:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0,0,0,0
022                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
023                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
024                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
025                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
026                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
027                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
028                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
029                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
030                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
031                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
032                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
033                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
034                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
035                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
036                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
037                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
038                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
039                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
040                     	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
041                     	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
042                     	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
043                     	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
044                     	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
045                     	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
046                     	;--cdb--F:ADC_LCD:G$main$0$0({2}DF,SV:S),C,0,0,0,0,0
047                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
048                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
049                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
050                     	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
051                     	;--cdb--S:G$__fslt$0$0({2}DF,SC:U),C,0,0
052                     	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
053                     	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
054                     	;--cdb--F:ADC_LCD:G$ISR$0$0({2}DF,SV:S),C,0,0,1,256,0
055                     ;--------------------------------------------------------
056                     ; overlayable items in internal ram 
057                     ;--------------------------------------------------------
058                     ;	udata_ovr
059                     	.globl _main
060                     ;--------------------------------------------------------
061                     ; reset vector 
062                     ;--------------------------------------------------------
063                     	.area STARTUP	(code,REL,CON) 
064 0000 0000           	nop
065 0001 C200 FD45      	jmp	__sdcc_gsinit_startup256fsr2
066 0003 0000           	nop
067                     ;--------------------------------------------------------
068                     ; interrupt and initialization code
069                     ;--------------------------------------------------------
070                     	.area c_interrupt	(code,REL,CON)
071                     __sdcc_interrupt:
072                     .globl _ISR
073                     
074                     ;--------------------------------------------------------
075                     	.FUNC _ISR:0:$C:_ADC_GetData\
076                     
077                     ;--------------------------------------------------------
078                     ;	;.line	572; ".\ADC_LCD.c"	if(ADIF_IsFlag()&&(adS.Presskey_flag !=1))
079 0004 [00] D020 F16B 
079 0006 D01F F16A D01E 
079 0009 F169 0011      _ISR:	;Function start
080 000B [00] AA26      	BTSZ	_INTF0,5
081 000C [00] AB78      	BTSZ	(_adS+6),5
082 000D [00] 780B      	JMP	_00461_DS_
083                     ;	;.line	574; ".\ADC_LCD.c"	ADIF_ClearFlag();
084 000E [00] 8A26      	BCF	_INTF0,5
085                     ;	;.line	575; ".\ADC_LCD.c"	ADC=ADC_GetData();
086 000F [00] C86B 0011 	CALL	_ADC_GetData
087                     	.CHKPARA _ADC_GetData 0
088 0011 [00] 6770      	MVF	(_ADC + 3),1,0
089 0012 [00] D020      	MVF	STK00,0,0
090 0013 [00] F16F      	MVF	(_ADC + 2),1,0
091 0014 [00] D01F      	MVF	STK01,0,0
092 0015 [00] F16E      	MVF	(_ADC + 1),1,0
093 0016 [00] 641E      	MVF	STK02,0,0
094 0017 [00] 676D      	MVF	_ADC,1,0
095                     ;	;.line	576; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=1;
096 0018 [00] 9171      	BSF	_MCUSTATUSbits,0
097 0019 [00] D16B F020 
097 001B D16A F01F D169 
097 001E F01E           _00461_DS_:
098                     ;	;.line	580; ".\ADC_LCD.c"	}
099 001F [00] 0009      	RETI	 1
100                     ; exit point of _ISR
101                     	.ENDFUNC	_ISR
102                     ;--------------------------------------------------------
103                     
104                     .area CCODE (code,REL,CON) ; ADC_LCD-code 
105                     .globl _main
106                     
107                     ;--------------------------------------------------------
108                     	.FUNC _main:0:$C:_GPIO_Iint:$C:_ADC_Open:$C:_PGAandADCAccuracyMode:$C:_Delay\
109                     :$C:_Display2Er:$C:_DisplayUnit:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
110                     :$C:___fssub:$C:_DisplayNum:$C:___fslt:$C:_Reverse_Data:$C:_UnitConverter\
111                     :$C:_LowVoltageDisplay:$C:___fsadd:$C:_HY17P52WR3\
112                     :$L:r0x1140:$L:r0x1143:$L:r0x1142:$L:r0x1141:$L:r0x1147\
113                     :$L:r0x1146:$L:r0x1145:$L:r0x1144:$L:r0x114B:$L:r0x114A\
114                     :$L:r0x1149:$L:r0x1148:$L:r0x114D:$L:r0x114C
115                     ;--------------------------------------------------------
116                     ;	;.line	93; ".\ADC_LCD.c"	CLK_OSCSelect(OSCS_HAO); //OSCS_HAO = 3.686MHz
117 01AD [00] C48E      _main:	;Function start
118 01AE [14] 9E35      	BSF	0x35,7
119 01AF [14] 063F      	MVL	0x3f
120 01B0 [14] 2A34      	ANDF	_OSCCN0,1,0
121                     ;	;.line	94; ".\ADC_LCD.c"	CLK_CPUCK_Sel(DHS_HSCKDIV1,CPUS_HSCK); //fre = 3.686Mhz /2 =1.843Mhz
122 01B1 [14] 06CE      	MVL	0xce
123 01B2 [14] 2A34      	ANDF	_OSCCN0,1,0
124                     ;	;.line	95; ".\ADC_LCD.c"	GPIO_Iint() ;
125 01B3 [14] CF23      	CALL	_GPIO_Iint
126                     	.CHKPARA _GPIO_Iint 0
127                     ;	;.line	98; ".\ADC_LCD.c"	PWR_BGREnable();
128 01B4 [14] 9E33      	BSF	_PWRCN,7
129                     ;	;.line	99; ".\ADC_LCD.c"	PWR_LDOPLEnable();
130 01B5 [14] 9842      	BSF	_AD1CN5,4
131                     ;	;.line	100; ".\ADC_LCD.c"	PWR_LDOEnable();
132 01B6 [14] 9233      	BSF	_PWRCN,1
133                     ;	;.line	101; ".\ADC_LCD.c"	PWR_LDOSel(LDOC_2V4);
134 01B7 [14] 068F      	MVL	0x8f
135 01B8 [14] 2A33      	ANDF	_PWRCN,1,0
136                     ;	;.line	103; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
137 01B9 [14] C520      	MVL	0x20
138                     	MVF	_ADC_Open_STK10,1,0
139 01BA [15] 0C0D      	CLRF	_ADC_Open_STK09,0
140 01BB [16] C508      	MVL	0x08
141                     	MVF	_ADC_Open_STK08,1,0
142 01BC [17] C520      	MVL	0x20
143                     	MVF	_ADC_Open_STK07,1,0
144 01BD [18] C518      	MVL	0x18
145                     	MVF	_ADC_Open_STK06,1,0
146 01BE [19] C506      	MVL	0x06
147                     	MVF	_ADC_Open_STK05,1,0
148 01BF [20] C510      	MVL	0x10
149                     	MVF	_ADC_Open_STK04,1,0
150 01C0 [21] 0C0D      	CLRF	_ADC_Open_STK03,0
151 01C1 [22] C501      	MVL	0x01
152                     	MVF	_ADC_Open_STK02,1,0
153 01C2 [23] C590      	MVL	0x90
154                     	MVF	_ADC_Open_STK01,1,0
155 01C3 [24] C501      	MVL	0x01
156                     	MVF	_ADC_Open_STK00,1,0
157 01C4 [25] 0610      	MVL	0x10
158 01C5 [25] CEC9      	CALL	_ADC_Open
159                     	.CHKPARA _ADC_Open 12
160                     ;	;.line	106; ".\ADC_LCD.c"	PGAandADCAccuracyMode();
161 01C6 [14] CFD8      	CALL	_PGAandADCAccuracyMode
162                     	.CHKPARA _PGAandADCAccuracyMode 0
163                     ;	;.line	113; ".\ADC_LCD.c"	LCD_Enable();
164 01C7 [14] 9E5B      	BSF	_LCDCN1,7
165                     ;	;.line	114; ".\ADC_LCD.c"	LCD_ChargePumpSelect(LCDV_3V0);
166 01C8 [14] 068F      	MVL	0x8f
167 01C9 [14] 285B      	ANDF	_LCDCN1,0,0
168 01CA [14] 0240      	IORL	0x40
169 01CB [14] 665B      	MVF	_LCDCN1,1,0
170                     ;	;.line	115; ".\ADC_LCD.c"	LCD_OutBufferEnable();
171 01CC [14] 965B      	BSF	_LCDCN1,3
172                     ;	;.line	116; ".\ADC_LCD.c"	LCD_ChargePumpClk(SELPCLK_14KHZ);
173 01CD [14] 845B      	BCF	_LCDCN1,2
174                     ;	;.line	118; ".\ADC_LCD.c"	LCD_DisplayOn();
175 01CE [14] 825C      	BCF	_LCDCN2,1
176                     ;	;.line	121; ".\ADC_LCD.c"	LCD_PT60Mode(LCD);   //COM0
177 01CF [14] 645D      	MVF	_LCDCN3,0,0
178 01D0 [14] 01FC      	ANDL	0xfc
179 01D1 [14] 0203      	IORL	0x03
180 01D2 [14] 665D      	MVF	_LCDCN3,1,0
181 01D3 [14] 01F3      	ANDL	0xf3
182                     ;	;.line	122; ".\ADC_LCD.c"	LCD_PT61Mode(LCD);	 //COM1
183 01D4 [14] 020C      	IORL	0x0c
184 01D5 [14] 665D      	MVF	_LCDCN3,1,0
185 01D6 [14] 01CF      	ANDL	0xcf
186                     ;	;.line	123; ".\ADC_LCD.c"	LCD_PT62Mode(LCD);   //COM2
187 01D7 [14] 0230      	IORL	0x30
188 01D8 [14] 665D      	MVF	_LCDCN3,1,0
189 01D9 [14] 013F      	ANDL	0x3f
190                     ;	;.line	124; ".\ADC_LCD.c"	LCD_PT63Mode(LCD);   //COM3
191 01DA [14] 02C0      	IORL	0xc0
192 01DB [14] 665D      	MVF	_LCDCN3,1,0
193                     ;	;.line	128; ".\ADC_LCD.c"	ADIF_ClearFlag();
194 01DC [14] 8A26      	BCF	_INTF0,5
195                     ;	;.line	129; ".\ADC_LCD.c"	ADIE_Enable();
196 01DD [14] 9A23      	BSF	_INTE0,5
197                     ;	;.line	130; ".\ADC_LCD.c"	GIE_Enable();
198 01DE [14] 9E23      	BSF	_INTE0,7
199                     _00105_DS_:
200                     ;	;.line	136; ".\ADC_LCD.c"	if(GPIO_READ_PT10())
201 01DF [14] 6447      	MVF	_PT1,0,0
202 01E0 [14] 0101      	ANDL	0x01
203 01E1 [14] A02B      	BTSZ	_STATUS,0
204 01E2 [14] 788A      	JMP	_00178_DS_
205                     ;	;.line	140; ".\ADC_LCD.c"	GIE_Disable();
206 01E3 [14] 8E23 0011 	BCF	_INTE0,7
207                     ;	;.line	142; ".\ADC_LCD.c"	if(adS.Presskey_flag==0){
208 01E5 [14] AB78      	BTSZ	(_adS+6),5
209 01E6 [14] 782C      	JMP	_00109_DS_
210                     ;	;.line	143; ".\ADC_LCD.c"	Delay(20000);
211 01E7 [14] C520      	MVL	0x20
212                     	MVF	_Delay_STK00,1,0
213 01E8 [15] 064E      	MVL	0x4e
214 01E9 [15] CF8A      	CALL	_Delay
215                     	.CHKPARA _Delay 2
216                     ;	;.line	144; ".\ADC_LCD.c"	Delay(20000);
217 01EA [14] C520      	MVL	0x20
218                     	MVF	_Delay_STK00,1,0
219 01EB [15] 064E      	MVL	0x4e
220 01EC [15] CF87      	CALL	_Delay
221                     	.CHKPARA _Delay 2
222                     ;	;.line	145; ".\ADC_LCD.c"	Delay(20000);
223 01ED [14] C520      	MVL	0x20
224                     	MVF	_Delay_STK00,1,0
225 01EE [15] 064E      	MVL	0x4e
226 01EF [15] CF84      	CALL	_Delay
227                     	.CHKPARA _Delay 2
228                     ;	;.line	146; ".\ADC_LCD.c"	Delay(20000);
229 01F0 [14] C520      	MVL	0x20
230                     	MVF	_Delay_STK00,1,0
231 01F1 [15] 064E      	MVL	0x4e
232 01F2 [15] CF81 0011 	CALL	_Delay
233                     ;	;.line	148; ".\ADC_LCD.c"	if(adS.resetZeroDisplay==0 ){ /* zero point mode*/
234 01F4 [14] 6F77      	TFSZ	(_adS + 5),0
235 01F5 [14] 780D      	JMP	_00107_DS_
236                     ;	;.line	150; ".\ADC_LCD.c"	adS.resetZeroDisplay++;
237 01F6 [14] 0601      	MVL	0x01
238 01F7 [14] 1377      	ADDF	(_adS + 5),1,0
239                     ;	;.line	151; ".\ADC_LCD.c"	adS.zeroPoint_Mode =1;
240 01F8 [14] 9375      	BSF	(_adS+3),1
241                     ;	;.line	152; ".\ADC_LCD.c"	adS.unit_setMode =0;
242 01F9 [14] 8372      	BCF	_adS,1
243                     ;	;.line	153; ".\ADC_LCD.c"	adS.testMode=0;
244 01FA [14] 8175      	BCF	(_adS+3),0
245                     ;	;.line	154; ".\ADC_LCD.c"	Display2Er();
246 01FB [14] CED3      	CALL	_Display2Er
247                     	.CHKPARA _Display2Er 0
248                     ;	;.line	155; ".\ADC_LCD.c"	Delay(20000);
249 01FC [14] C520      	MVL	0x20
250                     	MVF	_Delay_STK00,1,0
251 01FD [15] 064E      	MVL	0x4e
252 01FE [15] CF75      	CALL	_Delay
253                     	.CHKPARA _Delay 2
254                     ;	;.line	156; ".\ADC_LCD.c"	Delay(10000);
255 01FF [14] C510      	MVL	0x10
256                     	MVF	_Delay_STK00,1,0
257 0200 [15] 0627      	MVL	0x27
258 0201 [15] CF72      	CALL	_Delay
259                     	.CHKPARA _Delay 2
260                     ;	;.line	157; ".\ADC_LCD.c"	goto zeroPoint ;
261 0202 [14] 7FDC      	JMP	_00105_DS_
262                     _00107_DS_:
263                     ;	;.line	160; ".\ADC_LCD.c"	Delay(20000);
264 0203 [14] C520      	MVL	0x20
265                     	MVF	_Delay_STK00,1,0
266 0204 [15] 064E      	MVL	0x4e
267 0205 [15] CF6E      	CALL	_Delay
268                     	.CHKPARA _Delay 2
269                     ;	;.line	161; ".\ADC_LCD.c"	Delay(20000);
270 0206 [14] C520      	MVL	0x20
271                     	MVF	_Delay_STK00,1,0
272 0207 [15] 064E      	MVL	0x4e
273 0208 [15] CF6B      	CALL	_Delay
274                     	.CHKPARA _Delay 2
275                     ;	;.line	162; ".\ADC_LCD.c"	Delay(20000);
276 0209 [14] C520      	MVL	0x20
277                     	MVF	_Delay_STK00,1,0
278 020A [15] 064E      	MVL	0x4e
279 020B [15] CF68      	CALL	_Delay
280                     	.CHKPARA _Delay 2
281                     ;	;.line	163; ".\ADC_LCD.c"	Delay(20000);
282 020C [14] C520      	MVL	0x20
283                     	MVF	_Delay_STK00,1,0
284 020D [15] 064E      	MVL	0x4e
285 020E [15] CF65 0011 	CALL	_Delay
286                     	.CHKPARA _Delay 2
287                     ;	;.line	164; ".\ADC_LCD.c"	adS.Presskey_flag=1;
288 0210 [14] 9B78      	BSF	(_adS+6),5
289                     ;	;.line	165; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
290 0211 [14] 8375      	BCF	(_adS+3),1
291 0212 [14] 7806      	JMP	_00110_DS_
292                     _00109_DS_:
293                     ;	;.line	173; ".\ADC_LCD.c"	Delay(20000);	
294 0213 [14] C520      	MVL	0x20
295                     	MVF	_Delay_STK00,1,0
296 0214 [15] 064E      	MVL	0x4e
297 0215 [15] CF5E      	CALL	_Delay
298                     	.CHKPARA _Delay 2
299                     ;	;.line	174; ".\ADC_LCD.c"	Delay(10000);
300 0216 [14] C510      	MVL	0x10
301                     	MVF	_Delay_STK00,1,0
302 0217 [15] 0627      	MVL	0x27
303 0218 [15] CF5B      	CALL	_Delay
304                     	.CHKPARA _Delay 2
305 0219 [00] 0011      _00110_DS_:
306                     ;	;.line	181; ".\ADC_LCD.c"	adS.unit_setMode =1;
307 021A [14] 9372      	BSF	_adS,1
308                     ;	;.line	182; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
309 021B [14] 8375      	BCF	(_adS+3),1
310                     ;	;.line	183; ".\ADC_LCD.c"	adS.testMode =1;
311 021C [14] 9175      	BSF	(_adS+3),0
312                     ;	;.line	184; ".\ADC_LCD.c"	DisplayUnit();
313 021D [14] CEA9 0011 	CALL	_DisplayUnit
314                     	.CHKPARA _DisplayUnit 0
315                     ;	;.line	188; ".\ADC_LCD.c"	switch(adS.plus_uint){
316 021F [14] 6573      	MVF	(_adS + 1),0,0
317 0220 [14] 04FC      	ADDL	0xfc
318 0221 [14] A82B      	BTSZ	_STATUS,4
319 0222 [14] 7FBC      	JMP	_00105_DS_
320 0223 [14] 0602      	MVL	HIGHD2(_00381_DS_)
321 0224 [14] 661A      	MVF	_PCLATH,1,0
322 0225 [14] 062A      	MVL	D2(_00381_DS_)
323 0226 [14] 1173      	ADDF	(_adS + 1),0,0
324 0227 [14] A82B      	BTSZ	_STATUS,4
325 0228 [14] 3A1A      	INF	_PCLATH,1,0
326 0229 [14] 661B      	MVF	_PCLATL,1,0
327                     _00381_DS_:
328 022A [14] 7803      	RJ	_00111_DS_
329 022B [14] 7812      	RJ	_00112_DS_
330 022C [14] 7820      	RJ	_00113_DS_
331 022D [14] 7831      	RJ	_00114_DS_
332                     _00111_DS_:
333                     ;	;.line	190; ".\ADC_LCD.c"	adS.plus_uint++;
334 022E [14] 0601      	MVL	0x01
335 022F [14] 1373      	ADDF	(_adS + 1),1,0
336                     ;	;.line	191; ".\ADC_LCD.c"	adS.unitChoose = psi;
337 0230 [14] 0D74      	CLRF	(_adS + 2),0
338                     ;	;.line	194; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
339 0231 [14] 06DF      	MVL	0xdf
340 0232 [14] 2847      	ANDF	_PT1,0,0
341 0233 [14] 0220      	IORL	0x20
342 0234 [14] 6647      	MVF	_PT1,1,0
343                     ;	;.line	195; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_psi);
344 0235 [14] 0604      	MVL	0x04
345 0236 [14] 6663      	MVF	_LCD4,1,0
346                     ;	;.line	196; ".\ADC_LCD.c"	Delay(20000);	
347 0237 [14] C520      	MVL	0x20
348                     	MVF	_Delay_STK00,1,0
349 0238 [15] 064E      	MVL	0x4e
350 0239 [15] CF3A      	CALL	_Delay
351                     	.CHKPARA _Delay 2
352                     ;	;.line	197; ".\ADC_LCD.c"	Delay(10000);
353 023A [14] C510      	MVL	0x10
354                     	MVF	_Delay_STK00,1,0
355 023B [15] 0627      	MVL	0x27
356 023C [15] CF37      	CALL	_Delay
357                     	.CHKPARA _Delay 2
358                     ;	;.line	198; ".\ADC_LCD.c"	break;
359 023D [14] 7FA1      	JMP	_00105_DS_
360                     _00112_DS_:
361                     ;	;.line	200; ".\ADC_LCD.c"	adS.plus_uint++;
362 023E [14] 0601 0011 	MVL	0x01
363 0240 [14] 1373      	ADDF	(_adS + 1),1,0
364                     ;	;.line	201; ".\ADC_LCD.c"	adS.unitChoose = bar;
365 0241 [14] 0601      	MVL	0x01
366 0242 [14] 6774      	MVF	(_adS + 2),1,0
367                     ;	;.line	202; ".\ADC_LCD.c"	GPIO_PT15_LOW();
368 0243 [14] 8A47      	BCF	_PT1,5
369                     ;	;.line	204; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_bar);
370 0244 [14] 0602      	MVL	0x02
371 0245 [14] 6663      	MVF	_LCD4,1,0
372                     ;	;.line	205; ".\ADC_LCD.c"	Delay(20000);	
373 0246 [14] C520      	MVL	0x20
374                     	MVF	_Delay_STK00,1,0
375 0247 [15] 064E      	MVL	0x4e
376 0248 [15] CF2B      	CALL	_Delay
377                     	.CHKPARA _Delay 2
378                     ;	;.line	206; ".\ADC_LCD.c"	Delay(10000);
379 0249 [14] C510      	MVL	0x10
380                     	MVF	_Delay_STK00,1,0
381 024A [15] 0627      	MVL	0x27
382 024B [15] CF28      	CALL	_Delay
383                     	.CHKPARA _Delay 2
384                     ;	;.line	207; ".\ADC_LCD.c"	break;
385 024C [14] 7F92      	JMP	_00105_DS_
386                     _00113_DS_:
387                     ;	;.line	209; ".\ADC_LCD.c"	adS.plus_uint++;
388 024D [14] 0601 0011 	MVL	0x01
389 024F [14] 1373      	ADDF	(_adS + 1),1,0
390                     ;	;.line	210; ".\ADC_LCD.c"	adS.unitChoose = kgf;
391 0250 [14] 0602      	MVL	0x02
392 0251 [14] 6774      	MVF	(_adS + 2),1,0
393                     ;	;.line	211; ".\ADC_LCD.c"	GPIO_PT15_HIGH();
394 0252 [14] 06DF      	MVL	0xdf
395 0253 [14] 2847      	ANDF	_PT1,0,0
396 0254 [14] 0220      	IORL	0x20
397 0255 [14] 6647      	MVF	_PT1,1,0
398                     ;	;.line	213; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_kgf);
399 0256 [14] 0601      	MVL	0x01
400 0257 [14] 6663      	MVF	_LCD4,1,0
401                     ;	;.line	214; ".\ADC_LCD.c"	Delay(20000);
402 0258 [14] C520      	MVL	0x20
403                     	MVF	_Delay_STK00,1,0
404 0259 [15] 064E      	MVL	0x4e
405 025A [15] CF19      	CALL	_Delay
406                     	.CHKPARA _Delay 2
407                     ;	;.line	215; ".\ADC_LCD.c"	Delay(10000);	
408 025B [14] C510      	MVL	0x10
409                     	MVF	_Delay_STK00,1,0
410 025C [15] 0627      	MVL	0x27
411 025D [15] CF16      	CALL	_Delay
412                     	.CHKPARA _Delay 2
413                     ;	;.line	217; ".\ADC_LCD.c"	break;
414 025E [14] 7F80      	JMP	_00105_DS_
415 025F [00] 0011      _00114_DS_:
416                     ;	;.line	219; ".\ADC_LCD.c"	adS.plus_uint=0;
417 0260 [14] 0D73      	CLRF	(_adS + 1),0
418                     ;	;.line	220; ".\ADC_LCD.c"	adS.unitChoose = mpa;
419 0261 [14] 0603      	MVL	0x03
420 0262 [14] 6774      	MVF	(_adS + 2),1,0
421                     ;	;.line	221; ".\ADC_LCD.c"	GPIO_PT15_LOW();
422 0263 [14] 8A47      	BCF	_PT1,5
423                     ;	;.line	223; ".\ADC_LCD.c"	LCD_WriteData(&LCD4,seg_mpa);
424 0264 [14] 0608      	MVL	0x08
425 0265 [14] 6663      	MVF	_LCD4,1,0
426                     ;	;.line	225; ".\ADC_LCD.c"	Delay(20000);
427 0266 [14] C520      	MVL	0x20
428                     	MVF	_Delay_STK00,1,0
429 0267 [15] 064E      	MVL	0x4e
430 0268 [15] CF0B      	CALL	_Delay
431                     	.CHKPARA _Delay 2
432                     ;	;.line	226; ".\ADC_LCD.c"	Delay(10000);	
433 0269 [14] C510      	MVL	0x10
434                     	MVF	_Delay_STK00,1,0
435 026A [15] 0627      	MVL	0x27
436 026B [15] CF08      	CALL	_Delay
437                     	.CHKPARA _Delay 2
438                     ;	;.line	228; ".\ADC_LCD.c"	}
439 026C [14] 7F72      	JMP	_00105_DS_
440 026D [00] 0011      _00178_DS_:
441                     ;	;.line	234; ".\ADC_LCD.c"	if(adS.testMode == 0){ /* measure mode */
442 026E [14] A175      	BTSZ	(_adS+3),0
443 026F [14] 7BBA      	JMP	_00146_DS_
444                     ;	;.line	235; ".\ADC_LCD.c"	adS.zeroPoint_Mode=0;
445 0270 [14] 8375      	BCF	(_adS+3),1
446                     ;	;.line	236; ".\ADC_LCD.c"	adS.unit_setMode=0;
447 0271 [14] 8372      	BCF	_adS,1
448                     ;	;.line	237; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
449 0272 [14] 0D77      	CLRF	(_adS + 5),0
450                     ;	;.line	238; ".\ADC_LCD.c"	if(adS.reload_ADCInterrupt == 1){
451 0273 [14] B17B      	BTSS	(_adS+9),0
452 0274 [14] 7811      	JMP	_00117_DS_
453                     ;	;.line	239; ".\ADC_LCD.c"	adS.reload_ADCInterrupt =0;
454 0275 [14] 817B      	BCF	(_adS+9),0
455                     ;	;.line	240; ".\ADC_LCD.c"	ADC_Open(DADC_DHSCKDIV4, CPUS_DHSCK, INP_VSS ,INN_VSS, VRH_AI2, VRL_AI3, ADGN_16, PGAGN_8, VREGN_DIV2, DCSET_N0, OSR_65536,VCMS_V12);
456 0276 [14] C520      	MVL	0x20
457                     	MVF	_ADC_Open_STK10,1,0
458 0277 [15] 0C0D      	CLRF	_ADC_Open_STK09,0
459 0278 [16] C508      	MVL	0x08
460                     	MVF	_ADC_Open_STK08,1,0
461 0279 [17] C520      	MVL	0x20
462                     	MVF	_ADC_Open_STK07,1,0
463 027A [18] C518      	MVL	0x18
464                     	MVF	_ADC_Open_STK06,1,0
465 027B [19] C506      	MVL	0x06
466                     	MVF	_ADC_Open_STK05,1,0
467 027C [20] C510      	MVL	0x10
468                     	MVF	_ADC_Open_STK04,1,0
469 027D [21] 0C0D      	CLRF	_ADC_Open_STK03,0
470 027E [22] C501      	MVL	0x01
471                     	MVF	_ADC_Open_STK02,1,0
472 027F [23] C590      	MVL	0x90
473                     	MVF	_ADC_Open_STK01,1,0
474 0280 [24] C501      	MVL	0x01
475                     	MVF	_ADC_Open_STK00,1,0
476 0281 [25] 0610      	MVL	0x10
477 0282 [25] CE0C      	CALL	_ADC_Open
478                     	.CHKPARA _ADC_Open 12
479                     ;	;.line	241; ".\ADC_LCD.c"	ADIF_ClearFlag();
480 0283 [14] 8A26      	BCF	_INTF0,5
481                     ;	;.line	242; ".\ADC_LCD.c"	ADIE_Enable();
482 0284 [14] 9A23      	BSF	_INTE0,5
483                     ;	;.line	243; ".\ADC_LCD.c"	GIE_Enable();
484 0285 [14] 9E23      	BSF	_INTE0,7
485 0286 [00] 0011      _00117_DS_:
486                     ;	;.line	246; ".\ADC_LCD.c"	if(MCUSTATUSbits.b_ADCdone==1)
487 0287 [14] B171      	BTSS	_MCUSTATUSbits,0
488 0288 [14] 7BA1      	JMP	_00146_DS_
489                     ;	;.line	250; ".\ADC_LCD.c"	MCUSTATUSbits.b_ADCdone=0;
490 0289 [14] 8171      	BCF	_MCUSTATUSbits,0
491                     ;	;.line	254; ".\ADC_LCD.c"	ADC=ADC>>6;
492 028A [14] 616D      	SWPF	_ADC,0,0
493 028B [14] 010F      	ANDL	0x0f
494 028C [14] 676D      	MVF	_ADC,1,0
495 028D [14] 616E      	SWPF	(_ADC + 1),0,0
496 028E [14] 676E      	MVF	(_ADC + 1),1,0
497 028F [14] 01F0      	ANDL	0xf0
498 0290 [14] 2F6D      	IORF	_ADC,1,0
499 0291 [14] 236E      	XORF	(_ADC + 1),1,0
500 0292 [14] 616F      	SWPF	(_ADC + 2),0,0
501 0293 [14] 676F      	MVF	(_ADC + 2),1,0
502 0294 [14] 01F0      	ANDL	0xf0
503 0295 [14] 2F6E      	IORF	(_ADC + 1),1,0
504 0296 [14] 236F      	XORF	(_ADC + 2),1,0
505 0297 [14] 6170      	SWPF	(_ADC + 3),0,0
506 0298 [14] 6770      	MVF	(_ADC + 3),1,0
507 0299 [14] 01F0      	ANDL	0xf0
508 029A [14] 2F6F      	IORF	(_ADC + 2),1,0
509 029B [14] 2370      	XORF	(_ADC + 3),1,0
510 029C [14] 06F0      	MVL	0xf0
511 029D [14] A770      	BTSZ	(_ADC + 3),3
512 029E [14] 2F70      	IORF	(_ADC + 3),1,0
513 029F [14] 5F70      	ARRC	(_ADC + 3),1,0
514 02A0 [14] 536F      	RRFC	(_ADC + 2),1,0
515 02A1 [14] 536E      	RRFC	(_ADC + 1),1,0
516 02A2 [14] 536D      	RRFC	_ADC,1,0
517 02A3 [14] 5F70      	ARRC	(_ADC + 3),1,0
518 02A4 [14] 536F      	RRFC	(_ADC + 2),1,0
519 02A5 [14] 536E      	RRFC	(_ADC + 1),1,0
520 02A6 [14] 536D      	RRFC	_ADC,1,0
521                     ;	;.line	256; ".\ADC_LCD.c"	ADC = ADC * 0.1 ;
522 02A7 [14] D16D      	MVF	_ADC,0,0
523 02A8 [14] F00D      	MVF	___slong2fs_STK02,1,0
524 02A9 [15] D16E      	MVF	(_ADC + 1),0,0
525 02AA [15] F00D      	MVF	___slong2fs_STK01,1,0
526 02AB [16] D16F      	MVF	(_ADC + 2),0,0
527 02AC [16] F00D      	MVF	___slong2fs_STK00,1,0
528 02AD [17] 6570      	MVF	(_ADC + 3),0,0
529 02AE [17] C000 F750 	CALL	___slong2fs
530                     	.CHKPARA ___slong2fs 4
531 02B0 [14] 668C      	MVF	r0x1143,1,0
532 02B1 [14] D01E      	MVF	STK02,0,0
533 02B2 [14] F00D      	MVF	___fsmul_STK06,1,0
534 02B3 [15] D01F      	MVF	STK01,0,0
535 02B4 [15] F00D      	MVF	___fsmul_STK05,1,0
536 02B5 [16] D020      	MVF	STK00,0,0
537 02B6 [16] F00D      	MVF	___fsmul_STK04,1,0
538 02B7 [17] C60F      	MVF	r0x1143,0,0
539 02B8 [17] F00D      	MVF	___fsmul_STK03,1,0
540 02B9 [18] C5CD      	MVL	0xcd
541                     	MVF	___fsmul_STK02,1,0
542 02BA [19] C5CC      	MVL	0xcc
543                     	MVF	___fsmul_STK01,1,0
544 02BB [20] C5CC      	MVF	___fsmul_STK00,1,0
545 02BC [21] 063D      	MVL	0x3d
546 02BD [21] C000 FB93 	CALL	___fsmul
547                     	.CHKPARA ___fsmul 8
548 02BF [14] 668C      	MVF	r0x1143,1,0
549 02C0 [14] D01E      	MVF	STK02,0,0
550 02C1 [14] F00D      	MVF	___fs2slong_STK02,1,0
551 02C2 [15] D01F      	MVF	STK01,0,0
552 02C3 [15] F00D      	MVF	___fs2slong_STK01,1,0
553 02C4 [16] D020      	MVF	STK00,0,0
554 02C5 [16] F00D      	MVF	___fs2slong_STK00,1,0
555 02C6 [17] 648F      	MVF	r0x1143,0,0
556 02C7 [17] C000 F7EE 
556 02C9 0011           	CALL	___fs2slong
557                     	.CHKPARA ___fs2slong 4
558 02CA [14] 6770      	MVF	(_ADC + 3),1,0
559 02CB [14] D020      	MVF	STK00,0,0
560 02CC [14] F16F      	MVF	(_ADC + 2),1,0
561 02CD [14] D01F      	MVF	STK01,0,0
562 02CE [14] F16E      	MVF	(_ADC + 1),1,0
563 02CF [14] 641E      	MVF	STK02,0,0
564 02D0 [14] 676D      	MVF	_ADC,1,0
565                     ;	;.line	258; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
566 02D1 [14] AF70      	BTSZ	(_ADC + 3),7
567 02D2 [14] 7809      	JMP	_00118_DS_
568 02D3 [14] 316D      	DCF	_ADC,0,0
569 02D4 [14] 06FF      	MVL	0xff
570 02D5 [14] 156E      	ADDC	(_ADC + 1),0,0
571 02D6 [14] 06FF      	MVL	0xff
572 02D7 [14] 156F      	ADDC	(_ADC + 2),0,0
573 02D8 [14] 067F      	MVL	0x7f
574 02D9 [14] 1570      	ADDC	(_ADC + 3),0,0
575 02DA [14] B82B      	BTSS	_STATUS,4
576 02DB [14] 7802      	JMP	_00119_DS_
577                     _00118_DS_:
578                     ;	;.line	261; ".\ADC_LCD.c"	adS.Pressure_sign =1;
579 02DC [14] 9D78      	BSF	(_adS+6),6
580 02DD [14] 7802      	JMP	_00120_DS_
581 02DE [00] 0011      _00119_DS_:
582                     ;	;.line	265; ".\ADC_LCD.c"	adS.Pressure_sign =0;
583 02DF [14] 8D78      	BCF	(_adS+6),6
584                     _00120_DS_:
585                     ;	;.line	268; ".\ADC_LCD.c"	if(adS.Pressure_sign == 0){/*Input positive Pressure mode*/
586 02E0 [14] AD78      	BTSZ	(_adS+6),6
587 02E1 [14] 79E9      	JMP	_00141_DS_
588                     ;	;.line	270; ".\ADC_LCD.c"	n = ADC ;
589 02E2 [14] 656D      	MVF	_ADC,0,0
590 02E3 [14] 668D      	MVF	r0x1140,1,0
591 02E4 [14] 656E      	MVF	(_ADC + 1),0,0
592 02E5 [14] 668A      	MVF	r0x1141,1,0
593 02E6 [14] 656F      	MVF	(_ADC + 2),0,0
594 02E7 [14] 668B      	MVF	r0x1142,1,0
595 02E8 [14] 6570      	MVF	(_ADC + 3),0,0
596 02E9 [14] 668C      	MVF	r0x1143,1,0
597                     ;	;.line	271; ".\ADC_LCD.c"	LCDDisplay= (0.1 * n)-364 ;  //y = 0.0175x - 36.495  //= 0.0175x - 36.495 
598 02EA [14] C60D      	MVF	r0x1140,0,0
599 02EB [14] F00D      	MVF	___slong2fs_STK02,1,0
600 02EC [15] C60B      	MVF	r0x1141,0,0
601 02ED [15] F00D      	MVF	___slong2fs_STK01,1,0
602 02EE [16] C60D      	MVF	r0x1142,0,0
603 02EF [16] F00D      	MVF	___slong2fs_STK00,1,0
604 02F0 [17] 648F      	MVF	r0x1143,0,0
605 02F1 [17] C000 F750 	CALL	___slong2fs
606                     	.CHKPARA ___slong2fs 4
607 02F3 [14] 6689      	MVF	r0x1147,1,0
608 02F4 [14] 6420      	MVF	STK00,0,0
609 02F5 [14] 6688      	MVF	r0x1146,1,0
610 02F6 [14] 641F      	MVF	STK01,0,0
611 02F7 [14] 6687      	MVF	r0x1145,1,0
612 02F8 [14] 641E      	MVF	STK02,0,0
613 02F9 [14] 6686      	MVF	r0x1144,1,0
614 02FA [14] 660D      	MVF	___fsmul_STK06,1,0
615 02FB [15] C608      	MVF	r0x1145,0,0
616 02FC [15] F00D      	MVF	___fsmul_STK05,1,0
617 02FD [16] C60A      	MVF	r0x1146,0,0
618 02FE [16] F00D      	MVF	___fsmul_STK04,1,0
619 02FF [17] C60C      	MVF	r0x1147,0,0
620 0300 [17] F00D      	MVF	___fsmul_STK03,1,0
621 0301 [18] C5CD      	MVL	0xcd
622                     	MVF	___fsmul_STK02,1,0
623 0302 [19] C5CC      	MVL	0xcc
624                     	MVF	___fsmul_STK01,1,0
625 0303 [20] C5CC      	MVF	___fsmul_STK00,1,0
626 0304 [21] 063D      	MVL	0x3d
627 0305 [21] C000 FB93 	CALL	___fsmul
628                     	.CHKPARA ___fsmul 8
629 0307 [14] 6685      	MVF	r0x114B,1,0
630 0308 [14] 0C0D      	CLRF	___fssub_STK06,0
631 0309 [15] 0C0D      	CLRF	___fssub_STK05,0
632 030A [16] C5B6      	MVL	0xb6
633                     	MVF	___fssub_STK04,1,0
634 030B [17] C543      	MVL	0x43
635                     	MVF	___fssub_STK03,1,0
636 030C [18] D01E      	MVF	STK02,0,0
637 030D [18] F00D      	MVF	___fssub_STK02,1,0
638 030E [19] D01F      	MVF	STK01,0,0
639 030F [19] F00D      	MVF	___fssub_STK01,1,0
640 0310 [20] D020      	MVF	STK00,0,0
641 0311 [20] F00D      	MVF	___fssub_STK00,1,0
642 0312 [21] 648C      	MVF	r0x114B,0,0
643 0313 [21] CDE0      	CALL	___fssub
644                     	.CHKPARA ___fssub 8
645 0314 [14] 6685 0011 	MVF	r0x114B,1,0
646                     ;	;.line	274; ".\ADC_LCD.c"	if(adS.plus_revise_flag ==1){
647 0316 [14] B778      	BTSS	(_adS+6),3
648 0317 [14] 7996      	JMP	_00132_DS_
649                     ;	;.line	276; ".\ADC_LCD.c"	if(n<2000)DisplayNum(ADC);
650 0318 [14] 0630      	MVL	0x30
651 0319 [14] 108D      	ADDF	r0x1140,0,0
652 031A [14] 06F8      	MVL	0xf8
653 031B [14] 148A      	ADDC	r0x1141,0,0
654 031C [14] 06FF      	MVL	0xff
655 031D [14] 148B      	ADDC	r0x1142,0,0
656 031E [14] 067F      	MVL	0x7f
657 031F [14] 148C      	ADDC	r0x1143,0,0
658 0320 [14] A22B      	BTSZ	_STATUS,1
659 0321 [14] 780A      	JMP	_00129_DS_
660 0322 [14] D16D      	MVF	_ADC,0,0
661 0323 [14] F00D      	MVF	_DisplayNum_STK02,1,0
662 0324 [15] D16E      	MVF	(_ADC + 1),0,0
663 0325 [15] F00D      	MVF	_DisplayNum_STK01,1,0
664 0326 [16] D16F      	MVF	(_ADC + 2),0,0
665 0327 [16] F00D      	MVF	_DisplayNum_STK00,1,0
666 0328 [17] 6570      	MVF	(_ADC + 3),0,0
667 0329 [17] C000 F829 	CALL	_DisplayNum
668                     	.CHKPARA _DisplayNum 4
669 032B [14] 7AFE      	JMP	_00146_DS_
670                     _00129_DS_:
671                     ;	;.line	278; ".\ADC_LCD.c"	else if( (LCDDisplay *10) < 2875){
672 032C [14] D01E      	MVF	STK02,0,0
673 032D [14] F00D      	MVF	___fsmul_STK06,1,0
674 032E [15] D01F      	MVF	STK01,0,0
675 032F [15] F00D      	MVF	___fsmul_STK05,1,0
676 0330 [16] D020      	MVF	STK00,0,0
677 0331 [16] F00D      	MVF	___fsmul_STK04,1,0
678 0332 [17] 6488      	MVF	r0x114B,0,0
679 0333 [17] 660D      	MVF	___fsmul_STK03,1,0
680 0334 [18] 0C0D      	CLRF	___fsmul_STK02,0
681 0335 [19] 0C0D      	CLRF	___fsmul_STK01,0
682 0336 [20] C520      	MVL	0x20
683                     	MVF	___fsmul_STK00,1,0
684 0337 [21] 0641      	MVL	0x41
685 0338 [21] C000 FB93 	CALL	___fsmul
686                     	.CHKPARA ___fsmul 8
687 033A [14] 668C      	MVF	r0x1143,1,0
688 033B [14] 0C0D      	CLRF	___fslt_STK06,0
689 033C [15] C5B0      	MVL	0xb0
690                     	MVF	___fslt_STK05,1,0
691 033D [16] C533      	MVL	0x33
692                     	MVF	___fslt_STK04,1,0
693 033E [17] C545      	MVL	0x45
694                     	MVF	___fslt_STK03,1,0
695 033F [18] D01E      	MVF	STK02,0,0
696 0340 [18] F00D      	MVF	___fslt_STK02,1,0
697 0341 [19] D01F      	MVF	STK01,0,0
698 0342 [19] F00D      	MVF	___fslt_STK01,1,0
699 0343 [20] D020      	MVF	STK00,0,0
700 0344 [20] F00D      	MVF	___fslt_STK00,1,0
701 0345 [21] 6493      	MVF	r0x1143,0,0
702 0346 [21] CCEA      	CALL	___fslt
703 0347 [14] 0200      	IORL	0x00
704 0348 [14] A02B      	BTSZ	_STATUS,0
705 0349 [14] 786D      	JMP	_00126_DS_
706                     ;	;.line	279; ".\ADC_LCD.c"	LCDDisplay= 0.125 *n- 202.86; //y = 0.0125x - 20.286
707 034A [14] C606      	MVF	r0x1144,0,0
708 034B [14] F00D      	MVF	___fsmul_STK06,1,0
709 034C [15] C608      	MVF	r0x1145,0,0
710 034D [15] F00D      	MVF	___fsmul_STK05,1,0
711 034E [16] C60A      	MVF	r0x1146,0,0
712 034F [16] F00D      	MVF	___fsmul_STK04,1,0
713 0350 [17] 648C      	MVF	r0x1147,0,0
714 0351 [17] 660D      	MVF	___fsmul_STK03,1,0
715 0352 [18] 0C0D      	CLRF	___fsmul_STK02,0
716 0353 [19] 0C0D      	CLRF	___fsmul_STK01,0
717 0354 [20] 0C0D      	CLRF	___fsmul_STK00,0
718 0355 [21] 063E      	MVL	0x3e
719 0356 [21] C000 FB93 	CALL	___fsmul
720                     	.CHKPARA ___fsmul 8
721 0358 [14] 668C      	MVF	r0x1143,1,0
722 0359 [14] C529      	MVL	0x29
723                     	MVF	___fssub_STK06,1,0
724 035A [15] C5DC      	MVL	0xdc
725                     	MVF	___fssub_STK05,1,0
726 035B [16] C54A      	MVL	0x4a
727                     	MVF	___fssub_STK04,1,0
728 035C [17] C543      	MVL	0x43
729                     	MVF	___fssub_STK03,1,0
730 035D [18] D01E      	MVF	STK02,0,0
731 035E [18] F00D      	MVF	___fssub_STK02,1,0
732 035F [19] D01F      	MVF	STK01,0,0
733 0360 [19] F00D      	MVF	___fssub_STK01,1,0
734 0361 [20] D020      	MVF	STK00,0,0
735 0362 [20] F00D      	MVF	___fssub_STK00,1,0
736 0363 [21] 6493      	MVF	r0x1143,0,0
737 0364 [21] CD8F      	CALL	___fssub
738                     	.CHKPARA ___fssub 8
739 0365 [14] 668C      	MVF	r0x1143,1,0
740 0366 [14] D01E      	MVF	STK02,0,0
741                     ;	;.line	280; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
742 0367 [14] F00D      	MVF	___fs2slong_STK02,1,0
743 0368 [15] D01F      	MVF	STK01,0,0
744 0369 [15] F00D      	MVF	___fs2slong_STK01,1,0
745 036A [16] D020      	MVF	STK00,0,0
746 036B [16] F00D      	MVF	___fs2slong_STK00,1,0
747 036C [17] 648F      	MVF	r0x1143,0,0
748 036D [17] C000 F7EE 	CALL	___fs2slong
749                     	.CHKPARA ___fs2slong 4
750 036F [14] 668C      	MVF	r0x1143,1,0
751 0370 [14] D01E      	MVF	STK02,0,0
752 0371 [14] F00D      	MVF	_Reverse_Data_STK02,1,0
753 0372 [15] D01F      	MVF	STK01,0,0
754 0373 [15] F00D      	MVF	_Reverse_Data_STK01,1,0
755 0374 [16] D020      	MVF	STK00,0,0
756 0375 [16] F00D      	MVF	_Reverse_Data_STK00,1,0
757 0376 [17] 648F      	MVF	r0x1143,0,0
758 0377 [17] CBFE      	CALL	_Reverse_Data
759                     	.CHKPARA _Reverse_Data 4
760 0378 [14] 668C      	MVF	r0x1143,1,0
761 0379 [14] D01E      	MVF	STK02,0,0
762 037A [14] F00D      	MVF	___slong2fs_STK02,1,0
763 037B [15] D01F      	MVF	STK01,0,0
764 037C [15] F00D      	MVF	___slong2fs_STK01,1,0
765 037D [16] D020      	MVF	STK00,0,0
766 037E [16] F00D      	MVF	___slong2fs_STK00,1,0
767 037F [17] 648F      	MVF	r0x1143,0,0
768 0380 [17] CBCF      	CALL	___slong2fs
769                     	.CHKPARA ___slong2fs 4
770 0381 [14] 668C      	MVF	r0x1143,1,0
771 0382 [14] D01E      	MVF	STK02,0,0
772                     ;	;.line	281; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
773 0383 [14] F00D      	MVF	___fs2slong_STK02,1,0
774 0384 [15] D01F      	MVF	STK01,0,0
775 0385 [15] F00D      	MVF	___fs2slong_STK01,1,0
776 0386 [16] D020      	MVF	STK00,0,0
777 0387 [16] F00D      	MVF	___fs2slong_STK00,1,0
778 0388 [17] 648F      	MVF	r0x1143,0,0
779 0389 [17] C000 F7EE 	CALL	___fs2slong
780                     	.CHKPARA ___fs2slong 4
781 038B [14] 668C      	MVF	r0x1143,1,0
782 038C [14] 641E      	MVF	STK02,0,0
783 038D [14] 660D      	MVF	_UnitConverter_STK02,1,0
784 038E [15] 641F      	MVF	STK01,0,0
785 038F [15] 660D      	MVF	_UnitConverter_STK01,1,0
786 0390 [16] 6420      	MVF	STK00,0,0
787 0391 [16] 660D      	MVF	_UnitConverter_STK00,1,0
788 0392 [17] 648F      	MVF	r0x1143,0,0
789 0393 [17] C000 F86B 	CALL	_UnitConverter
790                     	.CHKPARA _UnitConverter 4
791 0395 [14] 668C      	MVF	r0x1143,1,0
792 0396 [14] D01E      	MVF	STK02,0,0
793 0397 [14] F00D      	MVF	___slong2fs_STK02,1,0
794 0398 [15] D01F      	MVF	STK01,0,0
795 0399 [15] F00D      	MVF	___slong2fs_STK01,1,0
796 039A [16] D020      	MVF	STK00,0,0
797 039B [16] F00D      	MVF	___slong2fs_STK00,1,0
798 039C [17] 648F      	MVF	r0x1143,0,0
799 039D [17] CBB2      	CALL	___slong2fs
800                     	.CHKPARA ___slong2fs 4
801 039E [14] 668C      	MVF	r0x1143,1,0
802 039F [14] D01E      	MVF	STK02,0,0
803                     ;	;.line	282; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
804 03A0 [14] F00D      	MVF	___fs2slong_STK02,1,0
805 03A1 [15] D01F      	MVF	STK01,0,0
806 03A2 [15] F00D      	MVF	___fs2slong_STK01,1,0
807 03A3 [16] D020      	MVF	STK00,0,0
808 03A4 [16] F00D      	MVF	___fs2slong_STK00,1,0
809 03A5 [17] 648F      	MVF	r0x1143,0,0
810 03A6 [17] C000 F7EE 	CALL	___fs2slong
811                     	.CHKPARA ___fs2slong 4
812 03A8 [14] 668C      	MVF	r0x1143,1,0
813 03A9 [14] D01E      	MVF	STK02,0,0
814 03AA [14] F00D      	MVF	_DisplayNum_STK02,1,0
815 03AB [15] D01F      	MVF	STK01,0,0
816 03AC [15] F00D      	MVF	_DisplayNum_STK01,1,0
817 03AD [16] D020      	MVF	STK00,0,0
818 03AE [16] F00D      	MVF	_DisplayNum_STK00,1,0
819 03AF [17] 648F      	MVF	r0x1143,0,0
820 03B0 [17] C000 F829 	CALL	_DisplayNum
821                     	.CHKPARA _DisplayNum 4
822                     ;	;.line	283; ".\ADC_LCD.c"	LowVoltageDisplay();
823 03B2 [14] CDCD      	CALL	_LowVoltageDisplay
824                     	.CHKPARA _LowVoltageDisplay 0
825                     ;	;.line	285; ".\ADC_LCD.c"	Delay(20000);
826 03B3 [14] C520      	MVL	0x20
827                     	MVF	_Delay_STK00,1,0
828 03B4 [15] 064E      	MVL	0x4e
829 03B5 [15] CDBE      	CALL	_Delay
830                     	.CHKPARA _Delay 2
831 03B6 [14] 7A73      	JMP	_00146_DS_
832 03B7 [00] 0011      _00126_DS_:
833                     ;	;.line	290; ".\ADC_LCD.c"	if(adS.p_offset_value >=0) //WT.EDIT 2020-05-28
834 03B8 [14] AF7F      	BTSZ	(_adS + 13),7
835 03B9 [14] 783F      	JMP	_00123_DS_
836                     ;	;.line	291; ".\ADC_LCD.c"	n =abs(ADC)- abs(adS.p_offset_value);
837 03BA [14] 316D      	DCF	_ADC,0,0
838 03BB [14] 06FF      	MVL	0xff
839 03BC [14] 156E      	ADDC	(_ADC + 1),0,0
840 03BD [14] 06FF      	MVL	0xff
841 03BE [14] 156F      	ADDC	(_ADC + 2),0,0
842 03BF [14] 067F      	MVL	0x7f
843 03C0 [14] 1570      	ADDC	(_ADC + 3),0,0
844 03C1 [14] B22B      	BTSS	_STATUS,1
845 03C2 [14] 7809      	JMP	_00185_DS_
846 03C3 [14] 656D      	MVF	_ADC,0,0
847 03C4 [14] 668D      	MVF	r0x1140,1,0
848 03C5 [14] 656E      	MVF	(_ADC + 1),0,0
849 03C6 [14] 668A      	MVF	r0x1141,1,0
850 03C7 [14] 656F      	MVF	(_ADC + 2),0,0
851 03C8 [14] 668B      	MVF	r0x1142,1,0
852 03C9 [14] 6570      	MVF	(_ADC + 3),0,0
853 03CA [14] 668C      	MVF	r0x1143,1,0
854 03CB [14] 780E      	JMP	_00186_DS_
855 03CC [00] 0011      _00185_DS_:
856 03CD [14] 256D      	COMF	_ADC,0,0
857 03CE [14] 668D      	MVF	r0x1140,1,0
858 03CF [14] 256E      	COMF	(_ADC + 1),0,0
859 03D0 [14] 668A      	MVF	r0x1141,1,0
860 03D1 [14] 256F      	COMF	(_ADC + 2),0,0
861 03D2 [14] 668B      	MVF	r0x1142,1,0
862 03D3 [14] 2570      	COMF	(_ADC + 3),0,0
863 03D4 [14] 668C      	MVF	r0x1143,1,0
864 03D5 [14] 3A8D      	INF	r0x1140,1,0
865 03D6 [14] 0600      	MVL	0x00
866 03D7 [14] 168A      	ADDC	r0x1141,1,0
867 03D8 [14] 168B      	ADDC	r0x1142,1,0
868 03D9 [14] 168C      	ADDC	r0x1143,1,0
869                     _00186_DS_:
870 03DA [14] 317E      	DCF	(_adS + 12),0,0
871 03DB [14] 067F      	MVL	0x7f
872 03DC [14] 157F      	ADDC	(_adS + 13),0,0
873 03DD [14] B22B      	BTSS	_STATUS,1
874 03DE [14] 7805      	JMP	_00187_DS_
875 03DF [14] 657E      	MVF	(_adS + 12),0,0
876 03E0 [14] 6688      	MVF	r0x1146,1,0
877 03E1 [14] 657F      	MVF	(_adS + 13),0,0
878 03E2 [14] 6689      	MVF	r0x1147,1,0
879 03E3 [14] 7807      	JMP	_00188_DS_
880 03E4 [00] 0011      _00187_DS_:
881 03E5 [14] 257E      	COMF	(_adS + 12),0,0
882 03E6 [14] 6688      	MVF	r0x1146,1,0
883 03E7 [14] 257F      	COMF	(_adS + 13),0,0
884 03E8 [14] 4288      	INSUZ	r0x1146,1,0
885 03E9 [14] 0401      	ADDL	0x01
886 03EA [14] 6689      	MVF	r0x1147,1,0
887                     _00188_DS_:
888 03EB [14] 0600      	MVL	0x00
889 03EC [14] AE89      	BTSZ	r0x1147,7
890 03ED [14] 06FF      	MVL	0xff
891 03EE [14] 6683      	MVF	r0x1149,1,0
892 03EF [14] 6682      	MVF	r0x1148,1,0
893 03F0 [14] 6488      	MVF	r0x1146,0,0
894 03F1 [14] 1A8D      	SUBF	r0x1140,1,0
895 03F2 [14] 6489      	MVF	r0x1147,0,0
896 03F3 [14] 1E8A      	SUBC	r0x1141,1,0
897 03F4 [14] 6482      	MVF	r0x1148,0,0
898 03F5 [14] 1E8B      	SUBC	r0x1142,1,0
899 03F6 [14] 6483      	MVF	r0x1149,0,0
900 03F7 [14] 1E8C      	SUBC	r0x1143,1,0
901 03F8 [14] 7843      	JMP	_00124_DS_
902 03F9 [00] 0011      _00123_DS_:
903                     ;	;.line	292; ".\ADC_LCD.c"	else  n =abs(ADC) + abs(adS.p_offset_value);
904 03FA [14] 316D      	DCF	_ADC,0,0
905 03FB [14] 06FF      	MVL	0xff
906 03FC [14] 156E      	ADDC	(_ADC + 1),0,0
907 03FD [14] 06FF      	MVL	0xff
908 03FE [14] 156F      	ADDC	(_ADC + 2),0,0
909 03FF [14] 067F      	MVL	0x7f
910 0400 [14] 1570      	ADDC	(_ADC + 3),0,0
911 0401 [14] B22B      	BTSS	_STATUS,1
912 0402 [14] 7809      	JMP	_00189_DS_
913 0403 [14] 656D      	MVF	_ADC,0,0
914 0404 [14] 6686      	MVF	r0x1144,1,0
915 0405 [14] 656E      	MVF	(_ADC + 1),0,0
916 0406 [14] 6687      	MVF	r0x1145,1,0
917 0407 [14] 656F      	MVF	(_ADC + 2),0,0
918 0408 [14] 6688      	MVF	r0x1146,1,0
919 0409 [14] 6570      	MVF	(_ADC + 3),0,0
920 040A [14] 6689      	MVF	r0x1147,1,0
921 040B [14] 780E      	JMP	_00190_DS_
922 040C [00] 0011      _00189_DS_:
923 040D [14] 256D      	COMF	_ADC,0,0
924 040E [14] 6686      	MVF	r0x1144,1,0
925 040F [14] 256E      	COMF	(_ADC + 1),0,0
926 0410 [14] 6687      	MVF	r0x1145,1,0
927 0411 [14] 256F      	COMF	(_ADC + 2),0,0
928 0412 [14] 6688      	MVF	r0x1146,1,0
929 0413 [14] 2570      	COMF	(_ADC + 3),0,0
930 0414 [14] 6689      	MVF	r0x1147,1,0
931 0415 [14] 3A86      	INF	r0x1144,1,0
932 0416 [14] 0600      	MVL	0x00
933 0417 [14] 1687      	ADDC	r0x1145,1,0
934 0418 [14] 1688      	ADDC	r0x1146,1,0
935 0419 [14] 1689      	ADDC	r0x1147,1,0
936                     _00190_DS_:
937 041A [14] 317E      	DCF	(_adS + 12),0,0
938 041B [14] 067F      	MVL	0x7f
939 041C [14] 157F      	ADDC	(_adS + 13),0,0
940 041D [14] B22B      	BTSS	_STATUS,1
941 041E [14] 7805      	JMP	_00191_DS_
942 041F [14] 657E      	MVF	(_adS + 12),0,0
943 0420 [14] 6684      	MVF	r0x114A,1,0
944 0421 [14] 657F      	MVF	(_adS + 13),0,0
945 0422 [14] 6685      	MVF	r0x114B,1,0
946 0423 [14] 7807      	JMP	_00192_DS_
947 0424 [00] 0011      _00191_DS_:
948 0425 [14] 257E      	COMF	(_adS + 12),0,0
949 0426 [14] 6684      	MVF	r0x114A,1,0
950 0427 [14] 257F      	COMF	(_adS + 13),0,0
951 0428 [14] 4284      	INSUZ	r0x114A,1,0
952 0429 [14] 0401      	ADDL	0x01
953 042A [14] 6685      	MVF	r0x114B,1,0
954                     _00192_DS_:
955 042B [14] 0600      	MVL	0x00
956 042C [14] AE85      	BTSZ	r0x114B,7
957 042D [14] 06FF      	MVL	0xff
958 042E [14] 6681      	MVF	r0x114D,1,0
959 042F [14] 6680      	MVF	r0x114C,1,0
960 0430 [14] 6484      	MVF	r0x114A,0,0
961 0431 [14] 1086      	ADDF	r0x1144,0,0
962 0432 [14] 668D      	MVF	r0x1140,1,0
963 0433 [14] 6487      	MVF	r0x1145,0,0
964 0434 [14] 1485      	ADDC	r0x114B,0,0
965 0435 [14] 668A      	MVF	r0x1141,1,0
966 0436 [14] 6488      	MVF	r0x1146,0,0
967 0437 [14] 1480      	ADDC	r0x114C,0,0
968 0438 [14] 668B      	MVF	r0x1142,1,0
969 0439 [14] 6489      	MVF	r0x1147,0,0
970 043A [14] 1481      	ADDC	r0x114D,0,0
971 043B [14] 668C      	MVF	r0x1143,1,0
972                     _00124_DS_:
973                     ;	;.line	293; ".\ADC_LCD.c"	LCDDisplay= 56193  - (8.47 * n) ;//y=-0.846x + 5619.3
974 043C [14] C60D      	MVF	r0x1140,0,0
975 043D [14] F00D      	MVF	___slong2fs_STK02,1,0
976 043E [15] C60B      	MVF	r0x1141,0,0
977 043F [15] F00D      	MVF	___slong2fs_STK01,1,0
978 0440 [16] C60D      	MVF	r0x1142,0,0
979 0441 [16] F00D      	MVF	___slong2fs_STK00,1,0
980 0442 [17] 648F      	MVF	r0x1143,0,0
981 0443 [17] CB0C      	CALL	___slong2fs
982                     	.CHKPARA ___slong2fs 4
983 0444 [14] 668C      	MVF	r0x1143,1,0
984 0445 [14] D01E      	MVF	STK02,0,0
985 0446 [14] F00D      	MVF	___fsmul_STK06,1,0
986 0447 [15] D01F      	MVF	STK01,0,0
987 0448 [15] F00D      	MVF	___fsmul_STK05,1,0
988 0449 [16] D020      	MVF	STK00,0,0
989 044A [16] F00D      	MVF	___fsmul_STK04,1,0
990 044B [17] C60F      	MVF	r0x1143,0,0
991 044C [17] F00D      	MVF	___fsmul_STK03,1,0
992 044D [18] C51F      	MVL	0x1f
993                     	MVF	___fsmul_STK02,1,0
994 044E [19] C585      	MVL	0x85
995                     	MVF	___fsmul_STK01,1,0
996 044F [20] C507      	MVL	0x07
997                     	MVF	___fsmul_STK00,1,0
998 0450 [21] 0641      	MVL	0x41
999 0451 [21] C000 FB93 	CALL	___fsmul
1000                     	.CHKPARA ___fsmul 8
1001 0453 [14] 668C      	MVF	r0x1143,1,0
1002 0454 [14] D01E      	MVF	STK02,0,0
1003 0455 [14] F00D      	MVF	___fssub_STK06,1,0
1004 0456 [15] D01F      	MVF	STK01,0,0
1005 0457 [15] F00D      	MVF	___fssub_STK05,1,0
1006 0458 [16] D020      	MVF	STK00,0,0
1007 0459 [16] F00D      	MVF	___fssub_STK04,1,0
1008 045A [17] 648F      	MVF	r0x1143,0,0
1009 045B [17] 660D      	MVF	___fssub_STK03,1,0
1010 045C [18] 0C0D      	CLRF	___fssub_STK02,0
1011 045D [19] C581      	MVL	0x81
1012                     	MVF	___fssub_STK01,1,0
1013 045E [20] C55B      	MVL	0x5b
1014                     	MVF	___fssub_STK00,1,0
1015 045F [21] 0647      	MVL	0x47
1016 0460 [21] CC93      	CALL	___fssub
1017                     	.CHKPARA ___fssub 8
1018 0461 [14] 668C      	MVF	r0x1143,1,0
1019 0462 [14] D01E      	MVF	STK02,0,0
1020                     ;	;.line	294; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
1021 0463 [14] F00D      	MVF	___fs2slong_STK02,1,0
1022 0464 [15] D01F      	MVF	STK01,0,0
1023 0465 [15] F00D      	MVF	___fs2slong_STK01,1,0
1024 0466 [16] D020      	MVF	STK00,0,0
1025 0467 [16] F00D      	MVF	___fs2slong_STK00,1,0
1026 0468 [17] 648F      	MVF	r0x1143,0,0
1027 0469 [17] CB84      	CALL	___fs2slong
1028                     	.CHKPARA ___fs2slong 4
1029 046A [14] 668C      	MVF	r0x1143,1,0
1030 046B [14] D01E      	MVF	STK02,0,0
1031 046C [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1032 046D [15] D01F      	MVF	STK01,0,0
1033 046E [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1034 046F [16] D020      	MVF	STK00,0,0
1035 0470 [16] F00D      	MVF	_Reverse_Data_STK00,1,0
1036 0471 [17] 648F      	MVF	r0x1143,0,0
1037 0472 [17] CB03      	CALL	_Reverse_Data
1038                     	.CHKPARA _Reverse_Data 4
1039 0473 [14] 668C      	MVF	r0x1143,1,0
1040 0474 [14] D01E      	MVF	STK02,0,0
1041 0475 [14] F00D      	MVF	___slong2fs_STK02,1,0
1042 0476 [15] D01F      	MVF	STK01,0,0
1043 0477 [15] F00D      	MVF	___slong2fs_STK01,1,0
1044 0478 [16] D020      	MVF	STK00,0,0
1045 0479 [16] F00D      	MVF	___slong2fs_STK00,1,0
1046 047A [17] 648F      	MVF	r0x1143,0,0
1047 047B [17] CAD4      	CALL	___slong2fs
1048                     	.CHKPARA ___slong2fs 4
1049 047C [14] 668C      	MVF	r0x1143,1,0
1050 047D [14] D01E      	MVF	STK02,0,0
1051                     ;	;.line	295; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
1052 047E [14] F00D      	MVF	___fs2slong_STK02,1,0
1053 047F [15] D01F      	MVF	STK01,0,0
1054 0480 [15] F00D      	MVF	___fs2slong_STK01,1,0
1055 0481 [16] D020      	MVF	STK00,0,0
1056 0482 [16] F00D      	MVF	___fs2slong_STK00,1,0
1057 0483 [17] 648F      	MVF	r0x1143,0,0
1058 0484 [17] CB69      	CALL	___fs2slong
1059                     	.CHKPARA ___fs2slong 4
1060 0485 [14] 668C      	MVF	r0x1143,1,0
1061 0486 [14] 641E      	MVF	STK02,0,0
1062 0487 [14] 660D      	MVF	_UnitConverter_STK02,1,0
1063 0488 [15] 641F      	MVF	STK01,0,0
1064 0489 [15] 660D      	MVF	_UnitConverter_STK01,1,0
1065 048A [16] 6420      	MVF	STK00,0,0
1066 048B [16] 660D      	MVF	_UnitConverter_STK00,1,0
1067 048C [17] 648F      	MVF	r0x1143,0,0
1068 048D [17] CBDD      	CALL	_UnitConverter
1069                     	.CHKPARA _UnitConverter 4
1070 048E [14] 668C      	MVF	r0x1143,1,0
1071 048F [14] D01E      	MVF	STK02,0,0
1072 0490 [14] F00D      	MVF	___slong2fs_STK02,1,0
1073 0491 [15] D01F      	MVF	STK01,0,0
1074 0492 [15] F00D      	MVF	___slong2fs_STK01,1,0
1075 0493 [16] D020      	MVF	STK00,0,0
1076 0494 [16] F00D      	MVF	___slong2fs_STK00,1,0
1077 0495 [17] 648F      	MVF	r0x1143,0,0
1078 0496 [17] CAB9      	CALL	___slong2fs
1079                     	.CHKPARA ___slong2fs 4
1080 0497 [14] 668C      	MVF	r0x1143,1,0
1081 0498 [14] D01E      	MVF	STK02,0,0
1082                     ;	;.line	296; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
1083 0499 [14] F00D      	MVF	___fs2slong_STK02,1,0
1084 049A [15] D01F      	MVF	STK01,0,0
1085 049B [15] F00D      	MVF	___fs2slong_STK01,1,0
1086 049C [16] D020      	MVF	STK00,0,0
1087 049D [16] F00D      	MVF	___fs2slong_STK00,1,0
1088 049E [17] 648F      	MVF	r0x1143,0,0
1089 049F [17] CB4E      	CALL	___fs2slong
1090                     	.CHKPARA ___fs2slong 4
1091 04A0 [14] 668C      	MVF	r0x1143,1,0
1092 04A1 [14] D01E      	MVF	STK02,0,0
1093 04A2 [14] F00D      	MVF	_DisplayNum_STK02,1,0
1094 04A3 [15] D01F      	MVF	STK01,0,0
1095 04A4 [15] F00D      	MVF	_DisplayNum_STK01,1,0
1096 04A5 [16] D020      	MVF	STK00,0,0
1097 04A6 [16] F00D      	MVF	_DisplayNum_STK00,1,0
1098 04A7 [17] 648F      	MVF	r0x1143,0,0
1099 04A8 [17] CB80      	CALL	_DisplayNum
1100                     	.CHKPARA _DisplayNum 4
1101                     ;	;.line	297; ".\ADC_LCD.c"	LowVoltageDisplay();
1102 04A9 [14] CCD6      	CALL	_LowVoltageDisplay
1103                     	.CHKPARA _LowVoltageDisplay 0
1104                     ;	;.line	299; ".\ADC_LCD.c"	Delay(20000);
1105 04AA [14] C520      	MVL	0x20
1106                     	MVF	_Delay_STK00,1,0
1107 04AB [15] 064E      	MVL	0x4e
1108 04AC [15] CCC7      	CALL	_Delay
1109                     	.CHKPARA _Delay 2
1110 04AD [14] 797C      	JMP	_00146_DS_
1111                     _00132_DS_:
1112                     ;	;.line	306; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
1113 04AE [14] D16D      	MVF	_ADC,0,0
1114 04AF [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1115 04B0 [15] D16E      	MVF	(_ADC + 1),0,0
1116 04B1 [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1117 04B2 [16] D16F      	MVF	(_ADC + 2),0,0
1118 04B3 [16] F00D 0011 	MVF	_Reverse_Data_STK00,1,0
1119 04B5 [17] 6570      	MVF	(_ADC + 3),0,0
1120 04B6 [17] CABF 0011 	CALL	_Reverse_Data
1121                     	.CHKPARA _Reverse_Data 4
1122 04B8 [14] 6770      	MVF	(_ADC + 3),1,0
1123 04B9 [14] D020      	MVF	STK00,0,0
1124 04BA [14] F16F      	MVF	(_ADC + 2),1,0
1125 04BB [14] D01F      	MVF	STK01,0,0
1126 04BC [14] F16E      	MVF	(_ADC + 1),1,0
1127 04BD [14] 641E      	MVF	STK02,0,0
1128 04BE [14] 676D      	MVF	_ADC,1,0
1129                     ;	;.line	307; ".\ADC_LCD.c"	DisplayNum(ADC);
1130 04BF [14] 660D      	MVF	_DisplayNum_STK02,1,0
1131 04C0 [15] D16E      	MVF	(_ADC + 1),0,0
1132 04C1 [15] F00D      	MVF	_DisplayNum_STK01,1,0
1133 04C2 [16] D16F      	MVF	(_ADC + 2),0,0
1134 04C3 [16] F00D      	MVF	_DisplayNum_STK00,1,0
1135 04C4 [17] 6570      	MVF	(_ADC + 3),0,0
1136 04C5 [17] CB63      	CALL	_DisplayNum
1137                     	.CHKPARA _DisplayNum 4
1138                     ;	;.line	308; ".\ADC_LCD.c"	LowVoltageDisplay();
1139 04C6 [14] CCB9      	CALL	_LowVoltageDisplay
1140                     	.CHKPARA _LowVoltageDisplay 0
1141                     ;	;.line	310; ".\ADC_LCD.c"	Delay(20000);
1142 04C7 [14] C520      	MVL	0x20
1143                     	MVF	_Delay_STK00,1,0
1144 04C8 [15] 064E      	MVL	0x4e
1145 04C9 [15] CCAA      	CALL	_Delay
1146                     	.CHKPARA _Delay 2
1147 04CA [14] 795F      	JMP	_00146_DS_
1148 04CB [00] 0011      _00141_DS_:
1149                     ;	;.line	316; ".\ADC_LCD.c"	adS.Pressure_sign =1;
1150 04CC [14] 9D78      	BSF	(_adS+6),6
1151                     ;	;.line	319; ".\ADC_LCD.c"	theta= abs(ADC) - adS.m_offset_value;  
1152 04CD [14] 316D      	DCF	_ADC,0,0
1153 04CE [14] 06FF      	MVL	0xff
1154 04CF [14] 156E      	ADDC	(_ADC + 1),0,0
1155 04D0 [14] 06FF      	MVL	0xff
1156 04D1 [14] 156F      	ADDC	(_ADC + 2),0,0
1157 04D2 [14] 067F      	MVL	0x7f
1158 04D3 [14] 1570      	ADDC	(_ADC + 3),0,0
1159 04D4 [14] B22B      	BTSS	_STATUS,1
1160 04D5 [14] 7809      	JMP	_00193_DS_
1161 04D6 [14] 656D      	MVF	_ADC,0,0
1162 04D7 [14] 6686      	MVF	r0x1144,1,0
1163 04D8 [14] 656E      	MVF	(_ADC + 1),0,0
1164 04D9 [14] 6687      	MVF	r0x1145,1,0
1165 04DA [14] 656F      	MVF	(_ADC + 2),0,0
1166 04DB [14] 6688      	MVF	r0x1146,1,0
1167 04DC [14] 6570      	MVF	(_ADC + 3),0,0
1168 04DD [14] 6689      	MVF	r0x1147,1,0
1169 04DE [14] 780E      	JMP	_00194_DS_
1170 04DF [00] 0011      _00193_DS_:
1171 04E0 [14] 256D      	COMF	_ADC,0,0
1172 04E1 [14] 6686      	MVF	r0x1144,1,0
1173 04E2 [14] 256E      	COMF	(_ADC + 1),0,0
1174 04E3 [14] 6687      	MVF	r0x1145,1,0
1175 04E4 [14] 256F      	COMF	(_ADC + 2),0,0
1176 04E5 [14] 6688      	MVF	r0x1146,1,0
1177 04E6 [14] 2570      	COMF	(_ADC + 3),0,0
1178 04E7 [14] 6689      	MVF	r0x1147,1,0
1179 04E8 [14] 3A86      	INF	r0x1144,1,0
1180 04E9 [14] 0600      	MVL	0x00
1181 04EA [14] 1687      	ADDC	r0x1145,1,0
1182 04EB [14] 1688      	ADDC	r0x1146,1,0
1183 04EC [14] 1689      	ADDC	r0x1147,1,0
1184                     _00194_DS_:
1185 04ED [14] 0600      	MVL	0x00
1186 04EE [14] AF7D      	BTSZ	(_adS + 11),7
1187 04EF [14] 06FF      	MVL	0xff
1188 04F0 [14] 6681      	MVF	r0x114D,1,0
1189 04F1 [14] 6680      	MVF	r0x114C,1,0
1190 04F2 [14] 657C      	MVF	(_adS + 10),0,0
1191 04F3 [14] 1A86      	SUBF	r0x1144,1,0
1192 04F4 [14] 657D      	MVF	(_adS + 11),0,0
1193 04F5 [14] 1E87      	SUBC	r0x1145,1,0
1194 04F6 [14] 6480      	MVF	r0x114C,0,0
1195 04F7 [14] 1E88      	SUBC	r0x1146,1,0
1196 04F8 [14] 6481      	MVF	r0x114D,0,0
1197 04F9 [14] 1E89      	SUBC	r0x1147,1,0
1198                     ;	;.line	320; ".\ADC_LCD.c"	if(adS.minus_revise_flag==1){
1199 04FA [14] B978      	BTSS	(_adS+6),4
1200 04FB [14] 78E8      	JMP	_00138_DS_
1201                     ;	;.line	323; ".\ADC_LCD.c"	if(delta >=0 ){
1202 04FC [14] AF70      	BTSZ	(_ADC + 3),7
1203 04FD [14] 7873      	JMP	_00135_DS_
1204                     ;	;.line	324; ".\ADC_LCD.c"	LCDDisplay= 200 - 0.126*theta ;//y = -0.0126x + 20.075
1205 04FE [14] C606      	MVF	r0x1144,0,0
1206 04FF [14] F00D      	MVF	___slong2fs_STK02,1,0
1207 0500 [15] C608      	MVF	r0x1145,0,0
1208 0501 [15] F00D      	MVF	___slong2fs_STK01,1,0
1209 0502 [16] C60A      	MVF	r0x1146,0,0
1210 0503 [16] F00D      	MVF	___slong2fs_STK00,1,0
1211 0504 [17] 648C      	MVF	r0x1147,0,0
1212 0505 [17] CA4A      	CALL	___slong2fs
1213                     	.CHKPARA ___slong2fs 4
1214 0506 [14] 668C      	MVF	r0x1143,1,0
1215 0507 [14] D01E      	MVF	STK02,0,0
1216 0508 [14] F00D      	MVF	___fsmul_STK06,1,0
1217 0509 [15] D01F      	MVF	STK01,0,0
1218 050A [15] F00D      	MVF	___fsmul_STK05,1,0
1219 050B [16] D020      	MVF	STK00,0,0
1220 050C [16] F00D      	MVF	___fsmul_STK04,1,0
1221 050D [17] C60F      	MVF	r0x1143,0,0
1222 050E [17] F00D      	MVF	___fsmul_STK03,1,0
1223 050F [18] C525      	MVL	0x25
1224                     	MVF	___fsmul_STK02,1,0
1225 0510 [19] C506      	MVL	0x06
1226                     	MVF	___fsmul_STK01,1,0
1227 0511 [20] C501      	MVL	0x01
1228                     	MVF	___fsmul_STK00,1,0
1229 0512 [21] 063E      	MVL	0x3e
1230 0513 [21] C000 FB93 	CALL	___fsmul
1231                     	.CHKPARA ___fsmul 8
1232 0515 [14] 668C      	MVF	r0x1143,1,0
1233 0516 [14] D01E      	MVF	STK02,0,0
1234 0517 [14] F00D      	MVF	___fssub_STK06,1,0
1235 0518 [15] D01F      	MVF	STK01,0,0
1236 0519 [15] F00D      	MVF	___fssub_STK05,1,0
1237 051A [16] D020      	MVF	STK00,0,0
1238 051B [16] F00D      	MVF	___fssub_STK04,1,0
1239 051C [17] 648F      	MVF	r0x1143,0,0
1240 051D [17] 660D      	MVF	___fssub_STK03,1,0
1241 051E [18] 0C0D      	CLRF	___fssub_STK02,0
1242 051F [19] 0C0D      	CLRF	___fssub_STK01,0
1243 0520 [20] C548      	MVL	0x48
1244                     	MVF	___fssub_STK00,1,0
1245 0521 [21] 0643      	MVL	0x43
1246 0522 [21] C000 F0F4 	CALL	___fssub
1247                     	.CHKPARA ___fssub 8
1248 0524 [14] 668C      	MVF	r0x1143,1,0
1249 0525 [14] D01E      	MVF	STK02,0,0
1250                     ;	;.line	325; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
1251 0526 [14] F00D      	MVF	___fs2slong_STK02,1,0
1252 0527 [15] D01F      	MVF	STK01,0,0
1253 0528 [15] F00D      	MVF	___fs2slong_STK01,1,0
1254 0529 [16] D020      	MVF	STK00,0,0
1255 052A [16] F00D      	MVF	___fs2slong_STK00,1,0
1256 052B [17] 648F      	MVF	r0x1143,0,0
1257 052C [17] CAC1      	CALL	___fs2slong
1258                     	.CHKPARA ___fs2slong 4
1259 052D [14] 668C      	MVF	r0x1143,1,0
1260 052E [14] D01E      	MVF	STK02,0,0
1261 052F [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1262 0530 [15] D01F      	MVF	STK01,0,0
1263 0531 [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1264 0532 [16] D020      	MVF	STK00,0,0
1265 0533 [16] F00D      	MVF	_Reverse_Data_STK00,1,0
1266 0534 [17] 648F      	MVF	r0x1143,0,0
1267 0535 [17] CA40      	CALL	_Reverse_Data
1268                     	.CHKPARA _Reverse_Data 4
1269 0536 [14] 668C      	MVF	r0x1143,1,0
1270 0537 [14] D01E      	MVF	STK02,0,0
1271 0538 [14] F00D      	MVF	___slong2fs_STK02,1,0
1272 0539 [15] D01F      	MVF	STK01,0,0
1273 053A [15] F00D      	MVF	___slong2fs_STK01,1,0
1274 053B [16] D020      	MVF	STK00,0,0
1275 053C [16] F00D      	MVF	___slong2fs_STK00,1,0
1276 053D [17] 648F      	MVF	r0x1143,0,0
1277 053E [17] CA11      	CALL	___slong2fs
1278                     	.CHKPARA ___slong2fs 4
1279 053F [14] 668C      	MVF	r0x1143,1,0
1280 0540 [14] D01E      	MVF	STK02,0,0
1281                     ;	;.line	326; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
1282 0541 [14] F00D      	MVF	___fs2slong_STK02,1,0
1283 0542 [15] D01F      	MVF	STK01,0,0
1284 0543 [15] F00D      	MVF	___fs2slong_STK01,1,0
1285 0544 [16] D020      	MVF	STK00,0,0
1286 0545 [16] F00D      	MVF	___fs2slong_STK00,1,0
1287 0546 [17] 648F      	MVF	r0x1143,0,0
1288 0547 [17] CAA6      	CALL	___fs2slong
1289                     	.CHKPARA ___fs2slong 4
1290 0548 [14] 668C      	MVF	r0x1143,1,0
1291 0549 [14] 641E      	MVF	STK02,0,0
1292 054A [14] 660D      	MVF	_UnitConverter_STK02,1,0
1293 054B [15] 641F      	MVF	STK01,0,0
1294 054C [15] 660D      	MVF	_UnitConverter_STK01,1,0
1295 054D [16] 6420      	MVF	STK00,0,0
1296 054E [16] 660D      	MVF	_UnitConverter_STK00,1,0
1297 054F [17] 648F      	MVF	r0x1143,0,0
1298 0550 [17] CB1A      	CALL	_UnitConverter
1299                     	.CHKPARA _UnitConverter 4
1300 0551 [14] 668C      	MVF	r0x1143,1,0
1301 0552 [14] D01E      	MVF	STK02,0,0
1302 0553 [14] F00D      	MVF	___slong2fs_STK02,1,0
1303 0554 [15] D01F      	MVF	STK01,0,0
1304 0555 [15] F00D      	MVF	___slong2fs_STK01,1,0
1305 0556 [16] D020      	MVF	STK00,0,0
1306 0557 [16] F00D      	MVF	___slong2fs_STK00,1,0
1307 0558 [17] 648F      	MVF	r0x1143,0,0
1308 0559 [17] C9F6      	CALL	___slong2fs
1309                     	.CHKPARA ___slong2fs 4
1310 055A [14] 668C      	MVF	r0x1143,1,0
1311 055B [14] D01E      	MVF	STK02,0,0
1312                     ;	;.line	327; ".\ADC_LCD.c"	DisplayNum(LCDDisplay);
1313 055C [14] F00D      	MVF	___fs2slong_STK02,1,0
1314 055D [15] D01F      	MVF	STK01,0,0
1315 055E [15] F00D      	MVF	___fs2slong_STK01,1,0
1316 055F [16] D020      	MVF	STK00,0,0
1317 0560 [16] F00D      	MVF	___fs2slong_STK00,1,0
1318 0561 [17] 648F      	MVF	r0x1143,0,0
1319 0562 [17] CA8B      	CALL	___fs2slong
1320                     	.CHKPARA ___fs2slong 4
1321 0563 [14] 668C      	MVF	r0x1143,1,0
1322 0564 [14] D01E      	MVF	STK02,0,0
1323 0565 [14] F00D      	MVF	_DisplayNum_STK02,1,0
1324 0566 [15] D01F      	MVF	STK01,0,0
1325 0567 [15] F00D      	MVF	_DisplayNum_STK01,1,0
1326 0568 [16] D020      	MVF	STK00,0,0
1327 0569 [16] F00D      	MVF	_DisplayNum_STK00,1,0
1328 056A [17] 648F      	MVF	r0x1143,0,0
1329 056B [17] CABD      	CALL	_DisplayNum
1330                     	.CHKPARA _DisplayNum 4
1331                     ;	;.line	328; ".\ADC_LCD.c"	LowVoltageDisplay();
1332 056C [14] CC13      	CALL	_LowVoltageDisplay
1333                     	.CHKPARA _LowVoltageDisplay 0
1334                     ;	;.line	330; ".\ADC_LCD.c"	Delay(20000);
1335 056D [14] C520      	MVL	0x20
1336                     	MVF	_Delay_STK00,1,0
1337 056E [15] 064E      	MVL	0x4e
1338 056F [15] CC04      	CALL	_Delay
1339                     	.CHKPARA _Delay 2
1340 0570 [14] 78B9      	JMP	_00146_DS_
1341                     _00135_DS_:
1342                     ;	;.line	341; ".\ADC_LCD.c"	LCDDisplay= 0.125*theta + 204; //y = 0.0125x + 19.849//y = 0.0125x + 19.854
1343 0571 [14] C606      	MVF	r0x1144,0,0
1344 0572 [14] F00D      	MVF	___slong2fs_STK02,1,0
1345 0573 [15] C608      	MVF	r0x1145,0,0
1346 0574 [15] F00D      	MVF	___slong2fs_STK01,1,0
1347 0575 [16] C60A      	MVF	r0x1146,0,0
1348 0576 [16] F00D      	MVF	___slong2fs_STK00,1,0
1349 0577 [17] 648C      	MVF	r0x1147,0,0
1350 0578 [17] C9D7      	CALL	___slong2fs
1351                     	.CHKPARA ___slong2fs 4
1352 0579 [14] 668C      	MVF	r0x1143,1,0
1353 057A [14] D01E      	MVF	STK02,0,0
1354 057B [14] F00D      	MVF	___fsmul_STK06,1,0
1355 057C [15] D01F      	MVF	STK01,0,0
1356 057D [15] F00D      	MVF	___fsmul_STK05,1,0
1357 057E [16] D020      	MVF	STK00,0,0
1358 057F [16] F00D      	MVF	___fsmul_STK04,1,0
1359 0580 [17] 648F      	MVF	r0x1143,0,0
1360 0581 [17] 660D      	MVF	___fsmul_STK03,1,0
1361 0582 [18] 0C0D      	CLRF	___fsmul_STK02,0
1362 0583 [19] 0C0D      	CLRF	___fsmul_STK01,0
1363 0584 [20] 0C0D      	CLRF	___fsmul_STK00,0
1364 0585 [21] 063E      	MVL	0x3e
1365 0586 [21] C000 FB93 	CALL	___fsmul
1366                     	.CHKPARA ___fsmul 8
1367 0588 [14] 668C      	MVF	r0x1143,1,0
1368 0589 [14] 0C0D      	CLRF	___fsadd_STK06,0
1369 058A [15] 0C0D      	CLRF	___fsadd_STK05,0
1370 058B [16] C54C      	MVL	0x4c
1371                     	MVF	___fsadd_STK04,1,0
1372 058C [17] C543      	MVL	0x43
1373                     	MVF	___fsadd_STK03,1,0
1374 058D [18] D01E      	MVF	STK02,0,0
1375 058E [18] F00D      	MVF	___fsadd_STK02,1,0
1376 058F [19] D01F      	MVF	STK01,0,0
1377 0590 [19] F00D      	MVF	___fsadd_STK01,1,0
1378 0591 [20] D020      	MVF	STK00,0,0
1379 0592 [20] F00D      	MVF	___fsadd_STK00,1,0
1380 0593 [21] 6493      	MVF	r0x1143,0,0
1381 0594 [21] CB6A      	CALL	___fsadd
1382                     	.CHKPARA ___fsadd 8
1383 0595 [14] 668C      	MVF	r0x1143,1,0
1384 0596 [14] D01E      	MVF	STK02,0,0
1385                     ;	;.line	342; ".\ADC_LCD.c"	LCDDisplay=Reverse_Data(LCDDisplay);
1386 0597 [14] F00D      	MVF	___fs2slong_STK02,1,0
1387 0598 [15] D01F      	MVF	STK01,0,0
1388 0599 [15] F00D      	MVF	___fs2slong_STK01,1,0
1389 059A [16] D020      	MVF	STK00,0,0
1390 059B [16] F00D      	MVF	___fs2slong_STK00,1,0
1391 059C [17] 648F      	MVF	r0x1143,0,0
1392 059D [17] CA50      	CALL	___fs2slong
1393                     	.CHKPARA ___fs2slong 4
1394 059E [14] 668C      	MVF	r0x1143,1,0
1395 059F [14] D01E      	MVF	STK02,0,0
1396 05A0 [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1397 05A1 [15] D01F      	MVF	STK01,0,0
1398 05A2 [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1399 05A3 [16] D020      	MVF	STK00,0,0
1400 05A4 [16] F00D      	MVF	_Reverse_Data_STK00,1,0
1401 05A5 [17] 648F      	MVF	r0x1143,0,0
1402 05A6 [17] C9CF      	CALL	_Reverse_Data
1403                     	.CHKPARA _Reverse_Data 4
1404 05A7 [14] 668C      	MVF	r0x1143,1,0
1405 05A8 [14] D01E      	MVF	STK02,0,0
1406 05A9 [14] F00D      	MVF	___slong2fs_STK02,1,0
1407 05AA [15] D01F      	MVF	STK01,0,0
1408 05AB [15] F00D      	MVF	___slong2fs_STK01,1,0
1409 05AC [16] D020      	MVF	STK00,0,0
1410 05AD [16] F00D      	MVF	___slong2fs_STK00,1,0
1411 05AE [17] 648F      	MVF	r0x1143,0,0
1412 05AF [17] C9A0      	CALL	___slong2fs
1413                     	.CHKPARA ___slong2fs 4
1414 05B0 [14] 668C      	MVF	r0x1143,1,0
1415 05B1 [14] D01E      	MVF	STK02,0,0
1416                     ;	;.line	343; ".\ADC_LCD.c"	LCDDisplay=UnitConverter(LCDDisplay);
1417 05B2 [14] F00D      	MVF	___fs2slong_STK02,1,0
1418 05B3 [15] D01F      	MVF	STK01,0,0
1419 05B4 [15] F00D      	MVF	___fs2slong_STK01,1,0
1420 05B5 [16] D020      	MVF	STK00,0,0
1421 05B6 [16] F00D      	MVF	___fs2slong_STK00,1,0
1422 05B7 [17] 648F      	MVF	r0x1143,0,0
1423 05B8 [17] CA35      	CALL	___fs2slong
1424                     	.CHKPARA ___fs2slong 4
1425 05B9 [14] 668C      	MVF	r0x1143,1,0
1426 05BA [14] 641E      	MVF	STK02,0,0
1427 05BB [14] 660D      	MVF	_UnitConverter_STK02,1,0
1428 05BC [15] 641F      	MVF	STK01,0,0
1429 05BD [15] 660D      	MVF	_UnitConverter_STK01,1,0
1430 05BE [16] 6420      	MVF	STK00,0,0
1431 05BF [16] 660D      	MVF	_UnitConverter_STK00,1,0
1432 05C0 [17] 648F      	MVF	r0x1143,0,0
1433 05C1 [17] CAA9      	CALL	_UnitConverter
1434                     	.CHKPARA _UnitConverter 4
1435 05C2 [14] 668C      	MVF	r0x1143,1,0
1436 05C3 [14] D01E      	MVF	STK02,0,0
1437 05C4 [14] F00D      	MVF	___slong2fs_STK02,1,0
1438 05C5 [15] D01F      	MVF	STK01,0,0
1439 05C6 [15] F00D      	MVF	___slong2fs_STK01,1,0
1440 05C7 [16] D020      	MVF	STK00,0,0
1441 05C8 [16] F00D      	MVF	___slong2fs_STK00,1,0
1442 05C9 [17] 648F      	MVF	r0x1143,0,0
1443 05CA [17] C985      	CALL	___slong2fs
1444                     	.CHKPARA ___slong2fs 4
1445 05CB [14] 668C      	MVF	r0x1143,1,0
1446 05CC [14] D01E      	MVF	STK02,0,0
1447                     ;	;.line	344; ".\ADC_LCD.c"	DisplayNum( LCDDisplay);
1448 05CD [14] F00D      	MVF	___fs2slong_STK02,1,0
1449 05CE [15] D01F      	MVF	STK01,0,0
1450 05CF [15] F00D      	MVF	___fs2slong_STK01,1,0
1451 05D0 [16] D020      	MVF	STK00,0,0
1452 05D1 [16] F00D      	MVF	___fs2slong_STK00,1,0
1453 05D2 [17] 648F      	MVF	r0x1143,0,0
1454 05D3 [17] CA1A      	CALL	___fs2slong
1455                     	.CHKPARA ___fs2slong 4
1456 05D4 [14] 668C      	MVF	r0x1143,1,0
1457 05D5 [14] D01E      	MVF	STK02,0,0
1458 05D6 [14] F00D      	MVF	_DisplayNum_STK02,1,0
1459 05D7 [15] D01F      	MVF	STK01,0,0
1460 05D8 [15] F00D      	MVF	_DisplayNum_STK01,1,0
1461 05D9 [16] D020      	MVF	STK00,0,0
1462 05DA [16] F00D      	MVF	_DisplayNum_STK00,1,0
1463 05DB [17] 648F      	MVF	r0x1143,0,0
1464 05DC [17] CA4C      	CALL	_DisplayNum
1465                     	.CHKPARA _DisplayNum 4
1466                     ;	;.line	345; ".\ADC_LCD.c"	LowVoltageDisplay();
1467 05DD [14] C000 F180 	CALL	_LowVoltageDisplay
1468                     	.CHKPARA _LowVoltageDisplay 0
1469                     ;	;.line	347; ".\ADC_LCD.c"	Delay(20000);
1470 05DF [14] C520      	MVL	0x20
1471                     	MVF	_Delay_STK00,1,0
1472 05E0 [15] 064E      	MVL	0x4e
1473 05E1 [15] C000 F174 	CALL	_Delay
1474                     	.CHKPARA _Delay 2
1475 05E3 [14] 7846      	JMP	_00146_DS_
1476 05E4 [00] 0011      _00138_DS_:
1477                     ;	;.line	353; ".\ADC_LCD.c"	ADC = abs(ADC);
1478 05E5 [14] 316D      	DCF	_ADC,0,0
1479 05E6 [14] 06FF      	MVL	0xff
1480 05E7 [14] 156E      	ADDC	(_ADC + 1),0,0
1481 05E8 [14] 06FF      	MVL	0xff
1482 05E9 [14] 156F      	ADDC	(_ADC + 2),0,0
1483 05EA [14] 067F      	MVL	0x7f
1484 05EB [14] 1570      	ADDC	(_ADC + 3),0,0
1485 05EC [14] B22B      	BTSS	_STATUS,1
1486 05ED [14] 7809      	JMP	_00195_DS_
1487 05EE [14] 656D      	MVF	_ADC,0,0
1488 05EF [14] 668D      	MVF	r0x1140,1,0
1489 05F0 [14] 656E      	MVF	(_ADC + 1),0,0
1490 05F1 [14] 668A      	MVF	r0x1141,1,0
1491 05F2 [14] 656F      	MVF	(_ADC + 2),0,0
1492 05F3 [14] 668B      	MVF	r0x1142,1,0
1493 05F4 [14] 6570      	MVF	(_ADC + 3),0,0
1494 05F5 [14] 668C      	MVF	r0x1143,1,0
1495 05F6 [14] 780E      	JMP	_00196_DS_
1496 05F7 [00] 0011      _00195_DS_:
1497 05F8 [14] 256D      	COMF	_ADC,0,0
1498 05F9 [14] 668D      	MVF	r0x1140,1,0
1499 05FA [14] 256E      	COMF	(_ADC + 1),0,0
1500 05FB [14] 668A      	MVF	r0x1141,1,0
1501 05FC [14] 256F      	COMF	(_ADC + 2),0,0
1502 05FD [14] 668B      	MVF	r0x1142,1,0
1503 05FE [14] 2570      	COMF	(_ADC + 3),0,0
1504 05FF [14] 668C      	MVF	r0x1143,1,0
1505 0600 [14] 3A8D      	INF	r0x1140,1,0
1506 0601 [14] 0600      	MVL	0x00
1507 0602 [14] 168A      	ADDC	r0x1141,1,0
1508 0603 [14] 168B      	ADDC	r0x1142,1,0
1509 0604 [14] 168C      	ADDC	r0x1143,1,0
1510                     _00196_DS_:
1511 0605 [14] C60D      	MVF	r0x1140,0,0
1512 0606 [14] F16D      	MVF	_ADC,1,0
1513 0607 [14] C60A      	MVF	r0x1141,0,0
1514 0608 [14] F16E      	MVF	(_ADC + 1),1,0
1515 0609 [14] C60B      	MVF	r0x1142,0,0
1516 060A [14] F16F      	MVF	(_ADC + 2),1,0
1517 060B [14] C60C      	MVF	r0x1143,0,0
1518 060C [14] F170      	MVF	(_ADC + 3),1,0
1519                     ;	;.line	354; ".\ADC_LCD.c"	ADC=Reverse_Data(ADC);
1520 060D [14] D16D      	MVF	_ADC,0,0
1521 060E [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1522 060F [15] D16E      	MVF	(_ADC + 1),0,0
1523 0610 [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1524 0611 [16] D16F      	MVF	(_ADC + 2),0,0
1525 0612 [16] F00D      	MVF	_Reverse_Data_STK00,1,0
1526 0613 [17] 6570      	MVF	(_ADC + 3),0,0
1527 0614 [17] C961 0011 	CALL	_Reverse_Data
1528                     	.CHKPARA _Reverse_Data 4
1529 0616 [14] 6770      	MVF	(_ADC + 3),1,0
1530 0617 [14] D020      	MVF	STK00,0,0
1531 0618 [14] F16F      	MVF	(_ADC + 2),1,0
1532 0619 [14] D01F      	MVF	STK01,0,0
1533 061A [14] F16E      	MVF	(_ADC + 1),1,0
1534 061B [14] 641E      	MVF	STK02,0,0
1535 061C [14] 676D      	MVF	_ADC,1,0
1536                     ;	;.line	355; ".\ADC_LCD.c"	DisplayNum(ADC);
1537 061D [14] 660D      	MVF	_DisplayNum_STK02,1,0
1538 061E [15] D16E      	MVF	(_ADC + 1),0,0
1539 061F [15] F00D      	MVF	_DisplayNum_STK01,1,0
1540 0620 [16] D16F      	MVF	(_ADC + 2),0,0
1541 0621 [16] F00D      	MVF	_DisplayNum_STK00,1,0
1542 0622 [17] 6570      	MVF	(_ADC + 3),0,0
1543 0623 [17] CA05      	CALL	_DisplayNum
1544                     	.CHKPARA _DisplayNum 4
1545                     ;	;.line	356; ".\ADC_LCD.c"	LowVoltageDisplay();
1546 0624 [14] C000 F180 	CALL	_LowVoltageDisplay
1547                     	.CHKPARA _LowVoltageDisplay 0
1548                     ;	;.line	358; ".\ADC_LCD.c"	Delay(20000);
1549 0626 [14] C520      	MVL	0x20
1550                     	MVF	_Delay_STK00,1,0
1551 0627 [15] 064E      	MVL	0x4e
1552 0628 [15] C000 F174 	CALL	_Delay
1553                     	.CHKPARA _Delay 2
1554 062A [00] 0011      _00146_DS_:
1555                     ;	;.line	364; ".\ADC_LCD.c"	if(adS.zeroPoint_Mode == 1){ /*zero point mode */
1556 062B [14] B375      	BTSS	(_adS+3),1
1557 062C [14] 78C9      	JMP	_00155_DS_
1558                     ;	;.line	366; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
1559 062D [14] 0D77      	CLRF	(_adS + 5),0
1560                     ;	;.line	367; ".\ADC_LCD.c"	adS.zeroPoint_Mode =0;
1561 062E [14] 8375      	BCF	(_adS+3),1
1562                     ;	;.line	368; ".\ADC_LCD.c"	adS.testMode=0;
1563 062F [14] 8175      	BCF	(_adS+3),0
1564                     ;	;.line	369; ".\ADC_LCD.c"	ADC=ADC>>6;
1565 0630 [14] 616D      	SWPF	_ADC,0,0
1566 0631 [14] 010F      	ANDL	0x0f
1567 0632 [14] 676D      	MVF	_ADC,1,0
1568 0633 [14] 616E      	SWPF	(_ADC + 1),0,0
1569 0634 [14] 676E      	MVF	(_ADC + 1),1,0
1570 0635 [14] 01F0      	ANDL	0xf0
1571 0636 [14] 2F6D      	IORF	_ADC,1,0
1572 0637 [14] 236E      	XORF	(_ADC + 1),1,0
1573 0638 [14] 616F      	SWPF	(_ADC + 2),0,0
1574 0639 [14] 676F      	MVF	(_ADC + 2),1,0
1575 063A [14] 01F0      	ANDL	0xf0
1576 063B [14] 2F6E      	IORF	(_ADC + 1),1,0
1577 063C [14] 236F      	XORF	(_ADC + 2),1,0
1578 063D [14] 6170      	SWPF	(_ADC + 3),0,0
1579 063E [14] 6770      	MVF	(_ADC + 3),1,0
1580 063F [14] 01F0      	ANDL	0xf0
1581 0640 [14] 2F6F      	IORF	(_ADC + 2),1,0
1582 0641 [14] 2370      	XORF	(_ADC + 3),1,0
1583 0642 [14] 06F0      	MVL	0xf0
1584 0643 [14] A770      	BTSZ	(_ADC + 3),3
1585 0644 [14] 2F70      	IORF	(_ADC + 3),1,0
1586 0645 [14] 5F70      	ARRC	(_ADC + 3),1,0
1587 0646 [14] 536F      	RRFC	(_ADC + 2),1,0
1588 0647 [14] 536E      	RRFC	(_ADC + 1),1,0
1589 0648 [14] 536D      	RRFC	_ADC,1,0
1590 0649 [14] 5F70      	ARRC	(_ADC + 3),1,0
1591 064A [14] 536F      	RRFC	(_ADC + 2),1,0
1592 064B [14] 536E      	RRFC	(_ADC + 1),1,0
1593 064C [14] 536D      	RRFC	_ADC,1,0
1594                     ;	;.line	370; ".\ADC_LCD.c"	ADC = ADC * 0.1;
1595 064D [14] D16D      	MVF	_ADC,0,0
1596 064E [14] F00D      	MVF	___slong2fs_STK02,1,0
1597 064F [15] D16E      	MVF	(_ADC + 1),0,0
1598 0650 [15] F00D      	MVF	___slong2fs_STK01,1,0
1599 0651 [16] D16F      	MVF	(_ADC + 2),0,0
1600 0652 [16] F00D      	MVF	___slong2fs_STK00,1,0
1601 0653 [17] 6570      	MVF	(_ADC + 3),0,0
1602 0654 [17] C8FB      	CALL	___slong2fs
1603                     	.CHKPARA ___slong2fs 4
1604 0655 [14] 668C      	MVF	r0x1143,1,0
1605 0656 [14] D01E      	MVF	STK02,0,0
1606 0657 [14] F00D      	MVF	___fsmul_STK06,1,0
1607 0658 [15] D01F      	MVF	STK01,0,0
1608 0659 [15] F00D      	MVF	___fsmul_STK05,1,0
1609 065A [16] D020      	MVF	STK00,0,0
1610 065B [16] F00D      	MVF	___fsmul_STK04,1,0
1611 065C [17] C60F      	MVF	r0x1143,0,0
1612 065D [17] F00D      	MVF	___fsmul_STK03,1,0
1613 065E [18] C5CD      	MVL	0xcd
1614                     	MVF	___fsmul_STK02,1,0
1615 065F [19] C5CC      	MVL	0xcc
1616                     	MVF	___fsmul_STK01,1,0
1617 0660 [20] C5CC      	MVF	___fsmul_STK00,1,0
1618 0661 [21] 063D      	MVL	0x3d
1619 0662 [21] C000 FB93 	CALL	___fsmul
1620                     	.CHKPARA ___fsmul 8
1621 0664 [14] 668C      	MVF	r0x1143,1,0
1622 0665 [14] D01E      	MVF	STK02,0,0
1623 0666 [14] F00D      	MVF	___fs2slong_STK02,1,0
1624 0667 [15] D01F      	MVF	STK01,0,0
1625 0668 [15] F00D      	MVF	___fs2slong_STK01,1,0
1626 0669 [16] D020      	MVF	STK00,0,0
1627 066A [16] F00D      	MVF	___fs2slong_STK00,1,0
1628 066B [17] 648F      	MVF	r0x1143,0,0
1629 066C [17] C981 0011 	CALL	___fs2slong
1630                     	.CHKPARA ___fs2slong 4
1631 066E [14] 6770      	MVF	(_ADC + 3),1,0
1632 066F [14] D020      	MVF	STK00,0,0
1633 0670 [14] F16F      	MVF	(_ADC + 2),1,0
1634 0671 [14] D01F      	MVF	STK01,0,0
1635 0672 [14] F16E      	MVF	(_ADC + 1),1,0
1636 0673 [14] 641E      	MVF	STK02,0,0
1637 0674 [14] 676D      	MVF	_ADC,1,0
1638                     ;	;.line	371; ".\ADC_LCD.c"	if((ADC<0)||(ADC>0x80000000))
1639 0675 [14] AF70      	BTSZ	(_ADC + 3),7
1640 0676 [14] 7809      	JMP	_00147_DS_
1641 0677 [14] 316D      	DCF	_ADC,0,0
1642 0678 [14] 06FF      	MVL	0xff
1643 0679 [14] 156E      	ADDC	(_ADC + 1),0,0
1644 067A [14] 06FF      	MVL	0xff
1645 067B [14] 156F      	ADDC	(_ADC + 2),0,0
1646 067C [14] 067F      	MVL	0x7f
1647 067D [14] 1570      	ADDC	(_ADC + 3),0,0
1648 067E [14] B82B      	BTSS	_STATUS,4
1649 067F [14] 7802      	JMP	_00148_DS_
1650                     _00147_DS_:
1651                     ;	;.line	374; ".\ADC_LCD.c"	adS.Pressure_sign =1;
1652 0680 [14] 9D78      	BSF	(_adS+6),6
1653 0681 [14] 7802      	JMP	_00149_DS_
1654 0682 [00] 0011      _00148_DS_:
1655                     ;	;.line	378; ".\ADC_LCD.c"	adS.Pressure_sign =0;
1656 0683 [14] 8D78      	BCF	(_adS+6),6
1657                     _00149_DS_:
1658                     ;	;.line	384; ".\ADC_LCD.c"	if(adS.Pressure_sign==1){ /*negative pressure "-"*/
1659 0684 [14] BD78      	BTSS	(_adS+6),6
1660 0685 [14] 7826      	JMP	_00152_DS_
1661                     ;	;.line	385; ".\ADC_LCD.c"	adS.m_offset_value = abs(ADC) - STD_NEGATIVE_VOLTAGE + 1;
1662 0686 [14] 316D      	DCF	_ADC,0,0
1663 0687 [14] 06FF      	MVL	0xff
1664 0688 [14] 156E      	ADDC	(_ADC + 1),0,0
1665 0689 [14] 06FF      	MVL	0xff
1666 068A [14] 156F      	ADDC	(_ADC + 2),0,0
1667 068B [14] 067F      	MVL	0x7f
1668 068C [14] 1570      	ADDC	(_ADC + 3),0,0
1669 068D [14] B22B      	BTSS	_STATUS,1
1670 068E [14] 7805      	JMP	_00197_DS_
1671 068F [14] 656D      	MVF	_ADC,0,0
1672 0690 [14] 668D      	MVF	r0x1140,1,0
1673 0691 [14] 656E      	MVF	(_ADC + 1),0,0
1674 0692 [14] 668A      	MVF	r0x1141,1,0
1675 0693 [14] 780E      	JMP	_00198_DS_
1676 0694 [00] 0011      _00197_DS_:
1677 0695 [14] 256D      	COMF	_ADC,0,0
1678 0696 [14] 668D      	MVF	r0x1140,1,0
1679 0697 [14] 256E      	COMF	(_ADC + 1),0,0
1680 0698 [14] 668A      	MVF	r0x1141,1,0
1681 0699 [14] 256F      	COMF	(_ADC + 2),0,0
1682 069A [14] 668B      	MVF	r0x1142,1,0
1683 069B [14] 2570      	COMF	(_ADC + 3),0,0
1684 069C [14] 668C      	MVF	r0x1143,1,0
1685 069D [14] 3A8D      	INF	r0x1140,1,0
1686 069E [14] 0600      	MVL	0x00
1687 069F [14] 168A      	ADDC	r0x1141,1,0
1688 06A0 [14] 168B      	ADDC	r0x1142,1,0
1689 06A1 [14] 168C      	ADDC	r0x1143,1,0
1690                     _00198_DS_:
1691 06A2 [14] 0637      	MVL	0x37
1692 06A3 [14] 108D      	ADDF	r0x1140,0,0
1693 06A4 [14] 668D      	MVF	r0x1140,1,0
1694 06A5 [14] 06E7      	MVL	0xe7
1695 06A6 [14] 148A      	ADDC	r0x1141,0,0
1696 06A7 [14] C60D F17C 	MVSF	r0x1140,(_adS + 10)
1697 06A9 [14] 677D      	MVF	(_adS + 11),1,0
1698                     ;	;.line	386; ".\ADC_LCD.c"	adS.minus_revise_flag=1;
1699 06AA [14] 9978      	BSF	(_adS+6),4
1700 06AB [14] 784A      	JMP	_00155_DS_
1701 06AC [00] 0011      _00152_DS_:
1702                     ;	;.line	392; ".\ADC_LCD.c"	adS.p_offset_value= abs(STD_VALUE) -abs(ADC) + 1; 
1703 06AD [14] 316D      	DCF	_ADC,0,0
1704 06AE [14] 06FF      	MVL	0xff
1705 06AF [14] 156E      	ADDC	(_ADC + 1),0,0
1706 06B0 [14] 06FF      	MVL	0xff
1707 06B1 [14] 156F      	ADDC	(_ADC + 2),0,0
1708 06B2 [14] 067F      	MVL	0x7f
1709 06B3 [14] 1570      	ADDC	(_ADC + 3),0,0
1710 06B4 [14] B22B      	BTSS	_STATUS,1
1711 06B5 [14] 7805      	JMP	_00199_DS_
1712 06B6 [14] 656D      	MVF	_ADC,0,0
1713 06B7 [14] 668D      	MVF	r0x1140,1,0
1714 06B8 [14] 656E      	MVF	(_ADC + 1),0,0
1715 06B9 [14] 668A      	MVF	r0x1141,1,0
1716 06BA [14] 780E      	JMP	_00200_DS_
1717 06BB [00] 0011      _00199_DS_:
1718 06BC [14] 256D      	COMF	_ADC,0,0
1719 06BD [14] 668D      	MVF	r0x1140,1,0
1720 06BE [14] 256E      	COMF	(_ADC + 1),0,0
1721 06BF [14] 668A      	MVF	r0x1141,1,0
1722 06C0 [14] 256F      	COMF	(_ADC + 2),0,0
1723 06C1 [14] 6686      	MVF	r0x1144,1,0
1724 06C2 [14] 2570      	COMF	(_ADC + 3),0,0
1725 06C3 [14] 6687      	MVF	r0x1145,1,0
1726 06C4 [14] 3A8D      	INF	r0x1140,1,0
1727 06C5 [14] 0600      	MVL	0x00
1728 06C6 [14] 168A      	ADDC	r0x1141,1,0
1729 06C7 [14] 1686      	ADDC	r0x1144,1,0
1730 06C8 [14] 1687      	ADDC	r0x1145,1,0
1731                     _00200_DS_:
1732 06C9 [14] 248D      	COMF	r0x1140,0,0
1733 06CA [14] 047E      	ADDL	0x7e
1734 06CB [14] 668D      	MVF	r0x1140,1,0
1735 06CC [14] 268A      	COMF	r0x1141,1,0
1736 06CD [14] 0619      	MVL	0x19
1737 06CE [14] 168A      	ADDC	r0x1141,1,0
1738 06CF [14] C60D      	MVF	r0x1140,0,0
1739 06D0 [14] F17E      	MVF	(_adS + 12),1,0
1740 06D1 [14] 648A      	MVF	r0x1141,0,0
1741 06D2 [14] 677F      	MVF	(_adS + 13),1,0
1742                     ;	;.line	393; ".\ADC_LCD.c"	adS.plus_revise_flag =1;
1743 06D3 [14] 9778      	BSF	(_adS+6),3
1744                     ;	;.line	394; ".\ADC_LCD.c"	adS.p_offset_value=Reverse_Data(adS.p_offset_value);
1745 06D4 [14] 0600      	MVL	0x00
1746 06D5 [14] AE8A      	BTSZ	r0x1141,7
1747 06D6 [14] 06FF      	MVL	0xff
1748 06D7 [14] 6683      	MVF	r0x1149,1,0
1749 06D8 [14] 6682      	MVF	r0x1148,1,0
1750 06D9 [14] C60D      	MVF	r0x1140,0,0
1751 06DA [14] F00D      	MVF	_Reverse_Data_STK02,1,0
1752 06DB [15] C60B      	MVF	r0x1141,0,0
1753 06DC [15] F00D      	MVF	_Reverse_Data_STK01,1,0
1754 06DD [16] C604      	MVF	r0x1148,0,0
1755 06DE [16] F00D      	MVF	_Reverse_Data_STK00,1,0
1756 06DF [17] 6486      	MVF	r0x1149,0,0
1757 06E0 [17] C895      	CALL	_Reverse_Data
1758 06E1 [14] D01E      	MVF	STK02,0,0
1759 06E2 [14] F17E      	MVF	(_adS + 12),1,0
1760 06E3 [14] D01F      	MVF	STK01,0,0
1761 06E4 [14] F17F      	MVF	(_adS + 13),1,0
1762                     ;	;.line	395; ".\ADC_LCD.c"	DisplayNum( adS.p_offset_value);
1763 06E5 [14] 0600      	MVL	0x00
1764 06E6 [14] AE1F      	BTSZ	STK01,7
1765 06E7 [14] 06FF      	MVL	0xff
1766 06E8 [14] 6689      	MVF	r0x1147,1,0
1767 06E9 [14] 6688      	MVF	r0x1146,1,0
1768 06EA [14] D01E      	MVF	STK02,0,0
1769 06EB [14] F00D      	MVF	_DisplayNum_STK02,1,0
1770 06EC [15] D01F      	MVF	STK01,0,0
1771 06ED [15] F00D      	MVF	_DisplayNum_STK01,1,0
1772 06EE [16] C60A      	MVF	r0x1146,0,0
1773 06EF [16] F00D      	MVF	_DisplayNum_STK00,1,0
1774 06F0 [17] 648C      	MVF	r0x1147,0,0
1775 06F1 [17] C937      	CALL	_DisplayNum
1776                     	.CHKPARA _DisplayNum 4
1777                     ;	;.line	396; ".\ADC_LCD.c"	Delay(20000);
1778 06F2 [14] C520      	MVL	0x20
1779                     	MVF	_Delay_STK00,1,0
1780 06F3 [15] 064E      	MVL	0x4e
1781 06F4 [15] C000 F174 	CALL	_Delay
1782                     	.CHKPARA _Delay 2
1783 06F6 [00] 0011      _00155_DS_:
1784                     ;	;.line	401; ".\ADC_LCD.c"	if(adS.unit_setMode ==1){
1785 06F7 [14] B372      	BTSS	_adS,1
1786 06F8 [14] C200 F1DF 	JMP	_00105_DS_
1787                     ;	;.line	403; ".\ADC_LCD.c"	adS.Presskey_flag=0;
1788 06FA [14] 8B78      	BCF	(_adS+6),5
1789                     ;	;.line	404; ".\ADC_LCD.c"	adS.unit_setMode =0 ;
1790 06FB [14] 8372      	BCF	_adS,1
1791                     ;	;.line	405; ".\ADC_LCD.c"	adS.testMode = 0;
1792 06FC [14] 8175      	BCF	(_adS+3),0
1793                     ;	;.line	406; ".\ADC_LCD.c"	adS.reload_ADCInterrupt = 1;
1794 06FD [14] 917B      	BSF	(_adS+9),0
1795                     ;	;.line	407; ".\ADC_LCD.c"	adS.resetZeroDisplay=0;
1796 06FE [14] 0D77      	CLRF	(_adS + 5),0
1797                     ;	;.line	410; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
1798 06FF [14] 06BF      	MVL	0xbf
1799 0700 [14] 2847      	ANDF	_PT1,0,0
1800 0701 [14] 0240      	IORL	0x40
1801 0702 [14] 6647      	MVF	_PT1,1,0
1802                     ;	;.line	411; ".\ADC_LCD.c"	Delay(20000);
1803 0703 [14] C520      	MVL	0x20
1804                     	MVF	_Delay_STK00,1,0
1805 0704 [15] 064E      	MVL	0x4e
1806 0705 [15] C000 F174 	CALL	_Delay
1807                     	.CHKPARA _Delay 2
1808                     ;	;.line	412; ".\ADC_LCD.c"	GPIO_PT16_LOW();
1809 0707 [14] 8C47      	BCF	_PT1,6
1810                     ;	;.line	413; ".\ADC_LCD.c"	Delay(20000);
1811 0708 [14] C520      	MVL	0x20
1812                     	MVF	_Delay_STK00,1,0
1813 0709 [15] 064E      	MVL	0x4e
1814 070A [15] C000 F174 	CALL	_Delay
1815                     	.CHKPARA _Delay 2
1816                     ;	;.line	414; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
1817 070C [14] 06BF      	MVL	0xbf
1818 070D [14] 2847      	ANDF	_PT1,0,0
1819 070E [14] 0240      	IORL	0x40
1820 070F [14] 6647      	MVF	_PT1,1,0
1821                     ;	;.line	415; ".\ADC_LCD.c"	Delay(20000);
1822 0710 [14] C520      	MVL	0x20
1823                     	MVF	_Delay_STK00,1,0
1824 0711 [15] 064E      	MVL	0x4e
1825 0712 [15] C000 F174 	CALL	_Delay
1826                     	.CHKPARA _Delay 2
1827                     ;	;.line	416; ".\ADC_LCD.c"	GPIO_PT16_LOW();
1828 0714 [14] 8C47      	BCF	_PT1,6
1829                     ;	;.line	419; ".\ADC_LCD.c"	HY17P52WR3(0,0xAA,adS.unitChoose);	//addr=00,BIE_DataH=0xAA,BIE_DataL=0x11
1830 0715 [14] D174      	MVF	(_adS + 2),0,0
1831 0716 [14] F00D      	MVF	_HY17P52WR3_STK01,1,0
1832 0717 [15] C5AA      	MVL	0xaa
1833                     	MVF	_HY17P52WR3_STK00,1,0
1834 0718 [16] 0600      	MVL	0x00
1835 0719 [16] C000 F10C 
1835 071B 0011           	CALL	_HY17P52WR3
1836                     	.CHKPARA _HY17P52WR3 3
1837                     ;	;.line	420; ".\ADC_LCD.c"	if(Flag== 1)
1838 071C [14] 356C      	DCSZ	_Flag,0,0
1839 071D [14] 7805      	JMP	_00160_DS_
1840                     ;	;.line	422; ".\ADC_LCD.c"	GPIO_PT16_HIGH();
1841 071E [14] 06BF      	MVL	0xbf
1842 071F [14] 2847      	ANDF	_PT1,0,0
1843 0720 [14] 0240      	IORL	0x40
1844 0721 [14] 6647      	MVF	_PT1,1,0
1845                     _00157_DS_:
1846                     ;	;.line	423; ".\ADC_LCD.c"	while(1);    //fail
1847 0722 [14] 7FFF      	JMP	_00157_DS_
1848                     _00160_DS_:
1849                     ;	;.line	427; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
1850 0723 [14] 0C30      	CLRF	_BIEARL,0
1851                     ;	;.line	428; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
1852 0724 [14] 902E      	BSF	_BIECN,0
1853                     _00161_DS_:
1854                     ;	;.line	429; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
1855 0725 [14] 642E      	MVF	_BIECN,0,0
1856 0726 [14] 0101      	ANDL	0x01
1857 0727 [14] 668D      	MVF	r0x1140,1,0
1858 0728 [14] 308D      	DCF	r0x1140,0,0
1859 0729 [14] 4C29      	RRF	_WREG,0,0
1860 072A [14] A02B      	BTSZ	_STATUS,0
1861 072B [14] 7FF9      	JMP	_00161_DS_
1862                     ;	;.line	430; ".\ADC_LCD.c"	adS.eepromRead_low_bit=BIEDRL;
1863 072C [14] 6432 0011 	MVF	_BIEDRL,0,0
1864 072E [14] 677A      	MVF	(_adS + 8),1,0
1865                     ;	;.line	432; ".\ADC_LCD.c"	if(adS.eepromRead_low_bit==0)  LCD_WriteData(&LCD4, seg_bar) ; 
1866 072F [14] 668D      	MVF	r0x1140,1,0
1867 0730 [14] 6E8D      	TFSZ	r0x1140,0
1868 0731 [14] 7804      	JMP	_00173_DS_
1869 0732 [14] 0602      	MVL	0x02
1870 0733 [14] 6663      	MVF	_LCD4,1,0
1871 0734 [14] C200 F1DF 	JMP	_00105_DS_
1872 0736 [00] 0011      _00173_DS_:
1873                     ;	;.line	433; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==1)LCD_WriteData(&LCD4, seg_kgf) ; 
1874 0737 [14] 357A      	DCSZ	(_adS + 8),0,0
1875 0738 [14] 7804      	JMP	_00170_DS_
1876 0739 [14] 0601      	MVL	0x01
1877 073A [14] 6663      	MVF	_LCD4,1,0
1878 073B [14] C200 F1DF 	JMP	_00105_DS_
1879 073D [00] 0011      _00170_DS_:
1880                     ;	;.line	434; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==2)LCD_WriteData(&LCD4, seg_mpa) ; 
1881 073E [14] 657A      	MVF	(_adS + 8),0,0
1882 073F [14] 0302      	XORL	0x02
1883 0740 [14] B02B      	BTSS	_STATUS,0
1884 0741 [14] 7804      	JMP	_00167_DS_
1885 0742 [14] 0608      	MVL	0x08
1886 0743 [14] 6663      	MVF	_LCD4,1,0
1887 0744 [14] C200 F1DF 	JMP	_00105_DS_
1888 0746 [00] 0011      _00167_DS_:
1889                     ;	;.line	435; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==3)LCD_WriteData(&LCD4, seg_psi) ; 
1890 0747 [14] 657A      	MVF	(_adS + 8),0,0
1891 0748 [14] 0303      	XORL	0x03
1892 0749 [14] B02B      	BTSS	_STATUS,0
1893 074A [14] C200 F1DF 	JMP	_00105_DS_
1894 074C [14] 0604      	MVL	0x04
1895 074D [14] 6663      	MVF	_LCD4,1,0
1896                     ;	;.line	446; ".\ADC_LCD.c"	}
1897 074E [14] C200 F1DF 	JMP	_00105_DS_
1898                     	.ENDFUNC	_main
1899                     ;--------------------------------------------------------
1900                     
1901                     .globl _LowVoltageDisplay
1902                     
1903                     ;--------------------------------------------------------
1904                     	.FUNC _LowVoltageDisplay:0:$C:_LowVoltageDetect_3V:$C:_DisplayBatteryCapacityFull:$C:_LowVoltageDetect_2V4:$C:_DisplayBatteryCapacityHalf\
1905                     :$C:_DispalyBatteryCapacityLow\
1906                     :$L:r0x1196
1907                     ;--------------------------------------------------------
1908                     ;	;.line	543; ".\ADC_LCD.c"	adS.LVD_3V_flag = LowVoltageDetect_3V();
1909 0180 [00] C481      _LowVoltageDisplay:	;Function start
1910 0181 [01] CEE8      	CALL	_LowVoltageDetect_3V
1911 0182 [01] 6680      	MVF	r0x1196,1,0
1912 0183 [01] 5080 0011 	RRFC	r0x1196,0,0
1913 0185 [01] B82B      	BTSS	_STATUS,4
1914 0186 [01] 8578 0011 	BCF	(_adS+6),2
1915 0188 [01] A82B      	BTSZ	_STATUS,4
1916 0189 [01] 9578 0011 	BSF	(_adS+6),2
1917                     ;	;.line	544; ".\ADC_LCD.c"	if(adS.LVD_3V_flag==0){ /* battery capacity is full*/
1918 018B [01] A578      	BTSZ	(_adS+6),2
1919 018C [01] 7802      	JMP	_00451_DS_
1920                     ;	;.line	547; ".\ADC_LCD.c"	DisplayBatteryCapacityFull(); 
1921 018D [01] CF37      	CALL	_DisplayBatteryCapacityFull
1922                     	.CHKPARA _DisplayBatteryCapacityFull 0
1923 018E [01] 780F      	JMP	_00453_DS_
1924                     _00451_DS_:
1925                     ;	;.line	550; ".\ADC_LCD.c"	adS.LVD_2V4_flag = LowVoltageDetect_2V4();
1926 018F [01] CE90      	CALL	_LowVoltageDetect_2V4
1927 0190 [01] 6680      	MVF	r0x1196,1,0
1928 0191 [01] 5080 0011 	RRFC	r0x1196,0,0
1929 0193 [01] B82B      	BTSS	_STATUS,4
1930 0194 [01] 8378 0011 	BCF	(_adS+6),1
1931 0196 [01] A82B      	BTSZ	_STATUS,4
1932 0197 [01] 9378 0011 	BSF	(_adS+6),1
1933                     ;	;.line	551; ".\ADC_LCD.c"	if(adS.LVD_2V4_flag == 0){
1934 0199 [01] A378      	BTSZ	(_adS+6),1
1935 019A [01] 7802      	JMP	_00448_DS_
1936                     ;	;.line	554; ".\ADC_LCD.c"	DisplayBatteryCapacityHalf();
1937 019B [01] CF26      	CALL	_DisplayBatteryCapacityHalf
1938                     	.CHKPARA _DisplayBatteryCapacityHalf 0
1939 019C [01] 7801      	JMP	_00453_DS_
1940                     _00448_DS_:
1941                     ;	;.line	558; ".\ADC_LCD.c"	DispalyBatteryCapacityLow();
1942 019D [01] CF21      	CALL	_DispalyBatteryCapacityLow
1943                     	.CHKPARA _DispalyBatteryCapacityLow 0
1944                     _00453_DS_:
1945                     ;	;.line	562; ".\ADC_LCD.c"	}
1946 019E [01] C4FF      	RET	
1947                     ; exit point of _LowVoltageDisplay
1948                     	.ENDFUNC	_LowVoltageDisplay
1949                     ;--------------------------------------------------------
1950                     
1951                     .globl _LowVoltageDetect_2V4
1952                     
1953                     ;--------------------------------------------------------
1954                     	.FUNC _LowVoltageDetect_2V4:0:$C:_Delay\
1955                     :$L:r0x1195
1956                     ;--------------------------------------------------------
1957                     ;	;.line	521; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_24);  
1958 0020 [00] C481      _LowVoltageDetect_2V4:	;Function start
1959 0021 [01] 06E1      	MVL	0xe1
1960 0022 [01] 2843      	ANDF	_LVDCN,0,0
1961 0023 [01] 020A      	IORL	0x0a
1962 0024 [01] 6643      	MVF	_LVDCN,1,0
1963                     ;	;.line	522; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
1964 0025 [01] 8A43      	BCF	_LVDCN,5
1965                     ;	;.line	523; ".\ADC_LCD.c"	Delay(10);
1966 0026 [01] C50A      	MVL	0x0a
1967                     	MVF	_Delay_STK00,1,0
1968 0027 [02] 0600      	MVL	0x00
1969 0028 [02] C94B      	CALL	_Delay
1970                     	.CHKPARA _Delay 2
1971                     ;	;.line	524; ".\ADC_LCD.c"	if(LVD_GetLVDO())
1972 0029 [01] B043      	BTSS	_LVDCN,0
1973 002A [01] 7802      	JMP	_00441_DS_
1974                     ;	;.line	526; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
1975 002B [01] 0C80      	CLRF	r0x1195,0
1976 002C [01] 7802      	JMP	_00442_DS_
1977                     _00441_DS_:
1978                     ;	;.line	530; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
1979 002D [01] 0601      	MVL	0x01
1980 002E [01] 6680      	MVF	r0x1195,1,0
1981                     _00442_DS_:
1982                     ;	;.line	532; ".\ADC_LCD.c"	return flag;
1983 002F [01] 6480      	MVF	r0x1195,0,0
1984                     ;	;.line	533; ".\ADC_LCD.c"	}
1985 0030 [01] C4FF      	RET	
1986                     ; exit point of _LowVoltageDetect_2V4
1987                     	.ENDFUNC	_LowVoltageDetect_2V4
1988                     ;--------------------------------------------------------
1989                     
1990                     .globl _LowVoltageDetect_3V
1991                     
1992                     ;--------------------------------------------------------
1993                     	.FUNC _LowVoltageDetect_3V:0:$C:_Delay\
1994                     :$L:r0x1194
1995                     ;--------------------------------------------------------
1996                     ;	;.line	498; ".\ADC_LCD.c"	LVD_VolSelect(VLDX_30 );  
1997 006A [00] C481      _LowVoltageDetect_3V:	;Function start
1998 006B [01] 06E1      	MVL	0xe1
1999 006C [01] 2843      	ANDF	_LVDCN,0,0
2000 006D [01] 0216      	IORL	0x16
2001 006E [01] 6643      	MVF	_LVDCN,1,0
2002                     ;	;.line	499; ".\ADC_LCD.c"	LVD_PWRSelect(PWRS_VDD);    
2003 006F [01] 8A43      	BCF	_LVDCN,5
2004                     ;	;.line	500; ".\ADC_LCD.c"	Delay(10);
2005 0070 [01] C50A      	MVL	0x0a
2006                     	MVF	_Delay_STK00,1,0
2007 0071 [02] 0600      	MVL	0x00
2008 0072 [02] C901      	CALL	_Delay
2009                     	.CHKPARA _Delay 2
2010                     ;	;.line	501; ".\ADC_LCD.c"	if(LVD_GetLVDO())
2011 0073 [01] B043      	BTSS	_LVDCN,0
2012 0074 [01] 7802      	JMP	_00434_DS_
2013                     ;	;.line	503; ".\ADC_LCD.c"	flag= 0;    //Higher than detection voltage
2014 0075 [01] 0C80      	CLRF	r0x1194,0
2015 0076 [01] 7802      	JMP	_00435_DS_
2016                     _00434_DS_:
2017                     ;	;.line	507; ".\ADC_LCD.c"	flag= 1;    //Lower than detection voltage
2018 0077 [01] 0601      	MVL	0x01
2019 0078 [01] 6680      	MVF	r0x1194,1,0
2020                     _00435_DS_:
2021                     ;	;.line	509; ".\ADC_LCD.c"	return flag;
2022 0079 [01] 6480      	MVF	r0x1194,0,0
2023                     ;	;.line	510; ".\ADC_LCD.c"	}
2024 007A [01] C4FF      	RET	
2025                     ; exit point of _LowVoltageDetect_3V
2026                     	.ENDFUNC	_LowVoltageDetect_3V
2027                     ;--------------------------------------------------------
2028                     
2029                     .globl _UnitConverter
2030                     
2031                     ;--------------------------------------------------------
2032                     	.FUNC _UnitConverter:4:$C:___slong2fs:$C:___fsmul:$C:___fs2slong\
2033                     :$L:r0x118E:$L:_UnitConverter_STK00:$L:_UnitConverter_STK01:$L:_UnitConverter_STK02:$L:r0x118F\
2034                     :$L:r0x1193:$L:r0x1192
2035                     ;--------------------------------------------------------
2036                     ;	;.line	455; ".\ADC_LCD.c"	long UnitConverter(long data)
2037 086B [00] C484      _UnitConverter:	;Function start
2038 086C [04] 6683      	MVF	r0x118E,1,0
2039                     ;	;.line	458; ".\ADC_LCD.c"	BIEARL=0;                                //addr=0
2040 086D [04] 0C30      	CLRF	_BIEARL,0
2041                     ;	;.line	459; ".\ADC_LCD.c"	BIECN=BIECN | 0x01;              //BIE_DataH=0xAA,BIE_DataL=0x11
2042 086E [04] 902E      	BSF	_BIECN,0
2043                     _00387_DS_:
2044                     ;	;.line	460; ".\ADC_LCD.c"	while((BIECN& 0x01)==1); 
2045 086F [04] 642E      	MVF	_BIECN,0,0
2046 0870 [04] 0101      	ANDL	0x01
2047 0871 [04] 6682      	MVF	r0x118F,1,0
2048 0872 [04] 3082      	DCF	r0x118F,0,0
2049 0873 [04] A02B      	BTSZ	_STATUS,0
2050 0874 [04] 7FFA      	JMP	_00387_DS_
2051                     ;	;.line	461; ".\ADC_LCD.c"	adS.eepromRead_low_bit=BIEDRL;
2052 0875 [04] 6432 0011 	MVF	_BIEDRL,0,0
2053 0877 [04] 677A      	MVF	(_adS + 8),1,0
2054 0878 [04] 6682      	MVF	r0x118F,1,0
2055                     ;	;.line	463; ".\ADC_LCD.c"	if(adS.eepromRead_low_bit==0){ /*psi*/
2056 0879 [04] 6E29      	TFSZ	_WREG,0
2057 087A [04] 7822      	JMP	_00400_DS_
2058                     ;	;.line	465; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_psi) ;
2059 087B [04] 0604      	MVL	0x04
2060 087C [04] 6663      	MVF	_LCD4,1,0
2061                     ;	;.line	466; ".\ADC_LCD.c"	return  kgfTOpsi(data) ;
2062 087D [04] C606      	MVF	_UnitConverter_STK02,0,0
2063 087E [04] F00D      	MVF	___slong2fs_STK02,1,0
2064 087F [05] C606      	MVF	_UnitConverter_STK01,0,0
2065 0880 [05] F00D      	MVF	___slong2fs_STK01,1,0
2066 0881 [06] C606      	MVF	_UnitConverter_STK00,0,0
2067 0882 [06] F00D      	MVF	___slong2fs_STK00,1,0
2068 0883 [07] 6486      	MVF	r0x118E,0,0
2069 0884 [07] CECB      	CALL	___slong2fs
2070                     	.CHKPARA ___slong2fs 4
2071 0885 [04] 6681      	MVF	r0x1193,1,0
2072 0886 [04] D01E      	MVF	STK02,0,0
2073 0887 [04] F00D      	MVF	___fsmul_STK06,1,0
2074 0888 [05] D01F      	MVF	STK01,0,0
2075 0889 [05] F00D      	MVF	___fsmul_STK05,1,0
2076 088A [06] D020      	MVF	STK00,0,0
2077 088B [06] F00D      	MVF	___fsmul_STK04,1,0
2078 088C [07] C604      	MVF	r0x1193,0,0
2079 088D [07] F00D      	MVF	___fsmul_STK03,1,0
2080 088E [08] C5E1      	MVL	0xe1
2081                     	MVF	___fsmul_STK02,1,0
2082 088F [09] C57A      	MVL	0x7a
2083                     	MVF	___fsmul_STK01,1,0
2084 0890 [10] C514      	MVL	0x14
2085                     	MVF	___fsmul_STK00,1,0
2086 0891 [11] 063E      	MVL	0x3e
2087 0892 [11] CB00      	CALL	___fsmul
2088                     	.CHKPARA ___fsmul 8
2089 0893 [04] 6681      	MVF	r0x1193,1,0
2090 0894 [04] D01E      	MVF	STK02,0,0
2091 0895 [04] F00D      	MVF	___fs2slong_STK02,1,0
2092 0896 [05] D01F      	MVF	STK01,0,0
2093 0897 [05] F00D      	MVF	___fs2slong_STK01,1,0
2094 0898 [06] D020      	MVF	STK00,0,0
2095 0899 [06] F00D      	MVF	___fs2slong_STK00,1,0
2096 089A [07] 6484      	MVF	r0x1193,0,0
2097 089B [07] CF52      	CALL	___fs2slong
2098 089C [04] 7861      	JMP	_00402_DS_
2099                     _00400_DS_:
2100                     ;	;.line	468; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==1){ /*unit bar*/
2101 089D [04] 3482      	DCSZ	r0x118F,0,0
2102 089E [04] 7822      	JMP	_00397_DS_
2103                     ;	;.line	469; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_bar) ;
2104 089F [04] 0602      	MVL	0x02
2105 08A0 [04] 6663      	MVF	_LCD4,1,0
2106                     ;	;.line	470; ".\ADC_LCD.c"	return	kgfTObar(data);
2107 08A1 [04] C606      	MVF	_UnitConverter_STK02,0,0
2108 08A2 [04] F00D      	MVF	___slong2fs_STK02,1,0
2109 08A3 [05] C606      	MVF	_UnitConverter_STK01,0,0
2110 08A4 [05] F00D      	MVF	___slong2fs_STK01,1,0
2111 08A5 [06] C606      	MVF	_UnitConverter_STK00,0,0
2112 08A6 [06] F00D      	MVF	___slong2fs_STK00,1,0
2113 08A7 [07] 6486      	MVF	r0x118E,0,0
2114 08A8 [07] CEA7      	CALL	___slong2fs
2115                     	.CHKPARA ___slong2fs 4
2116 08A9 [04] 6681      	MVF	r0x1193,1,0
2117 08AA [04] D01E      	MVF	STK02,0,0
2118 08AB [04] F00D      	MVF	___fsmul_STK06,1,0
2119 08AC [05] D01F      	MVF	STK01,0,0
2120 08AD [05] F00D      	MVF	___fsmul_STK05,1,0
2121 08AE [06] D020      	MVF	STK00,0,0
2122 08AF [06] F00D      	MVF	___fsmul_STK04,1,0
2123 08B0 [07] C604      	MVF	r0x1193,0,0
2124 08B1 [07] F00D      	MVF	___fsmul_STK03,1,0
2125 08B2 [08] C50A      	MVL	0x0a
2126                     	MVF	___fsmul_STK02,1,0
2127 08B3 [09] C5D7      	MVL	0xd7
2128                     	MVF	___fsmul_STK01,1,0
2129 08B4 [10] C523      	MVL	0x23
2130                     	MVF	___fsmul_STK00,1,0
2131 08B5 [11] 063C      	MVL	0x3c
2132 08B6 [11] CADC      	CALL	___fsmul
2133                     	.CHKPARA ___fsmul 8
2134 08B7 [04] 6681      	MVF	r0x1193,1,0
2135 08B8 [04] D01E      	MVF	STK02,0,0
2136 08B9 [04] F00D      	MVF	___fs2slong_STK02,1,0
2137 08BA [05] D01F      	MVF	STK01,0,0
2138 08BB [05] F00D      	MVF	___fs2slong_STK01,1,0
2139 08BC [06] D020      	MVF	STK00,0,0
2140 08BD [06] F00D      	MVF	___fs2slong_STK00,1,0
2141 08BE [07] 6484      	MVF	r0x1193,0,0
2142 08BF [07] CF2E      	CALL	___fs2slong
2143 08C0 [04] 783D      	JMP	_00402_DS_
2144                     _00397_DS_:
2145                     ;	;.line	472; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==2){ /* unit kgf*/
2146 08C1 [04] 6482      	MVF	r0x118F,0,0
2147 08C2 [04] 0302      	XORL	0x02
2148 08C3 [04] B02B      	BTSS	_STATUS,0
2149 08C4 [04] 780A      	JMP	_00394_DS_
2150                     ;	;.line	474; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
2151 08C5 [04] 0601      	MVL	0x01
2152 08C6 [04] 6663      	MVF	_LCD4,1,0
2153                     ;	;.line	475; ".\ADC_LCD.c"	return data;
2154 08C7 [04] C606      	MVF	_UnitConverter_STK02,0,0
2155 08C8 [04] F01E      	MVF	STK02,1,0
2156 08C9 [04] C605      	MVF	_UnitConverter_STK01,0,0
2157 08CA [04] F01F      	MVF	STK01,1,0
2158 08CB [04] C604      	MVF	_UnitConverter_STK00,0,0
2159 08CC [04] F020      	MVF	STK00,1,0
2160 08CD [04] 6483      	MVF	r0x118E,0,0
2161 08CE [04] 782F      	JMP	_00402_DS_
2162                     _00394_DS_:
2163                     ;	;.line	477; ".\ADC_LCD.c"	else if(adS.eepromRead_low_bit==3){ /*uint mpa*/
2164 08CF [04] 6482      	MVF	r0x118F,0,0
2165 08D0 [04] 0303      	XORL	0x03
2166 08D1 [04] B02B      	BTSS	_STATUS,0
2167 08D2 [04] 7822      	JMP	_00391_DS_
2168                     ;	;.line	479; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_mpa) ;
2169 08D3 [04] 0608      	MVL	0x08
2170 08D4 [04] 6663      	MVF	_LCD4,1,0
2171                     ;	;.line	480; ".\ADC_LCD.c"	return kgfTOmpa(data);
2172 08D5 [04] C606      	MVF	_UnitConverter_STK02,0,0
2173 08D6 [04] F00D      	MVF	___slong2fs_STK02,1,0
2174 08D7 [05] C606      	MVF	_UnitConverter_STK01,0,0
2175 08D8 [05] F00D      	MVF	___slong2fs_STK01,1,0
2176 08D9 [06] C606      	MVF	_UnitConverter_STK00,0,0
2177 08DA [06] F00D      	MVF	___slong2fs_STK00,1,0
2178 08DB [07] 6486      	MVF	r0x118E,0,0
2179 08DC [07] CE73      	CALL	___slong2fs
2180                     	.CHKPARA ___slong2fs 4
2181 08DD [04] 6680      	MVF	r0x1192,1,0
2182 08DE [04] D01E      	MVF	STK02,0,0
2183 08DF [04] F00D      	MVF	___fsmul_STK06,1,0
2184 08E0 [05] D01F      	MVF	STK01,0,0
2185 08E1 [05] F00D      	MVF	___fsmul_STK05,1,0
2186 08E2 [06] D020      	MVF	STK00,0,0
2187 08E3 [06] F00D      	MVF	___fsmul_STK04,1,0
2188 08E4 [07] C603      	MVF	r0x1192,0,0
2189 08E5 [07] F00D      	MVF	___fsmul_STK03,1,0
2190 08E6 [08] C5CD      	MVL	0xcd
2191                     	MVF	___fsmul_STK02,1,0
2192 08E7 [09] C5CC      	MVL	0xcc
2193                     	MVF	___fsmul_STK01,1,0
2194 08E8 [10] C5CC      	MVF	___fsmul_STK00,1,0
2195 08E9 [11] 063D      	MVL	0x3d
2196 08EA [11] CAA8      	CALL	___fsmul
2197                     	.CHKPARA ___fsmul 8
2198 08EB [04] 6680      	MVF	r0x1192,1,0
2199 08EC [04] D01E      	MVF	STK02,0,0
2200 08ED [04] F00D      	MVF	___fs2slong_STK02,1,0
2201 08EE [05] D01F      	MVF	STK01,0,0
2202 08EF [05] F00D      	MVF	___fs2slong_STK01,1,0
2203 08F0 [06] D020      	MVF	STK00,0,0
2204 08F1 [06] F00D      	MVF	___fs2slong_STK00,1,0
2205 08F2 [07] 6483      	MVF	r0x1192,0,0
2206 08F3 [07] CEFA      	CALL	___fs2slong
2207 08F4 [04] 7809      	JMP	_00402_DS_
2208                     _00391_DS_:
2209                     ;	;.line	483; ".\ADC_LCD.c"	LCD_WriteData(&LCD4, seg_kgf) ;
2210 08F5 [04] 0601      	MVL	0x01
2211 08F6 [04] 6663      	MVF	_LCD4,1,0
2212                     ;	;.line	484; ".\ADC_LCD.c"	return data;
2213 08F7 [04] C606      	MVF	_UnitConverter_STK02,0,0
2214 08F8 [04] F01E      	MVF	STK02,1,0
2215 08F9 [04] C605      	MVF	_UnitConverter_STK01,0,0
2216 08FA [04] F01F      	MVF	STK01,1,0
2217 08FB [04] C604      	MVF	_UnitConverter_STK00,0,0
2218 08FC [04] F020      	MVF	STK00,1,0
2219 08FD [04] 6483      	MVF	r0x118E,0,0
2220                     _00402_DS_:
2221                     ;	;.line	487; ".\ADC_LCD.c"	}
2222 08FE [04] C4F9      	RET	
2223                     ; exit point of _UnitConverter
2224                     	.ENDFUNC	_UnitConverter
2225                     ;--------------------------------------------------------
2226                     
2227                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
2228                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
2229                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
2230                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
2231                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
2232                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
2233                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
2234                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
2235                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
2236                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
2237                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
2238                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
2239                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
2240                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
2241                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
2242                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
2243                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
2244                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
2245                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
2246                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
2247                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
2248                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
2249                     	;--cdb--S:G$HY17P52WR3$0$0({2}DF,SC:U),C,0,0
2250                     	;--cdb--S:G$HY17P52WR3Delay$0$0({2}DF,SV:S),C,0,0
2251                     	;--cdb--S:G$PGAandADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
2252                     	;--cdb--S:G$AccuracyModeADCOFF$0$0({2}DF,SV:S),C,0,0
2253                     	;--cdb--S:G$ADCAccuracyMode$0$0({2}DF,SV:S),C,0,0
2254                     	;--cdb--S:G$main$0$0({2}DF,SV:S),C,0,0
2255                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
2256                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
2257                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
2258                     	;--cdb--S:G$__fssub$0$0({2}DF,SF:S),C,0,0
2259                     	;--cdb--S:G$__fslt$0$0({2}DF,SC:U),C,0,0
2260                     	;--cdb--S:G$__fsadd$0$0({2}DF,SF:S),C,0,0
2261                     	;--cdb--S:G$ISR$0$0({2}DF,SV:S),C,0,0
2262                     	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
2263                     	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
2264                     	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
2265                     	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
2266                     	;--cdb--S:G$adS$0$0({14}ST_adc_works_:S),E,0,0
2267                     	;--cdb--S:G$Flag$0$0({1}SC:U),E,0,0
2268                     	;--cdb--S:G$ADC$0$0({4}SL:SL),E,0,0
2269                     	;--cdb--S:G$MCUSTATUSbits$0$0({1}ST_MCUSTATUS:S),E,0,0
2270                     	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
2271                     	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
2272                     	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
2273                     	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
2274                     	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
2275                     	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
2276                     	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
2277                     	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
2278                     	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
2279                     	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
2280                     	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
2281                     	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
2282                     	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
2283                     	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
2284                     	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
2285                     	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
2286                     	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
2287                     	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
2288                     	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
2289                     	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
2290                     	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
2291                     	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
2292                     	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
2293                     	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
2294                     	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
2295                     	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
2296                     	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
2297                     	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
2298                     	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
2299                     	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
2300                     	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
2301                     	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
2302                     	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
2303                     	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
2304                     	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
2305                     	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
2306                     	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
2307                     	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
2308                     	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
2309                     	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
2310                     	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
2311                     	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
2312                     	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
2313                     	;--cdb--S:G$BIEARH$0$0({1}SC:U),I,0,0
2314                     	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
2315                     	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
2316                     	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
2317                     	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
2318                     	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
2319                     	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
2320                     	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
2321                     	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
2322                     	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
2323                     	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
2324                     	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
2325                     	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
2326                     	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
2327                     	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
2328                     	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
2329                     	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
2330                     	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
2331                     	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
2332                     	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
2333                     	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
2334                     	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
2335                     	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
2336                     	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
2337                     	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
2338                     	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
2339                     	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
2340                     	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
2341                     	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
2342                     	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
2343                     	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
2344                     	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
2345                     	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
2346                     	;--cdb--S:G$PT8$0$0({1}SC:U),I,0,0
2347                     	;--cdb--S:G$TRISC8$0$0({1}SC:U),I,0,0
2348                     	;--cdb--S:G$PT8PU$0$0({1}SC:U),I,0,0
2349                     	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
2350                     	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
2351                     	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
2352                     	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
2353                     	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
2354                     	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
2355                     	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
2356                     	;--cdb--S:G$LCDCN1$0$0({1}SC:U),I,0,0
2357                     	;--cdb--S:G$LCDCN2$0$0({1}SC:U),I,0,0
2358                     	;--cdb--S:G$LCDCN3$0$0({1}SC:U),I,0,0
2359                     	;--cdb--S:G$LCDCN4$0$0({1}SC:U),I,0,0
2360                     	;--cdb--S:G$LCD0$0$0({1}SC:U),I,0,0
2361                     	;--cdb--S:G$LCD1$0$0({1}SC:U),I,0,0
2362                     	;--cdb--S:G$LCD2$0$0({1}SC:U),I,0,0
2363                     	;--cdb--S:G$LCD3$0$0({1}SC:U),I,0,0
2364                     	;--cdb--S:G$LCD4$0$0({1}SC:U),I,0,0
2365                     	;--cdb--S:G$LCD5$0$0({1}SC:U),I,0,0
2366                     	;--cdb--S:G$LCD6$0$0({1}SC:U),I,0,0
2367                     	;--cdb--S:G$Filter$0$0({1}SC:U),I,0,0
2368                     	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
2369                     	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
2370                     	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
2371                     	;--cdb--S:LADC_LCD.main._main_LCDDisplay_65536_29$LCDDisplay$10000$29({4}SF:S),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
2372                     	;--cdb--S:LADC_LCD.main._main_delta_65536_29$delta$10000$29({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
2373                     	;--cdb--S:LADC_LCD.main._main_theta_65536_29$theta$10000$29({4}SL:SL),R,0,0,[r0x1144,r0x1145,r0x1146,r0x1147]
2374                     	;--cdb--S:LADC_LCD.main._main_n_65536_29$n$10000$29({4}SL:SL),R,0,0,[r0x1140,r0x1141,r0x1142,r0x1143]
2375                     	;--cdb--S:LADC_LCD.UnitConverter._UnitConverter_data_65536_59$data$10000$59({4}SL:SL),R,0,0,[_UnitConverter_STK02,_UnitConverter_STK01,_UnitConverter_STK00,r0x118E]
2376                     	;--cdb--S:LADC_LCD.LowVoltageDetect_3V._LowVoltageDetect_3V_flag_65536_67$flag$10000$67({1}SC:U),R,0,0,[r0x1194]
2377                     	;--cdb--S:LADC_LCD.LowVoltageDetect_2V4._LowVoltageDetect_2V4_flag_65536_71$flag$10000$71({1}SC:U),R,0,0,[r0x1195]
2378                     	;--cdb--S:G$UnitConverter$0$0({2}DF,SL:SL),C,0,0
2379                     	;--cdb--S:G$LowVoltageDetect_3V$0$0({2}DF,SC:U),C,0,0
2380                     	;--cdb--S:G$LowVoltageDetect_2V4$0$0({2}DF,SC:U),C,0,0
2381                     	;--cdb--S:G$LowVoltageDisplay$0$0({2}DF,SV:S),C,0,0
2382                     	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
2383                     	;--cdb--S:G$_PCLATH$0$0({0}:U),Z,0,0
2384                     	;--cdb--S:G$_PCLATL$0$0({0}:U),Z,0,0
2385                     	;--cdb--S:G$_WREG$0$0({0}:U),Z,0,0
2386                     	;--cdb--S:G$_INTE0$0$0({0}:U),Z,0,0
2387                     ;--------------------------------------------------------
2388                     ; external declarations
2389                     ;--------------------------------------------------------
2390                     	.globl	_ADC_Open
2391                     	.globl	_ADC_GetData
2392                     	.globl	_DisplayNum
2393                     	.globl	_Display2Er
2394                     	.globl	_DisplayUnit
2395                     	.globl	_Delay
2396                     	.globl	_GPIO_Iint
2397                     	.globl	_Reverse_Data
2398                     	.globl	_DisplayBatteryCapacityFull
2399                     	.globl	_DisplayBatteryCapacityHalf
2400                     	.globl	_DispalyBatteryCapacityLow
2401                     	.globl	_HY17P52WR3
2402                     	.globl	_PGAandADCAccuracyMode
2403                     	.globl	___slong2fs
2404                     	.globl	___fsmul
2405                     	.globl	___fs2slong
2406                     	.globl	___fssub
2407                     	.globl	___fslt
2408                     	.globl	___fsadd
2409                     	.globl	_FSR0
2410                     	.globl	_FSR1
2411                     	.globl	_FSR2
2412                     	.globl	_ADCR
2413                     	.globl	_adS
2414                     	.globl	__sdcc_gsinit_startup256fsr2
2415                     ;--------------------------------------------------------
2416                     ; global -1 declarations
2417                     ;--------------------------------------------------------
2418                     	.globl	_LowVoltageDetect_2V4
2419                     	.globl	_LowVoltageDetect_3V
2420                     	.globl	_UnitConverter
2421                     	.globl	_Flag
2422                     	.globl	_ADC
2423                     	.globl	_MCUSTATUSbits
2424                     
2425                     	.globl WSAVE
2426                     	.globl STK07
2427                     	.globl STK07_SAVE
2428                     	.globl STK06
2429                     	.globl STK06_SAVE
2430                     	.globl STK05
2431                     	.globl STK05_SAVE
2432                     	.globl STK04
2433                     	.globl STK04_SAVE
2434                     	.globl STK03
2435                     	.globl STK03_SAVE
2436                     	.globl STK02
2437                     	.globl STK02_SAVE
2438                     	.globl STK01
2439                     	.globl STK01_SAVE
2440                     	.globl STK00
2441                     	.globl STK00_SAVE
2442                     	.globl _FSR0L_SAVE
2443                     	.globl _FSR0H_SAVE
2444                     	.globl _FSR1L_SAVE
2445                     	.globl _FSR1H_SAVE
2446                     	.globl _FSR2L_SAVE
2447                     	.globl _FSR2H_SAVE
2448                     	.globl	_TBLPTRH_SAVE
2449                     
2450                     .area UDATA (DATA,REL,CON)
2451                     STK07:	.ds	 1
2452                     STK06:	.ds	 1
2453                     STK05:	.ds	 1
2454                     STK04:	.ds	 1
2455 0168 --             STK03:	.ds	 1
2456                     STK02:	.equ	 0x1E
2457                     STK01:	.equ	 0x1F
2458                     STK00:	.equ	 0x20
2459                     WSAVE:	.ds 1
2460                     STK07_SAVE:	.ds	 1
2461                     STK06_SAVE:	.ds	 1
2462                     STK05_SAVE:	.ds	 1
2463                     STK04_SAVE:	.ds	 1
2464                     STK03_SAVE:	.ds	 1
2465 0169 --             STK02_SAVE:	.ds	 1
2466 016A --             STK01_SAVE:	.ds	 1
2467 016B --             STK00_SAVE:	.ds	 1
2468                     _FSR0L_SAVE:	.ds	 1
2469                     _FSR0H_SAVE:	.ds	 1
2470                     _FSR1L_SAVE:	.ds	 1
2471                     _FSR1H_SAVE:	.ds	 1
2472                     _FSR2L_SAVE:	.ds	 1
2473                     _FSR2H_SAVE:	.ds	 1
2474                     _TBLPTRH_SAVE:	.ds	 1
2475                     
2476                     	.globl	_memcpy
2477                     ;--------------------------------------------------------
2478                     ; global -2 definitions
2479                     ;--------------------------------------------------------
2480                     	.area DSEG(DATA)
2481 016C --             _Flag:	.ds	1
2482                     
2483                     	.area DSEG(DATA)
2484 016D -- -- -- --    _ADC:	.ds	4
2485                     
2486                     	.area DSEG(DATA)
2487 0171 --             _MCUSTATUSbits:	.ds	1
2488                     
2489                     	.area DSEG(DATA)
2490                     __SWTGTID	.equ	0xA43354DA
2491                     
2492                     	.area DSEG(DATA)
2493                     _INDF0	.equ	0x0
2494                     
2495                     	.area DSEG(DATA)
2496                     _POINC0	.equ	0x1
2497                     
2498                     	.area DSEG(DATA)
2499                     _PODEC0	.equ	0x2
2500                     
2501                     	.area DSEG(DATA)
2502                     _PRINC0	.equ	0x3
2503                     
2504                     	.area DSEG(DATA)
2505                     _PLUSW0	.equ	0x4
2506                     
2507                     	.area DSEG(DATA)
2508                     _INDF1	.equ	0x5
2509                     
2510                     	.area DSEG(DATA)
2511                     _POINC1	.equ	0x6
2512                     
2513                     	.area DSEG(DATA)
2514                     _PODEC1	.equ	0x7
2515                     
2516                     	.area DSEG(DATA)
2517                     _PRINC1	.equ	0x8
2518                     
2519                     	.area DSEG(DATA)
2520                     _PLUSW1	.equ	0x9
2521                     
2522                     	.area DSEG(DATA)
2523                     _INDF2	.equ	0xA
2524                     
2525                     	.area DSEG(DATA)
2526                     _POINC2	.equ	0xB
2527                     
2528                     	.area DSEG(DATA)
2529                     _PODEC2	.equ	0xC
2530                     
2531                     	.area DSEG(DATA)
2532                     _PRINC2	.equ	0xD
2533                     
2534                     	.area DSEG(DATA)
2535                     _PLUSW2	.equ	0xE
2536                     
2537                     	.area DSEG(DATA)
2538                     _FSR0H	.equ	0xF
2539                     
2540                     	.area DSEG(DATA)
2541                     _FSR0L	.equ	0x10
2542                     
2543                     	.area DSEG(DATA)
2544                     _FSR1H	.equ	0x11
2545                     
2546                     	.area DSEG(DATA)
2547                     _FSR1L	.equ	0x12
2548                     
2549                     	.area DSEG(DATA)
2550                     _FSR2H	.equ	0x13
2551                     
2552                     	.area DSEG(DATA)
2553                     _FSR2L	.equ	0x14
2554                     
2555                     	.area DSEG(DATA)
2556                     _TOSH	.equ	0x16
2557                     
2558                     	.area DSEG(DATA)
2559                     _TOSL	.equ	0x17
2560                     
2561                     	.area DSEG(DATA)
2562                     _SKCN	.equ	0x18
2563                     
2564                     	.area DSEG(DATA)
2565                     _PCLATH	.equ	0x1A
2566                     
2567                     	.area DSEG(DATA)
2568                     _PCLATL	.equ	0x1B
2569                     
2570                     	.area DSEG(DATA)
2571                     _TBLPTRH	.equ	0x1D
2572                     
2573                     	.area DSEG(DATA)
2574                     _TBLPTRL	.equ	0x1E
2575                     
2576                     	.area DSEG(DATA)
2577                     _TBLDH	.equ	0x1F
2578                     
2579                     	.area DSEG(DATA)
2580                     _TBLDL	.equ	0x20
2581                     
2582                     	.area DSEG(DATA)
2583                     _PRODH	.equ	0x21
2584                     
2585                     	.area DSEG(DATA)
2586                     _PRODL	.equ	0x22
2587                     
2588                     	.area DSEG(DATA)
2589                     _INTE0	.equ	0x23
2590                     
2591                     	.area DSEG(DATA)
2592                     _INTE1	.equ	0x24
2593                     
2594                     	.area DSEG(DATA)
2595                     _INTF0	.equ	0x26
2596                     
2597                     	.area DSEG(DATA)
2598                     _INTF1	.equ	0x27
2599                     
2600                     	.area DSEG(DATA)
2601                     _WREG	.equ	0x29
2602                     
2603                     	.area DSEG(DATA)
2604                     _BSRCN	.equ	0x2A
2605                     
2606                     	.area DSEG(DATA)
2607                     _STATUS	.equ	0x2B
2608                     
2609                     	.area DSEG(DATA)
2610                     _MSTAT	.equ	0x2B
2611                     
2612                     	.area DSEG(DATA)
2613                     _PSTAT	.equ	0x2C
2614                     
2615                     	.area DSEG(DATA)
2616                     _BIECN	.equ	0x2E
2617                     
2618                     	.area DSEG(DATA)
2619                     _BIEARH	.equ	0x2F
2620                     
2621                     	.area DSEG(DATA)
2622                     _BIEARL	.equ	0x30
2623                     
2624                     	.area DSEG(DATA)
2625                     _BIEDRH	.equ	0x31
2626                     
2627                     	.area DSEG(DATA)
2628                     _BIEDRL	.equ	0x32
2629                     
2630                     	.area DSEG(DATA)
2631                     _PWRCN	.equ	0x33
2632                     
2633                     	.area DSEG(DATA)
2634                     _OSCCN0	.equ	0x34
2635                     
2636                     	.area DSEG(DATA)
2637                     _OSCCN1	.equ	0x35
2638                     
2639                     	.area DSEG(DATA)
2640                     _OSCCN2	.equ	0x36
2641                     
2642                     	.area DSEG(DATA)
2643                     _CSFCN0	.equ	0x37
2644                     
2645                     	.area DSEG(DATA)
2646                     _CSFCN1	.equ	0x38
2647                     
2648                     	.area DSEG(DATA)
2649                     _WDTCN	.equ	0x39
2650                     
2651                     	.area DSEG(DATA)
2652                     _AD1H	.equ	0x3A
2653                     
2654                     	.area DSEG(DATA)
2655                     _AD1M	.equ	0x3B
2656                     
2657                     	.area DSEG(DATA)
2658                     _AD1L	.equ	0x3C
2659                     
2660                     	.area DSEG(DATA)
2661                     _AD1CN0	.equ	0x3D
2662                     
2663                     	.area DSEG(DATA)
2664                     _AD1CN1	.equ	0x3E
2665                     
2666                     	.area DSEG(DATA)
2667                     _AD1CN2	.equ	0x3F
2668                     
2669                     	.area DSEG(DATA)
2670                     _AD1CN3	.equ	0x40
2671                     
2672                     	.area DSEG(DATA)
2673                     _AD1CN4	.equ	0x41
2674                     
2675                     	.area DSEG(DATA)
2676                     _AD1CN5	.equ	0x42
2677                     
2678                     	.area DSEG(DATA)
2679                     _LVDCN	.equ	0x43
2680                     
2681                     	.area DSEG(DATA)
2682                     _TMA1CN	.equ	0x44
2683                     
2684                     	.area DSEG(DATA)
2685                     _TMA1R	.equ	0x45
2686                     
2687                     	.area DSEG(DATA)
2688                     _TMA1C	.equ	0x46
2689                     
2690                     	.area DSEG(DATA)
2691                     _PT1	.equ	0x47
2692                     
2693                     	.area DSEG(DATA)
2694                     _TRISC1	.equ	0x48
2695                     
2696                     	.area DSEG(DATA)
2697                     _PT1DA	.equ	0x49
2698                     
2699                     	.area DSEG(DATA)
2700                     _PT1PU	.equ	0x4A
2701                     
2702                     	.area DSEG(DATA)
2703                     _PT1M1	.equ	0x4B
2704                     
2705                     	.area DSEG(DATA)
2706                     _PT2	.equ	0x4C
2707                     
2708                     	.area DSEG(DATA)
2709                     _TRISC2	.equ	0x4D
2710                     
2711                     	.area DSEG(DATA)
2712                     _PT2DA	.equ	0x4E
2713                     
2714                     	.area DSEG(DATA)
2715                     _PT2PU	.equ	0x4F
2716                     
2717                     	.area DSEG(DATA)
2718                     _PT8	.equ	0x50
2719                     
2720                     	.area DSEG(DATA)
2721                     _TRISC8	.equ	0x51
2722                     
2723                     	.area DSEG(DATA)
2724                     _PT8PU	.equ	0x53
2725                     
2726                     	.area DSEG(DATA)
2727                     _UR0CN	.equ	0x54
2728                     
2729                     	.area DSEG(DATA)
2730                     _UR0STA	.equ	0x55
2731                     
2732                     	.area DSEG(DATA)
2733                     _BA0CN	.equ	0x56
2734                     
2735                     	.area DSEG(DATA)
2736                     _BG0RH	.equ	0x57
2737                     
2738                     	.area DSEG(DATA)
2739                     _BG0RL	.equ	0x58
2740                     
2741                     	.area DSEG(DATA)
2742                     _TX0R	.equ	0x59
2743                     
2744                     	.area DSEG(DATA)
2745                     _RC0REG	.equ	0x5A
2746                     
2747                     	.area DSEG(DATA)
2748                     _LCDCN1	.equ	0x5B
2749                     
2750                     	.area DSEG(DATA)
2751                     _LCDCN2	.equ	0x5C
2752                     
2753                     	.area DSEG(DATA)
2754                     _LCDCN3	.equ	0x5D
2755                     
2756                     	.area DSEG(DATA)
2757                     _LCDCN4	.equ	0x5E
2758                     
2759                     	.area DSEG(DATA)
2760                     _LCD0	.equ	0x5F
2761                     
2762                     	.area DSEG(DATA)
2763                     _LCD1	.equ	0x60
2764                     
2765                     	.area DSEG(DATA)
2766                     _LCD2	.equ	0x61
2767                     
2768                     	.area DSEG(DATA)
2769                     _LCD3	.equ	0x62
2770                     
2771                     	.area DSEG(DATA)
2772                     _LCD4	.equ	0x63
2773                     
2774                     	.area DSEG(DATA)
2775                     _LCD5	.equ	0x64
2776                     
2777                     	.area DSEG(DATA)
2778                     _LCD6	.equ	0x65
2779                     
2780                     	.area DSEG(DATA)
2781                     _Filter	.equ	0x66
2782                     
2783                     	.area DSEG(DATA)
2784                     _ADCRH	.equ	0x3A
2785                     
2786                     	.area DSEG(DATA)
2787                     _ADCRM	.equ	0x3B
2788                     
2789                     	.area DSEG(DATA)
2790                     _ADCRL	.equ	0x3C
2791                     
2792                     ;--------------------------------------------------------
2793                     ; absolute symbol definitions
2794                     ;--------------------------------------------------------
2795                     ;--------------------------------------------------------
2796                     ; compiler-defined variables
2797                     ;--------------------------------------------------------
2798                     	.area IDATA (DATA,REL,CON); pre-def
2799                     	.area IDATAROM (CODE,REL,CON); pre-def
2800                     	.area UDATA (DATA,REL,CON); pre-def
2801                     	.area UDATA (DATA,REL,CON) ;UDL_ADC_LCD_0	udata
2802 @FSR2-01 --         r0x1140:	.ds	1
2803 @FSR2-04 --         r0x1141:	.ds	1
2804 @FSR2-03 --         r0x1142:	.ds	1
2805 @FSR2-02 --         r0x1143:	.ds	1
2806 @FSR2-08 --         r0x1144:	.ds	1
2807 @FSR2-07 --         r0x1145:	.ds	1
2808 @FSR2-06 --         r0x1146:	.ds	1
2809 @FSR2-05 --         r0x1147:	.ds	1
2810 @FSR2-12 --         r0x1148:	.ds	1
2811 @FSR2-11 --         r0x1149:	.ds	1
2812 @FSR2-10 --         r0x114A:	.ds	1
2813 @FSR2-09 --         r0x114B:	.ds	1
2814 @FSR2-14 --         r0x114C:	.ds	1
2815 @FSR2-13 --         r0x114D:	.ds	1
2816 @FSR2-01 --         r0x118E:	.ds	1
2817 @FSR2-02 --         r0x118F:	.ds	1
2818 @FSR2-04 --         r0x1192:	.ds	1
2819 @FSR2-03 --         r0x1193:	.ds	1
2820 @FSR2-01 --         r0x1194:	.ds	1
2821 @FSR2-01 --         r0x1195:	.ds	1
2822 @FSR2-01 --         r0x1196:	.ds	1
2823                     	.area LOCALSTK (STK); local stack var
2824                     	.globl _ADC_Open_STK10
2825                     	.globl _ADC_Open_STK09
2826                     	.globl _ADC_Open_STK08
2827                     	.globl _ADC_Open_STK07
2828                     	.globl _ADC_Open_STK06
2829                     	.globl _ADC_Open_STK05
2830                     	.globl _ADC_Open_STK04
2831                     	.globl _ADC_Open_STK03
2832                     	.globl _ADC_Open_STK02
2833                     	.globl _ADC_Open_STK01
2834                     	.globl _ADC_Open_STK00
2835                     	.globl _Delay_STK00
2836                     	.globl ___slong2fs_STK02
2837                     	.globl ___slong2fs_STK01
2838                     	.globl ___slong2fs_STK00
2839                     	.globl ___fsmul_STK06
2840                     	.globl ___fsmul_STK05
2841                     	.globl ___fsmul_STK04
2842                     	.globl ___fsmul_STK03
2843                     	.globl ___fsmul_STK02
2844                     	.globl ___fsmul_STK01
2845                     	.globl ___fsmul_STK00
2846                     	.globl ___fs2slong_STK02
2847                     	.globl ___fs2slong_STK01
2848                     	.globl ___fs2slong_STK00
2849                     	.globl ___fssub_STK06
2850                     	.globl ___fssub_STK05
2851                     	.globl ___fssub_STK04
2852                     	.globl ___fssub_STK03
2853                     	.globl ___fssub_STK02
2854                     	.globl ___fssub_STK01
2855                     	.globl ___fssub_STK00
2856                     	.globl _DisplayNum_STK02
2857                     	.globl _DisplayNum_STK01
2858                     	.globl _DisplayNum_STK00
2859                     	.globl ___fslt_STK06
2860                     	.globl ___fslt_STK05
2861                     	.globl ___fslt_STK04
2862                     	.globl ___fslt_STK03
2863                     	.globl ___fslt_STK02
2864                     	.globl ___fslt_STK01
2865                     	.globl ___fslt_STK00
2866                     	.globl _Reverse_Data_STK02
2867                     	.globl _Reverse_Data_STK01
2868                     	.globl _Reverse_Data_STK00
2869 @FSR2+02 --         _UnitConverter_STK02:	.ds	1
2870                     	.globl _UnitConverter_STK02
2871 @FSR2+01 --         _UnitConverter_STK01:	.ds	1
2872                     	.globl _UnitConverter_STK01
2873 @FSR2-00 --         _UnitConverter_STK00:	.ds	1
2874                     	.globl _UnitConverter_STK00
2875                     	.globl ___fsadd_STK06
2876                     	.globl ___fsadd_STK05
2877                     	.globl ___fsadd_STK04
2878                     	.globl ___fsadd_STK03
2879                     	.globl ___fsadd_STK02
2880                     	.globl ___fsadd_STK01
2881                     	.globl ___fsadd_STK00
2882                     	.globl _HY17P52WR3_STK01
2883                     	.globl _HY17P52WR3_STK00
2884                     ;--------------------------------------------------------
2885                     ; initialized data
2886                     ;--------------------------------------------------------
2887                     ;--------------------------------------------------------
2888                     ; initialized data - mirror
2889                     ;--------------------------------------------------------
2890                     	;Following is optimization info, 
2891                     	;xxcdbxxW:dst:src+offset:srclit:just-remove
2892                     	;--cdb--W:r0x1195:NULL+0:-1:1
2893                     	;--cdb--W:r0x1194:NULL+0:-1:1
2894                     	;--cdb--W:r0x1190:NULL+0:-1:1
2895                     	;--cdb--W:r0x118F:NULL+0:-1:1
2896                     	;--cdb--W:r0x1190:NULL+0:0:0
2897                     	;--cdb--W:r0x1190:STK01+0:-1:0
2898                     	;--cdb--W:r0x1192:STK00+0:-1:0
2899                     	;--cdb--W:r0x1191:STK01+0:-1:0
2900                     	;--cdb--W:r0x1191:STK00+0:-1:0
2901                     	;--cdb--W:r0x1193:NULL+0:-1:1
2902                     	;--cdb--W:r0x1192:NULL+0:-1:1
2903                     	;--cdb--W:r0x1140:NULL+0:-1:1
2904                     	;--cdb--W:r0x1141:NULL+0:-1:1
2905                     	;--cdb--W:r0x1142:NULL+0:-1:1
2906                     	;--cdb--W:r0x1143:NULL+0:-1:1
2907                     	;--cdb--W:r0x1144:NULL+0:-1:1
2908                     	;--cdb--W:r0x1145:NULL+0:-1:1
2909                     	;--cdb--W:r0x1147:NULL+0:-1:1
2910                     	;--cdb--W:r0x1146:NULL+0:-1:1
2911                     	;--cdb--W:r0x1140:STK02+0:-1:0
2912                     	;--cdb--W:r0x1140:r0x1148+0:-1:0
2913                     	;--cdb--W:r0x1142:STK00+0:-1:0
2914                     	;--cdb--W:r0x1141:STK01+0:-1:0
2915                     	;--cdb--W:r0x1141:r0x1149+1:-1:0
2916                     	;--cdb--W:r0x1141:NULL+0:0:0
2917                     	;--cdb--W:r0x1147:r0x1141+1:-1:0
2918                     	;--cdb--W:r0x1146:r0x1140+0:-1:0
2919                     	;--cdb--W:r0x1145:r0x1147+1:-1:0
2920                     	;--cdb--W:r0x1145:r0x1141+1:-1:0
2921                     	;--cdb--W:r0x1144:r0x1146+0:-1:0
2922                     	;--cdb--W:r0x1144:r0x1140+0:-1:0
2923                     	;--cdb--W:r0x114B:r0x1149+1:-1:0
2924                     	;--cdb--W:r0x114A:STK00+0:-1:0
2925                     	;--cdb--W:r0x114A:r0x1148+0:-1:0
2926                     	;--cdb--W:r0x1149:STK01+0:-1:0
2927                     	;--cdb--W:r0x1149:r0x114B+1:-1:0
2928                     	;--cdb--W:r0x1148:STK02+0:-1:0
2929                     	;--cdb--W:r0x1148:r0x114A+0:-1:0
2930                     	end
