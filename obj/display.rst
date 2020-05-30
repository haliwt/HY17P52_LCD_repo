001                     ;--------------------------------------------------------
002                     ; File Created by SDCC : open source ANSI-C Compiler modified for HYCON CPU
003                     ; Version 3.9.3 #4ad52972e (MSVC)
004                     ;--------------------------------------------------------
005                     ; Port for HYCON CPU
006                     ;--------------------------------------------------------
007                     ;	;CCFROM:"E:\HY17P52_TestSoft\HY17P52_LCD_soft"
008                     ;;	.file	".\display.c"
009                     	.module display
010                     	;.list	p=HY17P52
011                     	;--cdb--T:Fdisplay$_adc_works_[({0}S:S$save_mode$0$0({1}SB0$1:U),Z,0,0)({0}S:S$unit_setMode$0$0({1}SB1$1:U),Z,0,0)({1}S:S$plus_uint$0$0({1}SC:U),Z,0,0)({2}S:S$unitChoose$0$0({1}SC:U),Z,0,0)({3}S:S$testMode$0$0({1}SB0$1:U),Z,0,0)({3}S:S$zeroPoint_Mode$0$0({1}SB1$1:U),Z,0,0)({3}S:S$error_mod$0$0({1}SB2$1:U),Z,0,0)({4}S:S$key_flag$0$0({1}SC:U),Z,0,0)({5}S:S$resetZeroDisplay$0$0({1}SC:U),Z,0,0)({6}S:S$quitCurrentMode$0$0({1}SB0$1:U),Z,0,0)({6}S:S$LVD_2V4_flag$0$0({1}SB1$1:U),Z,0,0)({6}S:S$LVD_3V_flag$0$0({1}SB2$1:U),Z,0,0)({6}S:S$plus_revise_flag$0$0({1}SB3$1:U),Z,0,0)({6}S:S$minus_revise_flag$0$0({1}SB4$1:U),Z,0,0)({6}S:S$Presskey_flag$0$0({1}SB5$1:U),Z,0,0)({6}S:S$Pressure_sign$0$0({1}SB6$1:U),Z,0,0)({7}S:S$eepromRead_high_bit$0$0({1}SC:U),Z,0,0)({8}S:S$eepromRead_low_bit$0$0({1}SC:U),Z,0,0)({9}S:S$reload_ADCInterrupt$0$0({1}SB0$1:U),Z,0,0)({10}S:S$m_offset_value$0$0({2}SI:S),Z,0,0)({12}S:S$p_offset_value$0$0({2}SI:S),Z,0,0)]
012                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
013                     	;--cdb--F:display:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0,0,0,0
014                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
015                     	;--cdb--F:display:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0,0,0,0
016                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
017                     	;--cdb--F:display:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0,0,0,0
018                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
019                     	;--cdb--F:display:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0,0,0,0
020                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
021                     	;--cdb--F:display:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0,0,0,0
022                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
023                     	;--cdb--F:display:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0,0,0,0
024                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
025                     	;--cdb--F:display:G$Delay$0$0({2}DF,SV:S),C,0,0,0,0,0
026                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
027                     	;--cdb--F:display:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0,0,0,0
028                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
029                     	;--cdb--F:display:G$Display2Er$0$0({2}DF,SV:S),C,0,0,0,0,0
030                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
031                     	;--cdb--F:display:G$DisplayHex$0$0({2}DF,SV:S),C,0,0,0,0,0
032                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
033                     	;--cdb--F:display:G$DisplayNum$0$0({2}DF,SV:S),C,0,0,0,0,0
034                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
035                     	;--cdb--F:display:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0,0,0,0
036                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
037                     	;--cdb--F:display:G$ClearLCD$0$0({2}DF,SV:S),C,0,0,0,0,0
038                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
039                     	;--cdb--F:display:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0,0,0,0
040                     	;--cdb--S:G$_modslong$0$0({2}DF,SL:SL),C,0,0
041                     	;--cdb--S:G$_divslong$0$0({2}DF,SL:SL),C,0,0
042                     	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
043                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
044                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
045                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
046                     ;--------------------------------------------------------
047                     ; overlayable items in internal ram 
048                     ;--------------------------------------------------------
049                     ;	udata_ovr
050                     .area CCODE (code,REL,CON) ; display-code 
051                     .globl _DispalyBatteryCapacityLow
052                     
053                     ;--------------------------------------------------------
054                     	.FUNC _DispalyBatteryCapacityLow:0
055                     ;--------------------------------------------------------
056                     ;	;.line	204; ".\display.c"	LCD_WriteData(&LCD0,0x90);
057                     _DispalyBatteryCapacityLow:	;Function start
058 00BF [00] 0690      	MVL	0x90
059 00C0 [00] 665F      	MVF	_LCD0,1,0
060                     ;	;.line	206; ".\display.c"	}
061 00C1 [00] 000A      	RET	
062                     ; exit point of _DispalyBatteryCapacityLow
063                     	.ENDFUNC	_DispalyBatteryCapacityLow
064                     ;--------------------------------------------------------
065                     
066                     .globl _DisplayBatteryCapacityHalf
067                     
068                     ;--------------------------------------------------------
069                     	.FUNC _DisplayBatteryCapacityHalf:0
070                     ;--------------------------------------------------------
071                     ;	;.line	193; ".\display.c"	LCD_WriteData(&LCD0,0xd0);
072                     _DisplayBatteryCapacityHalf:	;Function start
073 00C2 [00] 06D0      	MVL	0xd0
074 00C3 [00] 665F      	MVF	_LCD0,1,0
075                     ;	;.line	195; ".\display.c"	}
076 00C4 [00] 000A      	RET	
077                     ; exit point of _DisplayBatteryCapacityHalf
078                     	.ENDFUNC	_DisplayBatteryCapacityHalf
079                     ;--------------------------------------------------------
080                     
081                     .globl _DisplayBatteryCapacityFull
082                     
083                     ;--------------------------------------------------------
084                     	.FUNC _DisplayBatteryCapacityFull:0
085                     ;--------------------------------------------------------
086                     ;	;.line	183; ".\display.c"	LCD_WriteData(&LCD0,0xff);
087                     _DisplayBatteryCapacityFull:	;Function start
088 00C5 [00] 0A5F      	SETF	_LCD0,0
089                     ;	;.line	184; ".\display.c"	}
090 00C6 [00] 000A      	RET	
091                     ; exit point of _DisplayBatteryCapacityFull
092                     	.ENDFUNC	_DisplayBatteryCapacityFull
093                     ;--------------------------------------------------------
094                     
095                     .globl _DisplayLLL
096                     
097                     ;--------------------------------------------------------
098                     	.FUNC _DisplayLLL:0
099                     ;--------------------------------------------------------
100                     ;	;.line	167; ".\display.c"	LCD_WriteData(&LCD0,0x00);
101                     _DisplayLLL:	;Function start
102                     	CLRF	_LCD0,0
103                     ;	;.line	168; ".\display.c"	LCD_WriteData(&LCD1,Char_L);
104                     	MVL	0x70
105                     	MVF	_LCD1,1,0
106                     ;	;.line	169; ".\display.c"	LCD_WriteData(&LCD2,Char_L);
107                     	MVF	_LCD2,1,0
108                     ;	;.line	170; ".\display.c"	LCD_WriteData(&LCD3,Char_L); 
109                     	MVF	_LCD3,1,0
110                     ;	;.line	172; ".\display.c"	}
111                     	RET	
112                     ; exit point of _DisplayLLL
113                     	.ENDFUNC	_DisplayLLL
114                     ;--------------------------------------------------------
115                     
116                     .globl _DisplayHHH
117                     
118                     ;--------------------------------------------------------
119                     	.FUNC _DisplayHHH:0
120                     ;--------------------------------------------------------
121                     ;	;.line	152; ".\display.c"	LCD_WriteData(&LCD0,0x00);
122                     _DisplayHHH:	;Function start
123                     	CLRF	_LCD0,0
124                     ;	;.line	153; ".\display.c"	LCD_WriteData(&LCD1,Char_H );
125                     	MVL	0x6e
126                     	MVF	_LCD1,1,0
127                     ;	;.line	154; ".\display.c"	LCD_WriteData(&LCD2,Char_H );
128                     	MVF	_LCD2,1,0
129                     ;	;.line	155; ".\display.c"	LCD_WriteData(&LCD3,Char_H ); 
130                     	MVF	_LCD3,1,0
131                     ;	;.line	157; ".\display.c"	}
132                     	RET	
133                     ; exit point of _DisplayHHH
134                     	.ENDFUNC	_DisplayHHH
135                     ;--------------------------------------------------------
136                     
137                     .globl _Reverse_Data
138                     
139                     ;--------------------------------------------------------
140                     	.FUNC _Reverse_Data:4:$C:__mullong:$C:__modslong:$C:___slong2fs:$C:___fsmul\
141                     :$C:___fs2slong\
142                     :$L:r0x116B:$L:_Reverse_Data_STK00:$L:_Reverse_Data_STK01:$L:_Reverse_Data_STK02:$L:r0x116C\
143                     :$L:r0x116D:$L:r0x116E:$L:r0x116F:$L:r0x1173:$L:r0x1172\
144                     :$L:r0x1171:$L:r0x1170:$L:r0x1177
145                     ;--------------------------------------------------------
146                     ;	;.line	133; ".\display.c"	long Reverse_Data(long number)
147 0776 [00] C48A      _Reverse_Data:	;Function start
148 0777 [10] 6689      	MVF	r0x116B,1,0
149                     ;	;.line	135; ".\display.c"	long tmp=0;
150 0778 [10] 0C88      	CLRF	r0x116C,0
151 0779 [10] 0C87      	CLRF	r0x116D,0
152 077A [10] 0C86      	CLRF	r0x116E,0
153 077B [10] 0C85      	CLRF	r0x116F,0
154                     _00152_DS_:
155                     ;	;.line	136; ".\display.c"	while(number!=0)
156 077C [10] 648C      	MVF	_Reverse_Data_STK02,0,0
157 077D [10] 2C8B      	IORF	_Reverse_Data_STK01,0,0
158 077E [10] 2C8A      	IORF	_Reverse_Data_STK00,0,0
159 077F [10] 2C89      	IORF	r0x116B,0,0
160 0780 [10] A02B      	BTSZ	_STATUS,0
161 0781 [10] 7854      	JMP	_00154_DS_
162                     ;	;.line	138; ".\display.c"	tmp=(tmp*10 + number%10);
163 0782 [10] C608      	MVF	r0x116C,0,0
164 0783 [10] F00D      	MVF	__mullong_STK06,1,0
165 0784 [11] C608      	MVF	r0x116D,0,0
166 0785 [11] F00D      	MVF	__mullong_STK05,1,0
167 0786 [12] C608      	MVF	r0x116E,0,0
168 0787 [12] F00D      	MVF	__mullong_STK04,1,0
169 0788 [13] C608      	MVF	r0x116F,0,0
170 0789 [13] F00D      	MVF	__mullong_STK03,1,0
171 078A [14] C50A      	MVL	0x0a
172                     	MVF	__mullong_STK02,1,0
173 078B [15] 0C0D      	CLRF	__mullong_STK01,0
174 078C [16] 0C0D      	CLRF	__mullong_STK00,0
175 078D [17] 0600      	MVL	0x00
176 078E [17] CB25      	CALL	__mullong
177                     	.CHKPARA __mullong 8
178 078F [10] 6684      	MVF	r0x1173,1,0
179 0790 [10] 6420      	MVF	STK00,0,0
180 0791 [10] 6683      	MVF	r0x1172,1,0
181 0792 [10] 641F      	MVF	STK01,0,0
182 0793 [10] 6682      	MVF	r0x1171,1,0
183 0794 [10] 641E      	MVF	STK02,0,0
184 0795 [10] 6681      	MVF	r0x1170,1,0
185 0796 [10] C50A      	MVL	0x0a
186                     	MVF	__modslong_STK06,1,0
187 0797 [11] 0C0D      	CLRF	__modslong_STK05,0
188 0798 [12] 0C0D      	CLRF	__modslong_STK04,0
189 0799 [13] 0C0D      	CLRF	__modslong_STK03,0
190 079A [14] C610      	MVF	_Reverse_Data_STK02,0,0
191 079B [14] F00D      	MVF	__modslong_STK02,1,0
192 079C [15] C610      	MVF	_Reverse_Data_STK01,0,0
193 079D [15] F00D      	MVF	__modslong_STK01,1,0
194 079E [16] C610      	MVF	_Reverse_Data_STK00,0,0
195 079F [16] F00D      	MVF	__modslong_STK00,1,0
196 07A0 [17] 6490      	MVF	r0x116B,0,0
197 07A1 [17] CA9C      	CALL	__modslong
198                     	.CHKPARA __modslong 8
199 07A2 [10] 6680      	MVF	r0x1177,1,0
200 07A3 [10] 641E      	MVF	STK02,0,0
201 07A4 [10] 1081      	ADDF	r0x1170,0,0
202 07A5 [10] 6688      	MVF	r0x116C,1,0
203 07A6 [10] 6482      	MVF	r0x1171,0,0
204 07A7 [10] 141F      	ADDC	STK01,0,0
205 07A8 [10] 6687      	MVF	r0x116D,1,0
206 07A9 [10] 6483      	MVF	r0x1172,0,0
207 07AA [10] 1420      	ADDC	STK00,0,0
208 07AB [10] 6686      	MVF	r0x116E,1,0
209 07AC [10] 6484      	MVF	r0x1173,0,0
210 07AD [10] 1480      	ADDC	r0x1177,0,0
211 07AE [10] 6685      	MVF	r0x116F,1,0
212                     ;	;.line	139; ".\display.c"	number=number*0.1;
213 07AF [10] C60C      	MVF	_Reverse_Data_STK02,0,0
214 07B0 [10] F00D      	MVF	___slong2fs_STK02,1,0
215 07B1 [11] C60C      	MVF	_Reverse_Data_STK01,0,0
216 07B2 [11] F00D      	MVF	___slong2fs_STK01,1,0
217 07B3 [12] C60C      	MVF	_Reverse_Data_STK00,0,0
218 07B4 [12] F00D      	MVF	___slong2fs_STK00,1,0
219 07B5 [13] 648C      	MVF	r0x116B,0,0
220 07B6 [13] CF99      	CALL	___slong2fs
221                     	.CHKPARA ___slong2fs 4
222 07B7 [10] 6684      	MVF	r0x1173,1,0
223 07B8 [10] D01E      	MVF	STK02,0,0
224 07B9 [10] F00D      	MVF	___fsmul_STK06,1,0
225 07BA [11] D01F      	MVF	STK01,0,0
226 07BB [11] F00D      	MVF	___fsmul_STK05,1,0
227 07BC [12] D020      	MVF	STK00,0,0
228 07BD [12] F00D      	MVF	___fsmul_STK04,1,0
229 07BE [13] C607      	MVF	r0x1173,0,0
230 07BF [13] F00D      	MVF	___fsmul_STK03,1,0
231 07C0 [14] C5CD      	MVL	0xcd
232                     	MVF	___fsmul_STK02,1,0
233 07C1 [15] C5CC      	MVL	0xcc
234                     	MVF	___fsmul_STK01,1,0
235 07C2 [16] C5CC      	MVF	___fsmul_STK00,1,0
236 07C3 [17] 063D      	MVL	0x3d
237 07C4 [17] CBCE      	CALL	___fsmul
238                     	.CHKPARA ___fsmul 8
239 07C5 [10] 6684      	MVF	r0x1173,1,0
240 07C6 [10] D01E      	MVF	STK02,0,0
241 07C7 [10] F00D      	MVF	___fs2slong_STK02,1,0
242 07C8 [11] D01F      	MVF	STK01,0,0
243 07C9 [11] F00D      	MVF	___fs2slong_STK01,1,0
244 07CA [12] D020      	MVF	STK00,0,0
245 07CB [12] F00D      	MVF	___fs2slong_STK00,1,0
246 07CC [13] 6487      	MVF	r0x1173,0,0
247 07CD [13] C820      	CALL	___fs2slong
248                     	.CHKPARA ___fs2slong 4
249 07CE [10] 6689      	MVF	r0x116B,1,0
250 07CF [10] 6420      	MVF	STK00,0,0
251 07D0 [10] 668A      	MVF	_Reverse_Data_STK00,1,0
252 07D1 [10] 641F      	MVF	STK01,0,0
253 07D2 [10] 668B      	MVF	_Reverse_Data_STK01,1,0
254 07D3 [10] 641E      	MVF	STK02,0,0
255 07D4 [10] 668C      	MVF	_Reverse_Data_STK02,1,0
256 07D5 [10] 7FA6      	JMP	_00152_DS_
257                     _00154_DS_:
258                     ;	;.line	141; ".\display.c"	if(number<0) return (-tmp);
259 07D6 [10] BE89      	BTSS	r0x116B,7
260 07D7 [10] 780E      	JMP	_00156_DS_
261 07D8 [10] 2488      	COMF	r0x116C,0,0
262 07D9 [10] 661E      	MVF	STK02,1,0
263 07DA [10] 2487      	COMF	r0x116D,0,0
264 07DB [10] 661F      	MVF	STK01,1,0
265 07DC [10] 2486      	COMF	r0x116E,0,0
266 07DD [10] 6620      	MVF	STK00,1,0
267 07DE [10] 2485      	COMF	r0x116F,0,0
268 07DF [10] 6689      	MVF	r0x116B,1,0
269 07E0 [10] 3A1E      	INF	STK02,1,0
270 07E1 [10] 0600      	MVL	0x00
271 07E2 [10] 161F      	ADDC	STK01,1,0
272 07E3 [10] 1620      	ADDC	STK00,1,0
273 07E4 [10] 1489      	ADDC	r0x116B,0,0
274 07E5 [10] 7807      	JMP	_00158_DS_
275                     _00156_DS_:
276                     ;	;.line	142; ".\display.c"	else return tmp;
277 07E6 [10] C608      	MVF	r0x116C,0,0
278 07E7 [10] F01E      	MVF	STK02,1,0
279 07E8 [10] C607      	MVF	r0x116D,0,0
280 07E9 [10] F01F      	MVF	STK01,1,0
281 07EA [10] C606      	MVF	r0x116E,0,0
282 07EB [10] F020      	MVF	STK00,1,0
283 07EC [10] 6485      	MVF	r0x116F,0,0
284                     _00158_DS_:
285                     ;	;.line	143; ".\display.c"	}
286 07ED [10] C4F3      	RET	
287                     ; exit point of _Reverse_Data
288                     	.ENDFUNC	_Reverse_Data
289                     ;--------------------------------------------------------
290                     
291                     .globl _Delay
292                     
293                     ;--------------------------------------------------------
294                     	.FUNC _Delay:2:$L:r0x1166:$L:_Delay_STK00
295                     ;--------------------------------------------------------
296                     ;	;.line	122; ".\display.c"	void Delay(unsigned int ms)
297 0174 [00] C481      _Delay:	;Function start
298 0175 [01] 6680      	MVF	r0x1166,1,0
299                     _00145_DS_:
300                     ;	;.line	124; ".\display.c"	for(;ms>0;ms--)
301 0176 [01] 6481      	MVF	_Delay_STK00,0,0
302 0177 [01] 2C80      	IORF	r0x1166,0,0
303 0178 [01] A02B      	BTSZ	_STATUS,0
304 0179 [01] 7805      	JMP	_00147_DS_
305                     ;	;.line	125; ".\display.c"	 ..asm
306 017A [01] 0000      	NOP
307                     ;	;.line	124; ".\display.c"	for(;ms>0;ms--)
308 017B [01] 3281      	DCF	_Delay_STK00,1,0
309 017C [01] 4081      	INSUZ	_Delay_STK00,0,0
310 017D [01] 3280      	DCF	r0x1166,1,0
311 017E [01] 7FF7      	JMP	_00145_DS_
312                     _00147_DS_:
313                     ;	;.line	126; ".\display.c"	}
314 017F [01] C4FE      	RET	
315                     ; exit point of _Delay
316                     	.ENDFUNC	_Delay
317                     ;--------------------------------------------------------
318                     
319                     .globl _DisplayUnit
320                     
321                     ;--------------------------------------------------------
322                     	.FUNC _DisplayUnit:0
323                     ;--------------------------------------------------------
324                     ;	;.line	114; ".\display.c"	LCD_WriteData(&LCD0,0x00);
325                     _DisplayUnit:	;Function start
326 00C7 [00] 0C5F      	CLRF	_LCD0,0
327                     ;	;.line	115; ".\display.c"	LCD_WriteData(&LCD1,Char_I);
328 00C8 [00] 0602      	MVL	0x02
329 00C9 [00] 6660      	MVF	_LCD1,1,0
330                     ;	;.line	116; ".\display.c"	LCD_WriteData(&LCD2,Char_N);
331 00CA [00] 0626      	MVL	0x26
332 00CB [00] 6661      	MVF	_LCD2,1,0
333                     ;	;.line	117; ".\display.c"	LCD_WriteData(&LCD3,Char_CAP_U); 
334 00CC [00] 067A      	MVL	0x7a
335 00CD [00] 6662      	MVF	_LCD3,1,0
336                     ;	;.line	118; ".\display.c"	}
337 00CE [00] 000A      	RET	
338                     ; exit point of _DisplayUnit
339                     	.ENDFUNC	_DisplayUnit
340                     ;--------------------------------------------------------
341                     
342                     .globl _Display2Er
343                     
344                     ;--------------------------------------------------------
345                     	.FUNC _Display2Er:0
346                     ;--------------------------------------------------------
347                     ;	;.line	98; ".\display.c"	LCD_WriteData(&LCD0,0x00);
348                     _Display2Er:	;Function start
349 00CF [00] 0C5F      	CLRF	_LCD0,0
350                     ;	;.line	99; ".\display.c"	LCD_WriteData(&LCD3,Char_2);
351 00D0 [00] 06BC      	MVL	0xbc
352 00D1 [00] 6662      	MVF	_LCD3,1,0
353                     ;	;.line	100; ".\display.c"	LCD_WriteData(&LCD2,Char_E);
354 00D2 [00] 06F4      	MVL	0xf4
355 00D3 [00] 6661      	MVF	_LCD2,1,0
356                     ;	;.line	101; ".\display.c"	LCD_WriteData(&LCD1,Char_R);   
357 00D4 [00] 0624      	MVL	0x24
358 00D5 [00] 6660      	MVF	_LCD1,1,0
359                     ;	;.line	104; ".\display.c"	}
360 00D6 [00] 000A      	RET	
361                     ; exit point of _Display2Er
362                     	.ENDFUNC	_Display2Er
363                     ;--------------------------------------------------------
364                     
365                     .globl _DisplayHex
366                     
367                     ;--------------------------------------------------------
368                     	.FUNC _DisplayHex:2
369                     ;--------------------------------------------------------
370                     ;	;.line	88; ".\display.c"	}
371                     _DisplayHex:	;Function start
372                     	RET	
373                     ; exit point of _DisplayHex
374                     	.ENDFUNC	_DisplayHex
375                     ;--------------------------------------------------------
376                     
377                     .globl _DisplayNum
378                     
379                     ;--------------------------------------------------------
380                     	.FUNC _DisplayNum:4:$C:__modslong:$C:__g2ptrget1:$C:__g2ptrput1:$C:__divslong\
381                     :$L:r0x1146:$L:_DisplayNum_STK00:$L:_DisplayNum_STK01:$L:_DisplayNum_STK02:$L:r0x1147\
382                     :$L:r0x1148:$L:r0x1149:$L:r0x114A
383                     ;--------------------------------------------------------
384                     ;	;.line	61; ".\display.c"	void DisplayNum(long Num)
385 0829 [00] C485      _DisplayNum:	;Function start
386 082A [05] 6684      	MVF	r0x1146,1,0
387                     ;	;.line	66; ".\display.c"	LCDAddr=&LCD3;
388 082B [05] 0662      	MVL	(_LCD3 + 0)
389 082C [05] 6683      	MVF	r0x1147,1,0
390 082D [05] 0600      	MVL	high (_LCD3 + 0)
391 082E [05] 6682      	MVF	r0x1148,1,0
392                     ;	;.line	67; ".\display.c"	for(count=1;count<4;count++)
393 082F [05] 0603      	MVL	0x03
394 0830 [05] 6681      	MVF	r0x1149,1,0
395                     _00125_DS_:
396                     ;	;.line	69; ".\display.c"	LCDData=seg[Num%10];
397 0831 [05] C50A      	MVL	0x0a
398                     	MVF	__modslong_STK06,1,0
399 0832 [06] 0C0D      	CLRF	__modslong_STK05,0
400 0833 [07] 0C0D      	CLRF	__modslong_STK04,0
401 0834 [08] 0C0D      	CLRF	__modslong_STK03,0
402 0835 [09] C60B      	MVF	_DisplayNum_STK02,0,0
403 0836 [09] F00D      	MVF	__modslong_STK02,1,0
404 0837 [10] C60B      	MVF	_DisplayNum_STK01,0,0
405 0838 [10] F00D      	MVF	__modslong_STK01,1,0
406 0839 [11] C60B      	MVF	_DisplayNum_STK00,0,0
407 083A [11] F00D      	MVF	__modslong_STK00,1,0
408 083B [12] 648B      	MVF	r0x1146,0,0
409 083C [12] CA01      	CALL	__modslong
410 083D [05] 641E      	MVF	STK02,0,0
411 083E [05] 046C      	ADDL	(_seg + 0)
412 083F [05] 6680      	MVF	r0x114A,1,0
413 0840 [05] 061A      	MVL	high (_seg + 0)
414 0841 [05] 141F      	ADDC	STK01,0,0
415 0842 [05] C600 F00D 	MVSF	r0x114A,__g2ptrget1_STK00
416 0844 [06] 0280      	IORL	0x80
417 0845 [06] CAAC      	CALL	__g2ptrget1
418                     ;	;.line	70; ".\display.c"	LCD_WriteData(LCDAddr,LCDData);
419 0846 [05] 660D      	MVF	__g2ptrput1_STK01,1,0
420 0847 [06] C604      	MVF	r0x1147,0,0
421 0848 [06] F00D      	MVF	__g2ptrput1_STK00,1,0
422 0849 [07] 6484      	MVF	r0x1148,0,0
423 084A [07] CAB8      	CALL	__g2ptrput1
424                     ;	;.line	71; ".\display.c"	Num=Num/10 ;
425 084B [05] C50A      	MVL	0x0a
426                     	MVF	__divslong_STK06,1,0
427 084C [06] 0C0D      	CLRF	__divslong_STK05,0
428 084D [07] 0C0D      	CLRF	__divslong_STK04,0
429 084E [08] 0C0D      	CLRF	__divslong_STK03,0
430 084F [09] C60B      	MVF	_DisplayNum_STK02,0,0
431 0850 [09] F00D      	MVF	__divslong_STK02,1,0
432 0851 [10] C60B      	MVF	_DisplayNum_STK01,0,0
433 0852 [10] F00D      	MVF	__divslong_STK01,1,0
434 0853 [11] C60B      	MVF	_DisplayNum_STK00,0,0
435 0854 [11] F00D      	MVF	__divslong_STK00,1,0
436 0855 [12] 648B      	MVF	r0x1146,0,0
437 0856 [12] CA22      	CALL	__divslong
438                     	.CHKPARA __divslong 8
439 0857 [05] 6684      	MVF	r0x1146,1,0
440 0858 [05] 6420      	MVF	STK00,0,0
441 0859 [05] 6685      	MVF	_DisplayNum_STK00,1,0
442 085A [05] 641F      	MVF	STK01,0,0
443 085B [05] 6686      	MVF	_DisplayNum_STK01,1,0
444 085C [05] 641E      	MVF	STK02,0,0
445 085D [05] 6687      	MVF	_DisplayNum_STK02,1,0
446                     ;	;.line	72; ".\display.c"	LCDAddr--;
447 085E [05] 3283      	DCF	r0x1147,1,0
448 085F [05] 4083      	INSUZ	r0x1147,0,0
449 0860 [05] 3282      	DCF	r0x1148,1,0
450 0861 [05] 3681      	DCSZ	r0x1149,1,0
451                     ;	;.line	67; ".\display.c"	for(count=1;count<4;count++)
452 0862 [05] 7FCE 0011 	JMP	_00125_DS_
453                     ;	;.line	75; ".\display.c"	if(adS.Pressure_sign==1)
454 0864 [05] BD78      	BTSS	(_adS+6),6
455 0865 [05] 7803      	JMP	_00121_DS_
456                     ;	;.line	76; ".\display.c"	LCD_WriteData(&LCD0,0X08);
457 0866 [05] 0608      	MVL	0x08
458 0867 [05] 665F      	MVF	_LCD0,1,0
459 0868 [05] 7801      	JMP	_00126_DS_
460                     _00121_DS_:
461                     ;	;.line	78; ".\display.c"	LCD_WriteData(&LCD0,0);
462 0869 [05] 0C5F      	CLRF	_LCD0,0
463                     _00126_DS_:
464                     ;	;.line	80; ".\display.c"	}
465 086A [05] C4F8      	RET	
466                     ; exit point of _DisplayNum
467                     	.ENDFUNC	_DisplayNum
468                     ;--------------------------------------------------------
469                     
470                     .globl _DisplayHycon
471                     
472                     ;--------------------------------------------------------
473                     	.FUNC _DisplayHycon:0
474                     ;--------------------------------------------------------
475                     ;	;.line	43; ".\display.c"	LCD_WriteData(&LCD0,0x00);
476                     _DisplayHycon:	;Function start
477                     	CLRF	_LCD0,0
478                     ;	;.line	44; ".\display.c"	LCD_WriteData(&LCD1,Char_L);
479                     	MVL	0x70
480                     	MVF	_LCD1,1,0
481                     ;	;.line	45; ".\display.c"	LCD_WriteData(&LCD2,Char_L);
482                     	MVF	_LCD2,1,0
483                     ;	;.line	46; ".\display.c"	LCD_WriteData(&LCD3,Char_L);   /*HY17P52 com3 */
484                     	MVF	_LCD3,1,0
485                     ;	;.line	47; ".\display.c"	LCD_WriteData(&LCD4,Char_L);
486                     	MVF	_LCD4,1,0
487                     ;	;.line	48; ".\display.c"	LCD_WriteData(&LCD5,Char_L);
488                     	MVF	_LCD5,1,0
489                     ;	;.line	49; ".\display.c"	LCD_WriteData(&LCD6,0x00);
490                     	CLRF	_LCD6,0
491                     ;	;.line	50; ".\display.c"	}
492                     	RET	
493                     ; exit point of _DisplayHycon
494                     	.ENDFUNC	_DisplayHycon
495                     ;--------------------------------------------------------
496                     
497                     .globl _ClearLCD
498                     
499                     ;--------------------------------------------------------
500                     	.FUNC _ClearLCD:0:$L:r0x1140
501                     ;--------------------------------------------------------
502                     _ClearLCD:	;Function start
503                     	LDPR	(_LCD0 + 0),0
504                     ;	;.line	30; ".\display.c"	for(count=6;count>0;count--)
505                     	MVL	0x06
506                     	MVF	r0x1140,1,0
507                     _00110_DS_:
508                     ;	;.line	31; ".\display.c"	POINC0=0;
509                     	CLRF	_POINC0,0
510                     ;	;.line	30; ".\display.c"	for(count=6;count>0;count--)
511                     	DCSZ	r0x1140,1,0
512                     	JMP	_00110_DS_
513                     ;	;.line	32; ".\display.c"	}
514                     	RET	
515                     ; exit point of _ClearLCD
516                     	.ENDFUNC	_ClearLCD
517                     ;--------------------------------------------------------
518                     
519                     .globl _GPIO_Iint
520                     
521                     ;--------------------------------------------------------
522                     	.FUNC _GPIO_Iint:0
523                     ;--------------------------------------------------------
524                     ;	;.line	14; ".\display.c"	GPIO_PT15_OUTUT();  // SETTING PT4.4 OUTPUT
525                     _GPIO_Iint:	;Function start
526 00D7 [00] 06DF      	MVL	0xdf
527 00D8 [00] 2848      	ANDF	_TRISC1,0,0
528 00D9 [00] 0220      	IORL	0x20
529 00DA [00] 6648      	MVF	_TRISC1,1,0
530                     ;	;.line	15; ".\display.c"	GPIO_PT16_OUTUT();  // SETTING PT4.3 OUTPUT
531 00DB [00] 06BF      	MVL	0xbf
532 00DC [00] 2848      	ANDF	_TRISC1,0,0
533 00DD [00] 0240      	IORL	0x40
534 00DE [00] 6648      	MVF	_TRISC1,1,0
535                     ;	;.line	17; ".\display.c"	GPIO_PT10_INPUT();
536 00DF [00] 8048      	BCF	_TRISC1,0
537                     ;	;.line	18; ".\display.c"	}
538 00E0 [00] 000A      	RET	
539                     ; exit point of _GPIO_Iint
540                     	.ENDFUNC	_GPIO_Iint
541                     ;--------------------------------------------------------
542                     
543                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
544                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
545                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
546                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
547                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
548                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
549                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
550                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
551                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
552                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
553                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
554                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
555                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
556                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
557                     	;--cdb--S:G$_modslong$0$0({2}DF,SL:SL),C,0,0
558                     	;--cdb--S:G$_divslong$0$0({2}DF,SL:SL),C,0,0
559                     	;--cdb--S:G$_mullong$0$0({2}DF,SL:SL),C,0,0
560                     	;--cdb--S:G$__slong2fs$0$0({2}DF,SF:S),C,0,0
561                     	;--cdb--S:G$__fsmul$0$0({2}DF,SF:S),C,0,0
562                     	;--cdb--S:G$__fs2slong$0$0({2}DF,SL:SL),C,0,0
563                     	;--cdb--S:G$FSR0$0$0({2}DD,SC:U),E,0,0
564                     	;--cdb--S:G$FSR1$0$0({2}DD,SC:U),E,0,0
565                     	;--cdb--S:G$FSR2$0$0({2}DD,SC:U),E,0,0
566                     	;--cdb--S:G$ADCR$0$0({4}SL:SL),E,0,0
567                     	;--cdb--S:G$adS$0$0({14}ST_adc_works_:S),E,0,0
568                     	;--cdb--S:G$seg$0$0({29}DA29d,SC:U),D,0,0
569                     	;--cdb--S:G$_SWTGTID$0$0({1}SC:U),I,0,0
570                     	;--cdb--S:G$INDF0$0$0({1}SC:U),I,0,0
571                     	;--cdb--S:G$POINC0$0$0({1}SC:U),I,0,0
572                     	;--cdb--S:G$PODEC0$0$0({1}SC:U),I,0,0
573                     	;--cdb--S:G$PRINC0$0$0({1}SC:U),I,0,0
574                     	;--cdb--S:G$PLUSW0$0$0({1}SC:U),I,0,0
575                     	;--cdb--S:G$INDF1$0$0({1}SC:U),I,0,0
576                     	;--cdb--S:G$POINC1$0$0({1}SC:U),I,0,0
577                     	;--cdb--S:G$PODEC1$0$0({1}SC:U),I,0,0
578                     	;--cdb--S:G$PRINC1$0$0({1}SC:U),I,0,0
579                     	;--cdb--S:G$PLUSW1$0$0({1}SC:U),I,0,0
580                     	;--cdb--S:G$INDF2$0$0({1}SC:U),I,0,0
581                     	;--cdb--S:G$POINC2$0$0({1}SC:U),I,0,0
582                     	;--cdb--S:G$PODEC2$0$0({1}SC:U),I,0,0
583                     	;--cdb--S:G$PRINC2$0$0({1}SC:U),I,0,0
584                     	;--cdb--S:G$PLUSW2$0$0({1}SC:U),I,0,0
585                     	;--cdb--S:G$FSR0H$0$0({1}SC:U),I,0,0
586                     	;--cdb--S:G$FSR0L$0$0({1}SC:U),I,0,0
587                     	;--cdb--S:G$FSR1H$0$0({1}SC:U),I,0,0
588                     	;--cdb--S:G$FSR1L$0$0({1}SC:U),I,0,0
589                     	;--cdb--S:G$FSR2H$0$0({1}SC:U),I,0,0
590                     	;--cdb--S:G$FSR2L$0$0({1}SC:U),I,0,0
591                     	;--cdb--S:G$TOSH$0$0({1}SC:U),I,0,0
592                     	;--cdb--S:G$TOSL$0$0({1}SC:U),I,0,0
593                     	;--cdb--S:G$SKCN$0$0({1}SC:U),I,0,0
594                     	;--cdb--S:G$PCLATH$0$0({1}SC:U),I,0,0
595                     	;--cdb--S:G$PCLATL$0$0({1}SC:U),I,0,0
596                     	;--cdb--S:G$TBLPTRH$0$0({1}SC:U),I,0,0
597                     	;--cdb--S:G$TBLPTRL$0$0({1}SC:U),I,0,0
598                     	;--cdb--S:G$TBLDH$0$0({1}SC:U),I,0,0
599                     	;--cdb--S:G$TBLDL$0$0({1}SC:U),I,0,0
600                     	;--cdb--S:G$PRODH$0$0({1}SC:U),I,0,0
601                     	;--cdb--S:G$PRODL$0$0({1}SC:U),I,0,0
602                     	;--cdb--S:G$INTE0$0$0({1}SC:U),I,0,0
603                     	;--cdb--S:G$INTE1$0$0({1}SC:U),I,0,0
604                     	;--cdb--S:G$INTF0$0$0({1}SC:U),I,0,0
605                     	;--cdb--S:G$INTF1$0$0({1}SC:U),I,0,0
606                     	;--cdb--S:G$WREG$0$0({1}SC:U),I,0,0
607                     	;--cdb--S:G$BSRCN$0$0({1}SC:U),I,0,0
608                     	;--cdb--S:G$STATUS$0$0({1}SC:U),I,0,0
609                     	;--cdb--S:G$MSTAT$0$0({1}SC:U),I,0,0
610                     	;--cdb--S:G$PSTAT$0$0({1}SC:U),I,0,0
611                     	;--cdb--S:G$BIECN$0$0({1}SC:U),I,0,0
612                     	;--cdb--S:G$BIEARH$0$0({1}SC:U),I,0,0
613                     	;--cdb--S:G$BIEARL$0$0({1}SC:U),I,0,0
614                     	;--cdb--S:G$BIEDRH$0$0({1}SC:U),I,0,0
615                     	;--cdb--S:G$BIEDRL$0$0({1}SC:U),I,0,0
616                     	;--cdb--S:G$PWRCN$0$0({1}SC:U),I,0,0
617                     	;--cdb--S:G$OSCCN0$0$0({1}SC:U),I,0,0
618                     	;--cdb--S:G$OSCCN1$0$0({1}SC:U),I,0,0
619                     	;--cdb--S:G$OSCCN2$0$0({1}SC:U),I,0,0
620                     	;--cdb--S:G$CSFCN0$0$0({1}SC:U),I,0,0
621                     	;--cdb--S:G$CSFCN1$0$0({1}SC:U),I,0,0
622                     	;--cdb--S:G$WDTCN$0$0({1}SC:U),I,0,0
623                     	;--cdb--S:G$AD1H$0$0({1}SC:U),I,0,0
624                     	;--cdb--S:G$AD1M$0$0({1}SC:U),I,0,0
625                     	;--cdb--S:G$AD1L$0$0({1}SC:U),I,0,0
626                     	;--cdb--S:G$AD1CN0$0$0({1}SC:U),I,0,0
627                     	;--cdb--S:G$AD1CN1$0$0({1}SC:U),I,0,0
628                     	;--cdb--S:G$AD1CN2$0$0({1}SC:U),I,0,0
629                     	;--cdb--S:G$AD1CN3$0$0({1}SC:U),I,0,0
630                     	;--cdb--S:G$AD1CN4$0$0({1}SC:U),I,0,0
631                     	;--cdb--S:G$AD1CN5$0$0({1}SC:U),I,0,0
632                     	;--cdb--S:G$LVDCN$0$0({1}SC:U),I,0,0
633                     	;--cdb--S:G$TMA1CN$0$0({1}SC:U),I,0,0
634                     	;--cdb--S:G$TMA1R$0$0({1}SC:U),I,0,0
635                     	;--cdb--S:G$TMA1C$0$0({1}SC:U),I,0,0
636                     	;--cdb--S:G$PT1$0$0({1}SC:U),I,0,0
637                     	;--cdb--S:G$TRISC1$0$0({1}SC:U),I,0,0
638                     	;--cdb--S:G$PT1DA$0$0({1}SC:U),I,0,0
639                     	;--cdb--S:G$PT1PU$0$0({1}SC:U),I,0,0
640                     	;--cdb--S:G$PT1M1$0$0({1}SC:U),I,0,0
641                     	;--cdb--S:G$PT2$0$0({1}SC:U),I,0,0
642                     	;--cdb--S:G$TRISC2$0$0({1}SC:U),I,0,0
643                     	;--cdb--S:G$PT2DA$0$0({1}SC:U),I,0,0
644                     	;--cdb--S:G$PT2PU$0$0({1}SC:U),I,0,0
645                     	;--cdb--S:G$PT8$0$0({1}SC:U),I,0,0
646                     	;--cdb--S:G$TRISC8$0$0({1}SC:U),I,0,0
647                     	;--cdb--S:G$PT8PU$0$0({1}SC:U),I,0,0
648                     	;--cdb--S:G$UR0CN$0$0({1}SC:U),I,0,0
649                     	;--cdb--S:G$UR0STA$0$0({1}SC:U),I,0,0
650                     	;--cdb--S:G$BA0CN$0$0({1}SC:U),I,0,0
651                     	;--cdb--S:G$BG0RH$0$0({1}SC:U),I,0,0
652                     	;--cdb--S:G$BG0RL$0$0({1}SC:U),I,0,0
653                     	;--cdb--S:G$TX0R$0$0({1}SC:U),I,0,0
654                     	;--cdb--S:G$RC0REG$0$0({1}SC:U),I,0,0
655                     	;--cdb--S:G$LCDCN1$0$0({1}SC:U),I,0,0
656                     	;--cdb--S:G$LCDCN2$0$0({1}SC:U),I,0,0
657                     	;--cdb--S:G$LCDCN3$0$0({1}SC:U),I,0,0
658                     	;--cdb--S:G$LCDCN4$0$0({1}SC:U),I,0,0
659                     	;--cdb--S:G$LCD0$0$0({1}SC:U),I,0,0
660                     	;--cdb--S:G$LCD1$0$0({1}SC:U),I,0,0
661                     	;--cdb--S:G$LCD2$0$0({1}SC:U),I,0,0
662                     	;--cdb--S:G$LCD3$0$0({1}SC:U),I,0,0
663                     	;--cdb--S:G$LCD4$0$0({1}SC:U),I,0,0
664                     	;--cdb--S:G$LCD5$0$0({1}SC:U),I,0,0
665                     	;--cdb--S:G$LCD6$0$0({1}SC:U),I,0,0
666                     	;--cdb--S:G$Filter$0$0({1}SC:U),I,0,0
667                     	;--cdb--S:G$ADCRH$0$0({1}SC:U),I,0,0
668                     	;--cdb--S:G$ADCRM$0$0({1}SC:U),I,0,0
669                     	;--cdb--S:G$ADCRL$0$0({1}SC:U),I,0,0
670                     	;--cdb--S:Ldisplay.ClearLCD._ClearLCD_count_65536_18$count$10000$18({1}SC:U),R,0,0,[r0x1140]
671                     	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_Num_65536_22$Num$10000$22({4}SL:SL),R,0,0,[_DisplayNum_STK02,_DisplayNum_STK01,_DisplayNum_STK00,r0x1146]
672                     	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_count_65536_23$count$10000$23({1}SC:U),R,0,0,[r0x1149]
673                     	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_MINUS_65536_23$MINUS$10000$23({1}SC:U),E,0,0
674                     	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_LCDAddr_65536_23$LCDAddr$10000$23({2}DT,SC:U),R,0,0,[]
675                     	;--cdb--S:Ldisplay.DisplayNum._DisplayNum_LCDData_65536_23$LCDData$10000$23({1}SC:U),R,0,0,[r0x114E]
676                     	;--cdb--S:Ldisplay.DisplayHex._DisplayHex_Num_65536_26$Num$10000$26({2}SI:U),R,0,0,[]
677                     	;--cdb--S:Ldisplay.Delay._Delay_ms_65536_33$ms$10000$33({2}SI:U),R,0,0,[_Delay_STK00,r0x1166]
678                     	;--cdb--S:Ldisplay.Reverse_Data._Reverse_Data_number_65536_36$number$10000$36({4}SL:SL),R,0,0,[_Reverse_Data_STK02,_Reverse_Data_STK01,_Reverse_Data_STK00,r0x116B]
679                     	;--cdb--S:Ldisplay.Reverse_Data._Reverse_Data_tmp_65536_37$tmp$10000$37({4}SL:SL),R,0,0,[r0x116C,r0x116D,r0x116E,r0x116F]
680                     	;--cdb--S:G$GPIO_Iint$0$0({2}DF,SV:S),C,0,0
681                     	;--cdb--S:G$ClearLCD$0$0({2}DF,SV:S),C,0,0
682                     	;--cdb--S:G$DisplayHycon$0$0({2}DF,SV:S),C,0,0
683                     	;--cdb--S:G$DisplayNum$0$0({2}DF,SV:S),C,0,0
684                     	;--cdb--S:G$DisplayHex$0$0({2}DF,SV:S),C,0,0
685                     	;--cdb--S:G$Display2Er$0$0({2}DF,SV:S),C,0,0
686                     	;--cdb--S:G$DisplayUnit$0$0({2}DF,SV:S),C,0,0
687                     	;--cdb--S:G$Delay$0$0({2}DF,SV:S),C,0,0
688                     	;--cdb--S:G$Reverse_Data$0$0({2}DF,SL:SL),C,0,0
689                     	;--cdb--S:G$DisplayHHH$0$0({2}DF,SV:S),C,0,0
690                     	;--cdb--S:G$DisplayLLL$0$0({2}DF,SV:S),C,0,0
691                     	;--cdb--S:G$DisplayBatteryCapacityFull$0$0({2}DF,SV:S),C,0,0
692                     	;--cdb--S:G$DisplayBatteryCapacityHalf$0$0({2}DF,SV:S),C,0,0
693                     	;--cdb--S:G$DispalyBatteryCapacityLow$0$0({2}DF,SV:S),C,0,0
694                     	;--cdb--S:G$_STATUS$0$0({0}:U),Z,0,0
695                     	;--cdb--S:G$_POINC0$0$0({0}:U),Z,0,0
696                     ;--------------------------------------------------------
697                     ; external declarations
698                     ;--------------------------------------------------------
699                     	.globl	__modslong
700                     	.globl	__divslong
701                     	.globl	__mullong
702                     	.globl	___slong2fs
703                     	.globl	___fsmul
704                     	.globl	___fs2slong
705                     	.globl	_FSR0
706                     	.globl	_FSR1
707                     	.globl	_FSR2
708                     	.globl	_ADCR
709                     	.globl	__g2ptrget1
710                     	.globl	__g2ptrput1
711                     
712                     	.globl WSAVE
713                     	.globl STK07
714                     	.globl STK07_SAVE
715                     	.globl STK06
716                     	.globl STK06_SAVE
717                     	.globl STK05
718                     	.globl STK05_SAVE
719                     	.globl STK04
720                     	.globl STK04_SAVE
721                     	.globl STK03
722                     	.globl STK03_SAVE
723                     	.globl STK02
724                     	.globl STK02_SAVE
725                     	.globl STK01
726                     	.globl STK01_SAVE
727                     	.globl STK00
728                     	.globl STK00_SAVE
729                     ;--------------------------------------------------------
730                     ; global -1 declarations
731                     ;--------------------------------------------------------
732                     	.globl	_Reverse_Data
733                     	.globl	_Delay
734                     	.globl	_DisplayHex
735                     	.globl	_DisplayNum
736                     	.globl	_adS
737                     	.globl	_seg
738                     
739                     	.globl	_memcpy
740                     ;--------------------------------------------------------
741                     ; global -2 definitions
742                     ;--------------------------------------------------------
743                     	.area DSEG(DATA)
744 0172 -- -- -- -- -- -- -- -- -- -- -- -- -- -- _adS:	.ds	14
745                     
746                     	.area DSEG(DATA)
747                     __SWTGTID	.equ	0xA43354DA
748                     
749                     	.area DSEG(DATA)
750                     _INDF0	.equ	0x0
751                     
752                     	.area DSEG(DATA)
753                     _POINC0	.equ	0x1
754                     
755                     	.area DSEG(DATA)
756                     _PODEC0	.equ	0x2
757                     
758                     	.area DSEG(DATA)
759                     _PRINC0	.equ	0x3
760                     
761                     	.area DSEG(DATA)
762                     _PLUSW0	.equ	0x4
763                     
764                     	.area DSEG(DATA)
765                     _INDF1	.equ	0x5
766                     
767                     	.area DSEG(DATA)
768                     _POINC1	.equ	0x6
769                     
770                     	.area DSEG(DATA)
771                     _PODEC1	.equ	0x7
772                     
773                     	.area DSEG(DATA)
774                     _PRINC1	.equ	0x8
775                     
776                     	.area DSEG(DATA)
777                     _PLUSW1	.equ	0x9
778                     
779                     	.area DSEG(DATA)
780                     _INDF2	.equ	0xA
781                     
782                     	.area DSEG(DATA)
783                     _POINC2	.equ	0xB
784                     
785                     	.area DSEG(DATA)
786                     _PODEC2	.equ	0xC
787                     
788                     	.area DSEG(DATA)
789                     _PRINC2	.equ	0xD
790                     
791                     	.area DSEG(DATA)
792                     _PLUSW2	.equ	0xE
793                     
794                     	.area DSEG(DATA)
795                     _FSR0H	.equ	0xF
796                     
797                     	.area DSEG(DATA)
798                     _FSR0L	.equ	0x10
799                     
800                     	.area DSEG(DATA)
801                     _FSR1H	.equ	0x11
802                     
803                     	.area DSEG(DATA)
804                     _FSR1L	.equ	0x12
805                     
806                     	.area DSEG(DATA)
807                     _FSR2H	.equ	0x13
808                     
809                     	.area DSEG(DATA)
810                     _FSR2L	.equ	0x14
811                     
812                     	.area DSEG(DATA)
813                     _TOSH	.equ	0x16
814                     
815                     	.area DSEG(DATA)
816                     _TOSL	.equ	0x17
817                     
818                     	.area DSEG(DATA)
819                     _SKCN	.equ	0x18
820                     
821                     	.area DSEG(DATA)
822                     _PCLATH	.equ	0x1A
823                     
824                     	.area DSEG(DATA)
825                     _PCLATL	.equ	0x1B
826                     
827                     	.area DSEG(DATA)
828                     _TBLPTRH	.equ	0x1D
829                     
830                     	.area DSEG(DATA)
831                     _TBLPTRL	.equ	0x1E
832                     
833                     	.area DSEG(DATA)
834                     _TBLDH	.equ	0x1F
835                     
836                     	.area DSEG(DATA)
837                     _TBLDL	.equ	0x20
838                     
839                     	.area DSEG(DATA)
840                     _PRODH	.equ	0x21
841                     
842                     	.area DSEG(DATA)
843                     _PRODL	.equ	0x22
844                     
845                     	.area DSEG(DATA)
846                     _INTE0	.equ	0x23
847                     
848                     	.area DSEG(DATA)
849                     _INTE1	.equ	0x24
850                     
851                     	.area DSEG(DATA)
852                     _INTF0	.equ	0x26
853                     
854                     	.area DSEG(DATA)
855                     _INTF1	.equ	0x27
856                     
857                     	.area DSEG(DATA)
858                     _WREG	.equ	0x29
859                     
860                     	.area DSEG(DATA)
861                     _BSRCN	.equ	0x2A
862                     
863                     	.area DSEG(DATA)
864                     _STATUS	.equ	0x2B
865                     
866                     	.area DSEG(DATA)
867                     _MSTAT	.equ	0x2B
868                     
869                     	.area DSEG(DATA)
870                     _PSTAT	.equ	0x2C
871                     
872                     	.area DSEG(DATA)
873                     _BIECN	.equ	0x2E
874                     
875                     	.area DSEG(DATA)
876                     _BIEARH	.equ	0x2F
877                     
878                     	.area DSEG(DATA)
879                     _BIEARL	.equ	0x30
880                     
881                     	.area DSEG(DATA)
882                     _BIEDRH	.equ	0x31
883                     
884                     	.area DSEG(DATA)
885                     _BIEDRL	.equ	0x32
886                     
887                     	.area DSEG(DATA)
888                     _PWRCN	.equ	0x33
889                     
890                     	.area DSEG(DATA)
891                     _OSCCN0	.equ	0x34
892                     
893                     	.area DSEG(DATA)
894                     _OSCCN1	.equ	0x35
895                     
896                     	.area DSEG(DATA)
897                     _OSCCN2	.equ	0x36
898                     
899                     	.area DSEG(DATA)
900                     _CSFCN0	.equ	0x37
901                     
902                     	.area DSEG(DATA)
903                     _CSFCN1	.equ	0x38
904                     
905                     	.area DSEG(DATA)
906                     _WDTCN	.equ	0x39
907                     
908                     	.area DSEG(DATA)
909                     _AD1H	.equ	0x3A
910                     
911                     	.area DSEG(DATA)
912                     _AD1M	.equ	0x3B
913                     
914                     	.area DSEG(DATA)
915                     _AD1L	.equ	0x3C
916                     
917                     	.area DSEG(DATA)
918                     _AD1CN0	.equ	0x3D
919                     
920                     	.area DSEG(DATA)
921                     _AD1CN1	.equ	0x3E
922                     
923                     	.area DSEG(DATA)
924                     _AD1CN2	.equ	0x3F
925                     
926                     	.area DSEG(DATA)
927                     _AD1CN3	.equ	0x40
928                     
929                     	.area DSEG(DATA)
930                     _AD1CN4	.equ	0x41
931                     
932                     	.area DSEG(DATA)
933                     _AD1CN5	.equ	0x42
934                     
935                     	.area DSEG(DATA)
936                     _LVDCN	.equ	0x43
937                     
938                     	.area DSEG(DATA)
939                     _TMA1CN	.equ	0x44
940                     
941                     	.area DSEG(DATA)
942                     _TMA1R	.equ	0x45
943                     
944                     	.area DSEG(DATA)
945                     _TMA1C	.equ	0x46
946                     
947                     	.area DSEG(DATA)
948                     _PT1	.equ	0x47
949                     
950                     	.area DSEG(DATA)
951                     _TRISC1	.equ	0x48
952                     
953                     	.area DSEG(DATA)
954                     _PT1DA	.equ	0x49
955                     
956                     	.area DSEG(DATA)
957                     _PT1PU	.equ	0x4A
958                     
959                     	.area DSEG(DATA)
960                     _PT1M1	.equ	0x4B
961                     
962                     	.area DSEG(DATA)
963                     _PT2	.equ	0x4C
964                     
965                     	.area DSEG(DATA)
966                     _TRISC2	.equ	0x4D
967                     
968                     	.area DSEG(DATA)
969                     _PT2DA	.equ	0x4E
970                     
971                     	.area DSEG(DATA)
972                     _PT2PU	.equ	0x4F
973                     
974                     	.area DSEG(DATA)
975                     _PT8	.equ	0x50
976                     
977                     	.area DSEG(DATA)
978                     _TRISC8	.equ	0x51
979                     
980                     	.area DSEG(DATA)
981                     _PT8PU	.equ	0x53
982                     
983                     	.area DSEG(DATA)
984                     _UR0CN	.equ	0x54
985                     
986                     	.area DSEG(DATA)
987                     _UR0STA	.equ	0x55
988                     
989                     	.area DSEG(DATA)
990                     _BA0CN	.equ	0x56
991                     
992                     	.area DSEG(DATA)
993                     _BG0RH	.equ	0x57
994                     
995                     	.area DSEG(DATA)
996                     _BG0RL	.equ	0x58
997                     
998                     	.area DSEG(DATA)
999                     _TX0R	.equ	0x59
1000                     
1001                     	.area DSEG(DATA)
1002                     _RC0REG	.equ	0x5A
1003                     
1004                     	.area DSEG(DATA)
1005                     _LCDCN1	.equ	0x5B
1006                     
1007                     	.area DSEG(DATA)
1008                     _LCDCN2	.equ	0x5C
1009                     
1010                     	.area DSEG(DATA)
1011                     _LCDCN3	.equ	0x5D
1012                     
1013                     	.area DSEG(DATA)
1014                     _LCDCN4	.equ	0x5E
1015                     
1016                     	.area DSEG(DATA)
1017                     _LCD0	.equ	0x5F
1018                     
1019                     	.area DSEG(DATA)
1020                     _LCD1	.equ	0x60
1021                     
1022                     	.area DSEG(DATA)
1023                     _LCD2	.equ	0x61
1024                     
1025                     	.area DSEG(DATA)
1026                     _LCD3	.equ	0x62
1027                     
1028                     	.area DSEG(DATA)
1029                     _LCD4	.equ	0x63
1030                     
1031                     	.area DSEG(DATA)
1032                     _LCD5	.equ	0x64
1033                     
1034                     	.area DSEG(DATA)
1035                     _LCD6	.equ	0x65
1036                     
1037                     	.area DSEG(DATA)
1038                     _Filter	.equ	0x66
1039                     
1040                     	.area DSEG(DATA)
1041                     _ADCRH	.equ	0x3A
1042                     
1043                     	.area DSEG(DATA)
1044                     _ADCRM	.equ	0x3B
1045                     
1046                     	.area DSEG(DATA)
1047                     _ADCRL	.equ	0x3C
1048                     
1049                     ;--------------------------------------------------------
1050                     ; absolute symbol definitions
1051                     ;--------------------------------------------------------
1052                     ;--------------------------------------------------------
1053                     ; compiler-defined variables
1054                     ;--------------------------------------------------------
1055                     	.area IDATA (DATA,REL,CON); pre-def
1056                     	.area IDATAROM (CODE,REL,CON); pre-def
1057                     	.area UDATA (DATA,REL,CON); pre-def
1058                     	.area UDATA (DATA,REL,CON) ;UDL_display_0	udata
1059 0000 --             r0x1140:	.ds	1
1060 @FSR2-01 --         r0x1146:	.ds	1
1061 @FSR2-02 --         r0x1147:	.ds	1
1062 @FSR2-03 --         r0x1148:	.ds	1
1063 @FSR2-04 --         r0x1149:	.ds	1
1064 @FSR2-05 --         r0x114A:	.ds	1
1065 @FSR2-01 --         r0x1166:	.ds	1
1066 @FSR2-01 --         r0x116B:	.ds	1
1067 @FSR2-02 --         r0x116C:	.ds	1
1068 @FSR2-03 --         r0x116D:	.ds	1
1069 @FSR2-04 --         r0x116E:	.ds	1
1070 @FSR2-05 --         r0x116F:	.ds	1
1071 @FSR2-09 --         r0x1170:	.ds	1
1072 @FSR2-08 --         r0x1171:	.ds	1
1073 @FSR2-07 --         r0x1172:	.ds	1
1074 @FSR2-06 --         r0x1173:	.ds	1
1075 @FSR2-10 --         r0x1177:	.ds	1
1076                     	.area LOCALSTK (STK); local stack var
1077 @FSR2-00 --         _DisplayNum_STK00:	.ds	1
1078                     	.globl _DisplayNum_STK00
1079 @FSR2+01 --         _DisplayNum_STK01:	.ds	1
1080                     	.globl _DisplayNum_STK01
1081 @FSR2+02 --         _DisplayNum_STK02:	.ds	1
1082                     	.globl _DisplayNum_STK02
1083                     	.globl __modslong_STK06
1084                     	.globl __modslong_STK05
1085                     	.globl __modslong_STK04
1086                     	.globl __modslong_STK03
1087                     	.globl __modslong_STK02
1088                     	.globl __modslong_STK01
1089                     	.globl __modslong_STK00
1090                     	.globl __g2ptrget1_STK00
1091                     	.globl __g2ptrput1_STK01
1092                     	.globl __g2ptrput1_STK00
1093                     	.globl __divslong_STK06
1094                     	.globl __divslong_STK05
1095                     	.globl __divslong_STK04
1096                     	.globl __divslong_STK03
1097                     	.globl __divslong_STK02
1098                     	.globl __divslong_STK01
1099                     	.globl __divslong_STK00
1100 @FSR2-00 --         _Delay_STK00:	.ds	1
1101                     	.globl _Delay_STK00
1102 @FSR2-00 --         _Reverse_Data_STK00:	.ds	1
1103                     	.globl _Reverse_Data_STK00
1104 @FSR2+01 --         _Reverse_Data_STK01:	.ds	1
1105                     	.globl _Reverse_Data_STK01
1106 @FSR2+02 --         _Reverse_Data_STK02:	.ds	1
1107                     	.globl _Reverse_Data_STK02
1108                     	.globl __mullong_STK06
1109                     	.globl __mullong_STK05
1110                     	.globl __mullong_STK04
1111                     	.globl __mullong_STK03
1112                     	.globl __mullong_STK02
1113                     	.globl __mullong_STK01
1114                     	.globl __mullong_STK00
1115                     	.globl ___slong2fs_STK02
1116                     	.globl ___slong2fs_STK01
1117                     	.globl ___slong2fs_STK00
1118                     	.globl ___fsmul_STK06
1119                     	.globl ___fsmul_STK05
1120                     	.globl ___fsmul_STK04
1121                     	.globl ___fsmul_STK03
1122                     	.globl ___fsmul_STK02
1123                     	.globl ___fsmul_STK01
1124                     	.globl ___fsmul_STK00
1125                     	.globl ___fs2slong_STK02
1126                     	.globl ___fs2slong_STK01
1127                     	.globl ___fs2slong_STK00
1128                     ;--------------------------------------------------------
1129                     ; initialized data
1130                     ;--------------------------------------------------------
1131                     
1132                     	.area	CONST   (CODE)	 ;display-0-code, const
1133                     
1134                     _seg:
1135 0D36 FA             	.db #0xfa	; 250
1136 0D36 0A             	.db #0x0a	; 10
1137 0D37 BC             	.db #0xbc	; 188
1138 0D37 9E             	.db #0x9e	; 158
1139 0D38 4E             	.db #0x4e	; 78	'N'
1140 0D38 D6             	.db #0xd6	; 214
1141 0D39 F6             	.db #0xf6	; 246
1142 0D39 CA             	.db #0xca	; 202
1143 0D3A FE             	.db #0xfe	; 254
1144 0D3A DE             	.db #0xde	; 222
1145 0D3B EE             	.db #0xee	; 238
1146 0D3B 76             	.db #0x76	; 118	'v'
1147 0D3C F0             	.db #0xf0	; 240
1148 0D3C 3E             	.db #0x3e	; 62
1149 0D3D F4             	.db #0xf4	; 244
1150 0D3D E4             	.db #0xe4	; 228
1151 0D3E 6E             	.db #0x6e	; 110	'n'
1152 0D3E 02             	.db #0x02	; 2
1153 0D3F 1E             	.db #0x1e	; 30
1154 0D3F 70             	.db #0x70	; 112	'p'
1155 0D40 26             	.db #0x26	; 38
1156 0D40 36             	.db #0x36	; 54	'6'
1157 0D41 EC             	.db #0xec	; 236
1158 0D41 CE             	.db #0xce	; 206
1159 0D42 24             	.db #0x24	; 36
1160 0D42 74             	.db #0x74	; 116	't'
1161 0D43 32             	.db #0x32	; 50	'2'
1162 0D43 5E             	.db #0x5e	; 94
1163 0D44 7A             	.db #0x7a	; 122	'z'
1164                     
1165                     ;--------------------------------------------------------
1166                     ; initialized data - mirror
1167                     ;--------------------------------------------------------
1168                     
1169                     	;Following is optimization info, 
1170                     	;xxcdbxxW:dst:src+offset:srclit:just-remove
1171                     	;--cdb--W:r0x1174:NULL+0:-1:1
1172                     	;--cdb--W:r0x1170:NULL+0:-1:1
1173                     	;--cdb--W:r0x1172:STK00+0:-1:0
1174                     	;--cdb--W:r0x1171:STK01+0:-1:0
1175                     	;--cdb--W:r0x1176:STK00+0:-1:0
1176                     	;--cdb--W:r0x1175:STK01+0:-1:0
1177                     	;--cdb--W:r0x114D:NULL+0:-1:1
1178                     	;--cdb--W:r0x114C:NULL+0:-1:1
1179                     	;--cdb--W:r0x114A:NULL+0:-1:1
1180                     	;--cdb--W:r0x114E:NULL+0:-1:1
1181                     	;--cdb--W:r0x114B:STK01+0:-1:0
1182                     	;--cdb--W:r0x114B:NULL+0:-1:1
1183                     	;--cdb--W:r0x113F:NULL+0:-1:1
1184                     	end
