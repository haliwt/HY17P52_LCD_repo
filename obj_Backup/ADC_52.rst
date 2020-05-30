001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft"
008                     ;;	.file	"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"
009                     	.module ADC_52
010                     	;.list	p=HY17P52
011                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
012                     	;--cdb--F:ADC_52:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0,0,0,0
013                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
014                     	;--cdb--F:ADC_52:G$ADC_Open$0$0({2}DF,SV:S),C,0,0,0,0,0
015                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
016                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
017                     	;--cdb--S:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0
018                     	;--cdb--F:ADC_52:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0,0,0,0
019                     	;--cdb--S:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0
020                     	;--cdb--F:ADC_52:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0,0,0,0
021                     ;--------------------------------------------------------
022                     ; overlayable items in internal ram 
023                     ;--------------------------------------------------------
024                     ;	udata_ovr
025                     .area CCODE (code,REL,CON) ; ADC_52-code 
026                     .globl _ENSDRVDisable
027                     
028                     ;--------------------------------------------------------
029                     	.FUNC _ENSDRVDisable:0
030                     ;--------------------------------------------------------
031                     ;	;.line	120; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONEnable();
032                     _ENSDRVDisable:	;Function start
033                     	BSF	_PWRCN,0
034                     ;	;.line	121; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CSFCN1 &= 0x7F;
035                     	BCF	_CSFCN1,7
036                     ;	;.line	122; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONDisable();
037                     	BCF	_PWRCN,0
038                     ;	;.line	123; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
039                     	RET	
040                     ; exit point of _ENSDRVDisable
041                     	.ENDFUNC	_ENSDRVDisable
042                     ;--------------------------------------------------------
043                     
044                     .globl _ENSDRVEnable
045                     
046                     ;--------------------------------------------------------
047                     	.FUNC _ENSDRVEnable:0
048                     ;--------------------------------------------------------
049                     ;	;.line	114; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONEnable();
050                     _ENSDRVEnable:	;Function start
051                     	BSF	_PWRCN,0
052                     ;	;.line	115; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CSFCN1 |= 0x80;
053                     	BSF	_CSFCN1,7
054                     ;	;.line	116; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	PWR_CSFONDisable();
055                     	BCF	_PWRCN,0
056                     ;	;.line	117; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
057                     	RET	
058                     ; exit point of _ENSDRVEnable
059                     	.ENDFUNC	_ENSDRVEnable
060                     ;--------------------------------------------------------
061                     
062                     .globl _ADC_GetData
063                     
064                     ;--------------------------------------------------------
065                     	.FUNC _ADC_GetData:0:$L:_ADC_GetData_ADCData_65536_8
066                     ;--------------------------------------------------------
067                     ;	;.line	98; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[0] = AD1L; /* ADC low byte register*/
068 0080 [00] C484      _ADC_GetData:	;Function start
069 0081 [04] 643C      	MVF	_AD1L,0,0
070 0082 [04] 6683      	MVF	(_ADC_GetData_ADCData_65536_8 + 0),1,0
071                     ;	;.line	99; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[1] = AD1M; /* ADC middle byte*/
072 0083 [04] 643B      	MVF	_AD1M,0,0
073 0084 [04] 6682      	MVF	(_ADC_GetData_ADCData_65536_8 + 1),1,0
074                     ;	;.line	100; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[2] = AD1H; /* ADC high byte register */
075 0085 [04] 643A      	MVF	_AD1H,0,0
076 0086 [04] 6681      	MVF	(_ADC_GetData_ADCData_65536_8 + 2),1,0
077                     ;	;.line	102; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	if (ADCData&0x800000L)  //2^(24-1) -1 = 8388607  
078 0087 [04] BE81      	BTSS	(_ADC_GetData_ADCData_65536_8 + 2),7
079 0088 [04] 7802      	JMP	_00110_DS_
080                     ;	;.line	103; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[3] = 0xFF;
081 0089 [04] 0A80      	SETF	(_ADC_GetData_ADCData_65536_8 + 3),0
082 008A [04] 7801      	JMP	_00111_DS_
083                     _00110_DS_:
084                     ;	;.line	105; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	((char *)(&ADCData))[3] = 0x00;
085 008B [04] 0C80      	CLRF	(_ADC_GetData_ADCData_65536_8 + 3),0
086                     _00111_DS_:
087                     ;	;.line	106; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	return ADCData;
088 008C [04] C603      	MVF	_ADC_GetData_ADCData_65536_8,0,0
089 008D [04] F01E      	MVF	STK02,1,0
090 008E [04] C602      	MVF	(_ADC_GetData_ADCData_65536_8 + 1),0,0
091 008F [04] F01F      	MVF	STK01,1,0
092 0090 [04] C601      	MVF	(_ADC_GetData_ADCData_65536_8 + 2),0,0
093 0091 [04] F020      	MVF	STK00,1,0
094 0092 [04] 6480      	MVF	(_ADC_GetData_ADCData_65536_8 + 3),0,0
095                     ;	;.line	107; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
096 0093 [04] C4FC      	RET	
097                     ; exit point of _ADC_GetData
098                     	.ENDFUNC	_ADC_GetData
099                     ;--------------------------------------------------------
100                     
101                     .globl _ADC_Open
102                     
103                     ;--------------------------------------------------------
104                     	.FUNC _ADC_Open:12:$L:r0x113F:$L:_ADC_Open_STK00:$L:_ADC_Open_STK01:$L:_ADC_Open_STK02:$L:_ADC_Open_STK03\
105                     :$L:_ADC_Open_STK04:$L:_ADC_Open_STK05:$L:_ADC_Open_STK06:$L:_ADC_Open_STK07:$L:_ADC_Open_STK08\
106                     :$L:_ADC_Open_STK09:$L:_ADC_Open_STK10
107                     ;--------------------------------------------------------
108                     ;	;.line	52; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	void ADC_Open(unsigned char ck,    //Selector of SD18 peripheral operating clock source
109 0094 [00] C481      _ADC_Open:	;Function start
110 0095 [01] 6680      	MVF	r0x113F,1,0
111                     ;	;.line	67; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_CLK_DivSelect(ck);
112 0096 [01] 06CF      	MVL	0xcf
113 0097 [01] 2835      	ANDF	_OSCCN1,0,0
114 0098 [01] 2C80      	IORF	r0x113F,0,0
115 0099 [01] 6635      	MVF	_OSCCN1,1,0
116                     ;	;.line	68; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	CLK_DHSCKSelect(cks);
117 009A [01] 06CF      	MVL	0xcf
118 009B [01] 2834      	ANDF	_OSCCN0,0,0
119 009C [01] 2C81      	IORF	_ADC_Open_STK00,0,0
120 009D [01] 6634      	MVF	_OSCCN0,1,0
121                     ;	;.line	71; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VINSelect(inh,inl);             // Config ADC Input Channel
122 009E [01] 6483      	MVF	_ADC_Open_STK02,0,0
123 009F [01] 2C82      	IORF	_ADC_Open_STK01,0,0
124 00A0 [01] 6640      	MVF	_AD1CN3,1,0
125                     ;	;.line	72; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VRINSelect(vrh,vrl);            // Config ADC Ref. Voltage Input Channel
126 00A1 [01] 060F      	MVL	0x0f
127 00A2 [01] 2841      	ANDF	_AD1CN4,0,0
128 00A3 [01] 6680      	MVF	r0x113F,1,0
129 00A4 [01] 6485      	MVF	_ADC_Open_STK04,0,0
130 00A5 [01] 2E84      	IORF	_ADC_Open_STK03,1,0
131 00A6 [01] 6484      	MVF	_ADC_Open_STK03,0,0
132 00A7 [01] 2C80      	IORF	r0x113F,0,0
133 00A8 [01] 6641      	MVF	_AD1CN4,1,0
134                     ;	;.line	73; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_GainSelect(adgn,pgagn);         // Config PGA Gain and AD Gain
135 00A9 [01] 06E0      	MVL	0xe0
136 00AA [01] 283E      	ANDF	_AD1CN1,0,0
137 00AB [01] 6680      	MVF	r0x113F,1,0
138 00AC [01] 6487      	MVF	_ADC_Open_STK06,0,0
139 00AD [01] 2E86      	IORF	_ADC_Open_STK05,1,0
140 00AE [01] 6486      	MVF	_ADC_Open_STK05,0,0
141 00AF [01] 2C80      	IORF	r0x113F,0,0
142 00B0 [01] 663E      	MVF	_AD1CN1,1,0
143                     ;	;.line	74; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VRXSelect(vrgn);             // Config Ref. Gain and DC offset
144 00B1 [01] 06DF      	MVL	0xdf
145 00B2 [01] 283E      	ANDF	_AD1CN1,0,0
146 00B3 [01] 2C88      	IORF	_ADC_Open_STK07,0,0
147 00B4 [01] 663E      	MVF	_AD1CN1,1,0
148                     ;	;.line	75; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_DCSETSelect(dcset);             // Config Ref. Gain and DC offset
149 00B5 [01] 06F0      	MVL	0xf0
150 00B6 [01] 283F      	ANDF	_AD1CN2,0,0
151 00B7 [01] 2C89      	IORF	_ADC_Open_STK08,0,0
152 00B8 [01] 663F      	MVF	_AD1CN2,1,0
153                     ;	;.line	76; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_OSRSelect(osr);                 // Config Over sampling ratio
154 00B9 [01] 06E1      	MVL	0xe1
155 00BA [01] 283D      	ANDF	_AD1CN0,0,0
156 00BB [01] 2C8A      	IORF	_ADC_Open_STK09,0,0
157 00BC [01] 663D      	MVF	_AD1CN0,1,0
158                     ;	;.line	77; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_VCMSSelect(vcms); 
159 00BD [01] 06DF      	MVL	0xdf
160 00BE [01] 2842      	ANDF	_AD1CN5,0,0
161 00BF [01] 2C8B      	IORF	_ADC_Open_STK10,0,0
162 00C0 [01] 6642      	MVF	_AD1CN5,1,0
163                     ;	;.line	79; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_ENACMEnable();
164 00C1 [01] 9E42      	BSF	_AD1CN5,7
165                     ;	;.line	80; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	ADC_Enable();
166 00C2 [01] 9E3D      	BSF	_AD1CN0,7
167                     ;	;.line	81; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\ADC_52.c"	}
168 00C3 [01] C4F4      	RET	
169                     ; exit point of _ADC_Open
170                     	.ENDFUNC	_ADC_Open
171                     ;--------------------------------------------------------
172                     
173                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
174                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
175                     	;--cdb--S:G$ADC_SDRVEnable$0$0({2}DF,SV:S),C,0,0
176                     	;--cdb--S:G$ADC_SDRVDisable$0$0({2}DF,SV:S),C,0,0
177                     	;--cdb--S:G$ENSDRVEnable$0$0({2}DF,SV:S),C,0,0
178                     	;--cdb--S:G$ENSDRVDisable$0$0({2}DF,SV:S),C,0,0
179                     	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
180                     	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
181                     	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
182                     	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
183                     	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
184                     	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
185                     	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
186                     	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
187                     	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
188                     	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
189                     	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
190                     	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
191                     	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
192                     	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
193                     	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
194                     	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
195                     	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
196                     	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
197                     	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
198                     	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
199                     	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
200                     	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
201                     	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
202                     	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
203                     	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
204                     	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
205                     	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
206                     	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
207                     	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
208                     	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
209                     	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
210                     	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
211                     	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
212                     	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
213                     	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
214                     	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
215                     	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
216                     	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
217                     	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
218                     	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
219                     	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
220                     	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
221                     	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
222                     	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
223                     	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
224                     	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
225                     	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
226                     	;--cdb--S:G$BIEARH$0$0({1}SC:U),I,0,0
227                     	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
228                     	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
229                     	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
230                     	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
231                     	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
232                     	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
233                     	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
234                     	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
235                     	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
236                     	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
237                     	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
238                     	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
239                     	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
240                     	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
241                     	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
242                     	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
243                     	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
244                     	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
245                     	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
246                     	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
247                     	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
248                     	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
249                     	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
250                     	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
251                     	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
252                     	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
253                     	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
254                     	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
255                     	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
256                     	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
257                     	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
258                     	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
259                     	;--cdb--S:G$PT8$0$0({1}SC:U),I,0,0
260                     	;--cdb--S:G$TRISC8$0$0({1}SC:U),I,0,0
261                     	;--cdb--S:G$PT8PU$0$0({1}SC:U),I,0,0
262                     	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
263                     	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
264                     	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
265                     	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
266                     	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
267                     	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
268                     	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
269                     	;--cdb--S:G$LCDCN1$0$0({1}SC:U),I,0,0
270                     	;--cdb--S:G$LCDCN2$0$0({1}SC:U),I,0,0
271                     	;--cdb--S:G$LCDCN3$0$0({1}SC:U),I,0,0
272                     	;--cdb--S:G$LCDCN4$0$0({1}SC:U),I,0,0
273                     	;--cdb--S:G$LCD0$0$0({1}SC:U),I,0,0
274                     	;--cdb--S:G$LCD1$0$0({1}SC:U),I,0,0
275                     	;--cdb--S:G$LCD2$0$0({1}SC:U),I,0,0
276                     	;--cdb--S:G$LCD3$0$0({1}SC:U),I,0,0
277                     	;--cdb--S:G$LCD4$0$0({1}SC:U),I,0,0
278                     	;--cdb--S:G$LCD5$0$0({1}SC:U),I,0,0
279                     	;--cdb--S:G$LCD6$0$0({1}SC:U),I,0,0
280                     	;--cdb--S:G$Filter$0$0({1}SC:U),I,0,0
281                     	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
282                     	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
283                     	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
284                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vcms_65536_5$vcms$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK10]
285                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_osr_65536_5$osr$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK09]
286                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_dcset_65536_5$dcset$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK08]
287                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrgn_65536_5$vrgn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK07]
288                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_pgagn_65536_5$pgagn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK06]
289                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_adgn_65536_5$adgn$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK05]
290                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrl_65536_5$vrl$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK04]
291                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_vrh_65536_5$vrh$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK03]
292                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_inl_65536_5$inl$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK02]
293                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_inh_65536_5$inh$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK01]
294                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_cks_65536_5$cks$10000$5({1}SC:U),R,0,0,[_ADC_Open_STK00]
295                     	;--cdb--S:LADC_52.ADC_Open._ADC_Open_ck_65536_5$ck$10000$5({1}SC:U),R,0,0,[r0x113F]
296                     	;--cdb--S:LADC_52.ADC_GetData._ADC_GetData_ADCData_65536_8$ADCData$10000$8({4}SL:SL),E,0,0
297                     	;--cdb--S:G$ADC_Open$0$0({2}DF,SV:S),C,0,0
298                     	;--cdb--S:G$ADC_GetData$0$0({2}DF,SL:SL),C,0,0
299                     ;--------------------------------------------------------
300                     ; external declarations
301                     ;--------------------------------------------------------
302                     	.globl	_FSR0
303                     	.globl	_FSR1
304                     	.globl	_FSR2
305                     	.globl	_ADCR
306                     
307                     	.globl WSAVE
308                     	.globl STK07
309                     	.globl STK07_SAVE
310                     	.globl STK06
311                     	.globl STK06_SAVE
312                     	.globl STK05
313                     	.globl STK05_SAVE
314                     	.globl STK04
315                     	.globl STK04_SAVE
316                     	.globl STK03
317                     	.globl STK03_SAVE
318                     	.globl STK02
319                     	.globl STK02_SAVE
320                     	.globl STK01
321                     	.globl STK01_SAVE
322                     	.globl STK00
323                     	.globl STK00_SAVE
324                     ;--------------------------------------------------------
325                     ; global -1 declarations
326                     ;--------------------------------------------------------
327                     	.globl	_ADC_Open
328                     
329                     	.globl	_memcpy
330                     ;--------------------------------------------------------
331                     ; global -2 definitions
332                     ;--------------------------------------------------------
333                     	.area DSEG(DATA)
334                     __SWTGTID	.equ	0xA43354DA
335                     
336                     	.area DSEG(DATA)
337                     _INDF0	.equ	0x0
338                     
339                     	.area DSEG(DATA)
340                     _POINC0	.equ	0x1
341                     
342                     	.area DSEG(DATA)
343                     _PODEC0	.equ	0x2
344                     
345                     	.area DSEG(DATA)
346                     _PRINC0	.equ	0x3
347                     
348                     	.area DSEG(DATA)
349                     _PLUSW0	.equ	0x4
350                     
351                     	.area DSEG(DATA)
352                     _INDF1	.equ	0x5
353                     
354                     	.area DSEG(DATA)
355                     _POINC1	.equ	0x6
356                     
357                     	.area DSEG(DATA)
358                     _PODEC1	.equ	0x7
359                     
360                     	.area DSEG(DATA)
361                     _PRINC1	.equ	0x8
362                     
363                     	.area DSEG(DATA)
364                     _PLUSW1	.equ	0x9
365                     
366                     	.area DSEG(DATA)
367                     _INDF2	.equ	0xA
368                     
369                     	.area DSEG(DATA)
370                     _POINC2	.equ	0xB
371                     
372                     	.area DSEG(DATA)
373                     _PODEC2	.equ	0xC
374                     
375                     	.area DSEG(DATA)
376                     _PRINC2	.equ	0xD
377                     
378                     	.area DSEG(DATA)
379                     _PLUSW2	.equ	0xE
380                     
381                     	.area DSEG(DATA)
382                     _FSR0H	.equ	0xF
383                     
384                     	.area DSEG(DATA)
385                     _FSR0L	.equ	0x10
386                     
387                     	.area DSEG(DATA)
388                     _FSR1H	.equ	0x11
389                     
390                     	.area DSEG(DATA)
391                     _FSR1L	.equ	0x12
392                     
393                     	.area DSEG(DATA)
394                     _FSR2H	.equ	0x13
395                     
396                     	.area DSEG(DATA)
397                     _FSR2L	.equ	0x14
398                     
399                     	.area DSEG(DATA)
400                     _TOSH	.equ	0x16
401                     
402                     	.area DSEG(DATA)
403                     _TOSL	.equ	0x17
404                     
405                     	.area DSEG(DATA)
406                     _SKCN	.equ	0x18
407                     
408                     	.area DSEG(DATA)
409                     _PCLATH	.equ	0x1A
410                     
411                     	.area DSEG(DATA)
412                     _PCLATL	.equ	0x1B
413                     
414                     	.area DSEG(DATA)
415                     _TBLPTRH	.equ	0x1D
416                     
417                     	.area DSEG(DATA)
418                     _TBLPTRL	.equ	0x1E
419                     
420                     	.area DSEG(DATA)
421                     _TBLDH	.equ	0x1F
422                     
423                     	.area DSEG(DATA)
424                     _TBLDL	.equ	0x20
425                     
426                     	.area DSEG(DATA)
427                     _PRODH	.equ	0x21
428                     
429                     	.area DSEG(DATA)
430                     _PRODL	.equ	0x22
431                     
432                     	.area DSEG(DATA)
433                     _INTE0	.equ	0x23
434                     
435                     	.area DSEG(DATA)
436                     _INTE1	.equ	0x24
437                     
438                     	.area DSEG(DATA)
439                     _INTF0	.equ	0x26
440                     
441                     	.area DSEG(DATA)
442                     _INTF1	.equ	0x27
443                     
444                     	.area DSEG(DATA)
445                     _WREG	.equ	0x29
446                     
447                     	.area DSEG(DATA)
448                     _BSRCN	.equ	0x2A
449                     
450                     	.area DSEG(DATA)
451                     _STATUS	.equ	0x2B
452                     
453                     	.area DSEG(DATA)
454                     _MSTAT	.equ	0x2B
455                     
456                     	.area DSEG(DATA)
457                     _PSTAT	.equ	0x2C
458                     
459                     	.area DSEG(DATA)
460                     _BIECN	.equ	0x2E
461                     
462                     	.area DSEG(DATA)
463                     _BIEARH	.equ	0x2F
464                     
465                     	.area DSEG(DATA)
466                     _BIEARL	.equ	0x30
467                     
468                     	.area DSEG(DATA)
469                     _BIEDRH	.equ	0x31
470                     
471                     	.area DSEG(DATA)
472                     _BIEDRL	.equ	0x32
473                     
474                     	.area DSEG(DATA)
475                     _PWRCN	.equ	0x33
476                     
477                     	.area DSEG(DATA)
478                     _OSCCN0	.equ	0x34
479                     
480                     	.area DSEG(DATA)
481                     _OSCCN1	.equ	0x35
482                     
483                     	.area DSEG(DATA)
484                     _OSCCN2	.equ	0x36
485                     
486                     	.area DSEG(DATA)
487                     _CSFCN0	.equ	0x37
488                     
489                     	.area DSEG(DATA)
490                     _CSFCN1	.equ	0x38
491                     
492                     	.area DSEG(DATA)
493                     _WDTCN	.equ	0x39
494                     
495                     	.area DSEG(DATA)
496                     _AD1H	.equ	0x3A
497                     
498                     	.area DSEG(DATA)
499                     _AD1M	.equ	0x3B
500                     
501                     	.area DSEG(DATA)
502                     _AD1L	.equ	0x3C
503                     
504                     	.area DSEG(DATA)
505                     _AD1CN0	.equ	0x3D
506                     
507                     	.area DSEG(DATA)
508                     _AD1CN1	.equ	0x3E
509                     
510                     	.area DSEG(DATA)
511                     _AD1CN2	.equ	0x3F
512                     
513                     	.area DSEG(DATA)
514                     _AD1CN3	.equ	0x40
515                     
516                     	.area DSEG(DATA)
517                     _AD1CN4	.equ	0x41
518                     
519                     	.area DSEG(DATA)
520                     _AD1CN5	.equ	0x42
521                     
522                     	.area DSEG(DATA)
523                     _LVDCN	.equ	0x43
524                     
525                     	.area DSEG(DATA)
526                     _TMA1CN	.equ	0x44
527                     
528                     	.area DSEG(DATA)
529                     _TMA1R	.equ	0x45
530                     
531                     	.area DSEG(DATA)
532                     _TMA1C	.equ	0x46
533                     
534                     	.area DSEG(DATA)
535                     _PT1	.equ	0x47
536                     
537                     	.area DSEG(DATA)
538                     _TRISC1	.equ	0x48
539                     
540                     	.area DSEG(DATA)
541                     _PT1DA	.equ	0x49
542                     
543                     	.area DSEG(DATA)
544                     _PT1PU	.equ	0x4A
545                     
546                     	.area DSEG(DATA)
547                     _PT1M1	.equ	0x4B
548                     
549                     	.area DSEG(DATA)
550                     _PT2	.equ	0x4C
551                     
552                     	.area DSEG(DATA)
553                     _TRISC2	.equ	0x4D
554                     
555                     	.area DSEG(DATA)
556                     _PT2DA	.equ	0x4E
557                     
558                     	.area DSEG(DATA)
559                     _PT2PU	.equ	0x4F
560                     
561                     	.area DSEG(DATA)
562                     _PT8	.equ	0x50
563                     
564                     	.area DSEG(DATA)
565                     _TRISC8	.equ	0x51
566                     
567                     	.area DSEG(DATA)
568                     _PT8PU	.equ	0x53
569                     
570                     	.area DSEG(DATA)
571                     _UR0CN	.equ	0x54
572                     
573                     	.area DSEG(DATA)
574                     _UR0STA	.equ	0x55
575                     
576                     	.area DSEG(DATA)
577                     _BA0CN	.equ	0x56
578                     
579                     	.area DSEG(DATA)
580                     _BG0RH	.equ	0x57
581                     
582                     	.area DSEG(DATA)
583                     _BG0RL	.equ	0x58
584                     
585                     	.area DSEG(DATA)
586                     _TX0R	.equ	0x59
587                     
588                     	.area DSEG(DATA)
589                     _RC0REG	.equ	0x5A
590                     
591                     	.area DSEG(DATA)
592                     _LCDCN1	.equ	0x5B
593                     
594                     	.area DSEG(DATA)
595                     _LCDCN2	.equ	0x5C
596                     
597                     	.area DSEG(DATA)
598                     _LCDCN3	.equ	0x5D
599                     
600                     	.area DSEG(DATA)
601                     _LCDCN4	.equ	0x5E
602                     
603                     	.area DSEG(DATA)
604                     _LCD0	.equ	0x5F
605                     
606                     	.area DSEG(DATA)
607                     _LCD1	.equ	0x60
608                     
609                     	.area DSEG(DATA)
610                     _LCD2	.equ	0x61
611                     
612                     	.area DSEG(DATA)
613                     _LCD3	.equ	0x62
614                     
615                     	.area DSEG(DATA)
616                     _LCD4	.equ	0x63
617                     
618                     	.area DSEG(DATA)
619                     _LCD5	.equ	0x64
620                     
621                     	.area DSEG(DATA)
622                     _LCD6	.equ	0x65
623                     
624                     	.area DSEG(DATA)
625                     _Filter	.equ	0x66
626                     
627                     	.area DSEG(DATA)
628                     _ADCRH	.equ	0x3A
629                     
630                     	.area DSEG(DATA)
631                     _ADCRM	.equ	0x3B
632                     
633                     	.area DSEG(DATA)
634                     _ADCRL	.equ	0x3C
635                     
636                     ;--------------------------------------------------------
637                     ; absolute symbol definitions
638                     ;--------------------------------------------------------
639                     ;--------------------------------------------------------
640                     ; compiler-defined variables
641                     ;--------------------------------------------------------
642                     	.area IDATA (DATA,REL,CON); pre-def
643                     	.area IDATAROM (CODE,REL,CON); pre-def
644                     	.area UDATA (DATA,REL,CON); pre-def
645                     	.area UDATA (DATA,REL,CON) ;UDL_ADC_52_0	udata
646 @FSR2-01 --         r0x113F:	.ds	1
647                     	.area LOCALSTK (STK); local stack var
648 @FSR2-00 --         _ADC_Open_STK00:	.ds	1
649                     	.globl _ADC_Open_STK00
650 @FSR2+01 --         _ADC_Open_STK01:	.ds	1
651                     	.globl _ADC_Open_STK01
652 @FSR2+02 --         _ADC_Open_STK02:	.ds	1
653                     	.globl _ADC_Open_STK02
654 @FSR2+03 --         _ADC_Open_STK03:	.ds	1
655                     	.globl _ADC_Open_STK03
656 @FSR2+04 --         _ADC_Open_STK04:	.ds	1
657                     	.globl _ADC_Open_STK04
658 @FSR2+05 --         _ADC_Open_STK05:	.ds	1
659                     	.globl _ADC_Open_STK05
660 @FSR2+06 --         _ADC_Open_STK06:	.ds	1
661                     	.globl _ADC_Open_STK06
662 @FSR2+07 --         _ADC_Open_STK07:	.ds	1
663                     	.globl _ADC_Open_STK07
664 @FSR2+08 --         _ADC_Open_STK08:	.ds	1
665                     	.globl _ADC_Open_STK08
666 @FSR2+09 --         _ADC_Open_STK09:	.ds	1
667                     	.globl _ADC_Open_STK09
668 @FSR2+10 --         _ADC_Open_STK10:	.ds	1
669                     	.globl _ADC_Open_STK10
670 @FSR2-01 -- -- -- -- _ADC_GetData_ADCData_65536_8:	.ds	4
671                     ;--------------------------------------------------------
672                     ; initialized data
673                     ;--------------------------------------------------------
674                     ;--------------------------------------------------------
675                     ; initialized data - mirror
676                     ;--------------------------------------------------------
677                     	;Following is optimization info, 
678                     	;xxcdbxxW:dst:src+offset:srclit:just-remove
679                     	;--cdb--W:r0x114B:NULL+0:-1:1
680                     	;--cdb--W:r0x113F:NULL+0:-1:1
681                     	end
