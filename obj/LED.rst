001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft"
008                     ;;	.file	"D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"
009                     	.module LED
010                     	;.list	p=HY17P52
011                     	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
012                     	;--cdb--F:LED:G$GetDisplay$0$0({2}DF,SC:U),C,0,0,0,0,0
013                     	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
014                     	;--cdb--F:LED:G$LEDSetting$0$0({2}DF,SV:S),C,0,0,0,0,0
015                     ;--------------------------------------------------------
016                     ; overlayable items in internal ram 
017                     ;--------------------------------------------------------
018                     ;	udata_ovr
019                     .area CCODE (code,REL,CON) ; LED-code 
020                     .globl _GetDisplay
021                     
022                     ;--------------------------------------------------------
023                     	.FUNC _GetDisplay:2:$L:r0x1141:$L:_GetDisplay_STK00:$L:r0x1143:$L:r0x1144
024                     ;--------------------------------------------------------
025                     ;	;.line	63; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRTemp=(RRTemp<<1);
026                     _GetDisplay:	;Function start
027                     	MVF	r0x1141,1,0
028                     	BCF	_STATUS,4
029                     	RLFC	r0x1141,0,0
030                     	MVF	r0x1144,1,0
031                     ;	;.line	64; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR=(RRR<<ledx);
032                     	SETF	r0x1143,0
033                     	MVF	_GetDisplay_STK00,0,0
034                     	SUBL	0x00
035                     	BTSZ	_STATUS,0
036                     	JMP	_00112_DS_
037                     _00111_DS_:
038                     	RLFC	r0x1143,1,0
039                     	ADDL	0x01
040                     	BTSS	_STATUS,4
041                     	JMP	_00111_DS_
042                     _00112_DS_:
043                     ;	;.line	65; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRTemp &= RRR;
044                     	MVF	r0x1143,0,0
045                     	ANDF	r0x1144,1,0
046                     ;	;.line	68; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR=RRR>>(8-ledx);
047                     	MVF	_GetDisplay_STK00,0,0
048                     	SUBL	0x08
049                     	MVF	_GetDisplay_STK00,1,0
050                     	SETF	r0x1143,0
051                     	MVF	_GetDisplay_STK00,0,0
052                     	SUBL	0x00
053                     	BTSZ	_STATUS,0
054                     	JMP	_00114_DS_
055                     _00113_DS_:
056                     	RRFC	r0x1143,1,0
057                     	ADDL	0x01
058                     	BTSS	_STATUS,4
059                     	JMP	_00113_DS_
060                     _00114_DS_:
061                     ;	;.line	69; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RLTemp &= RRR;
062                     	MVF	r0x1143,0,0
063                     	ANDF	r0x1141,1,0
064                     ;	;.line	70; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	RRR= RLTemp | RRTemp;
065                     	MVF	r0x1141,0,0
066                     	IORF	r0x1144,1,0
067                     ;	;.line	72; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	return RRR;
068                     	MVF	r0x1144,0,0
069                     ;	;.line	73; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	}
070                     	RET	
071                     ; exit point of _GetDisplay
072                     	.ENDFUNC	_GetDisplay
073                     ;--------------------------------------------------------
074                     
075                     .globl _LEDSetting
076                     
077                     ;--------------------------------------------------------
078                     	.FUNC _LEDSetting:1:$L:r0x113F
079                     ;--------------------------------------------------------
080                     ;	;.line	33; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	void LEDSetting(unsigned char cclevel)
081                     _LEDSetting:	;Function start
082                     	MVF	r0x113F,1,0
083                     ;	;.line	35; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	CCNT_CCLevelSel(cclevel);
084                     	MVL	0xf8
085                     	ANDF	_CCNT,0,0
086                     	IORF	r0x113F,0,0
087                     	MVF	_CCNT,1,0
088                     ;	;.line	36; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	ENCCALL_Enable();
089                     	SETF	_ENCCMode,0
090                     ;	;.line	37; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	PT12DA=0x00;
091                     	CLRF	_PT12DA,0
092                     ;	;.line	38; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	INTE2 |= 0x40;
093                     	BSF	_INTE2,6
094                     ;	;.line	39; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	TMA2CN=0xc0;
095                     	MVL	0xc0
096                     	MVF	_TMA2CN,1,0
097                     ;	;.line	40; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	TMA2C=2;		     //Set Scan Rate
098                     	MVL	0x02
099                     	MVF	_TMA2C,1,0
100                     ;	;.line	41; "D:\NZSE20A_project\NZSE20A_Soft_proj\HY17P52_LCD_soft\Driver\HY17P\LED.c"	}
101                     	RET	
102                     ; exit point of _LEDSetting
103                     	.ENDFUNC	_LEDSetting
104                     ;--------------------------------------------------------
105                     
106                     	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
107                     	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
108                     	;--cdb--S:G$FSR0$0$0({2}DX,SC:U),E,0,0
109                     	;--cdb--S:G$FSR1$0$0({2}DX,SC:U),E,0,0
110                     	;--cdb--S:G$FSR2$0$0({2}DX,SC:U),E,0,0
111                     	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
112                     	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
113                     	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
114                     	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
115                     	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
116                     	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
117                     	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
118                     	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
119                     	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
120                     	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
121                     	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
122                     	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
123                     	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
124                     	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
125                     	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
126                     	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
127                     	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
128                     	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
129                     	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
130                     	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
131                     	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
132                     	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
133                     	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
134                     	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
135                     	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
136                     	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
137                     	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
138                     	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
139                     	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
140                     	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
141                     	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
142                     	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
143                     	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
144                     	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
145                     	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
146                     	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
147                     	;--cdb--S:G$INTE2$0$0({1}SC:U),I,0,0
148                     	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
149                     	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
150                     	;--cdb--S:G$INTF2$0$0({1}SC:U),I,0,0
151                     	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
152                     	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
153                     	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
154                     	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
155                     	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
156                     	;--cdb--S:G$INTE3$0$0({1}SC:U),I,0,0
157                     	;--cdb--S:G$INTF3$0$0({1}SC:U),I,0,0
158                     	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
159                     	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
160                     	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
161                     	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
162                     	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
163                     	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
164                     	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
165                     	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
166                     	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
167                     	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
168                     	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
169                     	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
170                     	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
171                     	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
172                     	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
173                     	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
174                     	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
175                     	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
176                     	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
177                     	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
178                     	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
179                     	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
180                     	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
181                     	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
182                     	;--cdb--S:G$TB1FLAG$0$0({1}SC:U),I,0,0
183                     	;--cdb--S:G$TB1CN0$0$0({1}SC:U),I,0,0
184                     	;--cdb--S:G$TB1CN1$0$0({1}SC:U),I,0,0
185                     	;--cdb--S:G$TB1RH$0$0({1}SC:U),I,0,0
186                     	;--cdb--S:G$TB1RL$0$0({1}SC:U),I,0,0
187                     	;--cdb--S:G$TB1C0H$0$0({1}SC:U),I,0,0
188                     	;--cdb--S:G$TB1C0L$0$0({1}SC:U),I,0,0
189                     	;--cdb--S:G$TB1C1H$0$0({1}SC:U),I,0,0
190                     	;--cdb--S:G$TB1C1L$0$0({1}SC:U),I,0,0
191                     	;--cdb--S:G$TB1C2H$0$0({1}SC:U),I,0,0
192                     	;--cdb--S:G$TB1C2L$0$0({1}SC:U),I,0,0
193                     	;--cdb--S:G$TC1CN0$0$0({1}SC:U),I,0,0
194                     	;--cdb--S:G$TC1CN1$0$0({1}SC:U),I,0,0
195                     	;--cdb--S:G$TC1R0H$0$0({1}SC:U),I,0,0
196                     	;--cdb--S:G$TC1R0L$0$0({1}SC:U),I,0,0
197                     	;--cdb--S:G$TC1R1H$0$0({1}SC:U),I,0,0
198                     	;--cdb--S:G$TC1R1L$0$0({1}SC:U),I,0,0
199                     	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
200                     	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
201                     	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
202                     	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
203                     	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
204                     	;--cdb--S:G$PT1M2$0$0({1}SC:U),I,0,0
205                     	;--cdb--S:G$PT1INT$0$0({1}SC:U),I,0,0
206                     	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
207                     	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
208                     	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
209                     	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
210                     	;--cdb--S:G$PT2INT$0$0({1}SC:U),I,0,0
211                     	;--cdb--S:G$PT2INTE$0$0({1}SC:U),I,0,0
212                     	;--cdb--S:G$PT2INTF$0$0({1}SC:U),I,0,0
213                     	;--cdb--S:G$PT4$0$0({1}SC:U),I,0,0
214                     	;--cdb--S:G$PT4DA$0$0({1}SC:U),I,0,0
215                     	;--cdb--S:G$PT4PU$0$0({1}SC:U),I,0,0
216                     	;--cdb--S:G$PT4INT$0$0({1}SC:U),I,0,0
217                     	;--cdb--S:G$PT4INTE$0$0({1}SC:U),I,0,0
218                     	;--cdb--S:G$PT4INTF$0$0({1}SC:U),I,0,0
219                     	;--cdb--S:G$PT12$0$0({1}SC:U),I,0,0
220                     	;--cdb--S:G$TRISC12$0$0({1}SC:U),I,0,0
221                     	;--cdb--S:G$PT12DA$0$0({1}SC:U),I,0,0
222                     	;--cdb--S:G$PT12PU$0$0({1}SC:U),I,0,0
223                     	;--cdb--S:G$TMA2CN$0$0({1}SC:U),I,0,0
224                     	;--cdb--S:G$TMA2R$0$0({1}SC:U),I,0,0
225                     	;--cdb--S:G$TMA2C$0$0({1}SC:U),I,0,0
226                     	;--cdb--S:G$SSPCN0$0$0({1}SC:U),I,0,0
227                     	;--cdb--S:G$SSPSTA0$0$0({1}SC:U),I,0,0
228                     	;--cdb--S:G$SSPBUF0$0$0({1}SC:U),I,0,0
229                     	;--cdb--S:G$CFG0$0$0({1}SC:U),I,0,0
230                     	;--cdb--S:G$ACT0$0$0({1}SC:U),I,0,0
231                     	;--cdb--S:G$STA0$0$0({1}SC:U),I,0,0
232                     	;--cdb--S:G$CRG0$0$0({1}SC:U),I,0,0
233                     	;--cdb--S:G$TOC0$0$0({1}SC:U),I,0,0
234                     	;--cdb--S:G$RDB0$0$0({1}SC:U),I,0,0
235                     	;--cdb--S:G$TDB0$0$0({1}SC:U),I,0,0
236                     	;--cdb--S:G$SID0$0$0({1}SC:U),I,0,0
237                     	;--cdb--S:G$CFG2$0$0({1}SC:U),I,0,0
238                     	;--cdb--S:G$ACT2$0$0({1}SC:U),I,0,0
239                     	;--cdb--S:G$STA2$0$0({1}SC:U),I,0,0
240                     	;--cdb--S:G$CRG2$0$0({1}SC:U),I,0,0
241                     	;--cdb--S:G$TOC2$0$0({1}SC:U),I,0,0
242                     	;--cdb--S:G$RDB2$0$0({1}SC:U),I,0,0
243                     	;--cdb--S:G$TDB2$0$0({1}SC:U),I,0,0
244                     	;--cdb--S:G$SID2$0$0({1}SC:U),I,0,0
245                     	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
246                     	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
247                     	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
248                     	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
249                     	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
250                     	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
251                     	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
252                     	;--cdb--S:G$UR2CN$0$0({1}SC:U),I,0,0
253                     	;--cdb--S:G$UR2STA$0$0({1}SC:U),I,0,0
254                     	;--cdb--S:G$BA2CN$0$0({1}SC:U),I,0,0
255                     	;--cdb--S:G$BG2RH$0$0({1}SC:U),I,0,0
256                     	;--cdb--S:G$BG2RL$0$0({1}SC:U),I,0,0
257                     	;--cdb--S:G$TX2R$0$0({1}SC:U),I,0,0
258                     	;--cdb--S:G$RC2REG$0$0({1}SC:U),I,0,0
259                     	;--cdb--S:G$CCNT$0$0({1}SC:U),I,0,0
260                     	;--cdb--S:G$ENCCMode$0$0({1}SC:U),I,0,0
261                     	;--cdb--S:G$PT1AIE$0$0({1}SC:U),I,0,0
262                     	;--cdb--S:G$PT2AIE$0$0({1}SC:U),I,0,0
263                     	;--cdb--S:G$PT4AIE$0$0({1}SC:U),I,0,0
264                     	;--cdb--S:G$PT6AIE$0$0({1}SC:U),I,0,0
265                     	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
266                     	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
267                     	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
268                     	;--cdb--S:LLED.LEDSetting._LEDSetting_cclevel_65536_3$cclevel$10000$3({1}SC:U),R,0,0,[r0x113F]
269                     	;--cdb--S:LLED.GetDisplay._GetDisplay_ledx_65536_5$ledx$10000$5({1}SC:U),R,0,0,[_GetDisplay_STK00]
270                     	;--cdb--S:LLED.GetDisplay._GetDisplay_show_65536_5$show$10000$5({1}SC:U),R,0,0,[r0x1141]
271                     	;--cdb--S:LLED.GetDisplay._GetDisplay_RRTemp_65536_6$RRTemp$10000$6({1}SC:U),R,0,0,[r0x1144]
272                     	;--cdb--S:LLED.GetDisplay._GetDisplay_RLTemp_65536_6$RLTemp$10000$6({1}SC:U),R,0,0,[r0x1141]
273                     	;--cdb--S:LLED.GetDisplay._GetDisplay_RRR_65536_6$RRR$10000$6({1}SC:U),R,0,0,[r0x1143]
274                     	;--cdb--S:G$LEDSetting$0$0({2}DF,SV:S),C,0,0
275                     	;--cdb--S:G$GetDisplay$0$0({2}DF,SC:U),C,0,0
276                     	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
277                     ;--------------------------------------------------------
278                     ; external declarations
279                     ;--------------------------------------------------------
280                     	.globl	_FSR0
281                     	.globl	_FSR1
282                     	.globl	_FSR2
283                     	.globl	_ADCR
284                     
285                     	.globl WSAVE
286                     	.globl STK07
287                     	.globl STK07_SAVE
288                     	.globl STK06
289                     	.globl STK06_SAVE
290                     	.globl STK05
291                     	.globl STK05_SAVE
292                     	.globl STK04
293                     	.globl STK04_SAVE
294                     	.globl STK03
295                     	.globl STK03_SAVE
296                     	.globl STK02
297                     	.globl STK02_SAVE
298                     	.globl STK01
299                     	.globl STK01_SAVE
300                     	.globl STK00
301                     	.globl STK00_SAVE
302                     ;--------------------------------------------------------
303                     ; global -1 declarations
304                     ;--------------------------------------------------------
305                     	.globl	_GetDisplay
306                     	.globl	_LEDSetting
307                     
308                     	.globl	_memcpy
309                     ;--------------------------------------------------------
310                     ; global -2 definitions
311                     ;--------------------------------------------------------
312                     	.area DSEG(DATA)
313                     __SWTGTID	.equ	0x93E79486
314                     
315                     	.area DSEG(DATA)
316                     _INDF0	.equ	0x0
317                     
318                     	.area DSEG(DATA)
319                     _POINC0	.equ	0x1
320                     
321                     	.area DSEG(DATA)
322                     _PODEC0	.equ	0x2
323                     
324                     	.area DSEG(DATA)
325                     _PRINC0	.equ	0x3
326                     
327                     	.area DSEG(DATA)
328                     _PLUSW0	.equ	0x4
329                     
330                     	.area DSEG(DATA)
331                     _INDF1	.equ	0x5
332                     
333                     	.area DSEG(DATA)
334                     _POINC1	.equ	0x6
335                     
336                     	.area DSEG(DATA)
337                     _PODEC1	.equ	0x7
338                     
339                     	.area DSEG(DATA)
340                     _PRINC1	.equ	0x8
341                     
342                     	.area DSEG(DATA)
343                     _PLUSW1	.equ	0x9
344                     
345                     	.area DSEG(DATA)
346                     _INDF2	.equ	0xA
347                     
348                     	.area DSEG(DATA)
349                     _POINC2	.equ	0xB
350                     
351                     	.area DSEG(DATA)
352                     _PODEC2	.equ	0xC
353                     
354                     	.area DSEG(DATA)
355                     _PRINC2	.equ	0xD
356                     
357                     	.area DSEG(DATA)
358                     _PLUSW2	.equ	0xE
359                     
360                     	.area DSEG(DATA)
361                     _FSR0H	.equ	0xF
362                     
363                     	.area DSEG(DATA)
364                     _FSR0L	.equ	0x10
365                     
366                     	.area DSEG(DATA)
367                     _FSR1H	.equ	0x11
368                     
369                     	.area DSEG(DATA)
370                     _FSR1L	.equ	0x12
371                     
372                     	.area DSEG(DATA)
373                     _FSR2H	.equ	0x13
374                     
375                     	.area DSEG(DATA)
376                     _FSR2L	.equ	0x14
377                     
378                     	.area DSEG(DATA)
379                     _TOSH	.equ	0x16
380                     
381                     	.area DSEG(DATA)
382                     _TOSL	.equ	0x17
383                     
384                     	.area DSEG(DATA)
385                     _SKCN	.equ	0x18
386                     
387                     	.area DSEG(DATA)
388                     _PCLATH	.equ	0x1A
389                     
390                     	.area DSEG(DATA)
391                     _PCLATL	.equ	0x1B
392                     
393                     	.area DSEG(DATA)
394                     _TBLPTRH	.equ	0x1D
395                     
396                     	.area DSEG(DATA)
397                     _TBLPTRL	.equ	0x1E
398                     
399                     	.area DSEG(DATA)
400                     _TBLDH	.equ	0x1F
401                     
402                     	.area DSEG(DATA)
403                     _TBLDL	.equ	0x20
404                     
405                     	.area DSEG(DATA)
406                     _PRODH	.equ	0x21
407                     
408                     	.area DSEG(DATA)
409                     _PRODL	.equ	0x22
410                     
411                     	.area DSEG(DATA)
412                     _INTE0	.equ	0x23
413                     
414                     	.area DSEG(DATA)
415                     _INTE1	.equ	0x24
416                     
417                     	.area DSEG(DATA)
418                     _INTE2	.equ	0x25
419                     
420                     	.area DSEG(DATA)
421                     _INTF0	.equ	0x26
422                     
423                     	.area DSEG(DATA)
424                     _INTF1	.equ	0x27
425                     
426                     	.area DSEG(DATA)
427                     _INTF2	.equ	0x28
428                     
429                     	.area DSEG(DATA)
430                     _WREG	.equ	0x29
431                     
432                     	.area DSEG(DATA)
433                     _BSRCN	.equ	0x2A
434                     
435                     	.area DSEG(DATA)
436                     _STATUS	.equ	0x2B
437                     
438                     	.area DSEG(DATA)
439                     _MSTAT	.equ	0x2B
440                     
441                     	.area DSEG(DATA)
442                     _PSTAT	.equ	0x2C
443                     
444                     	.area DSEG(DATA)
445                     _INTE3	.equ	0x2E
446                     
447                     	.area DSEG(DATA)
448                     _INTF3	.equ	0x30
449                     
450                     	.area DSEG(DATA)
451                     _BIECN	.equ	0x31
452                     
453                     	.area DSEG(DATA)
454                     _BIEARL	.equ	0x33
455                     
456                     	.area DSEG(DATA)
457                     _BIEDRH	.equ	0x34
458                     
459                     	.area DSEG(DATA)
460                     _BIEDRL	.equ	0x35
461                     
462                     	.area DSEG(DATA)
463                     _PWRCN	.equ	0x36
464                     
465                     	.area DSEG(DATA)
466                     _OSCCN0	.equ	0x37
467                     
468                     	.area DSEG(DATA)
469                     _OSCCN1	.equ	0x38
470                     
471                     	.area DSEG(DATA)
472                     _OSCCN2	.equ	0x39
473                     
474                     	.area DSEG(DATA)
475                     _CSFCN0	.equ	0x3A
476                     
477                     	.area DSEG(DATA)
478                     _CSFCN1	.equ	0x3B
479                     
480                     	.area DSEG(DATA)
481                     _WDTCN	.equ	0x3E
482                     
483                     	.area DSEG(DATA)
484                     _AD1H	.equ	0x3F
485                     
486                     	.area DSEG(DATA)
487                     _AD1M	.equ	0x40
488                     
489                     	.area DSEG(DATA)
490                     _AD1L	.equ	0x41
491                     
492                     	.area DSEG(DATA)
493                     _AD1CN0	.equ	0x42
494                     
495                     	.area DSEG(DATA)
496                     _AD1CN1	.equ	0x43
497                     
498                     	.area DSEG(DATA)
499                     _AD1CN2	.equ	0x44
500                     
501                     	.area DSEG(DATA)
502                     _AD1CN3	.equ	0x45
503                     
504                     	.area DSEG(DATA)
505                     _AD1CN4	.equ	0x46
506                     
507                     	.area DSEG(DATA)
508                     _AD1CN5	.equ	0x47
509                     
510                     	.area DSEG(DATA)
511                     _LVDCN	.equ	0x48
512                     
513                     	.area DSEG(DATA)
514                     _TMA1CN	.equ	0x49
515                     
516                     	.area DSEG(DATA)
517                     _TMA1R	.equ	0x4A
518                     
519                     	.area DSEG(DATA)
520                     _TMA1C	.equ	0x4B
521                     
522                     	.area DSEG(DATA)
523                     _TB1FLAG	.equ	0x4C
524                     
525                     	.area DSEG(DATA)
526                     _TB1CN0	.equ	0x4D
527                     
528                     	.area DSEG(DATA)
529                     _TB1CN1	.equ	0x4E
530                     
531                     	.area DSEG(DATA)
532                     _TB1RH	.equ	0x4F
533                     
534                     	.area DSEG(DATA)
535                     _TB1RL	.equ	0x50
536                     
537                     	.area DSEG(DATA)
538                     _TB1C0H	.equ	0x51
539                     
540                     	.area DSEG(DATA)
541                     _TB1C0L	.equ	0x52
542                     
543                     	.area DSEG(DATA)
544                     _TB1C1H	.equ	0x53
545                     
546                     	.area DSEG(DATA)
547                     _TB1C1L	.equ	0x54
548                     
549                     	.area DSEG(DATA)
550                     _TB1C2H	.equ	0x55
551                     
552                     	.area DSEG(DATA)
553                     _TB1C2L	.equ	0x56
554                     
555                     	.area DSEG(DATA)
556                     _TC1CN0	.equ	0x57
557                     
558                     	.area DSEG(DATA)
559                     _TC1CN1	.equ	0x58
560                     
561                     	.area DSEG(DATA)
562                     _TC1R0H	.equ	0x59
563                     
564                     	.area DSEG(DATA)
565                     _TC1R0L	.equ	0x5A
566                     
567                     	.area DSEG(DATA)
568                     _TC1R1H	.equ	0x5B
569                     
570                     	.area DSEG(DATA)
571                     _TC1R1L	.equ	0x5C
572                     
573                     	.area DSEG(DATA)
574                     _PT1	.equ	0x5D
575                     
576                     	.area DSEG(DATA)
577                     _TRISC1	.equ	0x5E
578                     
579                     	.area DSEG(DATA)
580                     _PT1DA	.equ	0x5F
581                     
582                     	.area DSEG(DATA)
583                     _PT1PU	.equ	0x60
584                     
585                     	.area DSEG(DATA)
586                     _PT1M1	.equ	0x61
587                     
588                     	.area DSEG(DATA)
589                     _PT1M2	.equ	0x62
590                     
591                     	.area DSEG(DATA)
592                     _PT1INT	.equ	0x63
593                     
594                     	.area DSEG(DATA)
595                     _PT2	.equ	0x64
596                     
597                     	.area DSEG(DATA)
598                     _TRISC2	.equ	0x65
599                     
600                     	.area DSEG(DATA)
601                     _PT2DA	.equ	0x66
602                     
603                     	.area DSEG(DATA)
604                     _PT2PU	.equ	0x67
605                     
606                     	.area DSEG(DATA)
607                     _PT2INT	.equ	0x6A
608                     
609                     	.area DSEG(DATA)
610                     _PT2INTE	.equ	0x6B
611                     
612                     	.area DSEG(DATA)
613                     _PT2INTF	.equ	0x6C
614                     
615                     	.area DSEG(DATA)
616                     _PT4	.equ	0x6D
617                     
618                     	.area DSEG(DATA)
619                     _PT4DA	.equ	0x6F
620                     
621                     	.area DSEG(DATA)
622                     _PT4PU	.equ	0x70
623                     
624                     	.area DSEG(DATA)
625                     _PT4INT	.equ	0x73
626                     
627                     	.area DSEG(DATA)
628                     _PT4INTE	.equ	0x74
629                     
630                     	.area DSEG(DATA)
631                     _PT4INTF	.equ	0x75
632                     
633                     	.area DSEG(DATA)
634                     _PT12	.equ	0x76
635                     
636                     	.area DSEG(DATA)
637                     _TRISC12	.equ	0x77
638                     
639                     	.area DSEG(DATA)
640                     _PT12DA	.equ	0x78
641                     
642                     	.area DSEG(DATA)
643                     _PT12PU	.equ	0x79
644                     
645                     	.area DSEG(DATA)
646                     _TMA2CN	.equ	0x7A
647                     
648                     	.area DSEG(DATA)
649                     _TMA2R	.equ	0x7B
650                     
651                     	.area DSEG(DATA)
652                     _TMA2C	.equ	0x7C
653                     
654                     	.area DSEG(DATA)
655                     _SSPCN0	.equ	0x7D
656                     
657                     	.area DSEG(DATA)
658                     _SSPSTA0	.equ	0x7E
659                     
660                     	.area DSEG(DATA)
661                     _SSPBUF0	.equ	0x7F
662                     
663                     	.area DSEG(DATA)
664                     _CFG0	.equ	0x180
665                     
666                     	.area DSEG(DATA)
667                     _ACT0	.equ	0x181
668                     
669                     	.area DSEG(DATA)
670                     _STA0	.equ	0x182
671                     
672                     	.area DSEG(DATA)
673                     _CRG0	.equ	0x183
674                     
675                     	.area DSEG(DATA)
676                     _TOC0	.equ	0x184
677                     
678                     	.area DSEG(DATA)
679                     _RDB0	.equ	0x185
680                     
681                     	.area DSEG(DATA)
682                     _TDB0	.equ	0x186
683                     
684                     	.area DSEG(DATA)
685                     _SID0	.equ	0x187
686                     
687                     	.area DSEG(DATA)
688                     _CFG2	.equ	0x188
689                     
690                     	.area DSEG(DATA)
691                     _ACT2	.equ	0x189
692                     
693                     	.area DSEG(DATA)
694                     _STA2	.equ	0x18A
695                     
696                     	.area DSEG(DATA)
697                     _CRG2	.equ	0x18B
698                     
699                     	.area DSEG(DATA)
700                     _TOC2	.equ	0x18C
701                     
702                     	.area DSEG(DATA)
703                     _RDB2	.equ	0x18D
704                     
705                     	.area DSEG(DATA)
706                     _TDB2	.equ	0x18E
707                     
708                     	.area DSEG(DATA)
709                     _SID2	.equ	0x18F
710                     
711                     	.area DSEG(DATA)
712                     _UR0CN	.equ	0x190
713                     
714                     	.area DSEG(DATA)
715                     _UR0STA	.equ	0x191
716                     
717                     	.area DSEG(DATA)
718                     _BA0CN	.equ	0x192
719                     
720                     	.area DSEG(DATA)
721                     _BG0RH	.equ	0x193
722                     
723                     	.area DSEG(DATA)
724                     _BG0RL	.equ	0x194
725                     
726                     	.area DSEG(DATA)
727                     _TX0R	.equ	0x195
728                     
729                     	.area DSEG(DATA)
730                     _RC0REG	.equ	0x196
731                     
732                     	.area DSEG(DATA)
733                     _UR2CN	.equ	0x197
734                     
735                     	.area DSEG(DATA)
736                     _UR2STA	.equ	0x198
737                     
738                     	.area DSEG(DATA)
739                     _BA2CN	.equ	0x199
740                     
741                     	.area DSEG(DATA)
742                     _BG2RH	.equ	0x19A
743                     
744                     	.area DSEG(DATA)
745                     _BG2RL	.equ	0x19B
746                     
747                     	.area DSEG(DATA)
748                     _TX2R	.equ	0x19C
749                     
750                     	.area DSEG(DATA)
751                     _RC2REG	.equ	0x19D
752                     
753                     	.area DSEG(DATA)
754                     _CCNT	.equ	0x19E
755                     
756                     	.area DSEG(DATA)
757                     _ENCCMode	.equ	0x19F
758                     
759                     	.area DSEG(DATA)
760                     _PT1AIE	.equ	0x1B0
761                     
762                     	.area DSEG(DATA)
763                     _PT2AIE	.equ	0x1B1
764                     
765                     	.area DSEG(DATA)
766                     _PT4AIE	.equ	0x1B3
767                     
768                     	.area DSEG(DATA)
769                     _PT6AIE	.equ	0x1B5
770                     
771                     	.area DSEG(DATA)
772                     _ADCRH	.equ	0x3F
773                     
774                     	.area DSEG(DATA)
775                     _ADCRM	.equ	0x40
776                     
777                     	.area DSEG(DATA)
778                     _ADCRL	.equ	0x41
779                     
780                     ;--------------------------------------------------------
781                     ; absolute symbol definitions
782                     ;--------------------------------------------------------
783                     ;--------------------------------------------------------
784                     ; compiler-defined variables
785                     ;--------------------------------------------------------
786                     	.area IDATA (DATA,REL,CON); pre-def
787                     	.area IDATAROM (CODE,REL,CON); pre-def
788                     	.area UDATA (DATA,REL,CON); pre-def
789                     	.area UDATA (DATA,REL,CON) ;UDL_LED_0	udata
790 0000 --             r0x113F:	.ds	1
791 0000 --             r0x1141:	.ds	1
792 0002 --             r0x1143:	.ds	1
793 0003 --             r0x1144:	.ds	1
794                     	.area LOCALSTK (STK); local stack var
795 0001 --             _GetDisplay_STK00:	.ds	1
796                     	.globl _GetDisplay_STK00
797                     ;--------------------------------------------------------
798                     ; initialized data
799                     ;--------------------------------------------------------
800                     ;--------------------------------------------------------
801                     ; initialized data - mirror
802                     ;--------------------------------------------------------
803                     	;Following is optimization info, 
804                     	;xxcdbxxW:dst:src+offset:srclit:just-remove
805                     	;--cdb--W:r0x1143:r0x1141+0:-1:0
806                     	;--cdb--W:r0x1141:NULL+0:-1:1
807                     	;--cdb--W:r0x1140:NULL+0:-1:1
808                     	end
